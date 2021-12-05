'''
This module contains the HTML generator for the documentation. Its input is the documentation database.
'''

import os
import sys
import shutil
import webbrowser
import json
import argparse
from declarations import *
from lexer import quoteHtml, CharStream

def showInBrowser(path):
    sys.stdout.write('Opening ' + path + ' in browser\n')
    webbrowser.open('file://' + path)

def fixLinks(baseId, html):
    if baseId:
        baseId += '/'
    result = []
    start = 0
    while True:
        fix = html.find('"\rlLINK', start)
        if fix < 0:
            result.append(html[start:])
            break
        end = html.index('"', fix + 7)
        pathEnd = html.rfind('/', fix, end)
        if pathEnd >= 0:
            pathEnd += 1
        else:
            pathEnd = fix+7
        path = html[fix+7:pathEnd]
        b = 0
        while True:
            b2 = baseId.find('/', b)
            p2 = path.find('/')
            if b2 >= 0 and p2 >= 0 and baseId[b:b2] == path[:p2]:
                b = b2 + 1
                path = path[p2+1:]
            else:
                break
        while True:
            b2 = baseId.find('/', b)
            if b2 >= 0:
                b = b2 + 1
                path = '../' + path
            else:
                break
        result.append(html[start:fix+1])
        result.append(path)
        start = pathEnd
    return ''.join(result)


doxDeclarations = set(['@page', '@section', '@subsection', '@subsubsection', '@paragraph'])
htmlDoctype = '<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN"\n\t"http://www.w3.org/TR/html4/strict.dtd">'
linkCss = '<link href="\rlLINKdox.css" rel="stylesheet" type="text/css"/>'

