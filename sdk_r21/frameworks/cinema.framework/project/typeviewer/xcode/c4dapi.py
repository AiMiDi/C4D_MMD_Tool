import lldb
import math
import sys

py3 = sys.version_info >= (3, 0)

unichr = chr if py3 else unichr

def BaseObject(valueObject, dictionary):

    target = valueObject.GetTarget()
    Vector_Type = target.FindFirstType('Vector')

    pos = valueObject.CreateChildAtOffset("pos", 1152, Vector_Type)
    rot = valueObject.CreateChildAtOffset("rot", 1128, Vector_Type)
    scale = valueObject.CreateChildAtOffset("scale", 1176, Vector_Type)

    return BaseList2D(valueObject, dictionary) + " , " + Vector(pos, dictionary) + " , " + Vector(rot, dictionary) + " , " + Vector(scale, dictionary)


def BaseDocument(valueObject, dictionary):

    filestr = valueObject.GetChildMemberWithName('dummy1')
    return String(filestr, dictionary)


def Matrix(valueObject, dictionary):

    off = valueObject.GetChildMemberWithName('off')

    error = lldb.SBError()

    off_x = off.GetChildMemberWithName('x').GetData().GetDouble(error, 0)
    off_y = off.GetChildMemberWithName('y').GetData().GetDouble(error, 0)
    off_z = off.GetChildMemberWithName('z').GetData().GetDouble(error, 0)

    v1 = valueObject.GetChildMemberWithName('v1')

    v1_x = v1.GetChildMemberWithName('x').GetData().GetDouble(error, 0)
    v1_y = v1.GetChildMemberWithName('y').GetData().GetDouble(error, 0)
    v1_z = v1.GetChildMemberWithName('z').GetData().GetDouble(error, 0)

    v2 = valueObject.GetChildMemberWithName('v2')

    v2_x = v2.GetChildMemberWithName('x').GetData().GetDouble(error, 0)
    v2_y = v2.GetChildMemberWithName('y').GetData().GetDouble(error, 0)
    v2_z = v2.GetChildMemberWithName('z').GetData().GetDouble(error, 0)

    v3 = valueObject.GetChildMemberWithName('v3')

    v3_x = v3.GetChildMemberWithName('x').GetData().GetDouble(error, 0)
    v3_y = v3.GetChildMemberWithName('y').GetData().GetDouble(error, 0)
    v3_z = v3.GetChildMemberWithName('z').GetData().GetDouble(error, 0)

    return '[ (' + str(off_x) + ' , ' + str(off_y) + ' , ' + str(off_z) + ') , (' + str(v1_x) + ' , ' + str(v1_y) + ' , ' + str(v1_z) + ') , (' + str(v2_x) + ' , ' + str(v2_y) + ' , ' + str(v2_z) + ') , (' + str(v3_x) + ' , ' + str(v3_y) + ' , ' + str(v3_z) + ') ' + ']'


def Vector(valueObject, dictionary):

    error = lldb.SBError()

    x = valueObject.GetChildMemberWithName('x').GetData().GetDouble(error, 0)
    y = valueObject.GetChildMemberWithName('y').GetData().GetDouble(error, 0)
    z = valueObject.GetChildMemberWithName('z').GetData().GetDouble(error, 0)

    len = math.sqrt(x * x + y * y + z * z)

    return '(' + str(x) + ' , ' + str(y) + ' , ' + str(z) + ') , ' + str(len)


# Same as maxon::Url
def Filename(valueObject, dictionary):

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


def BaseShader(valueObject, dictionary):

    return BaseList2D(valueObject, dictionary)


def BasePlugin(valueObject, dictionary):

    return BaseList2D(valueObject, dictionary)


def BaseSceneHook(valueObject, dictionary):

    return BaseList2D(valueObject, dictionary)


def BaseSceneLoader(valueObject, dictionary):

    return BaseList2D(valueObject, dictionary)


def BaseSceneSaver(valueObject, dictionary):

    return BaseList2D(valueObject, dictionary)


def BaseTag(valueObject, dictionary):

    return BaseList2D(valueObject, dictionary)


def BaseVideoPost(valueObject, dictionary):

    return BaseList2D(valueObject, dictionary)


def CCurve(valueObject, dictionary):

    return BaseList2D(valueObject, dictionary)


