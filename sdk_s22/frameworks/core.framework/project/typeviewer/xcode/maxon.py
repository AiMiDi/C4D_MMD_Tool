import lldb
import time
import sys

py3 = sys.version_info >= (3, 0)

unichr = chr if py3 else unichr


# maxon::CString
def CString(valueObject, dictionary):

    error = lldb.SBError()

    sbtype = valueObject.GetType()

    voidPtrType = sbtype.GetBasicType(lldb.eBasicTypeVoid).GetPointerType()
    # int32Type = sbtype.GetBasicType(lldb.eBasicTypeInt)
    intType = sbtype.GetBasicType(lldb.eBasicTypeLong)
    charPtrType = sbtype.GetBasicType(lldb.eBasicTypeChar).GetPointerType()

    cnt = 0
    capacity = 0
    strRef = valueObject.CreateChildAtOffset("strRef", 0, voidPtrType)

    ptr = None
    objPtr = strRef.GetValueAsUnsigned(0)
    if objPtr != 0:
        ptr = valueObject.CreateValueFromAddress("ptr", objPtr, charPtrType)
        objPtr = objPtr + 8
        cnt = valueObject.CreateValueFromAddress("cnt", objPtr, intType).GetValueAsSigned()
        objPtr = objPtr + 8
        capacity = valueObject.CreateValueFromAddress("capacity", objPtr, intType).GetValueAsSigned()

    # Check for garbage values (this might be called on an uninitialized CString).
    # If capacity is a very large value something might be wrong (and it must not be smaller than cnt).
    if capacity > 1073741824:
        cnt = 0

    if cnt > capacity:
        cnt = 0

    # Limit number of characters (this might be called on an uninitialized CString).
    displayCnt = cnt
    if cnt > 128:
        displayCnt = 128

    # Assume CString is utf8
    if ptr:
        data = ptr.GetPointeeData(0, displayCnt)
        if data:
            return b'\x22' + data.GetString(error, 0) + b'\x22' + " (%i @ %s)" % (cnt, hex(ptr.GetValueAsUnsigned()))

    return b'\x22' + b'\x22'


# maxon::String
def String(valueObject, dictionary):

    error = lldb.SBError()

    sbtype = valueObject.GetType()

    voidPtrType = sbtype.GetBasicType(lldb.eBasicTypeVoid).GetPointerType()
    int8Type = sbtype.GetBasicType(lldb.eBasicTypeChar)
    int16Type = sbtype.GetBasicType(lldb.eBasicTypeShort)
    int32Type = sbtype.GetBasicType(lldb.eBasicTypeInt)
    intType = sbtype.GetBasicType(lldb.eBasicTypeLong)
    uCharPtrType = sbtype.GetBasicType(lldb.eBasicTypeUnsignedChar).GetPointerType()
    utf16CharPtrType = sbtype.GetBasicType(lldb.eBasicTypeChar16).GetPointerType()
    utf32CharPtrType = sbtype.GetBasicType(lldb.eBasicTypeChar32).GetPointerType()

    cnt = 0
    capacity = 0
    characterEncoding = 0
    characterShift = 0
    pad0 = 0
    pad1 = 0
    strRef = valueObject.CreateChildAtOffset("strRef", 0, voidPtrType)

    objPtr = strRef.GetValueAsUnsigned(0)
    if objPtr != 0:
        # For R16
        ptr = valueObject.CreateValueFromAddress("ptr", objPtr, utf16CharPtrType)

        # For R17
        characterEncoding = valueObject.CreateValueFromAddress("ptr", objPtr, int8Type).GetValueAsSigned()
        objPtr = objPtr + 1
        characterShift = valueObject.CreateValueFromAddress("ptr", objPtr, int8Type).GetValueAsSigned()
        objPtr = objPtr + 1
        pad0 = valueObject.CreateValueFromAddress("ptr", objPtr, int16Type).GetValueAsSigned()
        objPtr = objPtr + 2
        pad1 = valueObject.CreateValueFromAddress("ptr", objPtr, int32Type).GetValueAsSigned()
        objPtr = objPtr + 4

        # Check for new padding from R17 on:
        if pad1 == -1 and pad0 == -1:
            # Skip the FixedBufferAllocator
            objPtr = objPtr + 16
            # Select the pointer type depending on the shift value.
            if characterShift == 0:
                ptr = valueObject.CreateValueFromAddress("ptr", objPtr, uCharPtrType)
            elif characterShift == 1:
                ptr = valueObject.CreateValueFromAddress("ptr", objPtr, utf16CharPtrType)
            elif characterShift == 2:
                ptr = valueObject.CreateValueFromAddress("ptr", objPtr, utf32CharPtrType)
            objPtr = objPtr + 8
        else:
            characterShift = 0
            characterEncoding = 0

        cnt = valueObject.CreateValueFromAddress("cnt", objPtr, intType).GetValueAsSigned()
        objPtr = objPtr + 8
        capacity = valueObject.CreateValueFromAddress("capacity", objPtr, intType).GetValueAsSigned()

    # Check for garbage values (this might be called on an uninitialized String).
    # If capacity is a very large value something might be wrong (and it must not be smaller than cnt).
    if capacity > 1073741824:
        cnt = 0

    if cnt > capacity:
        cnt = 0

    # Convert from bytes to number of characters.
    cnt = cnt >> characterShift

    # Limit number of characters (this might be called on an uninitialized String).
    displayCnt = cnt
    if cnt > 128:
        displayCnt = 128

    s = u'"'
    for i in range(0, displayCnt):
        data_val = ptr.GetPointeeData(i, 1)
        if characterEncoding == 0:
            newchar = data_val.GetUnsignedInt16(error, 0)
        elif characterEncoding == 1:
            newchar = data_val.GetUnsignedInt32(error, 0)
        else:
            newchar = data_val.GetUnsignedInt8(error, 0)

        # size = data_val.GetByteSize()
        if newchar > 0xffff:
            newchar -= 0x10000
            s += unichr((newchar >> 10) + 0xd800)
            newchar = (newchar & 0x3ff) + 0xdc00
        s += unichr(newchar)
    s += u'"'

    if cnt > 0 and ptr != 0:
        s += " (%i @ %s)" % (cnt, hex(ptr.GetValueAsUnsigned()))

    return s.encode('utf-8')


