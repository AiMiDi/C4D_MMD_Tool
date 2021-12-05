'''
MAXON API Summary Generator
This generates the summary files for frameworks.
'''

import os
import json
from declarations import *

def removeTemplate(str):
    t = str.find('<')
    return str if t < 0 else str[:t]

def processTree(node, lines):
    for c in node.children:
        if isinstance(c, Class) and c.interface == Class.VIRTUAL:
            methods = set()
            for m in c.children:
                if isinstance(m, Function) and m.kind == 'MAXON_METHOD':
                    methods.add(operatorId(m.name, None) or m.name)
            lines.append(c.qname(None, '.') + '\t' + str(c.id) + '\t' + str(c.name.pos) + '\t' + ','.join(removeTemplate(str) for str, g in c.baseInterfaces).replace('::', '.') + '\t' + ','.join(sorted(methods)) \
                         + ('\tsingleImpl=true' if c.singleImpl else '') + ('\ttemplate=' + str(len(c.template.params)) if c.template else '') + ('\tgeneric=true' if c.generic else '') + ('\thasStaticMethods=true' if c.hasStaticMethods else '') + '\t')
                
        else:
            processTree(c, lines)


def processesFilesWithError():
    return True


def process(args, file, root):
    if not root:
        return None
    fdir, basename = os.path.split(file)
    dir = os.path.join(args.generated, 'summary')

    outputDir = os.path.join(dir, fdir)
    makeDir(outputDir)

    basename, ext = os.path.splitext(basename)
    if ext == '.h':
        output = os.path.join(outputDir, basename + '.sum')
        
        lines = []
        processTree(root, lines)
        if lines:
            writeToFile(output, '\n'.join(lines) + '\n')
        else:
            removeFile(output)

    output = os.path.join(outputDir, basename + '.sn' + ext[1:])
    if root.snippets:
        d = dict()
        for k in root.snippets:
            d[k], dummy = root.snippets[k]
        writeToFile(output, json.dumps(d, separators=(',', ':'), indent=1))
    else:
        removeFile(output)
        
    return None

def done(args, results, sources, msg, err):
    # We have to proceed even in case of an error: The error might be caused by an outdated summary information of the current project,
    # so we'd never get rid of the error if we didn't update the summary information.
    cleanupGeneratedFiles(args, 'summary', lambda e: e == '.sum' and '.h', sources)
    cleanupGeneratedFiles(args, 'summary', lambda e: (e == '.snh' or e == '.sncpp') and '.' + e[3:], sources)
    dir = os.path.join(args.generated, 'summary')
    all = dict()
    snippets = dict()
    for root, dirs, files in os.walk(dir):
        for file in files:
            if file.endswith('.sum'):
                file = os.path.join(root, file)
                f = open(file)
                for line in f:
                    parts = line.split('\t')
                    if parts[0] in all:
                        err = True
                        msg += pos + ': error: Duplicate definition of ' + parts[0] + '\n'
                    else:
                        all[parts[0]] = '\t'.join(parts[1:])
                f.close()
            elif file.endswith('.snh') or file.endswith('.sncpp'):
                file = os.path.join(root, file)
                f = open(file)
                snippets.update(json.load(f))
                f.close()
    
    file = os.path.join(dir, 'framework.summary')
    if all:
        writeToFile(file, ''.join([x+'\t'+all[x] for x in sorted(all)]))
    else:
        removeFile(file)
    file = os.path.join(dir, 'snippets.json')
    if snippets:
        writeToFile(file, json.dumps(snippets, separators=(',', ':'), indent=1))
    else:
        removeFile(file)
    return (msg, err)
