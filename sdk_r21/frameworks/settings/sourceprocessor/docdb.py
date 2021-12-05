'''
This module contains the generator for the documentation database. It scans the frameworks for parsed files (*.ph, *.pcpp) and generates a database from them.

The database is a JSON file with some optimizations to avoid redundancy. Its content is a tree of nodes. Each node has the following properties:
- kind: The kind of the node, one of
  - namespace
  - class, struct
  - enum
  - enumvalue
  - typealias (for a type alias like 'using Value = Int;'), typealias_asclass (for a type alias which shall be documented as if it was a class on its own)
  - using (for a using declaration which adds members of a base class to the current class like 'using Base::Func;')
  - constructor
  - function, MAXON_FUNCTION, MAXON_METHOD
  - variable
  - #define
  - @page, @section, @subsection, @subsubsection, @paragraph
- id: The id used to refer to the node. It is unique among all siblings of the node. It starts with the simple name of the node and may optionally have
      a suffix which starts with '@' and is followed by a hash code as in 'IsIterable@Iy_ux__NVv'. So in this case the simple name of the node is 'IsIterable'.
      By concatenating the ids of the path from the root node to a given node we can uniquely identify each node as in root/maxon/StreamConversionRef/ConvertImpl@KWo37dDTSs.
- name: This property is optional. It is only present if the node has a name different from the simple name (as given by the id, see before).
      Typically this contains template parameters as in 'IsIterable<T[N]>'
- qname: The fully-qualified name. This string contains special characters, see below. An example is
      'template &lt;typename T, size_t N&gt; \rnmaxon::IsIterable&lt;T[N]&gt;\f'
- bases: Optionally present for classes or type aliases. This is a list of the base classes (or the type which is aliased by the type alias). The base classes are
      given as a list of strings with special characters, see below. 
- inherited: Optionally present when information about inherited members shall be added to the documentation of the current node. Format may change, ignore for now. 
- doc: The documentation of the node including link information and HTML formatting, see below.
- children: A list of the child nodes.

The strings in qname, bases and doc contain special characters as well as HTML formatting. The special characters indicate parts which have
to be replaced by corresponding HTML code before they can be put onto an HTML page. The special characters \b, \f and \r are used: 

The sequence \rn...\f is used within qnames and encloses the name part of the node, for example 'template &lt;typename T&gt; \rnmaxon::details::GetResultType\f'.
It can be used to find that part if one wants to remove the namespace prefixes for the documentation (just GetResultType instead of maxon::details::GetResultType).

The sequence \rc...\f can occur within the doc strings and represents the @copydoc dox command. For example '\rcroot/maxon/StreamConversionRef/ConvertImpl@KWo37dDTSs\f'
means that the documentation of the node identified by the path root/maxon/StreamConversionRef/ConvertImpl@KWo37dDTSs shall be inserted.

The two-character-marker \rC is used within qnames or doc strings. It has to be replaced by the simple name of the enclosing class. This is used for constructors and the @CLASS placeholder. 

The two-character-marker \rl is used within an HTML link to indicate that the link needs to be resolved.
Currently only links to images of the documentation are supported, then the format is as in
<img src="\rlLINK/images/matrix_o44xejbmyj2ca.png"/>

The character \b introduces an internal link. After \b the path to the linked node follows but without the root prefix. Then we have either a \f character to end the link,
or a space character followed by the text to show for the link and then the terminating \f:
\b/maxon/Set\f
\b/nodes/usernodes/usernodes_ov_instancing instances\f
The link text may contain nested special sequences, so the replacement has to be done recursively.
'''

import os
import copy
import pickle
import sys
import shutil
import json
import time
import sourceprocessor
import htmlgen
import graph
import argparse
from declarations import *
from lexer import *


cppKeywords = set(['alignas', 'alignof', 'asm', 'auto', 'bool', 'break', 'case', 'catch', 'char', 'char16_t', 'char32_t', 'class', 'const', 'constexpr', 'const_cast', 'continue',
                   'decltype', 'default', 'delete', 'do', 'double', 'dynamic_cast', 'else', 'enum', 'explicit', 'export', 'extern', 'false', 'final', 'float', 'for', 'friend', 'goto',
                   'if', 'inline', 'int', 'long', 'mutable', 'namespace', 'new', 'noexcept', 'nullptr', 'operator', 'override', 'private', 'protected', 'public', 'register', 'reinterpret_cast', 'return',
                   'short', 'signed', 'sizeof', 'static', 'static_assert', 'static_cast', 'struct', 'switch', 'template', 'this', 'thread_local', 'throw', 'true', 'try', 'typedef', 'typeid', 'typename',
                   'union', 'unsigned', 'using', 'virtual', 'void', 'volatile', 'wchar_t', 'while'])

cvQualifiers = set(['const', 'volatile'])
typeKeywords = set(['const', 'volatile', 'signed', 'unsigned', 'bool', 'char', 'short', 'int', 'long', 'float', 'double', 'char16_t', 'char32_t', 'wchar_t',
                    'Bool', 'Char', 'UChar', 'Int', 'UInt', 'Int16', 'UInt16', 'Int32', 'UInt32', 'Int64', 'UInt64', 'Float', 'Float32', 'Float64', 'Utf16Char', 'Utf32Char'])
opening = set(['(', '{', '[', '<'])

normalWhitespace = set([' ', '\t', '\n'])

# checks for MAXON API-style identifiers
def isProbablyIdentifier(t, includeCapitalized):
    if len(t) < 2:
        return False
    # check for member variables _abc or global variables g_xyz
    if t[0] == '_' or t.startswith('g_'):
        return True
    if t.find('_') >= 0:
        # check for ABC_DEF
        return t.isupper()
    else:
        # check for identifiers in camel case such as DataDictionary or myVar
        # if includeCapitalized is True then also String is considered an identifier 
        if not t.isalnum():
            return False
        return any(c.isupper() for c in (t if includeCapitalized else t[1:])) and any(c.islower() for c in t)

def isEmphasisStart(prev, lex):
    if not prev or prev.isWhitespace() or prev == '(':
        next = lex.next()
        return next and (next[0].isalpha() or next == '/' or (next == '(' and prev != '('))
    return False

def isEmphasisEnd(prev, lex):
    if not (not prev or prev.isWhitespace() or prev == '('):
        next = lex.next()
        return not next or next.isWhitespace() or next in ['/', ')', '.', ',', ':', ';']
    return False

def getFirst(list):
    return list[0] if list else None

class ResolvedDeclRef(object):
    def __init__(self, decl, owner, local):
        self.decl = decl
        self.owner = owner
        self.local = local
        self.targs = []
        self.targsMap = {}
        if decl.decl.template:
            for p in decl.decl.template.params:
                self.targsMap[p.name] = None

    def localCopy(self):
        c = ResolvedDeclRef(self.decl, self.owner, True)
        c.targs += self.targs
        c.targsMap.update(self.targsMap)
        return c

    def resolve(self, name):
        return self.decl.resolve(name)
        
    def resolveTemplateParam(self, name):
        d = self
        while d:
            arg = d.targsMap.get(name, self)
            if arg != self:
                return arg
            d = d.owner
        return None

    def toJson(self):
        return (self.decl.fullId(), [(i, self.targsMap[i][0], self.targsMap[i][1].toJson() if self.targsMap[i][1] else None) for i in self.targsMap if self.targsMap[i]])
        
    def __repr__(self):
        s = ''
        for x in self.targsMap:
            if x and self.targsMap[x]:
              s += x + '->' + str(self.targsMap[x]) + ', '
        if s:
            s = '[' + s[:-2] + ']'
        if self.owner:
            s = str(self.owner) + '::' + self.decl.decl.simpleName + s
        else:
            s = str(self.decl.decl) + s
        return s


defaultSep = set(['::'])
whitespaceStarAmpSet = set([' ', '\t', '*', '&'])

