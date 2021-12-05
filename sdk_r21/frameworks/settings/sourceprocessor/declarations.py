'''
This module contains class definitions to represent the parsed C++ header declarations of the MAXON API
'''


import os
import shutil
import stat


def intHashCode(s):
    hc = 0
    for c in s:
        hc = 31 * hc + ord(c)
    return hc


base32Table = 'abcdefghijklmnopqrstuvwxyz234567'

def base32HashCode(str):
    hash = intHashCode(str)
    result = ''
    while len(result) < 13:
        result += base32Table[hash & 31]
        hash >>= 5
        if hash == 0:
            break
    return result


base64UrlTable = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_'

# don't use Base64 for file names as this might lead to problems on case-insensitive file systems
def base64UrlHashCode(str):
    hash = intHashCode(str)
    result = ''
    while len(result) < 10:
        result += base64UrlTable[hash & 63]
        hash >>= 6
        if hash == 0:
            break
    return result

operatorDict = {'=' : 'operatorAssign',
                '+=' : 'operatorAddAssign',
                '-=' : 'operatorSubAssign',
                '*=' : 'operatorMulAssign',
                '/=' : 'operatorDivAssign',
                '%=' : 'operatorModAssign',
                '&=' : 'operatorAndAssign',
                '|=' : 'operatorOrAssign',
                '^=' : 'operatorXorAssign',
                '<<=' : 'operatorShlAssign',
                '>>=' : 'operatorShrAssign',
                '++' : 'operatorIncAssign',
                '--' : 'operatorDecAssign',
                '==' : 'operatorEq',
                '!=' : 'operatorNe',
                '>' : 'operatorGt',
                '<' : 'operatorLt',
                '>=' : 'operatorGe',
                '<=' : 'operatorLe',
                '+' : 'operatorAdd',
                '-' : 'operatorSub',
                '*' : 'operatorMul',
                '/' : 'operatorDiv',
                '%' : 'operatorMod',
                '&' : 'operatorAnd',
                '|' : 'operatorOr',
                '^' : 'operatorXor',
                '<<' : 'operatorShl',
                '>>' : 'operatorShr',
                '!' : 'operatorNot',
                '~' : 'operatorNeg',
                '[]' : 'operatorIndex',
                '()' : 'operatorCall'} 

def operatorId(name, pos):
    if not name.startswith('operator '):
        return None
    op = name[9:]
    opId = operatorDict.get(op, None)
    if opId:
        return opId
    if pos:
        pos.raiseError('Unknown operator ' + op)
    return None

def operatorName(id):
    if id.startswith('operator'):
        for op in operatorDict:
            if operatorDict[op] == id:
                return op
    return None

# Writes string s to file. If the file's content already equals s, nothing is done.
def writeToFile(file, s):
    try:
        f = open(file, 'rU')
        current = f.read()
        f.close()
    except (KeyboardInterrupt, SystemExit):
        raise
    except:
        current = None
    if current != s:
        f = open(file, 'w')
        f.write(s)
        f.close()

def makeDir(dir):
    try:
        os.makedirs(dir)
    except (KeyboardInterrupt, SystemExit):
        raise
    except:
        pass

def cleanupGeneratedFiles(args, dirname, extensionMap, sources):
    dir = os.path.join(args.generated, dirname)
    # scan directory for generated files to which the original source doesn't exist any longer
    for root, dirs, files in os.walk(dir):
        for file in files:
            n, ext = os.path.splitext(file)
            mappedExt = extensionMap(ext)
            if mappedExt:
                file = os.path.join(root, file)
                f = os.path.relpath(file, dir)
                f = f[:-len(ext)] + mappedExt
                if not f in sources:
                    removeFile(file)


# returns tuple (keys in the order they are found, dict)
def parseProjectDefinition(lines):
    m = dict()
    keys = []
    option = ''
    for line in lines:
        comm = line.find('//')
        if comm >= 0:
            line = line[:comm]
        line = line.strip()
        if line.endswith('\\'):
            option += line[:-1]
        else:
            option += line
            eq = option.find('=')
            if eq >= 0:
                key = option[:eq].strip().lower()
                option = option[eq + 1:].strip()
                m[key] = option
                keys.append(key)
            option = ''
    return (keys, m)


def findFrameworkDir(startDir, fwName):
    while True:
        parent = os.path.dirname(startDir)
        if not parent or parent == startDir:
            return None
        startDir = parent
        fwDir = os.path.join(startDir, 'frameworks', fwName)
        if os.path.isdir(fwDir):
            return fwDir


