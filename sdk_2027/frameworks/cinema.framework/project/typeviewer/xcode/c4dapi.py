import lldb
import math
import struct
import sys

py3 = sys.version_info >= (3, 0)

unichr = chr if py3 else unichr

def _fmt(v):
    """Format a float to up to 5 decimal places, no trailing zeroes."""
    return '{:.5f}'.format(v).rstrip('0').rstrip('.')

# ---------------------------------------------------------------------------
# Matrix math helpers (for computing GetMg in the debugger)
# ---------------------------------------------------------------------------
def _read_vec(v):
    """Read a Vector SBValue into (x, y, z) tuple."""
    err = lldb.SBError()
    return (
        v.GetChildMemberWithName('x').GetData().GetDouble(err, 0),
        v.GetChildMemberWithName('y').GetData().GetDouble(err, 0),
        v.GetChildMemberWithName('z').GetData().GetDouble(err, 0),
    )

def _read_mat(m):
    """Read a Matrix SBValue into (off, v1, v2, v3) of (x,y,z) tuples."""
    sq = m.GetChildMemberWithName('sqmat')
    return (
        _read_vec(m.GetChildMemberWithName('off')),
        _read_vec(sq.GetChildMemberWithName('v1')),
        _read_vec(sq.GetChildMemberWithName('v2')),
        _read_vec(sq.GetChildMemberWithName('v3')),
    )

def _mul_mat(a, b):
    """Multiply two matrices a * b.  Each is (off, v1, v2, v3)."""
    ao, a1, a2, a3 = a
    bo, b1, b2, b3 = b
    def tv(v):
        return (a1[0]*v[0]+a2[0]*v[1]+a3[0]*v[2],
                a1[1]*v[0]+a2[1]*v[1]+a3[1]*v[2],
                a1[2]*v[0]+a2[2]*v[1]+a3[2]*v[2])
    def tp(v):
        t = tv(v)
        return (ao[0]+t[0], ao[1]+t[1], ao[2]+t[2])
    return (tp(bo), tv(b1), tv(b2), tv(b3))

def _mat_to_sbvalue(mat_tuple, mat_type, target):
    """Pack a (off, v1, v2, v3) tuple into an SBValue of mat_type."""
    off, v1, v2, v3 = mat_tuple
    data = struct.pack('<12d',
        off[0], off[1], off[2],
        v1[0], v1[1], v1[2],
        v2[0], v2[1], v2[2],
        v3[0], v3[1], v3[2])
    sbdata = lldb.SBData()
    err = lldb.SBError()
    sbdata.SetData(err, data, target.GetByteOrder(), target.GetAddressByteSize())
    return target.CreateValueFromData('Global Mat', sbdata, mat_type)

# ---------------------------------------------------------------------------
# Module-scoped type lookup -- equivalent to natvis "c4d_base.xdl64!TypeName"
# ---------------------------------------------------------------------------
C4D_BASE_MODULE = 'c4d_base'
_module_cache = {}  # (target_id, module_name) → SBModule

def _get_module(target, module_name):
    """Return the SBModule for module_name, caching the lookup."""
    key = (target.GetProcess().GetUniqueID(), module_name)
    cached = _module_cache.get(key)
    if cached is not None and cached.IsValid():
        return cached
    for i in range(target.GetNumModules()):
        mod = target.GetModuleAtIndex(i)
        fname = mod.GetFileSpec().GetFilename() or ''
        if module_name in fname:
            _module_cache[key] = mod
            return mod
    return None

def find_type_in_module(target, type_name, module_name=C4D_BASE_MODULE):
    """Search for type_name inside a specific shared library first, then fall back globally."""
    mod = _get_module(target, module_name)
    if mod:
        t = mod.FindFirstType(type_name)
        if t.IsValid():
            return t
    return target.FindFirstType(type_name)

def reinterpret_as(valueObject, type_name, module_name=C4D_BASE_MODULE):
    """Reinterpret valueObject address as type_name from module_name.
    Equivalent to natvis (c4d_base.xdl64!cinema::Foo*)this."""
    # Always work on the non-synthetic value to avoid triggering
    # synthetic children providers which can cause infinite recursion
    # when summaries and synthetics interact.
    vo = valueObject.GetNonSyntheticValue()
    target = vo.GetTarget()
    t = find_type_in_module(target, type_name, module_name)
    if not t.IsValid():
        return None
    
    if vo.GetType().IsReferenceType():
        vo = vo.Dereference()
    elif vo.GetType().IsPointerType():
        vo = vo.Dereference()
        
    result = vo.CreateValueFromAddress(type_name, vo.GetLoadAddress(), t)
    # Return non-synthetic so callers get raw struct members,
    # not synthetic children (which would break GetChildMemberWithName lookups).
    return result.GetNonSyntheticValue() if result else None

