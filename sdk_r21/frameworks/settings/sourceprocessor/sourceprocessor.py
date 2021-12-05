# The version number is used by the project tool to generate the project files according to the output of the source processor.
# version 2

"""MAXON API Source File Processor - Stylecheck options for projectdefinition.txt (add =true/false as option value).

stylecheck.whitespace
  checks for missing whitespace as in if(condition)
stylecheck.no-whitespace
  checks for forbidden whitespace as in if ( condition )
stylecheck.indentation
  checks for correct indentation
stylecheck.todo
  checks style of TODO comments
stylecheck.consistent-blocks
  checks that either both or none of if/else use a {}-block, same for switch
stylecheck.newline-for-substatement
  checks that the substatement of if or a loop is within a new line
stylecheck.typedef-struct
  checks for C-style struct declarations as in typedef struct { ... } S;
stylecheck.enum-class
  checks that scoped enums are used (enum class instead of just enum)
stylecheck.enum-registration
  checks that enums are ended with one of the enum macros (MAXON_ENUM_LIST etc.)
stylecheck.case-break
  checks that a switch case has a break statement at its end (or MAXON_SWITCH_FALLTHROUGH)
stylecheck.class-for-templateparam
  checks that a template type parameter is introduced by typename (template <typename T> instead of template <class T>)
stylecheck.explicit
  checks that constructors which can be used as conversion constructors are marked by either explicit or MAXON_IMPLICIT
stylecheck.void-paramlist
  checks for C-style function declarations with empty parameter list as in void Func(void);
stylecheck.virtual
  checks for virtual functions in public frameworks
stylecheck.static-within-type
  checks for declarations like const static Int x = 0;
stylecheck.supercall
  checks for super call in comparison functions of components
stylecheck.aswarnings
  turns style errors into warnings
stylecheck.ambiguouscalls
  checks for ambiguous method calls
stylecheck.selfcalls
  checks for virtual calls to implemented methods of final components
stylecheck.using
  checks for "using namespace" in namespace scope within header files
stylecheck.naming
  checks compliance with the naming convention

Stylecheck options with numeric value

stylecheck.max-linecount
  sets the maximum line count a function may have

Stylecheck options with string value

stylecheck.domains
  sets the expected domains for identifiers (semicolon-separated list)
"""

import os
import copy
import sys
import platform
import locale
import subprocess
import argparse
import traceback
from multiprocessing import Process, Queue, cpu_count  # @UnresolvedImport

dir, fn = os.path.split(__file__)
if dir not in sys.path:
    sys.path.append(dir)

import declarations
import inspect
import lexer
import docdb
import htmlgen
from declarations import *
from lexer import *

defines = [('MAXON_DECLARATION_STRINGENCODING',
            'namespace StringEncodings'\
            '{'\
            '\n\tMAXON_DECLARATION(maxon::StringEncodingRef, %2, "net.maxon.stringencoding.#%1#");'\
            '}'\
            '\nnamespace StringDecodings'\
            '{'\
            '\n\tMAXON_DECLARATION(maxon::StringDecodingRef, %2, "net.maxon.stringdecoding.#%1#");'\
            '}'\
            '\nnamespace StreamConversions'\
            '{'\
            '\n\tMAXON_DECLARATION(maxon::StreamConversionFactory, String%2Encoder, "net.maxon.streamconversion.#%1#enc");'\
            '\n\tMAXON_DECLARATION(maxon::StreamConversionFactory, String%2Decoder, "net.maxon.streamconversion.#%1#dec");'\
            '}'),
           ('MAXON_IF_SOURCEPROCESSOR', '%1'), ('MAXON_IF_TARGET_DEBUG', '%1'), ('PRIVATE_MAXON_ENABLE_IF_ERROR', '%1'), ('MAXON_DEPRECATED_ENUMVALUE', '%1')]



spaceOperators = set(['=', '+=', '-=', '*=', '/=', '%=', '^=', '&=', '|=', '>>=', '<<=', '==', '!=', '<=', '>=', '||'])
varOrFunctionPrefixes = set(['constexpr', 'inline', 'static', 'virtual', 'extern', 'explicit', 'friend', 'MAXON_IMPLICIT', 'MAXON_WARN_UNUSED', '__declspec', '@property', 'IBOutlet',
                         'MAXON_ATTRIBUTE_FORCE_INLINE', 'MAXON_ATTRIBUTE_NO_INLINE', 'MAXON_ATTRIBUTE_DLL_PUBLIC', 'MAXON_WARN_MUTE_FUNCTION_LENGTH', 'MAXON_WARN_MUTE_NAMING', 'MAXON_METHOD', 'MAXON_FUNCTION', 'PIXELFORMAT_INLINE',
                         'GLAPI_EXTERN', 'GLAPI', 'JNIEXPORT', 'FMX_ENTRYPT'])
varOrFunctionPostfixes = set(['WINAPI', 'CALLBACK', 'APIENTRY', 'DNSSD_API', 'noexcept'])
parameterPrefixes = set(['__in', '__in_opt', 'AVAHI_GCC_UNUSED'])


def indentLen(str):
    res = 0
    if str:
        for c in str:
            if c == '\t':
                res = (res & ~1) + 2
            elif c != '\n':
                res = res + 1
    return res


def isComponentComparison(name, params):
    return name in ['IsEqual', 'Compare'] and params and params[0].type in ['const ObjectInterface*', 'const maxon::ObjectInterface*']


def isCamelCaseUpper(str):
    str = str.replace('_', '')
    if not (str and str[0].isupper()):
        return False
    return str.isalnum() and not str.isupper()


def splitComma(str):
    start = 0
    i = 0
    nesting = 0
    list = []
    while i < len(str):
        c = str[i]
        if '<({['.find(c) >= 0:
            nesting += 1
        elif '>)}]'.find(c) >= 0:
            nesting -= 1
            if nesting < 0:
                list.append(str[start:i].strip())
                break
        elif nesting == 0 and c == ',':
            list.append(str[start:i].strip())
            start = i + 1
        i += 1
    return (list, i)

