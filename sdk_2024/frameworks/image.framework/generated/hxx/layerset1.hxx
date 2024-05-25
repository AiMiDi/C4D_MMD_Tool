#if 1
class LayerSet;

struct LayerSetInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = LayerSet;
	/// Intermediate helper class for LayerSetInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = LayerSetInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(LayerSetInterface**);
		using LayerHash = LayerSetInterface::LayerHash;
/// Gets the selected layers.
/// @return												The layers.
		inline HXXADDRET2(const LayerHash&) GetSelectedLayers() const;
/// Gets the selected image.
/// @return												The image.
		inline HXXADDRET2(String) GetSelectedImage() const;
/// Gets the mode.
/// @return												The mode.
		inline HXXADDRET2(LAYERSETMODE) GetMode() const;
/// Gets the alpha calculation mode.
/// @return												The mode.
		inline HXXADDRET2(Bool) GetCalculateAlpha() const;
/// Compares this LayerSet with another one if both are identical.
/// @param[in] other							The other LayerSet to compare this object to.
/// @return												True if the object is identical.
		inline HXXADDRET2(Bool) IsEqual(const LayerSetInterface* other) const;
		inline HXXADDRET2(Bool) HasLayerSelection() const;
		inline HXXADDRET2(Bool) IsLayerEnabled(const String& name) const;
		inline HXXADDRET2(Bool) HasMultiImageSelection() const;
		inline HXXADDRET2(Bool) IsMultiImageEnabled(const String& name) const;
/// Describe all elements of this class for I/O operations.
/// @param[in] stream							The stream that is used to register the class members.
/// @return												OK on success.
		static inline Result<void> DescribeIO(const DataSerializeInterface& stream);
	};
	/// Intermediate helper class for LayerSetInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = LayerSetInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(LayerSetInterface**);
/// Sets the selected layers.
/// @param[in] layers							The layers to set.
/// @return												OK on success.
		inline Result<void> SetSelectedLayers(const LayerHash& layers) const;
/// Sets the selected image.
/// @param[in] image							The image to set.
		inline HXXADDRET2(void) SetSelectedImage(const String& image) const;
/// Sets the mode.
/// @param[in] mode								The mode to set.
		inline HXXADDRET2(void) SetMode(LAYERSETMODE mode) const;
/// Sets the alpha calculation mode.
/// @param[in] calcAlpha					The mode to set.
		inline HXXADDRET2(void) SetCalculateAlpha(Bool calcAlpha) const;
		inline HXXADDRET2(void) FlushLayers() const;
		inline Result<void> RemoveLayer(const String& layer) const;
		inline Result<void> AddLayer(const String& layer) const;
	};
	/// Intermediate helper class for LayerSetInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = LayerSetInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(LayerSetInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, LayerSet, false>::type&() const { return reinterpret_cast<const LayerSet&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, LayerSet, false>::type&() { return reinterpret_cast<const LayerSet&>(this->GetBaseRef()); }
/// Sets the selected layers.
/// @param[in] layers							The layers to set.
/// @return												OK on success.
		inline Result<void> SetSelectedLayers(const LayerHash& layers);
/// Sets the selected image.
/// @param[in] image							The image to set.
		inline HXXADDRET1(void) SetSelectedImage(const String& image);
/// Sets the mode.
/// @param[in] mode								The mode to set.
		inline HXXADDRET1(void) SetMode(LAYERSETMODE mode);
/// Sets the alpha calculation mode.
/// @param[in] calcAlpha					The mode to set.
		inline HXXADDRET1(void) SetCalculateAlpha(Bool calcAlpha);
		inline HXXADDRET1(void) FlushLayers();
		inline Result<void> RemoveLayer(const String& layer);
		inline Result<void> AddLayer(const String& layer);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ST::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ST::type>, Fn<typename ST::type>>::type
	> { };
};
class LayerSetInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWFnDoxy<LayerSet>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const LayerSetInterface, maxon::StrongCOWRefHandler, LayerSet>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const LayerSetInterface, maxon::StrongCOWRefHandler, LayerSet>>>>);
	using NonConst = Hxx1::NonConstRef;
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<LayerSet> Create();
};

class LayerSetInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<LayerSetInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<LayerSetInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// LayerSet is the reference class of LayerSetInterface.
///
/// Class to choose layers or alphas from an image.
class LayerSet : public LayerSetInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(LayerSet, typename LayerSetInterface::Hxx1::Reference);
};

#endif