# ---------------------------------------------------------------------------
# cinema::GeListNode
# ---------------------------------------------------------------------------
def GeListNode(valueObject, dictionary):
    error = lldb.SBError()
    valueObject = valueObject.GetNonSyntheticValue()
    obj = reinterpret_as(valueObject, 'cinema::GeListNode') or valueObject
    plug_member = obj.GetChildMemberWithName('plug_type')
    plug_type = plug_member.GetData().GetSignedInt32(error, 0) if (plug_member and plug_member.IsValid()) else 0
    # Try to get name from BaseList2D if this is actually a derived type
    bl2d = reinterpret_as(valueObject, 'cinema::BaseList2D')
    if bl2d:
        name_member = bl2d.GetChildMemberWithName('l_name')
        if name_member and name_member.IsValid():
            return str(String(name_member, dictionary)) + ' id:' + str(plug_type)
    return 'id:' + str(plug_type)

# ---------------------------------------------------------------------------
# cinema::BaseList2D
# ---------------------------------------------------------------------------
def BaseList2D(valueObject, dictionary):
    error = lldb.SBError()
    valueObject = valueObject.GetNonSyntheticValue()
    # Cast to full c4d_base type -- equivalent to (c4d_base.xdl64!cinema::BaseList2D*)this
    obj = reinterpret_as(valueObject, 'cinema::BaseList2D') or valueObject
    name_member = obj.GetChildMemberWithName('l_name')
    plug_member = obj.GetChildMemberWithName('plug_type')
    if name_member and name_member.IsValid():
        id = plug_member.GetData().GetUnsignedInt32(error, 0) if (plug_member and plug_member.IsValid()) else 0
        return str(String(name_member, dictionary)) + ' id:' + str(id)
    # Fallback: hardcoded offsets when full type unavailable
    target = valueObject.GetTarget()
    strType = find_type_in_module(target, 'cinema::String')
    if not strType.IsValid():
        strType = target.FindFirstType('String')
    char_type = strType.GetBasicType(lldb.eBasicTypeChar)
    charptr_type = char_type.GetPointerType()
    int_type = charptr_type.GetBasicType(lldb.eBasicTypeInt)
    name = valueObject.CreateChildAtOffset('name', 576, strType)
    plugindata = valueObject.CreateChildAtOffset('plugindata', 72, charptr_type)
    id = plugindata.CreateChildAtOffset('id', 8, int_type).GetData().GetUnsignedInt32(error, 0)
    return str(String(name, dictionary)) + ' id:' + str(id)

# ---------------------------------------------------------------------------
# cinema::BaseObject
# ---------------------------------------------------------------------------
def BaseObject(valueObject, dictionary):
    valueObject = valueObject.GetNonSyntheticValue()
    obj = reinterpret_as(valueObject, 'cinema::BaseObject') or valueObject
    pos_m = obj.GetChildMemberWithName('t_pos') or obj.GetChildMemberWithName('pos')
    rot_m = obj.GetChildMemberWithName('t_rot') or obj.GetChildMemberWithName('rot')
    scale_m = obj.GetChildMemberWithName('t_scale') or obj.GetChildMemberWithName('scale')
    base = BaseList2D(valueObject, dictionary)
    if pos_m and pos_m.IsValid():
        return base + ' , pos: ' + Vector(pos_m, dictionary) + ' , rot: ' + Vector(rot_m, dictionary) + ' , scale: ' + Vector(scale_m, dictionary)
    # Fallback: hardcoded offsets
    target = valueObject.GetTarget()
    Vector_Type = find_type_in_module(target, 'cinema::Vector')
    if not Vector_Type.IsValid():
        Vector_Type = target.FindFirstType('cinema::Vector')
    pos = valueObject.CreateChildAtOffset('pos', 1152, Vector_Type)
    rot = valueObject.CreateChildAtOffset('rot', 1128, Vector_Type)
    scale = valueObject.CreateChildAtOffset('scale', 1176, Vector_Type)
    return base + ' , pos: ' + Vector(pos, dictionary) + ' , rot: ' + Vector(rot, dictionary) + ' , scale: ' + Vector(scale, dictionary)

# ---------------------------------------------------------------------------
# cinema::BaseDocument
# ---------------------------------------------------------------------------
def BaseDocument(valueObject, dictionary):
    valueObject = valueObject.GetNonSyntheticValue()
    obj = reinterpret_as(valueObject, 'cinema::BaseDocument') or valueObject
    name_m = obj.GetChildMemberWithName('m_name')
    if name_m and name_m.IsValid():
        return String(name_m, dictionary)
    return String(obj.GetChildMemberWithName('dummy1'), dictionary)

