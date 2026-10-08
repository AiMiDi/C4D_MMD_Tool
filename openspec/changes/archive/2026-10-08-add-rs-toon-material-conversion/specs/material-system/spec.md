# Material System Delta

## MODIFIED Requirements

### Requirement: Renderer-specific material adapters
The material system SHALL use renderer-specific adapters to create, sync, and read Standard, RedShift, Octane, and Corona materials, and SHALL additionally create and synchronize a distinct RS Toon profile. Managed Toon outputs SHALL preserve source base data instead of being reverse-read as independent base values.

#### Scenario: Create material for selected renderer
- **WHEN** a material is created from PMX data for a selected material type
- **THEN** the matching material adapter SHALL create a Cinema 4D material and preserve supported sync paths for that renderer and profile

#### Scenario: A managed Toon material is reverse-synchronized
- **WHEN** the user requests reverse synchronization from managed Toon outputs
- **THEN** the source base values SHALL remain unchanged and the UI SHALL explain that the managed outputs are driven from those values

### Requirement: Material management UI
The model manager attribute UI SHALL expose material list management and editable PMX material fields, including RS Toon creation and explicit conversion of the current material entry.

#### Scenario: User edits a material entry
- **WHEN** the user selects a material in the model manager material list
- **THEN** the UI SHALL expose controls for linking, creating, syncing, reverse-syncing, reordering, deleting, and editing PMX material properties

#### Scenario: User selects RS Toon
- **WHEN** the installed renderer supports the profile
- **THEN** the material-type selector SHALL offer RS Toon and the UI SHALL expose its conversion action and support diagnostics

## ADDED Requirements

### Requirement: Standard Matcap Sphere conversion
New Standard and Redshift Standard conversions SHALL project ordinary PMX Sphere
textures using the camera-space surface normal, independently of mesh UVs and
reflected view rays. Multiply/Add SHALL compose with base color before native
surface shading. Sphere RGBA Morph factors SHALL remain independent and image
Alpha SHALL NOT change object opacity. SubTexture SHALL retain its source data
with an unsupported diagnostic instead of using ordinary UV or reflection.

#### Scenario: Sphere parameters are edited
- **WHEN** a unique owned Standard or Redshift Standard binding receives a valid Sphere path or mode edit
- **THEN** it SHALL update the managed Sphere contribution, preserve sampling and artist inputs, and survive Undo/Redo with immediate save/reopen

#### Scenario: An older material is opened
- **WHEN** a scene retains the legacy Environment approximation or seven-field RS binding
- **THEN** opening and runtime evaluation SHALL NOT silently rewrite its material recipe, and an explicit independent conversion or supported upgrade SHALL be required to obtain the new Matcap binding

#### Scenario: A Sphere edit conflicts with artist input
- **WHEN** an artist replaces the owned bitmap or connects an unowned source to an active or dormant managed input
- **THEN** the edit SHALL fail while preserving the current graph and authoritative source parameters

### Requirement: Conversion uses authoritative MMD data
Conversion to RS Toon SHALL use the selected model entry's stored base material and Morph definitions. It SHALL NOT infer equivalent PMX parameters from arbitrary renderer graphs. Conversion SHALL require EDIT mode with material preview disabled.

#### Scenario: The linked source material has artist edits
- **WHEN** the user explicitly converts its MMD material entry
- **THEN** the new material SHALL use stored MMD values, the UI SHALL identify that input source, and the original material graph SHALL remain available unchanged

### Requirement: Scoped material assignment
Successful conversion SHALL create a new material, update the selected entry's material link and its unambiguous mesh material assignments, and preserve unrelated assignments. The source material SHALL remain in the document. Missing or ambiguous target assignments SHALL reject conversion with a diagnostic.

#### Scenario: A source material is shared by two entries
- **WHEN** one entry is converted to RS Toon
- **THEN** only that entry and its resolved mesh or polygon-selection assignments SHALL use the new material while the other entry retains the source

#### Scenario: Target assignments cannot be resolved
- **WHEN** the selected entry's mesh, selection or source-material relationships are ambiguous
- **THEN** conversion SHALL report the ambiguity without creating an assigned or orphan conversion result

### Requirement: Atomic conversion and recovery
Conversion, including assignment and animation-binding preparation, SHALL form one Undo action. Failure SHALL restore previous links, assignments and binding attributes and remove only objects created by that failed operation. Undo and Redo SHALL restore usable states that can be immediately saved and reopened.

#### Scenario: Binding preparation fails
- **WHEN** material construction succeeds but required binding preparation fails
- **THEN** the original scene state SHALL be restored and conversion SHALL report failure

#### Scenario: Conversion is undone and redone
- **WHEN** the user performs Undo or Redo after a successful conversion
- **THEN** material assignment and binding ownership SHALL agree, source data and animation tracks SHALL be preserved, and immediate save/reopen SHALL succeed