class Parser(object):

    def checkCamelCaseUpper(self, scope, name, type):
        if self.args.stylecheck and self.args.stylecheckOptions.get('naming', True) and not isCamelCaseUpper(name):
            n = scope.getNamespace()
            if n and n.owner and n.name != 'std' and n.owner.name != 'std':
                self.styleerrors.append(name.pos, 'Style guide requires camel-case for the name of a ' + type + '.')

    def checkIdentifier(self, decl):
        if isinstance(decl, Declaration) and isinstance(decl.id, Token):
            if not self.args.maxon and decl.id.startswith('"net.maxon.'):
                self.errors.append(decl.id.pos, 'Identifier ' + decl.id + ' is in net.maxon domain')
            if self.args.stylecheckOptions['domains']:
                for dom in self.args.stylecheckOptions['domains'].split(';'):
                    if decl.id.startswith('"' + dom.strip() + '.'):
                        break
                else:
                    self.errors.append(decl.id.pos, 'Identifier ' + decl.id + ' doesn\'t start with one of the domain(s) ' + self.args.stylecheckOptions['domains'] + '.')

    def checkCamelCaseUpperFunction(self, scope, name, type):
        return name == 'begin' or name == 'end' or name.startswith('operator') or self.checkCamelCaseUpper(scope, name, type) 


    # parses a type, also handles template types with < > and commas and macros like BASE_INTERFACES(A, B)
    # returns tuple (type as string, bool, param name) where the bool tells if the type is a const-qualified type
    def parseTypeCheckConst(self, firstToken=None, parentheses=True, allowTilde=False, param=False):
        nest = 0
        type = ''
        self.lex.splitAngularBracket += 1
        allowIdent = True
        prev = None
        const = False
        while True:
            self.lex.lookahead()
            t = firstToken if firstToken else self.lex.getNoEof()
            firstToken = None
            maybeSuffix = t == 'const' or t == 'volatile' or t == 'long' or t == 'int' or t == 'short' or t == 'char' or t == 'double' or t == '__RPC_FAR'
            if t == 'static':
                if self.args.stylecheck and self.args.stylecheckOptions.get('static-within-type', True):
                    self.styleerrors.append(t.pos, 'Wrong place of static, put it in front of the type.')
            if t == 'const':
                const = True
            if t == '<':
                nest += 1
            elif nest > 0 and t == '>':
                nest -= 1
            elif allowTilde and t == '~' and prev == '::':
                type += t
            elif t != '{' and t != ')' and (parentheses or t != '(') and self.handleBlock(None, t, False, True, -1):
                t = self.block
                if param and (t.startswith('(*') or t.startswith('(&')):
                    self.lex.accept()
                    self.lex.splitAngularBracket -= 1
                    return (type, const, t[1:-1])
            elif nest == 0 and not ((allowIdent and t.type == Token.IDENT) or maybeSuffix or t == '::' or t == '&' or t == '&&' or t == '*'):
                self.lex.reject()
                self.lex.splitAngularBracket -= 1
                return (type, const, None)
            if maybeSuffix and not allowIdent:
                # suffix as 'const' in 'Int const' or 'long' in 'unsigned long'
                type += ' ' + t
            elif not (allowTilde and t == '~'):
                # check for keyword prefix as in 'const Int'
                keyword = t == 'const' or t == 'volatile' or t == 'template' or t == 'typename' or t == 'struct' or t == 'static'
                allowIdent = keyword or t == '::' or t == '<' or t == ','
                type += t
                if keyword or t == ',':
                    type += ' '
                if t == '*':
                    const = False
            prev = t
            self.lex.accept()

    # parses a type, also handles template types with < > and commas and macros like BASE_INTERFACES(A, B)
    def parseType(self, firstToken=None, parentheses=True):
        type, c, name = self.parseTypeCheckConst(firstToken, parentheses)
        return type

    # If t is one of ([{, parses until the closing parenthesis, sets self.block to a single string of all parsed tokens including parentheses and returns True.
    # Otherwise, does nothing and returns False.
    def handleBlock(self, owner, t, angular, expectNoSpace, indent):
        if t == '(':
            self.block = t + ''.join(self.parseUntil(owner, t, False, ')', expectNoSpace, -1))
            return True
        elif t == '[':
            self.block = t + ''.join(self.parseUntil(owner, t, False, ']', expectNoSpace, -1))
            return True
        elif t == '{':
            self.block = t + ''.join(self.parseUntil(owner, t, False, '}', False, indent))
            return True
        elif t == '<' and angular:
            self.block = t + ''.join(self.parseUntil(owner, t, True, '>', False, indent))
            return True
        else:
            return False

    # parses the token stream until a character of stop is found which is not contained in parentheses, returns tuple (parsed tokens as a single string, terminating token)
    def parseUntil(self, owner, start, angular, stop, expectNoSpace, indent, switch=False, inCase=None):
        result = ''
        prevNumberIdent = False
        checkCode = stop == '}'
        expectWhitespaceSep = None
        checkStatement = None
        checkConditional = None
        ifHasBlock = False
        prevToken = None
        prevPrevToken = None
        prevNonWsToken = None
        noSpace = expectNoSpace
        extraIndent = 0
        breakFound = False
        returnOrContinueOrGotoFound = False
        caseWithBlock = False
        try:
            self.lex.reportWhitespace += 1
            self.lex.ignoreDefine += 1
            if angular:
                self.lex.splitAngularBracket += 1
            while True:
                t = self.lex.getNoEof(owner)
                if self.args.stylecheck and self.args.stylecheckOptions.get('whitespace', True) and expectWhitespaceSep:
                    if t.type != Token.WHITESPACE and t != '\n' and t != ',' and t != ')' and t != ']':
                        self.styleerrors.append(t.pos, 'Style guide requires whitespace behind ' + expectWhitespaceSep + '.')
                    expectWhitespaceSep = None
                if self.args.stylecheck and self.args.stylecheckOptions.get('no-whitespace', True) and noSpace:
                    if t.type == Token.WHITESPACE:
                        self.styleerrors.append(t.pos, 'Style guide forbids whitespace at this position.')
                    noSpace = False
                if (len(t) == 1 or t.type == Token.POSTFIX_DOC) and stop.find(t if t.type != Token.POSTFIX_DOC else '/') >= 0:
                    if self.args.stylecheck and self.args.stylecheckOptions.get('no-whitespace', True) and expectNoSpace and prevToken and prevToken.type == Token.WHITESPACE and prevPrevToken != ';' and prevPrevToken != ':' and prevPrevToken != ',' and prevPrevToken != '\n':
                        self.styleerrors.append(prevToken.pos, 'Style guide forbids whitespace at this position.')
                    if inCase and not (breakFound or returnOrContinueOrGotoFound) and self.args.stylecheck and self.args.stylecheckOptions.get('case-break', True):
                        if switch:
                            self.errors.append(t.pos, 'break missing for the last case.')
                        else:
                            self.errors.append(t.pos, 'break or MAXON_SWITCH_FALLTHROUGH missing at the end of this case block.')
                    return (result, t)
                if switch:
                    caseLabel = t == 'case' or t == 'default'
                    if caseLabel:
                        if inCase and not (breakFound or returnOrContinueOrGotoFound) and prevNonWsToken and prevNonWsToken != ':' and self.args.stylecheck and self.args.stylecheckOptions.get('case-break', True):
                            self.errors.append(prevNonWsToken.pos, 'break or MAXON_SWITCH_FALLTHROUGH missing at the end of this case.')
                        inCase = t
                        breakFound = False
                        returnOrContinueOrGotoFound = False
                    if caseWithBlock:
                        if caseLabel:
                            caseWithBlock = False
                        elif self.args.stylecheck and self.args.stylecheckOptions.get('indentation', True) and t != '\n' and t.type != Token.WHITESPACE and t.type != Token.DIRECTIVE:
                            self.styleerrors.append(t.pos, 'Style guide forbids further code for case behind case block.')
                if inCase and not checkStatement:
                    if t == 'break' or t == 'MAXON_SWITCH_FALLTHROUGH':
                        if not breakFound:
                            breakFound = True
                        elif self.args.stylecheck and self.args.stylecheckOptions.get('case-break', True):
                            self.styleerrors.append(t.pos, 'Duplicate break or MAXON_SWITCH_FALLTHROUGH.')
                    elif t == 'return' or t == 'continue' or t == 'goto':
                        returnOrContinueOrGotoFound = True
                caseBlock = switch and (t == '{' and prevNonWsToken == ':')
                if t.type == Token.DIRECTIVE or t.type == Token.DEFINE:
                    extraIndent = 0
                if caseBlock:
                    caseWithBlock = True
                    inCase = None
                if self.args.stylecheck and self.args.stylecheckOptions.get('indentation', True) and indent >= 0 and ((prevPrevToken == '\n' and prevToken.type == Token.WHITESPACE) or prevToken == '\n') \
                        and t.type != Token.DIRECTIVE and t.type != Token.DEFINE and t.type != Token.INCLUDE and t != '\n' and t.type != Token.WHITESPACE:
                    if t == 'case' or t == 'default' or caseBlock or (t.type == Token.IDENT and self.lex.next() == ':'):
                        if indentLen(prevToken) + 2 != indent:
                            self.styleerrors.append(t.pos, 'Wrong indentation of ' + (t if t == 'case' or t == 'default' else 'block' if t == '{' else 'label') + '.')
                    elif t in ['break', 'if', 'iferr', 'ifnoerr', 'for', 'while', 'do', 'switch', 'else', 'return', 'goto']:
                        if indentLen(prevToken) != indent + extraIndent:
                            self.styleerrors.append(t.pos, 'Wrong indentation of ' + t + '.')
                    else:
                        if indentLen(prevToken) < indent + extraIndent:
                            if indentLen(prevToken) == 0:
                                self.warnings.append(t.pos, 'Wrong indentation.')
                            else:
                                self.styleerrors.append(t.pos, 'Wrong indentation.')
                if ')]}'.find(t) >= 0:
                    if not start:
                        t.pos.raiseError('Unexpected closing parenthesis ' + t)
                    elif '([{'.find(start) >= 0:
                        start.pos.raiseError('No matching closing parenthesis found for ' + start + '\n' + str(t.pos) + ': error: Mismatching closing parenthesis ' + t)
                    else:
                        start.pos.raiseError('Unexpected closing parenthesis while parsing from here.\n' + str(t.pos) + ': error: Unexpected closing parenthesis ' + t)
                elif caseBlock:
                    s, t = self.parseUntil(owner, t, False, '}', False, indent, False, t)
                    result += s
                elif self.handleBlock(owner, t, angular, False, indent if caseBlock else -1):
                    result += self.block
                    prevNumberIdent = False
                else:
                    if t == 'iferr_scope' or t == 'iferr_scope_handler' or t == 'do':
                        if indent < 0 and prevToken and prevToken.type == Token.WHITESPACE and prevPrevToken == '\n':
                            indent = indentLen(prevToken)
                    if checkCode and (t == 'if' or t == 'iferr' or t == 'ifnoerr' or t == 'for' or t == 'while' or t == 'switch' or t == 'else'):
                        if indent < 0 and prevToken and prevToken.type == Token.WHITESPACE and prevPrevToken == '\n':
                            indent = indentLen(prevToken)
                        checkStatement = t
                        elseCase = t == 'else'
                        if elseCase:
                            self.lex.lookahead()
                            ws = ''
                            t = self.lex.getNoEof(owner)
                            while t.type == Token.WHITESPACE or t == '\n':
                                ws += t
                                t = self.lex.getNoEof(owner)
                            if t == 'if':
                                if self.args.stylecheck and self.args.stylecheckOptions.get('whitespace', True) and ws != ' ':
                                    self.styleerrors.append(t.pos, 'Style guide requires a single space between if and else.')
                                self.lex.accept()
                                result += checkStatement
                                checkStatement = t
                            else:
                                self.lex.reject()

                        result += t
                        if checkStatement != 'else':
                            t = self.lex.getNoEof(owner)
                            if self.args.stylecheck and self.args.stylecheckOptions.get('whitespace', True) and t != ' ':
                                self.styleerrors.append(t.pos, 'Style guide requires a single space behind ' + checkStatement + '.')
                            while t.type == Token.WHITESPACE or t == '\n':
                                t = self.lex.getNoEof(owner)
                            t.expect('(')
                            self.handleBlock(owner, t, False, True, -1)
                            result += self.block
                        self.lex.lookahead()
                        t = self.lex.getNoEof(owner)
                        if t.type == Token.WHITESPACE:
                            t = self.lex.getNoEof(owner)
                        if self.args.stylecheck and self.args.stylecheckOptions.get('newline-for-substatement', True) and t != '\n' and t != ';':
                            self.styleerrors.append(t.pos, 'Style guide requires a new line for the substatement of ' + checkStatement + '.')
                        while t.type == Token.WHITESPACE or t.type == Token.DIRECTIVE or t == '\n':
                            if t.type == Token.DIRECTIVE:
                                elseCase = False
                            t = self.lex.getNoEof(owner)
                        if t == '{':
                            if self.args.stylecheck and self.args.stylecheckOptions.get('consistent-blocks', True) and elseCase and not ifHasBlock:
                                self.styleerrors.append(t.pos, 'Style guide requires that the else case must not use a block if the if case doesn\'t.')
                            self.lex.accept()
                            result += t
                            s, t = self.parseUntil(owner, t, False, '}', False, (indent + (4 if checkStatement == 'switch' else 2)) if indent >= 0 else -1, checkStatement == 'switch')
                            result += s
                            result += t
                            checkStatement = None
                            ifHasBlock = True
                            extraIndent = 0
                        else:
                            if self.args.stylecheck and self.args.stylecheckOptions.get('consistent-blocks', True) and elseCase and ifHasBlock:
                                self.styleerrors.append(t.pos, 'Style guide requires that the else case uses a block if the if case does.')
                            self.lex.reject()
                            ifHasBlock = False
                            extraIndent = extraIndent + 2
                    elif checkCode and (t == '&&' or t == '||' or t == '?'):
                        checkConditional = t
                        result += t
                    else:
                        if checkStatement:
                            if t == ';':
                                checkStatement = None
                                extraIndent = 0
                            elif t == 'iferr_return' or t == 'iferr_handle':
                                self.errors.append(t.pos, '' + t + ' has to be put in a block if it is used in the substatement of ' + checkStatement + '.')
                        if checkConditional:
                            if t == ';' or t == '=':
                                checkConditional = None
                            elif t == 'iferr_return' or t == 'iferr_handle':
                                self.errors.append(t.pos, '' + t + ' cannot be used within the conditional expression ' + checkConditional + '.')
                        if t in spaceOperators:
                            if self.args.stylecheck and self.args.stylecheckOptions.get('whitespace', True) and prevToken and prevToken.type != Token.WHITESPACE and prevToken != '\n':
                                self.styleerrors.append(t.pos, 'Style guide requires whitespace before ' + t + '.')
                            if prevPrevToken == 'operator':
                                noSpace = True
                            else:
                                expectWhitespaceSep = t
                        if t == ',' or t == ';':
                            expectWhitespaceSep = t
                        if not t.isWhitespace():
                            numberIdent = t.type == Token.NUMBER or t.type == Token.IDENT
                            if prevNumberIdent and numberIdent:
                                result += ' '
                            result += t
                            prevNumberIdent = numberIdent
                prevPrevToken = prevToken
                prevToken = t
                if t.type != Token.WHITESPACE and t != '\n':
                    prevNonWsToken = t
        finally:
            self.lex.reportWhitespace -= 1
            self.lex.ignoreDefine -= 1
            if angular:
                self.lex.splitAngularBracket -= 1

    # parses a parameter list in parentheses, returns a Param list
    # the opening ( has to be parsed in advance
    def parseParams(self, noneIfInvalid=False):
        self.lex.lookahead()
        self.lex.ignoreDirectives += 1
        try:
            params = []
            if self.lex.getNoEof() == ')':
                self.lex.accept()
            else:
                self.lex.reject()
                while True:
                    t = self.lex.getNoEof()
                    while t in parameterPrefixes:
                        t = self.lex.getNoEof()
                    type = ''
                    ellipsis = t if t == '...' else None
                    parenthesizedName = None
                    if not ellipsis:
                        type, dummy, parenthesizedName = self.parseTypeCheckConst(t, True, False, True)
                    param = Parameter(type)
                    t = self.lex.getNoEof()
                    if ellipsis:
                        param.name = ellipsis
                    else:
                        if t == '...':
                            param.pack = True
                            t = self.lex.getNoEof()
                        if parenthesizedName:
                            paramName = parenthesizedName[1:]
                        elif t.type == Token.IDENT:
                            paramName = t
                            t = self.lex.getNoEof()
                            if t == '::':
                                # special case like "T BASEATTR::ValueType::* MEMBER", we misinterpreted T as type and BASEATTR as paramName
                                rest, t = self.parseUntil(None, None, True, '*', False, -1)
                                param.type += ' ' + paramName + '::' + rest + '*'
                                paramName = self.lex.getNoEof()
                                t = self.lex.getNoEof()
                        else:
                            paramName = ''
                        param.name = paramName or 'anonymous_param_' + str(len(params) + 1)
                        if t == '(':
                            fn, t = self.parseUntil(None, None, True, ')', False, -1)
                            param.type = param.type + '(' + fn + ')'
                            t = self.lex.getNoEof()
                        dimensions = []
                        while t == '[':
                            dimension, t = self.parseUntil(None, None, False, ']', False, -1)
                            dimensions.append(dimension)
                            t = self.lex.getNoEof()
                        for dimension in reversed(dimensions):
                            if dimension:
                                param.type = 'maxon::AddArrayT<' + param.type + ', ' + str(dimension) + '>'
                            else:
                                param.type = 'maxon::AddArrayOfUnknownBoundT<' + param.type + '>'
                        if parenthesizedName:
                            param.type += parenthesizedName[0]
                    if not params and param.type == 'void':
                        if self.args.stylecheck and self.args.stylecheckOptions.get('void-paramlist', True):
                            self.styleerrors.append(t.pos, 'Use just () instead of (void) for an empty parameter list.')
                        t.expect(')')
                        break
                    if t == '=':
                        param.default, t = self.parseUntil(None, None, True, '),', False, -1)
                    if param.type == 'MAXON_SOURCE_LOCATION_DECLARATION':
                        param.type = 'const maxon::SourceLocation&'
                        param.name = 'allocLocation'
                    params.append(param)
                    if t == ')':
                        break
                    elif t != ',':
                        if noneIfInvalid:
                            return None
                        t.pos.raiseError('Expected , or ), found ' + t + ' instead.')
        finally:
            self.lex.ignoreDirectives -= 1
        return params

    def parseSpecialization(self, t):
        self.lex.splitAngularBracket += 1
        specialization, t = self.parseUntil(None, t, True, '>', False, -1)
        self.lex.splitAngularBracket -= 1
        return specialization

    def parseVariableDeclarationRest(self, owner, t):
        while t == '[':
            self.parseUntil(owner, t, False, ']', False, -1)
            t = self.lex.get(owner)
        t.expect(['=', '{', ',', ';'])
        if t == '=':
            self.parseUntil(owner, None, False, ';', False, -1)
        elif t == '{':
            self.parseUntil(owner, t, False, '}', False, -1)
            self.lex.consume(';')
        elif t == ',':
            # another variable declaration as in Int x, y;
            while True:
                t = self.lex.getNoEof()
                if t != '*':
                    if t.type != Token.IDENT:
                        t.pos.raiseError('Expected identifier, found ' + t + ' instead.')
                    break
            self.parseVariableDeclarationRest(owner, t = self.lex.getNoEof(owner))

    # parses a method declaration if t is a valid start of such a declaration, otherwise does nothing
    def tryParseMethod(self, t, doclist, cls, access):
        if not (cls.interface or cls.name == 'StringTemplate' or cls.name == 'Methods'):
            return None
        self.lex.lookahead()
        static = False
        while True:
            if t == '[' and self.lex.next() == '[':
                self.parseAttributeRest()
            elif not t in varOrFunctionPrefixes:
                self.lex.reject()
                return None
            elif t == 'MAXON_METHOD' or t == 'MAXON_FUNCTION':
                break
            elif t == 'static':
                static = True
            t = self.lex.get(cls)
        self.lex.accept()
        if static and cls.interface == Class.SIMPLE_VIRTUAL and t == 'MAXON_METHOD':
            self.errors.append(t.pos, 'Simple interfaces can\'t have static methods.')
        if not static and cls.static:
            self.errors.append(t.pos, 'Static interfaces can\'t have non-static methods.')
        if self.template:
            index = 1
            for p in self.template.params:
                if not p.name:
                    p.name = 'ANONYMOUS_PARAM_' + str(index)
                    index += 1
        kind = t
        annots = {}
        if self.lex.next() == 'operator':
            name = self.lex.get(cls)
            retType = self.parseType(None, False)
        else:
            retType = self.parseType()
            name = self.lex.getFunctionName()
            self.checkCamelCaseUpperFunction(cls, name, 'method')
        method = Function(kind, name, static, retType, cls, access)
        method.annotations.update(annots)
        method.annotations.update(self.annotations)
        if static and retType.endswith('&') and not retType.startswith('const'):
            self.errors.append(name.pos, 'A static ' + kind + ' must not return non-const references.')
        self.lex.consume('(')
        method.params = self.parseParams()
        if cls.interface == Class.VIRTUAL and name == 'GetHashCode' and len(method.params) == 0 and cls.name != 'ObjectInterface':  
            self.errors.append(t.pos, 'The name GetHashCode can\'t be used for virtual methods, use GetHashCodeImpl instead.')

        # all params scanned, scan comment for in, out, inout
        comment = ''.join(doclist)
        for param in method.params:
            foundDoc = False
            pos = -1 if not comment else comment.find('] ' + param.name)
            if pos != -1:
                posNewLine = comment.rfind('\n', 0, pos)
                if posNewLine == -1:
                    posNewLine = 0
                posParam = comment.find('@param[', posNewLine, pos)
                if posParam != -1:
                    posOut = comment.find('out', posParam, pos)
                    posIn = comment.find('in', posParam, pos)
                    param.output = (posOut != -1)
                    param.input = (posIn != -1)
                    foundDoc = True
            if not foundDoc:
                if cls.interface and cls.parseAnnotation('export_rpc', False) is True and param.type[-1] == '&' and param.type.find('const') == -1:
                    self.styleerrors.append(t.pos, 'parameter "' + param.name + '" of ' + method.name + '() is not documented and assumed as output or inoutput value.')
                # else:
                #    self.warnings.append(t.pos, 'parameter "' + param.name + '" of ' + method.name + '() is not documented and assumed to be an input value.')

        while True:
            t = self.lex.getNoEof(cls)
            if t == 'const':
                method.const = True
            elif t == 'final' or t == 'override':
                pass
            elif t == ';' or t == '{':
                if t == '{':
                    if method.kind == 'MAXON_METHOD':
                        self.errors.append(t.pos, 'Method ' + str(method) + ' must not have an implementation body.')
                    self.parseUntil(cls, t, False, '}', False, -1)
                break
            else:
                t.pos.raiseError('Unexpected token ' + t)
        return method

    # parses a variable or function declaration
    def tryParseVarOrFunction(self, t, owner, access):
        self.lex.lookahead()
        explicitImplicitFound = False
        static = False
        constexpr = False
        explicit = False
        checkLineCount = True
        checkNaming = True
        method = False
        while (t in varOrFunctionPrefixes) or (t == '[' and self.lex.next() == '['):
            extern = False
            property = False
            if t == '[':
                self.parseAttributeRest()
            elif t == 'static':
                static = True
            elif t == 'constexpr':
                constexpr = True
            elif t == 'explicit' or t == 'MAXON_IMPLICIT':
                explicitImplicitFound = True
                if t == 'explicit':
                    explicit = True
            elif t == 'MAXON_WARN_MUTE_FUNCTION_LENGTH':
                checkLineCount = False
            elif t == 'MAXON_WARN_MUTE_NAMING':
                checkNaming = False
            elif t == 'MAXON_METHOD':
                method = True
            elif t == 'extern':
                extern = True
            elif t == '@property':
                property = True
                checkNaming = False
            elif t == '__declspec':
                t = self.lex.consume('(')
                self.parseUntil(owner, t, False, ')', False, -1)
            elif t == 'virtual':
                dir = os.path.basename(self.args.directory)
                if self.args.stylecheck and self.args.stylecheckOptions.get('virtual', True):
                    if dir.endswith('.framework') and not dir.startswith('private_') and dir not in ['core.framework', 'kernel.framework', 'cinema.framework', 'cinema_legacy.framework', 'cinema_maxon.framework']:
                        self.warnings.append(t.pos, 'Virtual functions are not allowed in public frameworks.')
            t = self.lex.get(owner)
            if extern and t.type == Token.STRING:
                t = self.lex.get(owner)
            elif property and t == '(':
                self.parseUntil(owner, t, False, ')', False, -1)
                t = self.lex.get(owner)
        if t.type == Token.IDENT or t == '::': # the type might start with ::
            if t == owner.simpleName and isinstance(owner, Class) and self.lex.next() == '(':
                # found a constructor
                ctor = t
                self.lex.consume('(')
                params = self.parseParams()
                self.lex.accept()
                while self.lex.next() in ['noexcept']:
                    self.lex.get(owner)
                deleted = False
                if self.lex.next() in [':', '{', '=']:
                    t = self.lex.getNoEof(owner)
                    if t == ':':
                        dummy, t = self.parseUntil(owner, None, False, '{', False, -1)
                    if t == '{':
                        self.parseUntil(owner, t, False, '}', False, -1)
                    elif t == '=':
                        if self.lex.getIdent() == 'delete':
                            deleted = True
                        self.lex.consume(';')
                if not explicitImplicitFound and len(params) >= 1 and (len(params) == 1 or params[1].default or params[1].pack):
                    if self.args.stylecheck and self.args.stylecheckOptions.get('explicit', True) and params[0].type.find(ctor) < 0:
                        self.styleerrors.append(ctor.pos, 'Either explicit or MAXON_IMPLICIT has to be used for this constructor of ' + ctor + '.')
                if method:
                    self.errors.append(ctor.pos, 'A constructor must not be marked with MAXON_METHOD.')
                decl = Function('constructor', 'constructor', False, 'void', owner, access)
                decl.params = params
                decl.annotations.update(self.annotations)
                decl.explicit = explicit
                decl.deleted = deleted
                return decl
            conversion = t if t == 'operator' else None
            if t == '::':
                type = None
            if conversion:
                type, constType, dummy = self.parseTypeCheckConst(None, False, False)
            else:
                type, constType, dummy = self.parseTypeCheckConst(t, True, True)
            if type:
                name = conversion if conversion else self.lex.get(owner)
                while name in varOrFunctionPostfixes:
                    name = self.lex.get(owner)
                if type.endswith(')') and (name == '{' or name == ':'):
                    # This looks like a constructor or destructor definition of the form [A::]X::X(...) [: ...] {...}. Just ignore this because we only need the declaration. 
                    self.lex.accept()
                    t = name
                    if t == ':':
                        # skip base constructor call and member initializers
                        try:
                            self.lex.ignoreDirectives += 1
                            while True:
                                dummy, t = self.parseUntil(owner, None, True, '({', False, -1)
                                self.handleBlock(owner, t, False, True, -1)
                                t = self.lex.getNoEof(owner)
                                t.expect([',', '{'])
                                if t == '{':
                                    break
                        finally:
                            self.lex.ignoreDirectives -= 1
                    self.parseUntil(owner, t, False, '}', False, -1)
                    return True
                elif name.type == Token.IDENT:
                    if not conversion:
                        name = self.lex.parseOperatorPostfix(name)
                    t = self.lex.get(owner)
                    namePrefix = None
                    unspecializedName = name
                    while t == '::' or t == '<':
                        if t == '<':
                            name = Token(name + '<' + self.parseSpecialization(t) + '>', Token.IDENT, name.pos)
                            t = self.lex.get(owner)
                        else:
                            # This is a qualified name, so it's a definition and not a declaration.
                            # Set namePrefix, this is used later to avoid the creation of a Declaration.
                            namePrefix = (namePrefix + '::' + unspecializedName) if namePrefix else unspecializedName
                            name = self.lex.get(owner)
                            if name.type != Token.IDENT:
                                self.lex.reject()
                                return None
                            name = self.lex.parseOperatorPostfix(name)
                            unspecializedName = name
                            t = self.lex.get(owner)
                    if t == ';' or t == '=' or t == '[' or t == '{':
                        self.parseVariableDeclarationRest(owner, t)
                        self.lex.accept()
                        if namePrefix:
                            return None
                        if checkNaming and isinstance(owner, Namespace) and not name.startswith('g_') and not (constType or constexpr) and not self.isObjectiveC \
                           and self.args.stylecheck and self.args.stylecheckOptions.get('naming', True) and name != 'PRIVATE_MAXON_MODULE':
                            self.warnings.append(name.pos, 'The name of the global variable ' + name + ' does not start with g_.')
                        decl = Variable(name, static, type, owner, access)
                        return decl
                    elif t == '(':
                        params = self.parseParams(True)
                        if params is not None:
                            self.lex.accept()
                            lineCount = 0
                            constFunction = False
                            deleted = False
                            while True:
                                t = self.lex.getNoEof(owner)
                                if t == 'const':
                                    constFunction = True
                                elif t == '__attribute__':
                                    t = self.lex.consume('(')
                                    self.parseUntil(owner, t, False, ')', False, -1)
                                elif t == '->':
                                    type = self.parseType()
                                elif t == ';':
                                    break
                                elif t == 'delete':
                                    deleted = True
                                elif t == '{':
                                    comp = owner.lookup(namePrefix.replace('::', '.'), True) if namePrefix else owner
                                    comp = isinstance(comp, Class) and comp.component and comp
                                    if comp:
                                        self.lex.methodNamesClass = comp
                                    firstLine = t.pos.line
                                    s, t = self.parseUntil(owner, t, False, '}', False, -1)
                                    if comp:
                                        self.lex.methodNamesClass = None
                                        if namePrefix:
                                            self.checkAmbiguousCalls(comp)
                                    lineCount = t.pos.line + 1 - firstLine
                                    if self.args.stylecheck and self.args.stylecheckOptions.get('supercall', True) \
                                      and owner.qname() != 'maxon.ObjectImpl' \
                                      and (isComponentComparison(name, params) or (name == 'GetHashCodeImpl' and isinstance(owner, Class) and owner.component)) \
                                      and s.find('super.' + name + '(') < 0: 
                                        self.warnings.append(name.pos, 'This implementation of ' + name + ' does not call the super implementation.')
                                    break
                            limit = self.args.stylecheckOptions.get('max-linecount', 500)
                            if checkLineCount and self.args.stylecheck and lineCount > limit:
                                self.warnings.append(name.pos, 'The function ' + name + ' has ' + str(lineCount) + ' lines, this exceeds the limit of ' + str(limit) + ' lines.')
                            if namePrefix:
                                return None
                            if isinstance(owner, Class) and owner.component:
                                if name in owner.methodNames:
                                    if not method:
                                        self.errors.append(name.pos, 'The function ' + name + ' has the name of method ' + str(owner.methodNames[name]) + '::' + name + ', but is not marked with MAXON_METHOD.')
                                elif not owner.missingInterfaces:
                                    if method:
                                        self.errors.append(name.pos, 'The function ' + name + ' is not a method of one of the interfaces, but it is marked with MAXON_METHOD.')
                            elif method:
                                self.errors.append(name.pos, 'Only functions in interfaces or in a class directly derived from Component may be marked with MAXON_METHOD.')
                            self.checkCamelCaseUpperFunction(owner, unspecializedName, 'function')
                            createError = name == 'Create' and isinstance(owner, Class) and owner.isError
                            if createError:
                                decl = Function('constructor', 'constructor', static, type, owner, 'public')
                            else:
                                decl = Function('function', name, static, type, owner, access)
                            decl.params = params
                            decl.const = constFunction
                            decl.annotations.update(self.annotations)
                            decl.explicit = explicit
                            decl.deleted = deleted
                            return decl
        self.lex.reject()
        return None

    # parses an observable method declaration if t is a valid start of such a declaration, otherwise does nothing
    def tryParseObservable(self, t, cls, access):
        static = t == 'MAXON_OBSERVABLE_STATIC'
        if not (static or t == 'MAXON_OBSERVABLE'):
            return None
        self.lex.consume('(')
        type = self.parseType()
        self.lex.consume(',')
        name = self.lex.getIdent()
        self.lex.consume(',')
        self.lex.consume('(')
        params = self.parseParams()
        self.lex.consume(',')
        combiner = self.parseType()
        self.lex.consume(')')
        method = Function('MAXON_METHOD', name, static, 'maxon::ObservableRef<' + name + 'Delegate>', cls, access)
        method.const = not static
        method.observable = Observable(t, name, type, params, combiner, static, cls, access)
        method.annotations.update(self.annotations)
        return method

    # parses a declaration at namespace or class level, does nothing if t is no recognized declaration
    def tryParseNamespaceOrClassDeclaration(self, t, owner, access):
        if t == 'MAXON_REGISTRY' or t == 'MAXON_DECLARATION' or t == 'MAXON_DECLARATION_CLASS':
            if t == 'MAXON_DECLARATION' and not isinstance(owner, Namespace):
                self.errors.append(t.pos, 'Within a class you have to use MAXON_DECLARATION_CLASS.')
            elif t == 'MAXON_DECLARATION_CLASS' and not isinstance(owner, Class):
                self.errors.append(t.pos, 'At namespace scope you have to use MAXON_DECLARATION.')
            declToken = t
            start = self.lex.consume('(')
            type = self.parseType()
            self.lex.consume(',')
            name = self.lex.getIdent()
            self.lex.consume(',')
            dependencies = False
            registry = False
            if t == 'MAXON_REGISTRY':
                registry = True
                id = self.lex.getString()
                t = self.lex.getNoEof(owner)
                if t == ',':
                    self.lex.consume('MAXON_REGISTRY_DEPENDENCIES')
                    start = self.lex.consume('(')
                    self.parseUntil(owner, start, False, ')', False, -1)
                    dependencies = True
                    t = self.lex.getNoEof(owner)
                t.expect(')')
            else:
                id, dummy = self.parseUntil(owner, start, False, ')', False, -1)
            self.lex.consume(';')
            if registry:
                d = owner.find('namespace', name)
                if not d:
                    d = Namespace(name, owner)
                d.registry = True
            else:
                d = CppDeclaration(declToken, name, owner, 'public')
            d.type = type
            d.id = id
            d.dependencies = dependencies
            return d
        elif t == 'MAXON_GRAPH_ATTRIBUTE':
            self.lex.consume('(')
            id = self.lex.getString()
            self.lex.consume(',')
            name = self.lex.getIdent()
            self.lex.consume(',')
            type = self.parseType()
            self.lex.consume(')')
            self.lex.consume(';')
            d = CppDeclaration(t, name, owner, access)
            d.id = id
            d.type = type
            return d
        elif t == 'typedef':
            typedef = t
            if self.lex.next() == 'struct':
                self.lex.getNoEof(owner)
                if self.args.stylecheck and self.args.stylecheckOptions.get('typedef-struct', True):
                    t = self.lex.getNoEof(owner)
                    if t.type == Token.IDENT:
                        t = self.lex.getNoEof(owner)
                    if t == '{':
                        self.styleerrors.append(t.pos, 'Style guide forbids C-style typedef struct declarations.')
                        self.parseUntil(owner, None, False, '}', False, -1)
                self.parseUntil(owner, None, False, ';', False, -1)
                return True
            else:
                typedef, t = self.parseUntil(owner, None, False, ';', False, -1)
                i = len(typedef) - 1
                while i >= 0 and isIdentifierPart(typedef[i]):
                    i -= 1
                name = typedef[i + 1:]
                if name:
                    decl = TypeAlias('typealias_typedef', name, None, owner, access)
                    decl.annotations.update(self.annotations)
                    return decl
                return True
        elif t == 'using':
            t = self.lex.getNoEof(owner)
            if t == 'namespace':
                if self.isHeader and self.args.stylecheck and self.args.stylecheckOptions.get('using', True):
                    self.styleerrors.append(t.pos, 'Style guide forbids using namespace in namespace scope within header files.')
                u = list()
                while True:
                    t = self.lex.getNoEof(owner)
                    u.append(t)
                    t = self.lex.getNoEof(owner)
                    t.expect(['::', ';'])
                    if t == ';':
                        break
                if isinstance(owner, Namespace):
                    owner.usings.add('.'.join(u))
            else:
                name = t
                t = self.lex.getNoEof(owner)
                if t == '=':
                    alias, t = self.parseUntil(owner, None, False, ';', False, -1)
                    decl = TypeAlias('typealias', name, None, owner, access)
                    decl.annotations.update(self.annotations)
                    decl.bases.append((alias, 'public', ''))
                    return decl
                else:
                    name = None
                    while True:
                        if t.type == Token.IDENT:
                            name = t
                        t = self.lex.getNoEof(owner)
                        if t == ';':
                            break
                        name = None
                    if name and isinstance(owner, Class):
                        return Using(name, owner, access)
        elif t.type == Token.DEFINE:
            t = self.lex.getIdent()
            decl = None
            if not t.endswith('H__'):
                decl = Define(t, owner)
            if self.lex.next() == '(':
                self.lex.consume('(')
                while True:
                    t = self.lex.getNoEof(owner)
                    if t == ')':
                        break
                    elif decl and (t.type == Token.IDENT or t == '...'):
                        decl.params.append(t)
            self.lex.skipDirectiveRest('', False, t.pos)
            return decl
        elif (t.startswith('MAXON_') or t.find('MACRO') >= 0) and not (t in varOrFunctionPrefixes):
            # skip a macro usage
            t = self.lex.next()
            if t == '(':
                t = self.lex.consume('(')
                self.parseUntil(owner, t, False, ')', False, -1)
            return None
        else:
            return self.tryParseEnum(t, owner, access) or self.tryParseVarOrFunction(t, owner, access)

    # parses a declaration at class level, does nothing if t is no recognized declaration
    def tryParseClassDeclaration(self, t, owner, access):
        if t == 'MAXON_ATTRIBUTE_CLASS':
            start = self.lex.consume('(')
            self.parseUntil(owner, None, False, ',', False, -1)
            name = self.lex.getIdent()
            self.lex.consume(',')
            id = self.lex.next()            
            self.parseUntil(owner, start, False, ')', False, -1)
            decl = Attribute(t, name, owner, access)
            if id.type == Token.STRING and id[0] == '"':
                decl.id = id
            return decl
        elif t == '~':
            self.lex.consume(owner.simpleName)
            return None
        elif t == 'MAXON_COMPONENT':
            t = self.lex.consume('(')
            kind = self.lex.getNoEof(owner)
            if kind != ')':
                if kind not in ['NORMAL', 'ABSTRACT', 'FINAL', 'SINGLETON', 'FINAL_SINGLETON']:
                    self.errors.append(kind.pos, 'The class kind of a component has to be one of NORMAL, ABSTRACT, FINAL, SINGLETON, FINAL_SINGLETON.')
                if kind.startswith('FINAL'):
                    owner.finalComponent = True;
                self.parseUntil(owner, t, False, ')', False, -1)
            self.lex.consume(';')
        else:
            if t == 'mutable':
                t = self.lex.getNoEof()
            d = self.tryParseNamespaceOrClassDeclaration(t, owner, access)
            if d:
                return d
            elif t.startswith('MAXON_IMPLEMENTATION'):
                if owner.bases:
                    access = owner.bases[0][1]
                    if access == 'public' and owner.bases[0][0].endswith('Interface'):
                        self.errors.append((access if isinstance(access, Token) else t).pos, 'An implementation class must not use public inheritance from its interface.')
                owner.implementation = True
        return True

    # returns (TemplateParam, next token)
    def parseSingleTemplateParam(self, generic):
        self.lex.lookahead()
        tp = None
        variance = None
        t = self.lex.getNoEof()
        if t == '(':
            self.lex.accept()
            variance = self.parseType()
            self.lex.consume(')')
            self.lex.lookahead()
            t = self.lex.getNoEof()
        if t == 'typename' or t == 'class':
            if t == 'class' and self.args.stylecheck and self.args.stylecheckOptions.get('class-for-templateparam', True):
                self.styleerrors.append(t.pos, 'Use typename instead of class for template type parameters.')
            # probably a type parameter, but it could also be a non-type parameter of the form typename T::M X
            self.lex.lookahead()
            test = self.lex.getNoEof()
            if test.type == Token.IDENT:
                test = self.lex.getNoEof()
            self.lex.reject()
            if test in ['...', '=', ',', '>', ')']:
                # really a type parameter
                tp = TypeTemplateParam()
        if tp:
            self.lex.accept()
        elif t == 'template':
            self.lex.accept()
            tmp = Template()
            self.parseTemplateParamDecl(tmp)
            tp = TemplateTemplateParam(tmp)
            self.lex.consume('class')
        else:
            self.lex.reject()
            type = self.parseType()
            tp = NontypeTemplateParam(type)
        tp.pos = t.pos
        tp.variance = variance
        t = self.lex.getNoEof()
        if t == '...':
            tp.pack = True
            t = self.lex.getNoEof()
        if t.type == Token.IDENT:
            tp.name = t
            t = self.lex.getNoEof()
        if t == '::':
            # special case like "T BASEATTR::ValueType::* MEMBER", ignore for now
            dummy, t = self.parseUntil(None, None, True, ',>)', False, -1)
        if t == '=':
            if not isinstance(tp, NontypeTemplateParam):
                tp.default = self.parseType()
                t = self.lex.getNoEof()
            else:
                tp.default, t = self.parseUntil(None, None, True, ',>)', False, -1)
        elif generic:
            self.errors.append(t.pos, 'A default argument has to be given for template parameter ' + tp.name + '.')
        return (tp, t)
        

    # parses a template parameter declaration in angular brackets and adds each parameter as a TemplateParam instance to template.params
    def parseTemplateParamDecl(self, template):
        self.lex.consume('<')
        while True:
            tp, t = self.parseSingleTemplateParam(False)
            template.params.append(tp)
            t.expect(['>', ','])
            if t == '>':
                return

    # parses a template declaration it t is 'template' and sets self.template to the parsed declaration, otherwise sets self.template to None
    def tryParseTemplateDeclaration(self, t):
        self.template = None
        if t == 'template' and self.lex.next() == '<':
            self.template = Template()
            self.parseTemplateParamDecl(self.template)
            t = self.lex.getNoEof()
        return t

    # parses a single annotation declaration if possible and adds it to the dict self.annotations
    def parseAnnotation(self):
        self.lex.consume('{')
        while True:
            id = self.lex.getIdent()
            t = self.lex.getNoEof()
            if t == '=':
                a, t = self.parseUntil(None, None, False, '},', False, -1)
                a = Token(a, Token.INVALID, t.pos)
            else:
                a = True
            self.annotations[id] = a
            t.expect(['}', ','])
            if t == '}':
                break

    # parses the rest of an attribute specifier (exluding the first [ ) and adds it to the dict self.annotations
    def parseAttributeRest(self):
        self.lex.consume('[')
        using = None
        nextToken = None
        while True:
            t = nextToken or self.lex.getNoEof()
            nextToken = None
            if t == ']':
                self.lex.consume(']')
                break
            elif t == 'using':
                using = self.lex.getIdent()
                self.lex.consume(':')
            elif t.type == Token.IDENT:
                attr = t
                arg = True
                if using:
                    attr = Token(using + '::' + attr, Token.IDENT, t.pos)
                else: 
                    nextToken = self.lex.getNoEof()
                    if nextToken == '::':
                        t = self.lex.getIdent()
                        attr = Token(attr + '::' + t, Token.IDENT, t.pos)
                        nextToken = None
                if not nextToken:
                    nextToken = self.lex.getNoEof()
                if nextToken == '(':
                    arg, t = self.parseUntil(None, nextToken, False, ')', False, -1)
                    nextToken = self.lex.getNoEof()
                    arg = Token(arg, Token.INVALID, attr.pos)
                nextToken.expect([',', ']'])
                if nextToken == ',':
                    nextToken = None
                if attr.startswith('maxon::'):
                    attr = Token(attr[7:], Token.IDENT, t.pos)
                self.annotations[attr] = arg
            else:
                self.errors.append(t.pos, 'Expected attribute identifier.')
                break

    def resetDoc(self):
        self.doclist = []
        self.annotations = {}

    # parses an enum declaration if t is 'enum', otherwise does nothing
    def tryParseEnum(self, t, owner, access):
        if t != 'enum':
            return None
        start = t
        t = self.lex.getNoEof(owner)
        scoped = False
        if t == 'class' or t == 'struct':
            scoped = True
            t = self.lex.getNoEof(owner)
        if t == '{':
            self.parseUntil(owner, t, False, '}', False, -1)
            return None
        if t.type != Token.IDENT:
            return None
        if self.args.stylecheck and self.args.stylecheckOptions.get('enum-class', True) and not scoped:
            self.styleerrors.append(t.pos, 'Unscoped enums must not be declared, write "enum class" instead of "enum".')
        name = t
        t = self.lex.getNoEof(owner)
        type = None
        if scoped and t == ':':
            type = self.parseType()
            t = self.lex.getNoEof(owner)
        if t != '{':
            return None
        e = Enum(name, scoped, type, owner, access)
        last = None
        doc = []
        t = self.lex.getNoEof(e)
        while True:
            if t.type == Token.POSTFIX_DOC and last:
                last.doclist.append(t)
            elif t.type == Token.PREFIX_DOC:
                doc.append(t)
            elif t.type == Token.DIRECTIVE:
                Directive(t, e)
            elif t == 'MAXON_MISC_DEPRECATED_ENUMVALUE':
                start = self.lex.consume('(')
                self.parseUntil(owner, start, False, ')', False, -1)
            elif t.type == Token.IDENT:
                name = t
                value = None
                t = self.lex.getNoEof(e)
                if t == '=':
                    value, t = self.parseUntil(owner, None, False, ',}/', False, -1)
                last = EnumValue(name, value, e)
                last.doclist = doc
                doc = []
                continue
            elif t == '}':
                break
            elif t != ',':
                t.pos.raiseError('Expected \',\', found ' + t + ' instead.')
            t = self.lex.getNoEof(e)
        t = self.lex.getNoEof(owner)
        e.registered = t.find('_ENUM_') >= 0
        if e.registered:
            enumToken = t
            if self.args.stylecheck and self.args.stylecheckOptions.get('whitespace', True) and self.lex.leadingWhitespace(t) != ' ':
                self.styleerrors.append(t.pos, 'Styleguide requires a single space in front of ' + t + '.')
            e.flags = t.find('_FLAGS') >= 0
            if isinstance(owner, Class):
                if not t.endswith('_CLASS'):
                    self.styleerrors.append(t.pos, 'You have to use one of MAXON_ENUM_LIST_CLASS, MAXON_ENUM_ORDERED_LIST_CLASS, MAXON_ENUM_FLAGS_CLASS, MAXON_ENUM_ORDERED_FLAGS_CLASS after a class-scope enum.')
            else:
                if t.startswith('CLASS_'):
                    self.styleerrors.append(t.pos, 'You have to use one of MAXON_ENUM_LIST, MAXON_ENUM_ORDERED_LIST, MAXON_ENUM_FLAGS, MAXON_ENUM_ORDERED_FLAGS after a namespace-scope enum.')
            self.lex.consume('(')
            t = self.lex.getIdent()
            if t != e.name:
                self.errors.append(t.pos, 'The name ' + t + ' does not match the name ' + e.name + ' of the enum.')
            t = self.lex.getNoEof(e)
            t.expect([')', ','])
            if t == ',':
                e.id = self.lex.getString()
                t = self.lex.getNoEof(e)
                t.expect([')', ','])
                if t == ',':
                    self.lex.consume('EARLY')
                    self.lex.consume(')')
                    e.early = True
            t = self.lex.consume(';')
            e.code = self.lex.cin.source[start.pos.index:enumToken.pos.index]
            e.line = enumToken.pos.line
        if self.args.stylecheck and self.args.stylecheckOptions.get('enum-registration', True) and not e.registered:
            if isinstance(owner, Class):
                self.styleerrors.append(t.pos, 'You have to add one of MAXON_ENUM_LIST_CLASS, MAXON_ENUM_ORDERED_LIST_CLASS, MAXON_ENUM_FLAGS_CLASS, MAXON_ENUM_ORDERED_FLAGS_CLASS after the enum.')
            else:
                self.styleerrors.append(t.pos, 'You have to add one of MAXON_ENUM_LIST, MAXON_ENUM_ORDERED_LIST, MAXON_ENUM_FLAGS, MAXON_ENUM_ORDERED_FLAGS after the enum.')
        return e

    def checkAmbiguousCalls(self, cls):
        if self.args.stylecheckOptions.get('ambiguouscalls', True) and not cls.finalComponent:
            for c in cls.ambiguousCalls:
                for f in cls.findAll(Function, c):
                    if not f.static:
                        self.warnings.append(c.pos, 'Ambiguous call to implemented method, use either self.' + c + ' for a virtual call or ' + cls.name + '::' + c + ' for a direct call.')
                        break
        if self.args.stylecheckOptions.get('selfcalls', True) and cls.finalComponent:
            for c in cls.selfCalls:
                for f in cls.findAll(Function, c):
                    self.warnings.append(c.pos, 'Virtual call to implemented method ' + c + ' of final component, remove the self prefix for better performance.')
                    break
        cls.ambiguousCalls = []

    # parses a class declaration if t is 'class', 'struct', 'union' or a similar keyword followed by an identifier and one of {:;, otherwise does nothing
    def tryParseClass(self, t, owner, access, friend):
        if t == 'class' or t == 'struct' or t == 'union' or t == '@class' or t == '@protocol' or t == '@interface' or t == 'interface':
            generic = None
            kind = t
            anonymous = self.lex.next() == '{'
            self.lex.lookahead()
            if anonymous:
                name = Token('anonymous#' + str(t.pos), Token.IDENT, t.pos)
            else:
                name = self.lex.get(owner)
                if name == 'alignas':
                    start = self.lex.consume('(')
                    self.parseUntil(owner, start, False, ')', False, -1)
                    name = self.lex.get(owner)
                if name == 'MAXON_WARN_UNUSED_CLASS':
                    name = self.lex.get(owner)                  
            punct = self.lex.get(owner)
            while punct == '::':
                if not friend:
                    owner = owner.findOrCreate(name)
                name = self.lex.get(owner)
                punct = self.lex.get(owner)
            clsName = name
            specialization = None
            final = None
            if punct == '<':
                specialization = self.parseSpecialization(punct)
                clsName = name + '<' + specialization + '>'
                punct = self.lex.get(owner)
            if punct == 'final':
                final = punct
                punct = self.lex.get(owner)
            while punct.type == Token.DIRECTIVE:
                punct = self.lex.get(owner)
            if name.type == Token.IDENT and (punct == '{' or punct == ':' or punct == ';'):
                if not anonymous and name != 'RESTRICT':
                    self.checkCamelCaseUpper(owner, name, 'class')
                # class declaration found
                self.lex.accept()
                if friend:
                    return True
                cls = owner.find(Class, clsName)
                haveDef = cls and not cls.forward
                copyDoclist = None
                if cls and cls.forward:
                    # if cls already exists due to a forward declaration, remove it as this would lead to a wrong order (we need the order of the class definitions, not of their declarations)
                    copyDoclist = cls.doclist
                    owner.children.remove(cls)
                cls = Class(clsName, self.template, owner, access, punct == ';')
                if copyDoclist:
                    cls.doclist = copyDoclist
                if haveDef:
                    # if we already have a class definition (namely, in another #ifdef branch), we only parse the current definition, but otherwise ignore it
                    owner.children.remove(cls)
                cls.simpleName = name
                cls.annotations.update(self.annotations)
                cls.ambiguousCalls = []
                cls.selfCalls = []
                cls.methodNames = dict()
                cls.anonymous = anonymous
                if punct == ':':
                    # parse base classes
                    self.lex.lookahead()
                    t = self.lex.getNoEof(cls)
                    if t == 'public' or t == 'protected' or t == 'private':
                        access = t
                        self.lex.accept()
                    else:
                        access = 'private' if kind == 'class' else 'public'
                        self.lex.reject()
                    if self.lex.next() == 'MAXON_INTERFACE_BASES':
                        cls.baseInterfaces = []
                        self.lex.get()
                        self.lex.consume('(')
                        while True:
                            type = self.parseType()
                            gen = ''
                            pos = type.find('<')
                            if pos >= 0:
                                base = type[:pos]
                                scope = self.summary.lookup(owner.qname('.'), True)
                                base = scope.lookup(base)
                                if isinstance(base, Class) and base.generic:
                                    # we have to split the template arguments into the template part and the generic part
                                    tparamCount = base.template or 0
                                    args, dummy = splitComma(type[pos+1:])
                                    if len(args) > tparamCount:
                                        type = type[:pos]
                                        if tparamCount:
                                            type += '<' + ', '.join(args[:tparamCount]) + '>'
                                        gen = ''.join(', ' + a for a in args[tparamCount:])
                            cls.baseInterfaces.append((type, gen))
                            t = self.lex.getNoEof()
                            t.expect([',', ')'])
                            if t == ')':
                                break
                        t = self.lex.getNoEof(cls)
                    else: 
                        t = self.parseType()
                        next = self.lex.getNoEof(cls)
                        gen = ''
                        if next == 'MAXON_GENERIC_BASE':
                            # template arguments for the generic base interface follow
                            self.lex.consume('(')
                            args, next = self.parseUntil(cls, None, False, ')', False, -1)
                            gen = ', ' + args
                            next = self.lex.getNoEof(cls)
                        cls.bases.append((t, access, gen))
                        t = next
                    while t == ',':
                        self.lex.lookahead()
                        t = self.lex.getNoEof(cls)
                        if t == 'public' or t == 'protected' or t == 'private':
                            access = t
                            self.lex.accept()
                        else:
                            access = 'private' if kind == 'class' else 'public'
                            self.lex.reject()
                        t = self.parseType()
                        cls.bases.append((t, access, ''))
                        t = self.lex.getNoEof(cls)
                    if t != '{':
                        # may happen if #if/#else/#endif is used in class declaration, ignore such a class declaration
                        owner.children.remove(cls)
                        return cls
                if punct != ';':
                    # parse class definition
                    if len(cls.bases) == 1:
                        bases = cls.bases[0][0]
                        if bases.startswith('maxon::'):
                            bases = bases[7:]
                        i = bases.find('<')
                        if i >= 0:
                            comp = bases[:i]
                            bases = bases[i+1:]
                            basicComp = comp in ['Component', 'ComponentWithBase', 'AdapterComponent']
                            if basicComp or comp.endswith('Component'):
                                methods = dict()
                                skip = 1 if comp == 'Component' or not basicComp else 2
                                scope = self.summary.lookup(cls.qname('.'), True)
                                usings = set()
                                ownerParent = owner
                                while ownerParent:
                                    if isinstance(ownerParent, Namespace):
                                        usings |= ownerParent.usings
                                    ownerParent = ownerParent.owner
                                bases, i = splitComma(bases)
                                for base in bases:
                                    c = base.find('<')
                                    if c >= 0:
                                        base = base[:c]
                                    if skip > 0:
                                        skip -= 1
                                        if not basicComp and not base.startswith(clsName):
                                            # For the case of special components like UnitTestComponent, check that the first template argument matches the current class
                                            # to avoid that a base class which is unrelated to components is considered a component base class just because its name happens to end with Component.
                                            break
                                    else:
                                        resolved = scope.lookup(base)
                                        if not resolved:
                                            for u in usings:
                                                resolved = scope.lookup(u + '.' + base)
                                                if resolved:
                                                    break
                                        if resolved:
                                            if isinstance(resolved, Class):
                                                resolved.addMethodNames(methods)
                                        elif base.endswith('Interface'):
                                            self.warnings.append(punct.pos, 'Interface ' + base + ' not found in frameworks.')
                                            cls.missingInterfaces = True
                                else:
                                    # We've found a component class when the for loop hasn't been terminated by break.
                                    if not basicComp:
                                        # For a special component like UnitTestComponent we assume that UnitTestInterface is an implicit base interface.
                                        i = comp[:-9] + 'Interface'
                                        i = scope.lookup(i)
                                        if isinstance(i, Class):
                                            i.addMethodNames(methods)
                                    cls.implementation = True
                                    cls.component = True
                                    cls.methodNames = methods
                    self.resetDoc()
                    interface = None
                    access = 'private' if kind == 'class' else 'public'
                    isEqual = None
                    getHashCode = None
                    addToHxxClass = None
                    addToHxxClassStart = -1
                    addToHxxClassAccess = None
                    refClassMembers = []
                    while True:
                        t = self.lex.getNoEof(cls)
                        resetDoc = True
                        # check for relevant tokens at class level
                        if t == '}':
                            if not kind.startswith('@'):
                                t = self.lex.getNoEof(cls)
                                if t != ';':
                                    if not anonymous:
                                        self.errors.append(t.pos, 'Expected ; immediately after definition of ' + kind + ', use a separate declaration for ' + t + '.')
                                    self.parseVariableDeclarationRest(cls, self.lex.getNoEof())
                            break
                        elif t.type == Token.ANNOTATION:
                            self.parseAnnotation()
                            resetDoc = False
                        elif t.type == Token.PREFIX_DOC:
                            self.doclist.append(t)
                            resetDoc = False
                        elif t == 'public' or t == 'protected' or t == 'private':
                            self.lex.consume(':')
                            access = t
                        elif t.type == Token.DIRECTIVE or t.type == Token.DOC_DIRECTIVE:
                            Directive(t, cls)
                            resetDoc = False
                        elif t == 'MAXON_ADD_TO_REFERENCE_CLASS' or t == 'MAXON_ADD_TO_CONST_REFERENCE_CLASS' or t == 'MAXON_ADD_TO_COPY_ON_WRITE_REFERENCE_CLASS' or t == 'MAXON_ADD_TO_INTERFACE_TEMPLATE_CLASS':
                            if addToHxxClass:
                                self.errors.append(t.pos, 'Nesting of ' + t + ' not allowed.')
                            else:
                                addToHxxClass = t
                                t = self.lex.consume('(')
                                addToHxxClassStart = self.lex.cin.index
                                addToHxxClassAccess = access
                        elif t == ')' and addToHxxClass:
                            d = Declaration(addToHxxClass, None, cls, access)
                            d.code = self.lex.cin.source[addToHxxClassStart:self.lex.cin.index - 1] + '\n'
                            addToHxxClass = None
                            access = addToHxxClassAccess
                        elif t != '[' and self.handleBlock(cls, t, False, True, -1):
                            pass
                        elif t == 'MAXON_INTERFACE_NONVIRTUAL' or t == 'MAXON_INTERFACE_NONVIRTUAL_DERIVED' or t == 'MAXON_INTERFACE':
                            if t == 'MAXON_INTERFACE':
                                cls.interface = Class.VIRTUAL
                            else:
                                cls.interface = Class.NONVIRTUAL
                            self.lex.consume('(')
                            self.lex.consume(name)
                            self.lex.consume(',')
                            refKind = self.lex.getIdent()
                            self.lex.consume(',')
                            cls.id = self.lex.getString()
                            self.lex.consume(')')
                            cls.derived = t == 'MAXON_INTERFACE_NONVIRTUAL_DERIVED'
                            if cls.template and cls.interface == Class.NONVIRTUAL:
                                self.errors.append(name.pos, 'Interface templates aren\'t allowed for non-virtual interfaces.')
                            cls.setRefKind(refKind)
                            if cls.interface == Class.VIRTUAL and (cls.refKind is None or cls.refKind == Class.POINTER or cls.refKind == Class.CONST_POINTER):
                                self.errors.append(name.pos, 'Virtual interfaces must not use ' + refKind)
                            if cls.interface == Class.NONVIRTUAL and (cls.refKind == Class.COW or cls.refKind == Class.ACOW):
                                method = Function('MAXON_METHOD', 'Alloc', True, cls.name + '*', cls, 'public')
                                method.params.append(Parameter('const maxon::SourceLocation&', 'allocLocation'))
                                method = Function('MAXON_METHOD', 'Alloc', True, cls.name + '*', cls, 'public')
                                method.annotations['refclass'] = 'false'
                                method.params.append(Parameter('const maxon::SourceLocation&', 'allocLocation'))
                                method.params.append(Parameter('const ' + cls.name + '&', 'object'))
                        elif t == 'MAXON_INTERFACE_SIMPLE_VIRTUAL' or t == 'MAXON_INTERFACE_SIMPLE_VIRTUAL_DERIVED':
                            cls.interface = Class.SIMPLE_VIRTUAL
                            self.lex.consume('(')
                            self.lex.consume(name)
                            self.lex.consume(',')
                            refKind = self.lex.getIdent()
                            self.lex.consume(')')
                            cls.derived = t == 'MAXON_INTERFACE_SIMPLE_VIRTUAL_DERIVED'
                            cls.setRefKind(refKind)
                        elif t == 'MAXON_INTERFACE_SINGLE_IMPLEMENTATION':
                            if cls.interface != Class.VIRTUAL:
                                self.errors.append(t.pos, 'MAXON_INTERFACE_SINGLE_IMPLEMENTATION can only be used within a virtual interface class after the interface macro.')
                            cls.singleImpl = True
                        elif t == 'MAXON_GENERIC':
                            if not cls.interface:
                                self.errors.append(t.pos, 'MAXON_GENERIC can only be used for interfaces.')
                            if not generic:
                                generic = Template()
                            self.lex.consume('(')
                            tp, t = self.parseSingleTemplateParam(True)
                            generic.params.append(tp)
                            t.expect(')')
                            self.lex.consume(';')
                            if cls.refClass and cls.refClass.startswith('Generic'):
                                cls.refClass = cls.refClass[7:]
                        elif t == 'MAXON_REFERENCE_SHARED':
                            lex.consume('(')
                            cls.sharedWrapper = lex.getIdent()
                            lex.consume(')')
                            if not cls.interface:
                                self.errors.append(t.pos, 'MAXON_REFERENCE_SHARED can only be used within an interface class after the interface macro.')
                            elif cls.refKind != Class.COW:
                                self.errors.append(t.pos, 'MAXON_REFERENCE_SHARED can only be used for interfaces with copy-on-write references.')
                        else:
                            doclist = [d for d in self.doclist]
                            t = self.tryParseTemplateDeclaration(t)
                            friend = None
                            if t == 'friend':
                                friend = t
                                t = self.lex.getNoEof(cls)
                            template = self.template
                            decl = self.tryParseClass(t, cls, access, friend) or self.tryParseMethod(t, doclist, cls, access) or self.tryParseObservable(t, cls, access) \
                                or self.tryParseClassDeclaration(t, cls, access)
                            if decl and decl is not True:
                                self.checkIdentifier(decl)
                                decl.friend = friend
                                decl.template = template
                                if doclist:
                                    decl.doclist = doclist
                                self.lex.parsePostfixDoc(decl)
                                if addToHxxClass:
                                    refClassMembers.append(decl)
                                if isinstance(decl, Function) and cls.component:
                                    if decl.name == 'GetHashCodeImpl':
                                        getHashCode = decl
                                    elif decl.name == 'IsEqual' and isComponentComparison(decl.name, decl.params):
                                        isEqual = decl
                        if resetDoc:
                            self.resetDoc()
                    if getHashCode and not isEqual:
                        self.warnings.append(getHashCode.name.pos, 'This component implements the method GetHashCodeImpl, but not IsEqual.')
                    elif isEqual and not getHashCode:
                        self.warnings.append(isEqual.name.pos, 'This component implements the method IsEqual, but not GetHashCodeImpl.')
                    if cls.interface:
                        cls.generic = generic
                        if cls.interface != Class.VIRTUAL:
                            if cls.baseInterfaces:
                                self.errors.append(name.pos, 'MAXON_INTERFACE_BASES can only be specified for virtual interfaces.')
                            if cls.derived:
                                if not cls.bases:
                                    self.errors.append(name.pos, 'You have to specify the base interface for the derived interface ' + cls.qname())
                        elif not cls.baseInterfaces:
                            if cls.qname() == 'maxon.ObjectInterface':
                                cls.baseInterfaces = []
                            else:
                                self.errors.append(name.pos, 'You have to specify MAXON_INTERFACE_BASES for the virtual interface ' + cls.qname())
                        if cls.refKind and cls.parseAnnotation('refclass', True) is True:
                            # create the reference class
                            ref = owner.find(Class, cls.refClass)
                            if ref and ref.forward:
                                owner.children.remove(ref)
                                if cls.generic:
                                    cls.refClassForwardDeclared = True
                            ref = Class(cls.refClass, cls.template, owner, cls.access, False)
                            ref.artificial = Declaration.ARTIFICIAL_REFCLASS
                            ref.source = cls
                            if cls.baseInterfaces:
                                for b, g in cls.baseInterfaces:
                                    cls.bases.append((b, 'public', ''))
                                    ref.bases.append((b + '::ReferenceClassHelper::type', 'public', ''))
                            for decl in refClassMembers:
                                decl.owner = ref
                                cls.children.remove(decl)
                                ref.children.append(decl)
                            # ref.bases.append((t, access))
                            for decl in cls.children:
                                if isinstance(decl, Function) and (decl.kind == 'MAXON_METHOD' or decl.kind == 'MAXON_FUNCTION') and decl.includeInRefClass():
                                    fn = copy.copy(decl)
                                    fn.owner = ref
                                    ref.children.append(fn)
                self.checkAmbiguousCalls(cls)
                return cls
            self.lex.reject()

    # parses a directive or processor macro at namespace level, does nothing if t is no such entity
    def tryParseNamespaceDeclaration(self, t, owner):
        if t.type == Token.INCLUDE:
            h = t[8:].strip()
            if not ((h[0] == '"' and h[-1] == '"') or (h[0] == '<' and h[-1] == '>')):
                t.pos.raiseError('Malformed #include path.')
            return Include(h[1:-1], h[0], owner)
        elif t == 'MAXON_DATATYPE' or t == 'MAXON_DATATYPE_SCALAR' or t == 'MAXON_DATATYPE_BITWIDTH_DEPENDENT':
            self.lex.consume('(')
            type = self.lex.getIdent()
            self.lex.consume(',')
            id = self.lex.getString()
            self.lex.consume(')')
            t = 'MAXON_DATATYPE'
            decl = Declaration(t, type, owner, 'public')
            decl.id = id
            return decl
        elif t == 'MAXON_INTERNED_ID':
            self.lex.consume('(')
            id = self.lex.getString()
            self.lex.consume(',')
            name = self.lex.getIdent()
            self.lex.consume(')')
            decl = CppDeclaration(t, name, owner, 'public')
            decl.id = id
            return decl
        elif t == 'MAXON_RESOURCE_DATABASE_SCOPE':
            self.lex.consume('(')
            id = self.lex.getString()
            self.lex.consume(')')
            decl = CppDeclaration(t, t, owner, 'public')
            decl.id = id
            return decl
        elif t == 'MAXON_ATTRIBUTE':
            start = self.lex.consume('(')
            self.parseUntil(owner, None, False, ',', False, -1)
            name = self.lex.getIdent()
            self.lex.consume(',')
            id = self.lex.next()            
            self.parseUntil(owner, start, False, ')', False, -1)
            decl = Attribute(t, name, owner, 'public')
            if id.type == Token.STRING and id[0] == '"':
                decl.id = id
            ns = owner
            while ns and ns.owner and ns.name[0].isupper():
                ns.containsResourceId = True
                ns = ns.owner
            self.lex.consume(';')
            return decl
        elif t == 'MAXON_INTERFACE_INSTANTIATION':
            start = self.lex.consume('(')
            inst, dummy = self.parseUntil(owner, None, True, ',', False, -1)
            instId = self.lex.getString()
            self.lex.consume(')') 
            self.lex.consume(';')
            i = inst.find('<')
            if i <= 0:
                self.errors.append(t.pos, 'You have to specify the template instantiation in the form Interface<Arg>.')
                return None
            clsName = inst[:i]
            scope = self.summary.lookup(owner.qname('.'), True)
            if not scope:
                self.errors.append(t.pos, 'Couldn\'t find the current namespace in summary information.')
                return None
            cls = scope.lookup(clsName)
            if not cls:
                self.errors.append(t.pos, 'Couldn\'t find the class ' + clsName + ' in summary information.')
                return None
            if cls.interface != Class.VIRTUAL or not cls.template:
                self.errors.append(t.pos, clsName + ' has to be a virtual interface template.')
                return None
            decl = InterfaceInstantiation(t, cls, inst, instId, owner)
            return decl
        else:
            return self.tryParseNamespaceOrClassDeclaration(t, owner, 'public')

    def tryParseNamespaceMember(self, t, namespace):
        result = None
        resetDoc = True
        if t.type == Token.HXX1_INCLUDE:
            namespace.root.hxx1 = namespace
        elif t.type == Token.HXX2_INCLUDE:
            namespace.root.hxx2 = namespace
        elif t.type == Token.ANNOTATION:
            self.parseAnnotation()
            resetDoc = False
        elif t.type == Token.PREFIX_DOC:
            self.doclist.append(t)
            resetDoc = False
        elif t == '@end' or ((t != '[') and self.handleBlock(namespace, t, False, True, -1)):
            pass
        elif t == 'MAXON_PREPROCESSOR_CONDITION':
            t = self.lex.consume('(')
            cond, t = self.parseUntil(namespace, t, False, ')', True, -1)
            namespace.root.preprocessorConditions.append(cond)
        elif t.type == Token.DIRECTIVE or t.type == Token.DOC_DIRECTIVE:
            if t.startswith('#if'):
                self.conditionalDirectiveNesting += 1
                self.conditionalDirectiveFirst = True
                namespace.maxIndentation += 2
                ts = t.split()
                # We want to detect if we are within #if(n)def USE_API_MAXON
                if ts == ['#ifdef', 'USE_API_MAXON']:
                    self.useApiMaxonNesting = self.conditionalDirectiveNesting
                    self.useApiMaxon = True
                elif ts == ['#ifndef', 'USE_API_MAXON']:
                    self.useApiMaxonNesting = self.conditionalDirectiveNesting
                    self.useApiMaxon = False
            elif t == '#else' or t == '#elif':
                self.conditionalDirectiveFirst = False
            elif t == '#endif':
                if self.conditionalDirectiveNesting == self.useApiMaxonNesting:
                    self.useApiMaxonNesting = -1
                self.conditionalDirectiveNesting -= 1
                namespace.maxIndentation -= 2
            result = Directive(t, namespace)
            resetDoc = False
        else:
            doclist = [d for d in self.doclist]
            declStart = t
            t = self.tryParseTemplateDeclaration(t)
            template = self.template
            if t == 'extern' and self.lex.next() == 'template':
                t = self.lex.get(namespace)
            if t == 'template' and self.lex.next() in ['class', 'struct']:
                t = self.lex.get(namespace)
            result = self.tryParseNamespace(t, namespace) or self.tryParseClass(t, namespace, 'public', None) or self.tryParseNamespaceDeclaration(t, namespace)
            if result:
                if result is not True:
                    self.checkIdentifier(result)
                    if doclist:
                        result.doclist = doclist
                    result.template = template
                    self.lex.parsePostfixDoc(result)
                    if self.useApiMaxonNesting >= 0 and self.useApiMaxon != self.conditionalDirectiveFirst:
                        # We have found a declaration which exists only when USE_API_MAXON is not defined. Ignore this declaration.
                        if not isinstance(result, Namespace) and result.owner and result in result.owner.children:
                            result.owner.children.remove(result)
                if not isinstance(result, Define) and self.args.stylecheck and self.args.stylecheckOptions.get('indentation', True):
                    lw = self.lex.leadingWhitespaceOfLine(declStart)
                    i = indentLen(lw)
                    if lw is None or i < namespace.minIndentation or i > namespace.maxIndentation:
                        self.styleerrors.append(declStart.pos, 'Wrong indentation of namespace member.')
            elif self.args.stylecheck and self.args.stylecheckOptions.get('indentation', True):
                lw = self.lex.leadingWhitespaceOfLine(declStart)
                i = indentLen(lw)
                if lw is not None and (i < namespace.minIndentation or ((namespace.firstMember or t in varOrFunctionPrefixes) and i > namespace.maxIndentation)):
                    self.styleerrors.append(declStart.pos, 'Wrong indentation of namespace member.')

        if resetDoc:
            self.resetDoc()
        namespace.firstMember = False
        return result

    # parses a namespace declaration if t is 'namespace' followed by identifier and {, otherwise does nothing
    def tryParseNamespace(self, t, owner):
        if t == 'namespace' or t == 'RESOURCE' or t == 'RESOURCEi':
            self.lex.lookahead()
            anonymous = False
            if t != 'namespace':
                self.lex.consume('(')
                name = self.lex.get(owner)
                self.lex.consume(')')
                if t == "RESOURCE":
                    o = owner.find(Namespace, "maxon")
                    if not o:
                        o = Namespace("maxon", owner)
                    owner = o
            else:
                anonymous = self.lex.next() == '{'
                name = self.lex.get(owner) if not anonymous else Token('anonymous#', Token.IDENT, t.pos)
            if name.type == Token.IDENT:
                next = self.lex.get(owner)
                if next in ['{', '::']:
                    # namespace declaration found
                    self.lex.accept()
                    self.resetDoc()
                    while True:
                        namespace = owner.find(Namespace, name)
                        # if namespace already exists, extend this instance by further child declarations
                        if not namespace:
                            namespace = Namespace(name, owner, anonymous)
                        namespace.minIndentation = indentLen(self.lex.leadingWhitespaceOfLine(t))
                        if name[0].isupper():
                            namespace.minIndentation += 2
                        namespace.maxIndentation = namespace.minIndentation
                        namespace.firstMember = True
                        if next == '{':
                            break
                        next.expect('::')
                        # C++17 nested namespace definition
                        owner = namespace
                        name = self.lex.getIdent()
                        next = self.lex.getNoEof(owner)
                    while True:
                        t = self.lex.getNoEof(owner)
                        # check for relevant tokens at namespace level
                        if t == '}':
                            break
                        else:
                            self.tryParseNamespaceMember(t, namespace)
                    return namespace
            self.lex.reject()

    # returns a triple (string, bool, bool):
    # - first element is an error/warning message
    # - second element a bool value which is True if the message contains errors
    # - third element is True if an exception occurred so that the parsed data may be inconsistent and shouldn't be processed afterwards
    @staticmethod
    def parseFile(relFile, resultQueue, args, stampTime, previousFiles, generators, basedir, summary):
        namespace = None
        errors = ErrorList('error')
        warnings = ErrorList('warning')
        file = os.path.join(basedir, relFile)
        exceptionOccurred = False
        if os.stat(file).st_mtime > stampTime or slashPath(relFile) not in previousFiles:
            # source file has been modified
            sys.stdout.write('  Parsing ' + os.path.normpath(file) + '...\n')
            optionsCopy = args.stylecheckOptions.copy()
            try:
                if not args.encoding:
                    f = open(file, 'rU')
                    source = f.read()
                else:
                    enc = args.encoding
                    if enc == 'system':
                        if os.name == 'nt':
                            enc = locale.getpreferredencoding()
                        else:
                            # getpreferredencoding reports us-ascii when called from Xcode because Xcode doesn't set all environment variables 
                            enc = 'utf-8'
                    if sys.version_info.major >= 3:
                        f = open(file, 'rU', encoding=enc)
                        source = f.read()
                    else:
                        import codecs
                        f = codecs.open(file, encoding=enc)
                        source = f.read().encode('utf-8')
                f.close()
                # remove unicode BOMs
                if source.startswith('\xef\xbb\xbf'):
                    source = source[3:]
                if source and ord(source[0]) == 0xfeff:
                    source = source[1:]
                if os.name == 'nt':
                    source = source.replace('\r', '')
                    
                for m, r in defines:
                    source = replaceMacro(source, m, r)

                namespace = Namespace(Token('', Token.IDENT, SourcePosition(str(file), 0, 1, 1)), None)
                namespace.hxx1 = None
                namespace.hxx2 = None
                namespace.root = namespace
                namespace.declarations = list()
                namespace.snippets = {}
                namespace.minIndentation = 0
                namespace.maxIndentation = 0
                namespace.firstMember = True
                otherMember = None
                frameworkRegistration = None

                lex = Lexer(file, source, not args.encoding, namespace)
                parser = Parser()
                parser.lex = lex
                parser.errors = errors
                parser.warnings = warnings
                parser.styleerrors = warnings if args.stylecheckOptions.get('aswarnings', False) else errors
                parser.args = args
                parser.isHeader = file.endswith('.h')
                parser.isObjectiveC = file.endswith('.mm')
                parser.resetDoc()
                parser.conditionalDirectiveNesting = 0
                parser.useApiMaxonNesting = -1
                parser.summary = summary
                lex.errors = parser.errors
                lex.warnings = parser.warnings
                lex.styleerrors = parser.styleerrors
                lex.args = args

                while True:
                    t = lex.get(namespace)
                    # check for relevant tokens at global level
                    if t.type == Token.EOF:
                        break
                    else:
                        mb = parser.tryParseNamespaceMember(t, namespace)
                        if not isinstance(mb, Define):
                            if isinstance(mb, Include) and mb.name.startswith('registration_') and mb.name.endswith('.hxx') and not mb.name[-4] in ['1', '2']:
                                frameworkRegistration = t
                            elif not otherMember:
                                otherMember = t
                if frameworkRegistration and otherMember:
                    parser.errors.append(otherMember.pos, 'A file which includes framework registrations must not contain any additional source.')
                namespace.postprocess(lambda e: docdb.checkDox(e, parser))
                for s in lex.snippets:
                    start, end, pos = lex.snippets.get(s)
                    if end < 0:
                        errors.append(pos, 'Snippet marker given only once.')
            except (KeyboardInterrupt, SystemExit):
                raise
            except UnicodeDecodeError as e:
                errors.append(SourcePosition(file, 0, 1, -1), str(e))
            except IOError as e:
                errors.list.append(str(e))
            except Exception as e:
                traceback.print_exc()
                errors.append(SourcePosition(file, 0, 1, -1), str(e))
                exceptionOccurred = True
            finally:
                args.stylecheckOptions = optionsCopy

        h = os.path.relpath(file, basedir)
        if os.sep == '\\':
            h = h.replace(os.sep, '/')
        for g in generators:
            if not errors.list or g.processesFilesWithError():
                try:
                    resultQueue.put((g.__name__, h, g.process(args, h, namespace)))
                except (KeyboardInterrupt, SystemExit):
                    raise
                except IOError as e:
                    errors.list.append(str(e))
                except Exception as e:
                    traceback.print_exc()
                    errors.append(SourcePosition(file, 0, 1, -1), str(e))
                    exceptionOccurred = True
        return (''.join(x + '\n' for x in errors.list + warnings.list), len(errors.list) > 0, exceptionOccurred)


