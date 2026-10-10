"""Execute the actual upstream MoveService and emit portable reference values."""
import argparse
import hashlib
import json
import logging
from pathlib import Path
import sys
import time
from types import SimpleNamespace


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('reference_src', type=Path)
    parser.add_argument('fixtures', type=Path)
    parser.add_argument('output', type=Path)
    parser.add_argument('--motion-name', default='motion.vmd')
    parser.add_argument('--phase', choices=('movement', 'stance'), default='movement')
    args = parser.parse_args()
    sys.path.insert(0, str(args.reference_src.resolve()))
    # numpy 1.26 removed aliases still used by upstream; the mapping preserves
    # their former built-in meaning and does not replace any algorithm.
    import numpy as np
    np.float, np.int = float, int
    import utils
    from utils import MFileutils
    utils.MFileUtils = MFileutils  # upstream filename/import capitalization mismatch
    sys.modules['utils.MFileUtils'] = MFileutils
    from mmd.PmxReader import PmxReader
    from mmd.VmdReader import VmdReader
    from module.MOptions import MOptionsDataSet, MLegProcessOptions
    from service.parts.MoveService import MoveService
    from utils.MLogger import MLogger
    from utils import MServiceUtils
    MLogger.initialize(level=logging.ERROR)
    source = PmxReader(str(args.fixtures/'source.pmx')).read_data()
    target = PmxReader(str(args.fixtures/'target.pmx')).read_data()
    motion = VmdReader(str(args.fixtures/args.motion_name)).read_data()
    dataset = MOptionsDataSet(motion, source, target)
    started = time.perf_counter()
    dataset.original_xz_ratio, dataset.original_y_ratio, dataset.original_heads_tall_ratio = MServiceUtils.calc_leg_ik_ratio(dataset)
    dataset.xz_ratio = dataset.original_xz_ratio
    dataset.y_ratio = dataset.original_y_ratio
    options = SimpleNamespace(data_set_list=[dataset], max_workers=1, now_process_ctrl=None,
                              leg_options=MLegProcessOptions(), is_file=False, outout_datetime='', monitor=sys.stdout)
    if not MoveService(options).execute():
        raise RuntimeError('Upstream MoveService failed')
    if args.phase == 'stance':
        from module.MOptions import MOptions, MArmProcessOptions
        from service.parts.StanceService import StanceService
        arms = MArmProcessOptions(False, {}, False, False, False, .3, .3, .3, True)
        stance_options = MOptions('reference', logging.ERROR, 1, [dataset], arms,
                                  None, '', False, 5, sys.stdout, False, '', 0, 0, None, None, {})
        if not StanceService(stance_options).execute():
            raise RuntimeError('Upstream StanceService failed')
    elapsed = (time.perf_counter()-started)*1000
    args.output.mkdir(parents=True, exist_ok=True)
    rows = []
    for name, keys in sorted(motion.bones.items()):
        for frame, key in sorted(keys.items()):
            row = f'{name}\t{frame}\t{key.position.x():.12g}\t{key.position.y():.12g}\t{key.position.z():.12g}'
            if args.phase == 'stance':
                row += f'\t{key.rotation.x():.12g}\t{key.rotation.y():.12g}\t{key.rotation.z():.12g}\t{key.rotation.scalar():.12g}'
            rows.append(row)
    (args.output/'reference.tsv').write_text('\n'.join(rows)+'\n', encoding='utf-8')
    receipt = {'kind': 'synthetic-upstream-' + args.phase, 'upstream_revision': 'e5c3035',
               'input_sha256': {name: hashlib.sha256((args.fixtures/name).read_bytes()).hexdigest()
                                for name in ('source.pmx', 'target.pmx', args.motion_name)},
               'options': {'movement_multiplier': 1, 'leg_offset': 0},
               'horizontal_ratio': dataset.xz_ratio, 'vertical_ratio': dataset.y_ratio,
               'elapsed_ms': elapsed, 'keys': len(rows), 'runtime_compatibility': ['numpy.float=float', 'numpy.int=int', 'MFileUtils filename alias'],
               'local_offsets': {n: [b.local_offset.x(), b.local_offset.y(), b.local_offset.z()]
                                 for n, b in target.bones.items() if b.local_offset.lengthSquared() > 0}}
    (args.output/'reference.json').write_text(json.dumps(receipt, ensure_ascii=False, indent=2), encoding='utf-8')
    print(json.dumps(receipt, ensure_ascii=True))


if __name__ == '__main__':
    main()
