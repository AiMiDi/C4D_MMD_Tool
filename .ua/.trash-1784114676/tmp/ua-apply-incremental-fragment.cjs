const fs = require('fs');
const path = require('path');

const uaDir = process.argv[2];
const fragmentPath = process.argv[3];
const gitCommitHash = process.argv[4];
if (!uaDir || !fragmentPath || !gitCommitHash) {
  throw new Error('Usage: node ua-apply-incremental-fragment.cjs <ua-dir> <fragment> <git-hash>');
}

const graphPath = path.join(uaDir, 'knowledge-graph.json');
const scanPath = path.join(uaDir, 'intermediate', 'scan-result.json');
const graph = JSON.parse(fs.readFileSync(graphPath, 'utf8'));
const fragment = JSON.parse(fs.readFileSync(fragmentPath, 'utf8'));
const scan = JSON.parse(fs.readFileSync(scanPath, 'utf8'));
const replacementPaths = new Set(fragment.nodes.map((node) => node.filePath).filter(Boolean));
const replacementIds = new Set(fragment.nodes.map((node) => node.id));

const oldNodes = graph.nodes.filter((node) => replacementPaths.has(node.filePath));
const oldIds = new Set(oldNodes.map((node) => node.id));
graph.nodes = graph.nodes.filter((node) => !replacementPaths.has(node.filePath));
graph.nodes.push(...fragment.nodes);

// Preserve existing relationships when an endpoint is replaced by a node with the same canonical ID.
graph.edges = graph.edges.filter((edge) => {
  if (oldIds.has(edge.source) && !replacementIds.has(edge.source)) return false;
  if (oldIds.has(edge.target) && !replacementIds.has(edge.target)) return false;
  return true;
});
const edgeKeys = new Set(graph.edges.map((edge) => `${edge.source}\u0000${edge.target}\u0000${edge.type}`));
for (const edge of fragment.edges) {
  const key = `${edge.source}\u0000${edge.target}\u0000${edge.type}`;
  if (!edgeKeys.has(key)) {
    graph.edges.push(edge);
    edgeKeys.add(key);
  }
}

graph.project.description = scan.description;
graph.project.languages = scan.languages;
graph.project.frameworks = scan.frameworks;
graph.project.gitCommitHash = gitCommitHash;
graph.project.analyzedAt = new Date().toISOString();

const serialized = `${JSON.stringify(graph, null, 2)}\n`;
fs.writeFileSync(graphPath, serialized);
fs.writeFileSync(path.join(uaDir, 'intermediate', 'assembled-graph.json'), serialized);
process.stdout.write(
  `Replaced ${oldNodes.length} node(s) with ${fragment.nodes.length}; graph now has ` +
  `${graph.nodes.length} nodes and ${graph.edges.length} edges\n`,
);