# returns (terminating token, string for expression, ResolvedDeclRef (maybe None), bool flag if the expression looks like source code)
# parseDoc==1/True: normal doxygen text
# parseDoc=2: @code snippet, preserve whitespace
def resolveExpr(scope, lex, sep, closing, createLinks, parseDoc=0, firstToken=None, returnFunctionDecl=False, recursionDetection=None, checkOverloadTypes=False):
    s = ''
    wasTypename = False
    prevToken = None
    res = None
    overloads = None
    usedOverloadStr = None
    usedOverloadToken = None
    nameBegin = -1
    source = False
    functionDecl = None
    referenceClassHelper = None
    while True:
        functionDeclSave = functionDecl
        functionDecl = None
        t = firstToken if firstToken else lex.get()
        firstToken = None
        tIsClosing = t.type == Token.EOF or t.type == Token.HTML or t.type == Token.COMMAND or t == ',' or t == '`' or t == '/' \
            or t in closing or (t.isWhitespace() and ' ' in closing) or (t == '.' and not t in sep)
        if not parseDoc and prevToken and not tIsClosing and ((prevToken.type == Token.IDENT and t.type != Token.OP_PUNCT) or (t in cvQualifiers and prevToken == '*')):
            s += ' '
        prevToken = t
        if t in sep or t == 'template':
            source = True
            s += t
        elif t in typeKeywords:
            referenceClassHelper = None
            usedOverloadStr = None
            usedOverloadToken = None
            overloads = scope.resolve(t)
            decl = getFirst(overloads)
            if decl:
                source = True
            if not decl:
                res = None
            elif not isinstance(decl, ResolvedDeclRef):
                res = ResolvedDeclRef(decl, None, False)
            elif not decl.local:
                res = decl.localCopy()
            else:
                res = decl
            if res:
                if createLinks and res.decl.isInDoc() and not res.local:
                    usedOverloadToken = t
                    usedOverloadStr = res.decl.link(t)
                    s += usedOverloadStr
                else:
                    s += t
            else:
                s += t
                res = None
        elif t.type == Token.IDENT:
            referenceClassHelperSave = referenceClassHelper
            referenceClassHelper = None
            overloads = None
            usedOverloadStr = None
            usedOverloadToken = None
            t = lex.parseOperatorPostfix(t)
            nameAdded = False
            if wasTypename or nameBegin < 0:
                if nameBegin < 0:
                    nameBegin = len(s)
                targ = scope.resolveTemplateParam(t)
                if targ:
                    res = targ[1]
                    s += targ[0]
                    nameAdded = True
                else:
                    overloads = scope.resolve(t)
                    singular = None
                    if not overloads:
                        if t.endswith('ies'):
                            singular = t[:-3] + 'y'
                        elif t.endswith('ves'):
                            singular = t[:-3] + 'f'
                        elif t.endswith('es'):
                            singular = t[:-2]
                        elif t.endswith('s'):
                            singular = t[:-1]
                        if singular:
                            overloads = scope.resolve(singular)
                            if not overloads and t.endswith('es'):
                                singular = t[:-1]
                                overloads = scope.resolve(singular)
                    decl = getFirst(overloads)
                    if not decl:
                        res = None
                    elif not isinstance(decl, ResolvedDeclRef):
                        res = ResolvedDeclRef(decl, None, False)
                    elif not decl.local:
                        res = decl.localCopy()
                    else:
                        res = decl
                    if res:
                        if singular and not isinstance(res.decl.decl, TypeDeclaration):
                            overloads = None
                            res = None
                        else:
                            source = True
            elif res:
                if t == 'ReferenceClassHelper' and isinstance(res.decl.decl, Class) and res.decl.decl.refClass:
                    referenceClassHelper = res
                overloads = res.decl.findByName(t, True)
                decl = getFirst(overloads)
                res = ResolvedDeclRef(decl, res, False) if decl else None
            if nameAdded:
                pass
            elif not parseDoc and res and res.decl.equals('maxon/ByValueParam/type') and len(res.owner.targs) == 1:
                res = res.owner.targs[0]
                s = s[:nameBegin] + 'const ' + res[0] + '&'
                res = res[1]
            elif not parseDoc and referenceClassHelperSave and t == 'type':
                t, s, res, dummy = resolveExprStr(referenceClassHelperSave, referenceClassHelperSave.decl.decl.refClass, createLinks, recursionDetection)
            elif res:
                if createLinks and res.decl.isInDoc() and not res.local:
                    usedOverloadToken = t
                    usedOverloadStr = res.decl.link(t)
                    s += usedOverloadStr
                else:
                    s += t
            else:
                s += t
                res = None
        else:
            if tIsClosing:
                return (t, s, functionDeclSave if (returnFunctionDecl and functionDeclSave) else res if nameBegin >= 0 else None, source)
            elif (t in opening) and (t != '<' or (res and res.decl.decl.template)):
                source = True
                open = t
                s += quoteHtml(t)
                c = ')' if t == '(' else '}' if t == '{' else ']' if t == '[' else '>'
                i = 0
                params = []
                while True:
                    t, u, d, dummy = resolveExpr(scope, lex, defaultSep if open == '<' else sep, set([c]), createLinks and not checkOverloadTypes, parseDoc, None, False, recursionDetection)
                    if t.type == Token.EOF:
                        open.pos.raiseError('No matching closing parenthesis found for ' + open + '.')
                    if parseDoc != 2:
                        while u and u[-1] in normalWhitespace: # don't use strip() because this removes our special \b \r \f commands
                            u = u[:-1]
                        while u and u[0] in normalWhitespace:
                            u = u[1:]
                    if u:
                        params.append((u, d))
                    if res and nameBegin >= 0 and open == '<':
                        res.targs.append((u, d))
                        if res.decl.decl.template and i < len(res.decl.decl.template.params):
                            res.targsMap[res.decl.decl.template.params[i].name] = (u, d)
                    if t == c:
                        break
                    i += 1
                if usedOverloadToken and overloads and len(overloads) > 1:
                    for decl in overloads:
                        if not isinstance(decl, ResolvedDeclRef):
                            r = ResolvedDeclRef(decl, None, False)
                        elif not decl.local:
                            r = decl.localCopy()
                        else:
                            r = decl
                        if r.decl.isInDoc() and isinstance(r.decl.decl, Function) and len(r.decl.decl.params) == len(params):
                            matchingOverload = True
                            if checkOverloadTypes:
                                for p, ud in zip(r.decl.decl.params, params):
                                    if str(p).find(ud[0]) < 0:
                                        matchingOverload = False
                                        break
                            if matchingOverload:
                                if r.decl.decl != res.decl.decl:
                                    # replace last occurrence of usedOverloadStr with new link text
                                    x = s.rsplit(usedOverloadStr, 1)
                                    s = r.decl.link(usedOverloadToken).join(x)
                                    res = r
                                break
                s += (',' if parseDoc else ', ').join(p[0] for p in params) + quoteHtml(c) 
                if open == '(' and res and isinstance(res.decl.decl, Function):
                    functionDecl = res
                    t = res.decl.decl.retType
                    while t and t[-1] in whitespaceStarAmpSet:
                        t = t[:-1]
                    if recursionDetection and t in recursionDetection:
                        d = None
                    else:
                        t, u, d, dummy = resolveExprStr(res, t, False, recursionDetection)
                    # sys.stderr.write(str(res) + '  ->  ' + res.decl.decl.retType + ' ' + t + ' ' + u + ' ' + str(d) + '\n')
                    if d:
                        res = d
                    else:
                        res = None
                        nameBegin = -1
                elif open != '<':
                    nameBegin = -1
            else:
                nameBegin = -1
                s += quoteHtml(t)
        wasTypename = t == 'typename'

def resolveExprStr(scope, str, createLinks, recursionDetection=None):
    if not recursionDetection:
        recursionDetection = set()
    else:
        recursionDetection = copy.copy(recursionDetection)
    recursionDetection.add(str)
    lex = Lexer('expr', str)
    lex.splitAngularBracket = 1
    return resolveExpr(scope, lex, defaultSep, set(), createLinks, False, None, False, recursionDetection)


class HtmlDeclstrMode(OnlySigDeclstrMode):
    def __init__(self):
        self.createLinks = True
    def quote(self, str):
        return quoteHtml(str)
    def showKind(self, e):
        return False
    def transformExpr(self, str):
        lex = Lexer('expr', str)
        lex.splitAngularBracket = 1
        dummy, s, decl, dummy2 = resolveExpr(self.scope, lex, defaultSep, set(), True, False, None, True)
        return s
    def name(self, e):
        return '' if isinstance(e, Parameter) and e.name.startswith('anonymous_param_') else e.name
    def qname(self, e):
        return e.title if isinstance(e, DoxDeclaration) else quoteHtml(e.name)
    def listTemplateParam(self, p):
        return p.name and not p.name.startswith('ANONYMOUS_PARAM_')


