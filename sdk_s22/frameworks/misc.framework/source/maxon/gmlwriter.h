#ifndef GMLWRITER_H__
#define GMLWRITER_H__

#include "maxon/object.h"
#include "maxon/array.h"
#include "maxon/dataformat_base.h"

namespace maxon
{

struct GmlNode
{
	explicit GmlNode(const void* n = nullptr, Int i = -1) : node(n), index(i) { }

	MAXON_OPERATOR_EQUALITY_HASHCODE(GmlNode, node, index);

	explicit operator Bool() const
	{
		return node != nullptr;
	}

	const void* node;
	Int index;
};

struct GmlTarget
{
	enum class LABEL_POSITION
	{
		SOURCE = 0,
		CENTER = 1,
		TARGET = 2
	} MAXON_ENUM_LIST_CLASS(LABEL_POSITION);

	explicit GmlTarget(const GmlNode& n = GmlNode(), Int32 c = -1, Int32 w = -1, const Char* s = nullptr,
										 const String& t = String(), LABEL_POSITION pos = LABEL_POSITION::CENTER, Bool rev = false, const Char* tArr = "standard", const Char* sArr = nullptr)
		: node(n), color(c), width(w), style(s), label(t), position(pos), reversed(rev), targetArrow(tArr), sourceArrow(sArr)
	{
	}

	GmlNode node;
	Int32 color;
	Int32 width;
	const Char* style;
	String label;
	LABEL_POSITION position;
	Bool reversed;
	const Char* targetArrow;
	const Char* sourceArrow;
};

struct GmlNodeAttribs
{
	enum class ALIGNMENT
	{
		LEFT = 0,
		CENTER = 1,
		RIGHT = 2
	} MAXON_ENUM_LIST_CLASS(ALIGNMENT);

	explicit GmlNodeAttribs(const String& t = String(), Int32 bg = -1, const Char* sh = nullptr, Int32 fg = -1,
													ALIGNMENT a = ALIGNMENT::CENTER, Int32 ow = -1) : text(t), bgColor(bg), shape(sh), fgColor(fg), align(a), outlineWidth(ow)
	{
	}

	String text;
	Int32 bgColor;
	const Char* shape;
	Int32 fgColor;
	ALIGNMENT align;
	Int32 outlineWidth;
};

class GmlGraphInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(GmlGraphInterface, MAXON_REFERENCE_CONST, "net.maxon.interface.gmlgraph");

public:
	MAXON_METHOD Result<Bool> GetTargets(const GmlNode& node, const ValueReceiver<const GmlTarget&>& targets) const;

	MAXON_METHOD GmlNode GetParent(const GmlNode& node) const;

	MAXON_METHOD GmlNodeAttribs GetNodeAttribs(const GmlNode& node) const;
};

class GmlGraph;

class GmlWriterInterface
{
	MAXON_INTERFACE_NONVIRTUAL(GmlWriterInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.gmlwriter");

public:
	static MAXON_METHOD GmlWriterInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION, const GmlGraph& graph);

	MAXON_METHOD Result<void> Add(const GmlNode& node);

	MAXON_METHOD Result<void> Write(const WriterRef<Utf32Char>& writer);
};

#include "gmlwriter1.hxx"

#include "gmlwriter2.hxx"

} // namespace maxon

#endif // GMLWRITER_H__
