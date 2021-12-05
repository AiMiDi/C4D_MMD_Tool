'''
MAXON API Lexer Module
'''

import os
import sys

class Token(str):
    INVALID, IDENT, NUMBER, STRING, OP_PUNCT, ESCAPED, COMMENT, PREFIX_DOC, POSTFIX_DOC, DOC_DIRECTIVE, DIRECTIVE, DEFINE, ANNOTATION, INCLUDE, HXX1_INCLUDE, HXX2_INCLUDE, WHITESPACE, NEWLINE, HTML, COMMAND, VERBATIM, GRAPH, SNIPPET, EOF = range(24)
    def __new__(cls, s, type=0, pos=None, escaped=False):
        obj = str.__new__(cls, s)
        obj.type = type
        obj.pos = pos
        obj.escaped = escaped
        return obj

    def isWhitespace(self):
        return self.type == Token.WHITESPACE or self.type == Token.NEWLINE

def quoteHtml(s):
    orig = s
    if isinstance(s, Token) and s.type == Token.HTML:
        return s
    s = s.replace('&', '&amp;').replace('<', '&lt;').replace('>', '&gt;')
    for i in range(0, len(s)):
        if ord(s[i]) > 127:
            s = s[:i] + '&#' + str(ord(s[i])) + ';' + s[i+1:]
    if isinstance(orig, Token) and (orig.type == Token.VERBATIM or orig.type == Token.GRAPH):
        s = '<pre>' + s.rstrip() + '</pre>'
    return s


def isIdentifierStart(c):
    return c.isalpha() or (c == '_') or (c == '$') or (c == '@') or (sys.version_info.major < 3 and c and ord(c) > 127) # embree uses $ in identifiers

def isIdentifierPart(c):
    return c.isalnum() or (c == '_') or (c == '$') or (sys.version_info.major < 3 and c and ord(c) > 127)

def isIdentifier(name):
    return len(name) > 0 and isIdentifierStart(name[0]) and all(isIdentifierPart(c) for c in name[1:]) 


class ParserError(IOError):
    def __init__(self, pos, msg):
        IOError.__init__(self, str(pos) + ': error: ' + msg)
        self.sourcePosition = pos


class SourcePosition(object):
    def __init__(self, file, index, line, pos):
        self.file = file
        self.index = index
        self.line = line
        self.pos = pos

    def __str__(self):
        if os.name == 'nt':
            return self.file + '(' + str(self.line) + (',' + str(self.pos) if self.pos >= 0 else '') + ')'
        else:
            return self.file + ':' + str(self.line) + (':' + str(self.pos) if self.pos >= 0 else '')

    def raiseError(self, msg):
        raise ParserError(self, msg)


class CharStream(object):
    def __init__(self, file, src, forceAscii):
        self.file = file
        self.source = src
        self.sourceLen = len(self.source)
        self.index = 0
        self.line = 1
        self.pos = 1
        self.prevPos = 1
        self.prevLine = 0
        self.stack = []
        self.forceAscii = forceAscii

    def get(self, checkAscii=True):
        i = self.index
        self.index += 1
        if i < self.sourceLen:
            c = self.source[i]
        else:
            c = ''
        self.prevPos = self.pos
        self.prevLine = self.line
        if c == '\n':
            self.line += 1
            self.pos = 1
        else:
            self.pos += 1
        if self.forceAscii and checkAscii and c and ord(c) > 127:
            SourcePosition(self.file, self.index, self.prevLine, self.prevPos).raiseError('Unexpected character ' + str(ord(c)) + ', only ASCII characters are allowed unless you set encoding=<file encoding> in projectdefinition.txt.')
        return c

    def unget(self):
        self.index -= 1
        self.pos = self.prevPos
        self.line = self.prevLine

    def lookahead(self):
        self.stack.append((self.index, self.line, self.pos))

    def reject(self):
        self.index, self.line, self.pos = self.stack.pop()

    def accept(self):
        self.stack.pop()


