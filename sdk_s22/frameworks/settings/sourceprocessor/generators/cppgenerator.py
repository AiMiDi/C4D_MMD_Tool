'''
MAXON API C++ Generator
This generates the necessary hxx files.
'''

import os
import re
import copy
import hashlib
from declarations import *
from lexer import *


def intToHex32(x):
    x = hex(x).replace('L', '')
    if len(x) > 10:
        x = '0x' + x[-8:]
    return x


def intToHex64(x):
    x = hex(x).replace('L', '')
    if len(x) > 18:
        x = '0x' + x[-16:]
    return x


def hashCode(s):
    return 'maxon::UInt(' + intToHex64(intHashCode(s)) + 'LL)'


def idHashCode(s):
    return 'PRIVATE_MAXON_ID_HASHCODE(' + hashCode(s) + ', maxon::UInt(' + str(len(s)) + '))'


def doxygenSkip(s):
    # ideally, we'd use the following, but somehow @cond doesn't nest properly in Doxygen 1.8.5 (although the manual says it does)
    #    return "\n/// \@cond IGNORE\n\n" . shift() . "\n/// \@endcond\n\n";
    return '\n#ifndef DOXYGEN\n\n' + s + '\n#endif\n\n'

def add_gcc_pragma(s):
    ''' this is to add pragmas for GCC to disable warnings in auto-generated code
    '''
    return '#if defined MAXON_COMPILER_GCC\n\t#pragma GCC diagnostic push\n\t#if MAXON_COMPILER_GCC >= 600\n\t\t#pragma GCC diagnostic ignored "-Wmisleading-indentation"\n\t#endif\n#endif\n\n' + s + '\n#ifdef MAXON_COMPILER_GCC\n\t#pragma GCC diagnostic pop\n#endif\n'

def boolStr(v):
    return 'true' if v else 'false'

def unqualified(name):
    p = name.rfind('::')
    return name if p < 0 else name[p+2:]

def addDirective(code, scope, writers):
    code += '\n'
    while scope and not isinstance(scope, Namespace):
        scope = scope.owner
    for w in writers:
        w.beginDirective()
        if scope:
            w << scope
        w.code += code
        w.endDirective()

def getInOutBits(function):
    paramDirs = {}
    if function.doc:
        paramPos = 0
        while True:
            paramPos = function.doc.find("@param", paramPos)
            if paramPos < 0:
                break
            paramPos += 6
            s = function.doc[paramPos:].lstrip()
            if s.startswith('['):
                pos = s.find(']')
                if pos > 0:
                    dir = s[1:pos]
                    s = s[pos+1:].lstrip()
                    pos = 0
                    while pos < len(s) and not s[pos].isspace():
                        pos += 1
                    paramDirs[s[:pos]] = dir
    inOut = 0
    bit = 1
    for p in function.params:
        dir = paramDirs.get(p.name)
        if dir:
            if dir.find('in') >= 0:
                inOut += bit
            if dir.find('out') >= 0:
                inOut += 2*bit
        bit *= 4
    return inOut

def maxonComma(str):
    return str.replace(',', ' MAXON_COMMA')

def getInstantiationSuffix(iname):
    return ''.join(['_' if ' \t,<>:\'"'.find(x) >= 0 else x for x in iname])

def addTypename(str):
    return str if str.startswith('typename') else 'typename ' + str

def substitute(str, map):
    lex = Lexer('str', str)
    lex.reportWhitespace = True
    memberAccess = False
    s = ''
    substituted = False
    while True:
        c = lex.get()
        if not c:
            break
        if c in ['.', '::', '->']:
            s += c
            memberAccess = True
        elif memberAccess:
            s += c
            memberAccess = False
        else:
            x = map.get(c)
            if x:
                s += x
                substituted = True
            else:
                s +=  c
    return (s, substituted)


def isParameterPack(tp):
    d = tp.default
    if not d:
        return False
    if d.startswith('maxon::'):
        d = d[7:]
    return d == 'ParameterPack<>' or d == 'NamedTuple<>'

def templateParamToStrSubstPack(p, nodef, onlyNames, pack):
    if isParameterPack(p):
        return p.default[:-2] + '<' + p.name + '...>' if pack else p.name + '...' if onlyNames else 'typename... ' + p.name
    return p.toStr(nodef, onlyNames)
        
def templateToStrSubstPack(t, nodef, onlyNames, pack):
    return ('' if onlyNames else 'template ') + '<' + ', '.join(templateParamToStrSubstPack(x, nodef, onlyNames, pack) for x in t.params) + '>'

def templateParamToStrMap(x):
    if not isinstance(x, TypeTemplateParam):
        return x.toStr(True, True)
    return 'typename MAP<' + x.name + '>::type' + ('...' if x.pack or isParameterPack(x) else ''); 

def hashString(s):
    return hashlib.md5(s.encode('utf-8')).hexdigest()