class HtmlQualifiedDeclstrMode(HtmlDeclstrMode):
    def qname(self, e):
        if isinstance(e, DoxDeclaration):
            str = e.title
        else:
            if e.name != 'constructor':
                str = e.qname(None, '::')
            else:
                str = '\rC::\rC'
                base = e.owner.owner
                while base and base.name:
                    str = base.name + '::' + str
                    base = base.owner
            str = quoteHtml(str)
        return '\rn' + str + '\f'


memberSep = set(['::', '.', '->', '%'])
emCommands = set(['@c', '@p', '@b', '@a', '@e', '@em'])


class HtmlStackEntry(object):
    def __init__(self, tag, indent):
        self.tag = tag
        self.indentation = indent
        self.elements = [] # list of open HTML elements

class HtmlWriter(object):
    def __init__(self):
        self.html = ''
        self.openElementsStack = [] # consists of HtmlStackEntry elements
        self.paraEnd = True
        self.startPara = False

    def push(self, element, tag, indent):
        if element:
            self.html += '<' + element + '>'
        h = HtmlStackEntry(tag, indent)
        h.elements.append(element)
        self.openElementsStack.append(h)
        return h

    def pushElement(self, element, extra=''):
        self.html += '<' + element + extra + '>'
        self.openElementsStack[-1].elements.append(element)

    def popElement(self):
        self.html += '</' + self.openElementsStack[-1].elements[-1] + '>'
        self.openElementsStack[-1].elements.pop()

    def pop(self):
        h = self.openElementsStack[-1]
        for x in reversed(h.elements):
            if x:
                self.html += '</' + x + '>'
        self.openElementsStack.pop()
        
    def __lshift__(self, code):
        if self.startPara:
            self.html += '<p></p>'
        self.html += code
        self.paraEnd = False
        self.startPara = False

    def appendParagraph(self, code):
        self.html += code
        self.paraEnd = True
        self.startPara = False

    def startParagraph(self, indent):
        while self.openElementsStack and indent <= self.openElementsStack[-1].indentation:
            self.pop()
        if not self.paraEnd:
            self.startPara = True
        self.paraEnd = True

    def startNamedSection(self, section, desc, indent):
        if indent < 0:
            if self.openElementsStack and self.openElementsStack[0].tag == section:
                while len(self.openElementsStack) > 1:
                    self.pop()
            else:
                self.startParagraph(0)
        else:
            while self.openElementsStack:
                top = self.openElementsStack[-1]
                if top.indentation < indent:
                    break
                elif top.indentation == indent and top.tag == section:
                    break
                self.pop()
        new = False
        if not self.openElementsStack or self.openElementsStack[-1].tag != section:
            new = True
            self.push('div', section, max(indent, self.openElementsStack[-1].indentation if self.openElementsStack else 0))
            self.pushElement('dl', ' class="' + section + '"')
            self.html += '<dt>' + desc + '</dt>'
            self.pushElement('dd')
            self.paraEnd = False
        else:
            self.startPara = True
            self.paraEnd = True
        return new

    def startList(self, indent, type):
        while self.openElementsStack:
            top = self.openElementsStack[-1]
            if type == '.' or top.tag != 'list':
                if top.indentation < indent:
                    break
            else:
                if top.indentation <= indent:
                    break
            self.pop()
        if type != '.':
            if not self.openElementsStack or self.openElementsStack[-1].tag != 'list' or self.openElementsStack[-1].indentation < indent:
                self.html += '\n'
                list = 'dl' if type == '=' or type == ':' else 'ol' if type == '#' else 'ul'
                self.push(list, 'list', indent)
            else:
                self.popElement()
            li = 'dt' if type == '=' else 'dd' if type == ':' else 'li'
            self.pushElement(li)
        self.startPara = False

    def finish(self):
        while self.openElementsStack:
            self.pop()
        return self.html


class LocalScope(object):
    def __init__(self, owner):
        self.owner = owner
        self.vars = {}

    def add(self, name, decl):
        self.vars[name] = decl

    def remove(self, name):
        self.vars.pop(name, None)

    def resolve(self, name):
        d = self.vars.get(name, None)
        return (d,) if d else self.owner.resolve(name)

    def resolveTemplateParam(self, name):
        return self.owner.resolveTemplateParam(name)


def normalizeDox(doc, stripSlashTriple):
    stripped = ''
    lines = []
    for line in doc:
        line = line.rstrip()
        if stripSlashTriple:
            lstr = line.lstrip()
            if lstr.startswith('///') or lstr.startswith('//!'):
                line = lstr[3:]
                if line.startswith('< ') or line.startswith('<\t'):
                    line = line[2:]
                elif line.startswith('<') or line.startswith(' ') or line.startswith('\t'):
                    line = line[1:]
        t = 0
        while True:
            t = line.find('\t', t)
            if t < 0:
                break
            line = line[:t] + (' ' if t & 1 else '  ') + line[t+1:]
        lines.append(line)
        stripped += line + '\n'
    stripped += '\n'
    return (lines, stripped)

def formatPre(code, removeIndent):
    res = '<pre>'
    codeLen = len(code)
    i = 0
    while i < codeLen:
        j = code.find('\n', i)
        if j < 0:
            j = codeLen
        line = code[i:j]
        if removeIndent >= 0 or line:
            t = 0
            while True:
                t = line.find('\t', t)
                if t < 0:
                    break
                line = line[:t] + (' ' if t & 1 else '  ') + line[t+1:]
            if removeIndent < 0:
                removeIndent = 0
                while removeIndent < len(line) and line[removeIndent].isspace():
                    removeIndent += 1
            t = 0
            while t < removeIndent and t < len(line) and line[t].isspace():
                t += 1
            res += line[t:] + '\n'
        i = j + 1
    if res.endswith('\n'):
        res = res[:-1]
    res += '</pre>'
    return (res, removeIndent)

