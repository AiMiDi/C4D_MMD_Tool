'use strict';

const fs = require('fs');
const path = require('path');

function fail(message) {
  process.stderr.write(String(message) + '\n');
  process.exit(1);
}

function normalizePath(value) {
  return String(value || '').replace(/\\/g, '/').replace(/^\.\//, '').replace(/\/+/g, '/');
}

function sortedObjectOfArrays(map) {
  const output = {};
  for (const key of [...map.keys()].sort()) {
    output[key] = [...map.get(key)].sort();
  }
  return output;
}

function increment(map, key, amount = 1) {
  map.set(key, (map.get(key) || 0) + amount);
}

function ratio(numerator, denominator) {
  return denominator === 0 ? 0 : Number((numerator / denominator).toFixed(4));
}

function commonDirectoryPrefix(paths) {
  if (paths.length === 0) return [];
  const directories = paths.map((filePath) => normalizePath(filePath).split('/').slice(0, -1));
  const limit = Math.min(...directories.map((segments) => segments.length));
  const prefix = [];
  for (let index = 0; index < limit; index += 1) {
    const value = directories[0][index];
    if (!directories.every((segments) => segments[index] === value)) break;
    prefix.push(value);
  }
  return prefix;
}

const directoryPatterns = [
  { names: ['routes', 'api', 'controllers', 'controller', 'endpoints', 'handlers', 'routers', 'blueprints', 'serializers'], label: 'api' },
  { names: ['services', 'core', 'lib', 'domain', 'logic', 'internal', 'composables', 'mailers', 'jobs', 'channels', 'signals'], label: 'service' },
  { names: ['models', 'db', 'data', 'persistence', 'repository', 'entities', 'entity', 'migrations', 'sql', 'database', 'schema'], label: 'data' },
  { names: ['components', 'views', 'pages', 'ui', 'layouts', 'screens'], label: 'ui' },
  { names: ['middleware', 'plugins', 'interceptors', 'guards'], label: 'middleware' },
  { names: ['utils', 'helpers', 'common', 'shared', 'tools', 'pkg', 'templatetags'], label: 'utility' },
  { names: ['config', 'constants', 'env', 'settings', 'management', 'commands'], label: 'config' },
  { names: ['__tests__', 'test', 'tests', 'spec', 'specs'], label: 'test' },
  { names: ['types', 'interfaces', 'schemas', 'contracts', 'dtos', 'dto', 'request', 'response'], label: 'types' },
  { names: ['hooks'], label: 'hooks' },
  { names: ['store', 'state', 'reducers', 'actions', 'slices'], label: 'state' },
  { names: ['assets', 'static', 'public'], label: 'assets' },
  { names: ['cmd', 'bin'], label: 'entry' },
  { names: ['docs', 'documentation', 'wiki'], label: 'documentation' },
  { names: ['deploy', 'deployment', 'infra', 'infrastructure', 'k8s', 'kubernetes', 'helm', 'charts', 'terraform', 'tf', 'docker'], label: 'infrastructure' },
  { names: ['.github', '.gitlab', '.circleci'], label: 'ci-cd' }
];

function directoryPattern(filePath, groupName) {
  const normalized = normalizePath(filePath).toLowerCase();
  if (normalized.includes('src/main/java')) return 'service';
  if (normalized.includes('src/test/java')) return 'test';
  const segments = normalized.split('/').slice(0, -1);
  const candidates = [String(groupName || '').toLowerCase(), ...segments.reverse()];
  for (const candidate of candidates) {
    for (const pattern of directoryPatterns) {
      if (pattern.names.includes(candidate)) return pattern.label;
    }
  }
  return null;
}

function filePattern(node) {
  const filePath = normalizePath(node.filePath || node.name);
  const lower = filePath.toLowerCase();
  const base = path.posix.basename(lower);
  const originalBase = path.posix.basename(filePath);

  if (node.type === 'pipeline' || lower.startsWith('.github/workflows/') || base === '.gitlab-ci.yml' || originalBase === 'Jenkinsfile') return 'ci-cd';
  if (/(^|\/)(__tests__|tests?|specs?)(\/|$)/.test(lower) ||
      /\.[^.\/]+\.(test|spec)\.[^.\/]+$/.test(lower) ||
      /\.(test|spec)\.[^.\/]+$/.test(lower) ||
      /(^|\/)test_[^/]+\.py$/.test(lower) ||
      /_test\.go$/.test(lower) ||
      /test\.java$/.test(lower) ||
      /_spec\.rb$/.test(lower) ||
      /test\.php$/.test(lower) ||
      /tests\.cs$/.test(lower)) return 'test';
  if (/\.d\.ts$/.test(lower)) return 'types';
  if (/\.(graphql|gql|proto)$/.test(lower) || node.type === 'schema' || node.type === 'endpoint') return 'types';
  if (/\.sql$/.test(lower) || node.type === 'table') return 'data';
  if (/\.tf(vars)?$/.test(lower) || base === 'dockerfile' || base.startsWith('dockerfile.') ||
      base.startsWith('docker-compose.') || base === 'docker-compose.yml' || base === 'docker-compose.yaml' ||
      originalBase === 'Makefile' || node.type === 'service') return 'infrastructure';
  if (node.type === 'resource') return 'assets';
  if (node.type === 'document' || /\.(md|rst)$/.test(lower)) return 'documentation';
  if (node.type === 'config' || ['cargo.toml', 'go.mod', 'gemfile', 'pom.xml', 'build.gradle', 'composer.json'].includes(base)) return 'config';
  if (['wsgi.py', 'asgi.py'].includes(base)) return 'config';
  if (base === 'config.ru' || base === 'manage.py' || base === 'application.java' || base === 'program.cs') return 'entry';
  if ((base === 'index.ts' || base === 'index.js' || base === '__init__.py') ||
      ((base === 'main.rs' || base === 'lib.rs') && lower.startsWith('src/')) ||
      (base === 'main.go' && /(^|\/)cmd\/[^/]+\/main\.go$/.test(lower))) return 'entry';
  return null;
}

function flatGroup(node) {
  const matched = filePattern(node);
  if (matched) return matched;
  const base = normalizePath(node.filePath || node.name).toLowerCase();
  const extension = path.posix.extname(base).replace(/^\./, '');
  return extension ? 'ext-' + extension : node.type || 'other';
}

function main() {
  const inputPath = process.argv[2];
  const outputPath = process.argv[3];
  if (!inputPath || !outputPath) fail('Usage: node ua-arch-analyze.js <input.json> <output.json>');

  let input;
  try {
    input = JSON.parse(fs.readFileSync(inputPath, 'utf8'));
  } catch (error) {
    fail('Unable to read architecture input: ' + error.message);
  }

  const fileNodes = Array.isArray(input.fileNodes) ? input.fileNodes : [];
  const importEdges = Array.isArray(input.importEdges) ? input.importEdges : [];
  const allEdges = Array.isArray(input.allEdges) ? input.allEdges : [];
  if (fileNodes.length === 0) fail('Architecture input has no fileNodes');

  const nodeById = new Map();
  for (const node of fileNodes) {
    if (!node || typeof node.id !== 'string' || nodeById.has(node.id)) fail('fileNodes must contain unique string IDs');
    nodeById.set(node.id, node);
  }

  const validImportEdges = importEdges.filter((edge) => nodeById.has(edge.source) && nodeById.has(edge.target));
  const validAllEdges = allEdges.filter((edge) => nodeById.has(edge.source) && nodeById.has(edge.target));
  const paths = fileNodes.map((node) => normalizePath(node.filePath || node.name));
  const prefixSegments = commonDirectoryPrefix(paths);
  const initiallyFlat = paths.every((filePath) => normalizePath(filePath).split('/').length === 1);

  const directoryGroupMap = new Map();
  const groupById = new Map();
  for (const node of fileNodes) {
    const filePath = normalizePath(node.filePath || node.name);
    const segments = filePath.split('/');
    let group;
    if (initiallyFlat) {
      group = flatGroup(node);
    } else {
      const remaining = segments.slice(prefixSegments.length);
      group = remaining.length > 1 ? remaining[0] : 'root';
    }
    if (!directoryGroupMap.has(group)) directoryGroupMap.set(group, new Set());
    directoryGroupMap.get(group).add(node.id);
    groupById.set(node.id, group);
  }

  const nodeTypeMap = new Map();
  for (const node of fileNodes) {
    if (!nodeTypeMap.has(node.type)) nodeTypeMap.set(node.type, new Set());
    nodeTypeMap.get(node.type).add(node.id);
  }

  const fanIn = Object.fromEntries(fileNodes.map((node) => [node.id, 0]));
  const fanOut = Object.fromEntries(fileNodes.map((node) => [node.id, 0]));
  const groupImportsFrom = new Map([...directoryGroupMap.keys()].map((group) => [group, new Set()]));
  const groupImportedBy = new Map([...directoryGroupMap.keys()].map((group) => [group, new Set()]));
  const interGroupCounts = new Map();
  const internalEdges = new Map([...directoryGroupMap.keys()].map((group) => [group, 0]));
  const totalInvolvingEdges = new Map([...directoryGroupMap.keys()].map((group) => [group, 0]));

  for (const edge of validImportEdges) {
    fanOut[edge.source] += 1;
    fanIn[edge.target] += 1;
    const fromGroup = groupById.get(edge.source);
    const toGroup = groupById.get(edge.target);
    if (fromGroup === toGroup) {
      increment(internalEdges, fromGroup);
      increment(totalInvolvingEdges, fromGroup);
    } else {
      groupImportsFrom.get(fromGroup).add(toGroup);
      groupImportedBy.get(toGroup).add(fromGroup);
      increment(interGroupCounts, fromGroup + '\u0000' + toGroup);
      increment(totalInvolvingEdges, fromGroup);
      increment(totalInvolvingEdges, toGroup);
    }
  }

  const directoryImportAdjacency = {};
  for (const group of [...directoryGroupMap.keys()].sort()) {
    directoryImportAdjacency[group] = {
      importsFrom: [...groupImportsFrom.get(group)].sort(),
      importedBy: [...groupImportedBy.get(group)].sort()
    };
  }

  const crossCategoryCount = new Map();
  const nonCodeConnections = [];
  for (const edge of validAllEdges) {
    const fromNode = nodeById.get(edge.source);
    const toNode = nodeById.get(edge.target);
    if (fromNode.type !== toNode.type) {
      increment(crossCategoryCount, fromNode.type + '\u0000' + toNode.type + '\u0000' + edge.type);
    }
    if (fromNode.type !== 'file' || toNode.type !== 'file') {
      nonCodeConnections.push({
        source: edge.source,
        target: edge.target,
        edgeType: edge.type,
        fromType: fromNode.type,
        toType: toNode.type
      });
    }
  }

  const crossCategoryEdges = [...crossCategoryCount.entries()].map(([key, count]) => {
    const [fromType, toType, edgeType] = key.split('\u0000');
    return { fromType, toType, edgeType, count };
  }).sort((a, b) => a.fromType.localeCompare(b.fromType) || a.toType.localeCompare(b.toType) || a.edgeType.localeCompare(b.edgeType));

  const interGroupImports = [...interGroupCounts.entries()].map(([key, count]) => {
    const [from, to] = key.split('\u0000');
    return { from, to, count };
  }).sort((a, b) => a.from.localeCompare(b.from) || a.to.localeCompare(b.to));

  const intraGroupDensity = {};
  for (const group of [...directoryGroupMap.keys()].sort()) {
    const internal = internalEdges.get(group) || 0;
    const total = totalInvolvingEdges.get(group) || 0;
    intraGroupDensity[group] = { internalEdges: internal, totalEdges: total, density: ratio(internal, total) };
  }

  const filePatternMatches = {};
  const patternMatches = {};
  for (const group of [...directoryGroupMap.keys()].sort()) {
    const labelCounts = new Map();
    for (const id of directoryGroupMap.get(group)) {
      const node = nodeById.get(id);
      const label = filePattern(node) || directoryPattern(node.filePath || node.name, group);
      if (label) {
        filePatternMatches[id] = label;
        increment(labelCounts, label);
      }
    }
    const direct = directoryPatterns.find((pattern) => pattern.names.includes(group.toLowerCase()));
    if (direct) {
      patternMatches[group] = direct.label;
    } else if (labelCounts.size > 0) {
      patternMatches[group] = [...labelCounts.entries()].sort((a, b) => b[1] - a[1] || a[0].localeCompare(b[0]))[0][0];
    }
  }

  const lowerPaths = paths.map((filePath) => filePath.toLowerCase());
  const isDocker = (filePath) => {
    const base = path.posix.basename(filePath);
    return base === 'dockerfile' || base.startsWith('dockerfile.');
  };
  const isCompose = (filePath) => /(^|\/)docker-compose([.-].+)?\.ya?ml$/.test(filePath);
  const isK8s = (filePath) => /(^|\/)(k8s|kubernetes|helm|charts)(\/|$)/.test(filePath);
  const isTerraform = (filePath) => /(^|\/)(terraform|tf)(\/|$)/.test(filePath) || /\.tf(vars)?$/.test(filePath);
  const isCi = (filePath) => filePath.startsWith('.github/workflows/') || filePath === '.gitlab-ci.yml' || path.posix.basename(filePath) === 'jenkinsfile';
  const infraFiles = paths.filter((_, index) => isDocker(lowerPaths[index]) || isCompose(lowerPaths[index]) || isK8s(lowerPaths[index]) || isTerraform(lowerPaths[index]) || isCi(lowerPaths[index]));

  const dockerEnvironments = lowerPaths.filter(isDocker).map((filePath) => path.posix.basename(filePath).split('.').slice(1).join('.')).filter(Boolean);
  const composeEnvironments = lowerPaths.filter(isCompose).map((filePath) => {
    const base = path.posix.basename(filePath);
    const match = base.match(/^docker-compose[.-](.+)\.ya?ml$/);
    return match ? match[1] : '';
  }).filter(Boolean);

  const deploymentTopology = {
    hasDockerfile: lowerPaths.some(isDocker),
    hasCompose: lowerPaths.some(isCompose),
    hasK8s: lowerPaths.some(isK8s),
    hasTerraform: lowerPaths.some(isTerraform),
    hasCI: lowerPaths.some(isCi) || fileNodes.some((node) => node.type === 'pipeline'),
    infraFiles: [...new Set(infraFiles)].sort(),
    environments: [...new Set([...dockerEnvironments, ...composeEnvironments])].sort(),
    chains: {
      dockerToCompose: lowerPaths.some(isDocker) && lowerPaths.some(isCompose),
      composeToK8s: lowerPaths.some(isCompose) && lowerPaths.some(isK8s),
      terraformModules: lowerPaths.filter((filePath) => isTerraform(filePath) && filePath.includes('/modules/')).sort()
    }
  };

  const hasAnyTag = (node, candidates) => {
    const tags = Array.isArray(node.tags) ? node.tags.map((tag) => String(tag).toLowerCase()) : [];
    return candidates.some((candidate) => tags.includes(candidate));
  };
  const schemaFiles = fileNodes.filter((node) => node.type === 'schema' || /\.(sql|graphql|gql|proto|prisma)$/.test(normalizePath(node.filePath || node.name).toLowerCase())).map((node) => normalizePath(node.filePath || node.name));
  const migrationFiles = fileNodes.filter((node) => /(^|\/)migrations?(\/|$)/.test(normalizePath(node.filePath || node.name).toLowerCase())).map((node) => normalizePath(node.filePath || node.name));
  const dataModelFiles = fileNodes.filter((node) => node.type === 'table' || /(^|\/)(models?|entities|repository|data)(\/|$)/.test(normalizePath(node.filePath || node.name).toLowerCase()) || hasAnyTag(node, ['data-model', 'model', 'persistence', 'schema'])).map((node) => normalizePath(node.filePath || node.name));
  const apiHandlerFiles = fileNodes.filter((node) => node.type === 'endpoint' || /(^|\/)(routes?|api|controllers?|endpoints?|handlers?)(\/|$)/.test(normalizePath(node.filePath || node.name).toLowerCase()) || hasAnyTag(node, ['api-handler', 'endpoint', 'controller'])).map((node) => normalizePath(node.filePath || node.name));
  const generatedFiles = fileNodes.filter((node) => /(^|\/)(generated|gen)(\/|$)/.test(normalizePath(node.filePath || node.name).toLowerCase()) || hasAnyTag(node, ['generated'])).map((node) => normalizePath(node.filePath || node.name));

  const dataPipeline = {
    schemaFiles: [...new Set(schemaFiles)].sort(),
    migrationFiles: [...new Set(migrationFiles)].sort(),
    dataModelFiles: [...new Set(dataModelFiles)].sort(),
    apiHandlerFiles: [...new Set(apiHandlerFiles)].sort(),
    generatedFiles: [...new Set(generatedFiles)].sort()
  };

  const documentNodes = fileNodes.filter((node) => node.type === 'document' || /\.(md|rst)$/.test(normalizePath(node.filePath || node.name).toLowerCase()));
  const groupsWithDocs = [];
  for (const group of [...directoryGroupMap.keys()].sort()) {
    const hasDocumentation = documentNodes.some((node) => {
      const docGroup = groupById.get(node.id);
      if (docGroup === group) return true;
      const searchable = (normalizePath(node.filePath || node.name) + ' ' + String(node.summary || '')).toLowerCase();
      return group !== 'root' && searchable.includes(group.toLowerCase());
    });
    if (hasDocumentation) groupsWithDocs.push(group);
  }
  const allGroups = [...directoryGroupMap.keys()].sort();
  const docCoverage = {
    groupsWithDocs: groupsWithDocs.length,
    totalGroups: allGroups.length,
    coverageRatio: ratio(groupsWithDocs.length, allGroups.length),
    documentedGroups: groupsWithDocs,
    undocumentedGroups: allGroups.filter((group) => !groupsWithDocs.includes(group))
  };

  const unorderedPairs = new Map();
  for (const item of interGroupImports) {
    const ordered = [item.from, item.to].sort();
    const key = ordered[0] + '\u0000' + ordered[1];
    if (!unorderedPairs.has(key)) unorderedPairs.set(key, { a: ordered[0], b: ordered[1], aToB: 0, bToA: 0 });
    const pair = unorderedPairs.get(key);
    if (item.from === pair.a) pair.aToB += item.count;
    else pair.bToA += item.count;
  }
  const dependencyDirection = [...unorderedPairs.values()].map((pair) => {
    if (pair.aToB >= pair.bToA) {
      return { dependent: pair.a, dependsOn: pair.b, dominantCount: pair.aToB, reverseCount: pair.bToA, balanced: pair.aToB === pair.bToA };
    }
    return { dependent: pair.b, dependsOn: pair.a, dominantCount: pair.bToA, reverseCount: pair.aToB, balanced: false };
  }).sort((a, b) => a.dependent.localeCompare(b.dependent) || a.dependsOn.localeCompare(b.dependsOn));

  const filesPerGroup = {};
  for (const [group, ids] of [...directoryGroupMap.entries()].sort(([a], [b]) => a.localeCompare(b))) filesPerGroup[group] = ids.size;
  const nodeTypeCounts = {};
  for (const [type, ids] of [...nodeTypeMap.entries()].sort(([a], [b]) => a.localeCompare(b))) nodeTypeCounts[type] = ids.size;

  const result = {
    scriptCompleted: true,
    commonPathPrefix: prefixSegments.length ? prefixSegments.join('/') + '/' : '',
    directoryGroups: sortedObjectOfArrays(directoryGroupMap),
    nodeTypeGroups: sortedObjectOfArrays(nodeTypeMap),
    directoryImportAdjacency,
    crossCategoryEdges,
    nonCodeConnections,
    interGroupImports,
    intraGroupDensity,
    patternMatches,
    filePatternMatches,
    deploymentTopology,
    dataPipeline,
    docCoverage,
    dependencyDirection,
    fileStats: {
      totalFileNodes: fileNodes.length,
      totalImportEdges: validImportEdges.length,
      totalFileLevelEdges: validAllEdges.length,
      filesPerGroup,
      nodeTypeCounts
    },
    fileFanIn: fanIn,
    fileFanOut: fanOut
  };

  try {
    fs.writeFileSync(outputPath, JSON.stringify(result, null, 2));
  } catch (error) {
    fail('Unable to write architecture results: ' + error.message);
  }
  process.stdout.write(JSON.stringify({
    scriptCompleted: true,
    totalFileNodes: fileNodes.length,
    importEdges: validImportEdges.length,
    allEdges: validAllEdges.length,
    directoryGroups: directoryGroupMap.size
  }) + '\n');
}

try {
  main();
} catch (error) {
  fail(error && error.stack ? error.stack : error);
}