class Generator(object):
    def __init__(self, args, header, cpp, root):
        self.args = args
        self.framework = args.directory
        self.header = header
        self.cpp = cpp
        self.decls = CodeWriter(header, root.hxx1 or root)
        self.defs = CodeWriter(header, root.hxx2 or root)
        self.regs = CodeWriter(header, root)
        self.reflection = CodeWriter(header, root)
        self.defaults = CodeWriter(header, root)
        self.decorators = CodeWriter(header, root)
        self.instantiations = ''
        self.errors = ErrorList('error')

    def writeInterfaceUse(self, cls, iname):
        if iname:
            suffix = getInstantiationSuffix(iname)
        else:
            suffix = ''
            iname = cls.name
        qname = cls.qname()
        underscoreClass = qname.replace('.', '_')
        if cls.interface != Class.SIMPLE_VIRTUAL:
            self.writeUse('s_ui_' + underscoreClass + suffix, iname + '::_interface.GetReference(), &maxon::g_translationUnit, "' + self.header + '"', False)
        if cls.interface == Class.VIRTUAL:
            if cls.singleImpl:
                self.writeUse('s_ui1_' + underscoreClass + suffix, iname + '::_nonvirtualMTable.GetReference(), &maxon::g_translationUnit, "' + self.header + '"', False)
            if cls.hasStaticMethods:
                self.writeUse('s_usi_' + underscoreClass + suffix, iname + '::_staticInterface.GetReference(), &maxon::g_translationUnit, "' + self.header + '"', False)

    def writeInterfaceDefinition(self, cls, iname):
        if iname:
            suffix = getInstantiationSuffix(iname)
        else:
            suffix = ''
            iname = cls.name
        qname = cls.qname()
        mainName = cls.qname(None, '.', True)
        notMain = qname != mainName
        self.reflection << '#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES'
        self.reflection << 'static maxon::InterfaceDefinition s_' + cls.name + suffix + '(' + iname + '::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::' \
            + ('NONE' if notMain else 'MAIN_DEFINITION') + ');'
        if notMain:
            templ = iname.find('<') 
            self.reflection << 'static maxon::EntityUse s_umi_' + cls.name + suffix + '(' + cls.qname(None, '::', True) + (iname[templ:] if templ >= 0 else '') + '::_interface.GetReference(), &maxon::g_translationUnit, nullptr, false);'
        self.reflection << '#endif'

    def writeInterfaceReflection(self, cls, iname, interfaceKind, suffix):
        self.reflection << '#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION' + ('' if interfaceKind == Class.VIRTUAL else '_NONVIRTUAL')
        if iname:
            isuffix = getInstantiationSuffix(iname)
        else:
            isuffix = ''
            iname = cls.name
        s = 'static maxon::reflection::ContainerInfo g_reflection_' + cls.name + isuffix + suffix + '('
        if interfaceKind == Class.VIRTUAL:
            s += 'nullptr, &' + iname + '::ProxyComponent::_descriptor'
        else:
            s += cls.id + ', nullptr'
        self.reflection << s + ', &RegisterReflection_' + iname + suffix + ', &PRIVATE_MAXON_MODULE);'
        self.reflection << '#endif'

    def writeUse(self, useName, useParams, weakDep):
        self.defs << '#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)'
        self.defs << '#ifdef MAXON_USE_REGISTER_FUNCTION'
        self.defs << 'MAXON_STATIC_STORAGE(maxon::EntityUse, ' + useName + '); \\'
        self.defs << 'MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_' + useName + '() { new (' + useName + ') maxon::EntityUse(' + useParams + ', ' + boolStr(weakDep) + '); }'
        self.defs << '#else // !MAXON_USE_REGISTER_FUNCTION'
        self.defs << 'static maxon::EntityUse ' + useName + '(' + useParams + ', ' + boolStr(weakDep) + ');'
        self.defs << '#endif // MAXON_USE_REGISTER_FUNCTION'
        self.defs << '#endif'

    def addObject(self, name, qname, id, ns, extra=0):
        self.regs << ns << 'PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(' + name + ', ' + qname[:extra-len(name)] + ', ' + id + ');'

    def substituteTemplateArgs(self, str):
        for param in self.templateArgs:
            s = ''
            p = 0
            while True:
                q = str.find(param, p)
                if q >= 0:
                    s += str[p:q]
                    if (q == 0 or not isIdentChar(str[q-1])) and (q + len(param) == len(str) or not isIdentChar(str[q + len(param)])):
                        s += self.templateArgs[param]
                        p = q + len(param)
                    else:
                        s += str[q]
                        p = q + 1
                else:
                    s += str[p:]
                    break
            str = s
        return str

    def processMethod(self, method, cls, freeMethod):
        methodParams = [copy.copy(p) for p in method.params]
        for p in methodParams:
            p.type = self.substituteTemplateArgs(p.type)
        returnsThis = method.parseAnnotation('returnsThis', False)
        op = operatorId(method.name, method.name.pos if isinstance(method.name, Token) else None)
        if op:
            xname = op
            if op.endswith('Assign'):
                returnsThis = True
        else:
            xname = method.name

        methodRetType = self.substituteTemplateArgs(method.retType)

        if not method.static:
            self.hasNonstaticMethods = True
        if method.name in ['IsPopulated', 'IsEmpty']:
            self.hasPopulatedOrEmptyFunction = True

        methodId = methodRetType + (' ' + cls.name if cls.derived else '') + '#' + ','.join([p.type for p in methodParams])
        if method.static:
            methodId += '#'
        elif method.const:
            methodId += ':'
        if self.args.obfuscate or cls.parseAnnotation('obfuscate', False):
            methodId = hashString(cls.name + '@' + xname + '@' + methodId)
        else:
            methodId = xname + '@' + intToHex64(intHashCode(methodId))[2:]
        s = method.getAnnotation('methodId', None)
        if isinstance(s, str):
            prefix = '"' + methodId + '"->"'
            if s.startswith(prefix):
                methodId = s[len(prefix):-1]
            else:
                self.errors.append(s.pos, 'methodId annotation has to be of the form "' + methodId + '"->"id to use".')               
        functionArgs = ', '.join([p.forward() for p in methodParams])
        implFunctionArgs = functionArgs
        refFunctionArgs = functionArgs
        if methodParams:
            if not method.static:
                functionArgs = ', ' + functionArgs
            if cls.interface != Class.VIRTUAL and len(methodParams) == 2 and method.name == 'Alloc':
                s = methodParams[0].name + ', '
                if methodParams[1].type == 'const ' + cls.name + '&':
                    implFunctionArgs = s + '((const C&) ' + methodParams[1].name + ')'
                elif methodParams[1].type == cls.name + '&&':
                    implFunctionArgs = s + '((C&) ' + methodParams[1].name + ')'

        const = 'const ' if method.const else ''
        params = ', '.join([p.toStr() for p in methodParams])
        paramsNoDefaults = ', '.join([p.toStr(True) for p in methodParams])
        paramsNoDefaultsWithComma = ', ' + paramsNoDefaults if paramsNoDefaults else ''
        if method.static:
            xparams = paramsNoDefaults
        elif cls.interface == Class.VIRTUAL:
            xparams = const + 'maxon::GenericComponent* this_' + paramsNoDefaultsWithComma
        else:
            xparams = const + cls.name + '* this_' + paramsNoDefaultsWithComma

        attr = ''
        deprecated = method.getAnnotation('deprecated', False)
        if deprecated == True:
            attr += '[[deprecated]] '
        elif deprecated:
            attr += '[[deprecated(' + deprecated + ')]] '

        if method.kind == 'MAXON_METHOD':
            if not method.static:
                self.nonstaticMethods.add(method.name)
            fnCount = self.functionNameCount.get(method.name, 0)
            self.functionNameCount[method.name] = fnCount + 1
            if fnCount > 0:
                cname = xname + '_' + str(fnCount)
            else:
                cname = xname
            cname = cls.name + '_' + cname
            inheritedMethod = (cls.interface == Class.NONVIRTUAL or cls.interface == Class.VIRTUAL) and method.owner != cls
            s = 'template <> ' if inheritedMethod and method.owner.template else ''
            s += self.templatePrefix + attr + 'MAXON_ATTRIBUTE_FORCE_INLINE auto '
            if inheritedMethod:
                s += method.owner.name
                if method.owner.template:
                    s += '<' + ','.join([self.templateArgs[p.name] for p in method.owner.template.params]) + '>'
            else:
                s += self.tclass
            s += '::' + method.name + '(' + paramsNoDefaults + ') ' + const + '-> ' + methodRetType
            if inheritedMethod and method.owner.template:
                self.decls << s + ';' # need forward declaration of template specialization, otherwise specialization happens after first instantiation
            self.functions << s << '{'
            fname = cname
            s = ''
            if cls.interface == Class.VIRTUAL:
                if method.static:
                    s += 'return Hxx2::StaticMTable::_instance.'
                else:
                    s = 'const ' + cls.name + '::MTable& mt_ = '
                    if cls.singleImpl:
                        s += 'MTable::NVMTable::_instance.mtable'
                    elif inheritedMethod:
                        s += 'PRIVATE_MAXON_VTABLE(' + cls.name + ', ((ObjectSuper*) this))'
                    else:
                        s += 'PRIVATE_MAXON_VTABLE(' + cls.name + ', this)'
                    s += '; return mt_.'
            elif cls.interface == Class.NONVIRTUAL:
                if freeMethod and cls.derived:
                    fname = cls.bases[0][0] + '_Free'
                    s += 'return BaseInterface::MTable::_instance.'
                elif inheritedMethod:
                    s += 'return ' + cls.name + '::MTable::_instance.'
                else:
                    s += 'return MTable::_instance.'
            else:
                if freeMethod:
                    s += 'if (!object)\n\treturn;\nreturn ((' + cls.name + '::MTable*) object->_vtable)->'
                else:
                    s += 'return ((' + cls.name + '::MTable*) this->_vtable)->'
            s += '_' + fname + '('
            if not method.static:
                if cls.interface == Class.VIRTUAL:
                    s += '(' + const + 'maxon::GenericComponent*) '
                if inheritedMethod:
                    s += 'static_cast<' + const + cls.name + '*>(this)'
                else:
                    s += 'this'
                if cls.interface == Class.VIRTUAL:
                    s += ' + mt_._' + cname + '_Offset'
            s += functionArgs + ');'
            self.functions << s << '}'
            paramNames = '"' + ''.join([p.name + '\\0' for p in methodParams]) + '"'
            inOut = getInOutBits(method)
            if cls.interface == Class.VIRTUAL:
                if method.static:
                    self.staticReflectionFunctions << 'maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(' + self.tclass + '::Hxx2::StaticMTable::_instance._' + fname + ')>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, ' + paramNames + ', ' + str(inOut) + 'LL, nullptr),'
                else:
                    self.reflectionFunctions << 'MAXON_GET_VIRTUAL_METHOD_INFO(' + ('CONST_INSTANCE_FUNCTION, ' if method.const else 'INSTANCE_FUNCTION, ') + paramNames + ', ' + str(inOut) + 'LL, ' + maxonComma(self.tclass) + ', _' + fname + '),'
            elif cls.interface == Class.NONVIRTUAL and not (freeMethod and cls.derived):
                self.reflectionFunctions << 'maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(' + cls.name + '::MTable::_instance._' + fname + ')>::type>(nullptr, maxon::reflection::Member::KIND::' \
                    + ('CONST_INSTANCE_FUNCTION, ' if method.const else 'FUNCTION, ' if method.static else 'INSTANCE_FUNCTION, ') + paramNames + ', ' + str(inOut) + 'LL, nullptr),'

        subst = dict()
        rtp = method.getAnnotation('refclassParameter', None)
        if rtp:
            subst[rtp] = 'maxon::details::GetReferenceClass<S>'
        itp = method.getAnnotation('interfaceParameter', None)
        if itp:
            subst[itp] = 'maxon::details::GetPrivateReferencedType<S>'
        stp = method.getAnnotation('superParameter', None)
        if stp:
            subst[stp] = 'S'
        if cls.generic:
            for p in cls.generic.params:
                subst[p.name] = p.name + '_'

        onlyCow = not method.static and ((method.retType.endswith('&') and not method.retType.startswith('const')) # non-const reference return types can only be handled by COW functions
                                         or (not method.const and method.access != 'public')) # protected methods are only needed for self and super reference classes

        defaultReturn = method.getAnnotation('default', None)
        if defaultReturn:
            pass
        elif methodRetType == 'void':
            defaultReturn = 'maxon::PrivateLogNullptrError()'
        elif isBoolType(methodRetType):
            defaultReturn = 'maxon::PrivateLogNullptrError(false)'
        elif isNumericType(methodRetType):
            defaultReturn = '0'
        elif methodRetType.endswith('*'):
            defaultReturn = 'this' if returnsThis else 'nullptr'
        elif method.observable:
            defaultReturn = methodRetType + '::NullValue()'
        elif method.result:
            defaultReturn = 'maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::@)'
        elif returnsThis:
            defaultReturn = '*this'
        elif self.templatePrefix or method.template or subst or isGenericType(methodRetType):
            defaultReturn = 'maxon::PrivateNullReturnValue<' + methodRetType + '>(maxon::NULL_RETURN_REASON::@, OVERLOAD_MAX_RANK)'
        else:
            defaultReturn = 'maxon::PrivateIncompleteNullReturnValue<' + methodRetType + '>(maxon::NULL_RETURN_REASON::@, OVERLOAD_MAX_RANK)'
            if not onlyCow:
                self.nullRets.add(methodRetType)
        if not (freeMethod and cls.derived) and (method.kind == 'MAXON_METHOD'):
            if cls.interface == Class.VIRTUAL:
                if method.static:
                    self.staticInit << 'tbl->_' + cname + ' = &IMPL::_' + cname + ';'
                else:
                    isImplemented = 'PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ' + cls.name + ', ' + xname + ')'
                    self.xinit << 'if (' + isImplemented + ')' << '{'
                    self.xinit << 'auto ptr = &std::conditional<' + isImplemented  + ', W, MTable>::type::_' + cname + ';'
                    self.xinit << '_' + cname + ' = reinterpret_cast<const decltype(_' + cname + ')&>(ptr);'
                    self.xinit << '_' + cname + '_Offset = offset;' << '}'
            else:
                self.init << '_' + cname + ' = &IMPL::_' + cname + ';'
            (self.staticIds if cls.interface == Class.VIRTUAL and method.static else self.ids) << '"' + methodId + '\\0" // ' + str(method.retType) + ' ' + xname + '(' + paramsNoDefaults + ')' + (' const' if method.const else '')
            if cls.interface == Class.NONVIRTUAL or (cls.interface == Class.VIRTUAL and method.static):
                unresolvedImpl = 'tbl->_' + cname + ' = &Hxx2::Wrapper<' + ('maxon::StaticHelper<Hxx2::Unresolved>' if cls.interface == Class.VIRTUAL else 'Hxx2::Unresolved') + '>::_' + cname + ';'
                self.unresolvedInit << '#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)'
                if not (methodRetType == 'void' or isBoolType(methodRetType) or isNumericType(methodRetType) or methodRetType.endswith('*')):
                    self.unresolvedInit << 'if (maxon::details::NullReturnType<' + methodRetType + '>::value == maxon::NULL_RETURN_TYPE::OTHER) ' + unresolvedImpl
                self.unresolvedInit << '#else' << unresolvedImpl << '#endif'
                self.unresolvedRetType << ('maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,' if freeMethod else 'maxon::details::NullReturnType<' + methodRetType + '>::value,')
            if cls.interface == Class.VIRTUAL and method.static:
                self.staticPointers << methodRetType + ' (*_' + cname + ') (' + xparams + ');'
            else:
                self.pointers << methodRetType + ' (*_' + cname + ') (' + xparams + ');'
                if cls.interface == Class.VIRTUAL:
                    self.pointers << 'maxon::Int _' + cname + '_Offset;'
            s = 'static ' + methodRetType + ' _' + cname + '(' + xparams + ') { return '
            if cls.interface == Class.VIRTUAL:
                if method.static:
                    s += 'S::Implementation::' + xname + '('
                else:
		                s += '((' + const + 'typename S::Implementation*) this_)->' + xname + '('
            elif method.static:
                s += 'C::' + method.name + '('
            else:
                s += '((' + const + 'C*) this_)->' + method.name + '('
            if cls.interface != Class.SIMPLE_VIRTUAL or not freeMethod:
                s += implFunctionArgs
            else:
                s += '(const C*) object'
            s += '); }'
            self.implFunctions << s
            if cls.interface == Class.VIRTUAL and not method.static:
                self.defaults << 'MAXON_METHOD ' + methodRetType + ' ' + xname + '(' + paramsNoDefaults + (') const' if const else ')') << '{'
                if defaultReturn:
                    self.defaults << 'return ' + defaultReturn.replace('@', 'NULLIMPL') + ';'
                self.defaults << '}' << ''
                self.decorators << 'MAXON_METHOD ' + methodRetType + ' ' + xname + '(' + paramsNoDefaults + (') const' if const else ')') << '{'
                self.decorators << 'return maxon::Cast<' + cls.refClass + '>(self.GetDecoratedObject()).' + method.name + '(' + refFunctionArgs + ');'
                self.decorators << '}' << ''
                self.proxyFunctions << methodRetType + ' ' + method.name + '(' + paramsNoDefaults + ') ' + const << '{'
                if cls.qname() == 'maxon.ObjectInterface' and method.name == 'InitObject':
                    self.proxyFunctions << 'return OK;'
                else:
                    retTypeStar = ''
                    retTypeAmp = ''
                    retType = methodRetType
                    if methodRetType.endswith('&&'):
                        retTypeStar = '*'
                        retTypeAmp = '&'
                        retType = methodRetType[:-2] + '*'
                    elif methodRetType.endswith('&'):
                        retTypeStar = '*'
                        retTypeAmp = '&'
                        retType = methodRetType[:-1] + '*'
                    self.proxyFunctions << 'const maxon::ComponentInfo* proxy_info;'
                    self.proxyFunctions << 'maxon::ObjectInterface* o_;'
                    self.proxyFunctions << 'const maxon::reflection::ProxyHandler* handler_;'
                    self.proxyFunctions << 'if (maxon::UInt(this) & (SIZEOF(void*)-1))' << '{' << 'o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);'
                    self.proxyFunctions << 'proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));'
                    self.proxyFunctions << 'handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());' << '}' << 'else' << '{'
                    self.proxyFunctions << 'o_ = (maxon::ObjectInterface*) this->self.GetPointer();' << 'proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);' << 'handler_ = &_handler;' << '}'
                    self.proxyFunctions << 'const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<' + cls.name + '>();'
                    if methodRetType != 'void':
                        self.proxyFunctions << retType + ' proxy_result = ' + retTypeAmp + defaultReturn.replace('@', 'NULLIMPL') + ';'
                    args = ', '.join(['maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._' + cname + '_Offset)']
                                     + ['maxon::reflection::Argument::By' + ('Reference' if x.type.endswith('&') else 'Value') + '(' + x.name + ')' for x in method.params])
                    self.proxyFunctions << 'maxon::reflection::Argument proxy_args[] = {' + args + '};'
                    self.proxyFunctions << '(*handler_)(_fn_' + cname + ', o_, maxon::reflection::ProxyInvocation(' + ('std::addressof(proxy_result)' if methodRetType != 'void' else 'nullptr') + ', proxy_args, ' \
                        + '&maxon::reflection::Invocation<' + methodRetType + ', ' + const + 'maxon::GenericComponent*' + ''.join([', ' + p.type for p in methodParams]) + '>::Invoke, (const void*) mt_._' + cname + '));'
                    if methodRetType != 'void':
                        self.proxyFunctions << 'return ' + retTypeStar + 'proxy_result;'
                self.proxyFunctions << '}'
                self.proxyFunctions << 'static const maxon::reflection::Function* _fn_' + cname + ';'
                self.proxyFunctionPointers << self.templatePrefix + 'const maxon::reflection::Function* ' + self.tclass + '::ProxyComponent::_fn_' + cname + ';'
            else:
                s = 'static ' if method.static else ''
                s += methodRetType + ' ' + method.name + '(' + paramsNoDefaults + ') ' + const + '{ '
                self.unresolvedFunctions << s + 'if (' + (methodParams[-1].name + ' && ' if freeMethod else '') + 'maxon::NonvirtualInterfaceReference::PrivateResolve(&' + ('_staticInterface' if cls.interface == Class.VIRTUAL else '_interface') + ', ' + boolStr(not method.result) + ')) return ' \
                    + (cls.name + '::' if method.static else '((' + const  + cls.name + '*) this)->') \
                    + method.name + '(' + refFunctionArgs + '); return ' + defaultReturn.replace('@', 'UNRESOLVED') + ';}'
                self.nullFunctions << s + 'return ' + defaultReturn.replace('@', 'NULLIMPL') + '; }'
        cowName = method.getAnnotation('cowName', None)
        if cls.refClass and method.includeInRefClass():
            funcTemplate = ''
            funcTemplateArgsCopy = ''
            funcTemplateArgs = ''
            mt = None
            if method.template:
                mt = Template()
                args = []
                for x in method.template.params:
                    s = subst.get(x.name)
                    if not s:
                        mt.params.append(x)
                    args.append(s or x.toStr(True, True))
                if args:
                    funcTemplateArgs = '<' + ', '.join(args) + '>'
                if mt.params:
                    funcTemplate = mt.toStr(False, False) + ' '
                    funcTemplateArgsCopy = mt.toStr(True, False) + ' '

            useGenericCast = False
            if subst:
                methodRetType, useGenericCast = substitute(methodRetType, subst)
                defaultReturn, dummy = substitute(defaultReturn, subst)                   
                functionArgs, dummy = substitute(functionArgs, subst)
                refFunctionArgs, dummy = substitute(refFunctionArgs, subst)
                for p in methodParams:
                    p.type, dummy = substitute(p.type, subst)

            params = ', '.join([p.toStr() for p in methodParams])
            paramsNoDefaults = ', '.join([p.toStr(True) for p in methodParams])

            if method.name == 'Create':
                self.hasCreateRefFunction = True            
            cowReset = boolStr(not cls.isError)
            for cowMode in range(1 if onlyCow else 0, 2):
                xret = methodRetType
                refName = cowName if cowMode and cowName else method.name
                if cowMode:
                    if method.static or method.const or (cls.interface != Class.VIRTUAL and not self.cowRef):
                        break
                    if not cowName and any([isinstance(m, Function) and m.name == refName and m.const for m in method.owner.children]):
                        break # don't add COW functions if there is a const-qualified overload
                refSuffix = ' const' if method.const or not (method.static or cowMode) else ''
                returnsThisReturn = None
                if returnsThis:
                    xret = 'DOXYGEN_SWITCH(maxon::RefMemberType<S' + refSuffix + '>, S)'
                    defaultReturn = 'this->PrivateGetRefMember()'
                    returnsThisReturn = defaultReturn
                    if method.result:
                        xret = 'maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S' + refSuffix + '>, S)>'
                        returnsThisReturn = 'this->PrivateGetRefMember()'
                        defaultReturn = 'maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::@)'
                returnsRef = cls.refClass and (xret == cls.name + '*')
                if returnsRef:
                    xret = cls.refClass
                    wrapper = xret
                    if not method.getAnnotation('default', None):
                        defaultReturn = xret + '::NullValue()'
                elif useGenericCast and not method.template:
                    wrapper = 'maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>'
                else:
                    wrapper = ''
                if method.parseAnnotation('incompleteReturnType', False):
                    xret = 'DOXYGEN_SWITCH(MAXON_MACROARG_TYPE(typename maxon::SFINAEHelper<' + xret + ', S>::type), ' + xret + ')'
                fnImplClass = ('Const' if method.const or method.static else 'COW' if cowMode else '') + 'ReferenceFunctionsImpl'
                defPrefix = self.templatePrefix + 'template <typename S' + self.genericParams + '> ' + funcTemplateArgsCopy + 'MAXON_ATTRIBUTE_FORCE_INLINE auto ' + self.tclass + '::Hxx1::' + fnImplClass + '<S' + self.genericArgs + '>'
                refFunction = None
                if method.static:
                    if method.name == 'Alloc':
                        params = ', '.join([p.toStr() for p in methodParams[1:]])
                        paramsNoDefaults = ', '.join([p.toStr(True) for p in methodParams[1:]])
                        if len(methodParams) != 2 or methodParams[1].type.find(cls.name + '&') < 0:
                            if method.doc:
                                createComment = ''
                                constrComment = ''
                                inRet = False
                                inAlloc = False
                                for line in method.doc.split('\n'):
                                    lineNoTabs = line.replace('\t', '  ')
                                    if line.find('@return') >= 0:
                                        inRet = True
                                        createComment += '/// @return\t\t\t\t\t\t\t\t\t\t\t\t@c true on success, @c false if allocation or initialization failed.\n'
                                    elif inRet and not lineNoTabs.startswith('///    '):
                                        inRet = False
                                    if line.find('@param') >= 0 and line.find('allocLocation') >= 0:
                                        inAlloc = True
                                    elif inAlloc and not lineNoTabs.startswith('///    '):
                                        inAlloc = False
                                    if line and not inRet and not inAlloc:
                                        createComment += line + '\n'
                                        constrComment += line + '\n'
                            if method.doc:
                                self.refConstructors.code += createComment
                            # We force inlining so that MAXON_SOURCE_LOCATION is more likely to use the current g_translationUnit.
                            if methodRetType.endswith('*'):
                                self.refConstructors << 'static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<' + self.genericRefClass + '> Create(' + params + ');'
                                self.refFunctionsDef << self.templatePrefix + self.genericOnlyPrefix + 'auto ' + self.tclass + '::' + self.referenceName + '::Create(' + paramsNoDefaults + ') -> maxon::ResultMemT<' + self.genericRefClass + '>' \
                                    << '{' <<  methodRetType + ' res_ = ' + cls.name + '::Alloc(MAXON_SOURCE_LOCATION' + ''.join([', ' + p.forward() for p in methodParams[1:]]) + ');' \
                                    << 'return ' + self.genericRefClass + '(maxon::ForwardResultPtr<' + methodRetType[:-1]  + '>(res_));' << '}'
                            else:
                                self.refConstructors << 'static MAXON_ATTRIBUTE_FORCE_INLINE maxon::Result<' + self.genericRefClass + '> Create(' + params + ');'
                                self.refFunctionsDef << self.templatePrefix + self.genericOnlyPrefix + 'auto ' + self.tclass + '::' + self.referenceName + '::Create(' + paramsNoDefaults + ') -> maxon::Result<' + self.genericRefClass + '>' \
                                    << '{' << 'auto res_ = ' + cls.name + '::Alloc(MAXON_SOURCE_LOCATION' + ''.join([', ' + p.forward() for p in methodParams[1:]]) + ');' \
                                    << 'if (res_ == maxon::FAILED) return res_.GetError(); else return ' + self.genericRefClass + '(res_.GetValue());' \
                                    << '}'
                    else:
                        refFunction = funcTemplate + attr + 'static inline ' + xret + ' ' + refName + '(' + params + ')' + refSuffix + ';'
                        if method.kind == 'MAXON_FUNCTION':
                            s = cls.name + '::' + method.name + funcTemplateArgs
                        else:
                            s = ('Hxx2::Static' if cls.interface == Class.VIRTUAL else '') + 'MTable::_instance._' + cname
                        self.refFunctionsDef << defPrefix + '::' + refName + '(' + paramsNoDefaults + ')' + refSuffix + ' -> ' + xret + ' { return ' \
                            + wrapper + '(' + s + '(' + functionArgs + ')); }'
                else:
                    result = method.result
                    if xret == 'ResultMem' or xret == 'maxon::ResultMem':
                        rret = 'maxon::Result<void>'
                    elif xret.startswith('ResultOk<') or xret.startswith('maxon::ResultOk<'):
                        rret = 'maxon::Result' + xret[xret.index('<'):]
                    elif xret.startswith('ResultPtr<') or xret.startswith('maxon::ResultPtr<'):
                        rret = 'maxon::Result' + xret[xret.index('<'):-1] + '*>'
                    elif xret.startswith('ResultRef<') or xret.startswith('maxon::ResultRef<'):
                        rret = 'maxon::Result' + xret[xret.index('<'):-1] + '&>'
                    elif not method.result:
                        rret = 'maxon::Result<' + xret + '>'
                    else:
                        rret = xret
                    xretOrig = xret
                    if not method.parseAnnotation('noResult', False) and method.name != 'operator':
                        if cowMode:
                            if xret != rret:
                                xret = 'typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ' + xret + ', ' + rret + '>::type'
                            defaultReturn = 'maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::@)'
                            result = True
                        elif not result:
                            if xret != rret:
                                xret = 'typename std::conditional<S::HAS_ERROR, ' + rret + ', ' + xret + '>::type'
                            result = True
                    refFunction = funcTemplate + attr + 'inline ' + ('operator ' + methodRetType if refName == 'operator' else xret + ' ' + refName) + '(' + params + ')' + refSuffix + ';'
                    if method.name == 'operator':
                        self.refFunctionsDef << defPrefix.replace(' auto ', ' ') + '::operator ' + methodRetType + '(' + paramsNoDefaults + ')' + refSuffix << '{'
                    else:
                        self.refFunctionsDef << defPrefix + '::' + refName + '(' + paramsNoDefaults + ')' + refSuffix + ' -> ' + xret << '{'
                    rfd = CodeWriter(self.header, None)
                    rfd.linebreak = False
                    rfd.baseIndent = self.refFunctionsDef.baseIndent + self.refFunctionsDef.indent
                    if method.access != 'public':
                        rfd << 'static_assert(std::is_base_of<maxon::SelfPointerHandler, typename S::Handler>::value, "Protected method ' + cls.name + '::' + method.name + ' can only be invoked on self or super.");'
                    elif not method.parseAnnotation('refclass', True):
                        rfd << 'static_assert(std::is_base_of<maxon::SelfPointerHandler, typename S::Handler>::value, "Method ' + cls.name + '::' + method.name + ' with refclass=false can only be invoked on self or super.");'
                    if method.kind == 'MAXON_FUNCTION' and cls.interface == Class.VIRTUAL and (cowMode or method.const):
                        rfd << 'static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can\'t invoke MAXON_FUNCTION ' + cls.name + '::' + method.name + ' on super.");'
                    if not result:
                        rfd << 'static_assert(!S::HAS_ERROR, "' + cls.name + '::' + refName + ' can\'t be used on a Result object because it does not return a Result object itself.");'
                    if result:
                        rfd << 'if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this);'
                    nullptrReturn = defaultReturn
                    if result and ((returnsThis and method.parseAnnotation('noResult', False)) or cowMode):
                        nullptrReturn = 'ReturnHelper::Return(this, ' + defaultReturn + ')'
                    if result and returnsThis and not method.parseAnnotation('noResult', False):
                        nullptrReturn = 'ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::@))'
                    if method.const:
                        rfd << 'const ' + cls.name + '* o_ = (const ' + cls.name + '*) this->GetPointer();' \
                            << 'if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ' + cls.name + '::NullValuePtr(); if (!o_) return ' + defaultReturn.replace('@', 'NULLPTR') + '; }'
                    else:
                        rfd << cls.name + '* o_ = (' + cls.name + '*) this->' + ('MakeWritable(' + cowReset + ').GetPointer();' if cowMode else 'GetPointer();') \
                            << 'if (!(S::Handler::KIND & (' + ('maxon::VALUEKIND::DEEP_CONSTNESS | ' if cowMode else '') + 'maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) {' + ('' if (cowMode or methodRetType != 'void') else ' DebugStop();')  + ' return ' + nullptrReturn.replace('@', 'MAKE_WRITABLE_FAILED' if cowMode else 'NULLPTR') + '; }'
                    if method.kind == 'MAXON_FUNCTION':
                        oPointer = 'o_'
                        if method.parseAnnotation('incompleteReturnType', False):
                            oPointer = 'static_cast<typename maxon::SFINAEHelper<' + ('const ' if method.const else '') + cls.name + '*, S>::type>(o_)'
                        s = oPointer + '->' + method.name
                        if method.name == 'operator':
                            s += ' ' + methodRetType
                        s += funcTemplateArgs + '(' + refFunctionArgs + ')'
                    else:
                        if cls.interface == Class.VIRTUAL:
                            rfd << 'const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(' + cls.name + ', o_, ' + cname + ') : ' \
                                + '((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<' + cls.name + '>::value) ? S::PrivateReferencedType::MTable::template GetMTable<' + cls.name + '>() : PRIVATE_MAXON_VTABLE(' + cls.name + ', o_);'
                            s = 'mt_.'
                        elif cls.interface == Class.NONVIRTUAL:
                            s = 'MTable::_instance.'
                        else:
                            s = '((' + cls.name + '::MTable*) o_->_vtable)->'
                        s += '_' + cname + '('
                        if cls.interface == Class.VIRTUAL:
                            s += 'reinterpret_cast<' + const + 'maxon::GenericComponent*>(o_) + mt_._' + cname + '_Offset'
                        else:
                            s += 'o_'
                        s += functionArgs + ')'
                    if returnsThis:
                        if method.result:
                            returnLine = 'auto res_ = ' + s + ';\nreturn ReturnHelper::Return(this, res_.GetErrorStorage());'
                        else:
                            if methodRetType.endswith('*'):
                                s = 'if (' + s + ' == nullptr) this->ResetReference()'
                            returnLine = s + ';\nreturn ' + returnsThisReturn + ';'
                    elif methodRetType == 'void':
                        returnLine = s + ';\nreturn (typename ReturnHelper::ReturnType) maxon::OK;'
                    else:
                        returnLine = 'return ' + wrapper + '(' + s + ');'
                    s = rfd.get()
                    if s.find('ReturnHelper') >= 0:
                        s = 'using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), ' + boolStr(returnsThis) + ', ' + xret + '>; ' + s
                    self.refFunctionsDef << s
                    self.refFunctionsDef << returnLine
                    self.refFunctionsDef << '}'
                if refFunction:
                    doc = ''
                    if method.doc:
                        doc = method.doc
                        if method.observable:
                            doc = doc.replace('@param', '-param')
                    if method.const or method.static:
                        self.constRefFunctions.code += doc
                        self.constRefFunctions << refFunction
                    else:
                        w = self.cowRefFunctions if cowMode else self.refFunctions
                        w.code += doc
                        w << refFunction

    def processClassMembers(self, cls, base):
        if cls.interface == Class.NONVIRTUAL or cls.interface == Class.VIRTUAL:
            for bc, access, generic in base.bases:
                basename = bc
                p = basename.find('<')
                if p >= 0:
                    basename = basename[:p]
                b = cls.owner.find(Class, basename)
                if b and not b.interface:
                    ta = self.templateArgs.copy()
                    if b.template:
                        if p < 0:
                            base.name.pos.raiseError('Template arguments don\'t match template specification.')
                        p += 1
                        for param in b.template.params:
                            e = bc.find(',', p + 1)
                            if e < 0:
                                e = bc.find('>', p + 1)
                            if e < 0:
                                base.name.pos.raiseError('Template arguments don\'t match template specification.')
                            self.templateArgs[param.name] = bc[p:e].strip()
                            p = e + 1
                    self.processClassMembers(cls, b)
                    self.templateArgs = ta
        for decl in base.children:
            if isinstance(decl, Function):
                if cls.interface and (decl.kind == 'MAXON_METHOD' or decl.kind == 'MAXON_FUNCTION'):
                    self.processMethod(decl, cls, cls.qname() == 'maxon.System' and decl.name == 'Free')
            elif cls == base:
                if isinstance(decl, Observable):
                    if cls.interface:
                        handlerName = 'Handle' + (decl.name[10:] if decl.name.startswith('Observable') else decl.name)

                        # The first enable_if case is for AddObserver calls where FN already contains a handler method to which the parameters should be forwarded.
                        # The second case is for calls where FN is a delegate/lambda/method.
                        self.signalDecl << 'class ' + cls.name + '::' + decl.name + 'Delegate : public maxon::Delegate<' + decl.retType + '(' + ','.join([p.type for p in decl.params]) + ')>' << '{' << 'public:' \
                            << 'using Super = maxon::Delegate<' + decl.retType + '(' + ','.join([p.type for p in decl.params]) + ')>;' \
                            << 'MAXON_MEMBERFUNCTION_DETECTOR(' + handlerName + ');' \
                            << decl.name + 'Delegate() = default;' \
															<< 'template <typename FN> static maxon::ResultOk<Super> Create' \
                                + '(FN&& src, typename std::enable_if<Has' + handlerName + '<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) ' \
                                + '{ return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::' + handlerName + '); }' \
                            << 'template <typename FN> static maxon::Result<Super> Create' \
                                + '(FN&& src, typename std::enable_if<!Has' + handlerName + '<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr)' \
                                + '{ return Super::Create(std::forward<FN>(src)); }' \
                            << 'using OBSERVABLECOMBINER = ' + decl.combiner + 'PrivateHelper;' \
                            << '};' << ''
                elif isinstance(decl, Declaration):
                    if decl.kind == 'MAXON_ATTRIBUTE_CLASS':
                        self.regs << cls.owner << cls.name + '::' + decl.name + '_PrivateAttribute ' + cls.name + '::' + decl.name + ';'
                    elif decl.kind == 'MAXON_ADD_TO_REFERENCE_CLASS':
                        self.refFunctions.code += decl.code
                        self.refFunctions << 'public:'
                    elif decl.kind == 'MAXON_ADD_TO_COPY_ON_WRITE_REFERENCE_CLASS':
                        self.cowRefFunctions.code += decl.code
                        self.cowRefFunctions << 'public:'
                    elif decl.kind == 'MAXON_ADD_TO_CONST_REFERENCE_CLASS':
                        self.constRefFunctions.code += decl.code
                        self.constRefFunctions << 'public:'
                    elif decl.kind == 'MAXON_ADD_TO_INTERFACE_TEMPLATE_CLASS':
                        self.interfaceTemplateCode.code += decl.code
                        self.interfaceTemplateCode << 'public:'
                    else:
                        self.processClassOrNamespaceDeclaration(decl)
                        if cls.interface and cls.qname() != 'maxon.ObjectInterface' and isinstance(decl, TypeDeclaration) and not decl.template and not decl.friend and not (isinstance(decl, Class) and decl.forward) and not cls.template:
                            self.membertypes.append(decl)
                elif isinstance(decl, Directive):
                    addDirective(decl.code, cls, (self.decls, self.defs, self.regs, self.reflection))
                    if cls.interface:
                        addDirective(decl.code, cls, (self.init, self.xinit, self.staticInit, self.ids, self.staticIds, self.pointers, self.staticPointers, self.functions, self.implFunctions, \
                                                      self.refFunctions, self.refFunctionsDef, self.constRefFunctions, self.cowRefFunctions, self.unresolvedFunctions, self.nullFunctions, \
                                                      self.reflectionFunctions, self.staticReflectionFunctions, self.proxyFunctions, self.proxyFunctionPointers, self.unresolvedInit, \
                                                      self.unresolvedRetType, self.interfaceTemplateCode))

    def processClass(self, cls):
        freeMethod = None
        if cls.interface:
            tclass = cls.name
            qname = cls.qname()
            nullSuper = 'S'
            invocationSuper = 'S'
            wrapperSuper = 'S'
            combinedSuper = 'S'
            if cls.baseInterfaces:
                for b, g in cls.baseInterfaces:
                    nullSuper = 'typename ' + b + '::template Null<' + nullSuper + '>'
                    invocationSuper = 'typename ' + b + '::template SuperInvocation<' + invocationSuper + '>'
                    wrapperSuper = 'typename ' + b + '::Hxx2::template Wrapper<' + wrapperSuper + '>'
                    combinedSuper = 'typename ' + b + '::MTable::template CombinedMTable<' + combinedSuper + '>'
            templatePrefix = ''
            genericPrefix = ''
            genericPostfix = ''
            genericOnlyPrefix = ''
            genericOnlyPostfix = ''
            genericOnlyRefPostfix = ''
            genericParamsWithDefaults = ''
            genericArgs = ''
            genericParams = ''
            completeGenericPrefix = ''
            templatePostfix = ''
            template = ''
            typename = ''
            generic = Template()
            if cls.generic:
                generic.params = [copy.copy(p) for p in cls.generic.params]
                for p in generic.params:
                    p.name += '_'
                genericOnlyPrefix = generic.toStr(True, False) + ' '
                genericOnlyPostfix = generic.toStr(True, True)
                genericOnlyRefPostfix = templateToStrSubstPack(generic, True, True, True)
                genericParams = ''.join(', ' + p.toStr(True, False) for p in generic.params)
                genericParamsWithDefaults = ''.join(', ' + str(p) for p in generic.params)
                genericArgs = ''.join(', ' + p.name for p in generic.params)
            if cls.template:
                templatePrefix = cls.template.toStr(True, False) + ' '
                genericPrefix = ''
                templatePostfix = cls.template.toStr(True, True)
                template = 'PRIVATE_MAXON_TEMPLATE_PREFIX '
                typename = 'typename '
                tclass += templatePostfix
                generic.params = cls.template.params + generic.params
            if generic.params:
                genericPrefix = templateToStrSubstPack(generic, True, False, False) + ' '
                genericPostfix = templateToStrSubstPack(generic, True, True, False)
                completeGenericPrefix = templateToStrSubstPack(generic, False, False, False) + ' '
            self.tclass = tclass
            self.templatePrefix = templatePrefix
            self.genericOnlyPrefix = genericOnlyPrefix
            self.genericPostfix = genericPostfix
            self.genericParams = genericParams
            self.genericArgs = genericArgs
            
            if cls.refClass:
                self.genericRefClass = cls.refClass + genericPostfix
                if generic.params and isParameterPack(generic.params[-1]):
                    self.genericRefClass = 'typename ' + generic.params[-1].name + '::template Apply<' + cls.refClass + ''.join(', ' + x.name for x in generic.params[:-1]) + '>'

            buildRefClass = cls.parseAnnotation('refclass', True) == True
            self.referenceName = ('Hxx1::Reference' if buildRefClass else 'Reference') + self.genericPostfix
            
            if cls.interface != Class.VIRTUAL and cls.derived:
                wrapperSuper = cls.bases[0][0] + '::Hxx2::' + template + 'Wrapper<C>'
            if wrapperSuper.startswith('typename '):
                wrapperSuper = wrapperSuper[9:]

            self.decls << cls.owner
            self.defs << cls.owner
            if cls.refKind and not cls.refClassForwardDeclared:
                self.decls << completeGenericPrefix + 'class ' + cls.refClass + ';' << ''
            self.regs << cls.owner

            self.functions = CodeWriter(self.header, None)
            self.pointers = CodeWriter(self.header, None)
            self.staticPointers = CodeWriter(self.header, None)
            self.init = CodeWriter(self.header, None)
            self.xinit = CodeWriter(self.header, None)
            self.staticInit = CodeWriter(self.header, None)
            self.ids = CodeWriter(self.header, None)
            self.staticIds = CodeWriter(self.header, None)
            self.unresolvedInit = CodeWriter(self.header, None)
            self.implFunctions = CodeWriter(self.header, None)
            self.refFunctions = CodeWriter(self.header, None)
            self.refFunctionsDef = CodeWriter(self.header, None)
            self.cowRefFunctions = CodeWriter(self.header, None)
            self.constRefFunctions = CodeWriter(self.header, None)
            self.refConstructors = CodeWriter(self.header, None)
            self.nullFunctions = CodeWriter(self.header, None)
            self.unresolvedFunctions = CodeWriter(self.header, None)
            self.reflectionFunctions = CodeWriter(self.header, None)
            self.staticReflectionFunctions = CodeWriter(self.header, None)
            self.proxyFunctions = CodeWriter(self.header, None)
            self.proxyFunctionPointers = CodeWriter(self.header, None)
            self.unresolvedRetType = CodeWriter(self.header, None)
            self.signalDecl = CodeWriter(self.header, None)
            self.interfaceTemplateCode = CodeWriter(self.header, None)

            self.unresolvedInit.baseIndent = self.regs.indent + 1
            self.unresolvedFunctions.baseIndent = self.regs.indent + 1
            self.unresolvedRetType.baseIndent = self.regs.indent + 1

            self.init.baseIndent = self.defs.indent + 1
            self.xinit.baseIndent = self.defs.indent + 1
            self.staticInit.baseIndent = self.defs.indent + 2
            self.ids.baseIndent = self.defs.indent + 2
            self.staticIds.baseIndent = self.defs.indent + 2
            self.pointers.baseIndent = self.defs.indent + 1
            self.staticPointers.baseIndent = self.defs.indent + 1
            self.nullFunctions.baseIndent = self.defs.indent + 1
            self.reflectionFunctions.baseIndent = self.defs.indent + 3
            self.staticReflectionFunctions.baseIndent = self.defs.indent + 3
            self.proxyFunctions.baseIndent = self.defs.indent + 2
            self.proxyFunctionPointers.baseIndent = self.defs.indent + 1
            self.implFunctions.baseIndent = self.defs.indent + 1
            self.functions.baseIndent = self.defs.indent
            self.refFunctionsDef.baseIndent = self.defs.indent

            self.refFunctions.baseIndent = self.decls.indent + 2
            self.cowRefFunctions.baseIndent = self.decls.indent + 2
            self.constRefFunctions.baseIndent = self.decls.indent + 2
            self.refConstructors.baseIndent = self.decls.indent + 1
            self.signalDecl.baseIndent = self.decls.indent
            self.interfaceTemplateCode.baseIndent = self.decls.indent

            self.hasCreateRefFunction = False

            if cls.interface == Class.VIRTUAL:
                self.xinit << 'template <typename W> void Init(maxon::Int offset)' << '{'
                comp = 'My' + (cls.name[:-9] if cls.name.endswith('Interface') else cls.name) + 'Impl'
                self.defaults << '' << 'class ' + comp + ' : public maxon::Component<' + comp + ', ' + cls.name + '>' << '{' << 'MAXON_COMPONENT();' << '' << 'public:'
                comp = (cls.name[:-9] if cls.name.endswith('Interface') else cls.name) + 'DecoratorImpl'
                self.decorators << '' << 'class ' + comp + ' : public maxon::Component<' + comp + ', ' + cls.name + ', maxon::DecoratorInterface>' << '{' << 'MAXON_COMPONENT();' << '' << 'public:'
            else:
                self.init << 'template <typename IMPL> void Init()' << '{'
                if cls.interface == Class.SIMPLE_VIRTUAL and cls.derived:
                    self.init << 'super.template Init<IMPL>();'
            mtableCls = 'Hxx2::StaticMTable' if cls.interface == Class.VIRTUAL else 'MTable'
            if cls.interface == Class.NONVIRTUAL:
                self.nullFunctions << 'static const Null* Get(const ' + cls.name + '* o) { return (const Null*) o; }' \
                    << 'static Null* Get(' + cls.name + '* o) { return (Null*) o; }'
                self.unresolvedFunctions << 'static const Unresolved* Get(const ' + cls.name + '* o) { return (const Unresolved*) o; }' \
                    << 'static Unresolved* Get(' + cls.name + '* o) { return (Unresolved*) o; }'

            self.functionNameCount = {}
            self.nonstaticMethods = set()
            self.nullRets = set()
            self.methodNames = ''
            constRef = '' # will be set to "const " for MAXON_REFERENCE_CONST or MAXON_REFERENCE_CONST_POINTER
            constPtr = '' # will be set to "const " if the internal pointer is const (either a const or a cow reference)

            refHandler = None
            cowRef = False

            if not cls.refKind:
                pass
            elif cls.refKind == Class.POINTER:
                refHandler = 'maxon::PointerHandler'
            elif cls.refKind == Class.CONST_POINTER:
                refHandler = 'maxon::PointerHandler'
                constRef = 'const '
                constPtr = 'const '
            else:
                if cls.interface != Class.VIRTUAL and (not cls.derived or cls.interface == Class.NONVIRTUAL):
                    freeMethod = Function('MAXON_METHOD', 'Free', True, 'void', None, 'public')
                    freeMethod.doc = None
                    freeMethod.owner = cls
                    freeMethod.params.append(Parameter('const ' + cls.name + '*', 'object'))
                    freeMethod.annotations['refclass'] = False
                if cls.refKind == Class.REF or cls.refKind == Class.REF_UNIQUE:
                    refHandler = 'maxon::StrongRefHandler'
                elif cls.refKind == Class.CONST_REF:
                    refHandler = 'maxon::StrongRefHandler'
                    constRef = 'const '
                    constPtr = 'const '
                elif cls.refKind == Class.COW:
                    refHandler = 'maxon::StrongCOWRefHandler'
                    cowRef = True
                    constPtr = 'const '
                elif cls.refKind == Class.ACOW:
                    refHandler = 'maxon::StrongACOWRefHandler'
                    cowRef = True
                    constPtr = 'const '

            self.cowRef = cowRef
            self.constPtr = constPtr
            errorObject = cls.refClass + 'Object' if cls.isError and (qname != 'maxon.ErrorInterface') else None
            if cls.refClass:
                s1 = 'operator const typename maxon::RefConversionTarget<S, typename S::Handler, '
                s2 = ', ' + self.genericRefClass + ', '
                s3 = '>::type&() '
                s4 = '{ return reinterpret_cast<const ' + self.genericRefClass + '&>(this->GetBaseRef()); }'
                fn = self.cowRefFunctions if cowRef else (self.constRefFunctions if constRef else self.refFunctions)
                fn << s1 + refHandler + s2 + boolStr(not constPtr) + s3 + 'const ' + s4
                fn << s1 + refHandler + s2 + 'false' + s3 + s4 # needed to resolve ambiguities when this conversion function is involved
                if not cowRef and not constRef:
                    self.cowRefFunctions << s1 + 'void' + s2 + 'false' + s3 + s4


        self.templateArgs = {}

        if freeMethod:
            self.processMethod(freeMethod, cls, True)

        if cls.interface:
            self.hasNonstaticMethods = False
            self.hasPopulatedOrEmptyFunction = False
            self.membertypes = []
        self.processClassMembers(cls, cls)

        if cls.interface:
            superSize = ''
            if cls.interface == Class.NONVIRTUAL:
                self.regs << 'const maxon::Char* const ' + cls.name + '::MTable::_ids = ' << self.ids << '"";'

            hasNonvirtual = cls.interface == Class.NONVIRTUAL or (cls.interface == Class.VIRTUAL and self.staticPointers)
            if cls.interface == Class.VIRTUAL:
                self.defaults << '};'
                self.decorators << '};'
            self.defs << '' << templatePrefix + 'struct ' + tclass + '::MTable' << '{'
            if cls.interface == Class.VIRTUAL:
                for m in sorted(self.nonstaticMethods):
                    op = operatorId(m, None)
                    self.defs << 'PRIVATE_MAXON_IMPLEMENTS_CHECK(' + (op or m) + ');'
                self.defs << 'static const maxon::Char* const _ids;'
                self.defs << 'static const maxon::Bool HAS_NONSTATIC = false;' # this is needed only for the registration of the static functions, so make it look as if they were the only functions
            else:
                if cls.interface == Class.NONVIRTUAL:
                    self.defs << 'static MTable _instance;' << 'static MTable _unresolvedInstance;' << 'static const maxon::Char* const _ids;' \
                        << 'static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);' \
                        << 'static const maxon::NULL_RETURN_TYPE _returnTypes[];' \
                        << 'static const maxon::Bool HAS_NONSTATIC = ' + boolStr(self.hasNonstaticMethods) + ';'
                else:
                    self.defs << 'MTable() { }' << 'template <typename C> explicit MTable(C*) { Init<typename maxon::SFINAEHelper<Hxx2, C>::type::template Wrapper<C>>(); }' \
                        << 'template <typename C> MTable(C*, maxon::Bool) { Init<C>(); }'
                    if cls.derived:
                        self.defs << 'PRIVATE_MAXON_ALLOC_TYPENAME ' + cls.bases[0][0] + '::MTable super;'
                self.init << '}'
            self.defs << self.pointers
            self.defs << self.init

            if cls.interface == Class.VIRTUAL:
                self.xinit << '}'
                self.defs << self.xinit
                self.defs << 'template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)' << '{'
                if cls.baseInterfaces:
                    self.defs << 'if (!W::Implementation::PROXY && (' + ' || '.join(['!' + x + '::MTable::template InitWithBases<W>(info, offset)' for x, g in cls.baseInterfaces]) + ')) return false;'
                self.defs << 'MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;'
                self.defs << 'vt->Init<W>(offset); return true;'
                self.defs << '}'

                self.defs << 'template <typename S> using CombinedMTable = maxon::CombinedMTable<' + cls.name + ', ' + combinedSuper + '>;'
                self.defs << 'PRIVATE_MAXON_COMPBASE(' + cls.name + ');'
                if cls.singleImpl:
                    self.defs << 'struct NVMTable;'
                    self.defs << 'template <typename I> static const typename I::MTable& GetMTable() { return maxon::SFINAEHelper<NVMTable, I>::type::_instance.template GetMTable<I>(); }'
                else:
                    self.defs << 'template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }'

                self.decls << templatePrefix + 'struct ' + tclass + '::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ' + cls.name \
                    + '>::value || ' + ('std::is_same<I, maxon::ObjectInterface>::value' if not cls.baseInterfaces else ' || '.join([x + '::HasBase::template Check<I>::value' for x, g in cls.baseInterfaces])) \
                    + '; static I* Cast(' + cls.name + '* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };'

            self.defs << '};' << ''

            if cls.refKind and errorObject:
                self.decls << 'struct ' + errorObject + 'PrivateHelper;'

            if cls.interface == Class.VIRTUAL:
                if cls.singleImpl:
                    self.defs << templatePrefix + 'struct ' + tclass + '::MTable::NVMTable : public MTable::template CombinedMTable<maxon::CombinedMTableRoot> { static NVMTable _instance; };' << ''

            self.defs << templatePrefix + 'struct ' + tclass + '::Hxx2' << '{'

            if hasNonvirtual:
                self.defs << 'class Unresolved;'

            if cls.interface == Class.VIRTUAL:
                if self.staticPointers:
                    self.defs << 'struct StaticMTable' << '{'
                    self.defs << 'static StaticMTable _instance;' << 'static StaticMTable _unresolvedInstance;'
                    self.defs << 'static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, StaticMTable* tbl);'
                    self.defs << 'static const maxon::Char* const _ids;' << 'static const maxon::NULL_RETURN_TYPE _returnTypes[];'
                    #     << 'static MTable _methodIds;' << 'static void InitIds(MTable* tbl);' \
                    #    << 'static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);' \
                    #    << 'static const maxon::NULL_RETURN_TYPE _returnTypes[];'
                    self.defs << self.staticPointers
                    self.defs << 'StaticMTable() = default;'
                    self.defs << 'template <typename IMPL> static void Init(StaticMTable* tbl)' << '{' << self.staticInit << '}'
                    self.defs << '};'

                self.defs << 'template <typename S> class Wrapper : public ' + wrapperSuper << '{' << 'public:'
                for m in sorted(self.nonstaticMethods):
                    op = operatorId(m, None)
                    self.defs << 'PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(' + (op or m) + ');'
            elif cls.interface == Class.NONVIRTUAL:
                if cls.parseAnnotation('nullimpl', False):
                    self.defs << 'class Null : public ' + (cls.bases[0][0] + '::Hxx1::Null' if cls.derived else cls.name) << '{' << 'public:'
                    if cls.derived:
                        self.defs << 'operator const ' + cls.name + '&() const { return *static_cast<const ' + cls.name + '*>(static_cast<const BaseInterface*>(this)); }'
                        self.defs << 'operator ' + cls.name + '&() { return *static_cast<' + cls.name + '*>(static_cast<BaseInterface*>(this)); }'
                    self.defs << self.nullFunctions
                    self.defs << '};' << ''
                self.defs << 'template <typename C> class Wrapper' + (' : public ' + wrapperSuper if cls.derived else '')
                self.defs << '{' << 'public:'
            else:
                self.defs << 'template <typename C> class Wrapper' + (' : public ' + wrapperSuper if cls.derived else '')
                self.defs << '{' << 'public:'
            self.defs << self.implFunctions
            self.defs << '};' << ''

            self.defs << '};'

            self.defs << self.functions << ''
            if cls.interface == Class.SIMPLE_VIRTUAL and cls.derived:
                self.defs << templatePrefix + tclass + '::' + cls.name + '(const MTable& vtable) : ' + cls.bases[0][0] \
                    + '(vtable.super) { }'

            super = None
            if cls.refKind:
                self.decls << templatePrefix + 'struct ' + tclass + '::Hxx1' << '{'
                if buildRefClass:
                    self.decls << genericOnlyPrefix + 'class Reference;'
                if constPtr:
                    self.decls << genericOnlyPrefix + 'class NonConstRef;'
                likely = 'MAXON_UNLIKELY' if cls.isError else 'MAXON_LIKELY'
                opBool = '\texplicit operator maxon::Bool() const { return ' + likely + '(this->GetPointer() != nullptr); }\n' \
                    + 'private:\n\toperator void*() const;\n'
                cowReset = boolStr(not cls.isError)
                if errorObject:
                    self.decls << 'using ErrObj = ' + errorObject + 'PrivateHelper;'
                self.decls << 'using ReferenceClass = ' + cls.refClass + (templatePostfix or ('<>' if cls.generic else '')) + ';'

                super = 'ST'

                doxySuper = ''
                if cls.interface == Class.VIRTUAL:
                    self.decls << 'template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<' + ', '.join(b for b, g in cls.baseInterfaces) + '>;'
                    for b, g in cls.baseInterfaces:
                        doxySuper += ', public '+ b + '::@ReferenceFunctionsImplDoxy<REF>'
 
                for fn in ['Const', '', 'COW']:
                    fnCls = fn + 'ReferenceFunctionsImpl'
                    self.decls << '/// Intermediate helper class for ' + cls.name + '.'
                    fnSuper = 'S' if fn == 'Const' else 'ConstReferenceFunctionsImpl<S' + genericArgs + '>'
                    self.decls << 'template <typename S' + genericParams + '> class ' + fnCls + (' DOXYGEN_SWITCH(: public S,)' if fn == 'Const' else ' : public ' + fnSuper)
                    self.decls << '{' << 'public:' << fnCls + '() = default;'
                    self.decls << 'using PrivateBaseClass = ' + fnSuper + ';' << 'using PrivateBaseClass::PrivateBaseClass;'
                    if cls.generic:
                        for p in cls.generic.params:
                            if isinstance(p, TypeTemplateParam):
                                self.decls << 'using ' + p.name + ' = ' + p.name + '_;'
                    if fn == 'Const':
                        for mt in self.membertypes:
                            if not (cls.generic and cls.generic.findParam(mt.name)):
                                self.decls << 'using ' + mt.name + ' = ' + cls.name + '::' + mt.name + ';'
                        if cls.generic:
                            s = 'typename _S'
                            c = 'true'
                            x = '_S'
                            d = ''
                            for p in cls.generic.params:
                                if p.variance:
                                    s += ', ' + p.declstr() + ' _' + p.name
                                    c += ' && '
                                    if p.variance.endswith('>'):
                                        c += p.variance[:-1] + ', _'
                                    else:
                                        c += p.variance + '<_'
                                    c += p.name + ', ' + p.name + '_>::value'
                                    x += ', _' + p.name 
                                else:
                                    x += ', ' + p.name + '_'
                                d += ', ' + p.default
                            self.decls << 'using S::GenericVarianceCheck;' # Intel compiler only works when the using is before the function declaration
                            self.decls << 'template <' + s + '> static typename std::integral_constant<bool, ' + c + '>::type GenericVarianceCheck(const ConstReferenceFunctionsImpl<' + x + '>*);'
                            self.decls << 'template <typename _S> static typename std::true_type GenericVarianceCheck(ConstReferenceFunctionsImpl<_S' + d + '>*);'
                            self.decls << 'template <typename DERIVED> struct IsGenericBaseOf { static const Bool value = S::template IsGenericBaseOf<DERIVED>::value && decltype(DERIVED::GenericVarianceCheck((ConstReferenceFunctionsImpl*) nullptr))::value; };'
                    self.decls << (self.constRefFunctions if fn == 'Const' else self.refFunctions if fn == '' else self.cowRefFunctions)
                    if fn == 'COW' and self.hasPopulatedOrEmptyFunction:
                        self.decls << 'explicit operator maxon::Bool() const MAXON_WORKAROUND_CLANG_DELETED_FUNCTION(S);'
                        self.decls << 'explicit operator maxon::Bool() MAXON_WORKAROUND_CLANG_DELETED_FUNCTION(S);'
                    self.decls << '};'

                if cls.generic:
                    subst = dict()
                    for p in cls.generic.params:
                        subst[p.name] = p.name + '_'

                if cls.interface == Class.VIRTUAL:
                    for b, gen in cls.baseInterfaces:
                        if cls.generic:
                            gen, dummy = substitute(gen, subst)
                        super = 'typename ' + b + '::Hxx1::template ReferenceFunctionsHelper<' + super + gen + '>'
                elif cls.derived:
                    gen = cls.bases[0][2]
                    if cls.generic:
                        gen, dummy = substitute(gen, subst)
                    super = cls.bases[0][0] + '::Hxx1::template ReferenceFunctionsHelper<' + super + gen + '>'

                super = addTypename(super)
 
                # GCC takes ages to compile when a "using" is used for ReferenceFunctionsHelper, therefore define a new struct
                self.decls << 'template <typename ST' + genericParamsWithDefaults + '> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<' + super + '::type' + genericArgs + '>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<' + super + '::type' + genericArgs + '>, ReferenceFunctionsImpl<' + super + '::type' + genericArgs + '>>::type> { };'

                self.decls << '};'
                
                genericInterfaceTemplate = None
                if cls.generic and cls.name.startswith('Generic'):
                    genericInterfaceTemplate = cls.name[7:]
                    self.decls << completeGenericPrefix + 'class ' + genericInterfaceTemplate + ' : public ' + cls.name + '::Hxx1::template ReferenceFunctionsHelper<maxon::details::DirectInstance<' \
                        + genericInterfaceTemplate + genericPostfix + ', ' + cls.name + '>' + ''.join(', ' + templateParamToStrSubstPack(x, True, True, True) for x in generic.params) + '>::type' \
                        << '{' << 'public:' << 'using ErasedType = ' + cls.name + ';' \
                        << 'struct Instantiation' << '{' \
                        << 'template <template <typename> class MAP> using Map = ' + genericInterfaceTemplate + '<' + ', '.join(templateParamToStrMap(x) for x in generic.params) + '>;' << '};'
                        # << 'template <typename X> using Rebind = ' + genericInterfaceTemplate + '<NAME, X>;'
                    self.decls << self.interfaceTemplateCode
                    self.decls << '};'

                for ref in ['Reference', 'NonConstRef']:
                    className = ref
                    if ref == 'Reference':
                        cptr = constPtr
                        handler = refHandler
                        rcls = self.genericRefClass
                        if buildRefClass:
                            className = 'Hxx1::' + ref
                    else:
                        if not constPtr:
                            continue
                        if templatePrefix:
                            continue # workaround for Intel 16 bug for the ArrayInterface<TYPE>::NonConstRef case. This is OK as long as we don't actually need ArrayInterface<TYPE>::NonConstRef.
                        cptr = ''
                        handler = 'maxon::StrongRefHandler' if refHandler == 'maxon::StrongCOWRefHandler' else refHandler
                        rcls = 'NonConstRef' + genericOnlyPostfix
                        className = 'Hxx1::' + ref

                    baseInterface = tclass
                    if genericInterfaceTemplate:
                        baseInterface = genericInterfaceTemplate + genericPostfix
                        if generic.params and isParameterPack(generic.params[-1]):
                            baseInterface = 'typename ' + generic.params[-1].name + '::template Apply<' + genericInterfaceTemplate + ''.join(', ' + x.name for x in generic.params[:-1]) + '>'

                    base = 'maxon::RefBaseFunctions<maxon::DirectRef<' + cptr + baseInterface + ', ' + handler + ', ' + rcls + '>>'
                    superRef = 'maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<' + base + genericArgs + '>>'
                    self.decls << templatePrefix + self.genericOnlyPrefix + 'class ' + tclass + '::' + className + ' :'
                    self.decls << '#ifdef DOXYGEN' << 'public ' + ('COWReferenceFunctionsImplDoxy' if handler.find('COW') >= 0 else 'ConstReferenceFunctionsImplDoxy' if cptr else 'ReferenceFunctionsImplDoxy') + '<' + rcls + '>'
                    self.decls << '#else' << 'public ' + superRef << '#endif'

                    if cls.refKind == Class.REF_UNIQUE:
                        self.decls << '{' << 'public:' << 'MAXON_UNIQUE_REFERENCE_CONSTRUCTORS(' + ref + ', ' + superRef + ');'
                    else:
                        self.decls << '{' << 'public:' << 'MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(' + ref + ', ' + superRef + ');'

                    if ref == 'Reference':
                        typename = 'typename ' if templatePrefix else ''
                        self.decls << 'using NonConst = ' + ('Hxx1::NonConstRef' + genericOnlyPostfix if constPtr else 'typename Super::ReferenceClass') + ';'
                        if self.refConstructors:
                            self.decls << self.refConstructors
                            if self.hasCreateRefFunction:            
                                self.decls << 'using Super::Create;'
                    self.decls  << '};' << ''

                self.defs << self.refFunctionsDef
                if cls.interface == Class.VIRTUAL:
                    self.defs << templatePrefix + 'auto ' + tclass + '::GetPtr() -> Ptr { return Ptr(this); }'
                    self.defs << templatePrefix + 'auto ' + tclass + '::GetPtr() const -> ConstPtr { return ConstPtr(this); }'
                if not cls.isError:
                    errorExtra = ''
                elif errorObject:
                    errorExtra = '\tfriend class ' + errorObject + ';\n\tfriend class maxon::ResultBase<' + cls.refClass + '>;\n\t' \
                        + cls.refClass + '(maxon::ERROR_OK) { }\n'
                else:
                    errorExtra = '\t' + cls.refClass + '(maxon::ERROR_OK) { }\n'
                if buildRefClass:
                    self.decls << '/// ' + cls.refClass + ' is the reference class of ' + cls.name + '.'
                    if cls.doc:
                        self.decls << '///'
                        self.decls.code += cls.doc
                    base = tclass + '::Hxx1::' + ('template ' if genericOnlyRefPostfix else '') + 'Reference' + genericOnlyRefPostfix
                    self.decls << genericPrefix + 'class ' + cls.refClass + ' : public ' + base << '{' << 'public:'
                    self.decls.code += errorExtra

                    if cls.isError and cls.name != 'ErrorInterface':
                        self.decls << 'PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(' + cls.refClass + ', typename ' + base + ');'
                        self.decls << 'template <typename D> ' + cls.refClass + '(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<' + cls.refClass + ', D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }'
                        self.decls << 'template <typename ARG1, typename... ARGS> ' + cls.refClass + '(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<' + cls.refClass + ', ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }'
                        self.decls << 'private:' << cls.refClass + '() = default;'
                    else:
                        if cls.refKind == Class.REF_UNIQUE:
                            self.decls << 'MAXON_UNIQUE_REFERENCE_CONSTRUCTORS(' + cls.refClass + ', typename ' + base + ');'
                        else:
                            self.decls << 'MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(' + cls.refClass + ', typename ' + base + ');'
                        if cls.refKind == Class.REF:
                            self.decls << 'using ConstPtr = typename ' + tclass + '::ConstPtr;'
                    if genericPrefix:
                        self.decls << 'struct Instantiation' << '{' \
                            << 'template <template <typename> class MAP> using Map = ' + cls.refClass + '<' + ', '.join(templateParamToStrMap(x) for x in generic.params) + '>;' << '};'
                    self.decls << '};' << ''

            self.decls << self.signalDecl

            if cls.parseAnnotation('dependencies', True) != False and not cls.template:
                self.writeInterfaceUse(cls, None)

            regs = self.defs if cls.interface == Class.VIRTUAL and cls.template else self.regs
            if hasNonvirtual:
                useUnresolved = not cls.parseAnnotation('noUnresolved', False)
                if useUnresolved:
                    regs << 'MAXON_WARNING_PUSH'
                    regs << 'MAXON_WARNING_DISABLE_DEPRECATED'
                    regs << templatePrefix + 'class ' + tclass + '::Hxx2::Unresolved : public ' + (cls.bases[0][0] + '::Hxx2::Unresolved' if cls.derived else cls.name) << '{' << 'public:'
                    if cls.derived:
                        regs << 'operator const ' + cls.name + '&() const { return *static_cast<const ' + cls.name + '*>(static_cast<const BaseInterface*>(this)); }'
                        regs << 'operator ' + cls.name + '&() { return *static_cast<' + cls.name + '*>(static_cast<BaseInterface*>(this)); }'
                    regs << self.unresolvedFunctions
                    regs << '};'
                    regs << 'MAXON_WARNING_POP'
                    regs << '#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED'
                    regs << templatePrefix + 'const maxon::NULL_RETURN_TYPE ' + tclass + '::' + ('Hxx2::Static' if cls.interface == Class.VIRTUAL else '') + 'MTable::_returnTypes[] = ' << '{'
                    regs << self.unresolvedRetType
                    regs << 'maxon::NULL_RETURN_TYPE::OTHER' << '};' << '#endif'
                regs << templatePrefix + 'maxon::Bool ' + tclass + '::' + mtableCls + '::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, ' + mtableCls + '* tbl)' << '{'
                if useUnresolved:
                    regs << self.unresolvedInit
                    regs << '#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED' << 'return assembler(&' + ('_staticInterface' if cls.interface == Class.VIRTUAL else '_interface') + ', (maxon::Char*) tbl' + superSize + ', _returnTypes, SIZEOF(' + ('Static' if cls.interface == Class.VIRTUAL else '') + 'MTable) / SIZEOF(void*));' \
                        << '#else' << 'return true;' << '#endif'
                else:
                    regs << 'return true;'
                regs << '}'
            if cls.interface == Class.NONVIRTUAL:
                self.regs << 'MAXON_INTERFACE_REGISTER(' + cls.name + ', ' + cls.id + ', ' + ('MAXON_INTERFACE_REGISTER_NULLIMPL(' + cls.name + ')' if cls.parseAnnotation('nullimpl', False) else 'nullptr') + ');'

            if cls.interface == Class.VIRTUAL:
                superCnt = 0
                reg = '';
                if cls.singleImpl:
                    regs << templatePrefix + 'typename ' + tclass + '::MTable::NVMTable ' + tclass + '::MTable::NVMTable::_instance;'
                for b, g in cls.baseInterfaces:
                    reg += ', (&' + b + '::_interface)'
                    superCnt += 1
                if superCnt == 1:
                    rt = 'PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE'
                    postfix = ''
                else:
                    rt = 'PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL'
                    reg += ', nullptr'
                    postfix = cls.name + ', ' + maxonComma(templatePostfix) + ', '
                if cls.singleImpl:
                    rt += '_SINGLE_IMPL'
                regId = 'PrivateGetInstantiationId((' + cls.name + '*) nullptr)' if cls.template else cls.id
                obfuscate = self.args.obfuscate or cls.parseAnnotation('obfuscate', False)
                regQName = 'PrivateGetInstantiationSourceName((' + cls.name + '*) nullptr)' if cls.template else '"' + (hashString(qname) if obfuscate else qname) + '"'
                regs << templatePrefix + 'const maxon::Char* const ' + tclass + '::MTable::_ids = ' << self.ids << '"";'
                regs << rt + '(' + maxonComma(tclass) + ', ' + postfix + maxonComma(templatePrefix) + ', ' + regId + ', ' + regQName + reg + ');'
                if self.staticIds:
                    regs << templatePrefix + 'const maxon::Char* const ' + tclass + '::Hxx2::StaticMTable::_ids = ' << self.staticIds << '"";'
                    regs << 'PRIVATE_MAXON_INTERFACE_REGISTER_STATIC(' + maxonComma(tclass) + ', ' + maxonComma(templatePrefix) + ', ' + regId + ');'

            if self.nullRets and not templatePrefix:
                self.regs << 'template <typename DUMMY> maxon::Int ' + tclass + '::PrivateInstantiateNullValueHelper()' << '{'
                self.regs << 'return 0'
                for t in sorted(self.nullRets):
                    self.regs << '| maxon::details::InstantiateNullReturnValue<' + t + '>(OVERLOAD_MAX_RANK)'
                self.regs << ';' << '}'
                self.instantiations += '\t| ' + str(cls) + '::PrivateInstantiateNullValueHelper<maxon::Int>()\n'

            if errorObject and cls.parseAnnotation('refclass', True) == True:
                en = cls.id.replace('.interface.', '.error.').replace('error"', '"')
                self.decls << 'MAXON_DECLARATION(' + cls.refClass + ', ' + errorObject + ', ' + en + ');'
                self.addObject(errorObject, errorObject, en, cls.owner)

        if cls.interface and cls.interface != Class.SIMPLE_VIRTUAL:
            dest = self.defs if cls.template else self.reflection
            dest << cls.owner
            if cls.interface == Class.VIRTUAL:
                if not cls.template:
                    self.writeInterfaceDefinition(cls, '')
                dest << '#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)'
                proxy = tclass + '::ProxyComponent'
                dest << templatePrefix + 'class ' + proxy + ' : public maxon::Component<ProxyComponent, ' + cls.name + '>' << '{'
                dest << 'MAXON_COMPONENT();' << 'public:' << 'using typename maxon::Component<ProxyComponent, ' + cls.name + '>::_Wrapper;'
                dest << 'static const maxon::Bool PROXY = true;' << 'maxon::reflection::ProxyHandler _handler;'
                dest << self.proxyFunctions
                dest << '};'
                dest << self.proxyFunctionPointers
                dest << 'PRIVATE_MAXON_COMPONENT_REGISTER(' + maxonComma(proxy) + ', ' + maxonComma(templatePrefix) + ', typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());'
                dest << '#endif'
                if cls.hasStaticMethods:
                    dest << '#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)'
                    dest << templatePrefix + 'static maxon::Result<void> RegisterReflection_' + cls.name + '_Static(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)'
                    dest << '{'
                    refl = self.staticReflectionFunctions.get()
                    if refl:
                        dest << 'maxon::reflection::FunctionInfo functions[] =' << '{' << self.staticReflectionFunctions << '};'
                    dest << 'return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&' + tclass + '::_staticInterface), ' \
                        + ('maxon::ToBlock(functions)' if refl else 'maxon::Block<maxon::reflection::FunctionInfo>()') + ');'
                    dest << '}'
                    dest << '#endif'
            dest << '#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION' + ('' if cls.interface == Class.VIRTUAL else '_NONVIRTUAL') + ')'
            dest << templatePrefix + 'static maxon::Result<void> RegisterReflection_' + cls.name + '(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)'
            dest << '{'
            refl = self.reflectionFunctions.get()
            if refl:
                dest << 'maxon::reflection::FunctionInfo functions[] =' << '{' << self.reflectionFunctions << '};'
            dest << 'return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&' + tclass + '::_interface), ' \
                + ('maxon::ToBlock(functions)' if refl else 'maxon::Block<maxon::reflection::FunctionInfo>()') + ');'
            dest << '}'
            dest << '#endif'
            if not cls.template:
                self.writeInterfaceReflection(cls, '', cls.interface, '')
                if cls.interface == Class.VIRTUAL and cls.hasStaticMethods:
                    self.writeInterfaceReflection(cls, '', Class.NONVIRTUAL, '_Static')

        if cls.interface and cls.parseAnnotation('export_js', False) == True:
            interfaceName = cls.name
            if cls and cls.baseInterfaces:
                parentInterfaceName = cls.baseInterfaces[0][0]
            else:
                parentInterfaceName = ""

            #export the RPC Implementation classes
            outIncludes = ""
            outInit = ""
            outFree = ""
            outObservables = ""
            out = ""

            observables = 0

            node = cls
            while node.owner:
                node = node.owner

            includeFile = node.name.pos.file;
            includeFile = includeFile[includeFile.index("maxon"):]
            includeFile = includeFile.replace('\\', '/');
            outIncludes += "#include \"" + includeFile + "\"\n"
            outIncludes += "#include \"maxon/rpc_component.h\"\n"
            out += "namespace maxon\n"
            out += "{\n"
            out += "//----------------------------------------------------------------------------------------\n"
            out += "maxon.frameworks.drawing_framework." + interfaceName + " = (\n"
            out += "\tfunction() {\n"
            out += "\t\t" + interfaceName + ".prototype = Object.create(maxon.frameworks.drawing_framework." + parentInterfaceName + ".prototype);\n"
            out += "\t\tfunction " + interfaceName + "(rect) {\n"
            out += "\t\t\tmaxon.frameworks.drawing_framework." + parentInterfaceName + ".call(this, rect);\n"
            out += "\t\t\t\n"
            out += "\t\t\tthis.scope = \"maxon.frameworks.drawing_framework." + interfaceName + "\";\n"
            out += "\t\t\tthis.ext.push(this.scope);\n"
            out += "\t\t\t\n"
            out += "\t\t\treturn this;\n"
            out += "\t\t};\n"
            out += "\t\t" + interfaceName + ".__in_out = {\n"
            out += "\t\t\t\"in\" : null,\n"
            out += "\t\t\t\"out\" : null\n"
            out += "\t\t};\n"

            def ConvertJSType(realType):
                if not realType:
                    return "";
                realType = realType.replace("const", "");
                realType = realType.replace("&", "");
                realType = realType.replace(" ", "");

                if realType == "Float":
                    realType = "Number"
                elif realType == "Int":
                    realType = "Number"
                elif realType == "Bool":
                    realType = "Boolean"
                else:
                    realType = "maxon." + realType
                return realType

            for decl in cls.children:
                if isinstance(decl, Function):
                    methodName = decl.qname(decl.owner, "::")

                    if not decl.observable:
                        #print(methodName, decl.observable)
                        # simple function with Result<void>
                        paramArgs = ""
                        inputArgs = ""
                        outputArgs = ""
                        for param in decl.params:
                            paramArgs += param.name + ", "
                            realType = ConvertJSType(param.type);

                            if param.input:
                                inputArgs += "\t\t\t\t\"" + param.name + "\": " + realType + ",\n"
                            if param.output:
                                outputArgs += "\t\t\t\t\"" + param.name + "\": " + realType + ",\n"
                        paramArgs = paramArgs[: -2]
                        inputArgs = inputArgs[: -2]
                        if inputArgs:
                            inputArgs = "{\n" + inputArgs + "\n\t\t\t},"
                        else:
                            inputArgs = "null,"

                        if decl.result != "void":
                            outputArgs += "\t\t\t\t\"result\": " + ConvertJSType(decl.result) + ",\n"

                        outputArgs = outputArgs[: -2]
                        if outputArgs:
                            outputArgs = "{\n\t\t\t" + outputArgs + "\n\t\t\t}"
                        else:
                           outputArgs = "null"

                        out += "\t\t" + interfaceName + ".prototype." + methodName + " = function(" + paramArgs + ") {\n"
                        methodLowerName = methodName
                        methodLowerName = methodLowerName[0].lower() + methodLowerName[1:]
                        out += "\t\t\treturn this._self." + methodLowerName + "(" + paramArgs + ");\n"
                        out += "\t\t};\n"
                        out += "\t\t" + interfaceName + ".prototype." + methodName + ".__in_out = {\n"
                        out += "\t\t\t\"in\" : " + inputArgs +"\n"
                        out += "\t\t\t\"out\" : " + outputArgs +"\n"
                        out += "\t\t};\n"

            out += "return " + interfaceName + ";\n\n"
            out += "})();\n"
            out += "// link\n"
            out += "//////////////////////////////////////////////////////////////////////////////////////////\n"
            out += "maxon." + interfaceName + " = maxon.frameworks.drawing_framework." + interfaceName + ";\n"
            out += "maxon.classes.push(\"maxon.frameworks.drawing_framework." + interfaceName + "\");\n"

            out = outIncludes + "\n" + out;

            rpchxx = os.path.join(self.framework, 'js')
            makeDir(rpchxx)
            dummy, basename = os.path.split(self.header)
            basename, dummy = os.path.splitext(basename)
            rpchxx = os.path.join(rpchxx, basename + '.js')
            writeToFile(rpchxx, out)

    def processClassOrNamespaceDeclaration(self, decl):
        ns = decl.owner
        while not isinstance(ns, Namespace):
            ns = ns.owner
        name = decl.qname(ns, '::')
        if isinstance(decl, Enum) and decl.registered:
            self.regs << ns
            enumProxyNamespace = 'enum' + str(decl.line)
            self.regs << 'namespace ' + enumProxyNamespace + ' { ' + decl.code + '; }'
            extra = '' if isinstance(decl.owner, Namespace) else 'void*'
            proto = 'maxon::String PrivateToString_' + decl.name + str(decl.line) + '(std::underlying_type<' + enumProxyNamespace + '::' + decl.name + '>::type x, const maxon::FormatStatement* fmt' + (extra and ', ') + extra + ')'
            if self.cpp or decl.owner.template:
                self.regs << proto + ';'
            self.regs << proto << '{'
            names = '"' + ''.join(v.name + '\\0' for v in decl.children if isinstance(v, EnumValue)) + '"'
            enums = ', '.join('(maxon::UInt64) ' + enumProxyNamespace + '::' + decl.name + '::' + v.name for v in decl.children if isinstance(v, EnumValue))
            enumvalues = 'const maxon::UInt64 values[] = {' + enums + '}' if enums else 'const maxon::UInt64* values = nullptr'
            self.regs << enumvalues + ';'
            self.regs << 'return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "' + name + '", SIZEOF(x), ' + boolStr(decl.flags) + ', values, ' + names + ', fmt);' << '}'
            if decl.id:
                enums = ', '.join('(maxon::UInt64) ' + name + '::' + v.name for v in decl.children if isinstance(v, EnumValue))
                enumvalues = 'const maxon::UInt64 values[] = {' + enums + '}' if enums else 'const maxon::UInt64* values = nullptr'
                self.addObject('DT_' + decl.name, name, decl.id, ns, 3)
                self.reflection << ns
                self.reflection << '#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES'
                self.reflection << 'PRIVATE_MAXON_DATATYPE_REGISTER_ENUM(' + decl.name + ', ' + decl.id + ', SIZEOF(' + name + '), ' + \
                    boolStr(decl.flags) + ', ' + names + ', ' + enumvalues + ')'
                self.reflection << '#endif'
        elif isinstance(decl, InterfaceInstantiation):
            cls = decl.interface
            self.defs << cls.owner
            self.regs << cls.owner
            self.reflection << cls.owner
            self.writeInterfaceUse(cls, decl.instantiation)
            self.writeInterfaceDefinition(cls, decl.instantiation)
            self.writeInterfaceReflection(cls, decl.instantiation, cls.interface, '')

            self.decls << cls.owner
            
            self.regs << 'constexpr inline const maxon::Char* PrivateGetInstantiationId(' + decl.instantiation + '*) { return ' + cls.id[:-1] + '.' + decl.id[1:] + '; }'
            self.regs << 'constexpr inline const maxon::Char* PrivateGetInstantiationSourceName(' + decl.instantiation + '*) { return "' + cls.qname() + decl.instantiation[decl.instantiation.find('<'):] + '"; }'

            self.decls << 'extern template maxon::InterfaceReference ' + decl.instantiation + '::_interface;'
            self.regs << 'template maxon::InterfaceReference ' + decl.instantiation + '::_interface;'
            if cls.singleImpl:
                self.decls << 'extern template maxon::NonvirtualMTableReference ' + decl.instantiation + '::_nonvirtualMTable;'
                self.regs << 'template maxon::NonvirtualMTableReference ' + decl.instantiation + '::_nonvirtualMTable;'
                self.defs << 'extern template ' + decl.instantiation + '::MTable::NVMTable ' + decl.instantiation + '::MTable::NVMTable::_instance;'
                self.regs << 'template ' + decl.instantiation + '::MTable::NVMTable ' + decl.instantiation + '::MTable::NVMTable::_instance;'
            if cls.hasStaticMethods:
                self.decls << 'extern template maxon::NonvirtualInterfaceReference ' + decl.instantiation + '::_staticInterface;'
                self.regs << 'template maxon::NonvirtualInterfaceReference ' + decl.instantiation + '::_staticInterface;'
                self.defs << 'extern template ' + decl.instantiation + '::Hxx2::StaticMTable ' + decl.instantiation + '::Hxx2::StaticMTable::_instance;'
                self.regs << 'template ' + decl.instantiation + '::Hxx2::StaticMTable ' + decl.instantiation + '::Hxx2::StaticMTable::_instance;'
        elif decl.kind in ['MAXON_DECLARATION', 'MAXON_DECLARATION_CLASS']:
            self.addObject(decl.name, name, decl.id, ns)

    def addFunction(self, fn):
        id = fn.getAnnotation('reflection', None)
        if not id:
            return
        if self.cpp:
            self.errors.append(id.pos, 'The reflection annotation can only be used in header files.')
            return
        paramNames = '"' + ''.join([p.name + '\\0' for p in fn.params]) + '"'
        inOut = getInOutBits(fn)
        self.reflection << fn.owner
        self.reflection << '#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION'
        fnType = ', '.join([p.type for p in fn.params])
        hash = intToHex64(intHashCode(fn.retType + '#' + fnType))[2:]
        regName = fn.qname(None, '_') + '_' + hash
        fnType = fn.retType + '(*)(' + fnType + ')'
        self.reflection << 'static maxon::Result<void> RegisterReflection_' + regName + '(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)'
        self.reflection << '{' << 'maxon::reflection::FunctionInfo functions[] = {'
        self.reflection << '\tmaxon::reflection::GetFunctionInfo(' + id + ' "@' + hash + '", maxon::reflection::Member::KIND::FUNCTION, ' + paramNames + ', ' + str(inOut) + 'LL, (' + fnType + ') &' + fn.name + ')\n\t\t};'
        self.reflection << 'return callback(cls, nullptr, maxon::ToBlock(functions));' << '}'
        s = 'static maxon::reflection::ContainerInfo g_reflection_' + regName + '(nullptr, nullptr, '
        self.reflection << s + '&RegisterReflection_' + regName + ', &PRIVATE_MAXON_MODULE);'
        self.reflection << '#endif'
        self.reflection.get()

    def processGlobalNamespace(self, root):
        for decl in root.declarations: # we don't use the namespace hierarchy as its traversal doesn't follow the source code order; root.declarations contains all declarations at namespace level in the correct order
            ns = decl.owner
            if isinstance(decl, Class):
                self.processClass(decl)
            elif isinstance(decl, Function):
                self.addFunction(decl)
            elif isinstance(decl, Declaration):
                if decl.kind == 'MAXON_DATATYPE':
                    self.regs << ns << 'PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_' + decl.name + ',, ' + decl.id + ');'
                elif decl.kind == 'MAXON_INTERNED_ID':
                    self.regs << ns << 'maxon::InternedId ' + decl.name + ';' << 'static maxon::InternedIdInitializer g_iid_' + decl.name \
                        + '(&' + decl.name + ', ' + decl.id + ', &PRIVATE_MAXON_MODULE);'
                elif decl.kind == 'MAXON_GRAPH_ATTRIBUTE':
                    self.regs << ns << 'maxon::InternedId ' + decl.name + '::_id;' << 'maxon::InternedIdInitializer ' + decl.name \
                        + '::_idInit(&_id, ' + decl.id + ', &PRIVATE_MAXON_MODULE);'
                elif decl.kind == 'MAXON_ATTRIBUTE':
                    self.regs << ns << decl.name + '_PrivateAttribute ' + decl.name + ';'
                elif decl.kind == 'MAXON_RESOURCE_DATABASE_SCOPE':
                    self.defs << ns
                elif isinstance(decl, Namespace):
                    if decl.containsResourceId:
                        guard = 'PRIVATE_MAXON_GUARD_' + decl.qname(None, '_')
                        self.decls << decl << '#ifndef ' + guard << '#define ' + guard
                        base = decl.owner.name + '::RESTRICT' if decl.owner.containsResourceId else 'maxon::RESTRICT'
                        self.decls << 'class RESTRICT : public ' + base + ' { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);'
                        self.decls << '#endif'
                    if decl.registry:
                        self.regs << ns << 'MAXON_REGISTRY_REGISTER(' + decl.name + ');'
                        self.reflection << ns
                        self.reflection << '#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES'
                        self.reflection << 'PRIVATE_MAXON_REGISTRY_DEFINE(' + decl.name + ');'
                        self.reflection << '#endif'
                else:
                    self.processClassOrNamespaceDeclaration(decl)
            elif isinstance(decl, Directive):
                if self.decls.root:
                    self.decls.beginDirective()
                    if self.decls.root.isAncestorOfOrSame(ns):
                        self.decls << ns
                    else:
                        self.decls << self.decls.root
                    self.decls.endDirective()
                if self.defs.root:
                    self.defs.beginDirective()
                    if self.defs.root.isAncestorOfOrSame(ns):
                        self.defs << ns
                    else:
                        self.defs << self.defs.root
                    self.defs.endDirective()
                addDirective(decl.code, None, (self.decls, self.defs))
                addDirective(decl.code, ns, (self.regs, self.reflection))