def getFrameworkId(startDir, name):
    id = name
    fwDir = findFrameworkDir(startDir, name)
    if fwDir:
        projDefPath = os.path.join(fwDir, 'project', 'projectdefinition.txt')
        projDef = open(projDefPath, 'rU')
        keys, m = parseProjectDefinition(projDef)
        projDef.close()
        id = m.get('moduleid', ('net.maxon.c4d.' if m.get('c4d', False) else 'net.maxon.') + name)
    return id


def usedFrameworks(projectDir, selfAndRecursive, visited):
    projectDir = os.path.abspath(projectDir)
    projDefPath = os.path.join(projectDir, 'project', 'projectdefinition.txt')
    projDef = open(projDefPath, 'rU')
    keys, m = parseProjectDefinition(projDef)
    projDef.close()
    frameworks = m.get('apis', None)
    if frameworks:
        for fw in frameworks.split(';'):
            fw = fw.strip()
            if fw:
                fwDir = findFrameworkDir(projectDir, fw)
                if fwDir:
                    if selfAndRecursive:
                        for x in usedFrameworks(fwDir, True, visited):
                            yield x
                    else:
                        yield fwDir
    if selfAndRecursive and not projectDir in visited:
        visited.add(projectDir)
        yield projectDir


class ErrorList(object):
    def __init__(self, prefix):
        self.prefix = ': ' + prefix + ': '
        self.list = []

    def append(self, pos, msg):
        self.list.append(str(pos) + self.prefix + msg)


class StringBuilder(object):
    def __init__(self):
        self.stringlist = []
        self.string = None

    def __iadd__(self, s):
        self.stringlist.append(s)
        self.string = None
        return self

    def __str__(self):
        if self.string == None:
            self.string = ''.join(self.stringlist)
        return self.string


class CodeWriter(object):
    def __init__(self, header, root, html=False):
        self.code = StringBuilder()
        self.header = header
        self.root = root
        self.namespace = root
        self.indent = 0
        if root:
            self.baseIndent = 0
        self.directiveCode = []
        self.html = html
        self.linebreak = True

    def setNamespace(self, ns):
        base = self.namespace
        if not base:
            return
        while ns.anonymous:
            ns = ns.owner
        qn = ns.qname()
        while base.owner and not (qn + '.').startswith(base.qname() + '.'):
            if self.indent <= 0:
                ns.name.pos.raiseError('Could not add code for namespace ' + str(ns) + ' because hxx include of ' + self.header + ' is within namespace ' + str(base))
            self << '}'
            base = base.owner
        stack = []
        self.namespace = ns
        while base.depth() != ns.depth():
            stack.append(ns)
            ns = ns.owner
        for n in reversed(stack):
            self << 'namespace ' + n.name
            self << '{'

    def __lshift__(self, code):
        if isinstance(code, Namespace):
            self.setNamespace(code)
        elif isinstance(code, CodeWriter):
            self.code += code.get()
        elif not code:
            self.code += '\n' if self.linebreak else ' '
        elif self.html:
            if code.startswith('<') and code.endswith('>') and code[1:-1].isalpha() and code not in ['<hr>', '<br>']:
                self.code += '\t' * (self.indent + self.baseIndent) + code + '\n'
                self.indent += 1
            elif code.startswith('</') and code.endswith('>') and code[2:-1].isalpha():
                self.indent -= 1
                self.code += '\t' * (self.indent + self.baseIndent) + code + '\n'
            else:
                self.code += '\t' * (self.indent + self.baseIndent) + code + '\n'
        else:
            if code == '{':
                self.code += '\t' * (self.indent + self.baseIndent) + '{\n'
                self.indent += 1
            elif code == '}' or code == '};':
                self.indent -= 1
                self.code += '\t' * (self.indent + self.baseIndent) + code + '\n'
            elif self.indent > 0 and (code == 'public:' or code == 'protected:' or code == 'private:' or code.startswith('#') or code.startswith('/// @')):
                self.code += '\t' * (self.indent + self.baseIndent - 1) + code + '\n'
            else:
                for line in code.split('\n'):
                    if self.linebreak:
                        self.code += '\t' * (self.indent + self.baseIndent) + line + '\n'
                    else:
                        self.code += line + ' '
        return self

    def __len__(self):
        return 0 if self.hasOnlyDirectiveCode() else len(self.code.stringlist)

    def get(self):
        self.beginDirective()
        if isinstance(self.root, Namespace):
            while self.indent > 0:
                self << '}'
                self.namespace = self.namespace.owner
        self.endDirective()
        return '' if self.hasOnlyDirectiveCode() else str(self.code)

    def incIndent(self, value):
        self.indent += value

    def beginDirective(self):
        if self.directiveCode != self.code.stringlist:
            self.directiveCode = None

    def endDirective(self):
        if self.directiveCode != None:
            self.directiveCode = [x for x in self.code.stringlist]

    def hasOnlyDirectiveCode(self):
        return self.directiveCode == self.code.stringlist
  