def parseDox(doc, declref, outdir, checkOnly, errors):
    stripSlashTriple = not isinstance(declref.decl, DoxDeclaration)
    lines, stripped = normalizeDox(doc, stripSlashTriple)
    lex = Lexer(declref.fullId(), stripped)
    lex.splitAngularBracket = 1
    lex.reportWhitespace = 1
    lex.language = Lexer.DOX
    root = declref
    while root.owner:
        root = root.owner
    try:
        nextToken = None
        emptySpace = -1
        startParagraph = False
        out = HtmlWriter()
        local = LocalScope(declref)
        keywords = set(['true', 'false', 'nullptr'])
        closingSet = set([' ', '.', ',', ';', ':', ')', '}', ']'])
        sepSet = set(['::', '->', '.'])
        htmlScopeElements = set(['td', 'th'])
        noAutolink = False
        forceAutolink = False 
        prevToken = None
        headingLine = False
        while True:
            noAutolinkSave = noAutolink
            forceAutolinkSave = forceAutolink
            noAutolink = False
            forceAutolink = False 
            t = nextToken if nextToken != None else lex.get()
            nextToken = None
            if t.type == Token.EOF:
                break
            if out.openElementsStack and out.openElementsStack[-1].tag == 'em_singleword':
                if not (t.type == Token.IDENT or t.isdigit() or t in emCommands or t == '::' or (t in ['.', '-', '/'] and (lex.next().type == Token.IDENT or lex.next().isdigit()))):
                    while out.openElementsStack and out.openElementsStack[-1].tag == 'em_singleword':
                        out.pop()
            prevEmptySpace = emptySpace
            if not t.isWhitespace():
                if startParagraph:
                    out.startParagraph(prevEmptySpace)
                emptySpace = -1
                startParagraph = False
            if t == '@code' or t == '@snippet':
                lex2 = lex
                snippet = None
                codeScope = local
                if t == '@snippet':
                    t = lex.getNoEofSkipWs()
                    if checkOnly:
                        continue
                    snippet = root.decl.snippets.get(t, None)
                    if not snippet:
                        while not t.isWhitespace():
                            t = lex.getNoEof()
                        t = lex.getNoEofSkipWs()
                        snippet = root.decl.snippets.get(t, None)
                        if not snippet:
                            continue
                    codeScope = LocalScope(declref.resolveDecl(snippet[1]))
                    lex2 = Lexer(t, snippet[0])
                    lex2.splitAngularBracket = 1
                    lex2.reportWhitespace = 1
                elif lex.next() == '{':
                    lex.consume('{')
                    t = lex.getNoEof()
                    lex.consume('}')
                lex2.language = Lexer.DOX_CODE
                code = ''
                nextToken = None
                nestedDox = []
                ws = ''
                removeIndent = -1
                while True:
                    t = nextToken if nextToken != None else lex2.get()
                    nextToken = None
                    if snippet and t.type == Token.COMMENT and t.startswith('////'):
                        lex2.consume('\n')
                        if code:
                            res, removeIndent = formatPre(code, removeIndent)
                            out.appendParagraph(res)
                            code = ''
                        doxLine = t[4:]
                        if doxLine and doxLine[0].isspace():
                            doxLine = doxLine[1:]
                        nestedDox.append(Token(doxLine.rstrip(), Token.INVALID, t.pos))
                        ws = ''
                    elif t.type == Token.WHITESPACE:
                        ws += t
                    elif t.type == Token.NEWLINE:
                        if code:
                            ws += t
                        else:
                            # strip empty lines at beginning of code
                            ws = ''
                    else:
                        if nestedDox:
                            out.appendParagraph(parseDox(nestedDox, declref, outdir, checkOnly, errors))
                            nestedDox = []
                        if t.type == Token.EOF or t == '@endcode':
                            if code:
                                res, removeIndent = formatPre(code, removeIndent)
                                out.appendParagraph(res)
                            break
                        if ws:
                            code += quoteHtml(ws)
                            ws = ''
                        if prevToken not in memberSep and t.type == Token.IDENT and codeScope.resolve(t):
                            t, s, decl, dummy = resolveExpr(codeScope, lex2, sepSet, whitespaceStarAmpSet, True, 2, t)
                            code += s
                            if not decl:
                                code += quoteHtml(t)
                            else:
                                while t in whitespaceStarAmpSet:
                                    code += t
                                    t = lex2.get()
                                if t.type != Token.IDENT:
                                    nextToken = t
                                else:
                                    code += quoteHtml(t)
                                    while True:
                                        nextToken = lex2.get()
                                        if nextToken.type == Token.WHITESPACE:
                                            code += nextToken
                                        elif nextToken in ['=', ';', ',', ')']:
                                            codeScope.add(t, decl)
                                            break
                                        else:
                                            break
                        else:
                            s = quoteHtml(t)
                            # if t in cppKeywords:
                            #     s = '<b>' + s + '</b>'
                            code += s
                    prevToken = t
                lex2.language = Lexer.DOX
            elif t == '@return':
                out.startNamedSection('return', 'Returns', -1)
            elif t == '@see':
                out.startNamedSection('see', 'See also', -1)
            elif t == '@warning':
                out.startNamedSection('warning', 'Warning', prevEmptySpace)
            elif t == '@note':
                out.startNamedSection('note', 'Note', prevEmptySpace)
            elif t == '@attention':
                out.startNamedSection('attention', 'Attention', prevEmptySpace)
            elif t == '@param' or t == '@tparam':
                if t == '@param':
                    new = out.startNamedSection('params', 'Parameters', -1)
                else:
                    new = out.startNamedSection('tparams', 'Template Parameters', -1)
                if new:
                    out.pushElement('table')
                    out.pushElement('tr')
                else:
                    out.popElement()
                    out << '</tr><tr>'
                p = t
                t = lex.getNoEofSkipWs()
                dir = ''
                if t == '[':
                    while t != ']':
                        dir += t
                        t = lex.getNoEofSkipWs()
                    dir += t
                    t = lex.getNoEofSkipWs()
                # out << '<tr>'
                if p == '@param':
                    out << '<td class="paramdir">' + dir + '</td>'
                out << '<td class="paramname">' + t + '</td>'
                out.pushElement('td')
            elif t in emCommands:
                if t == '@c' or t == '@p':
                    em = Token('tt')
                elif t == '@b':
                    em = Token('b')
                else:
                    em = Token('em')
                while True:
                    nextToken = lex.get()
                    if nextToken.type != Token.WHITESPACE:
                        break
                if nextToken == '{':
                    out.push(em, 'em_brace', 10000)
                    nextToken = None
                else:
                    out.push(em, 'em_singleword', 10000)
            elif out.openElementsStack and out.openElementsStack[-1].tag == 'em_brace' and (t == '{' or t == '}'):
                if t == '{':
                    out.push(None, 'em_brace', 10000)
                else:
                    out.pop()
            elif t == '`' and not t.escaped:
                if out.openElementsStack and out.openElementsStack[-1].tag == 'backtick':
                    out.pop()
                else:
                    out.push('tt', 'backtick', 10000)
            elif t == '@link' or t == '@copydoc':
                copy = t
                t = lex.getNoEofSkipWs()
                t, s, decl, dummy = resolveExpr(declref, lex, defaultSep, closingSet, True, True, t, True, None, True)
                if copy == '@copydoc':
                    if decl:
                        out << '\rc' + decl.decl.fullId() + '\f'
                else:
                    while t.isspace():
                        t = lex.getNoEof()
                    s = ''
                    prev = None
                    while t != '@endlink':
                        if prev:
                            s += quoteHtml(prev)
                        prev = t
                        t = lex.getNoEof()
                    if prev and not prev.isWhitespace():
                        s += quoteHtml(prev)
                    if decl:
                        out << decl.decl.link(s)
                    else:
                        out << s
            elif t == '@subpage' or t == '@ref':
                ref = lex.getNoEofSkipWs()
                decl = root.doxSections.get(ref, None)
                source = False
                if decl:
                    t = lex.get()
                else:
                    t, s, decl, source = resolveExpr(declref, lex, defaultSep, closingSet, True, True, ref, True)
                    if decl:
                        decl = decl.decl
                if t.type == Token.WHITESPACE and lex.next().type == Token.STRING:
                    t = lex.getNoEof()
                dummyRef = False
                if t.type != Token.STRING:
                    nextToken = t
                else:
                    ref = t[1:-1]
                    dummyRef = not ref
                if dummyRef:
                    pass
                elif decl:
                    out << decl.link(ref if t.type == Token.STRING else None, ('<tt>', '</tt>') if source else ('', ''))
                else:
                    out << ref
            elif t == '@tableofcontents' or t == '@private' or t == '@endcond':
                pass
            elif t == '@cond':
                t = lex.getNoEofSkipWs()
            elif t == '@CLASS':
                out << '\rC'
            elif t == '@image':
                t = lex.getNoEofSkipWs()
                t = lex.getNoEofSkipWs()
                imageFile = t
                while True:
                    t = lex.get()
                    if t.type == Token.EOF or t.isWhitespace():
                        nextToken = t
                        break
                    imageFile += t
                resolved = imageFile
                for i in root.images.values():
                    path = i[0]
                    if os.name == 'nt':
                        path = path.replace('\\', '/')
                    if path.endswith(imageFile):
                        resolved = 'images/' + i[1]
                        i[2] = True
                        break
                out << '<img src="\rlLINK/' + resolved + '" alt="' + imageFile + '"/>'
            elif t.type == Token.GRAPH and graph.canBeUsed(): # otherwise, Token.GRAPH is treated like Token.VERBATIM below in the else-case
                if checkOnly:
                    graph.parseGraph(t, errors, doc[0].pos if doc else 0)
                else:
                    imgName = graph.parseGraphWriteImage(t, errors, doc[0].pos if doc else 0, os.path.join(outdir, 'images'))
                    if imgName:
                        out << '<p style="text-align:center;"><img src="\rlLINK/images/' + imgName + '"/></p>'
            elif t == '@using' or t == '@endusing':
                using = t
                if lex.get() == '{':
                    first = lex.getNoEof()
                    alias = None
                    t = lex.getNoEof()
                    if t == '=':
                        alias = first
                        first = lex.getNoEof()
                        t = lex.getNoEof()
                    decl = getFirst(declref.resolve(first))
                    while t == '::':
                        t = lex.getNoEof()
                        if decl:
                            decl = getFirst(decl.findByName(t, True))
                        t = lex.getNoEof()
                    if decl:
                        if alias:
                            if using == '@using':
                                local.add(alias, ResolvedDeclRef(decl, None, True))
                            else:
                                local.remove(alias)
                        else:
                            if using == '@using':
                                declref.usings.add(decl)
                            else:
                                declref.usings.remove(decl)
            elif t.type == Token.IDENT and t.startswith('@') and declref.framework and t[1:] in declref.framework.aliases:
                alias = t[1:]
                args = []
                begin = t.pos.pos
                if lex.next() == '{':
                    lex.get()
                    nest = 0
                    while True:
                        start = lex.cin.index
                        while True:
                            t = lex.getNoEof()
                            if not t.escaped:
                                if nest == 0 and (t == ',' or t == '}'):
                                    break
                                if t == '{':
                                    nest += 1
                                elif t == '}':
                                    nest -= 1
                        args.append(lex.cin.source[start:lex.cin.index-1])
                        if t == '}':
                            break
                for n, val in declref.framework.aliases[alias]:
                    if n == len(args):
                        s = val
                        for i in range(n):
                            s = s.replace('\\' + str(i+1), args[i])
                        lex.cin.source = lex.cin.source[:begin] + s + lex.cin.source[lex.cin.index:]
                        lex.cin.index = begin
                        lex.cin.sourceLen = len(lex.cin.source)
                        break
            elif t.type == Token.NEWLINE:
                while out.openElementsStack and out.openElementsStack[-1].tag == 'heading':
                    out.pop()
                if emptySpace >= 0:
                    startParagraph = True
                out << t
                emptySpace = 0
                headingLine = False
            elif not noAutolinkSave and prevToken not in memberSep and t.type == Token.IDENT and (forceAutolinkSave or isProbablyIdentifier(t, True)):
                if declref.findParam(t):
                    out << '<tt>' + t + '</tt>'
                else:
                    t, s, decl, source = resolveExpr(declref, lex, defaultSep, closingSet, True, True, t, False)
                    if source or forceAutolinkSave or isProbablyIdentifier(s, False):
                        out << '<tt>' + s + '</tt>'
                    else:
                        out << s
                    nextToken = t
            elif not noAutolinkSave and t.type == Token.IDENT and t in keywords:
                out << '<tt>' + t + '</tt>'
            elif t == '::' and lex.prev() and lex.prev().type != Token.IDENT:
                nextToken = lex.get()
                if nextToken.type != Token.IDENT:
                    out << t
                else:
                    nextToken, s, decl, source = resolveExpr(root, lex, defaultSep, closingSet, True, True, nextToken, False)
                    out << '<tt>' + s + '</tt>'
            elif prevEmptySpace >= 0 and (t == '@li' or (t in ['*', '-', ':', '='] and lex.next().isWhitespace()) or t == '.' or (t.isdigit() and lex.next() == '.')):
                if t != '.':
                    nextToken = lex.get()
                    if t.isdigit():
                        t = Token('#')
                        nextToken = None
                    elif nextToken == '#':
                        t = nextToken
                        nextToken = None
                out.startList(prevEmptySpace, t)
            elif t == '/' and not t.escaped and isEmphasisStart(prevToken, lex):
                em = Token('em')
                nextToken = lex.get()
                if nextToken == '/':
                    nextToken = None
                    em = Token('b')
                out.push(em, 'em_markdown', 10000)
            elif t == '/' and not t.escaped and out.openElementsStack and out.openElementsStack[-1].tag == 'em_markdown' and isEmphasisEnd(prevToken, lex):
                out.pop()
                nextToken = lex.get()
                if nextToken == '/':
                    nextToken = None
            elif (t == '%' or t == '#') and t.type != Token.ESCAPED:
                nextToken = lex.get()
                if t == '#' and headingLine:
                    pass
                elif t == '#' and prevEmptySpace >= 0 and (nextToken == '#' or nextToken.type == Token.WHITESPACE):
                    heading = 1
                    while nextToken == '#':
                        heading += 1
                        t = nextToken
                        nextToken = lex.get()
                    out.push('h' + str(heading), 'heading', -2)
                    headingLine = True
                elif nextToken.type != Token.IDENT:
                    out << t
                else:
                    if t == '%':
                        noAutolink = True
                    else:
                        forceAutolink = True
            elif t == '<table>':
                out << '<table class="doxtable">'
            else:
                isElement = False
                if t.type == Token.HTML:
                    e = t[1:-1]
                    if e.startswith('a href'):
                        if e.find('target="') < 0:
                            t = Token('<' + e + ' target="_blank">', Token.HTML, t.pos)
                    elif e in htmlScopeElements:
                        out.push(e, e, -1)
                        isElement = True
                    elif t[1] == '/':
                        e = t[2:-1]
                        if e in htmlScopeElements:
                            while out.openElementsStack and out.openElementsStack[-1].tag != e:
                                out.pop()
                            if out.openElementsStack:
                                out.pop()
                            isElement = True
                if not isElement:
                    out << quoteHtml(t)
                    if emptySpace >= 0 and t.isWhitespace():
                        emptySpace += len(t)
            prevToken = t
        return out.finish()
    except IOError as e:
        if isinstance(e, ParserError):
            line = e.sourcePosition.line - 1
            if line >= 0 and line < len(lines):
                raise ParserError(e.sourcePosition, e.message + '\n' + lines[line], False)
        sys.stderr.write(stripped)
        raise e