def process(args, file, root):
    dummy, basename = os.path.split(file)
    if basename == 'register.h' and args.projectId == 'net.maxon.core.framework':
        # Don't handle register.h of core.framework as the code below would remove register1.hxx and register2.hxx (which have a different meaning in this case).
        return None
    basename, ext = os.path.splitext(basename)
    cpp = ext == '.cpp'
    if not cpp and ext != '.h':
        return None
    if cpp:
        basename = basename + '_cpp'

    hxx = os.path.join(args.generated, 'hxx')
    makeDir(hxx)
    hxx1 = os.path.join(hxx, basename + '1.hxx')
    hxx2 = os.path.join(hxx, basename + '2.hxx')
    reg = os.path.join(hxx, '_register_' + basename + '.hxx')
    inc = os.path.join(hxx, '_include_' + basename + '.hxx')
    refl = os.path.join(hxx, '_reflection_' + basename + '.hxx')
    default = os.path.join(hxx, '_default_' + basename + '.hxx')
    decorator = os.path.join(hxx, '_decorator_' + basename + '.hxx')

    if root:
        gen = Generator(args, file, cpp, root)
        gen.processGlobalNamespace(root)

        if gen.errors.list:
            raise IOError(''.join(x + '\n' for x in gen.errors.list))

        needHxx12 = not (gen.defs.hasOnlyDirectiveCode() and gen.decls.hasOnlyDirectiveCode())
        if needHxx12 or not (gen.regs.hasOnlyDirectiveCode() and gen.reflection.hasOnlyDirectiveCode()):
            if needHxx12:
                if not root.hxx1:
                    raise IOError(str(root.name.pos) + ': error: #include "' + basename + '1.hxx" missing.')
                if not root.hxx2:
                    raise IOError(str(root.name.pos) + ': error: #include "' + basename + '2.hxx" missing.')
                decls = gen.decls.get()
                if not decls:
                    decls = '\n'
                defs = gen.defs.get()
                defs = add_gcc_pragma(defs)
                writeToFile(hxx1, decls)
                writeToFile(hxx2, doxygenSkip(defs))
            else:
                removeFile(hxx1)
                removeFile(hxx2)
            regs = gen.regs.get()
            reflection = gen.reflection.get()
            if not reflection:
                reflection = '\n'

            if gen.instantiations:
                regs += 'static maxon::details::ForceEvaluation s_forceEval_' + basename + '(0\n' + gen.instantiations + ');\n'
            i = '' if cpp else '#include "' + file + '"\n'
            for c in root.preprocessorConditions:
                regs = '#if ' + c + '\n' + regs + '#endif\n'
                i = '#if ' + c + '\n' + i + '#endif\n'
                reflection = '#if ' + c + '\n' + reflection + '#endif\n'
            writeToFile(reg, regs)
            writeToFile(inc, i)
            writeToFile(refl, reflection)
            if not gen.defaults.hasOnlyDirectiveCode():
                writeToFile(default, '// This file contains default implementations for the interfaces of ' + basename + ext + '. They are intended for copy&paste usage only.\n' + gen.defaults.get())
            if not gen.decorators.hasOnlyDirectiveCode():
                writeToFile(decorator, '// This file contains decorator implementations for the interfaces of ' + basename + ext + '. They are intended for copy&paste usage only.\n' + gen.decorators.get())
        else:
            removeFile(hxx1)
            removeFile(hxx2)
            removeFile(reg)
            removeFile(inc)
            removeFile(refl)
            removeFile(default)
            removeFile(decorator)

    if os.path.isfile(inc):
        return basename
    return None


