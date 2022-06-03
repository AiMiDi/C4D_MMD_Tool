'''
MAXON API Example Dump Generator
This just dumps the parsed declarations of the header files to stdout.
'''

import sys
from declarations import *


def processTree(e, result, indent):
    result += indent + e.declstr() + '\n'
    for c in e.children:
        result = processTree(c, result, indent + '  ')
    return result


def process(args, header, root):
    return '' # comment out this line to dump the declaration trees to stdout 
    result = header + ':\n'
    if root:
        result = processTree(root, result, '')
    else:
        result += '\t(not modified since last run)\n'
    return result


def processesFilesWithError():
    return False


def done(args, results, sources, msg, err):
    for s in results:
        sys.stdout.write(s)
    return (msg, err)