# ---------------------------------------------------------------------------
# Math helpers
# ---------------------------------------------------------------------------
def Matrix(valueObject, dictionary):
    error = lldb.SBError()
    def vec3(parent, name):
        v = parent.GetChildMemberWithName(name)
        x = v.GetChildMemberWithName('x').GetData().GetDouble(error, 0)
        y = v.GetChildMemberWithName('y').GetData().GetDouble(error, 0)
        z = v.GetChildMemberWithName('z').GetData().GetDouble(error, 0)
        return '{' + _fmt(x) + ' , ' + _fmt(y) + ' , ' + _fmt(z) + '}'
    sqMat = valueObject.GetChildMemberWithName('sqmat')
    return '[ off:' + vec3(valueObject, 'off') + ' , v1:' + vec3(sqMat, 'v1') + ' , v2:' + vec3(sqMat, 'v2') + ' , v3:' + vec3(sqMat, 'v3') + ' ]'

def Vector(valueObject, dictionary):
    error = lldb.SBError()
    x = valueObject.GetChildMemberWithName('x').GetData().GetDouble(error, 0)
    y = valueObject.GetChildMemberWithName('y').GetData().GetDouble(error, 0)
    z = valueObject.GetChildMemberWithName('z').GetData().GetDouble(error, 0)
    import math as _math
    return '[{' + _fmt(x) + ' , ' + _fmt(y) + ' , ' + _fmt(z) + '} , ||' + _fmt(_math.sqrt(x*x + y*y + z*z)) + '||]'

# ---------------------------------------------------------------------------
# cinema::Filename (same layout as maxon::Url)
# ---------------------------------------------------------------------------
def Filename(valueObject, dictionary):
    sbtype = valueObject.GetType()
    voidPtrType = sbtype.GetBasicType(lldb.eBasicTypeVoid).GetPointerType()
    charPtrType = sbtype.GetBasicType(lldb.eBasicTypeChar).GetPointerType()
    urlRef = valueObject.CreateChildAtOffset('urlRef', 0, voidPtrType)
    objPtr = urlRef.GetValueAsUnsigned(0)
    if objPtr == 0:
        return ""

    target = valueObject.GetTarget()

    # Try to resolve via UrlImpl type in debug info
    url_impl_type = target.FindFirstType('maxon::UrlImpl')
    if url_impl_type and url_impl_type.IsValid():
        impl = valueObject.CreateValueFromAddress("_impl", objPtr, url_impl_type)
        if impl and impl.IsValid():
            scheme = impl.GetChildMemberWithName('_scheme')
            path = impl.GetChildMemberWithName('_path')

            scheme_str = ''
            if scheme and scheme.IsValid():
                scheme_str = scheme.GetSummary() or ''

            path_str = ''
            if path and path.IsValid():
                path_str = String(path, dictionary)

            if scheme_str:
                return "scheme: " + scheme_str + " path: " + path_str
            elif path_str:
                return "path: " + path_str

    return ""

# ---------------------------------------------------------------------------
# BaseList2D derivatives
# ---------------------------------------------------------------------------
def _bl2d(v, d):
    return BaseList2D(reinterpret_as(v, 'cinema::BaseList2D') or v, d)

def BaseShader(v, d):      return _bl2d(v, d)
def BasePlugin(v, d):      return _bl2d(v, d)
def BaseSceneHook(v, d):   return _bl2d(v, d)
def BaseSceneLoader(v, d): return _bl2d(v, d)
def BaseSceneSaver(v, d):  return _bl2d(v, d)
def BaseTag(v, d):         return _bl2d(v, d)
def BaseVideoPost(v, d):   return _bl2d(v, d)
def CCurve(v, d):          return _bl2d(v, d)
def CTrack(v, d):          return _bl2d(v, d)
def GvNode(v, d):          return _bl2d(v, d)

# ---------------------------------------------------------------------------
# cinema::String (same implementation as maxon::String)
# ---------------------------------------------------------------------------
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

    cnt = capacity = characterEncoding = characterShift = pad0 = pad1 = 0
    strRef = valueObject.CreateChildAtOffset('strRef', 0, voidPtrType)
    objPtr = strRef.GetValueAsUnsigned(0)
    ptr = None
    if objPtr != 0:
        ptr = valueObject.CreateValueFromAddress('ptr', objPtr, utf16CharPtrType)
        characterEncoding = valueObject.CreateValueFromAddress('ptr', objPtr, int8Type).GetValueAsSigned()
        objPtr += 1
        characterShift = valueObject.CreateValueFromAddress('ptr', objPtr, int8Type).GetValueAsSigned()
        objPtr += 1
        pad0 = valueObject.CreateValueFromAddress('ptr', objPtr, int16Type).GetValueAsSigned()
        objPtr += 2
        pad1 = valueObject.CreateValueFromAddress('ptr', objPtr, int32Type).GetValueAsSigned()
        objPtr += 4
        if pad1 == -1 and pad0 == -1:
            objPtr += 16
            if characterShift == 0:
                ptr = valueObject.CreateValueFromAddress('ptr', objPtr, uCharPtrType)
            elif characterShift == 1:
                ptr = valueObject.CreateValueFromAddress('ptr', objPtr, utf16CharPtrType)
            elif characterShift == 2:
                ptr = valueObject.CreateValueFromAddress('ptr', objPtr, utf32CharPtrType)
            objPtr += 8
        else:
            characterShift = characterEncoding = 0
        cnt = valueObject.CreateValueFromAddress('cnt', objPtr, intType).GetValueAsSigned()
        capacity = valueObject.CreateValueFromAddress('capacity', objPtr + 8, intType).GetValueAsSigned()

    if capacity > 1073741824:
        cnt = 0
    if cnt > capacity:
        cnt = 0
    cnt = cnt >> characterShift
    displayCnt = min(cnt, 512)

    s = u'"'
    if ptr:
        for i in range(displayCnt):
            data_val = ptr.GetPointeeData(i, 1)
            if characterEncoding == 0:
                newchar = data_val.GetUnsignedInt16(error, 0)
            elif characterEncoding == 1:
                newchar = data_val.GetUnsignedInt32(error, 0)
            else:
                newchar = data_val.GetUnsignedInt8(error, 0)
            if newchar > 0xffff:
                newchar -= 0x10000
                s += unichr((newchar >> 10) + 0xd800)
                newchar = (newchar & 0x3ff) + 0xdc00
            s += unichr(newchar)
    s += u'"'
    return s

