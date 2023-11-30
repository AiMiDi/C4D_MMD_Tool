import lldb
import time
import sys

py3 = sys.version_info >= (3, 0)

unichr = chr if py3 else unichr

def rename_object(sbObj, name):
  return sbObj.CreateValueFromAddress(name, sbObj.GetLoadAddress(), sbObj.GetType())

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
    if capacity > 1073741824 and capacity != 9223372036854775807:
        cnt = 0

    if cnt > capacity:
        cnt = 0

    # Limit number of characters (this might be called on an uninitialized CString).
    displayCnt = cnt
    if cnt > 512:
        displayCnt = 512

    # Assume CString is utf8
    if ptr:
        data = ptr.GetPointeeData(0, displayCnt)
        if data:
            return b'\x22' + str(data.GetString(error, 0)).encode('utf-8') + b'\x22' + b" (%i @ %s)" % (cnt, hex(ptr.GetValueAsUnsigned()).encode('utf-8'))

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
    if capacity > 1073741824 and capacity != 9223372036854775807:
        cnt = 0

    if cnt > capacity:
        cnt = 0

    # Convert from bytes to number of characters.
    cnt = cnt >> characterShift

    # Limit number of characters (this might be called on an uninitialized String).
    displayCnt = cnt
    if cnt > 512:
        displayCnt = 512

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
    intType = sbtype.GetBasicType(lldb.eBasicTypeInt)

    ref = valueObject.CreateChildAtOffset("ref", pathOffset, charPtrType)

    ptr = ref.GetValueAsUnsigned(0)
    if ptr != 0:
        pathPtr = ptr + 24
        count = valueObject.CreateValueFromAddress("_count", ptr + 16, intType).GetValueAsSigned()
        if count > 0:
            result = '{'
            for i in range(0, min(count, 20)):
                if i:
                    result += ','
                internedId = valueObject.CreateValueFromAddress("_iid" + str(i), pathPtr + 8*i, charPtrType.GetPointerType())
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

# maxon::BaseArray
class BaseArray_SynthProvider:
    def __init__(self, valobj, dict):
        self.valobj = valobj

    def num_children(self):
        return self.num_elements

    def get_child_at_index(self,index):
        count = self.num_elements
        if index < 0 or index >= count:
          return None

        offset = index * self.data_size
        return self.ptr.CreateChildAtOffset(
            '[' + str(index) + ']', offset, self.data_type)

    def update(self):
        base_array_data = self.valobj.GetChildAtIndex(0).GetChildAtIndex(0).GetChildAtIndex(0).GetChildAtIndex(0).GetChildAtIndex(0).GetChildAtIndex(0)
        data_type_finder = base_array_data.GetChildMemberWithName('_ptr')
        self.ptr = data_type_finder
        self.data_type = data_type_finder.GetType().GetPointeeType()
        self.data_size = self.data_type.GetByteSize()
        self.num_elements = self.valobj.GetChildMemberWithName('_cnt').GetValueAsUnsigned(0)

# maxon::Block
class Block_SynthProvider:
    def __init__(self, valobj, dict):
        self.valobj = valobj

    def num_children(self):
        return self.num_elements

    def get_child_at_index(self,index):
        count = self.num_elements
        if index < 0 or index >= count:
          return None

        offset = index * self.data_size
        return self.ptr.CreateChildAtOffset(
            '[' + str(index) + ']', offset, self.data_type)

    def update(self):
        base_array_data = self.valobj.GetChildAtIndex(0).GetChildAtIndex(0).GetChildAtIndex(0).GetChildAtIndex(0).GetChildAtIndex(0)
        data_type_finder = base_array_data.GetChildMemberWithName('_ptr')
        self.ptr = data_type_finder
        self.data_type = data_type_finder.GetType().GetPointeeType()
        self.data_size = self.data_type.GetByteSize()
        self.num_elements = self.valobj.GetChildMemberWithName('_size').GetValueAsUnsigned(0)