class Node(object):
    def __init__(self):
        self.owner = None
        self.children = []
        self.id = None
        self.simpleName = None
        self.name = None
        self.qname = None
        self.kind = None
        self.doc = None
        self.bases = None
        self.inherited = None
        self.stamp = 0
        self.hierarchyStamp = 0

    def initFromDocNode(self, d, initChildren):
        for x in d:
            if initChildren or x != 'children':
                self.__dict__[x] = d[x]
        i = self.id.find('@')
        self.simpleName = self.id if i < 0 else self.id[:i]
        opn = operatorName(self.simpleName)
        if opn:
            self.simpleName = 'operator ' + opn
        if not self.name:
            self.name = self.simpleName

    def fullId(self):
        s = self.id
        d = self.owner
        while d:
            s = d.id + '/' + s
            d = d.owner
        return s

    def ownerId(self):
        d = self
        while d.isNestedDox():
            d = d.owner
        s = d.id
        d = d.owner
        while d:
            s = d.id + '/' + s
            d = d.owner
        return s

    def find(self, fullId):
        decl = None
        for x in fullId.split('/'):
            if not decl:
                if x == 'root':
                    decl = self
                    while decl.owner:
                        decl = decl.owner
                else:
                    return None
            else:
                found = None
                for child in decl.children:
                    if child.id == x:
                        found = child
                        break
                if not found:
                    return None
                decl = found
        return decl

    def getDetailLink(self, owner=None):
        if self.hasOverviewPage():
            return self.ownerId() + '_detail.html#MAIN'
        else:
            return (owner or self.owner).ownerId() + '_detail.html#' + self.id

    def getLink(self, owner=None):
        if self.hasOverviewPage():
            return self.ownerId() + '.html'
        else:
            return self.getDetailLink(owner)

    def createHRef(self, text, owner=None):
        link = self.getLink(owner)
        if self.hasOverviewPage():
            return '<a href="\rlLINK' + link + '" target="Overview">' + text + '</a>'
        else:
            return '<a href="\rlLINK' + link + '" target="Detail">' + text + '</a>'

    # qualified = 0: fully-qualified name, = 1: keep outer class names, = 2: only member name 
    def replaceLinksImpl(self, cin, createLinks, qualified, fragment):
        result = ''
        parseLink = False
        while True:
            c = cin.get()
            if c == '' or (c == '\f' and not parseLink):
                if c == '\f':
                    cin.unget()
                return result
            elif c == '\r':
                c = cin.get()
                if c == 'l':
                    result += '\rl'
                elif c == 'c' or c == 'n':
                    code = c
                    name = ''
                    while True:
                        c = cin.get()
                        if c == '\f' or c == '':
                            break
                        name += c
                    if code == 'n':
                        if qualified > 0:
                            while name and (qualified > 1 or name[0].islower()):
                                i = name.find('::')
                                if i < 0:
                                    break
                                name = name[i+2:]
                        if fragment:
                            result += '<a name="' + fragment + '">' + name + '</a>'
                        else:
                            result += name
                    else:
                        decl = self.find(name)
                        if decl and decl.doc:
                            result += self.replaceLinks(decl.doc, createLinks, qualified)
                else:
                    pass
            elif c == '\b':
                parseLink = True
                text = None
                idPart = 'root'
                id = ''
            elif parseLink:
                if idPart and (c == '\f' or c == ' ' or c == '/'):
                    id += idPart
                    if c == '/':
                        id += c
                    idPart = ''
                if c == '\f':
                    decl = self.find(id)
                    if text == None:
                        if not decl:
                            text = id
                        elif decl.isDox():
                            text = self.replaceLinks(decl.qname, False, 0)
                        else:
                            text = self.replaceLinks(decl.qname, False, 1)
                    if not (createLinks and decl):
                        result += text
                    elif decl.hasOverviewPage():
                        result += '<a href="\rlLINK' + id + '.html" target="Overview">' + text + '</a>'
                    else:
                        result += '<a href="\rlLINK' + decl.owner.ownerId() + '_detail.html#' + decl.id + '" target="Detail">' + text + '</a>'
                    parseLink = False
                elif c == ' ':
                    text = self.replaceLinksImpl(cin, False, qualified, None)
                elif c != '/':
                    idPart += c
            else:
                result += c

    def replaceLinks(self, str, createLinks, qualified, fragment=None):
        cls = self
        while cls and not cls.isClass():
            cls = cls.owner
        if cls:
            str = str.replace('\rC', cls.simpleName)
        return self.replaceLinksImpl(CharStream('link', str, False), createLinks, qualified, fragment)

    def isNamespace(self):
        return self.kind == 'namespace' or self.kind == 'MAXON_REGISTRY'

    def isPage(self):
        return self.kind == '@page'

    def isDox(self):
        return self.kind in doxDeclarations

    def isNestedDox(self):
        return self.kind != '@page' and self.kind in doxDeclarations

    def isDefine(self):
        return self.kind == '#define'

    def isClass(self):
        return self.kind == 'class' or self.kind == 'struct'

    def isClassLike(self):
        return self.isClass() or self.kind == 'typealias_asclass'

    def isEnum(self):
        return self.kind == 'enum'

    def isEnumValue(self):
        return self.kind == 'enumvalue'

    def isTypeAlias(self):
        return self.kind.startswith('typealias')

    def isUsing(self):
        return self.kind == 'using'

    def isVariable(self):
        return self.kind == 'variable'

    def isConstructor(self):
        return self.kind == 'constructor'

    def isFunction(self):
        return self.kind in set(['function', 'MAXON_FUNCTION', 'MAXON_METHOD'])

    def inheritsMembers(self):
        return self.isClassLike()

    def hasOverviewPage(self):
        return self.isNamespace() or self.isClassLike() or self.isEnum() or self.isPage()

    def generateTree(self, cw):
        if self.hasOverviewPage():
            cw << '<li><a href="' + self.fullId() + '.html" target="Overview">' + quoteHtml(self.name) + '</a></li>'
        else:
            cw << '<li><a href="' + self.owner.ownerId() + '_detail.html#' + self.id + '" target="Detail">' + quoteHtml(self.name) + '</a></li>'
        if self.isNamespace() or self.kind == '@page':
            haveChildren = False
            for c in self.children if self.kind == '@page' else sorted(self.children, key=lambda x: str(x.name).upper()):
                if c.name and not c.isNestedDox():
                    if not haveChildren:
                        cw << '<ul>'
                        haveChildren = True
                    c.generateTree(cw)
            if haveChildren:
                cw << '</ul>'

    def memberOrder(self):
        if self.isDox():
            return 'A_Articles'
        elif self.isDefine():
            return 'D_Macros'
        elif self.isNamespace():
            return 'F_Registries' if self.kind == 'MAXON_REGISTRY' else 'E_Namespaces'
        elif self.isClassLike():
            return 'H_Classes'
        elif self.isTypeAlias():
            return 'J_Type Aliases'
        elif self.isEnum():
            return 'M_Enumerations'
        elif self.isEnumValue():
            return 'N_Enumeration Values'
        elif self.isConstructor():
            return 'O_Constructors'
        elif self.isFunction():
            return 'Q_Functions'
        elif self.isVariable():
            return 'S_Static Variables' if self.qname.find('static ') >= 0 else 'T_Variables'
        else:
            return 'Z_Other'

    def addNestedDox(self, members):
        for c in self.children:
            members.append(c)
            c.addNestedDox(members)

    def update(self, docNode, changeStamp):
        if docNode.get('hierarchystamp', 0) < changeStamp:
            return
        self.hierarchyStamp = changeStamp
        if docNode.get('stamp', 0) == changeStamp:
            self.initFromDocNode(docNode, False)
            self.stamp = changeStamp
        childrenMap = {}
        for c in self.children:
            childrenMap[c.id] = c
        self.children = []
        for dc in docNode.get('children', []):
            c = childrenMap.get(dc['id'], None)
            if not c:
                # dc is a new node which doesn't exist yet in the HTML tree
                c = Node()
                c.owner = self
            self.children.append(c)
            c.update(dc, changeStamp)

    def generateDoc(self, root, outdir, changeStamp):
        declToShow = None
        if changeStamp:
            if self.hierarchyStamp < changeStamp:
                return None
            if self.stamp == changeStamp:
                declToShow = self

        if not (self.isFunction() or self.isConstructor()):
            sys.stdout.write(self.fullId() + '\n')

        ow = CodeWriter(None, self, True)
        ow << htmlDoctype << '<html>' << '<head>' << linkCss << '</head>' << '<body onload="var path = this.location.href; var i = path.lastIndexOf(\'#\'); path = path.substr(0, ((i < 0) ? path.length : i) - 5) + \'_detail.html\'; if (parent.Detail.location.href.indexOf(path) != 0) parent.Detail.location.href = path;">'
        ow.incIndent(1)
        ow << '<h2><a href="\rlLINK' + self.fullId() + '_detail.html#MAIN" target="Detail">' + self.replaceLinks(self.qname, False, 0) + '</a></h2>'
        
        dw = CodeWriter(None, self, True)
        dw << htmlDoctype << '<html>' << '<head>' << linkCss << '</head>' << '<body onload="var path = this.location.href; var i = path.lastIndexOf(\'#\'); path = path.substr(0, ((i < 0) ? path.length : i) - 12) + \'.html\'; if (parent.Overview.location.href != path) parent.Overview.location.href = path;">'
        dw.incIndent(1)
        dw << '<h2><a name="MAIN">' + self.replaceLinks(self.qname, True, 0) + '</a></h2>'

        if self.doc:
            dw << self.replaceLinks(self.doc, True, 0)
        if self.isClass():
            if self.bases:
                dw << '<hr><h2>Base classes</h2>' << '<ul>'
                for base in self.bases:
                    dw << '<li>' + self.replaceLinks(base, True, 0) + '</li>'
                dw << '</ul>'

        members = []
        if self.isDox():
            self.addNestedDox(members)
        else:
            members += self.children
            inheritOrder = dict()
            if self.inheritsMembers() and self.inherited:
                index = 1
                for base, mb in self.inherited:
                    for m in mb:
                        decl = root.find(base[0] + '/' + m)
                        if decl and decl != self:
                            inheritOrder[decl.owner] = index
                            members.append(decl)
                    index += 1
            inheritOrder[self] = 0
            members = sorted(members, key=lambda x: (x.memberOrder(), inheritOrder[x.owner], x.id.upper()))
        currentType = None
        for c in members:
            if currentType != c.memberOrder():
                if currentType:
                    ow << '</ul>'
                currentType = c.memberOrder()
                if not self.isDox():
                    ow << '<h2>' + currentType[2:] + '</h2>' << '<ul>'
                    dw << '<hr><h2>' + currentType[2:] + '</h2>'
            detail = True
            if self.isDox():
                o = c
                while o != self:
                    if o.kind == '@page':
                        detail = False
                        break
                    o = o.owner
            nesting = 0
            o = c.owner
            while o != self:
                nesting += 1
                o = o.owner
                if not o:
                    nesting = 0
                    break
            ow << '<li>' + '&nbsp;' * (4*nesting) + c.createHRef(self.replaceLinks(c.qname, False, 2), self if self.inheritsMembers() else None) + '</li>'
            inherited = c.owner != self and not self.isDox()
            if c.hasOverviewPage() and not inherited:
                c.generateDoc(root, outdir, changeStamp)
                if detail:
                    dw << '<br>' + c.createHRef(self.replaceLinks(c.qname, False, 2)) + '<br>'
            else:
                if changeStamp and c.stamp == changeStamp:
                    declToShow = c
                if detail:
                    if not self.isDox():
                        dw << '<hr>'
                    h = 'h5' if c.kind == '@subsubsection' else 'h4' if c.kind == '@subsection' else 'h3'
                    dw << '<' + h + '>' + self.replaceLinks(c.qname, True, 2, c.id)  + '</' + h + '>'
                    if inherited:
                        dw << '<p>Inherited from ' + c.owner.createHRef(c.owner.replaceLinks(c.owner.qname, False, 1)) + '.</p>'
                    if c.doc:
                        dw << self.replaceLinks(c.doc, True, 0)
        if currentType:
            ow << '</ul>'

        ow << '</body>' << '</html>'
        dw << '</body>' << '</html>'

        fname = os.path.join(outdir, self.fullId() + '.html')
        dir, dummy = os.path.split(fname)
        makeDir(dir)
        baseId = self.owner.fullId() if self.owner else ''
        writeToFile(fname, fixLinks(baseId, ow.get()))
        writeToFile(fname[:-5] + '_detail.html', fixLinks(baseId, dw.get()))
        if declToShow:
            link = declToShow.getDetailLink()
            link = os.path.join(outdir, link)
            showInBrowser(os.path.abspath(link))


