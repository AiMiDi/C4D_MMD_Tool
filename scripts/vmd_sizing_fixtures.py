"""Redistributable synthetic humanoids and sparse motion for P0/P1 validation."""
import argparse
import math
from pathlib import Path
from c4d_regression_fixtures import pack, text, fixed


def bones(target=False):
    rows = [('全ての親', (0, 0, 0), -1), ('センター', (0, 9, 0), 0),
            ('グルーブ', (0, 9, 0), 1), ('下半身', (0, 9, 0), 2),
            ('上半身', (0, 10, 0), 2), ('首', (0, 14, 0), 4), ('頭', (0, 15, 0), 5)]
    for side, sign in [('左', 1), ('右', -1)]:
        first = len(rows)
        rows += [(side+'足', (sign, 9, .3), 3), (side+'ひざ', (sign, 5, -.3), first),
                 (side+'足首', (sign, 1, 0), first+1), (side+'つま先', (sign, .4, -2), first+2),
                 (side+'足IK親', (sign, 0, 0), 0), (side+'足ＩＫ', (sign, 1, 0), first+4),
                 (side+'つま先ＩＫ', (sign, .4, -2), first+5),
                 (side+'腕', (sign*2, 13, 0), 4), (side+'ひじ', (sign*4, 12, 0), first+7),
                 (side+'手首', (sign*6, 11, 0), first+8)]
    if target:
        rows = [(name, (p[0]*1.7 + ((.3 if p[0] > 0 else -.3) if name.endswith('足ＩＫ') else 0),
                       p[1]*1.35, p[2]*1.2 + (.25 if name.endswith('足') else 0)), parent)
                for name, p, parent in rows]
    return rows


def pmx(target=False):
    rows = bones(target)
    data = bytearray(b'PMX ' + pack('fB', 2., 8) + bytes([1, 0, 4, 4, 4, 4, 4, 4]))
    for value in ('Sizing target' if target else 'Sizing source', 'Sizing fixture', 'Synthetic P0/P1 fixture', ''):
        data += text(value)
    vertices = []
    for index, (name, pos, parent) in enumerate(rows):
        if name in ('全ての親', 'センター', 'グルーブ') or 'IK' in name or 'ＩＫ' in name:
            continue
        end = rows[parent][1] if parent >= 0 else (pos[0], pos[1]+1, pos[2])
        if name == '頭':
            end = (pos[0], pos[1]+(2.7 if target else 2), pos[2])
        width = .3 if target else .22
        vertices.extend([((pos[0]-width, pos[1], pos[2]), index),
                         ((pos[0]+width, pos[1], pos[2]), index), (end, index)])
    data += pack('i', len(vertices))
    for pos, bone in vertices:
        data += pack('3f3f2fBif', *pos, 0, 0, -1, 0, 0, 0, bone, 1.)
    data += pack('i', len(vertices)) + pack(f'{len(vertices)}I', *range(len(vertices)))
    data += pack('i', 0)  # textures
    data += pack('i', 1) + text('Sizing surface') + text('Sizing surface')
    data += pack('4f3ff3fB4ffiiBBi', .3, .6, .8, 1., 0, 0, 0, 10., .1, .1, .1, 1,
                 0, 0, 0, 1, 1, -1, -1, 0, 0, -1)
    data += text('') + pack('i', len(vertices))
    data += pack('i', len(rows))
    for index, (name, pos, parent) in enumerate(rows):
        is_ik = name.endswith('足ＩＫ')
        data += text(name) + text(name) + pack('3fiiH', *pos, parent, 0, 0x1e | (0x20 if is_ik else 0))
        data += pack('3f', 0, .5, 0)
        if is_ik:
            data += pack('iifi', index-3, 16, .5, 2)
            data += pack('iB3f3f', index-4, 1, -math.pi, 0, 0, -.001, 0, 0)
            data += pack('iB', index-5, 0)
    data += pack('4i', 0, 0, 0, 0)  # morphs, display, rigid, joints
    return bytes(data)


def vmd(staggered=False):
    names = ['全ての親', 'センター', 'グルーブ', '左足IK親', '右足IK親',
             '左足ＩＫ', '右足ＩＫ', '左つま先ＩＫ', '右つま先ＩＫ', '上半身']
    data = bytearray(fixed('Vocaloid Motion Data 0002', 30) + fixed('Sizing fixture', 20))
    data += pack('I', len(names)*3)
    # Each channel has shifted replicas in the 64-byte VMD block. Keep them
    # consistent, and vary the arriving key's curve to test segment ownership.
    replicas = [((0,), (4, 19, 34, 49), (8, 23, 38, 53), (12, 27, 42, 57)),
                ((1, 16), (5, 20, 35, 50), (9, 24, 39, 54), (13, 28, 43, 58)),
                ((2, 17, 32), (6, 21, 36, 51), (10, 25, 40, 55), (14, 29, 44, 59)),
                ((3, 18, 33, 48), (7, 22, 37, 52), (11, 26, 41, 56), (15, 30, 45, 60))]
    for index, name in enumerate(names):
        middle = (20 if name == '全ての親' else 11 if 'IK親' in name else 15) if staggered else 15
        for frame in (0, middle, 30):
            interpolation = bytearray(64)
            for channel, indices in enumerate(replicas):
                values = (20+channel*5, 35+frame//3, 95, 110-frame//3)
                for copies, value in zip(indices, values):
                    for position in copies:
                        interpolation[position] = value
            sign = -1 if name.startswith('右') else 1
            translation = (sign*frame/30, frame/60, -frame/15) if name != '上半身' else (0, 0, 0)
            angle = (frame/30)*.3 if name in ('全ての親', 'センター') else 0
            data += fixed(name, 15) + pack('I3f4f', frame, *translation, 0, math.sin(angle/2), 0, math.cos(angle/2))
            data += interpolation
    data += pack('5I', 0, 0, 0, 0, 0)
    return bytes(data)


def generate(output):
    output.mkdir(parents=True, exist_ok=True)
    for name, content in [('source.pmx', pmx()), ('target.pmx', pmx(True)),
                          ('motion.vmd', vmd()), ('motion-staggered.vmd', vmd(True))]:
        (output/name).write_bytes(content)


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('output', type=Path)
    generate(parser.parse_args().output)
