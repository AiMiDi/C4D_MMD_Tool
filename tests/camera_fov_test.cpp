#include "utils/cmt_camera_fov.hpp"

#include <cmath>
#include <iostream>
#include <limits>
#include <stdexcept>

namespace
{
void Require(bool condition, const char* message)
{
	if (!condition)
		throw std::runtime_error(message);
}
}

int main()
{
	try
	{
		Require(std::abs(cmt_camera_fov::DegreesToRadians(45.) - cmt_camera_fov::kPi / 4.) < 1e-12,
			"45 degrees must map to a quarter pi, not sensor width");
		for (uint32_t expected = 1; expected < 180; ++expected)
		{
			const float imported_radians = static_cast<float>(cmt_camera_fov::DegreesToRadians(expected));
			uint32_t actual = 0;
			Require(cmt_camera_fov::ToVmdDegrees(imported_radians, actual) && actual == expected,
				"VMD integer FOV must survive float32 radians roundtrip");
		}
		Require(std::abs(cmt_camera_fov::DegreesToRadians(-3.) + cmt_camera_fov::kPi / 60.) < 1e-12,
			"Negative Bezier value tangent must retain direction after unit conversion");
		Require(std::abs(cmt_camera_fov::DegreesToRadians(5.) - cmt_camera_fov::kPi / 36.) < 1e-12,
			"Positive Bezier value tangent must scale with key value");
		uint32_t unused = 0;
		Require(!cmt_camera_fov::ToVmdDegrees(0., unused), "Zero FOV must fail");
		Require(!cmt_camera_fov::ToVmdDegrees(cmt_camera_fov::kPi, unused), "180-degree FOV must fail");
		Require(!cmt_camera_fov::ToVmdDegrees(-1., unused), "Negative FOV must fail");
		Require(!cmt_camera_fov::ToVmdDegrees(std::numeric_limits<double>::infinity(), unused), "Infinite FOV must fail");
		Require(!cmt_camera_fov::ToVmdDegrees(std::numeric_limits<double>::quiet_NaN(), unused), "NaN FOV must fail");
		std::cout << "Camera vertical FOV conversion assertions passed\n";
		return 0;
	}
	catch (const std::exception& error)
	{
		std::cerr << error.what() << '\n';
		return 1;
	}
}