def transform(d):
    o = Node()
    o.initFromDocNode(d, True)
    if o.children:
        for c in o.children:
            c.owner = o
    return o


def generateImpl(root, docroot, changeStamp, args):
    outdir = args.html
    makeDir(outdir)

    if changeStamp:
        root.update(docroot, changeStamp)
    root.generateDoc(root, outdir, changeStamp)

    cw = CodeWriter(None, root, True)
    cw << htmlDoctype << '<html>' << '<head>' << fixLinks('', linkCss) << '</head>' << '<body>' << '<ul>'
    root.generateTree(cw)
    cw << '</ul>' << '</body>' << '</html>'
    writeToFile(os.path.join(outdir, 'tree.html'), cw.get())


def generate(args):
    sys.stdout.write('Reading database...\n')
    db = os.path.join(args.directory, 'dox.txt')
    dbf = open(db, 'r')
    dox = json.load(dbf, object_hook=transform)
    dbf.close()

    sys.stdout.write('Writing HTML files...\n')
    generateImpl(dox, None, None, args)

    index = dox.find('root/index')
    if index:
        title = dox.replaceLinks(index.qname, False, 0)
        index = 'root/index'
    else:
        title = 'MAXON API Documentation'
        index = 'root'
    
    cw = CodeWriter(None, dox, True)
    cw << htmlDoctype << '<html>' << '<head>' << '<title>' + title + '</title>' << linkCss << '</head>' << '<frameset cols="20%,80%">'
    cw.incIndent(1)
    cw << '<frame src="tree.html" name="Tree">'
    cw << '<frameset rows="30%,70%">'
    cw.incIndent(1)
    cw << '<frame src="' + index + '.html" name="Overview">'
    cw << '<frame src="' + index + '_detail.html" name="Detail">'
    cw << '</frameset>'
    cw << '<noframes>' << '</noframes>' << '</frameset>' << '</html>'

    outdir = args.html
    writeToFile(os.path.join(outdir, 'index.html'), fixLinks('', cw.get()))

    scriptDir = os.path.dirname(sys.argv[0])
    css = os.path.join(scriptDir, 'dox.css')
    if os.path.isfile(css):
        shutil.copyfile(css, os.path.join(outdir, 'dox.css'))

    sys.stdout.write('Copying images...\n')

    updateImages(args.directory, outdir, False)

    return dox

def updateImages(src, dest, keepExisting):
    src = os.path.join(src, 'images')
    if os.path.isdir(src):
        dest = os.path.join(dest, 'images')
        if not keepExisting:
            shutil.rmtree(dest, True)
        makeDir(dest)
        for img in os.listdir(src):
            s = os.path.join(src, img)
            d = os.path.join(dest, img)
            if not os.path.isfile(d) or os.path.getmtime(d) < os.path.getmtime(s):
                shutil.copyfile(s, d)

def main():
    parser = argparse.ArgumentParser(description='Generate MAXON API documentation database.')
    parser.add_argument('html', help='Generate HTML documentation in the specified directory.')
    parser.add_argument('directory', help='The directory of the documentation database.')
    args = parser.parse_args()

    generate(args)
    return True


if __name__ == '__main__':
    if not main():
        exit(1)
