const fs = require('fs');
const path = require('path');

const uaDir = process.argv[2];
const gitCommitHash = process.argv[3];
const analyzedFiles = Number(process.argv[4]);
if (!uaDir || !gitCommitHash || !Number.isInteger(analyzedFiles)) {
  throw new Error('Usage: node ua-write-meta.cjs <ua-dir> <git-commit-hash> <analyzed-files>');
}

const meta = {
  lastAnalyzedAt: new Date().toISOString(),
  gitCommitHash,
  version: '1.0.0',
  analyzedFiles,
};
fs.writeFileSync(path.join(uaDir, 'meta.json'), `${JSON.stringify(meta, null, 2)}\n`);
process.stdout.write(`Wrote meta.json for ${analyzedFiles} files\n`);