# maxon::Url
def Url(valueObject, dictionary):

    # error = lldb.SBError()

    sbtype = valueObject.GetType()
    voidPtrType = sbtype.GetBasicType(lldb.eBasicTypeVoid).GetPointerType()
    charPtrType = sbtype.GetBasicType(lldb.eBasicTypeChar).GetPointerType()

    urlRef = valueObject.CreateChildAtOffset("urlRef", 0, voidPtrType)

    objPtr = urlRef.GetValueAsUnsigned(0)
    if objPtr != 0:
        scheme = valueObject.CreateValueFromAddress("_scheme", objPtr + 0, charPtrType)
        path = valueObject.CreateValueFromAddress("_path", objPtr + 16, valueObject.GetType()).AddressOf()
        if scheme.GetSummary():
            if py3:
                return "scheme: " + scheme.GetSummary() + " path: " + String(path, dictionary).decode("utf-8")
            else:
                return "scheme: " + scheme.GetSummary() + " path: " + String(path, dictionary)

    return ""


# maxon::Error
def Error(valueObject, dictionary):

    # error = lldb.SBError()

    sbtype = valueObject.GetType()
    voidPtrType = sbtype.GetBasicType(lldb.eBasicTypeVoid).GetPointerType()

    errorRef = valueObject.CreateChildAtOffset("errorRef", 0, voidPtrType)
    objPtr = errorRef.GetValueAsUnsigned(0)
    if objPtr != 0:
        message = valueObject.CreateValueFromAddress("_message", objPtr + 64, valueObject.GetType()).AddressOf()
        return String(message, dictionary)

    return


# maxon::Spinlock
def Spinlock(valueObject, dictionary):

    # error = lldb.SBError()

    sbtype = valueObject.GetType()
    int32Type = sbtype.GetBasicType(lldb.eBasicTypeInt)

    state = valueObject.CreateChildAtOffset("_state", 0, int32Type)
    if state.GetValueAsUnsigned(0) != 0:
        return "locked"

    return ""


# maxon::ScopedLock
def ScopedLock(valueObject, dictionary):

    # error = lldb.SBError()

    sbtype = valueObject.GetType()
    voidPtrType = sbtype.GetBasicType(lldb.eBasicTypeVoid).GetPointerType()

    lock = valueObject.CreateChildAtOffset("_lock", 0, voidPtrType)
    if lock.GetValueAsUnsigned(0) != 0:
        return Spinlock(lock, dictionary)

    return ""