operatorsPunctuation = set(['{', '}', '[', ']', '(', ')', ';', ':', '.', '..', '...', '?', '::', '.*', '+', '-', '*', '/', '%',
                        '^', '&', '|', '~', '!', '=', '<', '>', '+=', '-=', '*=', '/=', '%=', '^=', '&=', '|=', '<<', '>>',
                        '>>=', '<<=', '==', '!=', '<=', '>=', '&&', '||', '++', '--', ',', '->*', '->'])

htmlElements = set(['b', 'br', 'em', 'hr', 'i', 'p', 'pre', 'span', 'strong', 'sub', 'sup', 'table', 'td', 'tr', 'tt', 'var'])
htmlEntities = set(['amp', 'apos', 'copy', 'deg', 'gt', 'larr', 'lt', 'nbsp', 'quot', 'rarr', 'reg', 'times', 'trade'])

doxSpecialChars = set(['"', '&', '%', '\\', '<', '>', '@', '#', ',', '{', '}', '`'])
doxCommands = set(['@c', '@p', '@b', '@a', '@e', '@em', '@code', '@endcode', '@snippet', '@return', '@see', '@warning', '@note', '@attention', '@param', '@tparam', '@private', '@CLASS',
                   '@link', '@endlink', '@copydoc', '@subpage', '@ref', '@image', '@page', '@section', '@subsection', '@subsubsection', '@paragraph', '@tableofcontents'])

numericOptions = set(['max-linecount', 'level'])
stringOptions = set(['domains'])

def parseStylecheckOption(key, value, args, errors, pos):
    if key in numericOptions:
        try:
            value = int(value)
        except:
            errors.append(pos, 'Invalid value "' + value + '" for numeric option stylecheck.' + key + '.')
            value = 0
    elif not key in stringOptions:
        value = value.lower()
        if value != 'true' and value != 'false':
            errors.append(pos, 'Invalid value "' + value + '" for boolean option stylecheck.' + key + '.')
            value = False
        else:
            value = (value == 'true')
    args.stylecheckOptions[key] = value
    return value


