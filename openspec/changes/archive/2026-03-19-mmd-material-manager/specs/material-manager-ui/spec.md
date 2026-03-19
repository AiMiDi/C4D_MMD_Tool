## ADDED Requirements

### Requirement: Material Management Group
The Attribute Manager of `MMDModelManagerObject` SHALL include a `MODEL_MATERIAL_GRP` group, visible in edit mode (`MODEL_MODE_EDIT`), and read-only in animation/VMD modes.

### Requirement: Material List Selector
The material group SHALL contain a `CYCLE` dropdown `MODEL_MATERIAL_LIST` displaying all loaded material names.

#### Scenario: Switch Selected Material
- **WHEN** The user selects another material from the dropdown
- **THEN** The property area updates immediately to reflect the chosen material.

### Requirement: Material Link Property
The edit area SHALL contain a `LINK` property `MODEL_MATERIAL_LINK` showing the associated C4D `BaseMaterial`. Users can manually drag and drop a material here to update the link.

### Requirement: Material Name Editing
The edit area SHALL provide string fields for `MODEL_MATERIAL_NAME_LOCAL` and `MODEL_MATERIAL_NAME_UNIVERSAL`.

### Requirement: Material Color Editing
The edit area SHALL provide fields for diffuse color/alpha, specular color/power, and ambient color.

#### Scenario: Sync Diffuse to Ambient
- **WHEN** The user checks the option to sync diffuse to ambient and modifies the diffuse color
- **THEN** The ambient color is automatically set to diffuse color RGB × 0.5.

### Requirement: Draw Flags & Edge Settings
The edit area SHALL provide boolean toggles for drawing flags (double-sided, ground shadow, etc.) and edge settings (enabled, size, color).

### Requirement: Texture Information
The edit area SHALL display texture indices and dropdowns for sphere mode and toon mode.

### Requirement: Memo and Face Count
The edit area SHALL include a text field for memo and a read-only integer showing the face count.

### Requirement: Create Material (+) Button Behavior
The UI SHALL contain a `MODEL_MATERIAL_ADD_BUTTON` (+ button) to handle adding materials to associated meshes.

#### Scenario: Mesh Has Existing Material
- **WHEN** The selected MMD material is associated with a mesh (`mesh_link`) and the mesh already has a C4D material tag
- **THEN** The system SHALL update the MMD material's `material_link` to reference the existing C4D material, and perform a Reverse Sync to read its color and texture back into the MMD data.

#### Scenario: Mesh Has No Material
- **WHEN** The associated mesh does not have a material tag
- **THEN** The system SHALL create a new C4D material using the current MMD data (based on the `MODEL_MATERIAL_CREATE_TYPE`), assign it to the mesh via a new Material Tag (specifying selection if applicable), and update the `material_link`.

### Requirement: Sync Buttons
The UI SHALL contain:
- `MODEL_MATERIAL_SYNC_BUTTON`: Manually sync current MMD properties to the linked C4D material.
- `MODEL_MATERIAL_REVERSE_SYNC_BUTTON`: Manually read properties from the linked C4D material back into the MMD data.

### Requirement: Material Type Persistence
The `MODEL_MATERIAL_CREATE_TYPE` dropdown SHALL automatically remember and default to the material type (Standard/RedShift/Octane/Corona) selected during the initial PMX import.