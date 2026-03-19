## ADDED Requirements

### Requirement: Serialize VMD Animation Data to Scene File

The system SHALL serialize all VMD animation data from the `animations_` array to the HyperFile in `MMDModelManagerObject::Write()`, ensuring it persists when the scene is saved.

#### Scenario: Save Scene with VMD Animations
- **WHEN** a user saves a scene that has VMD animations loaded
- **THEN** the `Write()` method writes the size of the `animations_` array to the HyperFile
- **THEN** for each animation entry, it writes the animation name (String) and the VMD binary data (converted to a byte array via `VMDAnimation::Save(VMDFile&)` + `WriteVMDFile()`)
- **THEN** the HyperFile level is incremented to identify the new data format

#### Scenario: Save Scene without Animations
- **WHEN** a user saves a scene without VMD animations (`animations_` is empty)
- **THEN** the `Write()` method writes the animation count as 0
- **THEN** no additional animation data is written

### Requirement: Deserialize VMD Animation Data from Scene File

The system SHALL read VMD animation data from the HyperFile in `MMDModelManagerObject::Read()` and temporarily stage it to be restored during the runtime reconstruction phase.

#### Scenario: Load Scene with VMD Animation Data
- **WHEN** a user opens a scene file containing serialized VMD animation data
- **THEN** the `Read()` method reads the animation count, followed by each animation's name and VMD binary data from the HyperFile
- **THEN** the VMD binary data is staged in a temporary buffer, waiting for restoration during the runtime reconstruction phase

#### Scenario: Backward Compatibility with Older Scene Files
- **WHEN** a user opens a scene file saved by an older version of the plugin (without the level for VMD animation data)
- **THEN** the `Read()` method skips reading VMD animation data
- **THEN** `animations_` remains empty, and the plugin operates normally but without VMD animations

### Requirement: Restore VMD Animations During Runtime Reconstruction Phase

The system SHALL use the staged VMD binary data to restore `VMDAnimation` objects after the `PMXModel` runtime reconstruction is complete.

#### Scenario: Animation Restoration Successful
- **WHEN** `PMXModel` reconstruction is complete and staged VMD binary data exists
- **THEN** the system calls `VMDAnimation::Create(mmd_model_)` and `VMDAnimation::Add(vmd_file)` for each staged VMD data to restore the animation
- **THEN** the size of the restored `animations_` array and animation names match those from when it was saved
- **THEN** `animation_index_` and `animation_items_` are correctly restored
- **THEN** animations can be played normally

#### Scenario: `animation_index_` Persistence upon Animation Restoration
- **WHEN** a user selected an animation (`animation_index_` >= 0) when saving the scene
- **THEN** after the scene is reloaded, `animation_index_` is restored to its saved value
- **THEN** the animation list dropdown menu in the Attribute Manager displays the correct selected item

### Requirement: CopyTo Support for VMD Animation Data

The system SHALL correctly copy the `animations_` array in `MMDModelManagerObject::CopyTo()`, allowing undo/redo and object duplication operations to work properly.

#### Scenario: Object Duplication Retains Animation Data
- **WHEN** a user duplicates an `MMDModelManagerObject` containing VMD animations
- **THEN** the duplicated object contains the same `animations_` data
- **THEN** the duplicated object can play animations independently