def on_rm_error( func, path, exc_info):
    # path contains the path of the file that couldn't be removed
    # let's just assume that it's read-only and unlink it.
    os.chmod(path, stat.S_IWRITE)
    os.remove(path)


# Removes file, does nothing if the file doesn't exist.
def removeFile(file, forceRemove=False):
    try:
        if forceRemove:
            shutil.rmtree(file, onerror=on_rm_error)
        else:
            os.remove(file)
    except (KeyboardInterrupt, SystemExit):
        raise
    except:
        pass


# Returns True if t is a bool type
def isBoolType(t):
    return t == 'bool' or t == 'Bool' or t == 'maxon::Bool'


# Returns True if t is a numeric type
def isNumericType(t):
    if t.startswith('maxon::'):
        t = t[7:]
    if t == 'Char' or t == 'UChar' or t == 'Utf16Char' or t == 'Utf32Char' or t == 'char' or t == 'short' or t == 'int' or t == 'long' or t == 'float' or t == 'double':
        return True
    if t.startswith('Int'):
        t = t[3:]
    elif t.startswith('UInt'):
        t = t[4:]
    elif t.startswith('Float'):
        t = t[5:]
    else:
        return False
    return not t or t == '16' or t == '32' or t == '64'


# Returns True if t is a reference to Generic type
def isGenericType(t):
    return t == 'Generic&' or t == 'maxon::Generic&' or t == 'const Generic&' or t == 'const maxon::Generic&'


def isIdentChar(c):
    return c.isalpha() or c.isdigit() or c == '_' or c == '$'


def parseAnnotation(annotations, name, default):
    a = annotations.get(name, default)
    if a == default:
        return a
    if a == 'false':
        return False
    if a == 'true':
        return True
    return a


class DefaultDeclstrMode(object):
    def quote(self, str):
        return str
    def transformExpr(self, str):
        return str
    def annotstr(self, e):
        return e.annotstr()
    def name(self, e):
        return e.name
    def qname(self, e):
        return e.title if isinstance(e, DoxDeclaration) else e.name
    def showKind(self, e):
        return True
    def listTemplateParam(self, p):
        return True

class OnlySigDeclstrMode(DefaultDeclstrMode):
    def annotstr(self, e):
        return ''

class QualifiedDeclstrMode(DefaultDeclstrMode):
    def annotstr(self, e):
        return ''
    def qname(self, e):
        return e.title if isinstance(e, DoxDeclaration) else e.qname(None, '::')


# Entity is the root class of the nodes which represent a parsed header file. The class hierarchy is as follows:
#
#   Entity
#     Directive
#     Declaration
#       Observable
#       Attribute
#       DoxDeclaration
#       CppDeclaration
#         Namespace
#         Using
#         Function
#         Variable
#         EnumValue
#         Define
#         TypeDeclaration
#          Class
#          TypeAlias
#          Enum
#
# Entity has the following attributes:
#   self.name is the name of the entity (None for directives)
#   self.owner if the parent node (such as the class for a member function or the namespace for a class declaration at namespace scope)
#   self.children is the list of all child nodes
#
# The root node of a parse tree is a Namespace node which represents the global namespace.
class Entity(object):
    DEFAULT = DefaultDeclstrMode()
    ONLYSIG = OnlySigDeclstrMode()
    QUALIFIED = QualifiedDeclstrMode()

    def __init__(self, name, owner):
        self.name = name
        self.owner = owner
        self.children = list()
        if owner:
            owner.children.append(self)
            if isinstance(owner, Namespace) and owner.root:
                owner.root.declarations.append(self)

    def find(self, type, name):
        for c in self.children:
            if c.name == name and isinstance(c, type):
                return c
        return None

    def findAll(self, type, name):
        for c in self.children:
            if c.name == name and isinstance(c, type):
                yield c

    def findOrCreate(self, name):
        c = self.find(Declaration, name)
        return c if c else Class(name, None, self, 'public', True)

    def getNamespace(self):
        c = self
        while c and not isinstance(c, Namespace):
            c = c.owner
        return c

    def lookup(self, name, closest=False):
        resolved = None
        c = self
        name = name.replace('::', '.')
        for n in name.split('.'):
            # Fallback for R20 code: maxon::Object is the same as maxon::ObjectInterface.
            if n == 'Object':
              n = 'ObjectInterface'
            if resolved:
                resolved = resolved.find(Declaration, n)
            else:
                s = self
                while s and not resolved:
                    resolved = s.find(Declaration, n)
                    s = s.owner
            if not resolved:
                return c if closest else None
            c = resolved
        return resolved

    def treestr(self, indent=''):
        s = indent + self.declstr() + '\n'
        for c in self.children:
            s += c.treestr(indent + '  ')
        return s

    @staticmethod
    def skipVersionNamespaces(e, enableSkip):
        result = e
        if enableSkip:
            while result and isinstance(result, Namespace) and result.name and result.name[0] == 'v' and result.name[1:].isdigit():
                result = result.owner
        return result

    def qname(self, base=None, sep='.', excludeVersionNamespaces=False):
        s = Entity.skipVersionNamespaces(self, excludeVersionNamespaces)
        owner = Entity.skipVersionNamespaces(s.owner, excludeVersionNamespaces)
        if owner != base and owner.owner:
            return owner.qname(base, sep, excludeVersionNamespaces) + sep + str(s.name)
        else:
            return str(s.name)

    def depth(self):
        d = 0
        x = self
        while x.owner:
            x = x.owner
            d += 1
        return d

    def __str__(self):
        return self.qname(None, '::')

    def isAncestorOfOrSame(self, other):
        while other:
            if self == other:
                return True
            other = other.owner
        return False

    def postprocess(self, callback):
        callback(self)
        for c in self.children:
            c.postprocess(callback)


