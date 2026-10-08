# rs-toon-material Specification

## Purpose
Provide a distinct Redshift Toon material profile for MMD-style scenes, with editable stylized shading, managed animation bindings, and explicit approximation limits.

## Requirements

### Requirement: Distinct Toon profile
The system SHALL expose RS Toon as a distinct material conversion type targeting an MMD-like appearance. Existing Standard and Redshift Standard choices SHALL retain their behavior and persisted identities. RS Toon SHALL NOT be described as pixel-equivalent MMD rendering or MME compatibility.

#### Scenario: An existing scene is opened
- **WHEN** a scene stores an existing material type
- **THEN** the same type and existing materials SHALL remain selected without automatic Toon conversion

### Requirement: Runtime capability reporting
RS Toon availability SHALL reflect required shader and port capabilities of the installed renderer. An unavailable profile SHALL return an actionable reason and SHALL NOT silently create another material type.

#### Scenario: Redshift is present without required Toon capabilities
- **WHEN** the user requests RS Toon creation or conversion
- **THEN** the operation SHALL fail before changing scene assignments and SHALL identify the missing capability

### Requirement: Base texture and opacity
RS Toon SHALL support plain and textured materials, preserve the existing versioned diffuse and texture-factor contract, and obtain image opacity from embedded Alpha rather than RGB luminance. Its supported texture-path edits SHALL preserve unrelated authored settings.

#### Scenario: RGB changes with constant image Alpha
- **WHEN** two textures differ in RGB but have the same Alpha and material coefficients
- **THEN** their opacity SHALL remain equal

#### Scenario: A material has no base texture
- **WHEN** a plain RS Toon material is evaluated
- **THEN** diffuse color and diffuse Alpha SHALL determine its base output without applying an absent texture's factor

#### Scenario: The base texture is replaced
- **WHEN** an owned base texture changes between RGBA, RGB-only and an empty path
- **THEN** the resulting base color and opacity SHALL follow the corresponding texture state without retaining an obsolete image contribution

### Requirement: Lighting-driven tone mapping
RS Toon SHALL use a resolved shared or individual PMX Toon texture to control lighting-driven tone mapping. An unspecified Toon texture SHALL use a documented neutral white ramp without additional texture-factor darkening. An explicitly referenced unreadable texture SHALL use the documented stepped fallback with a visible diagnostic, and SHALL NOT be reported as successfully mapped.

#### Scenario: No Toon texture is assigned
- **WHEN** a PMX material has no assigned Toon texture
- **THEN** the default tone map SHALL remain neutral white and SHALL bypass Toon texture-factor multiplication

#### Scenario: A PMX Toon texture is assigned
- **WHEN** the same material is viewed under controlled changes in light direction
- **THEN** its Toon transitions SHALL follow illumination rather than ordinary mesh UV placement, with documented sampling orientation

#### Scenario: A Toon texture is edited
- **WHEN** the user changes the shared Toon slot or individual path on an owned binding
- **THEN** the tone map SHALL update without replacing unrelated graph branches, and Undo SHALL restore the previous result

### Requirement: Stylized highlight mapping
RS Toon SHALL map effective PMX specular color and power to a documented stylized highlight approximation. Zero specular color SHALL remove the corresponding highlight contribution. Increasing power SHALL not broaden the calibrated highlight under fixed validation lighting.

#### Scenario: Specular power is animated
- **WHEN** only supported specular power morph weights change
- **THEN** the highlight SHALL respond to the documented mapping while stored base values remain unchanged

### Requirement: Material-level contours
RS Toon SHALL provide per-material contour enablement, effective edge color and Alpha, and non-negative width derived from effective edge size and a documented profile scale. The first version SHALL identify contour width as an approximation and SHALL NOT claim per-vertex edge-magnitude support.

#### Scenario: Edge animation is evaluated
- **WHEN** supported edge color, Alpha or size morphs change
- **THEN** contours SHALL respond without rebuilding the material graph, and a disabled edge flag or zero effective width SHALL produce no profile contour