def CTrack(valueObject, dictionary):

    return BaseList2D(valueObject, dictionary)


def GvNode(valueObject, dictionary):

    return BaseList2D(valueObject, dictionary)


# Same as maxon::String
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

def Time(valueObject, dictionary):

    error = lldb.SBError()

    num = valueObject.GetChildMemberWithName('numerator').GetData().GetDouble(error, 0)
    den = valueObject.GetChildMemberWithName('denominator').GetData().GetDouble(error, 0)

    sec = num / den

    return str(num) + '/' + str(den) + ' ' + str(sec) + ' s'


def Polygon(valueObject, dictionary):

    error = lldb.SBError()

    a = valueObject.GetChildMemberWithName('a').GetData().GetUnsignedInt32(error, 0)
    b = valueObject.GetChildMemberWithName('b').GetData().GetUnsignedInt32(error, 0)
    c = valueObject.GetChildMemberWithName('c').GetData().GetUnsignedInt32(error, 0)
    d = valueObject.GetChildMemberWithName('d').GetData().GetUnsignedInt32(error, 0)

    if c == d:

        id = "Tri"

    if c != d:
        id = "Quad"

    return str(a) + ' , ' + str(b) + ' , ' + str(c) + ' , ' + str(d) + ' , ' + str(id)


def MinMax(valueObject, dictionary):

    error = lldb.SBError()

    used = valueObject.GetChildMemberWithName('used').GetData().GetUnsignedInt32(error, 0)

    if used == 1:

        min = valueObject.GetChildMemberWithName('min')
        minx = min.GetChildMemberWithName('x').GetData().GetDouble(error, 0)
        miny = min.GetChildMemberWithName('y').GetData().GetDouble(error, 0)
        minz = min.GetChildMemberWithName('z').GetData().GetDouble(error, 0)

        max = valueObject.GetChildMemberWithName('max')
        maxx = max.GetChildMemberWithName('x').GetData().GetDouble(error, 0)
        maxy = max.GetChildMemberWithName('y').GetData().GetDouble(error, 0)
        maxz = max.GetChildMemberWithName('z').GetData().GetDouble(error, 0)

        return '( (' + str(minx) + ' , ' + str(miny) + ' , ' + str(minz) + ') , (' + str(maxx) + ' , ' + str(maxy) + ' , ' + str(maxz) + ') )'

    else:

        return "(undefined)"


def DateTime(valueObject, dictionary):

    error = lldb.SBError()

    year = valueObject.GetChildMemberWithName('year').GetData().GetUnsignedInt32(error, 0)
    month = valueObject.GetChildMemberWithName('month').GetData().GetUnsignedInt32(error, 0)
    day = valueObject.GetChildMemberWithName('day').GetData().GetUnsignedInt32(error, 0)
    hour = valueObject.GetChildMemberWithName('hour').GetData().GetUnsignedInt32(error, 0)
    minute = valueObject.GetChildMemberWithName('minute').GetData().GetUnsignedInt32(error, 0)
    second = valueObject.GetChildMemberWithName('second').GetData().GetUnsignedInt32(error, 0)

    return str(year) + ' , ' + str(month) + ' , ' + str(day) + ' , ' + str(hour) + ' , ' + str(minute) + ' , ' + str(second)


def DescLevel(valueObject, dictionary):

    error = lldb.SBError()

    id = valueObject.GetChildMemberWithName('id').GetData().GetUnsignedInt32(error, 0)
    dtype = valueObject.GetChildMemberWithName('dtype').GetData().GetUnsignedInt32(error, 0)
    creator = valueObject.GetChildMemberWithName('creator').GetData().GetUnsignedInt32(error, 0)

    return str(id) + ' , ' + str(dtype) + ' , ' + str(creator)


def BaseList2D(valueObject, dictionary):

    error = lldb.SBError()

    target = valueObject.GetTarget()
    strType = target.FindFirstType('String')

    char_type = strType.GetBasicType(lldb.eBasicTypeChar)
    charptr_type = char_type.GetPointerType()
    int_type = charptr_type.GetBasicType(lldb.eBasicTypeInt)

    name = valueObject.CreateChildAtOffset("name", 576, strType)
    plugindata = valueObject.CreateChildAtOffset("plugindata", 72, charptr_type)
    id = plugindata.CreateChildAtOffset("id", 8, int_type).GetData().GetUnsignedInt32(error, 0)

    return str(String(name, dictionary)) + " " + str(id)


