#ifndef CORENODES_CONVERSION_H__
#define CORENODES_CONVERSION_H__

#include "maxon/corenodes_lib.h"
#include "maxon/corenodes_implementer.h"

namespace maxon
{

namespace corenodes
{

// Turn off warnings for ConversionNode
MAXON_WARNING_PUSH

#if defined(MAXON_COMPILER_MSVC)
	#pragma warning(disable:4244)
	#pragma warning(disable:4242)
	#if MAXON_COMPILER_MSVC < 1910
		#pragma warning(disable:4800) // Performance warning for bool T to bool conversion.
	#endif
#elif defined(MAXON_COMPILER_CLANG)
	#pragma clang diagnostic ignored "-Wconversion"
	#pragma clang diagnostic ignored "-Wfloat-conversion"
	#pragma clang diagnostic ignored "-Wsign-conversion"
#endif

//----------------------------------------------------------------------------------------
/// A ConversionNode is a BatchMicroNode which converts from FROM to TO. To implement and
/// register a core node conversion, you have to use MAXON_CORENODE_REGISTER_CONVERSION
/// with the appropriate types. In addition you have to specialize ConversionNode for those types
/// if the conversion can't be done by a constructor of TO which takes a FROM argument
/// (which is what this ConversionNode template does).
//----------------------------------------------------------------------------------------
template <typename TO, typename FROM, typename = void> class ConversionNode : public OperatorNode<ConversionNode<TO, FROM>, TO(FROM)>
{
public:
	static ResultOk<void> Process(TO& out, const FROM& in)
	{
		// We don't use the assignment operator because it may not exist, instead we directly construct
		// the target from the source which can make use of explicit conversion constructors.
		out.~TO();
		new (&out) TO(in);
		return OK;
	}
};

// Turn on warnings again.
MAXON_WARNING_POP


//----------------------------------------------------------------------------------------
/// MAXON_CORENODE_REGISTER_CONVERSION registers a conversion core node. The core node
/// compiler uses such nodes to implicitly convert values where required. Also you can
/// ask CoreNodesLib::GetConversion() for a ConversionSequence of several conversion core nodes
/// which is capable of converting from a source type to a destination type.
///
/// If the conversion is implemented by a constructor of #TO which takes a #FROM argument
/// the MAXON_CORENODE_REGISTER_CONVERSION macro alone is sufficient to implement and
/// register the conversion node. Otherwise you have to specialize the ConversionNode template
/// before you use the MAXON_CORENODE_REGISTER_CONVERSION macro:
/// @code{corenodes_conversion}
//! template <> class ConversionNode<Float, TimeValue> : public OperatorNode<ConversionNode<Float, TimeValue>, Float(TimeValue)>
//! {
//! public:
//! 	static ResultOk<void> Process(Float& out, const TimeValue& value)
//! 	{
//! 		out = value.GetSeconds();
//! 		return OK;
//! 	}
//! };
//! 
//! MAXON_CORENODE_REGISTER_CONVERSION(Float, TimeValue, CONVERSION_FLAGS::NONE);
/// @endcode
///
/// @warning
/// Take care of properly setting up the flags. The example uses CONVERSION_FLAGS::NONE
/// because there is a one-to-one correspondence between Float and TimeValue. However
/// typically you have narrowing conversions (such as from String to Float) or widening
/// conversions (such as from Float to String), then you must not use CONVERSION_FLAGS::NONE,
/// see CONVERSION_FLAGS. If not set properly the core nodes compiler might implicitly choose
/// undesirable conversions.
///
/// @param[in] TO									The destination type of the conversion.
/// @param[in] FROM								The source type of the conversion.
/// @param[in] flags							The conversion flags, take care of setting the correct flags (see warning).
//----------------------------------------------------------------------------------------
#define MAXON_CORENODE_REGISTER_CONVERSION(TO, FROM, flags) \
	MAXON_CORENODE_REGISTER_PURE_WITH_METADATA(maxon::corenodes::ConversionNode, "net.maxon.corenode.convert", \
																						 meta.Set(maxon::corenodes::CoreNodeInterface::ConversionFlags, flags) iferr_return; \
																						 meta.Set(maxon::corenodes::CoreNodeInterface::Type, maxon::GetDataType<TO>()) iferr_return; \
																						 meta.Set(maxon::corenodes::CoreNodeInterface::SourceType, maxon::GetDataType<FROM>()) iferr_return;, \
																						 TO, FROM);


//----------------------------------------------------------------------------------------
/// A ConversionSequence is a sequence of zero to two conversions (implemented by ConversionNode
/// and registered by MAXON_CORENODE_REGISTER_CONVERSION) which are needed to convert
/// from a source type to a destination type. It is created by CoreNodesLib::GetConversion().
//----------------------------------------------------------------------------------------
class ConversionSequence
{
public:
	//----------------------------------------------------------------------------------------
	/// Constructs an empty conversion sequence.
	//----------------------------------------------------------------------------------------
	ConversionSequence() = default;

