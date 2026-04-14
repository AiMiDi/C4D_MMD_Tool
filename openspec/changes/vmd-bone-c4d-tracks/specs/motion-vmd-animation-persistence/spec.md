## MODIFIED Requirements



### Requirement: Serialize VMD Animation Data to Scene File



The system SHALL serialize bone animation data as: (1) keyframe records and interpolation payload via `MMDBoneTag::Write()` / HyperFile, and (2) CTrack/CKey on the bone tag for SplineData and the frame-on Int parameter where used for markers. VMD binary blobs in `MMDModelManagerObject::Write()` SHALL NOT be used as the persisted source for bone playback, and new imports SHALL NOT retain any raw VMD source payload for bone animation. IK enable keyframes (already on CTrack) and morph keyframes (already on CTrack) SHALL continue to use their existing CTrack persistence.



#### Scenario: Save Scene with VMD Bone Animation

- **WHEN** a user saves a scene that has VMD bone animation imported

- **THEN** bone keyframe data (position, quaternion, bezier curves) SHALL be persisted via `MMDBoneTag::Write()`

- **THEN** CTrack/CKey on the bone tag for SplineData and frame-on parameters SHALL be persisted by C4D's native scene file mechanism

- **THEN** no persisted VMD binary blob SHALL be required for bone playback after reload



#### Scenario: Save Scene without Animations

- **WHEN** a user saves a scene without VMD animations

- **THEN** no animation-related data SHALL be written beyond what C4D persists natively and what bone tags serialize



### Requirement: Deserialize VMD Animation Data from Scene File



The system SHALL read bone animation data from `MMDBoneTag::Read()` and from CTrack/CKey on the bone tag (SplineData, frame-on). The system SHALL still support reading legacy VMD binary blob data from older scene files for backward compatibility, but SHALL NOT use that blob as the playback authority once tag keyframe data exists.



#### Scenario: Load Scene with New Format Bone Animation

- **WHEN** a user opens a scene file saved with the new format

- **THEN** bone tag internal keyframe data SHALL be loaded via `MMDBoneTag::Read()`

- **THEN** bone tag marker CTracks SHALL be loaded by C4D natively

- **THEN** bone animation SHALL play correctly without re-importing VMD



#### Scenario: Backward Compatibility with Older Scene Files

- **WHEN** a user opens a scene file saved by an older version containing VMD binary blobs

- **THEN** the `Read()` method SHALL read the VMD binary data without error

- **THEN** the old VMD blob data SHALL NOT be used for bone animation playback

- **THEN** the user SHALL need to re-import the VMD file to restore bone keyframe data on bone tags



## REMOVED Requirements



### Requirement: Restore VMD Animations During Runtime Reconstruction Phase

**Reason**: VMD bone animation is no longer stored as VMD binary blobs and no longer requires `VMDAnimation` objects for playback. Bone animation data is persisted through `MMDBoneTag` serialization and bone tag CTracks.

**Migration**: Re-import VMD files for existing scenes. New scenes persist bone animation through bone tag data and CTracks.