# Parameter represents a parameter of a function or method.
#   self.type is the parameter type
#   self.name is the parameter name (may be None)
#   self.default is the default argument (may be None)
#   self.pack is true if this is a parameter pack
class Parameter(object):
    def __init__(self, type, name=None):
        self.type = type
        self.name = name
        self.default = None
        self.pack = False
        self.input = True
        self.output = False

    def __str__(self):
        return self.toStr()

    def __eq__(self, other):
        return self.type == other.type and self.pack == other.pack

    def __ne__(self, other):
        return not (self == other)

    def toStr(self, nodef=False, mode=Entity.DEFAULT):
        s = mode.transformExpr(self.type)
        if self.pack:
            s += '...'
        n = mode.name(self)
        if n:
            if s:
                s += ' '
            s += n
        if self.default and not nodef:
            s += ' = ' + mode.quote(self.default)
        return s

    def forward(self):
        t = self.type
        if t.endswith('&&'):
            s = 'std::forward<' + t[:-2] + '>(' + self.name + ')'
        elif t.endswith('*') or t.endswith('&') or t == 'va_list' or t.startswith('maxon::AddArrayT<') or t.startswith('maxon::AddArrayOfUnknownBoundT<'):
            s = self.name
        else:
            if t.startswith('const '):
                t = t[5:].strip()
            if isBoolType(t) or isNumericType(t):
                s = self.name
            else:
                pos = t.rfind('::')
                if pos >= 0:
                    t = t[pos+2:]
                if t.replace('_', '').isupper(): # assume that uppercase-only types are enums
                    s = self.name
                else:
                    s = 'std::forward<' + self.type + '>(' + self.name + ')'
        if self.pack:
            s += '...'
        return s


# Base class for a template parameter.
#   self.pos is the source location
#   self.name is the parameter name (may be None)
#   self.default is the default argument for the parameter (may be None)
#   self.pack is True if we have a parameter pack
# There are three derived classes: TypeTemplateParam, NontypeTemplateParam and TemplateTemplateParam
class TemplateParam(object):
    def __init__(self):
        self.pos = None
        self.pack = False
        self.name = None
        self.default = None
    def toStr(self, nodef, onlyNames, mode=Entity.DEFAULT):
        if onlyNames:
            s = self.name
            if self.pack:
                s += '...'
            return s
        s = self.declstr(mode)
        if self.pack:
            s += '...'
        if self.name and (nodef or self.default == None or not self.name.startswith('ANONYMOUS_PARAM_')):
            s += ' ' + self.name
        if not nodef and self.default != None:
            s += ' = ' + mode.transformExpr(self.default)
        return s
    def __str__(self):
        s = self.declstr()
        if self.pack:
            s += '...'
        if self.name:
            s += ' ' + self.name
        if self.default:
            s += ' = ' + self.default
        return s


# TypeTemplateParam stands for a type template parameter such as in template <typename T>
class TypeTemplateParam(TemplateParam):
    def declstr(self, mode=Entity.DEFAULT):
        return 'typename'


