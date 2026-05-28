## ADDED Requirements

### Requirement: VMDBezier as standalone type in VMDInterpolation module

The `VMDBezier` struct (with `EvalX`, `EvalY`, `EvalDX`, `FindBezierX`, `m_cp1`, `m_cp2`) SHALL be declared in `VMDInterpolation.h` and implemented in `VMDInterpolation.cpp`. `VMDAnimation.h` SHALL re-export or include the type for backward compatibility.

#### Scenario: VMDBezier usable without VMDAnimation
- **WHEN** a consumer includes `VMDInterpolation.h` without including `VMDAnimation.h`
- **THEN** `VMDBezier` SHALL be fully usable with all evaluation methods

#### Scenario: Backward compatibility
- **WHEN** existing code includes `VMDAnimation.h` and uses `VMDBezier`
- **THEN** the code SHALL compile without modification

### Requirement: VMD interpolation byte codec functions

The module SHALL provide `SetVMDBezier(VMDBezier& bezier, const uint8_t* cp)` and `GetVMDBezier(const VMDBezier& bezier, uint8_t* cp)` as public functions in `VMDInterpolation.h`. `SetVMDBezier` SHALL decode VMD 0-127 bytes (stride 4) to normalized 0-1 control points. `GetVMDBezier` SHALL encode normalized control points back to 0-127 bytes.

#### Scenario: Decode VMD interpolation bytes
- **WHEN** `SetVMDBezier` is called with bytes `[20, *, *, *, 20, *, *, *, 107, *, *, *, 107, ...]`
- **THEN** `bezier.m_cp1` SHALL be approximately `(20/127, 20/127)` and `bezier.m_cp2` approximately `(107/127, 107/127)`

#### Scenario: Round-trip encode/decode
- **WHEN** a VMDBezier is encoded via `GetVMDBezier` and then decoded via `SetVMDBezier`
- **THEN** the resulting control points SHALL match the original within rounding tolerance

### Requirement: Bone keyframe interpolation pure function

The module SHALL provide an `InterpolateBoneKeys` pure function that takes two `VMDBoneKeyframe` structs and a current frame number, and returns interpolated position (Vector3f) and rotation (Quaternionf) using VMD bezier interpolation.

#### Scenario: Interpolation between two keyframes
- **WHEN** `InterpolateBoneKeys` is called with key0 at frame 0 (pos=[0,0,0], rot=identity) and key1 at frame 30 (pos=[10,0,0], rot=90deg around Y), with currentFrame=15 and linear bezier curves
- **THEN** the returned position x-component SHALL be approximately 5.0
- **THEN** the returned rotation SHALL be approximately slerp(identity, 90degY, 0.5)

#### Scenario: Per-axis bezier easing
- **WHEN** key0 has a non-linear X-translation bezier (ease-in) and linear Y/Z beziers
- **THEN** the X-component of the result SHALL follow the ease-in curve while Y and Z SHALL be linearly interpolated

### Requirement: FindBoundKey template function

The module SHALL provide a `FindBoundKey` template function that performs binary search on a sorted keyframe array to find the first key with `m_time > t`, with an optional start index hint for sequential access optimization.

#### Scenario: Sequential playback optimization
- **WHEN** `FindBoundKey` is called with monotonically increasing frame values
- **THEN** the start index hint SHALL reduce search time compared to always starting from index 0

### Requirement: VMDBoneKeyframe data structure

The module SHALL define a `VMDBoneKeyframe` struct containing: `int32_t frame`, `Eigen::Vector3f translate`, `Eigen::Quaternionf rotate`, and four `VMDBezier` members (`txBezier`, `tyBezier`, `tzBezier`, `rotBezier`).

#### Scenario: Construct from VMDMotion
- **WHEN** a `VMDBoneKeyframe` is constructed from a `VMDMotion` struct
- **THEN** `frame` SHALL equal `m_frame`, `translate` SHALL equal `m_translate`, `rotate` SHALL equal `m_quaternion`
- **THEN** the four beziers SHALL be decoded from `m_interpolation` bytes at offsets 0, 1, 2, 3 respectively
