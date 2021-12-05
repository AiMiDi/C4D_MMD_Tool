'''
MAXON API Summary Generator
This generates the summary files for frameworks.
'''

import os
from declarations import *


def processTree(node, lines):
    for c in node.children:
        if isinstance(c, Class) and c.interface == Class.VIRTUAL:
            methods = set()
            for m in c.children:
                if isinstance(m, Function) and m.kind == 'MAXON_METHOD':
                    methods.add(operatorId(m.name, None) or m.name)
            lines.append(c.qname(None, '.') + '=' + str(c.name.pos) + '=' + ','.join(c.baseInterfaces).replace('::', '.') + ':' + ','.join(sorted(methods)))
        else:
            processTree(c, lines)


def processesFilesWithError():
    return True


def process(args, file, root):
    if not root:
        return None
    fdir, basename = os.path.split(file)
    dir = os.path.join(args.directory, 'generated', 'summary')

    basename, ext = os.path.splitext(basename)
    if ext != '.h':
        return None

    output = os.path.join(dir, fdir)
    makeDir(output)
    output = os.path.join(output, basename + '.sum')

    lines = []
    processTree(root, lines)
    if lines:
        writeToFile(output, '\n'.join(lines) + '\n')
    else:
        removeFile(output)

    return None

def done(args, results, sources, msg, err):
    # We have to proceed even in case of an error: The error might be caused by an outdated summary information of the current project,
    # so we'd never get rid of the error if we didn't update the summary information.
    cleanupGeneratedFiles(args, 'summary', lambda e: e == '.sum' and '.h', sources)
    dir = os.path.join(args.directory, 'generated', 'summary')
    all = dict()
    for root, dirs, files in os.walk(dir):
        for file in files:
            if file.endswith('.sum'):
                file = os.path.join(root, file)
                f = open(file)
                for line in f:
                    key, pos, value = line.strip().split('=')
                    if key in all:
                        err = True
                        msg += pos + ': error: Duplication definition of ' + key + '\n'
                    else:
                        all[key] = value
                f.close()
    
    file = os.path.join(dir, 'framework.summary')
    if all:
        writeToFile(file, ''.join([x+'='+all[x]+'\n' for x in sorted(all)]))
    else:
        removeFile(file)
    return (msg, err)