# NontypeTemplateParam stands for a non-type template parameter such as in template <Int N>
#   self.type is the type of the parameter
class NontypeTemplateParam(TemplateParam):
    def __init__(self, type):
        TemplateParam.__init__(self)
        self.type = type

    def declstr(self, mode=Entity.DEFAULT):
        return mode.transformExpr(self.type)


# TemplateTemplateParam stands for a template template parameter such as in template <template <typename C> class X>
#   self.template is the template declaration of the parameter
class TemplateTemplateParam(TemplateParam):
    def __init__(self, template):
        TemplateParam.__init__(self)
        self.template = template

    def declstr(self, mode=Entity.DEFAULT):
        return str(self.template) + ' class'


# Template stands for a template declaration. Its attribute params is the list of template parameters.
class Template(object):
    def __init__(self):
        self.params = []

    def findParam(self, name):
        for p in self.params:
            if p.name == name:
                return p
        return None

    def toStr(self, nodef, onlyNames, mode=Entity.DEFAULT, suffix=''):
        s = ''
        if not onlyNames:
            s = 'template '
        return s + mode.quote('<') + ', '.join(x.toStr(nodef, onlyNames, mode) + suffix for x in self.params if mode.listTemplateParam(x)) + mode.quote('>')

    def __str__(self):
        return self.toStr(False, False)
            
    def equals(self, other):
        return len(self.params) == len(other.params)

# A Directive node stands for a conditional directive such as #if and #endif, but also for Doxygen's @cond and @endcond.
# The code attribute contains the original source code line of the directive. 
class Directive(Entity):
    def __init__(self, code, owner):
        Entity.__init__(self, None, owner)
        self.code = code

    def declstr(self, mode=Entity.DEFAULT):
        return self.code


# An Include node stands for an #include directive. The name attribute contains the header name,
# the quote attribute is either < or ", depending on the #include directive.
class Include(Entity):
    def __init__(self, header, quote, owner):
        Entity.__init__(self, header, owner)
        self.quote = quote

    def declstr(self, mode=Entity.DEFAULT):
        return '#include ' + self.quote + self.name + ('>' if self.quote == '<' else '"')


# A Declaration node stands for a C++ declaration. There are subclasses Namespace, Class etc., but Declaration
# instances are also created directly for simple things such as MAXON_DATATYPE or MAXON_EXTENSION_POINT
# (i.e., without having a dedicated subclass).
#
#   self.kind is the kind of declaration and corresponds to the source code token (e.g., 'class', 'MAXON_DATATYPE')
#   seld.id is the unique identifier (including quotation marks) of the declaration such as "maxon.Object" (only valid when given explicitly in the declaration, otherwise None) 
#   self.template is the template declaration if any, otherwise None
#   self.friend is a friend token for a friend declaration, otherwise None
#   self.doclist is the Doxygen comment of the declaration as a list of tokens, may be None
#   self.doc is the concatenation of self.doclist, it will be set in postprocess
#   self.annotations is a dictionary of the annotations of the declaration
#   self.type, self.id, self.point are used in a declaration-specific way (e.g., MAXON_DECLARATION uses self.type for the type of the object)
#   self.access is 'private', 'protected' or 'public'
#   self.simpleName is the same as self.name except for specializations (where it is the name without the specialization arguments)
#   self.anonymous is True for anonymous namespaces/classes/structs/unions
class Declaration(Entity):
    ARTIFICIAL_NONE, ARTIFICIAL, ARTIFICIAL_REFCLASS = range(3)
    def __init__(self, kind, name, owner, access):
        Entity.__init__(self, name, owner)
        self.simpleName = name
        self.access = access
        self.kind = kind
        self.template = None
        self.friend = None
        self.type = None
        self.id = None
        self.point = None
        self.artificial = Declaration.ARTIFICIAL_NONE
        self.doclist = []
        self.doc = None
        self.annotations = {}
        self.anonymous = False

    def declstr(self, mode=Entity.DEFAULT):
        s = mode.annotstr(self)
        if mode.showKind(self):
            s += self.kind
        if self.template:
            s = self.template.toStr(False, False, mode) + ' ' + s
        if self.name:
            if s:
                s += ' '
            s += mode.qname(self)
        return s

    def mergeimpl(self, selfValue, otherValue, changedSet):
        if otherValue and otherValue != selfValue:
            changedSet.add(self)
            return otherValue
        return selfValue

    def merge(self, other, changedSet):
        self.doclist = self.mergeimpl(self.doclist, other.doclist, changedSet)
        self.doc = ''.join(self.doclist)
        self.annotations = self.mergeimpl(self.annotations, other.annotations, changedSet)

    def annotstr(self):
        if not self.annotations:
            return ''
        return '@MAXON_ANNOTATION(' + ', '.join(x + '=' + str(self.annotations[x]) for x in self.annotations) + ') '

    def getAnnotation(self, name, default):
        return self.annotations.get(name, default)

    def parseAnnotation(self, name, default):
        return parseAnnotation(self.annotations, name, default)

    def postprocess(self, callback):
        if self.artificial == Declaration.ARTIFICIAL_REFCLASS:
            self.doclist = self.source.doclist
        self.doc = ''.join(self.doclist)
        Entity.postprocess(self, callback)

    def addSnippet(self, snippet):
        root = self
        while root.owner:
            root = root.owner
        root.snippets[snippet.id] = (snippet, self)

    def findParam(self, name):
        return None