def checkDox(decl, parser):
    if isinstance(decl, Declaration) and decl.doc:
        r = DeclRef(decl, None, None)
        r.doxSections = {}
        r.parentPage = {}
        r.aliases = {}
        r.images = {}
        parseDox(decl.doclist, r, None, True, parser.errors)


class DeclRef(object):
    def __init__(self, decl, owner, framework):
        self.owner = owner
        self.framework = framework
        self.children = list()
        self.prevChildren = list()
        self.inherited = dict() # ResolvedDeclRef r -> (list of inherited members of r, [minimum inheritance distance, order of insertion, r])
        self.usings = set()
        self.decl = decl
        self.id = decl.simpleName if owner else 'root'
        self.nameForFind = decl.name
        op = operatorId(self.id, None)
        if op:
            self.id = op
        i = self.id.find('@')
        if i >= 0:
            self.id = self.id[:i] + base64UrlHashCode(self.id)
        if decl.simpleName != decl.name:
            self.id += '@' + base64UrlHashCode(decl.name)
        if isinstance(decl, Function):
            unique = ','.join([p.type + ('.' if p.pack else '') for p in decl.params])
            if decl.const:
                unique += '#'
            if decl.template:
                unique += '<' + str(len(decl.template.params))
            self.id += '@' + base64UrlHashCode(unique)
        if isinstance(decl, DoxDeclaration):
            decl.title = quoteHtml(decl.title)
        if owner:
            owner.children.append(self)
            owner.childrenMap = None
        self.childrenMap = None

    def findByName(self, name, qualifiedPart=False):
        if self.childrenMap == None:
            self.childrenMap = {}
            for c in self.children + [j for i in self.inherited for j in self.inherited[i][0]]:
                if isinstance(c.decl, CppDeclaration) or isinstance(c.decl, Attribute):
                    old = self.childrenMap.get(c.nameForFind, None)
                    if c.isInDoc():                   
                        if not (old and old[0].isInDoc()):
                            self.childrenMap[c.nameForFind] = [c]
                        else:
                            self.childrenMap[c.nameForFind].append(c)
                    elif not old:
                        self.childrenMap[c.nameForFind] = [c]
        if not qualifiedPart:
            if name == 'constructor':
                return None
        elif name == self.id:
            name = 'constructor'
        return self.childrenMap.get(name, None)

    def findParam(self, name):
        if not self.instanceof(Declaration):
            return None
        p = self.decl.findParam(name)
        if p or not self.decl.template:
            return p
        return self.decl.template.findParam(name)
        
    def resolve(self, name):
        s = self
        while True:
            x = s.findByName(name)
            if x:
                return x
            for u in s.usings:
                x = u.findByName(name)
                if x:
                    return x
            if not s.owner:
                if 'defines' not in s.__dict__:
                    return None
                x = s.defines.get(name, None)
                return [x] if x else None
            s = s.owner

    def resolveDecl(self, decl):
        if decl.owner:
            p = self.resolveDecl(decl.owner)
            d = getFirst(p.findByName(decl.name, True))
            return d or p
        else:
            d = self
            while d.owner:
                d = d.owner
            return d
            
    def resolveTemplateParam(self, name):
        return None

    def treestr(self, indent=''):
        s = indent + self.decl.declstr() + '\n'
        for c in self.children:
            s += c.treestr(indent + '  ')
        return s

    def fullId(self):
        s = self.id
        d = self.owner
        while d:
            s = d.id + '/' + s
            d = d.owner
        return s

    def link(self, text, prefixPostfix=('', '')):
        id = self.fullId()[4:] # remove root prefix
        if not text:
            return prefixPostfix[0] + '\b' + id + '\f' + prefixPostfix[1]
        else:
            return '\b' + id + ' ' + text + '\f'

    def equals(self, id):
        return id.endswith(self.id) and 'root/' + id == self.fullId()

    def instanceof(self, type):
        return isinstance(self.decl, type)
 
    def isClassLike(self):
        return self.instanceof(Class) or (self.instanceof(TypeAlias) and self.decl.parseAnnotation('dox_typeAliasAsClass', False))

    def doclist(self):
        return self.decl.doclist

    def isInDoc(self):
        if self.decl.kind in ['MAXON_DATATYPE', 'MAXON_INTERFACE_INSTANTIATION']:
            return False
        d = self
        while d:
            if d.decl.access != 'public' or d.decl.simpleName == 'details' or d.decl.simpleName.lower().startswith('private'):
                return False
            if isinstance(d.decl, Function) and d.decl.deleted:
                return False
            if isinstance(d.decl, Declaration) and (d.decl.anonymous or (d.decl.name.find('<') >= 0 and not d.decl.doc)): # exclude undocumented specializations
                return False
            if d.decl.doc and (d.decl.doc.find('@markPrivate') >= 0 or d.decl.doc.find('@markInternal') >= 0 or d.decl.doc.find('@private') >= 0):
                return False
            d = d.owner
        return True

    def merge(self, decl, changedSet, framework, root):
        for c in decl.children:
            if isinstance(c, Declaration) and c.name != None:
                found = False
                for r in self.children:
                    if r.decl.name == c.name and type(r.decl) == type(c) and ((not isinstance(c, Function)) or c.equals(r.decl)):
                        found = True
                        break
                if found:
                    r.decl.merge(c, changedSet)
                else:
                    r = DeclRef(c, self, framework)
                r.merge(c, changedSet, framework, root)
                if isinstance(c, Define):
                    # Defines are stored at the scope where they were defined, but they have to be found in all scopes.
                    root.defines[c.name] = r

    def loadSnippets(self, file):
        f = open(file, 'rU')
        snippetId = None
        snippet = None
        for line in f:
            if line.lstrip().startswith('//!'):
                sid = line.lstrip()[3:].strip()
                if sid.startswith('[') and sid.endswith(']'):
                    sid = sid[1:-1].strip()
                    if sid:
                        if sid == snippetId:
                            self.decl.snippets[snippetId] = (snippet, self.decl)
                            snippetId = None
                        else:
                            snippetId = sid
                            snippet = ''
                        continue
            if snippetId:
                snippet += line
        f.close()

    def addInheritedMembers(self, tscope, public, usings, members, visited, inherited, distance):
        for base, access, generic in self.decl.bases:
            access = public and access == 'public'
            lex = Lexer('type', base)
            lex.splitAngularBracket = 1
            dummy, s, res, dummy2 = resolveExpr(tscope, lex, defaultSep, set(), False)
            while res and isinstance(res.decl.decl, TypeAlias) and res.decl.decl.bases:                
                lex = Lexer('type', res.decl.decl.bases[0][0])
                lex.splitAngularBracket = 1
                dummy, s, res2, dummy2 = resolveExpr(tscope, lex, defaultSep, set(), False)
                if not res2:
                    break
                res = res2
            if res and isinstance(res.decl.decl, Class):
                if res in inherited:
                    x = inherited[res]
                    if distance < x[1][0]:
                        x[1][0] = distance
                elif res.decl not in visited:
                    m = set()
                    m.update(members)
                    u = set()
                    u.update(usings)
                    visited.add(res.decl)
                    for i in res.decl.children:
                        if i.decl.kind != 'constructor' or 'constructor' in usings:
                            if (access and i.decl.access == 'public' and not i.decl.simpleName in members) or i.decl.simpleName in usings:
                                if not res in inherited:
                                    inherited[res] = (list(), [distance, len(inherited), res])
                                inherited[res][0].append(i)
                                m.add(i.decl.simpleName)
                                if i.decl.simpleName in u:
                                    u.remove(i.decl.simpleName)
                    res.decl.addUsings(u)
                    res.decl.addInheritedMembers(res, access, u, m, visited, inherited, distance + 1)

    def addUsings(self, usings):
        for c in self.decl.children:
            if isinstance(c, Using) and c.access == 'public':
                usings.add(c.name)

    def collectInheritedMembers(self):
        if self.isClassLike():
            members = set()
            hasCtors = False
            for c in self.children:
                if c.decl.access == 'public':
                    members.add(c.decl.simpleName)
                    if c.decl.kind == 'constructor':
                        hasCtors = True
            usings = set()
            visited = set([self])
            self.addUsings(usings)
            if not hasCtors and isinstance(self.decl, Class) and self.decl.artificial == Declaration.ARTIFICIAL_REFCLASS and self.decl.source.isError:
                usings.add('constructor')
            self.addInheritedMembers(self, True, usings, members, visited, self.inherited, 0)
            self.childrenMap = None
        if self.instanceof(Class) or self.instanceof(Namespace):
            for c in self.children:
                c.collectInheritedMembers()

    def collectSpecializationMembers(self):
        if self.instanceof(Class) and self.decl.name.find('<') >= 0:
            t = getFirst(self.owner.findByName(self.decl.simpleName, True))
            if t:
                if self.decl.doc and not t.decl.doc:
                    # the specialization is documented, but not the non-specialized template, so remove the non-specialized one
                    self.owner.children.remove(t)
                    self.owner.childrenMap = None
                    # also find the specialization when looking for the name
                    self.nameForFind = t.nameForFind
                else:
                    for c in self.children:
                        # copy documented members of specializations to non-specialized template
                        if c.decl.doc and not t.findByName(c.decl.name):
                            DeclRef(c.decl, t, c.framework)
        if self.instanceof(Class) or self.instanceof(Namespace):
            for c in self.children:
                c.collectSpecializationMembers()

    def generateDoc(self, path, output, changedSet, changeStamp):
        changed = False
        if (not changeStamp) or self.decl in changedSet: 
            if not isinstance(self.decl, Function):
                sys.stdout.write(self.decl.qname() + '\n')
            qmode = HtmlQualifiedDeclstrMode()
            qmode.scope = self
            qmode.tscope = None
            dmode = HtmlDeclstrMode()
            dmode.fragment = self.id
            dmode.scope = self
            dmode.tscope = None
            
            output['id'] = self.id
            if self.decl.kind.startswith('typealias') and self.decl.parseAnnotation('dox_typeAliasAsClass', False):
                output['kind'] = 'typealias_asclass'
            elif self.decl.kind == 'namespace' and self.decl.registry:
                output['kind'] = 'MAXON_REGISTRY'
            else:
                output['kind'] = self.decl.kind

            if self.decl.name != self.decl.simpleName:
                output['name'] = self.decl.name 
            output['qname'] = self.decl.declstr(qmode)
            if changeStamp:
                output['stamp'] = changeStamp
                changed = True
    
            comment = self.doclist()
            if comment:
                errors = sourceprocessor.ErrorList('error')
                output['doc'] = parseDox(comment, self, path, False, errors)
                for msg in errors.list:
                    sys.stderr.write(msg)
                if isinstance(self.decl, TypeDeclaration):
                    if self.decl.bases:
                        bases = []
                        for base, access, generic in self.decl.bases:
                            if access == 'public':
                                dmode.scope = self
                                dmode.tscope = None
                                bases.append(dmode.transformExpr(base))
                        if bases:
                            output['bases'] = bases
        elif not 'id' in output:
            raise Exception('Internal error: Empty output for ' + self.decl.qname())

        prevChildren = {}
        prevChildrenArray = output.pop('children', None)
        if prevChildrenArray:
            for c in prevChildrenArray:
                prevChildren[c['id']] = c
        children = []
        for c in self.children:
            if c.isInDoc():
                cd = prevChildren.get(c.id, {})
                if c.generateDoc(path, cd, changedSet, changeStamp):
                    changed = True
                children.append(cd)
        if children:
            output['children'] = children
        if changeStamp and changed:
            output['hierarchystamp'] = changeStamp
        if self.isClassLike() and self.inherited:
            output['inherited'] = list()
            s = sorted([self.inherited[i][1] for i in self.inherited])
            for dist, order, ref in s:
                output['inherited'].append((ref.toJson(), [j.id for j in self.inherited[ref][0]]))
        return changed

    def pop(self, parent, line, changedSet):
        current = self
        while current.decl.kind != parent:
            if current.decl.doclist != current.newdoclist:
                changedSet.add(current.decl)
                current.decl.doclist = current.newdoclist
                current.decl.doc = ''.join(current.newdoclist)
            if len(current.children) < len(current.prevChildren):
                changedSet.add(current.decl)
            if current.decl.kind == '@page':
                return current.owner
            current = current.owner
            if not current:
                raise IOError('Parent not found: ' + line)
        return current

    def parseDoxfileDecls(self, file, doc, changedSet, framework):
        i = 0
        docLen = len(doc)
        self.prevChildren = self.children
        self.childrenMap = None
        current = self
        sectionTags = ['@page', '@section', '@subsection', '@subsubsection', '@paragraph']
        lineNumber = 0
        page = None
        while i < docLen:
            lineNumber += 1
            j = doc.find('\n', i)
            if j < 0:
                j = docLen
            line = Token(doc[i:j], Token.INVALID, SourcePosition(file, 0, lineNumber, 0))
            parent = None
            prevTag = 'namespace'
            for t in sectionTags:
                p = line.find(t)
                mainPage = False
                if p < 0 and t == '@page':
                    p = line.find('@mainpage')
                    mainPage = True
                if p >= 0 and (p == 0 or line[p-1] != '@'):
                    x = line[:p].rstrip()
                    if x and current != self:
                        current.newdoclist.append(Token(x, Token.INVALID, SourcePosition(file, 0, lineNumber, 0)))
                    line = line[p:]
                    if mainPage:
                        # treat @mainpage like @page with fixed name index
                        line = '@page index' + line[9:]
                    parent = prevTag
                    break
                prevTag = t
            if parent:
                current = current.pop(parent, line, changedSet)
                x = line.split()
                name = x[1]
                subpage = False
                if x[0] == '@page' and name in self.parentPage:
                    subpage = True
                    current = self.parentPage[name]
                title = line[line.index(name)+len(name):].strip()
                if not title:
                    title = name

                found = False
                for e in current.children if subpage else current.prevChildren:
                    if e.decl.name == name:
                        e.prevChildren = e.children
                        e.children = []
                        e.childrenMap = None
                        e.decl.merge(DoxDeclaration(x[0], name, title, None), changedSet)
                        if not subpage:
                            if current != self:
                                current.children.append(e)
                            current.childrenMap = None
                        current = e
                        found = True
                        break
                if not found:
                    current = DeclRef(DoxDeclaration(x[0], name, title, current.decl), current, framework)
                    if changedSet:
                        changedSet.add(current.decl)
                self.doxSections[name] = current
                current.newdoclist = []
                if current.decl.kind == '@page':
                    page = current
            elif current != self:
                current.newdoclist.append(line)
                if line.find('@subpage') >= 0:
                    subpage = False
                    for x in line.split():
                        if x == '@subpage':
                            subpage = True
                        elif subpage:
                            while x and not (x[-1].isalnum() or x[-1] == '_'):
                                x = x[:-1]
                            if x:
                                self.parentPage[x] = page if page else current
                                self.parentPageOrdered.append(x)
                            subpage = False
            i = j + 1
        current.pop('namespace', '', changedSet)