	//----------------------------------------------------------------------------------------
	/// Constructs a conversion sequence consisting of a single conversion node.
	/// @param[in] c1									The conversion node.
	/// @param[in] flags							The conversion flags of the conversion.
	//----------------------------------------------------------------------------------------
	ConversionSequence(const CoreNode& c1, CONVERSION_FLAGS flags) : _flags(flags), _count(1)
	{
		_sequence[0] = c1;
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a conversion sequence consisting of a two conversion nodes.
	/// @param[in] c1									The first conversion node.
	/// @param[in] c2									The second conversion node.
	/// @param[in] flags							The conversion flags of the conversion.
	//----------------------------------------------------------------------------------------
	ConversionSequence(const CoreNode& c1, const CoreNode& c2, CONVERSION_FLAGS flags) : _flags(flags), _count(2)
	{
		_sequence[0] = c1;
		_sequence[1] = c2;
	}

	Result<Data> Convert(const ConstDataPtr& source) const
	{
		return CoreNodesLib::Convert(*this, source);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the conversion node at #index. The conversion sequence applies conversion nodes in ascending order.
	/// @param[in] index							Index within this sequence.
	/// @return												Conversion node at #index.
	//----------------------------------------------------------------------------------------
	const CoreNode& operator [](Int index) const
	{
		return _sequence[index];
	}

	//----------------------------------------------------------------------------------------
	/// Returns the number of conversions of this sequence (from zero to two).
	/// @return												Number of conversions.
	//----------------------------------------------------------------------------------------
	Int GetCount() const
	{
		return _count;
	}

	//----------------------------------------------------------------------------------------
	/// Returns this conversion sequence as a block.
	/// The conversion sequence applies conversion nodes in ascending order.
	/// @return												Conversion sequence as a block.
	//----------------------------------------------------------------------------------------
	Block<const CoreNode> ToBlock() const
	{
		return {_sequence, _count};
	}

	/// @copydoc ToBlock
	operator Block<const CoreNode>() const
	{
		return {_sequence, _count};
	}

	//----------------------------------------------------------------------------------------
	/// Returns the conversion flags of this sequence. They are the combination of the
	/// flags of the individual conversion nodes.
	/// @return												Conversion flags of this sequence.
	//----------------------------------------------------------------------------------------
	CONVERSION_FLAGS GetFlags() const
	{
		return _flags;
	}

	/// @copydoc DefaultDoc::operator==
	Bool operator ==(const ConversionSequence& other) const
	{
		return CoreNodesLib::IsEqualConversionSequence(*this, other);
	}

	/// @copydoc DefaultDoc::operator!=
	Bool operator !=(const ConversionSequence& other) const
	{
		return !this->operator ==(other);
	}

	using PartiallyOrdered = std::true_type;

	//----------------------------------------------------------------------------------------
	/// Checks if this conversion sequence is better than #other. For example a shorter
	/// sequence is better than a longer one, or the sequence
	/// Vec3<Float> &rarr; Float &rarr; Int is better than Vec3<Float> &rarr; Vec3<Int> &rarr; Int.
	/// This implements a partial ordering, i.e., there are pairs of sequences where
	/// one sequence is neither better nor worse than the other one.
	/// @param[in] other							Another conversion sequence.
	/// @return												True if this sequence is better than #other, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool operator >(const ConversionSequence& other) const
	{
		return CoreNodesLib::IsBetterConversionSequence(*this, other);
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this conversion sequence is better than #other or the same.
	/// This implements a partial ordering. See operator> for more details.
	/// @param[in] other							Another conversion sequence.
	/// @return												True if this sequence is better than #other or the same, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool operator >=(const ConversionSequence& other) const
	{
		return this->operator ==(other) || this->operator >(other);
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this conversion sequence is worse than #other.
	/// This implements a partial ordering. See operator> for more details.
	/// @param[in] other							Another conversion sequence.
	/// @return												True if this sequence is worse than #other, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool operator <(const ConversionSequence& other) const
	{
		return other.operator >(*this);
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this conversion sequence is worse than #other or the same.
	/// This implements a partial ordering. See operator> for more details.
	/// @param[in] other							Another conversion sequence.
	/// @return												True if this sequence is worse than #other or the same, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool operator <=(const ConversionSequence& other) const
	{
		return other.operator >=(*this);
	}

	/// @copydoc DefaultDoc::ToString
	String ToString(const FormatStatement* fs) const;

private:
	CONVERSION_FLAGS _flags = CONVERSION_FLAGS::NONE;
	Int _count = 0;
	CoreNode _sequence[2];
};

}

}

#endif // CORENODES_CONVERSION_H__