class Attribute(Declaration):
    def __init__(self, kind, name, owner, access):
        Declaration.__init__(self, kind, name, owner, access)


class CppDeclaration(Declaration):
    def __init__(self, kind, name, owner, access):
        Declaration.__init__(self, kind, name, owner, access)


class DoxDeclaration(Declaration):
    def __init__(self, kind, name, title, owner):
        Declaration.__init__(self, kind, name, owner, 'public')
        self.title = title

    def declstr(self, mode=Entity.DEFAULT):
        return mode.qname(self)

    def merge(self, other, changedSet):
        Declaration.merge(self, other, changedSet)
        self.title = self.mergeimpl(self.title, other.title, changedSet)


# A Function node stands for a C++ function or constructor (and also for the method which returns an observable).
#
#   self.static tells if the function is static
#   self.explicit tells if the constructor/operator is explicit
#   self.deleted tells if the function is deleted
#   self.const tells if the function is const
#   self.retType is the return type of the function
#   self.result is T if self.retType is of the form Result<T>, otherwise None
#   self.params is the Param list of the function
#
#   The inherited self.kind is either 'MAXON_METHOD', 'MAXON_FUNCTION', 'function' or 'constructor'
class Function(CppDeclaration):
    def __init__(self, kind, name, static, retType, owner, access):
        CppDeclaration.__init__(self, kind, name, owner, access)
        self.static = static
        self.explicit = False
        self.deleted = False
        self.retType = retType
        self.const = False
        self.params = []
        self.observable = None
        self.result = None
        if self.retType.startswith('Result<') or self.retType.startswith('maxon::Result<'):
            self.result = self.retType[self.retType.find('<')+1:-1]
        if static and kind == 'MAXON_METHOD' and isinstance(owner, Class):
            owner.hasStaticMethods = True

    def declstr(self, mode=Entity.DEFAULT):
        s = mode.annotstr(self)
        if mode.showKind(self):
            s += self.kind + ' '
        if self.kind != 'constructor':
            s += mode.transformExpr(self.retType) + ' '
        s += mode.qname(self) + '(' + ', '.join([x.toStr(False, mode) for x in self.params]) + ')'
        if self.static:
            s = 'static ' + s
        if self.explicit:
            s = 'explicit ' + s
        if self.template:
            s = self.template.toStr(False, False, mode) + ' ' + s
        if self.const:
            s += ' const'
        if self.deleted:
            s += ' = delete'
        return s

    def hasThis(self):
        return not self.static and isinstance(self.owner, Class)

    def equals(self, other):
        return self.const == other.const and self.params == other.params \
            and ((self.template == None and other.template == None)
                 or (self.template and other.template and self.template.equals(other.template)))

    def includeInRefClass(self):
        return self.name != 'operator =' \
            and not (self.name.startswith('Private') and (self.static or self.owner.interface != Class.VIRTUAL)) \
            and (self.owner.interface == Class.VIRTUAL or self.parseAnnotation('refclass', True)) \
            and (self.access == 'public' or (self.access == 'protected' and self.owner.interface == Class.VIRTUAL)) \
            and not (self.name == 'GetHashCode' and len(self.params) == 0)

    def findParam(self, name):
        for p in self.params:
            if p.name == name:
                return p
        return None

# Represents an observable.
#
#   self.static tells if the observable is static
#   self.retType is the return type of the observable's callback function
#   self.params is the Param list of the observable's callback function
#   self.combiner is the observable's combiner
class Observable(Declaration):
    def __init__(self, kind, name, retType, params, combiner, static, owner, access):
        Declaration.__init__(self, kind, name, owner, access)
        self.retType = retType
        self.params = params
        self.combiner = combiner
        self.static = static

    def declstr(self, mode=Entity.DEFAULT):
        s = self.kind + ' ' + self.retType + ' ' + self.name + '(' + ', '.join(map(str, self.params)) + ')'
        if self.static:
            s = 'static ' + s
        return s