def mergeWithParsed(tree, path, changedSet, framework):
    if path.endswith('.dox'):
        f = open(path, 'rU')
        doc = None
        while True:
            line = f.readline()
            if not line:
                break
            if doc != None:
                doc += line.rstrip() + '\n'
            else:
                line = line.strip()
                if line.startswith('/**'):
                    doc = line[3:].lstrip() + '\n'
        if doc:
            doc = doc.rstrip()
            if doc.endswith('*/'):
                doc = doc[:-2].rstrip() + '\n'
            tree.parseDoxfileDecls(path, doc, changedSet, framework)
    else:
        pf = open(path, 'rb')
        decls = pickle.load(pf)
        if decls:
            if path.endswith('.ph'):
                # merge parsed declarations from header with the DeclRef tree
                tree.merge(decls, changedSet, framework, tree)
            tree.decl.snippets.update(decls.snippets)
        pf.close()


def isImage(file):
    return file.endswith('.png') or file.endswith('.jpg')

globalAliases = None

# yields tuples (file, framework), where file is a dox or image file, or a framework directory
def traverseFiles(args, maindir, framework=None):
    if not framework:
        framework = globalAliases
    projDefPath = os.path.join(maindir, 'project', 'projectdefinition.txt')
    if os.path.isfile(projDefPath):
        b = not args.publicframeworks
        if not b: 
            projDef = open(projDefPath, 'rU')
            keys, m = parseProjectDefinition(projDef)
            projDef.close()
            b = m.get('publicframework', False) 
        if b:
            framework = Framework.getFramework(maindir)
            yield (maindir, framework)
            dox = os.path.join(maindir, 'dox')
            if os.path.isdir(dox):
                for x in traverseFiles(args, dox, framework):
                    yield x
    else:
        af = os.path.join(maindir, 'dox.aliases')
        if os.path.isfile(af):
            f = Framework(maindir)
            if framework:
                f.addBase(framework)
            f.parseAliases(af)
            framework = f
        for file in os.listdir(maindir):
            if file == 'kernel.framework':
                continue
            file = os.path.join(maindir, file)
            if file.endswith('.dox') or isImage(file):
                yield (file, framework)
            elif os.path.isdir(file):
                for x in traverseFiles(args, file, framework):
                    yield x