def loadGenerators(dir, show):
    gendir = os.path.join(dir, 'generators')
    if not os.path.isdir(gendir):
        msg = gendir + ' doesn\'t exist or is not a directory.'
        sys.stderr.write(msg)
        raise Exception(msg)
    sys.path.append(gendir)
    generators = []
    for f in os.listdir(gendir):
        if f.endswith('.py'):
            mod = f[:-3]
            if show:
                sys.stdout.write('Loading generator module ' + mod + ' from ' + os.path.join(gendir, f) + '...\n')
            generators.append(__import__(mod))
    return generators


def sharesModules():
    return os.name != 'nt'


def processHandler(queue, resultQueue, args, stampTime, previousFiles, generators, scriptDir, basedir, summary):
    if not sharesModules():
        generators = loadGenerators(scriptDir, False)
    errorMsg = ''
    exceptions = False
    filesWithErrors = []
    while True:
        try:
            file = queue.get()
        except:
            exceptions = True
            break
        if not file: # we've received a sentinel as end marker, so we're done
            break
        try:
            msg, err, exc = Parser.parseFile(file, resultQueue, args, stampTime, previousFiles, generators, basedir, summary)
            if exc:
                exceptions = True
        except:
            exceptions = True
            break
        if err:
            filesWithErrors.append(file)
        errorMsg += msg
    if errorMsg:
        resultQueue.put(errorMsg)
    if exceptions:
        resultQueue.put(True)
    if filesWithErrors:
        resultQueue.put(filesWithErrors)
    # put a sentinel value
    resultQueue.put(None)