# A Variable node stands for a C++ variable
#
#   self.static tells if the method is static
#   self.type is the type of the variable
class Variable(CppDeclaration):
    def __init__(self, name, static, type, owner, access):
        CppDeclaration.__init__(self, 'variable', name, owner, access)
        self.static = static
        self.type = type

    def declstr(self, mode=Entity.DEFAULT):
        s = mode.annotstr(self)
        if mode.showKind(self):
            s += self.kind + ' '
        s += mode.transformExpr(self.type) + ' ' + mode.qname(self)
        if self.static:
            s = 'static ' + s
        if self.template:
            s = self.template.toStr(False, False, mode) + ' ' + s
        return s


# A TypeDeclaration is one of Class, TypeAlias or Enum.
#   self.bases contains an array of tuples (base class, access, generic), may be empty
class TypeDeclaration(CppDeclaration):
    def __init__(self, kind, name, template, owner, access):
        CppDeclaration.__init__(self, kind, name, owner, access)
        self.template = template
        self.bases = []

    def merge(self, other, changedSet):
        Declaration.merge(self, other, changedSet)
        self.bases = self.mergeimpl(self.bases, other.bases, changedSet)

# A Class node represents a C++ class declaration.
#
#   self.interface is the interface kind, may be None
#   self.refKind is the reference kind, None for non-interfaces or for interfaces which use MAXON_REFERENCE_NONE or MAXON_REFERENCE_STATIC
#   self.static is True for interfaces which use MAXON_REFERENCE_STATIC
#   self.refClass is the name of the reference class, may be None
#   self.baseInterfaces is the list of base interfaces for a virtual interfaces, given by a tuple (interface, generic arguments)
#   self.derived is True for a derived non-virtual or simple virtual interface
#   self.forward is True for a forward declaration
#   self.singleImpl is True for interfaces with a single implementation, otherwise False
#   self.generic is a Template object for a generic interface, otherwise None
class Class(TypeDeclaration):
    VIRTUAL, SIMPLE_VIRTUAL, NONVIRTUAL = range(1, 4)
    POINTER, CONST_POINTER, REF, CONST_REF, COW, ACOW, REF_UNIQUE = range(1, 8)

    def __init__(self, name, template, owner, access, forward):
        TypeDeclaration.__init__(self, 'class', name, template, owner, access)
        self.interface = None
        self.refKind = None
        self.static = False
        self.refClass = None
        self.baseInterfaces = None
        self.derived = False
        self.isError = name.endswith('ErrorInterface')
        self.implementation = False
        self.component = False
        self.finalComponent = False
        self.forward = forward
        self.singleImpl = False
        self.hasStaticMethods = False
        self.generic = None
        self.refClassForwardDeclared = False
        self.missingInterfaces = False

    def merge(self, other, changedSet):
        TypeDeclaration.merge(self, other, changedSet)
        self.interface = self.mergeimpl(self.interface, other.interface, changedSet)
        self.refKind = self.mergeimpl(self.refKind, other.refKind, changedSet)
        self.refClass = self.mergeimpl(self.refClass, other.refClass, changedSet)
        self.baseInterfaces = self.mergeimpl(self.baseInterfaces, other.baseInterfaces, changedSet)

    def setRefKind(self, refKind):
        n = self.name
        p = n.find('Interface')
        if p >= 0 and (p+9 == len(n) or n[p+9:].isdigit()):
            n = n[:p]
        if refKind == 'MAXON_REFERENCE_NONE':
            self.refKind = None
        elif refKind == 'MAXON_REFERENCE_STATIC':
            self.refKind = None
            self.static = True
        elif refKind == 'MAXON_REFERENCE_POINTER':
            self.refKind = Class.POINTER
            self.refClass = n + 'Ptr'
        elif refKind == 'MAXON_REFERENCE_CONST_POINTER':
            self.refKind = Class.CONST_POINTER
            self.refClass = n
        elif refKind == 'MAXON_REFERENCE_NORMAL':
            self.refKind = Class.REF
            self.refClass = n + 'Ref'
        elif refKind == 'MAXON_REFERENCE_CONST':
            self.refKind = Class.CONST_REF
            self.refClass = n
        elif refKind == 'MAXON_REFERENCE_COPY_ON_WRITE':
            self.refKind = Class.COW
            self.refClass = n
        elif refKind == 'MAXON_REFERENCE_ALWAYS_COPY_ON_WRITE':
            self.refKind = Class.ACOW
            self.refClass = n
        elif refKind == 'MAXON_REFERENCE_UNIQUE':
            self.refKind = Class.REF_UNIQUE
            self.refClass = n + 'Ref'
        else:
            refKind.pos.raiseError('Unknown reference kind ' + refKind)
        prefix = self.getAnnotation('refprefix', None)
        if prefix:
            self.refClass = prefix + self.refClass
        elif self.refClass and self.refClass.startswith('Generic'):
            self.refClass = self.refClass[7:]

    def declstr(self, mode=Entity.DEFAULT):
        s = Declaration.declstr(self, mode)
        if mode != Entity.DEFAULT:
            return s
        if self.bases:
            s += ' : ' + ', '.join([a + ' ' + b + c for b, a, c in self.bases])
        if self.interface:
            s += ' ' + ['NONE', 'VIRTUAL', 'SIMPLE_VIRTUAL', 'NONVIRTUAL'][self.interface] + '('
            s += ['NONE', 'POINTER', 'CONST_POINTER', 'REF', 'CONST_REF', 'COW', 'ACOW'][self.refKind if self.refKind else 0] + ')'
        return s

    def addMethodNames(self, methods):
        for b in self.resolvedBaseInterfaces:
            b.addMethodNames(methods)
        for c in self.children:
            if c.kind == 'MAXON_METHOD':
                methods[c.name] = self