# ---------------------------------------------------------------------------
# Misc primitives
# ---------------------------------------------------------------------------
def Time(valueObject, dictionary):
    error = lldb.SBError()
    num = valueObject.GetChildMemberWithName('numerator').GetData().GetDouble(error, 0)
    den = valueObject.GetChildMemberWithName('denominator').GetData().GetDouble(error, 0)
    sec = (num / den) if den != 0 else 0.0
    return _fmt(num) + '/' + _fmt(den) + ' ' + _fmt(sec) + ' s'

def Polygon(valueObject, dictionary):
    error = lldb.SBError()
    def u(n): return valueObject.GetChildMemberWithName(n).GetData().GetUnsignedInt32(error, 0)
    a, b, c, d = u('a'), u('b'), u('c'), u('d')
    return str(a) + ' , ' + str(b) + ' , ' + str(c) + ' , ' + str(d) + ' , ' + ('Tri' if c == d else 'Quad')

def MinMax(valueObject, dictionary):
    error = lldb.SBError()
    used = valueObject.GetChildMemberWithName('used').GetData().GetUnsignedInt32(error, 0)
    if used == 1:
        def v3(m):
            x = m.GetChildMemberWithName('x').GetData().GetDouble(error, 0)
            y = m.GetChildMemberWithName('y').GetData().GetDouble(error, 0)
            z = m.GetChildMemberWithName('z').GetData().GetDouble(error, 0)
            return '(' + _fmt(x) + ' , ' + _fmt(y) + ' , ' + _fmt(z) + ')'
        return '( ' + v3(valueObject.GetChildMemberWithName('min')) + ' , ' + v3(valueObject.GetChildMemberWithName('max')) + ' )'
    return '(undefined)'

def DateTime(valueObject, dictionary):
    error = lldb.SBError()
    def u(n): return str(valueObject.GetChildMemberWithName(n).GetData().GetUnsignedInt32(error, 0))
    return u('year') + ' , ' + u('month') + ' , ' + u('day') + ' , ' + u('hour') + ' , ' + u('minute') + ' , ' + u('second')

def DescLevel(valueObject, dictionary):
    error = lldb.SBError()
    def u(n): return str(valueObject.GetChildMemberWithName(n).GetData().GetUnsignedInt32(error, 0))
    return u('id') + ' , ' + u('dtype') + ' , ' + u('creator')

def IconData(valueObject, dictionary):
    error = lldb.SBError()
    def u(n): return str(valueObject.GetChildMemberWithName(n).GetData().GetUnsignedInt32(error, 0))
    return u('x') + ' , ' + u('y') + ' , ' + u('w') + ' , ' + u('h')

def BaseBitmap(valueObject, dictionary):
    error = lldb.SBError()
    obj = reinterpret_as(valueObject, 'cinema::BaseBitmap') or valueObject
    w_m = obj.GetChildMemberWithName('m_width') or obj.GetChildMemberWithName('width')
    h_m = obj.GetChildMemberWithName('m_height') or obj.GetChildMemberWithName('height')
    if w_m and w_m.IsValid():
        return str(w_m.GetData().GetUnsignedInt32(error, 0)) + ' , ' + str(h_m.GetData().GetUnsignedInt32(error, 0))
    target = valueObject.GetTarget()
    int_type = target.FindFirstType('int')
    W = valueObject.CreateChildAtOffset('W', 152, int_type).GetData().GetUnsignedInt32(error, 0)
    H = valueObject.CreateChildAtOffset('H', 156, int_type).GetData().GetUnsignedInt32(error, 0)
    return str(W) + ' , ' + str(H)