# Simple LIFO queue for the single-threaded case. This avoids threading problems with multiprocessing.Queue.
class SingleThreadResultQueue(object):
    def __init__(self):
        self.list = []

    def put(self, value):
        self.list.append(value)

    def get(self):
        return self.list.pop()


# returns a tuple (string, bool, bool, set, set) with
# - an error/warning message
# - a bool value which is True if the message contains errors
# - a bool value which is True if an exception occurred (in this case the previous bool is also True)
# - a dict of source files found in the directory which have to be processed (relative to the source base directory, like 'maxon/apibase.h').
#   Each file is mapped to True if it has been processed without errors, False otherwise.
# - and a set of source files which haven't been modified since stampTime
def scanFiles(args, stampTime, previousFiles, generators, scriptDir, summary, results):
    sources = dict()
    oldSources = set()
    basedir = os.path.normpath(os.path.join(args.directory, 'source'))
    for root, dirs, files in os.walk(basedir):
        for file in files:
            if (file.endswith('.h') or file.endswith('.cpp') or file.endswith('.mm')) and not file.startswith('.'):
                file = os.path.join(root, file)
                rel = os.path.relpath(file, basedir)
                check = '/' + rel.replace('\\', '/')
                if all(check.lower().find(excl) < 0 for excl in args.excludedPaths):
                    sources[rel] = True
                    if slashPath(rel) in previousFiles and os.stat(file).st_mtime <= stampTime:
                        oldSources.add(file)

    errorMsg = ''
    errors = False
    exceptions = False

    queue = None
    processCount = 0
    if not args.singlethreaded:
        maxProcessCount = 16  # the max process count
        processCount = min(len(sources) - len(oldSources), cpu_count(), maxProcessCount)
        if processCount > 4:
            queue = Queue()

    resultQueue = Queue() if queue else SingleThreadResultQueue()

    for file in sorted(sources):
        if queue:
            queue.put(file)
        else:
            msg, err, exc = Parser.parseFile(file, resultQueue, args, stampTime, previousFiles, generators, basedir, summary)
            if err:
                sources[file] = False
                errors = True
                if exc:
                    exceptions = True
            else:
                for dummy in generators:
                    g, h, r = resultQueue.get()
                    results[g].append((h, r))
            errorMsg += msg

    if queue:
        processes = []
        for x in range(0, processCount):
            p = Process(target=processHandler, args=(queue, resultQueue, args, stampTime, previousFiles, generators if sharesModules() else None, scriptDir, basedir, summary))
            processes.append(p)
            p.start()
            queue.put(None) # for each process we put None as a sentinel into the queue
        while processCount > 0:
            alive = any([p.is_alive() for p in processes])
            try:
                t = resultQueue.get(True, 1)
            except (KeyboardInterrupt, SystemExit):
                raise
            except Exception as e:
                if alive:
                    continue
                else:
                    raise Exception('No processes alive, but didn\'t receive sentinel for each process.')
                    break
            if t == None: # received sentinel from a process
                processCount -= 1
            elif t == True:
                exceptions = True
            elif isinstance(t, str):
                errorMsg += t
            elif isinstance(t, list):
                errors = True
                for f in t:
                    sources[f] = False
            else:
                g, h, r = t
                results[g].append((h, r))

    return (errorMsg, errors, exceptions, sources, oldSources)


