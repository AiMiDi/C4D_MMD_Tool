'''
Maxon API Unity Group File Creator
'''

import os
import sys
import argparse
import locale
from declarations import *

locale.setlocale(locale.LC_ALL, '')
encoding = 'latin_1' if sys.version_info.major >= 3 else None
groupSize = 16

class Project(object):
    def __init__(self, dir):
        self.root = dir
        self.files = dict()
        self.output = ''
        self.index = 1
        self.count = 0

    def recurseFiles(self, dir, group):
        if os.path.isdir(dir):
            groupfile = os.path.join(dir, 'unitygroup.txt')
            if os.path.isfile(groupfile):
                group = readFile(groupfile, encoding).strip()
            for file in os.listdir(dir):
                file = os.path.join(dir, file)
                if os.path.isdir(file):
                    self.recurseFiles(file, group)
                elif file.endswith('.cpp') or file.endswith('.c'):
                    g = group
                    content = readFile(file, encoding)
                    i = content.find('MAXON_UNITY_BUILD_')
                    if i >= 0:
                        before = content[0:i]
                        if before.strip().endswith('#define'):
                            parts = content[i:].split()
                            if parts[0] == 'MAXON_UNITY_BUILD_EXCLUDE':
                                g = ''
                            elif parts[0] == 'MAXON_UNITY_BUILD_GROUP' and len(parts) >= 2:
                                g = parts[1]
                    self.files[os.path.relpath(file, self.root).replace('\\', '/')] = g

    def process(self):
        orderPath = os.path.join(self.root, 'project', 'order.txt')
        if os.path.isfile(orderPath):
            sys.stdout.write('Processing ' + self.root + '...\n')
            self.recurseFiles(os.path.join(self.root, 'source'), None)
            order = readFile(orderPath, encoding)
            for f in order.split('\n'):
                if f:
                    if f.endswith(' X'):
                        f = f[0:-2]
                    else:
                        self.addFile(f, self.files.get(f, None))
                    if f in self.files:
                        del self.files[f]
            for f in sorted(self.files):
                self.addFile(f, self.files[f])
            writeToFile(os.path.join(self.root, 'project', 'unity.txt'), self.output)
        else:
            sys.stdout.write('Skipping ' + self.root + ', no order.txt found.\n')

    def addFile(self, file, group):
        if group != '':
            if group:
                self.output += file + ' ' + str(group) + '\n'
            else:
                if self.count >= groupSize:
                    self.index += 1
                    self.count = 0
                self.count += 1
                self.output += file + ' ' + str(self.index) + '\n'


def findProjects(dir):
    projDefPath = os.path.join(dir, 'project', 'projectdefinition.txt')
    if os.path.isfile(projDefPath):
        projDef = open_23(projDefPath, 'r', newline=None)
        keys, m = parseProjectDefinition(projDef)
        projDef.close()
        if m.get('type', '').lower() != 'solution':
            project = Project(dir)
            project.process()
            return 
    if os.path.isdir(dir):
        for file in os.listdir(dir):
            file = os.path.join(dir, file)
            if os.path.isdir(file):
                findProjects(file)

parser = argparse.ArgumentParser(description='Process Maxon API order.txt and source files to generate unity.txt group files for unity builds.')
parser.add_argument('-n', action='store', type=int, default=16, help='Maximum size of unity groups, 16 by default.')
parser.add_argument('directories', nargs='+', help='A number of root directories, all subdirectories containing "project/order.txt" are processed.')
args = parser.parse_args()
groupsize = args.n

for d in args.directories:
    findProjects(os.path.abspath(d))
