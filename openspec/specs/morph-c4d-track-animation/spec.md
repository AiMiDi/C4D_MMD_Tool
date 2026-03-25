# Morph C4D track animation

## Purpose

Define how VMD morph keyframes are represented as Cinema 4D CTrack/CKey data on model manager morph strength parameters so playback uses C4D’s animation system.

## Requirements
### Requirement: Create CTrack keyframes for morph strength during VMD import

The system SHALL create C4D CTrack and CKey objects on each morph's `m_strength_id` DescID when importing VMD motion data, mapping VMD morph keyframes directly to the model manager's dynamic description parameters.

#### Scenario: VMD with morph keyframes imports successfully
- **WHEN** a VMD file containing morph keyframes is imported via `LoadVMDMotion`
- **THEN** for each unique morph name in `VMDFile::m_morphs` that matches an entry in `morph_name_`, a CTrack is created on the model manager object using `morph_data_[index].GetStrengthDescID()`
- **THEN** for each morph keyframe, a CKey is added at `BaseTime(frame, 30.0)` with the keyframe's weight value
- **THEN** each CKey's interpolation mode is set to `CINTERPOLATION_LINEAR`

#### Scenario: Multiple keyframes for same morph
- **WHEN** a VMD file contains multiple keyframes for the same morph name
- **THEN** all keyframes are added to the same CTrack as separate CKeys
- **THEN** the CKeys are ordered by frame time on the curve

#### Scenario: Morph name not found in model
- **WHEN** a VMD morph keyframe references a morph name that does not exist in `morph_name_`
- **THEN** no CTrack is created for that morph name
- **THEN** the unmatched morph name is recorded in the import log (`LoadVmdMotionLog::not_find_morph_name_list`)

#### Scenario: Existing CTrack for a morph strength
- **WHEN** a CTrack already exists on the morph's strength DescID (e.g., from a previous import or manual keyframing)
- **THEN** the existing CTrack is reused and new CKeys are added to its curve

### Requirement: Log unmatched VMD morph names in import report

The system SHALL report morph names from the VMD file that could not be matched to any morph in the target model.

#### Scenario: Unmatched morphs shown in import log
- **WHEN** VMD import completes with unmatched morph names
- **THEN** the import report dialog lists the unmatched morph names
- **THEN** the count of unmatched morphs is displayed

#### Scenario: All morphs matched
- **WHEN** all VMD morph names are successfully matched to model morphs
- **THEN** the import report does not show any unmatched morph warning

### Requirement: CTrack keyframes drive morph strength parameters at playback

The system SHALL allow C4D's animation engine to evaluate CTrack keyframes and update morph strength parameters automatically during playback.

#### Scenario: Timeline playback updates morph sliders
- **WHEN** the C4D timeline is playing and CTrack keyframes exist on morph strength parameters
- **THEN** the morph strength parameter values are updated by C4D's animation engine before `Execute()` is called
- **THEN** `UpdateMorph()` reads the updated strength values and applies them to mesh/bone managers
- **THEN** the Pose Morph tags on mesh objects reflect the correct morph weights

#### Scenario: User edits morph keyframe in timeline
- **WHEN** a user modifies a CKey value or timing in the C4D timeline
- **THEN** the morph animation reflects the modified keyframe during playback

