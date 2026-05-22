## ADDED Requirements

### Requirement: PMX export target validation
The system SHALL export PMX files only from the currently selected plugin-managed `MMDModelManagerObject`. When no object is selected or the selected object is not an `MMDModelManagerObject`, the system SHALL reject the export and report an export type or selection error.

#### Scenario: Export selected MMD model
- **WHEN** the active object is an `MMDModelManagerObject` and the user starts PMX export
- **THEN** the system SHALL use that model manager as the PMX export source

#### Scenario: Reject non-MMD selection
- **WHEN** the active object is not an `MMDModelManagerObject`
- **THEN** the system SHALL NOT write a PMX file
- **THEN** the system SHALL report an export type or selection error to the user

### Requirement: PMX export file writing
The system SHALL allow the user to choose a `.pmx` output path from the model tool UI and SHALL write the reconstructed PMX data through `libmmd::WritePMXFile`. A successful export SHALL produce a file that `libmmd::ReadPMXFile` can read back.

#### Scenario: Successful PMX file write
- **WHEN** a valid MMD model is selected and the user chooses a writable `.pmx` export path
- **THEN** the system SHALL construct a `libmmd::PMXFile`
- **THEN** the system SHALL write the file using `libmmd::WritePMXFile`
- **THEN** the written file SHALL be readable by `libmmd::ReadPMXFile`

#### Scenario: Cancel output path selection
- **WHEN** the user cancels PMX export path selection
- **THEN** the system SHALL NOT construct or write a PMX file
- **THEN** the export operation SHALL return without modifying the scene

### Requirement: Reconstructed PMX model metadata
The exporter SHALL write PMX header and model information from the selected model manager's persisted metadata, including PMX version, local and universal model names, and local and universal comments.

#### Scenario: Export model names and comments
- **WHEN** a selected MMD model has local and universal names and comments stored on the model manager
- **THEN** the exported PMX info block SHALL contain those names and comments
- **THEN** re-reading the PMX file SHALL preserve those metadata values

### Requirement: Editable state synchronization before export
Before collecting PMX section data, the exporter SHALL synchronize current editable model state back into the persisted PMX parameters used by export. This synchronization SHALL include bones, mesh bind pose data, rigid bodies, and joints.

#### Scenario: Export edited bone bind position
- **WHEN** the user edits a managed bone in edit mode and exports PMX
- **THEN** the exported PMX bone position SHALL reflect the edited bind position

#### Scenario: Export edited rigid and joint transforms
- **WHEN** the user edits managed rigid body or joint transforms before exporting PMX
- **THEN** the exported PMX rigid body and joint transforms SHALL reflect the edited values rather than stale import-time values

### Requirement: PMX bone section reconstruction
The exporter SHALL reconstruct the PMX bone section from managed bone tags and the bone manager's synchronized hierarchy. For each exported bone, it SHALL include names, position, parent index, deform layer, bone flags, tail information, append/inherit data, fixed axis, local axis, external parent data, IK target, IK iteration, IK unit angle, and IK links when those features are enabled and persisted.

#### Scenario: Export bone hierarchy and flags
- **WHEN** the selected MMD model contains a managed bone hierarchy with rotatable, visible, append, fixed-axis, local-axis, and after-physics flags
- **THEN** the exported PMX bone section SHALL contain the same synchronized hierarchy indices and persisted flag values

#### Scenario: Export IK bone data
- **WHEN** a managed bone has PMX IK enabled with a target, iteration count, unit angle, and IK links
- **THEN** the exported PMX bone SHALL contain the IK target index, iteration count, unit angle, and link limit data

#### Scenario: Export IK links without unsafe GeData access
- **WHEN** IK target or IK link dynamic description fields include non-link legacy index values
- **THEN** the exporter SHALL NOT call `GeData::GetBaseLink()` on non-link data
- **THEN** the exporter SHALL fall back to the persisted numeric or string bone index when no valid link is available

### Requirement: PMX mesh, material, and texture reconstruction
The exporter SHALL reconstruct PMX vertices, faces, material face ranges, and texture table entries from managed mesh and material data. When normals, UVs, materials, or weights are enabled by export settings, the exporter SHALL write those sections consistently with the exported geometry.

#### Scenario: Export mesh geometry with material face counts
- **WHEN** the selected MMD model has a managed polygon mesh with material selections
- **THEN** the exported PMX SHALL contain vertices and triangle faces from that mesh
- **THEN** the sum of all exported material face vertex counts SHALL equal the exported face count multiplied by three

#### Scenario: Export mesh from base pose instead of current expression
- **WHEN** the selected MMD model is currently on an animation frame with active expression morphs
- **THEN** the exported PMX mesh vertex positions SHALL be sampled from the managed base pose data when that data exists
- **THEN** the exported PMX SHALL NOT bake the current expression state into the base mesh

#### Scenario: Export material texture indices
- **WHEN** exported materials reference texture, sphere texture, or toon texture paths
- **THEN** the exporter SHALL add those paths to the PMX texture table
- **THEN** each exported material SHALL reference the correct PMX texture table index instead of always using `-1`

### Requirement: PMX weight reconstruction
When weight export is enabled, the exporter SHALL reconstruct PMX vertex weights from the C4D weight data associated with the managed mesh and bones. The exporter SHALL preserve PMX-specific SDEF or QDEF data only when that data is available from persisted plugin state; otherwise it SHALL use a supported PMX weight representation that matches the available C4D weights.

#### Scenario: Export readable weighted mesh
- **WHEN** the selected MMD model has a managed mesh bound to managed bones with C4D weight data
- **THEN** the exported PMX vertices SHALL contain valid bone indices and normalized weights
- **THEN** the exported PMX SHALL be readable by `libmmd::ReadPMXFile`

### Requirement: PMX morph and display frame reconstruction
The exporter SHALL reconstruct supported PMX morphs and display frames from plugin-managed morph data and display frame data. Display frame targets SHALL reference the exported bone and morph indices.

#### Scenario: Export display frame targets
- **WHEN** the model manager contains display frames with bone and morph targets
- **THEN** the exported PMX display frames SHALL contain targets that reference valid exported bone and morph indices

#### Scenario: Export supported morph definitions
- **WHEN** the model contains supported morph definitions persisted by the plugin
- **THEN** the exported PMX morph section SHALL contain those morph definitions with valid target indices

### Requirement: PMX rigid body and joint reconstruction
The exporter SHALL reconstruct PMX rigid bodies and joints from managed rigid and joint objects. Rigid bodies SHALL reference exported bone indices, and joints SHALL reference exported rigid body indices.

#### Scenario: Export rigid bodies with bone bindings
- **WHEN** the model has managed rigid bodies bound to managed bones
- **THEN** each exported PMX rigid body SHALL contain the persisted physics parameters and a valid exported bone index or `-1`

#### Scenario: Export joints with rigid body references
- **WHEN** the model has managed joints connecting managed rigid bodies
- **THEN** each exported PMX joint SHALL contain valid rigid body A and B indices that match the exported rigid body section

### Requirement: Explicit v1 export limitations
The exporter SHALL NOT claim lossless PMX round-trip for data that is not represented in plugin-managed state. The v1 exporter SHALL explicitly treat arbitrary C4D scene conversion, softbody passthrough, unknown PMX extensions, and unavailable SDEF/QDEF auxiliary data as unsupported or best-effort.

#### Scenario: Unsupported data is not advertised as lossless
- **WHEN** a source PMX contains unsupported data that is not represented in plugin-managed state
- **THEN** the exporter SHALL NOT guarantee that the unsupported data is preserved in the exported PMX
