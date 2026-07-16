const fs = require('fs');
const path = require('path');

const projectRoot = process.argv[2];
const uaDir = process.argv[3];
const gitCommitHash = process.argv[4];
if (!projectRoot || !uaDir || !gitCommitHash) {
  throw new Error('Usage: node ua-prepare-save.cjs <project-root> <ua-dir> <git-commit-hash>');
}

const intermediate = path.join(uaDir, 'intermediate');
const assembledPath = path.join(intermediate, 'assembled-graph.json');
const graphPath = path.join(uaDir, 'knowledge-graph.json');
const scan = JSON.parse(fs.readFileSync(path.join(intermediate, 'scan-result.json'), 'utf8'));
const graph = JSON.parse(fs.readFileSync(assembledPath, 'utf8'));

fs.writeFileSync(graphPath, `${JSON.stringify(graph, null, 2)}\n`);
const input = {
  projectRoot,
  sourceFilePaths: scan.files.map((file) => file.path),
  gitCommitHash,
};
fs.writeFileSync(
  path.join(intermediate, 'fingerprint-input.json'),
  `${JSON.stringify(input, null, 2)}\n`,
);
process.stdout.write(`Saved graph and prepared ${input.sourceFilePaths.length} fingerprint paths\n`);