# A TypeAlias node stands for a C++ typedef declaration (also used for alias declarations introduced by 'using').
class TypeAlias(TypeDeclaration):
    def __init__(self, kind, name, template, owner, access):
        TypeDeclaration.__init__(self, kind, name, template, owner, access)


# A Using node stands for a C++ using declaration (like using Base::Func)
class Using(CppDeclaration):
    def __init__(self, name, owner, access):
        CppDeclaration.__init__(self, 'using', name, owner, access)


# A InterfaceInstantiation node stands for a MAXON_INTERFACE_INSTANTIATION.
class InterfaceInstantiation(CppDeclaration):
    def __init__(self, token, cls, instantiation, id, owner):
        CppDeclaration.__init__(self, token, token, owner, 'public')
        self.interface = cls
        self.instantiation = instantiation
        self.id = id


# A Define node stands for a C++ macro definition
class Define(CppDeclaration):
    def __init__(self, name, owner):
        CppDeclaration.__init__(self, '#define', name, owner, 'public')
        self.params = []

    def declstr(self, mode=Entity.DEFAULT):
        s = Declaration.declstr(self, mode)
        if self.params:
            s += '(' + ', '.join(self.params) + ')'
        return s


# An Enum node stands for a C++ enum declaration. It has EnumValue and Directive children.
# For a scoped enum (declared with enum class), self.scoped is True. The underlying type of a scoped enum
# is stored in self.type, this type may be None. If self.registered is True, the enum is followed by one of the
# ENUM macros (like MAXON_ENUM_LIST). self.flags is True if the enum is followed by MAXON_ENUM_FLAGS or MAXON_ENUM_FLAGS_CLASS.
class Enum(TypeDeclaration):
    def __init__(self, name, scoped, base, owner, access):
        TypeDeclaration.__init__(self, 'enum', name, None, owner, access)
        self.scoped = scoped
        self.registered = False
        self.flags = False
        self.code = None
        self.line = None
        self.early = False
        if base:
            self.bases.append((base, 'public', ''))

    def declstr(self, mode=Entity.DEFAULT):
        s = Declaration.declstr(self, mode)
        if self.type:
            s += ' : ' + self.type
        return s


# An EnumValue node stands for an enumeration value of an enum declaration.
# self.value is the value as specified behind = in the declaration or None if this doesn't exist.
class EnumValue(CppDeclaration):
    def __init__(self, name, value, owner):
        CppDeclaration.__init__(self, 'enumvalue', name, owner, 'public')
        self.value = value

    def declstr(self, mode=Entity.DEFAULT):
        s = Declaration.declstr(self, mode)
        if self.value:
            s += ' = ' + self.value
        return s


# A Namespace node stands for a C++ namespace. The root node of a parsed header file is a Namespace node.
# self.root points to the Namespace root node.
# self.declarations is only valid for the root node, there it is a list of the declarations found in the
# global namespace and its direct and indirect sub-namespaces. This also contains class declarations,
# but not the member declarations within classes.
class Namespace(CppDeclaration):
    def __init__(self, name, owner, anonymous=False):
        CppDeclaration.__init__(self, 'namespace', name, owner, 'private' if anonymous else 'public')
        self.preprocessorConditions = []
        self.root = owner.root if owner else None
        self.declarations = None
        self.containsResourceId = False
        self.registry = False
        self.anonymous = anonymous
        self.usings = set()
