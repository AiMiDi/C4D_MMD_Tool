#pragma once

namespace cmt_runtime
{

// SDK-independent field algebra shared by material morph evaluation and tests.
// VectorType requires x/y/z components, a three-component constructor, and
// vector/scalar addition and multiplication. ScalarType follows C4D Float.
template <class VectorType, class ScalarType>
struct MaterialMorphValues
{
	explicit MaterialMorphValues(const ScalarType initial)
		: diffuse_rgb(initial), diffuse_alpha(initial), specular(initial), specular_power(initial),
		  ambient(initial), edge_color_rgb(initial), edge_color_alpha(initial), edge_size(initial),
		  texture_factor_rgb(initial), texture_factor_alpha(initial), sphere_texture_factor_rgb(initial),
		  sphere_texture_factor_alpha(initial), toon_texture_factor_rgb(initial), toon_texture_factor_alpha(initial)
	{
	}

	VectorType diffuse_rgb;
	ScalarType diffuse_alpha;
	VectorType specular;
	ScalarType specular_power;
	VectorType ambient;
	VectorType edge_color_rgb;
	ScalarType edge_color_alpha;
	ScalarType edge_size;
	VectorType texture_factor_rgb;
	ScalarType texture_factor_alpha;
	VectorType sphere_texture_factor_rgb;
	ScalarType sphere_texture_factor_alpha;
	VectorType toon_texture_factor_rgb;
	ScalarType toon_texture_factor_alpha;
};

template <class VectorType, class ScalarType>
class MaterialMorphAccumulator
{
public:
	template <class OffsetType>
	void Apply(const OffsetType& offset, const ScalarType weight)
	{
		if (weight == ScalarType(0))
			return;
		const bool additive = offset.op_type == 1;
		ApplyVector(multiply_.diffuse_rgb, add_.diffuse_rgb, offset.diffuse_rgb, weight, additive);
		ApplyScalar(multiply_.diffuse_alpha, add_.diffuse_alpha, offset.diffuse_alpha, weight, additive);
		ApplyVector(multiply_.specular, add_.specular, offset.specular, weight, additive);
		ApplyScalar(multiply_.specular_power, add_.specular_power, offset.specular_power, weight, additive);
		ApplyVector(multiply_.ambient, add_.ambient, offset.ambient, weight, additive);
		ApplyVector(multiply_.edge_color_rgb, add_.edge_color_rgb, offset.edge_color_rgb, weight, additive);
		ApplyScalar(multiply_.edge_color_alpha, add_.edge_color_alpha, offset.edge_color_alpha, weight, additive);
		ApplyScalar(multiply_.edge_size, add_.edge_size, offset.edge_size, weight, additive);
		ApplyVector(multiply_.texture_factor_rgb, add_.texture_factor_rgb, offset.texture_factor_rgb, weight, additive);
		ApplyScalar(multiply_.texture_factor_alpha, add_.texture_factor_alpha, offset.texture_factor_alpha, weight, additive);
		ApplyVector(multiply_.sphere_texture_factor_rgb, add_.sphere_texture_factor_rgb, offset.sphere_texture_factor_rgb, weight, additive);
		ApplyScalar(multiply_.sphere_texture_factor_alpha, add_.sphere_texture_factor_alpha, offset.sphere_texture_factor_alpha, weight, additive);
		ApplyVector(multiply_.toon_texture_factor_rgb, add_.toon_texture_factor_rgb, offset.toon_texture_factor_rgb, weight, additive);
		ApplyScalar(multiply_.toon_texture_factor_alpha, add_.toon_texture_factor_alpha, offset.toon_texture_factor_alpha, weight, additive);
	}

	template <class StateType>
	StateType Compose(const StateType& base) const
	{
		StateType state = base;
		state.diffuse_rgb = Multiply(base.diffuse_rgb, multiply_.diffuse_rgb) + add_.diffuse_rgb;
		state.diffuse_alpha = base.diffuse_alpha * multiply_.diffuse_alpha + add_.diffuse_alpha;
		state.specular = Multiply(base.specular, multiply_.specular) + add_.specular;
		state.specular_power = base.specular_power * multiply_.specular_power + add_.specular_power;
		state.ambient = Multiply(base.ambient, multiply_.ambient) + add_.ambient;
		state.edge_color_rgb = Multiply(base.edge_color_rgb, multiply_.edge_color_rgb) + add_.edge_color_rgb;
		state.edge_color_alpha = base.edge_color_alpha * multiply_.edge_color_alpha + add_.edge_color_alpha;
		state.edge_size = base.edge_size * multiply_.edge_size + add_.edge_size;
		state.texture.multiply_rgb = multiply_.texture_factor_rgb;
		state.texture.multiply_alpha = multiply_.texture_factor_alpha;
		state.texture.add_rgb = add_.texture_factor_rgb;
		state.texture.add_alpha = add_.texture_factor_alpha;
		state.sphere_texture.multiply_rgb = multiply_.sphere_texture_factor_rgb;
		state.sphere_texture.multiply_alpha = multiply_.sphere_texture_factor_alpha;
		state.sphere_texture.add_rgb = add_.sphere_texture_factor_rgb;
		state.sphere_texture.add_alpha = add_.sphere_texture_factor_alpha;
		state.toon_texture.multiply_rgb = multiply_.toon_texture_factor_rgb;
		state.toon_texture.multiply_alpha = multiply_.toon_texture_factor_alpha;
		state.toon_texture.add_rgb = add_.toon_texture_factor_rgb;
		state.toon_texture.add_alpha = add_.toon_texture_factor_alpha;
		return state;
	}

private:
	static VectorType Multiply(const VectorType& a, const VectorType& b)
	{
		return VectorType(a.x * b.x, a.y * b.y, a.z * b.z);
	}

	static void ApplyScalar(ScalarType& multiplier, ScalarType& addition, const ScalarType offset, const ScalarType weight, const bool additive)
	{
		if (additive)
			addition += offset * weight;
		else
			multiplier *= ScalarType(1) + (offset - ScalarType(1)) * weight;
	}

	static void ApplyVector(VectorType& multiplier, VectorType& addition, const VectorType& offset, const ScalarType weight, const bool additive)
	{
		if (additive)
			addition = addition + offset * weight;
		else
			multiplier = Multiply(multiplier, VectorType(
				ScalarType(1) + (offset.x - ScalarType(1)) * weight,
				ScalarType(1) + (offset.y - ScalarType(1)) * weight,
				ScalarType(1) + (offset.z - ScalarType(1)) * weight));
	}

	MaterialMorphValues<VectorType, ScalarType> multiply_{ScalarType(1)};
	MaterialMorphValues<VectorType, ScalarType> add_{ScalarType(0)};
};

} // namespace cmt_runtime
