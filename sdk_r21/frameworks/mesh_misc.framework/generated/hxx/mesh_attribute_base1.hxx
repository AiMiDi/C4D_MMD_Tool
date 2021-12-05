#if 1
class CustomDataTagDisplayRef;

struct CustomDataTagDisplayInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, CustomDataTagDisplayInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(CustomDataTagDisplayInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct CustomDataTagDisplayInterface::Hxx1
{
	class Reference;
	using ReferenceClass = CustomDataTagDisplayRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for CustomDataTagDisplayInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for CustomDataTagDisplayInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CustomDataTagDisplayRef, true>::type&() const { return reinterpret_cast<const CustomDataTagDisplayRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CustomDataTagDisplayRef, false>::type&() { return reinterpret_cast<const CustomDataTagDisplayRef&>(this->GetBaseRef()); }
/// Initializes the class after creation.
/// @param[in] tag								The tag that owns the attributes.
/// @return												OK on success.
		inline Result<void> Init(BaseTag* tag) const;
/// Draws the visual representation of the tag data in 3D views.
/// @calledThreadContext
/// @note To get the current drawpass call @formatParam{bd}->@link BaseDraw::GetDrawPass GetDrawPass()@endlink.
/// @warning Only draw in @ref DRAWPASS::HIGHLIGHTS if you really know what you are doing. Otherwise always check the drawpass and then do not draw if it is @ref DRAWPASS::HIGHLIGHTS.
/// @param[in] tag								The BaseTag connected with the TagData instance. Equal to <tt>static_cast</tt><@ref TagData*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{tag}
/// @param[in] op									The host object of the tag. @cinemaOwnsPointed{object}
/// @param[in] bd									The editor's view. @callerOwnsPointed{view}
/// @param[in] bh									The helper for the editor's view. @callerOwnsPointed{view helper}
/// @return												OK on success.
		inline Result<void> Draw(BaseTag* tag, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh) const;
/// Sets information about how the active object should be displayed.
/// @param[in] tag								The BaseTag connected with the TagData instance. Equal to <tt>static_cast</tt><@ref TagData*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{tag}
/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
/// @param[in] op									The active object. @cinemaOwnsPointed{object}
/// @param[in] bd									The active editor view. @cinemaOwnsPointed{base draw}
/// @param[in] bh									The helper for active the editor view. @callerOwnsPointed{view helper}
/// @param[in] cds								The display control settings.
/// @return												OK on success.
		inline Result<void> DisplayControl(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds) const;
/// Initializes resources for the display control used in @ref DisplayControl.
/// @param[in] tag								The BaseTag connected with the TagData instance. Equal to <tt>static_cast</tt><@ref TagData*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{tag}
/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
/// @param[in] bd									The active editor view. @cinemaOwnsPointed{base draw}
/// @param[in] active							The active objects array. @cinemaOwnsPointed{array}
/// @return												OK on success.
		inline Result<void> InitDisplayControl(BaseTag* tag, BaseDocument* doc, BaseDraw* bd, const AtomArray* active) const;
/// Frees resources allocated by @ref InitDisplayControl.
/// @param[in] tag								The BaseTag connected with the TagData instance. Equal to <tt>static_cast</tt><@ref TagData*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{tag}
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type FreeDisplayControl(BaseTag* tag) const;
/// Resets any local data before destroying the class instance.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Reset() const;
	};
	/// Intermediate helper class for CustomDataTagDisplayInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, CustomDataTagDisplayRef, false>::type&() { return reinterpret_cast<const CustomDataTagDisplayRef&>(this->GetBaseRef()); }
/// Initializes the class after creation.
/// @param[in] tag								The tag that owns the attributes.
/// @return												OK on success.
		inline Result<void> Init(BaseTag* tag);
/// Draws the visual representation of the tag data in 3D views.
/// @calledThreadContext
/// @note To get the current drawpass call @formatParam{bd}->@link BaseDraw::GetDrawPass GetDrawPass()@endlink.
/// @warning Only draw in @ref DRAWPASS::HIGHLIGHTS if you really know what you are doing. Otherwise always check the drawpass and then do not draw if it is @ref DRAWPASS::HIGHLIGHTS.
/// @param[in] tag								The BaseTag connected with the TagData instance. Equal to <tt>static_cast</tt><@ref TagData*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{tag}
/// @param[in] op									The host object of the tag. @cinemaOwnsPointed{object}
/// @param[in] bd									The editor's view. @callerOwnsPointed{view}
/// @param[in] bh									The helper for the editor's view. @callerOwnsPointed{view helper}
/// @return												OK on success.
		inline Result<void> Draw(BaseTag* tag, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh);
/// Sets information about how the active object should be displayed.
/// @param[in] tag								The BaseTag connected with the TagData instance. Equal to <tt>static_cast</tt><@ref TagData*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{tag}
/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
/// @param[in] op									The active object. @cinemaOwnsPointed{object}
/// @param[in] bd									The active editor view. @cinemaOwnsPointed{base draw}
/// @param[in] bh									The helper for active the editor view. @callerOwnsPointed{view helper}
/// @param[in] cds								The display control settings.
/// @return												OK on success.
		inline Result<void> DisplayControl(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds);
/// Initializes resources for the display control used in @ref DisplayControl.
/// @param[in] tag								The BaseTag connected with the TagData instance. Equal to <tt>static_cast</tt><@ref TagData*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{tag}
/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
/// @param[in] bd									The active editor view. @cinemaOwnsPointed{base draw}
/// @param[in] active							The active objects array. @cinemaOwnsPointed{array}
/// @return												OK on success.
		inline Result<void> InitDisplayControl(BaseTag* tag, BaseDocument* doc, BaseDraw* bd, const AtomArray* active);
/// Frees resources allocated by @ref InitDisplayControl.
/// @param[in] tag								The BaseTag connected with the TagData instance. Equal to <tt>static_cast</tt><@ref TagData*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{tag}
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type FreeDisplayControl(BaseTag* tag);
/// Resets any local data before destroying the class instance.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type Reset();
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class CustomDataTagDisplayInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<CustomDataTagDisplayRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CustomDataTagDisplayInterface, maxon::StrongRefHandler, CustomDataTagDisplayRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CustomDataTagDisplayInterface, maxon::StrongRefHandler, CustomDataTagDisplayRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// CustomDataTagDisplayRef is the reference class of CustomDataTagDisplayInterface.
///
/// CustomDataTagDisplayInterface can be optionally implemented for each CustomDataTagClassInterface implementation and defines
/// if and how a CustomDataTag should be displayed in the viewport.
class CustomDataTagDisplayRef : public CustomDataTagDisplayInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(CustomDataTagDisplayRef, typename CustomDataTagDisplayInterface::Hxx1::Reference);
};

class MeshAttributeClass;

struct MeshAttributeClassInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MeshAttributeClassInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(MeshAttributeClassInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct MeshAttributeClassInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = MeshAttributeClass;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for MeshAttributeClassInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MeshAttributeClass, false>::type&() const { return reinterpret_cast<const MeshAttributeClass&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MeshAttributeClass, false>::type&() { return reinterpret_cast<const MeshAttributeClass&>(this->GetBaseRef()); }
/// Returns the DataType this class manages, e.g. Vector2d32 for UV maps.
/// @return												The DataType.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type GetDataType() const;
/// Interpolates linearly between two values. Both addresses need to be cast to the appropriate data type.
/// @param[in,out] data1					The address of the first value. The value will be overwritten with the result.
/// @param[in] data2							The address of the second value.
/// @param[in] blend							The blend percentage [0.0..blend..1.0]
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type InterpolateLinear(void* data1, const void* data2, Float blend) const;
/// Interpolates a value in the outline using the specified weights. The addresses in data and outline need to be cast to the appropriate data type.
/// @param[in,out] data						The address of the value. The value will be overwritten with the result.
/// @param[in] outline						The outline data used to perform the interpolation.
/// @param[in] weights						Weights to be used for the interpolation, represent the interpolation distance from each outline edge.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type InterpolateInOutline(void* data, const Block<void*>& outline, const Block<Float>& weights) const;
/// Returns the default value for this attribute. The caller owns the passed pointer.
/// @param[out] data							A pointer filled with the default value.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type GetDefaultValue(void* data) const;
/// Compares two data values for "less than".
/// In most cases this returns the MeshAttributeClassInterface::GetDataType()::Compare() but the developer is free to customize comparison if needed.
/// @param[in] data1							First data to compare.
/// @param[in] data2							Second data to compare.
/// @return												True if the content of data1 is smaller then data2.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type AtrLessThen(const void* data1, const void* data2) const;
/// Compares two data values for equality.
/// In most of cases just returns the MeshAttributeClassInterface::GetDataType()::IsEqual() but the developer is free to customize comparison if needed.
/// @param[in] data1							First data to compare.
/// @param[in] data2							Second data to compare.
/// @return												True if the content of data1 is equal to data2.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type AtrIsEqual(const void* data1, const void* data2) const;
/// Defines how to add two data values.
/// @param[in,out] data1					The address of the first value. The value will be overwritten with the result.
/// @param[in] data2							The address of the second value.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type AtrAdd(void* data1, const void* data2) const;
/// Defines how to subtract two data values.
/// @param[in,out] data1					The address of the first value. The value will be overwritten with the result.
/// @param[in] data2							The address of the second value.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type AtrSubstract(void* data1, const void* data2) const;
/// Defines how to multiply two data values.
/// @param[in,out] data1					The address of the first value. The value will be overwritten with the result.
/// @param[in] data2							The address of the second value.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type AtrMultiply(void* data1, const void* data2) const;
/// Defines how to multiply a data value by a float value.
/// @param[in,out] data						The address of the data value. The value will be overwritten with the result.
/// @param[in] value							The value to be used for the multiplication.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type AtrMultiply(void* data, Float value) const;
/// Defines how to divide two data values.
/// @param[in,out] data1					The address of the first value. The value will be overwritten with the result.
/// @param[in] data2							The address of the second value.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type AtrDivide(void* data1, const void* data2) const;
/// Defines how to divide a data value by a float value.
/// @param[in,out] data						The address of the data value. The value will be overwritten with the result.
/// @param[in] value							The value to be used for the division.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type AtrDivide(void* data, Float value) const;
/// Returns a readable string of the content of a data pointer.
/// @param[in,out] data						The address of the data value.
/// @param[in] formatStatement		Nullptr or additional formatting instructions. Currently no additional formatting instructions are supported.
/// @return												The converted result.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type AtrToString(const void* data, const FormatStatement* formatStatement) const;
	};
	/// Intermediate helper class for MeshAttributeClassInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for MeshAttributeClassInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class MeshAttributeClassInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<MeshAttributeClass>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const MeshAttributeClassInterface, maxon::StrongRefHandler, MeshAttributeClass>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const MeshAttributeClassInterface, maxon::StrongRefHandler, MeshAttributeClass>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class MeshAttributeClassInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MeshAttributeClassInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MeshAttributeClassInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// MeshAttributeClass is the reference class of MeshAttributeClassInterface.
///
/// By implementing this interface, it is possible to define a new mesh attribute type so that a data type can be attached to mesh vertices or to mesh polyvertices.
/// The interface needs to be implemented with the data type description, which has to be registered using MAXON_MESHATTRIBUTE and MAXON_DATATYPE, and all arithmetic and comparison functions.
class MeshAttributeClass : public MeshAttributeClassInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(MeshAttributeClass, typename MeshAttributeClassInterface::Hxx1::Reference);
};

class CustomDataTagClass;

struct CustomDataTagClassInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, CustomDataTagClassInterface>::value || MeshAttributeClassInterface::HasBase::template Check<I>::value; static I* Cast(CustomDataTagClassInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct CustomDataTagClassInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = CustomDataTagClass;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<MeshAttributeClassInterface>;
	/// Intermediate helper class for CustomDataTagClassInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CustomDataTagClass, false>::type&() const { return reinterpret_cast<const CustomDataTagClass&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CustomDataTagClass, false>::type&() { return reinterpret_cast<const CustomDataTagClass&>(this->GetBaseRef()); }
/// Returns the Tag plugin ID to be registered with this implementation.
/// @return												A unique plugin ID.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type GetTagPluginId() const;
/// Returns the Tag string name to be registered with this implementation.
/// @return												A string that represent the tag in the interface.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const String&>, const String&>::type GetTagPluginName() const;
/// Returns the resource id for the Tag.
/// @return												A string that represent the tag res ID.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const String&>, const String&>::type GetResourceId() const;
/// Returns the Tag level to be used as data versioning system.
/// @return												The disk level.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type GetTagPluginLevel() const;
/// Get the Id of the display implementation or an empty Id if display is not implemented.
/// @return												The id of the associated display implementation.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Id>, Id>::type GetDisplayClassId() const;
/// Returns if the datatype is compatible with the SDS interpolation.
/// SDS implementations, both internal and OSD, are only able to interpolate float values.
/// The floatSize allows to define how many values are used for each entry, for example a vector will have a floatSize = 3.
/// @param[out] floatSize					The number of float values that the datatype contains.
/// @return												True if this interface can be processed for SDS interpolations.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsSdsCompatible(Int32& floatSize) const;
/// Reads a single data entry from a file.
/// @param[in] data								The data pointer.
/// @param[in] hf									The file handle to read.
/// @param[in] level							The disk level.
/// @return												OK on success.
		inline Result<void> Read(void* data, HyperFile* hf, Int32 level) const;
/// Writes a single data entry to a fil.
/// @param[in] data								The data pointer.
/// @param[in] hf									The file handle to write on.
/// @return												OK on success.
		inline Result<void> Write(const void* data, HyperFile* hf) const;
/// Gets the icon id according to the data location (per vertex vs. per polyvertex).
/// @param[in] perPolyVertex			If true the polyvertex icon id is returned.
/// @return												The icon id or NOTOK if there is no icon.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type GetIcon(Bool perPolyVertex) const;
/// By default, all implementations provide a standard UI.
/// Gets the default resource id in case a custom AM UI is not needed.
/// @return												The description string identifier.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const String&>, const String&>::type GetDefaultResourceId() const;
/// Returns the tag flags to be registered with this implementation.
/// @return												The tag flgas.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type GetTagPluginFlags() const;
	};
	/// Intermediate helper class for CustomDataTagClassInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for CustomDataTagClassInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename MeshAttributeClassInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename MeshAttributeClassInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename MeshAttributeClassInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class CustomDataTagClassInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<CustomDataTagClass>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const CustomDataTagClassInterface, maxon::StrongRefHandler, CustomDataTagClass>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const CustomDataTagClassInterface, maxon::StrongRefHandler, CustomDataTagClass>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class CustomDataTagClassInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CustomDataTagClassInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CustomDataTagClassInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// CustomDataTagClass is the reference class of CustomDataTagClassInterface.
///
/// CustomDataTagClassInterface uses MeshAttributeClassInterface as a base interface and allows to add informations and functionality to the mesh attribute to be used as tag.
/// It mainly contains the information about the CustomDataTag registration, read/write, icons and the optional display implementation.
/// By using the MAXON_CUSTOMDATATAG macro, only the Read, Write and GetIcon methods need to be implemented.
///
/// @code
///	class VertexColorImpl : public Component<VertexColorImpl, CustomDataTagClassInterface>
///	{
///		MAXON_COMPONENT();
///		MAXON_CUSTOMDATATAG(ID_CUSTOMDATA_TAG_VC, "Vertex Color Tag"_s, ""_s, Id("net.maxon.mesh_misc.meshattibutedisplay.vertxecolor"), 0, 1, flags);
///
///	public:
///
///		...
///		MAXON_METHOD Result<void> Read(void* data, HyperFile* hf, Int32 level) const;
///
///		MAXON_METHOD Result<void> Write(const void* data, HyperFile* hf) const;
///
///		MAXON_METHOD Int32 GetIcon(Bool perPolyVertex) const;
///
///	};
/// @endcode
class CustomDataTagClass : public CustomDataTagClassInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(CustomDataTagClass, typename CustomDataTagClassInterface::Hxx1::Reference);
};

#endif