class Lexer(object):
    CPP, DOX, DOX_CODE = range(3)
    def __init__(self, file, source, forceAscii=False):
        self.file = file
        self.splitAngularBracket = 0
        self.cin = CharStream(file, source, forceAscii)
        self.nextToken = None
        self.wasPrefixDoc = None
        self.stack = []
        self.reportWhitespace = 0
        self.ignoreDefine = 0
        self.ignoreDirectives = 0
        self.args = None
        self.language = Lexer.CPP
        self.errors = None
        self.snippets = {}
        self.methodNamesClass = None
        self.prevToken = None
        self.prevPrevToken = None
        self.prevPrevPrevToken = None


    def scanRestOfString(self, pos, delim):
        strlit = delim
        escape = False
        while True:
            c = self.cin.get()
            if self.language != Lexer.DOX or c != '\\' or not escape:
                strlit += c
            if escape:
                escape = False
            elif c == '\\':
                escape = True
            elif c == delim:
                break
            elif c == '':
                pos.raiseError('Unexpected end of file in string literal.')
        return strlit

    def scanExpect(self, pos, expect):
        while True:
            c = self.cin.get()
            if c == expect:
                return
            elif not c.isspace():
                pos.raiseError('Expected ' + expect + '.')

    def getImpl(self, scope):
        if self.nextToken:
            t = self.nextToken
            self.nextToken = None
            return t
        prefixDoc = self.wasPrefixDoc
        self.wasPrefixDoc = False
        while True:
            pos = SourcePosition(self.file, self.cin.index, self.cin.line, self.cin.pos)
            c = self.cin.get()
            if c == '/':
                n = self.cin.get()
                if n == '*':
                    comment = '/*'
                    prev = ''
                    while True:
                        c = self.cin.get(False)
                        if c == '':
                            pos.raiseError('Unexpected end of file in comment.')
                        comment += c
                        if c == '/' and prev == '*':
                            break
                        prev = c
                    if self.language == Lexer.CPP:
                        continue
                    return Token(comment, Token.COMMENT, pos)
                elif n == '/':
                    comment = '//'
                    while True:
                        c = self.cin.get(False)
                        endIndex = self.cin.index  
                        if c == '\n' or c == '':
                            if c == '\n' and self.reportWhitespace > 0:
                                self.cin.unget()
                            break
                        comment += c
                        if self.language == Lexer.CPP and comment.endswith('@MAXON_ANNOTATION'):
                            c = comment[3:-17]
                            if not c or c.isspace():
                                return Token('MAXON_ANNOTATION', Token.ANNOTATION, pos)

                    if comment.startswith('//!'):
                        snippetMarker = comment[3:].strip()
                        if snippetMarker.startswith('['):
                            snippetMarker = snippetMarker[1:]
                            if snippetMarker.endswith(']'):
                                snippetMarker = snippetMarker[:-1].strip()
                            elif self.errors:
                                self.errors.append(pos, 'Wrong format of snippet marker, use //![marker].')
                            x = self.snippets.get(snippetMarker, None)
                            if not x:
                                self.snippets[snippetMarker] = [endIndex, -1, pos]
                            elif endIndex != x[0]:
                                if x[1] < 0:
                                    x[1] = pos.index
                                elif self.errors and pos.index != x[1]:
                                    self.errors.append(pos, 'Snippet marker given more than twice.')
                                if x[2]:
                                    snippet = Token(self.cin.source[x[0]:x[1]], Token.SNIPPET, x[2])
                                    snippet.id = snippetMarker
                                    if scope:
                                        scope.addSnippet(snippet)
                                    x[2] = None
                            continue

                    commentText = 2
                    commentType = Token.COMMENT
                    if self.language == Lexer.CPP:
                        if comment.startswith('///<'):
                            commentText = 4
                            commentType = Token.POSTFIX_DOC
                            comment += '\n'
                        elif comment.startswith('///'):
                            commentText = 3
                            commentType = Token.DOC_DIRECTIVE if comment.find('@cond') >= 0 or comment.find('@endcond') >= 0 else Token.PREFIX_DOC
                            comment += '\n'
    
                        if self.args and self.args.stylecheck and self.args.stylecheckOptions.get('whitespace', True) and len(comment) > commentText \
                                and not comment[commentText] in set([' ', '\n', '\t', '\r', '-', '=']) and not comment.startswith('//////////'):
                            showError = True
                            if commentText == 2:
                                c = comment[2:].strip()
                                if c[0] in set(['#', '\'', '"']) or c in set(['else', 'do', 'private:', 'protected:', 'public:']) or c.find('//', 2) >= 0:
                                    # comment before directive, string literal or single C++ keyword, or comment in comment, don't show an error if space is missing
                                    showError = False
                                else:
                                    # now check if we can find three consecutive words, then we assume that the comment doesn't contain code
                                    foundThreeWords = False
                                    wordCnt = 0
                                    word = ''
                                    for c in (comment[commentText:] + ' '):
                                        if c.isalpha():
                                            word += c
                                        else:
                                            # don't count things like "const Int x" as three words
                                            if word and (wordCnt > 0 or not word in set(['mutable', 'const', 'volatile', 'unsigned', 'signed', 'operator'])):
                                                wordCnt += 1
                                                if wordCnt == 3:
                                                    foundThreeWords = True
                                                    break
                                            word = ''
                                            if not c.isspace():
                                                wordCnt = 0
                                    if not foundThreeWords:
                                        # we didn't find three consecutive words, so most likely comment contains code
                                        # but only if the comment ends with one of ;{}() or const we consider it as code
                                        c = comment.strip()
                                        if ';{}()'.find(c[-1]) >= 0 or c.endswith('const'): 
                                            showError = False
                            if showError:
                                self.styleerrors.append(pos, '// has to be followed by a space.')
                        if self.args and self.args.stylecheck and self.args.stylecheckOptions.get('todo', True):
                            if comment.find('@markTODO') < 0:
                                todo = comment.upper().find('TODO')
                                if todo >= 0 and not (todo > 0 and (comment[todo-1].isalnum() or comment[todo-1] == '@')) and not (todo+4 < len(comment) and comment[todo+4].isalnum()):
                                    todoPos = SourcePosition(self.file, pos.index + todo, pos.line, pos.pos + todo)
                                    if comment[todo:todo+4] != 'TODO':
                                        self.warnings.append(todoPos, 'TODO has to be in uppercase letters.')
                                    if not comment[todo - 1:todo].isspace():
                                        self.warnings.append(todoPos, 'There has to be a space before TODO.')
                                    todo = comment[todo+4:]
                                    if len(todo) < 3 or todo[0:3] != ': (':
                                        self.warnings.append(todoPos, 'TODO has to be followed by ": (Developer) comment".')
                                    else:
                                        p = todo.find(')')
                                        if p < 0:
                                            self.warnings.append(todoPos, 'No closing ) for TODO.')
                                        else:
                                            devs = todo[3:p].strip() 
                                            if not devs:
                                                self.warnings.append(todoPos, 'You must not specify an empty developer list.')
                                            elif not(todo[p+1:].strip()):
                                                self.warnings.append(todoPos, 'You have to add a comment to TODO.')
                                            else:
                                                prevChar = None
                                                for char in devs:
                                                    if char.isalpha():
                                                        if prevChar and prevChar.isalpha():
                                                            if char.isupper():
                                                                self.warnings.append(todoPos, 'Developer names in a TODO must start with uppercase, then lowercase.')
                                                        elif char.islower():
                                                            self.warnings.append(todoPos, 'Developer names in a TODO must start with uppercase, then lowercase.')
                                                    prevChar = char
                        opt = comment.find('stylecheck.')
                        if opt >= 0:
                            opt = comment[opt+11:].split('=')
                            if len(opt) != 2:
                                self.errors.append(pos, 'Use the format stylecheck:option=value to set a stylecheck option.')
                            else:
                                key = opt[0].strip()
                                value = opt[1].strip()
                                parseStylecheckOption(key, value, self.args, self.errors, pos)
                    if commentType == Token.COMMENT and self.language == Lexer.CPP:
                        continue
                    self.wasPrefixDoc = commentType == Token.PREFIX_DOC
                    return Token(comment, commentType, pos)
                self.cin.unget()

            if c != '\n' and c.isspace():
                if self.reportWhitespace:
                    ws = ''
                    while c != '\n' and c.isspace():
                        ws += c
                        c = self.cin.get()
                    self.cin.unget()
                    return Token(ws, Token.WHITESPACE, pos)
                continue

            if c == '\\' or (c == '@' and self.language == Lexer.DOX):
                if self.language == Lexer.CPP:
                    continue
                else:
                    n = self.cin.get()
                    if n in doxSpecialChars:
                        return Token(n, Token.ESCAPED, pos, True)
                    elif c == '\\' and n == 'n':
                        return Token('<br>', Token.HTML, pos, True)
                    else:
                        self.cin.unget()

            if c == '':
                return Token('', Token.EOF, pos)
            elif c == '"' or c == '\'':
                if c == '\'' and self.language != Lexer.CPP:
                    return Token(c, Token.OP_PUNCT, pos)
                strlit = self.scanRestOfString(pos, c)
                return Token(strlit, Token.STRING, pos)
            elif self.language == Lexer.CPP and c == '#':
                directive = self.skipDirectiveRest(c, self.ignoreDefine == 0, pos)
                if self.ignoreDirectives:
                    continue
                if directive == '#define':
                    return Token(directive, Token.DEFINE, pos)
                p = directive.find('//')
                if p < 0:
                    p = directive.find('/*')
                if p >= 0:
                    directive = directive[:p]
                directive = directive.strip()
                if directive.startswith('#if') or directive.startswith('#elif') or directive.startswith('#else') or directive.startswith('#endif'):
                    if directive.startswith('#ifndef') and directive.endswith('_H__'):
                        directive = '#if 1'
                    return Token(directive, Token.DIRECTIVE, pos)
                elif directive.startswith('#include'):
                    if directive.find('1.hxx') >= 0:
                        return Token(directive, Token.HXX1_INCLUDE, pos)
                    elif directive.find('2.hxx') >= 0:
                        return Token(directive, Token.HXX2_INCLUDE, pos)
                    else:
                        return Token(directive, Token.INCLUDE, pos)
                else:
                    # ignore other directives
                    continue
            elif self.language == Lexer.CPP and c.isdigit():
                number = c
                while True:
                    c = self.cin.get()
                    if c.lower() == 'e' and not number.lower().startswith('0x'):
                        number += c
                        c = self.cin.get()
                        number += c
                    elif c.isalnum() or (c == '.'):
                        number += c
                    else:
                        self.cin.unget()
                        break
                return Token(number, Token.NUMBER, pos)
            elif isIdentifierStart(c):
                ident = c
                while True:
                    c = self.cin.get()
                    if isIdentifierPart(c):
                        ident += c
                    else:
                        self.cin.unget()
                        break
                if ident.startswith('@$'):
                    ident = '@' + ident[2:]
                if ident == '_GCC_REFCONVERSION_WORKAROUND' and not self.file.endswith('compilerdetection.h'):
                    continue
                elif ident == '_Pragma':
                    self.scanExpect(pos, '(')
                    self.scanExpect(pos, '"')
                    self.scanRestOfString(pos, '"')
                    self.scanExpect(pos, ')')
                    continue
                elif self.language == Lexer.CPP and (ident == '@implementation' or ident == '@end'):
                    while True:
                        c = self.cin.get()
                        if c == '\n' or c == '':
                            break
                    continue
                elif self.language == Lexer.DOX and (ident == '@htmlonly' or ident == '@verbatim' or ident == '@graph'):
                    end = '@end' + ident[1:]
                    text = ''
                    while not text.endswith(end):
                        c = self.cin.get()
                        if c == '':
                            pos.raiseError('Unexpected end of file in ' + ident + '.')
                        text += c
                        if text == '\n':
                            text = ''
                    return Token(text[:-len(end)], Token.HTML if ident == '@htmlonly' else Token.VERBATIM if ident == '@verbatim' else Token.GRAPH, pos)
                elif self.language == Lexer.DOX and ident in doxCommands:
                    return Token(ident, Token.COMMAND, pos)
                else:
                    return Token(ident, Token.IDENT, pos)

            # at this point, c can be only be \n, operator, or punctuation

            if c in operatorsPunctuation:
                op = c
                if self.language == Lexer.DOX:
                    if c == '<':
                        # check if this is a HTML tag
                        tag = c
                        self.cin.lookahead()
                        c = self.cin.get()
                        if c == '/':
                            tag += c
                            c = self.cin.get()
                        tagName = ''
                        while c.isalpha() or (tagName and c.isdigit()):
                            tagName += c
                            c = self.cin.get()
                        if (c == '>' or c == ' ') and tagName.lower() in htmlElements:
                            tag += tagName + c
                            self.cin.accept()
                            while c != '>':
                                c = self.cin.get()
                                tag += c
                            return Token(tag, Token.HTML, pos)
                        self.cin.reject()
                    elif c == '&':
                        # check if this is a HTML entity
                        self.cin.lookahead()
                        c = self.cin.get()
                        entity = ''
                        while c.isalpha():
                            entity += c
                            c = self.cin.get()
                        if c == ';' and entity.lower() in htmlEntities:
                            self.cin.accept()
                            return Token('&' + entity + ';', Token.HTML, pos)
                        self.cin.reject()
                while True:
                    c = self.cin.get()
                    if c == '' or (op + c) not in operatorsPunctuation:
                        self.cin.unget()
                        break
                    op += c
                if self.splitAngularBracket > 0 and op == '>>':
                    self.nextToken = Token('>', Token.OP_PUNCT, SourcePosition(pos.file, pos.index + 1, pos.line, pos.pos + 1))
                    return Token('>', Token.OP_PUNCT, pos)
                else:
                    return Token(op, Token.OP_PUNCT, pos)
            elif c == '\n':
                if self.reportWhitespace or prefixDoc:
                    return Token(c, Token.NEWLINE, pos)
            elif self.language != Lexer.CPP:
                return Token(c, Token.OP_PUNCT, pos)
            else:
                pos.raiseError('Unexpected character ' + str(ord(c)) + '.')

    def skipDirectiveRest(self, directive, checkForDefine, pos):
        self.nextToken = None
        prev = ''
        while True:
            c = self.cin.get()
            if (c == '\n' and prev != '\\') or c == '':
                break
            directive += c
            if checkForDefine and directive == '#define':
                break
            if c == '*' and prev == '/':
                while True:
                    c = self.cin.get()
                    if c == '':
                        pos.raiseError('Unexpected end of file in comment.')
                    directive += c
                    if c == '/' and prev == '*':
                        break
                    prev = c
            prev = c
        return directive

    def getNoEof(self, scope=None):
        t = self.get(scope)
        if t == '':
            t.pos.raiseError('Unexpected end of file.')
        return t

    def getNoEofSkipWs(self, scope=None):
        while True:
            t = self.get(scope)
            if t == '':
                t.pos.raiseError('Unexpected end of file.')
            if not t.isWhitespace():
                return t

    def consume(self, expected):
        t = self.get()
        if t != expected:
            t.pos.raiseError('Expected ' + expected + ', found ' + t + ' instead.')
        return t

    def getIdent(self):
        t = self.get()
        if t.type != Token.IDENT:
            t.pos.raiseError('Expected identifier, found ' + t + ' instead.')
        return t

    def getFunctionName(self):
        return self.parseOperatorPostfix(self.getIdent())

    def parseOperatorPostfix(self, name):
        if name != 'operator':
            return name
        orig = name
        operator = self.get()
        while operator.isWhitespace():
            operator = self.get()
        if operator == '(':
            self.consume(')')
            operator += ')'
        elif operator == '[':
            self.consume(']') 
            operator += ']'
        elif operator == 'new':
            if self.next() == '[':
                self.consume('[') 
                self.consume(']') 
                operator += '[]'
        elif operator.type == Token.STRING:
            operator += self.getIdent()
        name += ' ' + operator
        return Token(name, Token.IDENT, orig.pos)

    def getNumber(self):
        t = self.get()
        if t.type != Token.NUMBER:
            t.pos.raiseError('Expected number, found ' + t + ' instead.')
        return t

    def getString(self):
        t = self.get()
        if t.type != Token.STRING:
            t.pos.raiseError('Expected string literal, found ' + t + ' instead.')
        return t

    def lookahead(self):
        self.cin.lookahead()
        self.stack.append((self.nextToken, self.wasPrefixDoc, self.prevToken, self.prevPrevToken, self.prevPrevPrevToken))

    def reject(self):
        self.cin.reject()
        self.nextToken, self.wasPrefixDoc, self.prevToken, self.prevPrevToken, self.prevPrevPrevToken = self.stack.pop()

    def accept(self):
        self.cin.accept()
        self.stack.pop()

    def next(self):
        self.lookahead()
        t = self.get()
        self.reject()
        return t

    def get(self, scope=None):
        t = self.getImpl(scope)
        if t.type == Token.IDENT and self.methodNamesClass and t in self.methodNamesClass.methodNames:
            if not (self.prevToken in ['::', '.'] or (self.prevToken == '->' and self.prevPrevToken != 'this')):
                self.methodNamesClass.ambiguousCalls.append(t)
            if self.prevToken == '.' and self.prevPrevToken == 'self':
                self.methodNamesClass.selfCalls.append(t)
        self.prevPrevToken = self.prevToken
        self.prevToken = t
        return t

    def prev(self):
        return self.prevPrevToken

    def leadingWhitespace(self, token):
        start = token.pos.index
        while start > 0 and self.cin.source[start - 1].isspace():
            start = start - 1
        return self.cin.source[start:token.pos.index]

    def leadingWhitespaceOfLine(self, token):
        start = token.pos.index
        while start > 0 and self.cin.source[start - 1] != '\n':
            start = start - 1
            if not self.cin.source[start].isspace():
                return None
        return self.cin.source[start:token.pos.index]

    def parsePostfixDoc(self, decl):
        while True:
            self.lookahead()
            t = self.get()
            if t.type != Token.POSTFIX_DOC:
                self.reject()
                return
            self.accept()
            decl.doclist.append(t)
