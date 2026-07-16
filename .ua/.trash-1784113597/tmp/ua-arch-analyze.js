const fs = require('fs');
const path = require('path');

function fail(message) {
  process.stderr.write(`${message}\n`);
  process.exit(1);
}

const [, , inputPath, outputPath] = process.argv;
if (!inputPath || !outputPath) fail('Usage: node ua-arch-analyze.js <input.json> <output.json>');

try {
  const input = JSON.parse(fs.readFileSync(inputPath, 'utf8'));
  const fileNodes = Array.isArray(input.fileNodes) ? input.fileNodes : [];
  const importEdges = Array.isArray(input.importEdges) ? input.importEdges : [];
  const allEdges = Array.isArray(input.allEdges) ? input.allEdges : [];
  if (!fileNodes.length) throw new Error('Input has no fileNodes');

  const nodeById = new Map(fileNodes.map((node) => [node.id, node]));
  if (nodeById.size !== fileNodes.length) throw new Error('Duplicate file node IDs');
  const normalize = (value) => String(value || '').replace(/\\/g, '/').replace(/^\.\//, '');
  const paths = fileNodes.map((node) => normalize(node.filePath));

  function commonPrefixSegments(filePaths) {
    const dirs = filePaths.map((filePath) => {
      const segments = filePath.split('/');
      return segments.length > 1 ? segments.slice(0, -1) : [];
    });
    if (!dirs.length) return [];
    const prefix = [...dirs[0]];
    for (const segments of dirs.slice(1)) {
      let i = 0;
      while (i < prefix.length && i < segments.length && prefix[i] === segments[i]) i += 1;
      prefix.length = i;
      if (!prefix.length) break;
    }
    return prefix;
  }

  const commonPrefix = commonPrefixSegments(paths);
  const hasSubdirectories = paths.some((filePath) => filePath.includes('/'));
  const flat = !hasSubdirectories;
  function flatGroup(filePath) {
    const name = path.posix.basename(filePath).toLowerCase();
    if (/\.(test|spec)\./.test(name)) return 'test';
    if (/config|preset|settings/.test(name)) return 'config';
    const ext = path.posix.extname(name).slice(1);
    return ext || 'root';
  }
  function groupForPath(filePath) {
    if (flat) return flatGroup(filePath);
    const segments = filePath.split('/');
    const remaining = segments.slice(commonPrefix.length);
    if (remaining.length <= 1) return 'root';
    return remaining[0] || 'root';
  }

  const directoryGroups = {};
  const groupById = new Map();
  for (const node of fileNodes) {
    const group = groupForPath(normalize(node.filePath));
    if (!directoryGroups[group]) directoryGroups[group] = [];
    directoryGroups[group].push(node.id);
    groupById.set(node.id, group);
  }
  for (const ids of Object.values(directoryGroups)) ids.sort();

  const nodeTypeGroups = {};
  for (const node of fileNodes) {
    if (!nodeTypeGroups[node.type]) nodeTypeGroups[node.type] = [];
    nodeTypeGroups[node.type].push(node.id);
  }
  for (const ids of Object.values(nodeTypeGroups)) ids.sort();

  const adjacency = {};
  const fileFanIn = {};
  const fileFanOut = {};
  for (const node of fileNodes) {
    adjacency[node.id] = [];
    fileFanIn[node.id] = 0;
    fileFanOut[node.id] = 0;
  }
  const groupImportsFrom = {};
  const groupImportedBy = {};
  for (const group of Object.keys(directoryGroups)) {
    groupImportsFrom[group] = new Set();
    groupImportedBy[group] = new Set();
  }
  const interCounts = new Map();
  const groupInvolving = Object.fromEntries(Object.keys(directoryGroups).map((group) => [group, 0]));
  const groupInternal = Object.fromEntries(Object.keys(directoryGroups).map((group) => [group, 0]));
  for (const edge of importEdges) {
    if (!nodeById.has(edge.source) || !nodeById.has(edge.target)) continue;
    adjacency[edge.source].push(edge.target);
    fileFanOut[edge.source] += 1;
    fileFanIn[edge.target] += 1;
    const from = groupById.get(edge.source);
    const to = groupById.get(edge.target);
    if (from === to) {
      groupInternal[from] += 1;
      groupInvolving[from] += 1;
    } else {
      groupInvolving[from] += 1;
      groupInvolving[to] += 1;
      groupImportsFrom[from].add(to);
      groupImportedBy[to].add(from);
      const key = `${from}\u0000${to}`;
      interCounts.set(key, (interCounts.get(key) || 0) + 1);
    }
  }
  for (const targets of Object.values(adjacency)) targets.sort();

  const directoryGroupDependencies = {};
  for (const group of Object.keys(directoryGroups)) {
    directoryGroupDependencies[group] = {
      importsFrom: [...groupImportsFrom[group]].sort(),
      importedBy: [...groupImportedBy[group]].sort(),
    };
  }
  const interGroupImports = [...interCounts.entries()]
    .map(([key, count]) => {
      const [from, to] = key.split('\u0000');
      return { from, to, count };
    })
    .sort((a, b) => b.count - a.count || a.from.localeCompare(b.from) || a.to.localeCompare(b.to));

  const intraGroupDensity = {};
  for (const group of Object.keys(directoryGroups)) {
    const totalEdges = groupInvolving[group];
    intraGroupDensity[group] = {
      internalEdges: groupInternal[group],
      totalEdges,
      density: totalEdges ? Number((groupInternal[group] / totalEdges).toFixed(4)) : 0,
    };
  }

  const crossCounts = new Map();
  const nonCodeConnections = [];
  const codeTypes = new Set(['file']);
  for (const edge of allEdges) {
    const source = nodeById.get(edge.source);
    const target = nodeById.get(edge.target);
    if (!source || !target) continue;
    const key = `${source.type}\u0000${target.type}\u0000${edge.type}`;
    crossCounts.set(key, (crossCounts.get(key) || 0) + 1);
    if ((!codeTypes.has(source.type) && codeTypes.has(target.type)) || (codeTypes.has(source.type) && !codeTypes.has(target.type))) {
      nonCodeConnections.push({ source: edge.source, target: edge.target, edgeType: edge.type });
    }
  }
  const crossCategoryEdges = [...crossCounts.entries()]
    .map(([key, count]) => {
      const [fromType, toType, edgeType] = key.split('\u0000');
      return { fromType, toType, edgeType, count };
    })
    .sort((a, b) => b.count - a.count || a.fromType.localeCompare(b.fromType) || a.toType.localeCompare(b.toType));

  const directoryPatternTable = [
    [/^(routes|api|controllers?|endpoints?|handlers?|serializers?)$/i, 'api'],
    [/^(services?|core|lib|domain|logic|internal|signals?|mailers?|jobs?|channels?)$/i, 'service'],
    [/^(models?|db|data|persistence|repositories?|entities?|entity|migrations?|sql|database|schema)$/i, 'data'],
    [/^(components?|views?|pages?|ui|layouts?|screens?)$/i, 'ui'],
    [/^(middleware|plugins?|interceptors?|guards?)$/i, 'middleware'],
    [/^(utils?|helpers?|common|shared|tools|pkg|templatetags)$/i, 'utility'],
    [/^(config|constants|env|settings|management|commands)$/i, 'config'],
    [/^(__tests__|tests?|specs?|src\/test\/java)$/i, 'test'],
    [/^(types?|interfaces?|schemas?|contracts?|dtos?|dto|request|response)$/i, 'types'],
    [/^(hooks)$/i, 'hooks'],
    [/^(store|state|reducers|actions|slices)$/i, 'state'],
    [/^(assets|static|public)$/i, 'assets'],
    [/^(cmd|bin)$/i, 'entry'],
    [/^(docs|documentation|wiki)$/i, 'documentation'],
    [/^(deploy|deployment|infra|infrastructure|k8s|kubernetes|helm|charts|terraform|tf|docker)$/i, 'infrastructure'],
    [/^(\.github|\.gitlab|\.circleci)$/i, 'ci-cd'],
  ];
  function filePattern(filePath) {
    const lower = filePath.toLowerCase();
    const base = path.posix.basename(lower);
    if (/\.(test|spec)\./.test(base) || /^test_.*\.py$/.test(base) || /_test\.go$/.test(base) || /(test\.java|_spec\.rb|test\.php|tests\.cs)$/.test(base)) return 'test';
    if (/\.d\.ts$/.test(base)) return 'types';
    if ((base === 'index.ts' || base === 'index.js' || base === '__init__.py') && lower.includes('/')) return 'entry';
    if (['manage.py', 'main.go', 'main.rs', 'lib.rs', 'application.java', 'program.cs', 'config.ru'].includes(base)) return 'entry';
    if (['wsgi.py', 'asgi.py', 'cargo.toml', 'go.mod', 'gemfile', 'pom.xml', 'build.gradle', 'composer.json'].includes(base)) return 'config';
    if (base === 'dockerfile' || base.startsWith('docker-compose.')) return 'infrastructure';
    if (/\.(tf|tfvars)$/.test(base)) return 'infrastructure';
    if (lower.startsWith('.github/workflows/') || base === '.gitlab-ci.yml' || base === 'jenkinsfile') return 'ci-cd';
    if (/\.sql$/.test(base)) return 'data';
    if (/\.(graphql|gql|proto)$/.test(base)) return 'types';
    if (/\.(md|rst)$/.test(base)) return 'documentation';
    if (base === 'makefile') return 'infrastructure';
    return null;
  }
  const patternMatches = {};
  for (const [group, ids] of Object.entries(directoryGroups)) {
    const tableMatch = directoryPatternTable.find(([regex]) => regex.test(group));
    if (tableMatch) {
      patternMatches[group] = tableMatch[1];
      continue;
    }
    const counts = {};
    for (const id of ids) {
      const match = filePattern(normalize(nodeById.get(id).filePath));
      if (match) counts[match] = (counts[match] || 0) + 1;
    }
    const ranked = Object.entries(counts).sort((a, b) => b[1] - a[1] || a[0].localeCompare(b[0]));
    if (ranked.length && ranked[0][1] > ids.length / 2) patternMatches[group] = ranked[0][0];
  }

  const infraFiles = [];
  let hasDockerfile = false;
  let hasCompose = false;
  let hasK8s = false;
  let hasTerraform = false;
  let hasCI = false;
  for (const node of fileNodes) {
    const filePath = normalize(node.filePath);
    const lower = filePath.toLowerCase();
    const base = path.posix.basename(lower);
    const dockerfile = base === 'dockerfile' || base.startsWith('dockerfile.');
    const compose = /^docker-compose\..+/.test(base) || base === 'docker-compose.yml' || base === 'docker-compose.yaml';
    const k8s = /(^|\/)(k8s|kubernetes|helm|charts)(\/|$)/.test(lower);
    const terraform = /(^|\/)(terraform|tf)(\/|$)/.test(lower) || /\.(tf|tfvars)$/.test(base);
    const ci = lower.startsWith('.github/workflows/') || base === '.gitlab-ci.yml' || base === 'jenkinsfile' || lower.startsWith('.circleci/');
    if (dockerfile || compose || k8s || terraform || ci || node.type === 'service' || node.type === 'resource' || node.type === 'pipeline') infraFiles.push(filePath);
    hasDockerfile ||= dockerfile;
    hasCompose ||= compose;
    hasK8s ||= k8s;
    hasTerraform ||= terraform;
    hasCI ||= ci || node.type === 'pipeline';
  }
  infraFiles.sort();

  const schemaFiles = [];
  const migrationFiles = [];
  const dataModelFiles = [];
  const apiHandlerFiles = [];
  for (const node of fileNodes) {
    const filePath = normalize(node.filePath);
    const lower = filePath.toLowerCase();
    const tags = (node.tags || []).map((tag) => String(tag).toLowerCase());
    if (['schema', 'table', 'endpoint'].includes(node.type) || /\.(graphql|gql|proto|prisma|sql)$/.test(lower)) schemaFiles.push(filePath);
    if (/(^|\/)migrations?(\/|$)/.test(lower)) migrationFiles.push(filePath);
    if (/(^|\/)(models?|entities?|data)(\/|$)/.test(lower) || tags.some((tag) => ['data-model', 'entity', 'database'].includes(tag))) dataModelFiles.push(filePath);
    if (/(^|\/)(routes?|controllers?|handlers?|api)(\/|$)/.test(lower) || tags.some((tag) => ['api-handler', 'endpoint'].includes(tag))) apiHandlerFiles.push(filePath);
  }

  const documentedGroups = new Set();
  for (const node of fileNodes) {
    const filePath = normalize(node.filePath);
    if (node.type === 'document' && (path.posix.basename(filePath).toLowerCase() === 'readme.md' || filePath.toLowerCase().startsWith('docs/'))) {
      documentedGroups.add(groupById.get(node.id));
    }
  }
  for (const edge of allEdges) {
    if (edge.type !== 'documents') continue;
    const source = nodeById.get(edge.source);
    const target = nodeById.get(edge.target);
    if (source?.type === 'document' && target) documentedGroups.add(groupById.get(target.id));
  }
  const groups = Object.keys(directoryGroups).sort();
  const undocumentedGroups = groups.filter((group) => !documentedGroups.has(group));

  const pairCounts = new Map();
  for (const item of interGroupImports) pairCounts.set(`${item.from}\u0000${item.to}`, item.count);
  const seenPairs = new Set();
  const dependencyDirection = [];
  for (const item of interGroupImports) {
    const pairKey = [item.from, item.to].sort().join('\u0000');
    if (seenPairs.has(pairKey)) continue;
    seenPairs.add(pairKey);
    const forward = pairCounts.get(`${item.from}\u0000${item.to}`) || 0;
    const reverse = pairCounts.get(`${item.to}\u0000${item.from}`) || 0;
    if (forward === reverse) continue;
    dependencyDirection.push(forward > reverse
      ? { dependent: item.from, dependsOn: item.to, count: forward, reverseCount: reverse }
      : { dependent: item.to, dependsOn: item.from, count: reverse, reverseCount: forward });
  }
  dependencyDirection.sort((a, b) => b.count - a.count || a.dependent.localeCompare(b.dependent));

  const result = {
    scriptCompleted: true,
    commonPathPrefix: commonPrefix.length ? `${commonPrefix.join('/')}/` : '',
    directoryGroups,
    directoryGroupDependencies,
    nodeTypeGroups,
    importAdjacency: adjacency,
    crossCategoryEdges,
    nonCodeConnections,
    interGroupImports,
    intraGroupDensity,
    patternMatches,
    deploymentTopology: { hasDockerfile, hasCompose, hasK8s, hasTerraform, hasCI, infraFiles },
    dataPipeline: { schemaFiles: schemaFiles.sort(), migrationFiles: migrationFiles.sort(), dataModelFiles: dataModelFiles.sort(), apiHandlerFiles: apiHandlerFiles.sort() },
    docCoverage: {
      groupsWithDocs: documentedGroups.size,
      totalGroups: groups.length,
      coverageRatio: groups.length ? Number((documentedGroups.size / groups.length).toFixed(4)) : 0,
      undocumentedGroups,
    },
    dependencyDirection,
    fileStats: {
      totalFileNodes: fileNodes.length,
      filesPerGroup: Object.fromEntries(Object.entries(directoryGroups).map(([group, ids]) => [group, ids.length])),
      nodeTypeCounts: Object.fromEntries(Object.entries(nodeTypeGroups).map(([type, ids]) => [type, ids.length])),
    },
    fileFanIn,
    fileFanOut,
  };
  fs.writeFileSync(outputPath, `${JSON.stringify(result, null, 2)}\n`);
  process.exit(0);
} catch (error) {
  fail(error && error.stack ? error.stack : String(error));
}