def IconData(valueObject, dictionary):

    error = lldb.SBError()

    x = valueObject.GetChildMemberWithName('x').GetData().GetUnsignedInt32(error, 0)
    y = valueObject.GetChildMemberWithName('y').GetData().GetUnsignedInt32(error, 0)
    w = valueObject.GetChildMemberWithName('w').GetData().GetUnsignedInt32(error, 0)
    h = valueObject.GetChildMemberWithName('h').GetData().GetUnsignedInt32(error, 0)
    # flags = valueObject.GetChildMemberWithName('flags').GetData().GetUnsignedInt32(error, 0)

    return str(x) + ' , ' + str(y) + ' , ' + str(w) + ' , ' + str(h)


def BaseBitmap(valueObject, dictionary):

    error = lldb.SBError()

    target = valueObject.GetTarget()
    strType = target.FindFirstType('String')

    char_type = strType.GetBasicType(lldb.eBasicTypeChar)
    charptr_type = char_type.GetPointerType()
    int_type = charptr_type.GetBasicType(lldb.eBasicTypeInt)

    Width = valueObject.CreateChildAtOffset("Width", 152, int_type).GetData().GetUnsignedInt32(error, 0)

    Height = valueObject.CreateChildAtOffset("Height", 156, int_type).GetData().GetUnsignedInt32(error, 0)

    return str(Width) + " , " + str(Height)


def __lldb_init_module(debugger, dict):

    # Install type formatters.
    debugger.HandleCommand('type summary add BaseObject -F c4dapi.BaseObject')
    debugger.HandleCommand('type summary add BaseDocument -F c4dapi.BaseDocument')
    debugger.HandleCommand('type summary add LVector -F c4dapi.Vector')
    debugger.HandleCommand('type summary add String -F c4dapi.String')
    debugger.HandleCommand('type summary add BaseTime -F c4dapi.Time')
    debugger.HandleCommand('type summary add CPolygon -F c4dapi.Polygon')
    debugger.HandleCommand('type summary add SVector -F c4dapi.Vector')
    debugger.HandleCommand('type summary add Vector64 -F c4dapi.Vector')
    debugger.HandleCommand('type summary add Vector32 -F c4dapi.Vector')
    debugger.HandleCommand('type summary add Matrix64 -F c4dapi.Matrix')
    debugger.HandleCommand('type summary add LMatrix -F c4dapi.Matrix')
    debugger.HandleCommand('type summary add Matrix32 -F c4dapi.Matrix')
    debugger.HandleCommand('type summary add SMatrix -F c4dapi.Matrix')
    debugger.HandleCommand('type summary add SMinMax -F c4dapi.MinMax')
    debugger.HandleCommand('type summary add LMinMax -F c4dapi.MinMax')
    debugger.HandleCommand('type summary add DateTime -F c4dapi.DateTime')
    debugger.HandleCommand('type summary add DescLevel -F c4dapi.DescLevel')
    debugger.HandleCommand('type summary add BaseList2D -F c4dapi.BaseList2D')
    debugger.HandleCommand('type summary add BaseShader -F c4dapi.BaseShader')
    debugger.HandleCommand('type summary add BasePlugin -F c4dapi.BasePlugin')
    debugger.HandleCommand('type summary add BaseSceneHook -F c4dapi.BaseSceneHook')
    debugger.HandleCommand('type summary add BaseSceneLoader -F c4dapi.BaseSceneLoader')
    debugger.HandleCommand('type summary add BaseSceneSaver -F c4dapi.BaseSceneSaver')
    debugger.HandleCommand('type summary add BaseTag -F c4dapi.BaseTag')
    debugger.HandleCommand('type summary add BaseVideoPost -F c4dapi.BaseVideoPost')
    debugger.HandleCommand('type summary add CCurve -F c4dapi.CCurve')
    debugger.HandleCommand('type summary add CTrack -F c4dapi.CTrack')
    debugger.HandleCommand('type summary add GvNode -F c4dapi.GvNode')
    debugger.HandleCommand('type summary add Filename -F c4dapi.Filename')
    debugger.HandleCommand('type summary add IconData -F c4dapi.IconData')
    debugger.HandleCommand('type summary add BaseBitmap -F c4dapi.BaseBitmap')

    print("c4dapi.py installed")