def generateDocDatabase(args):
    sys.stdout.write('Reading dox files and parsed files...\n')
    # read parsed header files
    root = Namespace('', None)
    root.root = root
    root.declarations = []
    root.snippets = {}
    root.doc = ''
    tree = DeclRef(root, None, None)
    tree.doxSections = {}
    tree.parentPage = {}
    tree.parentPageOrdered = []
    tree.images = {}
    tree.aliases = {}
    tree.defines = {}
    currentDir = None
    for fr in args.directories:
        fr = os.path.abspath(fr)
        for file, framework in traverseFiles(args, fr):
            if file.endswith('.framework') or file.endswith('.module'):
                dir = os.path.join(file, 'generated')
                dir = os.path.join(dir, 'parsed')
                if os.path.isdir(dir):
                    for d, dirs, files in os.walk(dir):
                        for f in files:
                            if f.endswith('.ph') or f.endswith('.pcpp'):
                                if d != currentDir:
                                    currentDir = d
                                    sys.stdout.write('  ' + d + '\n')
                                parsed = os.path.join(d, f)
                                mergeWithParsed(tree, parsed, set(), framework)
            elif file.endswith('.dox'):
                sys.stdout.write('  ' + file + '\n')
                mergeWithParsed(tree, file, set(), framework)
            elif isImage(file):
                dummy, fn = os.path.split(file)
                fn, ext = os.path.splitext(fn)
                tree.images[file] = [file, fn + '_' + base32HashCode(file) + ext, False]
    if args.snippets:
        for sd in args.snippets:
            for d, dirs, files in os.walk(sd):
                for f in files:
                    if f.endswith('.h') or f.endswith('.cpp'):
                        f = os.path.join(d, f)
                        if os.path.isfile(f):
                            tree.loadSnippets(f)

    for subpage in tree.parentPageOrdered:
        page = tree.parentPage[subpage]
        s = tree.doxSections.get(subpage, None)
        if s and s.decl.kind == '@page':
            s.owner.children.remove(s)
            s.owner = page
            page.children.append(s)
        else:
            sys.stderr.write('Error: No page with id ' + subpage + ' found for @subpage tag in ' + page.fullId() + '.\n')

    sys.stdout.write('Collecting inherited members...\n')
    tree.collectSpecializationMembers()
    tree.collectInheritedMembers()
 
    if args.using:
        for u in args.using:
            d = tree
            for x in u.split('::'):
                d = getFirst(d.findByName(x))
                if not d:
                    sys.stderr.write('Error: Couldn\'t resolve ' + u + ' (given as a --using command line argument).\n')
                    break
            if d:
                tree.usings.add(d)

    outdir = args.docdb
    makeDir(outdir)

    # write documentation
    # sys.stderr.write(tree.treestr() + '\n')
    sys.stdout.write('Generating database...\n')

    db = {}
    tree.generateDoc(outdir, db, set(), None)
    try:
        writeToFile(os.path.join(outdir, 'dox.txt'), json.dumps(db, separators=(',', ':'), indent=1))
    except ValueError as ve:
        sys.stderr.write('json dumps stopped with a value error exception: ' + str(ve) + '\n')
        exit(1)

    sys.stdout.write('Copying images...\n')

    imgdir = os.path.join(outdir, 'images')
    makeDir(imgdir)
    for img, dest, used in tree.images.values():
        if used:
            shutil.copyfile(img, os.path.join(imgdir, dest))

    if args.livehtml:
        watchForChanges(tree, db, args)
    sys.stdout.write('Done\n')