def BaseContainer(valueObject, dictionary):
    valueObject = valueObject.GetNonSyntheticValue()
    # Same as natvis Cast/GetRoot idea: reinterpret to c4d_base impl types.
    base = reinterpret_as(valueObject, 'cinema::BaseContainer') or valueObject
    root = base.GetChildMemberWithName('m_ulRoot')
    if not (root and root.IsValid()):
        return 'BaseContainer - not resolved'

    m_ulRoot = root.GetValueAsUnsigned(0)
    is_btree = ((m_ulRoot & 3) != 3)

    if is_btree:
        btree = reinterpret_as(valueObject, 'cinema::BTreeContainer')
        if btree and btree.IsValid():
            summary = btree.GetSummary()
            if summary:
                return summary
        return 'BTreeContainer'

    root_ptr = (m_ulRoot & ~3)
    if root_ptr == 0:
        return 'LinearContainer empty'

    target = valueObject.GetTarget()
    entry_type = find_type_in_module(target, 'cinema::BTreeContainerNodeDataList')
    if not entry_type.IsValid():
        return 'LinearContainer root=' + hex(root_ptr)

    entries = []
    cur = root_ptr
    max_entries = 24
    for _ in range(max_entries):
        if cur == 0:
            break

        entry = valueObject.CreateValueFromAddress('entry', cur, entry_type)
        l_id = entry.GetChildMemberWithName('lID').GetValueAsSigned(0)
        d_val = entry.GetChildMemberWithName('d')
        d_summary = GeData(d_val, dictionary) if (d_val and d_val.IsValid()) else '<GeData?>'

        entries.append('[id: ' + str(l_id) + ' => ' + str(d_summary) + ']')

        next_ptr = entry.GetChildMemberWithName('pNext')
        if not (next_ptr and next_ptr.IsValid()):
            cur = 0
            break
        cur = next_ptr.GetValueAsUnsigned(0)

    if cur != 0:
        entries.append('...')

    return 'LinearContainer [' + ' | '.join(entries) + ']'

# ---------------------------------------------------------------------------
# cinema::GeData
# ---------------------------------------------------------------------------
def GeData(valueObject, dictionary):
    error = lldb.SBError()
    obj = reinterpret_as(valueObject, 'cinema::GeData') or valueObject
    type_m = obj.GetChildMemberWithName('Type')
    if not (type_m and type_m.IsValid()):
        return '<GeData: no type>'
    Type = type_m.GetData().GetUnsignedInt32(error, 0)
    DA_NIL=0; DA_LONG=15; DA_REAL=19; DA_TIME=22; DA_VECTOR=23; DA_MATRIX=25
    DA_LLONG=26; DA_BYTEARRAY=128; DA_STRING=130; DA_FILENAME=131
    DA_CONTAINER=132; DA_ALIASLINK=133; DA_MARKER=256; DA_MISSINGPLUG=257
    DA_UUID=258; DA_TRISTATE=259; DA_DATA=260; DA_CUSTOMDATATYPE=1000000
    if   Type == DA_NIL:          return 'Nil'
    elif Type == DA_LONG:         return 'Int32: '    + str(obj.GetChildMemberWithName('DInteger').GetData().GetSignedInt32(error, 0))
    elif Type == DA_LLONG:        return 'Int64: '    + str(obj.GetChildMemberWithName('DLLong').GetData().GetSignedInt64(error, 0))
    elif Type == DA_REAL:         return 'Float: '    + _fmt(obj.GetChildMemberWithName('DReal').GetData().GetDouble(error, 0))
    elif Type == DA_TIME:         return 'Time: '     + Time(obj.GetChildMemberWithName('DBaseTime'), dictionary)
    elif Type == DA_STRING:       return 'String: '   + str(String(obj.GetChildMemberWithName('DString'), dictionary))
    elif Type == DA_FILENAME:     return 'Filename: ' + str(Filename(obj.GetChildMemberWithName('DFilename'), dictionary))
    elif Type == DA_VECTOR:       return 'Vector: '   + str(Vector(obj.GetChildMemberWithName('DVector'), dictionary))
    elif Type == DA_MATRIX:       return 'Matrix'
    elif Type == DA_BYTEARRAY:    return 'ByteArray'
    elif Type == DA_CONTAINER:    return 'Container'
    elif Type == DA_ALIASLINK:    return 'AliasLink'
    elif Type == DA_MARKER:       return 'Marker'
    elif Type == DA_DATA:         return 'Data'
    elif Type == DA_UUID:         return 'UUID'
    elif Type == DA_TRISTATE:     return 'TriState'
    elif Type == DA_MISSINGPLUG:  return 'MissingPlugin'
    elif Type == DA_CUSTOMDATATYPE: return 'CustomDataType (id=' + str(Type) + ')'
    else: return '<GeData type=' + str(Type) + '>'

