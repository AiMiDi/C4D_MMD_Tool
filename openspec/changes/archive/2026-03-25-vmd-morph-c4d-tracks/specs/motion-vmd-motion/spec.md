## ADDED Requirements

### Requirement: VMD morph animation playback mechanism

In VMD mode, morph animation playback SHALL be driven by C4D's CTrack system instead of per-frame reads from libMMD's morph weight output. The `MMDMeshManagerObject` SHALL NOT read morph weights from `libmmd::MorphManager` during VMD mode execution. Instead, morph strength values come from C4D parameters (set by CTrack evaluation), and `UpdateMorph()` dispatches them to mesh/bone managers through existing paths (`SetMorphStrength`, bone morph hubs).

#### Scenario: Mesh morph strength comes from CTrack in VMD mode
- **WHEN** the model is in `MODEL_MODE_VMD` and a mesh morph has CTrack keyframes
- **THEN** `MMDMeshManagerObject::Execute()` does NOT read morph weights from `mmd_morph_manager_`
- **THEN** mesh morph strength is applied through `MeshMorph::UpdateMorph()` → `SetMorphStrength()` using the CTrack-driven parameter value

#### Scenario: Bone morph still works via libMMD node transforms
- **WHEN** the model is in `MODEL_MODE_VMD` and bone morphs exist
- **THEN** libMMD's `VMDAnimation::Evaluate()` still sets bone morph weights internally
- **THEN** `UpdateMorphAnimation()` applies bone morph effects to `mmd_node_` transforms
- **THEN** `MMDBoneTag` reads correct transforms from `mmd_node_` including bone morph effects

### Requirement: Remove VMD morph weight reading from MeshManager

The `MMDMeshManagerObject` SHALL NOT maintain `morph_manager_index_` or `mmd_morph_manager_` members. The `MESH_MODE_VMD` morph weight reading loop in `Execute()` SHALL be removed.

#### Scenario: MeshManager Execute in VMD mode
- **WHEN** `MMDMeshManagerObject::Execute()` runs in `MESH_MODE_VMD`
- **THEN** no morph weight reading from libMMD's `MorphManager` occurs
- **THEN** morph strength is applied solely through the `SetMorphStrength()` path called by `UpdateMorph()`

### Requirement: Report unmatched VMD morph names

The VMD import pipeline SHALL record morph names from the VMD file that do not match any morph in the target model's `morph_name_` map, and include them in the import log report.

#### Scenario: Import report includes unmatched morph names
- **WHEN** a VMD file is imported and some morph names cannot be matched
- **THEN** `LoadVmdMotionLog::not_find_morph_name_list` contains the unmatched morph names
- **THEN** the import report dialog displays these names when `detail_report` is enabled
