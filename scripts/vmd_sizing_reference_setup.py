"""Build a pinned upstream P0 reference in an isolated directory, never in its checkout.

Run with the dedicated Python 3.10 environment described in docs/dev/vmd-sizing.md.
Compatibility edits remove unused invalid cimports only; algorithm bodies are unchanged.
"""
import argparse
import hashlib
import json
from pathlib import Path
import shutil
import subprocess
import sys

PIN = 'e5c30358696f688c96544e3af33ea9871961487d'
MODULES = ['module/MMath', 'module/MParams', 'module/MOptions', 'mmd/PmxData',
           'mmd/VmdData', 'utils/MBezierUtils', 'utils/MServiceUtils']


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('upstream', type=Path)
    parser.add_argument('output', type=Path)
    parser.add_argument('--advanced', action='store_true', help='Also compile the original stance and arm services')
    args = parser.parse_args()
    revision = subprocess.check_output(['git', '-C', str(args.upstream), 'rev-parse', 'HEAD'], text=True).strip()
    if revision != PIN:
        raise RuntimeError(f'Expected {PIN}, found {revision}')
    dirty = subprocess.check_output(['git', '-C', str(args.upstream), 'status', '--porcelain', '--', 'src'], text=True)
    if dirty.strip():
        raise RuntimeError('Pinned reference requires an unchanged src tree; source hashes must describe the pinned revision')
    target = args.output.resolve() / 'reference-src'
    if target.exists():
        raise RuntimeError(f'Reference directory already exists: {target}; reuse it or choose a fresh output')
    if args.upstream.resolve() in target.parents:
        raise RuntimeError('Output must be outside upstream')
    shutil.copytree(args.upstream / 'src', target)
    receipt = {'revision': revision, 'source_sha256': {}, 'compatibility_edits': [], 'python': sys.version}
    for original in sorted((args.upstream / 'src').rglob('*')):
        if original.suffix not in ('.py', '.pyx', '.pxd'):
            continue
        relative = original.relative_to(args.upstream / 'src')
        receipt['source_sha256'][relative.as_posix()] = hashlib.sha256(original.read_bytes()).hexdigest()
        copy = target / relative
        before = copy.read_text(encoding='utf-8-sig')
        after = '\n'.join(line for line in before.split('\n')
                          if not line.startswith('from libcpp cimport') and line != 'cimport bezier._curve')
        if after != before:
            copy.write_text(after, encoding='utf-8')
            receipt['compatibility_edits'].append({'file': relative.as_posix(),
                                                 'reason': 'Remove unused invalid libcpp/broken bezier Cython imports',
                                                 'patched_sha256': hashlib.sha256(copy.read_bytes()).hexdigest()})
    modules = MODULES + (['service/parts/StanceService', 'service/parts/ArmAvoidanceService',
                          'service/parts/ArmAlignmentService'] if args.advanced else [])
    receipt['modules'] = modules
    # Explicit build list excludes wx GUI.
    setup = """from setuptools import setup, Extension
from Cython.Build import cythonize
import numpy
names = %r
setup(ext_modules=cythonize([Extension(n.replace('/', '.'), [n+'.pyx'], include_dirs=[numpy.get_include(), '.']) for n in names], compiler_directives={'language_level': 3}))
""" % modules
    (target / 'setup_reference.py').write_text(setup, encoding='utf-8')
    args.output.mkdir(parents=True, exist_ok=True)
    import importlib.metadata
    receipt['dependencies'] = {n: importlib.metadata.version(n) for n in
                               ('numpy', 'numpy-quaternion', 'bezier', 'Cython', 'setuptools', 'scipy')}
    (args.output / 'reference-build.json').write_text(json.dumps(receipt, indent=2), encoding='utf-8')
    with (args.output / 'reference-build.log').open('w', encoding='utf-8') as log:
        completed = subprocess.run([sys.executable, 'setup_reference.py', 'build_ext', '--inplace'],
                                   cwd=target, stdout=log, stderr=subprocess.STDOUT)
    receipt['build_exit_code'] = completed.returncode
    (args.output / 'reference-build.json').write_text(json.dumps(receipt, indent=2), encoding='utf-8')
    if completed.returncode:
        raise RuntimeError(f'Build failed; inspect {args.output / "reference-build.log"}')
    print(target)


if __name__ == '__main__':
    main()