def processesFilesWithError():
    return False


def done(args, results, sources, msg, err):
    if err:
        return (msg, err)
    hxx = os.path.join(args.generated, 'hxx')
    makeDir(hxx)

    def writeRegisterFile(i, results):
        registerA = ''
        registerB = ''
        reflectionIncludes = ''
        for basename in results:
            if basename and basename != 'register':
                registerA += '#include "_include_' + basename + '.hxx"\n'
                registerB += '#include "_register_' + basename + '.hxx"\n'
                reflectionIncludes += '#include "_reflection_' + basename + '.hxx"\n'
        haveHxx = registerA
        registerA += '\n#ifdef PRIVATE_MAXON_REGISTRATION_FRAMEWORK\n\n' + reflectionIncludes + '\n#else\n'
        defines = '#define PRIVATE_MAXON_REGISTRATION_UNIT\n\n'
        if i != 0:
            defines += '#define PRIVATE_MAXON_EXTRA_REGISTRATION_UNIT\n'

        if haveHxx:
            registerA += '\nMAXON_NULL_VALUE_INCOMPLETE_GET_DEFINITION;\n\n'
        setUsedFrameworks = args.frameworks and i == 0 and args.projectType != 'app'
        if haveHxx or args.projectType != 'lib' or setUsedFrameworks:
            registerA = '\n#ifndef PRIVATE_MAXON_REGISTRATION_FRAMEWORK\n#define PRIVATE_MAXON_DEFINE_MODULE_INFO_FLAGS ' + ('| EntityBase::FLAGS::PUBLIC' if args.publicframework else '') + '\n#include "maxon/register.h"\n#endif\n\n' + registerA
        if setUsedFrameworks:
            # add indirectly used frameworks
            visited = set()
            visited.add(args.directory)
            frameworks = set()
            for fwDir in usedFrameworks(args, args.directory, True, visited):
                frameworks.add(getFrameworkId(args, os.path.basename(fwDir)))
            registerB += '\nstatic maxon::Id g_usedFrameworks[] = {' + ', '.join(['maxon::Id("' + f + '")' for f in sorted(frameworks)]) + '};\n'
            registerB += 'static maxon::SetUsedFrameworks g_setUsedFrameworks(PRIVATE_MAXON_MODULE, g_usedFrameworks);\n'

        base = 'register'
        if i > 0:
            base += str(i)
        writeToFile(os.path.join(hxx, base + '.cpp'), '#include "' + base + '.hxx"\n')
        writeToFile(os.path.join(hxx, base + '.hxx'), '/*\n\tDON\'T EDIT THIS FILE!\n\tIt has been created and is updated automatically by the interface processor.\n' + \
             '\tIt has to be included by the ' + base + '.cpp file of the project in order for the automatic registration to work.\n*/\n' + defines + registerA + registerB + '\n#endif\n')
        return base


    resultcnt = 0
    for basename in results:
        if basename:
            resultcnt += 1

    # since core.framework is the framework most other frameworks or modules are dependent on, this can accept up to (REGISTER_CPP_COUNT * 2) modules
    if args.splitRegisterCpps is True and args.projectId == 'net.maxon.core.framework':
        REGISTER_CPP_COUNT = 8
    elif args.splitRegisterCpps is True and args.projectType == 'lib':
        REGISTER_CPP_COUNT = 4
    else:
        REGISTER_CPP_COUNT = 1

    # Since we have a static amount of register files, no matter if they have a content or not,
    # we don't have to take care of deleting unused register files, because there aren't any.
    # We also go with a static amount because otherwise the developer has to execute "Update Projects"
    # once a new register file is added. We don't want to have this kind of workflow.

    splitResults = [list() for x in range(REGISTER_CPP_COUNT)]

    i = 0
    for basename in results:
        if basename:
            splitResults[i % REGISTER_CPP_COUNT].append(basename)
            i += 1

    createdRegisterFiles = []
    registerHxxList = ''
    for i, splitResult in enumerate(splitResults):
        base = writeRegisterFile(i, splitResult)
        createdRegisterFiles.append(base + '.hxx')
        createdRegisterFiles.append(base + '.cpp')
        registerHxxList += '#include "' + base + '.hxx"\n'

    registrationHxx = 'registration_' + args.mangledProjectId + '.hxx'
    writeToFile(os.path.join(hxx, registrationHxx),
                '// Include this file in a cpp file of a single module to add the framework registration of ' + args.projectId + ' to the module.\n\n'
                + '#define PRIVATE_MAXON_REGISTRATION_FRAMEWORK\n#if !(defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION) && defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL))\n'
                + '#include "maxon/reflection_registration.h"\n#else\n#include "maxon/apibase.h"\n#endif\n#undef MAXON_DEPENDENCY_ENABLE\n' + registerHxxList)
    createdRegisterFiles.append(registrationHxx)

    fwr = args.frameworkRegistration
    if args.projectType == 'dll':
        fwr += ';'
        if args.moduleRegistration:
            fwr += args.projectId

    if fwr:
        for file, prologue in [('interface_registration.cpp', '#define MAXON_REGISTRATION_EXCLUDE_REFLECTION\n#define MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL\n'),
                               ('reflection_registration.cpp', '#define MAXON_REGISTRATION_EXCLUDE_INTERFACES\n#define MAXON_REGISTRATION_EXCLUDE_REFLECTION\n'),
                               ('reflection_virtual_registration.cpp', '#define MAXON_REGISTRATION_EXCLUDE_INTERFACES\n#define MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL\n')]:
            reg = prologue
            if file == 'interface_registration.cpp' or args.frameworkRegistrationIncludeReflection:
                for f in fwr.split(';'):
                    f = f.strip()
                    if f and f != 'true':
                        fwId = getFrameworkId(args, f)
                        reg += '#include "registration_' + fwId.replace('.', '_').replace('-', '_') + '.hxx"\n'
            writeToFile(os.path.join(hxx, file), reg)
            createdRegisterFiles.append(file)

    # scan hxx directory for hxx files to which no original header file exists (i.e., the original header file has been moved or deleted)
    for file in os.listdir(hxx):
        if file not in createdRegisterFiles:
            if not file.endswith('.hxx'):
                removeFile(os.path.join(hxx, file))
            else:
                f = file[:-4]
                if f.startswith('_include_'):
                    f = f[9:]
                elif f.startswith('_register_'):
                    f = f[10:]
                elif f.startswith('_reflection_'):
                    f = f[12:]
                elif f.startswith('_default_'):
                    f = f[9:]
                elif f.startswith('_decorator_'):
                    f = f[11:]
                elif f.endswith('1') or f.endswith('2'):
                    f = f[:-1]
                elif f.endswith('.rpc'):
                    f = f[:-4]
                elif f.endswith('.rpc_handler'):
                    f = f[:-12]
                if f not in results:
                    removeFile(os.path.join(hxx, file))

    return (msg, err)
