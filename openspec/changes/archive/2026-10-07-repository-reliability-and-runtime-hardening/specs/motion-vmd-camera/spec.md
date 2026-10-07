## ADDED Requirements

### Requirement: Camera export reports the file operation result
Camera export SHALL report success only after camera serialization and file writing both succeed. Invalid selection, conversion failure, and write failure SHALL report failure. Temporary conversion objects SHALL not remain in the scene, and export SHALL restore the original document time.

#### Scenario: Serialization fails
- **WHEN** camera serialization fails
- **THEN** export returns failure without a success message

#### Scenario: Export ordinary camera
- **WHEN** an ordinary Cinema 4D camera is exported
- **THEN** a temporary converted camera is valid for the serialization operation and freed afterward
- **AND** the original scene camera hierarchy and document time are retained

### Requirement: Camera field of view uses angular units
New camera imports SHALL apply VMD field-of-view degrees to the native vertical field-of-view angle in radians. Earlier generated MMD cameras using aperture animation for field of view SHALL migrate once while preserving their key values and interpolation in angular units. Ordinary artist cameras SHALL retain their sensor aperture.

#### Scenario: Load earlier generated camera
- **WHEN** a generated MMD camera with legacy aperture keys is loaded
- **THEN** the keys are migrated to vertical field-of-view radians and the scene stores the new schema marker
- **AND** a subsequent load does not migrate the keys again