# finds the position of the terminating '>::type', takes care of parentheses
def findTraitEnd(line, pos, parts):
    parts[:] = []
    angularNesting = 0
    nesting = 0
    partBegin = pos
    while pos < len(line):
        if line[pos] in ['(', '{', '[']:
            nesting += 1
        elif line[pos] in [')', '}', ']']:
            nesting -= 1
        elif not nesting and line[pos] == '<':
            angularNesting += 1
        elif not nesting and line[pos] == '>':
            angularNesting -= 1
        elif not nesting and not angularNesting and line[pos] == ',':
            parts.append(line[partBegin:pos])
            partBegin = pos + 1
        if angularNesting < 0:
            parts.append(line[partBegin:pos])
            return pos if line[pos:].startswith('>::type') else -1
        pos += 1
    return -1


def filterDoxygen(file):
    import graph
    graphUsable = graph.canBeUsed()
    doxDir = os.path.abspath(file)
    while True:
        parent = os.path.dirname(doxDir)
        if not parent or parent == doxDir:
            graphUsable = False
            break
        doxDir = os.path.join(parent, 'docs')
        if os.path.isdir(doxDir):
            imgDir = os.path.join(doxDir, 'tmpimg')
            break
        doxDir = parent
    f = open(file, 'rU')
    parts = []
    dox = file.endswith('.dox')
    escape = ['@', '\\']
    lines = []
    while True:
        line = f.readline()
        if not line:
            break
        graphFound = False
        i = line.find('@graph')
        if i >= 0:
            s = line[0:i].strip()
            graphFound = not s if dox else s == '///'
        if graphFound:
            prefix = line[:i]
            verbGraph = prefix + '@verbatim\n'
            fill = prefix + '\n'  # we have to fill in lines so that the replacement by @image doesn't remove lines
            graphStr = ''
            while True:
                line = f.readline()
                if not line:
                    break
                if line.strip().startswith('///'):
                    i = line.find('///')
                    line = line[i + 4:]
                if line.find('@endgraph') >= 0:
                    if graphUsable:
                        pos = SourcePosition(file, 0, 0, 0)
                        imgName = graph.parseGraphWriteImage(Token(graphStr, Token.INVALID, pos), ErrorList(''), pos, imgDir)
                        if imgName:
                            line = fill + prefix + '@image html tmpimg/' + imgName + '\n'
                            break
                    line = verbGraph + prefix + '@endverbatim\n'
                    break
                else:
                    verbGraph = verbGraph + prefix + line
                    fill = fill + prefix + '\n'
                    graphStr = graphStr + line
        elif dox:
            # replace `text` by <tt>text</tt>
            start = 0
            while True:
                i = line.find('`', start)
                if i < 0:
                    break
                if i > 0 and line[i - 1] in escape:
                    start = i + 1
                    continue
                j = line.find('`', i + 1)
                if j < 0:
                    break
                var = line[i + 1:j]
                line = line[:i] + '<tt>' + var + '</tt>' + line[j + 1:]
                start = j + 1
        elif line.strip().startswith('///'):
            # replace `var` by @formatParam{var} and a general `text` by <tt>text</tt>
            start = 0
            while True:
                i = line.find('`', start)
                if i < 0:
                    break
                if i > 0 and line[i - 1] in escape:
                    start = i + 1
                    continue
                j = line.find('`', i + 1)
                if j < 0:
                    break
                var = line[i + 1:j]
                if isIdentifier(var):
                    line = line[:i] + '@formatParam{' + var + '}' + line[j + 1:]
                else:
                    line = line[:i] + '<tt>' + var + '</tt>' + line[j + 1:]
                start = j + 1
            i = line.find('@$')
            if i >= 0:
                line = line[:i + 1] + line[i + 2:]
        elif not line.strip().startswith('//'):
            # replace typename ByValueParam<T>::type by const T&
            start = 0
            while True:
                i = line.find('typename ByValueParam<', start)
                if i < 0:
                    break
                j = findTraitEnd(line, i + 22, parts)
                if j >= 0 and len(parts) == 1:
                    line = line[:i] + 'const ' + parts[0] + '&' + line[j + 7:]
                start = i + 1
            # replace typename std::conditional<A, B, C>::type by B (or C) if C (or B) contains DummyType
            start = 0
            while True:
                i = line.find('typename std::conditional<', start)
                if i < 0:
                    break
                j = findTraitEnd(line, i + 26, parts)
                if j >= 0 and len(parts) == 3:
                    if parts[1].find('DummyType') >= 0:
                        line = line[:i] + parts[2] + line[j + 7:]
                    elif parts[2].find('DummyType') >= 0:
                        line = line[:i] + parts[1] + line[j + 7:]
                start = i + 1
            # replace MAXON_INTERFACE_BASES(A, B, C) by public A, public B, public C
            i = line.find('MAXON_INTERFACE_BASES(')
            if i >= 0 and not line.strip().startswith('#'):
                j = line.find(')', i)
                if j >= 0:
                    line = line[:i] + ', '.join(['public ' + x.strip() for x in line[i + 22:j].split(',')]) + line[j + 1:]
        if line.find('@page') < 0 and line.find('@section') < 0 and line.find('@subsection') < 0 and line.find('@subsubsection') < 0:
            # replace _text_ by <em>text</em>
            start = 0
            while True:
                i = line.find('_', start)
                if i < 0:
                    break
                if i > 0 and not line[i - 1].isspace():
                    start = i + 1
                    continue
                j = line.find('_', i + 1)
                if j < 0:
                    break
                var = line[i + 1:j]
                if var.isalnum() and (j + 1 == len(line) or not line[j + 1].isalnum()):
                    line = line[:i] + '<em>' + var + '</em>' + line[j + 1:]
                start = j + 1
        # replace 1. etc. at beginning of line by -#
        s = line.strip()
        if not dox:
            if not s.startswith('///'):
                lines.append(line)
                continue
            s = s[3:].strip()
        if len(s) >= 2 and s[1] == '.' and s[0].isdigit():
            i = line.find('.')
            line = line[:i - 1] + '-#' + line[i + 1:]
        lines.append(line)

    f.close()
    # next pass: replace #param by <tt>param</tt> for function parameters
    if not dox:
        lines.append('')  # ensure that last line doesn't start with ///
        newLines = []
        comment = []
        params = set()
        for line in lines:
            if line.strip().startswith('///'):
                comment.append(line)
                i = line.find('@param')
                if i < 0:
                    i = line.find('@tparam')
                if i >= 0:
                    s = line[i:].split()
                    if len(s) > 1:
                        params.add(s[1])
            else:
                for c in comment:
                    start = 0
                    while True:
                        i = c.find('#', start)
                        if i < 0:
                            break
                        if i > 0 and c[i - 1] in escape:
                            start = i + 1
                            continue
                        j = i + 1
                        while j < len(c) and isIdentifierPart(c[j]):
                            j += 1
                        var = c[i + 1:j]
                        if var in params:
                            c = c[:i] + '<tt>' + var + '</tt>' + c[j:]
                        start = j
                    newLines.append(c)
                comment = []
                params = set()
                newLines.append(line)
        lines = newLines
    for line in lines:
        sys.stdout.write(line)