# ---------------------------------------------------------------------------
# cinema::DescID
# ---------------------------------------------------------------------------
def DescID(valueObject, dictionary):
    error = lldb.SBError()
    sbtype = valueObject.GetType()
    intType = sbtype.GetBasicType(lldb.eBasicTypeLong)
    charPtrType = sbtype.GetBasicType(lldb.eBasicTypeChar).GetPointerType()
    depth_inline = valueObject.CreateChildAtOffset('depth', 8, intType).GetValueAsSigned()
    if depth_inline > 0:
        result = 'Depth=' + str(depth_inline) + ': '
        desc_ptr = valueObject.CreateChildAtOffset('levels', 0, charPtrType)
        for i in range(min(int(depth_inline), 8)):
            if i: result += ', '
            id_val = valueObject.CreateValueFromAddress(
                'id' + str(i),
                desc_ptr.GetValueAsUnsigned(0) + i * 12,
                sbtype.GetBasicType(lldb.eBasicTypeInt)
            ).GetData().GetUnsignedInt32(error, 0)
            result += str(id_val)
        return result
    else:
        heap_ptr = valueObject.CreateChildAtOffset('heap', 0, charPtrType)
        if heap_ptr.GetValueAsUnsigned(0) == 0:
            return 'Null'
        depth_heap = valueObject.CreateValueFromAddress(
            'depth', heap_ptr.GetValueAsUnsigned(0) + 56, intType).GetValueAsSigned()
        return 'Heap Depth=' + str(depth_heap)

# ---------------------------------------------------------------------------
# cinema::TriState<T>
# ---------------------------------------------------------------------------
def TriState(valueObject, dictionary):
    error = lldb.SBError()
    tri = valueObject.GetChildMemberWithName('tri').GetData().GetSignedInt32(error, 0)
    val = valueObject.GetChildMemberWithName('value')
    suffix = ' (unchanged)' if tri == -1 else (' (tri)' if tri == 1 else '')
    # Use GetValue() only - avoid GetSummary() which can recurse
    val_str = val.GetValue() if val else 'None'
    return 'value=' + str(val_str) + suffix

# ---------------------------------------------------------------------------
# Tag helpers
# ---------------------------------------------------------------------------
def PluginTag(valueObject, dictionary):
    error = lldb.SBError()
    obj = reinterpret_as(valueObject, 'cinema::BaseList2D') or valueObject
    plug_type = obj.GetChildMemberWithName('plug_type')
    id = plug_type.GetData().GetUnsignedInt32(error, 0) if (plug_type and plug_type.IsValid()) else 0
    return 'Plugin Tag ' + str(BaseList2D(valueObject, dictionary)) + ' id=' + str(id)

def VertexColorTag(valueObject, dictionary):
    return 'Vertex Color Tag ' + str(BaseList2D(valueObject, dictionary))

# ===========================================================================
# Synthetic Children Providers
# ===========================================================================

class _BaseSyntheticProvider(object):
    """Base class for LLDB synthetic children providers."""

    def __init__(self, valueObject, internalDict):
        self._vo = valueObject.GetNonSyntheticValue()
        self._children = []  # list of (name, SBValue)

    # -- helpers --------------------------------------------------------------
    def _cast(self, type_name):
        return reinterpret_as(self._vo, type_name)

    def _add(self, name, sbvalue):
        if sbvalue and sbvalue.IsValid():
            self._children.append((name, sbvalue))

    def _add_if_nonnull(self, name, sbvalue):
        if sbvalue and sbvalue.IsValid() and sbvalue.GetValueAsUnsigned(0) != 0:
            self._children.append((name, sbvalue))

    # -- SyntheticChildrenProvider interface ----------------------------------
    def num_children(self):
        return len(self._children)

    def get_child_index(self, name):
        for i, (n, _) in enumerate(self._children):
            if n == name:
                return i
        return -1

    def get_child_at_index(self, index):
        if 0 <= index < len(self._children):
            name, val = self._children[index]
            # Use GetNonSyntheticValue() to prevent recursive synthetic provider calls
            val = val.GetNonSyntheticValue()
            if val.GetLoadAddress() != lldb.LLDB_INVALID_ADDRESS:
                return val.CreateValueFromAddress(name, val.GetLoadAddress(), val.GetType())
            return val
        return None

    def has_children(self):
        return len(self._children) > 0


# ---------------------------------------------------------------------------
class GeListNodeSynthProvider(_BaseSyntheticProvider):
    """Synthetic children for cinema::GeListNode — mirrors natvis GeListHead tree."""

    def update(self):
        self._children = []
        obj = self._cast('cinema::GeListNode')
        if not obj:
            return
        
        # Try resolving name from BaseList2D
        bl2d = self._cast('cinema::BaseList2D')
        if bl2d:
            name_m = bl2d.GetChildMemberWithName('l_name')
            self._add('Name', name_m)
            
        self._add('Type ID', obj.GetChildMemberWithName('plug_type'))
        self._add('plug_bits',  obj.GetChildMemberWithName('plug_bits'))

        self._add_if_nonnull('Next', obj.GetChildMemberWithName('t_next'))
        self._add_if_nonnull('Down', obj.GetChildMemberWithName('t_down'))
        self._add_if_nonnull('Prev', obj.GetChildMemberWithName('t_prev'))
        self._add_if_nonnull('Up', obj.GetChildMemberWithName('t_up'))

        # Raw struct members for full inspection
        if obj:
            for i in range(obj.GetNumChildren()):
                child = obj.GetChildAtIndex(i)
                if child and child.IsValid():
                    self._children.append((child.GetName(), child))