def modified(file, lastUpdated):
    t = os.stat(file).st_mtime
    if not file in lastUpdated:
        lastUpdated[file] = t
        return False
    if t <= lastUpdated[file]:
        return False
    lastUpdated[file] = t
    return True

frameworkCache = dict()

class Framework(object):
    def __init__(self, file):
        self.file = file
        self.bases = set()
        self.aliases = dict()

    def __str__(self):
        return self.file

    def addBase(self, base):
        self.bases.add(base)
        self.aliases.update(base.aliases)

    def parseAliases(self, aliasFile):
        f = open(aliasFile, 'rU')
        aliases = dict()
        for line in f:
            pos = line.find('=')
            if pos >= 0:
                key = line[:pos].strip()
                value = line[pos+1:].strip()
                pos = key.find('{')
                count = 0
                if pos >= 0:
                    count = key[pos+1:]
                    key = key[:pos].strip()
                    pos = count.find('}')
                    if pos >= 0:
                        count = int(count[:pos].strip())
                if not key in aliases:
                    aliases[key] = list()
                aliases[key].append((count, value))
        f.close()
        self.aliases.update(aliases)

    @staticmethod
    def getFramework(file):
        if not file in frameworkCache:
            f = Framework(file)
            global globalAliases
            if globalAliases:
                f.bases.add(globalAliases)
                f.aliases.update(globalAliases.aliases)
            for x in usedFrameworks(file, False, set()):
                b = Framework.getFramework(x)
                if b:
                    f.bases.add(b)
                    f.aliases.update(b.aliases)
            af = os.path.join(os.path.join(file, 'dox'), 'dox.aliases')
            if os.path.isfile(af):
                f.parseAliases(af)
            frameworkCache[file] = f
        return frameworkCache[file]
        

def watchForChanges(tree, docdb, args):
    rootDirs = args.directories
    args.html = args.livehtml
    args.directory = args.docdb
    args.option = None
    args.force = None
    args.singlethreaded = None
    htmlroot = htmlgen.generate(args)
    lastUpdated = {}
    changeStamp = 0
    sys.stdout.write('Ready, checking for modified files...\n')
    while True:
        changed = dict()
        for fr in rootDirs:
            fr = os.path.abspath(fr)
            for file, framework in traverseFiles(args, fr): 
                if file.endswith('.framework'):
                    frameworkChanged = False
                    srcDir = os.path.join(file, 'source')
                    if os.path.isdir(srcDir):
                        for d, dirs, files in os.walk(srcDir):
                            for f in files:
                                if f.endswith('.h') or f.endswith('.cpp'):
                                    path = os.path.join(d, f)
                                    if modified(path, lastUpdated):
                                        sys.stdout.write('Modification of ' + path + ' detected\n')
                                        pdir = os.path.join(file, 'generated')
                                        pdir = os.path.join(pdir, 'parsed')
                                        pdir = os.path.join(pdir, os.path.relpath(path, srcDir))
                                        idx = pdir.rfind('.') + 1
                                        pdir = pdir[:idx] + 'p' + pdir[idx:]
                                        changed[pdir] = framework
                                        frameworkChanged = True
                    if frameworkChanged:
                        args.directory = file
                        sourceprocessor.process(args)
                elif file.endswith('.dox'):
                    if modified(file, lastUpdated):
                        sys.stdout.write('Modification of ' + file + ' detected\n')
                        changed[file] = framework
                elif isImage(file):
                    dummy, fn = os.path.split(file)
                    fn, ext = os.path.splitext(fn)
                    tree.images[file] = [file, fn + '_' + base32HashCode(file) + ext, False]
        if changed:
            changedDecls = set()
            for c in changed:
                mergeWithParsed(tree, c, changedDecls, changed[c])
            if changedDecls:
                sys.stdout.write('Detected changes to:\n')
                for d in changedDecls:
                    sys.stdout.write('  ' + d.qname() + '\n')
                changeStamp += 1
                sys.stdout.write('Updating database...\n')
                tree.generateDoc(args.docdb, docdb, changedDecls, changeStamp)
                # writeChanged(docdb)
                sys.stdout.write('Updating images...\n')
                htmlgen.updateImages(args.docdb, args.livehtml, True)
                sys.stdout.write('Updating HTML files...\n')
                htmlgen.generateImpl(htmlroot, docdb, changeStamp, args)
                sys.stdout.write('Update done\n')
        time.sleep(2)

def writeChanged(node):
    if not 'hierarchystamp' in node:
        return
    sys.stdout.write(node['id'] + ' ' + str(node.get('stamp', 0)) + '\n')
    if 'children' in node:
        for c in node['children']:
            writeChanged(c)


def main():
    parser = argparse.ArgumentParser(description='Generate MAXON API documentation database.')
    parser.add_argument('docdb', help='Generate documentation database in the specified directory.')
    parser.add_argument('directories', nargs='+', help='A number of input directories to scan for framework directories and dox files.')
    parser.add_argument('--snippets', action='append', help='Browse the given directory for source files containing snippets. Can be given multiple times.')
    parser.add_argument('--using', action='append', help='Use the specified namespace (such as maxon or my::namespace) for automatic name resolution of the documentation.')
    parser.add_argument('--livehtml', action='store', help='Watch input files and update HTML documentation in the specified directory as soon as a change has been detected.')
    parser.add_argument('--publicframeworks', action='store_true', help='Process only frameworks with publicframework=true in their projectdefinition.txt.')
    args = parser.parse_args()

    dir = os.path.abspath(os.path.dirname(sys.argv[0]))
    af = os.path.join(dir, 'dox.aliases')
    if os.path.isfile(af):
        global globalAliases
        globalAliases = Framework(dir)
        globalAliases.parseAliases(af)

    while True:
        parent = os.path.dirname(dir)
        if not parent or parent == dir:
            break
        dir = parent
        ext = os.path.join(dir, '_external_libs')
        if os.path.isdir(ext):
            pillow = os.path.join(os.path.join(ext, 'pillow'), '3.2.0-' + sys.platform + '-' + str(sys.version_info[0]) + '.' + str(sys.version_info[1]))
            if os.path.isdir(pillow):
                sys.path.append(pillow)
            break

    generateDocDatabase(args)
    return True


if __name__ == '__main__':
    if not main():
        exit(1)