def findPypy():
    cwd = os.path.dirname(os.path.abspath(__file__))
    while True:
        newCwd = os.path.dirname(cwd)

        osname = platform.system()
        if osname == "Windows":
            pypy = os.path.join(cwd, "_external_libs", "pypy", "pypy.exe")
        elif osname == "Darwin":
            # TODO: (Seb) Disable pypy on OSX since it seems to cause trouble on OSX 10.9.5 (e.g: hanging compilation in xtensions)
            # pypy = os.path.join(cwd, "_external_libs", "pypy", "bin", "pypy")
            return None
        else:
            # Linux and other don't have pypy at the moment
            return None
        if os.path.exists(pypy):
            return pypy

        if newCwd == cwd:
            break
        cwd = newCwd

    return None


def IsPythonDebuggerPresent():
    for frame in inspect.stack():
        # Check if Visual Studio or PyDev is attached
        if frame[1].endswith("pydevd.py") or frame[1].endswith("visualstudio_py_debugger.py"):
            return True
    return False


def recurse(args, dir):
    result = True
    projDefPath = os.path.join(dir, 'project', 'projectdefinition.txt')
    if os.path.isfile(projDefPath):
        b = not args.publicframeworks
        if not b: 
            projDef = open(projDefPath, 'rU')
            keys, m = parseProjectDefinition(projDef)
            projDef.close()
            b = m.get('publicframework', False) 
        if b:
            a = copy.copy(args)
            a.directory = dir
            if not process(a):
                result = False
    else:
        for file in os.listdir(dir):
            file = os.path.join(dir, file)
            if os.path.isdir(file):
                if not recurse(args, file):
                    result = False
    return result