#### Scenario: Separate materials have different edge flags
- **WHEN** one material has contours enabled and another has them disabled
- **THEN** only the enabled material SHALL contribute profile contours in both merged-mesh and multipart import fixtures

### Requirement: Managed Morph lifecycle
RS Toon SHALL support existing Material, Group and Flip evaluation for diffuse, opacity, specular, power, Toon RGBA factors and material-level edge fields. Texture-factor Alpha SHALL affect sampled RGB according to the documented reference operation rather than object opacity. Preview, animation, render-document cloning, seek and reset SHALL use document-local state without cumulative drift or per-evaluation graph growth.

#### Scenario: Frames are revisited
- **WHEN** a sequence evaluates frame 0, a modified frame and frame 0 again
- **THEN** the repeated frame SHALL reproduce its supported material outputs with unchanged graph structure

#### Scenario: Preview is saved and reopened
- **WHEN** a scene is normally reopened after using the isolated material preview
- **THEN** preview SHALL be disabled and base state restored while definitions, tracks and binding identity remain intact

### Requirement: Explicit support boundaries
The profile SHALL report excluded appearance contributions while retaining source data and Morph definitions. Exclusions include Sphere SubTexture, Additional UV shading, per-vertex edge magnitude, independent Ambient and complete PMX shadow flags. Reference texture Morph semantics SHALL be documented without claiming native MMD equivalence.

#### Scenario: Unsupported fields are present
- **WHEN** the source material references Sphere SubTexture or an unsupported shading flag
- **THEN** conversion SHALL retain that data, report the omitted visual contribution, and SHALL NOT substitute an unrelated rendering effect

### Requirement: Ordinary Sphere shading
Sphere Multiply/Add SHALL use camera-related normal projection and independent texture Morph factors before Toon multiplication. Its bitmap Alpha SHALL NOT drive object opacity.

#### Scenario: Ordinary Sphere appearance is edited
- **WHEN** the user edits a Sphere bitmap or switches Multiply/Add/None on an importer-owned binding
- **THEN** the shader SHALL update without rebuilding graph roles, preserve opacity and sampling settings, and reject invalid files or conflicting artist connections while retaining the previous source values

### Requirement: Ordinary UV is sufficient by default
RS Toon SHALL assume Additional UV is unused for its default workflow. Conversion SHALL use ordinary mesh UVs without requiring additional channels or their implementation. Additional-UV diagnostics SHALL be limited to explicit source usage such as Sphere SubTexture or additional-UV Morphs; unused channels SHALL not trigger warnings.

#### Scenario: A normal model uses only ordinary UV
- **WHEN** a model has no source feature referencing Additional UV
- **THEN** Toon conversion SHALL proceed without an Additional-UV prerequisite or warning

#### Scenario: A source feature explicitly uses Additional UV
- **WHEN** the source model uses Sphere SubTexture or an additional-UV Morph
- **THEN** the result SHALL identify that unsupported contribution without blocking supported Toon conversion or reinterpreting it as ordinary UV shading

### Requirement: Editable graphs and ownership
Generated RS Toon graphs SHALL remain editable. Managed synchronization SHALL update only validated owned fields and connections. Artist changes that conflict with a managed binding SHALL stop that binding's updates with a diagnostic and provide an explicit repair or independent-material path.

#### Scenario: A managed input receives an artist connection
- **WHEN** synchronization encounters the altered input
- **THEN** the artist connection SHALL remain intact and the binding SHALL report the conflict rather than overwrite it

### Requirement: Appearance evidence
Acceptance SHALL include actual Toon and contour image comparisons under recorded camera, lighting, color-management and renderer settings. Shader creation and graph inspection alone SHALL NOT establish appearance acceptance. Evidence SHALL distinguish CPU and GPU execution and record the plugin module and profile revision.

#### Scenario: A graph is valid but no image was rendered
- **WHEN** validation has only confirmed node types and connections
- **THEN** appearance acceptance SHALL remain unverified

#### Scenario: An MMD reference image is available
- **WHEN** the profile is compared with the reference under documented comparable conditions
- **THEN** the comparison SHALL record the observed resemblance and remaining deviations without requiring pixel equivalence
