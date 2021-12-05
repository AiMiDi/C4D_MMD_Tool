'''
MAXON API Parsed Header Generator
This generates the ph files.
'''

import os
import pickle
from declarations import *


def process(args, file, root):
    fdir, basename = os.path.split(file)
    dir = os.path.join(args.generated, 'parsed')

    basename, ext = os.path.splitext(basename)
    if ext != '.cpp' and ext != '.h':
        return None

    parsed = os.path.join(dir, fdir)
    makeDir(parsed)
    parsed = os.path.join(parsed, basename + '.p' + ext[1:])
    if ext == '.cpp' and root:
        if not root.snippets:
            removeFile(parsed)
            return None

    if root:
        pf = open(parsed, 'wb')
        pickle.dump(root, pf, pickle.HIGHEST_PROTOCOL)
        pf.close()

    return None


def processesFilesWithError():
    return False


def done(args, results, sources, msg, err):
    if err:
        return (msg, err)
    cleanupGeneratedFiles(args, 'parsed', lambda e: (e == '.ph' or e == '.pcpp') and '.' + e[2:], sources)
    return (msg, err)