class Opt_SynthProvider:
  def __init__(self, valobj, dict):
    self.valobj = valobj
    self.valueStorage = None

  def num_children(self):
    return 1 if self.valueStorage != None else 0

  def get_child_at_index(self,index):
    if self.valueStorage != None and index == 0:
      return rename_object(self.valueStorage, '*')
    else:
      return None

  def update(self):
    storage = self.valobj.GetChildMemberWithName('_storage')
    hasValue = storage.GetChildMemberWithName('_hasValue')
    self.valueStorage = storage.GetChildMemberWithName('_valueStorage') if hasValue.GetValueAsUnsigned(0) else None

class BaseRef_SynthProvider:
  def __init__(self, valobj, dict):
    self.valobj = valobj
    self.object = None
    self.validPtr = False

  def num_children(self):
    return 1 if self.validPtr else 0

  def get_child_at_index(self,index):
    if self.object != None and index == 0:
      return rename_object(self.object, '*')
    else:
      return None

  def update(self):
    self.object = self.valobj.GetChildMemberWithName('_object')
    self.validPtr = self.object.GetValueAsUnsigned(0) != 0

class HashMapEntryBase_SynthProvider:
  def __init__(self, valobj, dict):
    self.valobj = valobj

  def num_children(self):
    return 2

  def get_child_at_index(self,index):
    if index == 0:
      return rename_object(self.valobj.GetChildMemberWithName("_key"), "K")
    elif index == 1:
      return rename_object(self.valobj.GetChildMemberWithName("_value"), "V")
    else:
      return None

  def update(self):
    pass

def extract_hashmap_items(valobj, numMaxEntries=1024):
  _size = valobj.GetChildMemberWithName("_size").GetValueAsSigned(0)
  # the map stores length - 1 (M1)
  _tableLength = valobj.GetChildMemberWithName("_tableLengthM1").GetValueAsSigned(0) + 1
  _table = valobj.GetChildMemberWithName("_table")

  items = _size * [None]
  tooLarge = _size > numMaxEntries

  if not tooLarge and _tableLength > 0:
    data_type = _table.GetType().GetPointeeType()
    data_size = data_type.GetByteSize()
    index = 0

    for bucketIdx in range(_tableLength):
      if bucketIdx > 128: # TODO: (Hannes) lldb ... python ... wasted time
          tooLarge = True
          break

      offset = bucketIdx * data_size
      bucketPtr = _table.CreateChildAtOffset("", offset, data_type)
  
      list = bucketPtr.GetChildMemberWithName("list")
      # synchronized maps store an AtomicPtr
      if not list.GetTypeName().endswith("::Entry *"):
        list = list.GetChildMemberWithName("_ptr")

      # iterate over the linked list
      entryType, ptrType = list.GetType(), list.GetTarget().FindFirstType("size_t")
      entryAddr = list.GetValueAsUnsigned(0) # this is simply the integer where the data is in memory
      while entryAddr != 0:
        entry = list.CreateValueFromAddress("", entryAddr, entryType.GetPointeeType())
        items[index] = rename_object(entry, f'[{index}]')
        index = index + 1
        entryAddr = list.CreateValueFromAddress("", entryAddr, ptrType).GetValueAsUnsigned(0)

  return _size, tooLarge, items

class SynchronizedValue_SynthProvider:
  def __init__(self, valobj, dict):
    self.valobj = valobj

  def num_children(self):
    return 1

  def get_child_at_index(self,index):
    if index == 0:
      return rename_object(self.valobj.GetChildMemberWithName("_value"), '*')
    else:
      return None

  def update(self):
    pass


class HashMap_SynthProvider:
  def __init__(self, valobj, dict):
    self.valobj = valobj

  def num_children(self):
    return 1 if self.tooLarge else self._size

  def get_child_at_index(self,index):
    if self.tooLarge:
      return "HashMap is too large to display!"
    else:
      return self.items[index] if index >= 0 and index < len(self.items) else None

  def update(self):
    self._size, self.tooLarge, self.items = extract_hashmap_items(self.valobj)

