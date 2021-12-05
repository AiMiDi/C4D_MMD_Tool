#if 1
class LayerSet;

struct LayerSetInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = LayerSet;
	/// Intermediate helper class for LayerSetInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using LayerHash = LayerSetInterface::LayerHash;
/// Gets the selected layers.
/// @return												The layers.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const LayerHash&>, const LayerHash&>::type GetSelectedLayers() const;
/// Gets the selected image.
/// @return												The image.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type GetSelectedImage() const;
/// Gets the mode.
/// @return												The mode.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<LAYERSETMODE>, LAYERSETMODE>::type GetMode() const;
/// Gets the alpha calculation mode.
/// @return												The mode.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type GetCalculateAlpha() const;
/// Compares this LayerSet with another one if both are identical.
/// @param[in] other							The other LayerSet to compare this object to.
/// @return												True if the object is identical.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsEqual(const LayerSetInterface* other) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type HasLayerSelection() const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsLayerEnabled(const String& name) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type HasMultiImageSelection() const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsMultiImageEnabled(const String& name) const;
/// Describe all elements of this class for I/O operations.
/// @param[in] stream							The stream that is used to register the class members.
/// @return												OK on success.
		static inline Result<void> DescribeIO(const DataSerializeInterface& stream);
	};
	/// Intermediate helper class for LayerSetInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
/// Sets the selected layers.
/// @param[in] layers							The layers to set.
/// @return												OK on success.
		inline Result<void> SetSelectedLayers(const LayerHash& layers) const;
/// Sets the selected image.
/// @param[in] image							The image to set.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type SetSelectedImage(const String& image) const;
/// Sets the mode.
/// @param[in] mode								The mode to set.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type SetMode(LAYERSETMODE mode) const;
/// Sets the alpha calculation mode.
/// @param[in] calcAlpha					The mode to set.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type SetCalculateAlpha(Bool calcAlpha) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type FlushLayers() const;
		inline Result<void> RemoveLayer(const String& layer) const;
		inline Result<void> AddLayer(const String& layer) const;
	};
	/// Intermediate helper class for LayerSetInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, LayerSet, false>::type&() const { return reinterpret_cast<const LayerSet&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, LayerSet, false>::type&() { return reinterpret_cast<const LayerSet&>(this->GetBaseRef()); }
/// Sets the selected layers.
/// @param[in] layers							The layers to set.
/// @return												OK on success.
		inline Result<void> SetSelectedLayers(const LayerHash& layers);
/// Sets the selected image.
/// @param[in] image							The image to set.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type SetSelectedImage(const String& image);
/// Sets the mode.
/// @param[in] mode								The mode to set.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type SetMode(LAYERSETMODE mode);
/// Sets the alpha calculation mode.
/// @param[in] calcAlpha					The mode to set.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type SetCalculateAlpha(Bool calcAlpha);
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type FlushLayers();
		inline Result<void> RemoveLayer(const String& layer);
		inline Result<void> AddLayer(const String& layer);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWReferenceFunctionsImpl<typename ST::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type
	> { };
};
class LayerSetInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<LayerSet>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const LayerSetInterface, maxon::StrongCOWRefHandler, LayerSet>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const LayerSetInterface, maxon::StrongCOWRefHandler, LayerSet>>>>);
	using NonConst = Hxx1::NonConstRef;
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<LayerSet> Create();
};

class LayerSetInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<LayerSetInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<LayerSetInterface, maxon::StrongRefHandler, NonConstRef>>>>);
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
