const fs = require('fs');
const path = require('path');

const uaDir = process.argv[2];
const gitCommitHash = process.argv[3];
if (!uaDir || !gitCommitHash) {
  throw new Error('Usage: node ua-assemble-final.cjs <ua-dir> <git-commit-hash>');
}

const intermediate = path.join(uaDir, 'intermediate');
const readJson = (name) => JSON.parse(fs.readFileSync(path.join(intermediate, name), 'utf8'));
const scan = readJson('scan-result.json');
const assembled = readJson('assembled-graph.json');
const rawLayers = readJson('layers.json');
const rawTour = readJson('tour.json');
const layers = Array.isArray(rawLayers) ? rawLayers : rawLayers.layers;
const tour = Array.isArray(rawTour) ? rawTour : (rawTour.steps || rawTour.tour);

if (!Array.isArray(layers) || !Array.isArray(tour)) {
  throw new Error('layers or tour is not an array');
}

const nodeIds = new Set(assembled.nodes.map((node) => node.id));
for (const layer of layers) {
  if (!layer.id || !layer.name || !layer.description || !Array.isArray(layer.nodeIds)) {
    throw new Error(`Invalid layer shape: ${JSON.stringify(layer)}`);
  }
  layer.nodeIds = layer.nodeIds.filter((id) => nodeIds.has(id));
}
for (const step of tour) {
  if (!Number.isInteger(step.order) || !step.title || !step.description || !Array.isArray(step.nodeIds)) {
    throw new Error(`Invalid tour shape: ${JSON.stringify(step)}`);
  }
  step.nodeIds = step.nodeIds.filter((id) => nodeIds.has(id));
}
tour.sort((a, b) => a.order - b.order);

const graph = {
  version: '1.0.0',
  project: {
    name: scan.name,
    languages: scan.languages,
    frameworks: scan.frameworks,
    description: scan.description,
    analyzedAt: new Date().toISOString(),
    gitCommitHash,
  },
  nodes: assembled.nodes,
  edges: assembled.edges,
  layers,
  tour,
};

fs.writeFileSync(
  path.join(intermediate, 'assembled-graph.json'),
  `${JSON.stringify(graph, null, 2)}\n`,
);
process.stdout.write(
  `Assembled final graph: ${graph.nodes.length} nodes, ${graph.edges.length} edges, ` +
  `${graph.layers.length} layers, ${graph.tour.length} tour steps\n`,
);