class DataDictionary_SynthProvider:
  def __init__(self, valobj, dict):
    self.valobj = valobj
    self.hashmap = None

  def num_children(self):
    return 1

  def get_child_at_index(self,index):
    return self.hashmap if index == 0 else "Empty"

  def update(self):
    # this has type maxon::DataDictionaryInterface* / maxon::DataDictionaryBase*
    o = self.valobj.GetChildMemberWithName("_object")
    name_fast = "maxon::HashMap<maxon::Data, maxon::Data, maxon::FastCompare, maxon::HashMapKeyValuePair, maxon::DefaultAllocator, maxon::HASHMAP_MODE::DEFAULT, 16, 10>"
    name_data = "maxon::HashMap<maxon::Data, maxon::Data, maxon::DefaultCompare, maxon::HashMapKeyValuePair, maxon::DefaultAllocator, maxon::HASHMAP_MODE::DEFAULT, 16, 10>"
    name_dict = f"maxon::DataDictionaryBase<{name_fast}, {name_data} >"
    type_fast = self.valobj.GetTarget().FindFirstType(name_fast)
    type_data = self.valobj.GetTarget().FindFirstType(name_data)
    type_dict = self.valobj.GetTarget().FindFirstType(name_dict)

    dict = o.CreateValueFromAddress("dict", o.GetValueAsUnsigned(0), type_dict)
    mode = dict.GetChildMemberWithName("_mode").GetValueAsUnsigned(0)

    if mode == 1 or mode == 2:
      self.hashmap = o.CreateValueFromAddress("Values", dict.GetChildMemberWithName("_hashMapUnion").GetLoadAddress(), type_data if mode == 1 else type_fast)

class Data_SynthProvider:
  def __init__(self, valobj, dict):
    self.valobj = valobj
    self.data = None
    self.char_type = self.valobj.GetTarget().FindFirstType("char")

  def num_children(self):
    return 1 if self.data != None else 0

  def get_child_at_index(self,index):
    return self.data if self.data != None and index == 0 else None

  def update(self):
    self.data = None

    _object = self.valobj.GetChildMemberWithName("_typeInfo").GetChildMemberWithName("_ptr").GetChildMemberWithName("_object")
    if object == None:
      return

    _size = _object.GetChildMemberWithName("_size").GetValueAsUnsigned(0)
    _hash = _object.GetChildMemberWithName("_id").GetChildMemberWithName("_hash").GetValueAsUnsigned(0)
    addr = self.valobj.GetChildMemberWithName("_memBlock").GetChildMemberWithName("dummy")

    def interpret_as_type(type_name, show_data=True):
      type = self.valobj.GetTarget().FindFirstType(f"maxon::{type_name}") if show_data else None
      if show_data and not type.IsValid():
        print(f"Error (maxon.py lldb formatter): Couldn't find {type_name} type")
      else:
        self.data = addr.CreateValueFromAddress(type_name, addr.GetLoadAddress(), type if show_data else self.char_type)

    types = [
      (0x63aea, "Bool"),
      (0x69356, "Char"),
      (0x7514b, "UChar"),
      (0x35e54, "Int16"),
      (0x25eff, "UInt16"),
      (0x35e8e, "Int32"),
      (0x25f39, "UInt32"),
      (0x35eed, "Int64"),
      (0x25f98, "UInt64"),
      (0x101bb, "Float32"),
      (0x1021a, "Float64"),
      (0x556ad, "Vec2<float, 1>"),
      (0x5622e, "Vec2<double, 1>"),
      (0x6c7cc, "Vec3<float, 1>"),
      (0x6d34d, "Vec3<double, 1>"),
      (0x038eb, "Vec4<float, 1>"),
      (0x0446c, "Vec4<double, 1>"),
      (0x3c358, "String"),
      (0x22f39, "CString"),
      (0x44734, "Url"),
      (0x62647, "DataDictionary"),
      (0x40272, "DataType"),
      (0x3f62b, "ConditionVariableRef"),
      (0x48360, "ObjectRef"),
      (0x5491a, "InternedId")
    ]

    for v, type_name in types:
      if (_hash & 0x7ffff) == v:
        interpret_as_type(type_name)
        return

    if _hash == 0x008100c6:
      interpret_as_type("Id")
    elif _hash == 0x000154931e777829:
      type = self.valobj.GetTarget().FindFirstType("maxon::Id")
      self.data = addr.CreateValueFromAddress("maxon::Id", addr.GetLoadAddress(), type.GetPointerType())
    elif _size <= 8:
      interpret_as_type("SmallData", False)
    else:
      interpret_as_type("BigData", False)

