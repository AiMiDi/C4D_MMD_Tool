#!/usr/bin/env node

const fs = require('fs');

function fail(message) {
  process.stderr.write(`${message}\n`);
  process.exit(1);
}

function readJson(path) {
  try {
    return JSON.parse(fs.readFileSync(path, 'utf8').replace(/^\uFEFF/, ''));
  } catch (error) {
    fail(`Failed to read ${path}: ${error.message}`);
  }
}

function main() {
  const inputPath = process.argv[2];
  const outputPath = process.argv[3];
  if (!inputPath || !outputPath) {
    fail('Usage: node ua-tour-analyze.js <input.json> <output.json>');
  }

  const input = readJson(inputPath);
  const nodes = Array.isArray(input.nodes) ? input.nodes : [];
  const edges = Array.isArray(input.edges) ? input.edges : [];
  const layers = Array.isArray(input.layers) ? input.layers : [];
  if (!nodes.length) {
    fail('Input contains no nodes.');
  }

  const nodeById = new Map();
  for (const node of nodes) {
    if (!node || typeof node.id !== 'string') {
      fail('Every node must have a string id.');
    }
    if (nodeById.has(node.id)) {
      fail(`Duplicate node id: ${node.id}`);
    }
    nodeById.set(node.id, node);
  }
  const nodeIds = new Set(nodeById.keys());
  const fanIn = new Map(nodes.map((node) => [node.id, 0]));
  const fanOut = new Map(nodes.map((node) => [node.id, 0]));
  for (const edge of edges) {
    if (fanOut.has(edge.source)) {
      fanOut.set(edge.source, fanOut.get(edge.source) + 1);
    }
    if (fanIn.has(edge.target)) {
      fanIn.set(edge.target, fanIn.get(edge.target) + 1);
    }
  }

  const ranking = (counts, field) => nodes
    .map((node) => ({id: node.id, [field]: counts.get(node.id) || 0, name: node.name}))
    .sort((a, b) => b[field] - a[field] || a.id.localeCompare(b.id));
  const fanInAll = ranking(fanIn, 'fanIn');
  const fanOutAll = ranking(fanOut, 'fanOut');
  const fanInRanking = fanInAll.slice(0, 20);
  const fanOutRanking = fanOutAll.slice(0, 20);

  const highFanOutCount = Math.max(1, Math.ceil(nodes.length * 0.10));
  const lowFanInCount = Math.max(1, Math.ceil(nodes.length * 0.25));
  const highFanOut = new Set(fanOutAll.slice(0, highFanOutCount).map((item) => item.id));
  const lowFanIn = new Set([...fanInAll].sort((a, b) => a.fanIn - b.fanIn || a.id.localeCompare(b.id)).slice(0, lowFanInCount).map((item) => item.id));
  const codeEntryNames = new Set([
    'index.ts', 'index.js', 'main.ts', 'main.js', 'app.ts', 'app.js', 'server.ts', 'server.js',
    'mod.rs', 'main.go', 'main.py', 'main.rs', 'manage.py', 'app.py', 'wsgi.py', 'asgi.py',
    'run.py', '__main__.py', 'application.java', 'main.java', 'program.cs', 'config.ru',
    'index.php', 'app.swift', 'application.kt', 'main.cpp', 'main.c',
  ]);

  const entryCandidatesAll = [];
  for (const node of nodes) {
    const path = String(node.filePath || '');
    const name = String(node.name || '').toLowerCase();
    const depth = path.split('/').filter(Boolean).length;
    let score = 0;
    if (node.type === 'file') {
      if (codeEntryNames.has(name)) score += 3;
      if (depth <= 2) score += 1;
      if (highFanOut.has(node.id)) score += 1;
      if (lowFanIn.has(node.id)) score += 1;
    } else if (node.type === 'document') {
      if (path === 'README.md') score += 5;
      else if (depth === 1 && name.endsWith('.md')) score += 2;
    }
    if (score > 0) {
      entryCandidatesAll.push({id: node.id, score, name: node.name, summary: node.summary, type: node.type});
    }
  }
  entryCandidatesAll.sort((a, b) => {
    const aReadme = a.id === 'document:README.md' ? 1 : 0;
    const bReadme = b.id === 'document:README.md' ? 1 : 0;
    return b.score - a.score || bReadme - aReadme || a.id.localeCompare(b.id);
  });
  const entryPointCandidates = entryCandidatesAll.slice(0, 5);

  let codeStart = entryCandidatesAll.find((item) => item.type === 'file' && codeEntryNames.has(String(item.name).toLowerCase()));
  if (!codeStart) codeStart = entryCandidatesAll.find((item) => item.type === 'file');
  const traversalEdges = edges.filter((edge) => (edge.type === 'imports' || edge.type === 'calls') && nodeIds.has(edge.source) && nodeIds.has(edge.target));
  const adjacency = new Map(nodes.map((node) => [node.id, []]));
  for (const edge of traversalEdges) {
    const list = adjacency.get(edge.source);
    if (!list.includes(edge.target)) list.push(edge.target);
  }
  for (const list of adjacency.values()) list.sort();

  const bfsTraversal = {startNode: codeStart ? codeStart.id : null, order: [], depthMap: {}, byDepth: {}};
  if (codeStart) {
    const queue = [codeStart.id];
    bfsTraversal.depthMap[codeStart.id] = 0;
    for (let cursor = 0; cursor < queue.length; cursor += 1) {
      const current = queue[cursor];
      const depth = bfsTraversal.depthMap[current];
      bfsTraversal.order.push(current);
      const key = String(depth);
      if (!bfsTraversal.byDepth[key]) bfsTraversal.byDepth[key] = [];
      bfsTraversal.byDepth[key].push(current);
      for (const target of adjacency.get(current) || []) {
        if (Object.prototype.hasOwnProperty.call(bfsTraversal.depthMap, target)) continue;
        bfsTraversal.depthMap[target] = depth + 1;
        queue.push(target);
      }
    }
  }

  const compactNode = (node) => ({id: node.id, name: node.name, type: node.type, summary: node.summary});
  const nonCodeFiles = {
    documentation: nodes.filter((node) => node.type === 'document').map(compactNode),
    infrastructure: nodes.filter((node) => ['service', 'pipeline', 'resource'].includes(node.type)).map(compactNode),
    data: nodes.filter((node) => ['table', 'schema', 'endpoint'].includes(node.type)).map(compactNode),
    config: nodes.filter((node) => node.type === 'config').map(compactNode),
  };

  const couplingEdges = edges.filter((edge) => (edge.type === 'imports' || edge.type === 'calls') && nodeIds.has(edge.source) && nodeIds.has(edge.target));
  const directed = new Set(couplingEdges.map((edge) => `${edge.source}\u0000${edge.target}`));
  const mutualPairs = [];
  for (const edge of couplingEdges) {
    if (edge.source >= edge.target) continue;
    if (directed.has(`${edge.target}\u0000${edge.source}`)) mutualPairs.push([edge.source, edge.target]);
  }
  const allConnections = new Map(nodes.map((node) => [node.id, new Set()]));
  for (const edge of couplingEdges) {
    allConnections.get(edge.source).add(edge.target);
    allConnections.get(edge.target).add(edge.source);
  }
  const clusterMap = new Map();
  for (const pair of mutualPairs) {
    const cluster = new Set(pair);
    let changed = true;
    while (changed && cluster.size < 5) {
      changed = false;
      const candidates = nodes
        .filter((node) => !cluster.has(node.id))
        .map((node) => ({
          id: node.id,
          connections: [...cluster].filter((member) => allConnections.get(node.id).has(member)).length,
        }))
        .filter((item) => item.connections >= 2)
        .sort((a, b) => b.connections - a.connections || a.id.localeCompare(b.id));
      if (candidates.length) {
        cluster.add(candidates[0].id);
        changed = true;
      }
    }
    const members = [...cluster].sort();
    const key = members.join('\u0000');
    if (clusterMap.has(key)) continue;
    const memberSet = new Set(members);
    const edgeCount = edges.filter((edge) => memberSet.has(edge.source) && memberSet.has(edge.target)).length;
    clusterMap.set(key, {nodes: members, edgeCount});
  }
  const clusters = [...clusterMap.values()]
    .sort((a, b) => b.edgeCount - a.edgeCount || b.nodes.length - a.nodes.length || a.nodes.join().localeCompare(b.nodes.join()))
    .slice(0, 10);

  const nodeSummaryIndex = {};
  for (const node of nodes) {
    nodeSummaryIndex[node.id] = {name: node.name, type: node.type, summary: node.summary};
  }
  const layerList = layers.map((layer) => ({id: layer.id, name: layer.name, description: layer.description}));
  const output = {
    scriptCompleted: true,
    entryPointCandidates,
    fanInRanking,
    fanOutRanking,
    bfsTraversal,
    nonCodeFiles,
    clusters,
    layers: {count: layerList.length, list: layerList},
    nodeSummaryIndex,
    totalNodes: nodes.length,
    totalEdges: edges.length,
  };
  try {
    fs.writeFileSync(outputPath, `${JSON.stringify(output, null, 2)}\n`, 'utf8');
  } catch (error) {
    fail(`Failed to write ${outputPath}: ${error.message}`);
  }
}

main();
