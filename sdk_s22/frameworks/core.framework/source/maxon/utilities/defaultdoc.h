#ifndef DEFAULTDOC_H__
#define DEFAULTDOC_H__

#error "This file needn't be included, it's only used for defaults for @copydoc."

namespace maxon
{

//----------------------------------------------------------------------------------------
/// The only purpose of this class is to be used in \@copydoc commands for standard
/// functions like CopyFrom or GetHashCode. For example to add a default documentation
/// to a CopyFrom function of a class, write
/// @code
/// /// @copydoc DefaultDoc::CopyFrom
///	Result<void> CopyFrom(const MyClass& src);
/// @endcode
//----------------------------------------------------------------------------------------
class DefaultDoc
{
public:
	//----------------------------------------------------------------------------------------
	/// Constructs a @CLASS object with default values.
	//----------------------------------------------------------------------------------------
	DefaultDoc() = default;

	//----------------------------------------------------------------------------------------
	/// Makes this @CLASS a copy of #src by copying the contents of #src into this @CLASS.
	/// @param[in] src								Another @CLASS to be used as source for the copy operation.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> CopyFrom(const DefaultDoc& src);

	//----------------------------------------------------------------------------------------
	/// Resets this @CLASS to the state it has right after default construction. This includes
	/// freeing all resources held by this @CLASS.
	//----------------------------------------------------------------------------------------
	void Reset();

	//----------------------------------------------------------------------------------------
	/// Returns the hash code of this @CLASS.
	/// @return												Hash code of this @CLASS.
	//----------------------------------------------------------------------------------------
	UInt GetHashCode() const;

	//----------------------------------------------------------------------------------------
	/// Checks if this @CLASS equals #other.
	/// @param[in] other							Another @CLASS.
	/// @return												True if this equals #other, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool operator ==(const DefaultDoc& other) const;

	//----------------------------------------------------------------------------------------
	/// Checks if this @CLASS is not equal to #other.
	/// @param[in] other							Another @CLASS.
	/// @return												True if this is not equal to #other, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool operator !=(const DefaultDoc& other) const;

	//----------------------------------------------------------------------------------------
	/// Checks if this @CLASS is less than #other.
	/// @param[in] other							Another @CLASS.
	/// @return												True if this is less than #other, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool operator <(const DefaultDoc& other) const;

	//----------------------------------------------------------------------------------------
	/// Checks if this @CLASS is less than or equal to #other.
	/// @param[in] other							Another @CLASS.
	/// @return												True if this is less than or equal to #other, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool operator <=(const DefaultDoc& other) const;

	//----------------------------------------------------------------------------------------
	/// Checks if this @CLASS is greater than #other.
	/// @param[in] other							Another @CLASS.
	/// @return												True if this is greater than #other, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool operator >(const DefaultDoc& other) const;

	//----------------------------------------------------------------------------------------
	/// Checks if this @CLASS is greater than or equal to #other.
	/// @param[in] other							Another @CLASS.
	/// @return												True if this is greater than or equal to #other, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool operator >=(const DefaultDoc& other) const;

	//----------------------------------------------------------------------------------------
	/// Compares this and #other.
	/// @param[in] other							Another @CLASS.
	/// @return												Result of the comparison.
	//----------------------------------------------------------------------------------------
	COMPARERESULT Compare(const DefaultDoc& other) const;

	//----------------------------------------------------------------------------------------
	/// Returns a String representation of this @CLASS.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction.
	/// @return												String representation of this @CLASS.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement) const;
};

}

#endif // DEFAULTDOC_H__