# ---------------------------------------------------------------------------
class BaseList2DSynthProvider(_BaseSyntheticProvider):
    """Synthetic children for cinema::BaseList2D — Name, plug_type, BaseContainer."""

    def update(self):
        self._children = []
        obj = self._cast('cinema::BaseList2D')
        if not obj:
            return

        self._add('Name', obj.GetChildMemberWithName('l_name'))
        self._add('Type ID', obj.GetChildMemberWithName('plug_type'))
        self._add('BaseContainer', obj.GetChildMemberWithName('data'))

        self._add_if_nonnull('Next', obj.GetChildMemberWithName('t_next'))
        self._add_if_nonnull('Down', obj.GetChildMemberWithName('t_down'))
        self._add_if_nonnull('Prev', obj.GetChildMemberWithName('t_prev'))
        self._add_if_nonnull('Up', obj.GetChildMemberWithName('t_up'))

        # Raw struct members for full inspection
        if obj:
            for i in range(obj.GetNumChildren()):
                child = obj.GetChildAtIndex(i)
                if child and child.IsValid():
                    self._children.append((child.GetName(), child))


# ---------------------------------------------------------------------------
class BaseObjectSynthProvider(_BaseSyntheticProvider):
    """Synthetic children for cinema::BaseObject — mirrors natvis BaseObject expand."""

    def update(self):
        self._children = []
        obj = self._cast('cinema::BaseObject')
        if not obj:
            return

        # BaseList2D fields
        bl2d = self._cast('cinema::BaseList2D')
        if bl2d:
            self._add('Name', bl2d.GetChildMemberWithName('l_name'))
            self._add('Type ID', bl2d.GetChildMemberWithName('plug_type'))

        # Tags
        self._add('Tags', obj.GetChildMemberWithName('root_tag'))

        # BaseContainer
        if bl2d:
            self._add('BaseContainer', bl2d.GetChildMemberWithName('data'))

        # Cache / Deform Cache (only if non-null)
        self._add_if_nonnull('Cache', obj.GetChildMemberWithName('_xcache'))
        self._add_if_nonnull('Deform Cache', obj.GetChildMemberWithName('_xdefcache'))

        # Navigation
        self._add_if_nonnull('Next', obj.GetChildMemberWithName('t_next'))
        self._add_if_nonnull('Down', obj.GetChildMemberWithName('t_down'))
        self._add_if_nonnull('Prev', obj.GetChildMemberWithName('t_prev'))
        self._add_if_nonnull('Up', obj.GetChildMemberWithName('t_up'))

        # Transform
        self._add('AbsPos', obj.GetChildMemberWithName('t_pos'))
        self._add('AbsRot', obj.GetChildMemberWithName('t_rot'))
        self._add('AbsScale', obj.GetChildMemberWithName('t_scale'))
        ml = obj.GetChildMemberWithName('ml_cache')
        self._add('Local Mat', ml)

        # Compute Global Matrix (GetMg equivalent): walk up t_up multiplying local matrices
        
        if ml and ml.IsValid():
            mg = _read_mat(ml)
            target = self._vo.GetTarget()
            bo_type = find_type_in_module(target, 'cinema::BaseObject')
            gln_type = find_type_in_module(target, 'cinema::GeListNode')
            if bo_type.IsValid() and gln_type.IsValid():
                # Start from current object's t_up
                gln = self._cast('cinema::GeListNode')
                up = gln.GetChildMemberWithName('t_up') if gln else None
                for _ in range(64):
                    if not (up and up.IsValid()) or up.GetValueAsUnsigned(0) == 0:
                        break
                    addr = up.GetValueAsUnsigned(0)
                    parent = self._vo.CreateValueFromAddress('_p', addr, bo_type).GetNonSyntheticValue()
                    if not parent or not parent.IsValid():
                        break
                    pml = parent.GetChildMemberWithName('ml_cache')
                    if not (pml and pml.IsValid()):
                        break
                    
                    mg = _mul_mat(_read_mat(pml), mg)
                    
                    up = parent.GetChildMemberWithName('t_up')
                    addr = up.GetValueAsUnsigned(0)
                    pgln = self._vo.CreateValueFromAddress('_pg', addr, gln_type).GetNonSyntheticValue()
                    dyn = up.GetDynamicValue(lldb.eDynamicDontRunTarget)

                    if dyn and dyn.IsValid() and 'GeListHead' in dyn.GetType().GetName():
                        break
                    if not pgln:
                        break
            mg_val = _mat_to_sbvalue(mg, ml.GetType(), target)
            if mg_val and mg_val.IsValid():
                self._children.append(('Global Mat', mg_val))

        # Add all raw struct members from the c4d_base reinterpreted type.
        # We can't add `obj` itself as a single child because LLDB would
        # re-apply BaseObjectSynthProvider to it. Instead, iterate the real
        # (non-synthetic) struct fields so the user can inspect every member.
        if obj:
            for i in range(obj.GetNumChildren()):
                child = obj.GetChildAtIndex(i)
                if child and child.IsValid():
                    self._children.append((child.GetName(), child))


