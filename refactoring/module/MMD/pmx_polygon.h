/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/10/2
File:			pmx_polygon.h
Description:	pmx polygon data

**************************************************************************/

#ifndef _PMX_POLYGON_H_
#define _PMX_POLYGON_H_
#include "pmx_element.hpp"

struct PMXPolygonData
{
	UInt32 a, b, c;

	explicit PMXPolygonData(const Int32 t_a = 0, const Int32 t_b = 1, const Int32 t_c = 2) : a(t_a),b(t_b),c(t_c){}

	const UInt32& operator[](const Int32 index) const
	{
		return reinterpret_cast<const UInt32*>(this)[index & 2];
	}

	explicit operator CPolygon() const
	{
		return {static_cast<Int32>(a), static_cast<Int32>(b), static_cast<Int32>(c)};
	}
};

class PMXPolygon final : public PMXElement
{
	GENERATE_MMD_CLASS_BODY(PMXPolygon, PMXPolygonData)
public:
	/**
	 * \brief Default constructor function
	 */
	explicit PMXPolygon(const PMXModelInfo* model_info) : PMXElement(model_info), m_data(std::make_unique<data_type>()) {}
	/**
	 * \brief Destructor function
	 */
	~PMXPolygon() override = default;
	/**
	 * \brief Read PMX polygon data from a pmx file
	 * \param file file pmx file
	 * \return Successful TRUE, other FALSE.
	 */
	Bool ReadFromFile(BaseFile* file) override;
};

#endif // !_PMX_POLYGON_H_