def NodePathImpl(valueObject, dictionary, pathOffset):
    error = lldb.SBError()

    sbtype = valueObject.GetType()
    voidPtrType = sbtype.GetBasicType(lldb.eBasicTypeVoid).GetPointerType()
    charPtrType = sbtype.GetBasicType(lldb.eBasicTypeChar).GetPointerType()
    intType = sbtype.GetBasicType(lldb.eBasicTypeLong)

    ref = valueObject.CreateChildAtOffset("ref", pathOffset, voidPtrType)

    ptr = ref.GetValueAsUnsigned(0)
    if ptr != 0:
        pathPtr = valueObject.CreateValueFromAddress("_pathptr", ptr + 0, charPtrType.GetPointerType()) # pointer to InternedId-array, treated as Char**
        count = valueObject.CreateValueFromAddress("_count", ptr + 8, intType).GetValueAsSigned()
        if count > 0:
            result = '{'
            for i in range(0, min(count, 20)):
                if i:
                    result += ','
                internedId = valueObject.CreateValueFromAddress("_iid" + str(i), pathPtr.GetValueAsUnsigned(0) + 8*i, charPtrType.GetPointerType())
                pathId = valueObject.CreateValueFromAddress("_id" + str(i), internedId.GetValueAsUnsigned(0), charPtrType)
                result += str(pathId.GetSummary())
            if count > 20:
                result += ',...'
            return result + '}'
    return ""


# maxon::NodePath
def NodePath(valueObject, dictionary):
    return NodePathImpl(valueObject, dictionary, 0)

# maxon::GraphNode
def GraphNode(valueObject, dictionary):
    return NodePathImpl(valueObject, dictionary, 8)

# maxon::nodes::Node etc.
def GNode(valueObject, dictionary):
    return NodePathImpl(valueObject, dictionary, 8)


def __lldb_init_module(debugger, dict):

    # Add type summary for the anonymous union of the vector to the upper level.
    debugger.HandleCommand('type summary add "maxon::Vec3<float>::<anonymous union>" -c maxon::Vec3<float>')
    debugger.HandleCommand('type summary add "maxon::Vec3<double>::<anonymous union>" -c maxon::Vec3<double>')
    debugger.HandleCommand('type summary add "maxon::Vec4<float>::<anonymous union>" -c maxon::Vec4<float>')
    debugger.HandleCommand('type summary add "maxon::Vec4<double>::<anonymous union>" -c maxon::Vec4<double>')

    debugger.HandleCommand('type summary add "maxon::Id" --summary-string "${var._value}"')

    debugger.HandleCommand('type summary add -x "maxon::BaseArray<" --summary-string "(cnt=${var._cnt}, capacity=${var._capacity})"')

    # Install type formatters.
    for type, pyType in [('maxon::CString', 'maxon.CString'),
                         ('maxon::String', 'maxon.String'),
                         ('maxon::Url', 'maxon.Url'),
                         ('maxon::Error', 'maxon.Error'),
                         ('maxon::Spinlock', 'maxon.Spinlock'),
                         ('maxon::ScopedLock', 'maxon.ScopedLock'),
                         ('maxon::NodePath', 'maxon.NodePath'),
                         ('maxon::GraphNode', 'maxon.GraphNode'),
                         ('maxon::nodes::Node', 'maxon.GNode'),
                         ('maxon::nodes::Port', 'maxon.GNode'),
                         ('maxon::nodes::PortList', 'maxon.GNode'),
                         ('maxon::nodes::MutableNode', 'maxon.GNode'),
                         ('maxon::nodes::MutablePort', 'maxon.GNode'),
                         ('maxon::nodes::MutablePortList', 'maxon.GNode'),
                         ('maxon::nodes::GNodeHandle', 'maxon.NodePath'),
                         ('maxon::nodes::ValidatedHandle', 'maxon.NodePath')
                         ]:
        debugger.HandleCommand('type summary add ' + type + ' -F ' + pyType)
        # All the types must be installed as const also.
        debugger.HandleCommand('type summary add "const ' + type + '" -F ' + pyType)

    print("maxon.py installed")