def main():
    locale.setlocale(locale.LC_ALL, '')
    parser = argparse.ArgumentParser(description='Process MAXON API source files and generate language binding code.')
    parser.add_argument('--registeronly', action='store_true', help='Deprecated.')
    parser.add_argument('--singlethreaded', action='store_true', help='Run in single-threaded mode.')
    parser.add_argument('-f', '--force', action='store_true', help='Force processing of all source files, even if they haven\'t changed since last run.')
    parser.add_argument('--option', action='append', help='Options for the source processor such as stylecheck.aswarnings=true')
    parser.add_argument('directories', nargs='+', help='A number of root directories, all subdirectories containing "project/projectdefinition.txt" are processed.')
    parser.add_argument('--doxygen', action='store_true', help='Work as Doxygen filter. In this case a source file has to be specified instead of the directory, and the filtered file goes to stdout.')
    parser.add_argument('--publicframeworks', action='store_true', help='Process only frameworks with publicframework=true in their projectdefinition.txt.')
    parser.add_argument('--generatedroot', action='store', help='Changes the root folder for generated files (may only be used for modules, not for frameworks).')
    args = parser.parse_args()

    if not args.doxygen:
        # Prefer using Pypy if available
        if platform.python_implementation() == "CPython" and not IsPythonDebuggerPresent() and cpu_count() <= 8:
            pypy = findPypy()
            # TODO: (Seb) At the moment Pypy doesn't scale well on machines with more than 8-cores
            if pypy:
                # t = time.time()
                l = [pypy, __file__] + sys.argv[1:]
                exitcode = subprocess.call(l)
                if exitcode == 0:
                    pass
                    # debug not necessary at the moment
                    # print("Executed Prebuild Event in {}ms".format(time.time() - t))
                sys.exit(exitcode)
                return
        else:
            pass

    result = True
    for d in args.directories:
        args.directory = os.path.abspath(d)
        if args.doxygen:
            try:
                filterDoxygen(args.directory)
            except:
                result = False
        else:
            if not recurse(args, args.directory):
                result = False
    return result