# ---------------------------------------------------------------------------
class BaseContainerSynthProvider(_BaseSyntheticProvider):
    """Synthetic children for cinema::BaseContainer — iterates linear list entries."""

    MAX_ENTRIES = 64

    def update(self):
        self._children = []
        base = self._cast('cinema::BaseContainer')
        if not base:
            return

        root = base.GetChildMemberWithName('m_ulRoot')
        if not (root and root.IsValid()):
            return

        m_ulRoot = root.GetValueAsUnsigned(0)
        is_btree = ((m_ulRoot & 3) != 3)

        if is_btree:
            btree = reinterpret_as(self._vo, 'cinema::BTreeContainer')
            if btree and btree.IsValid():
                self._add('BTreeContainer', btree)
            return

        root_ptr = (m_ulRoot & ~3)
        if root_ptr == 0:
            return

        target = self._vo.GetTarget()
        entry_type = find_type_in_module(target, 'cinema::BTreeContainerNodeDataList')
        if not entry_type.IsValid():
            return

        cur = root_ptr
        for idx in range(self.MAX_ENTRIES):
            if cur == 0:
                break
            entry = self._vo.CreateValueFromAddress('entry', cur, entry_type)
            l_id = entry.GetChildMemberWithName('lID').GetValueAsSigned(0)
            d_val = entry.GetChildMemberWithName('d')

            label = '[id:' + str(l_id) + ']'
            if d_val and d_val.IsValid():
                self._children.append((label, d_val))

            next_ptr = entry.GetChildMemberWithName('pNext')
            if not (next_ptr and next_ptr.IsValid()):
                break
            cur = next_ptr.GetValueAsUnsigned(0)


# ---------------------------------------------------------------------------
# LLDB module init
# ---------------------------------------------------------------------------
def __lldb_init_module(debugger, dict):
    for bare, fn in [
        ('BaseObject',      'BaseObject'),
        ('BaseDocument',    'BaseDocument'),
        ('LVector',         'Vector'),
        ('SVector',         'Vector'),
        ('Vector64',        'Vector'),
        ('Vector32',        'Vector'),
        ('String',          'String'),
        ('BaseTime',        'Time'),
        ('CPolygon',        'Polygon'),
        ('Matrix64',        'Matrix'),
        ('LMatrix',         'Matrix'),
        ('Matrix32',        'Matrix'),
        ('SMatrix',         'Matrix'),
        ('Matrix',         	'Matrix'),
        ('SMinMax',         'MinMax'),
        ('LMinMax',         'MinMax'),
        ('DateTime',        'DateTime'),
        ('DescLevel',       'DescLevel'),
        ('GeListNode',      'GeListNode'),
        ('BaseList2D',      'BaseList2D'),
        ('BaseShader',      'BaseShader'),
        ('BasePlugin',      'BasePlugin'),
        ('BaseSceneHook',   'BaseSceneHook'),
        ('BaseSceneLoader', 'BaseSceneLoader'),
        ('BaseSceneSaver',  'BaseSceneSaver'),
        ('BaseTag',         'BaseTag'),
        ('BaseVideoPost',   'BaseVideoPost'),
        ('CCurve',          'CCurve'),
        ('CTrack',          'CTrack'),
        ('GvNode',          'GvNode'),
        ('Filename',        'Filename'),
        ('IconData',        'IconData'),
        ('BaseBitmap',      'BaseBitmap'),
        ('BaseContainer',   'BaseContainer'),
        ('GeData',          'GeData'),
        ('DescID',          'DescID'),
        ('PluginTag',       'PluginTag'),
        ('VertexColorTag',  'VertexColorTag'),
    ]:
        for qualified in ['cinema::' + bare, bare]:
            debugger.HandleCommand('type summary add "' + qualified + '" -F c4dapi.' + fn)

    debugger.HandleCommand('type summary add -x "^cinema::TriState<.*>$" -F c4dapi.TriState')
    debugger.HandleCommand('type summary add -x "^TriState<.*>$" -F c4dapi.TriState')

    # -- Synthetic children providers -----------------------------------------
    for bare, cls in [
        ('GeListNode',    'GeListNodeSynthProvider'),
        ('BaseList2D',    'BaseList2DSynthProvider'),
        ('BaseObject',    'BaseObjectSynthProvider'),
        ('BaseContainer', 'BaseContainerSynthProvider'),
    ]:
        for qualified in ['cinema::' + bare, bare]:
            debugger.HandleCommand(
                'type synthetic add "' + qualified + '" '
                '--python-class c4dapi.' + cls
            )

    print('c4dapi.py installed')
