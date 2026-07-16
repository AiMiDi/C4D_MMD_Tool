const fs = require('fs');
const path = require('path');

const intermediateDir = process.argv[2];
if (!intermediateDir) {
  throw new Error('Usage: node ua-resplit-batches.cjs <intermediate-dir>');
}

const batchPattern = /^batch-(\d+)(?:-part-(\d+))?\.json$/;
const files = fs.readdirSync(intermediateDir).filter((name) => batchPattern.test(name));
const byBatch = new Map();
for (const name of files) {
  const match = name.match(batchPattern);
  const batchIndex = Number(match[1]);
  if (!byBatch.has(batchIndex)) byBatch.set(batchIndex, []);
  byBatch.get(batchIndex).push(name);
}

const backupDir = path.join(
  path.dirname(intermediateDir),
  'tmp',
  `resplit-backup-${Date.now()}`,
);
let changed = 0;

for (const [batchIndex, names] of [...byBatch.entries()].sort((a, b) => a[0] - b[0])) {
  const fragments = names.map((name) =>
    JSON.parse(fs.readFileSync(path.join(intermediateDir, name), 'utf8')),
  );
  const needsSplit = fragments.some(
    (fragment) => fragment.nodes.length > 60 || fragment.edges.length > 120,
  );
  if (!needsSplit) continue;

  const nodeMap = new Map();
  const edgeMap = new Map();
  for (const fragment of fragments) {
    for (const node of fragment.nodes) nodeMap.set(node.id, node);
    for (const edge of fragment.edges) {
      edgeMap.set(`${edge.source}\u0000${edge.target}\u0000${edge.type}`, edge);
    }
  }

  const nodeIds = new Set(nodeMap.keys());
  const parts = [];
  let currentEdges = [];
  let currentNodeIds = new Set();

  const flushEdges = () => {
    if (!currentEdges.length) return;
    parts.push({
      nodes: [...currentNodeIds].map((id) => nodeMap.get(id)),
      edges: currentEdges,
    });
    currentEdges = [];
    currentNodeIds = new Set();
  };

  for (const edge of edgeMap.values()) {
    const localIds = [edge.source, edge.target].filter((id) => nodeIds.has(id));
    const nextIds = new Set(currentNodeIds);
    for (const id of localIds) nextIds.add(id);
    if (currentEdges.length && (currentEdges.length + 1 > 120 || nextIds.size > 60)) {
      flushEdges();
    }
    for (const id of localIds) currentNodeIds.add(id);
    currentEdges.push(edge);
  }
  flushEdges();

  const represented = new Set(parts.flatMap((part) => part.nodes.map((node) => node.id)));
  const isolated = [...nodeMap.values()].filter((node) => !represented.has(node.id));
  for (let offset = 0; offset < isolated.length; offset += 60) {
    parts.push({ nodes: isolated.slice(offset, offset + 60), edges: [] });
  }

  for (const part of parts) {
    if (part.nodes.length > 60 || part.edges.length > 120) {
      throw new Error(`Batch ${batchIndex} still exceeds limits after resplit`);
    }
  }

  fs.mkdirSync(backupDir, { recursive: true });
  for (const name of names) {
    fs.renameSync(path.join(intermediateDir, name), path.join(backupDir, name));
  }
  parts.forEach((part, index) => {
    const name = parts.length === 1
      ? `batch-${batchIndex}.json`
      : `batch-${batchIndex}-part-${index + 1}.json`;
    fs.writeFileSync(path.join(intermediateDir, name), `${JSON.stringify(part, null, 2)}\n`);
  });
  changed += 1;
  process.stdout.write(
    `batch ${batchIndex}: ${nodeMap.size} nodes, ${edgeMap.size} edges -> ${parts.length} parts\n`,
  );
}

process.stdout.write(`resplit batches: ${changed}\nbackup: ${changed ? backupDir : '<none>'}\n`);