def parseSummary(file, root):
    if os.path.isfile(file):
        sf = open(file)
        classes = []
        for line in sf:
            try:
                parts = line.split('\t')
                if len(parts) < 5:
                    sys.stdout.write(str(file) + ' has outdated format\n')
                    break
                intf = parts[0]
                id = parts[1] 
                value = parts[2] 
                bases = parts[3]
                methods = parts[4]
                n = intf.split('.')
                name = n.pop()
                ns = root
                for i in n:
                    child = ns.find(Namespace, i)
                    if not child:
                        child = Namespace(i, ns)
                    ns = child
                cls = Class(name, None, ns, 'public', False)
                cls.id = id
                cls.interface = Class.VIRTUAL
                cls.resolvedBaseInterfaces = []
                for val in parts[5:]:
                    val = val.strip()
                    if val:
                        k, v = val.split('=')
                        cls.__dict__[k] = (v == 'true') or (int(v) if k == 'template' else False)
                for m in methods.split(','):
                    Function('MAXON_METHOD', m, False, 'Generic', cls, 'public')
                classes.append((cls, bases))
            except ValueError:
                pass
        sf.close()
        for cls, bases in classes:
            for base in bases.split(','):
                resolved = cls.owner.lookup(base)
                if isinstance(resolved, Class):
                    cls.resolvedBaseInterfaces.append(resolved)

def pySourceStamp(modulePath):
    if modulePath.endswith('.pyc') and os.path.exists(modulePath[:-1]):
        modulePath = modulePath[:-1]
    return os.stat(modulePath).st_mtime

def slashPath(path):
    return path.replace('\\', '/') if os.name == 'nt' else path

def process(args):
    projDefPath = os.path.join(args.directory, 'project', 'projectdefinition.txt')
    if not os.path.isfile(projDefPath):
        sys.stderr.write('**********\nSource processor:\nNo projectdefinition.txt found at ' + projDefPath + '\n**********\n')
        return False

    optionLines = []
    # read projectdefinition.txt and look for source processor options
    projDef = open(projDefPath, 'rU')
    for line in projDef:
        optionLines.append(line)
    projDef.close()

    # append options from command line
    if args.option:
        for option in args.option:
            optionLines.append(option)

    option = ''
    args.excludedPaths = []
    args.stylecheck = True
    args.stylecheckOptions = {}
    args.stylecheckOptions = {'domains': ''}
    args.splitRegisterCpps = False

    foundGlobalprojectsettings = False
    # check in one of the upper directories where we can find globalprojectsettings
    for x in range(1, 3):
        l = ["..", ] * x
        globalprojectsettings = os.path.join(args.directory, *l)
        globalprojectsettings = os.path.abspath(os.path.join(globalprojectsettings, "config", "globalprojectsettings.txt"))
        # print(globalprojectsettings)
        if os.path.exists(globalprojectsettings):

            foundGlobalprojectsettings = True

            with open(globalprojectsettings, "rb") as fp:
                for line in fp.readlines():
                    if line.lower().strip().decode("ascii") == "splitregistercpps=true":
                        args.splitRegisterCpps = True
            break

		# removed as the SDK projects dont have the txt file
    # if foundGlobalprojectsettings is False:
    #    raise IOError("missing globalprojectsettings.txt")

    projectErrors = ErrorList('error')

    args.publicframework = False
    args.obfuscate = False
    args.maxon = False
    args.projectType = None
    args.frameworks = set()
    args.encoding = None
    args.projectId = None
    args.c4d = False
    args.frameworkRegistration = ''
    args.frameworkRegistrationIncludeReflection = False
    args.moduleRegistration = True
    keys, options = parseProjectDefinition(optionLines)
    projPos = SourcePosition(projDefPath, 0, 1, 0)
    for key in keys:
        option = options[key]
        if key.startswith('stylecheck.'):
            key = key[11:]
            option = parseStylecheckOption(key, option, args, projectErrors, projPos)
            if key == 'level':
                args.stylecheck = option > 0
                if args.stylecheck:
                    if option <= 1:
                        args.stylecheckOptions['no-whitespace'] = False
                        args.stylecheckOptions['consistent-blocks'] = False
                        args.stylecheckOptions['newline-for-substatement'] = False
                        args.stylecheckOptions['explicit'] = False
                    if option <= 2:
                        args.stylecheckOptions['typedef-struct'] = False
                        args.stylecheckOptions['enum-class'] = False
                        args.stylecheckOptions['enum-registration'] = False
                        args.stylecheckOptions['class-for-templateparam'] = False
                        args.stylecheckOptions['void-paramlist'] = False
                        args.stylecheckOptions['max-linecount'] = 100000
                        args.stylecheckOptions['naming'] = False
            elif key != 'aswarnings' and (not isinstance(option, bool) or option):
                args.stylecheck = True
        elif key == 'dontuncrustify':
            for p in option.split(';'):
                p = p.strip()
                if p.startswith('"'):
                    p = p[1:-1]
                args.excludedPaths.append(p.lower())
        elif key == 'c4d':
            if option.lower() == 'true':
                args.c4d = True
                args.stylecheck = False
        elif key == 'type':
            args.projectType = option.lower()
        elif key == 'apis':
            for f in option.split(';'):
                f = f.strip()
                if f:
                    args.frameworks.add(getFrameworkId(args.directory, f))
        elif key == 'stylecheck':
            args.stylecheck = (option.lower() == 'true')
        elif key == 'excludesplitregistercpps':
            args.splitRegisterCpps = (option.lower() == 'false')
        elif key.startswith('stylecheck.'):
            key = key[11:]
        elif key == 'encoding':
            args.encoding = option
        elif key == 'publicframework':
            args.publicframework = option.lower() == 'true'
        elif key == 'maxon':
            args.maxon = option.lower() == 'true'
        elif key == 'obfuscate':
            args.obfuscate = option.lower() == 'true'
        elif key == 'moduleid':
            args.projectId = option
        elif key == 'frameworkregistration':
            args.frameworkRegistration = option
        elif key == 'frameworkregistrationincludereflection':
            args.frameworkRegistrationIncludeReflection = option.lower() == 'true'
        elif key == 'moduleregistration':
            args.moduleRegistration = option.lower() == 'true'

    if not args.projectId:
        args.projectId = os.path.basename(args.directory).replace(' ', '')
        if not args.maxon:
            projectErrors.append(projPos, 'You have to specify the ModuleId in projectdefinition.txt of ' + args.projectId + '.')
        if args.projectId.endswith('.module'):
            args.projectId = args.projectId[:-7]
        args.projectId = ('net.maxon.c4d.' if args.c4d else 'net.maxon.') + args.projectId
    elif not args.maxon and args.projectId.startswith('net.maxon.'):
        projectErrors.append(SourcePosition(projDefPath, 0, 1, 0), 'Illegal module id ' + args.projectId + ': A module id must not be in the net.maxon domain.')

    args.mangledProjectId = args.projectId.replace('.', '_').replace('-', '_')


    args.generated = os.path.join(args.directory, args.generatedroot, os.path.basename(args.directory)) if args.generatedroot else os.path.join(args.directory, 'generated') 

    makeDir(args.generated)

    # Load generator modules from the generators subdirectory.
    #
    # A generator module needs to have three function definitions:
    #
    # def process(args, file, root):
    #         ...
    # This function will be invoked for each parsed source file.
    # The parameter args is set to the command line arguments as parsed by the argparse module.
    # args has an attribute 'directory' which points to the module or framework path (e.g., 'frameworks/core.framework').
    # the parameter file is set to the relative path of the source file in the source directory (e.g., 'maxon/system.h'),
    # and root is a Namespace instance which stands for the global namespace and contains the declarations of the source file as children.
    # If the source file hasn't changed since the last run, it isn't parsed and root will be None.
    #
    # def processesFilesWithError():
    #         ...
    # This function has to return True if the process function shall also be called for files with errors.
    #
    # def done(args, results, sources, msg, err):
    #         ...
    # This function will be invoked once in a final step. The parameter results is a list of all values returned by the process function,
    # sorted by the source file name. The parameter sources contains a dictionary of all source file names found by the source processor in the
    # source directory, mapped to True on success or False otherwise. The names are relative to the source directory such as 'maxon/apibase.h'.
    # The parameter msg is the complete error/warning message produced so far (a string), the parameter err is True if an error has happened so far.
    # The done function has to return the tuple (msg, err) when no additional error occurred during done, otherwise it has to append the error message
    # and return a tuple (extended message, True).

    scriptDir = os.path.dirname(sys.argv[0])
    generators = loadGenerators(scriptDir, True)

    stamp = os.path.join(args.generated, 'sourceprocessor.stamp')
    stampExists = os.path.isfile(stamp)
    previousFiles = set()
    if stampExists:
        stampTime = os.stat(stamp).st_mtime
        # If one of the Python modules or the project definition has been modified since last run, reset stampTime to force a complete run.
        if pySourceStamp(__file__) > stampTime:
            stampTime = 0
        if pySourceStamp(declarations.__file__) > stampTime:
            stampTime = 0
        if pySourceStamp(lexer.__file__) > stampTime:
            stampTime = 0
        if pySourceStamp(docdb.__file__) > stampTime:
            stampTime = 0
        for g in generators:
            if pySourceStamp(g.__file__) > stampTime:
                stampTime = 0
        if pySourceStamp(projDefPath) > stampTime:
            stampTime = 0
        stampFile = open(stamp, 'r')
        while True:
            line = stampFile.readline()
            if not line:
                break
            previousFiles.add(line.strip())
        stampFile.close()
    else:
        stampTime = 0
    if args.force:
        stampTime = 0

    for run in range(0, 2):
        results = {}
        for g in generators:
            results[g.__name__] = []
        summary = Namespace('', None)
        
        for fwDir in usedFrameworks(args.directory, True, set()):
            gen = args.generated if fwDir == args.directory else os.path.join(fwDir, 'generated')
            summaryFile = os.path.join(gen, 'summary', 'framework.summary')
            if stampTime and os.path.isfile(summaryFile) and os.stat(summaryFile).st_mtime > stampTime:
                # reset stampTime when summary information has changed
                stampTime = 0
                sys.stdout.write('Summary information of ' + fwDir + ' changed, therefore processing all sources files.\n')
            # the summary file of the current project will be reported last by usedFrameworks(),
            # so eventually ownSummary will be that file
            ownSummary = summaryFile
            if os.path.isfile(summaryFile):
                parseSummary(summaryFile, summary)
                summaryStampTime = os.stat(summaryFile).st_mtime
                # reset stampTime when summary information has changed
                if summaryStampTime > stampTime:
                    stampTime = 0

        ownSummaryStampTime = os.stat(ownSummary).st_mtime if os.path.isfile(ownSummary) else 0

        sys.stdout.write('Looking for source files in ' + args.directory + '...\n')
        try:
            msg, err, exc, sources, oldSources = scanFiles(args, stampTime, previousFiles, generators, scriptDir, summary, results)
        except KeyboardInterrupt:
            sys.stdout.write('warning: Sourceprocessor has been cancelled.\n')
            return False
    
        if exc:
            return False
    
        # Now call the done function of the generators.
        for g in generators:
            # Sort the results by header name.
            msg, err = g.done(args, [y[1] for y in sorted(results[g.__name__], key=lambda x: x[0])], sources, msg, err)

        if not (run == 0 and os.path.isfile(ownSummary) and os.stat(ownSummary).st_mtime > ownSummaryStampTime):
            break

        # Summary information has changed, redo the whole process once.
        sys.stdout.write('Summary information changed, redoing source file processing.\n')
            
    msgFile = os.path.join(args.generated, 'sourceprocessor.msg')
    if stampTime > 0 and os.path.isfile(msgFile):
        msgf = open(msgFile)
        for line in msgf:
            pos = line.find('(' if os.name == 'nt' else ':')
            if pos >= 0 and line[:pos] in oldSources:
                msg += line
                if line.find(': error:') >= 0:
                    err = True
        msgf.close()

    writeToFile(msgFile, msg)

    if projectErrors.list:
        msg += ''.join(x + '\n' for x in projectErrors.list)
        err = True
    
    if msg:
        sys.stderr.write('**********\nSource processor:\n' + msg + '**********\n')

    # Write files which have been processed successfully to the stamp file.
    # They needn't be processed again (unless something is modified).
    writeToFile(stamp, '\n'.join([slashPath(s) for s in sources if sources[s]]) + '\n')
    os.utime(stamp, None)

    return not err


if __name__ == '__main__':
    if not main():
        exit(1)