def __lldb_init_module(debugger, dict):
    # Add type summary for the anonymous union of the vector to the upper level.
    debugger.HandleCommand('type summary add "maxon::Vec3<float>::<anonymous union>" -c maxon::Vec3<float>')
    debugger.HandleCommand('type summary add "maxon::Vec3<double>::<anonymous union>" -c maxon::Vec3<double>')
    debugger.HandleCommand('type summary add "maxon::Vec4<float>::<anonymous union>" -c maxon::Vec4<float>')
    debugger.HandleCommand('type summary add "maxon::Vec4<double>::<anonymous union>" -c maxon::Vec4<double>')

    debugger.HandleCommand('type summary add "maxon::Id" --summary-string "${var._value}"')

    debugger.HandleCommand('type synthetic add -l maxon.BaseArray_SynthProvider -x "^maxon::BaseArray<.*>$"')
    debugger.HandleCommand('type summary add -x "^maxon::BaseArray<" --summary-string "(cnt=${var._cnt}, capacity=${var._capacity})"')

    debugger.HandleCommand('type synthetic add -l maxon.Block_SynthProvider -x "^maxon::Block<.*>$"')
        

        # template classes need the -x to enable regular expression matching
    debugger.HandleCommand('type synthetic add -l maxon.Opt_SynthProvider -x "^maxon::Opt<.*>$"')
    debugger.HandleCommand('type summary add -x ' + '^maxon::Opt<.*>$ --summary-string "(hasValue=${var._storage._hasValue}, value=${var._storage._valueStorage})"')

    debugger.HandleCommand('type synthetic add -l maxon.BaseRef_SynthProvider -x "^maxon::BaseRef<.*>$"')
    debugger.HandleCommand('type summary add -x ' + '^maxon::BaseRef<.*>$ --summary-string "${var._object}"')

    debugger.HandleCommand('type synthetic add -l maxon.HashMap_SynthProvider -x "^maxon::HashMap<.*>$"')
    debugger.HandleCommand('type summary add -x ' + '^maxon::HashMap<.*>$ --summary-string "(Size: ${var._size})"')
    debugger.HandleCommand('type synthetic add -l maxon.HashMapEntryBase_SynthProvider -x "^maxon::HashMapEntryBase<.*>$"')
    debugger.HandleCommand('type summary add -x ' + '^maxon::HashMapEntryBase<.*>$ --summary-string "(${var._key}, ${var._value})"')

    debugger.HandleCommand('type synthetic add -l maxon.SynchronizedValue_SynthProvider -x "^maxon::SynchronizedValue<.*>$"')
    debugger.HandleCommand('type summary add -x ' + '^maxon::SynchronizedValue<.*>$ --summary-string "${var._value}"')

    debugger.HandleCommand('type synthetic add -l maxon.DataDictionary_SynthProvider "maxon::DataDictionary"')
    debugger.HandleCommand('type synthetic add -l maxon.Data_SynthProvider "maxon::Data"')

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
