## ADDED Requirements

### Requirement: Material runtime state reflects material morph composition
The material system SHALL maintain an effective runtime material state derived from base `MMDMaterialData` plus active material morph contributions. Material adapters SHALL synchronize C4D materials from the effective runtime state when it changes.

#### Scenario: Material morph changes diffuse and alpha
- **WHEN** a Material morph adds diffuse color and alpha offsets to material index 0
- **AND** the morph effective strength is 1.0
- **THEN** material index 0 runtime state SHALL contain the adjusted diffuse RGB and alpha values
- **AND** the linked C4D material SHALL be synchronized from that adjusted runtime state

#### Scenario: Material runtime state uses base data when no material morph is active
- **WHEN** no Material morph has a non-zero effective strength
- **THEN** every material runtime state SHALL match its stored base `MMDMaterialData`

### Requirement: Standard materials use generic ShaderData for morphable texture channels
Standard C4D materials SHALL use a small set of generic MMD ShaderData shaders for texture channels where material morph logic must operate on sampled shader output. Texture morph shaders SHALL wrap the original texture shader as a child shader where supported by the C4D shader hierarchy and apply PMX texture, sphere texture, or toon texture factors to the sampled child output. Material morph updates SHALL update generic shader parameters or snapshots instead of creating one shader type per PMX field or per morph.

#### Scenario: Texture morph shader wraps original texture shader
- **WHEN** a Standard material is linked to material index 0
- **AND** the material color channel already uses a bitmap or compatible texture shader
- **THEN** the material color channel SHALL use a generic MMD material texture morph shader as the channel shader
- **AND** the original texture shader SHALL be preserved as a child shader of the generic wrapper when the shader type supports that hierarchy

#### Scenario: Texture factor applies to sampled child shader output
- **WHEN** a Standard material is linked to material index 0
- **AND** a Material morph changes material index 0 texture factor
- **THEN** the generic texture morph shader SHALL sample the wrapped child shader
- **AND** the shader SHALL apply the effective texture factor to the sampled child color

### Requirement: Simple material morph fields are precomputed before parameter synchronization
Standard material fields that can be represented as simple colors, floats, or direct material parameters SHALL be computed during material morph runtime evaluation and then synchronized to shader or material parameters. These fields SHALL NOT require per-sample ShaderData evaluation unless they are part of a texture sampling operation.

#### Scenario: Diffuse color updates as precomputed parameter
- **WHEN** a Standard material is linked to material index 0
- **AND** a Material morph changes material index 0 diffuse RGB
- **THEN** the material runtime evaluator SHALL compute the effective diffuse RGB before shader sampling
- **AND** the Standard material adapter SHALL update the material color parameter or a simple color shader parameter from the precomputed value

#### Scenario: Alpha updates as precomputed parameter
- **WHEN** a Standard material is linked to material index 0
- **AND** a Material morph changes material index 0 alpha
- **THEN** the material runtime evaluator SHALL compute the effective alpha before shader sampling
- **AND** the Standard material adapter SHALL update the material alpha parameter or a simple alpha shader parameter from the precomputed value

### Requirement: ShaderData output is read-only with respect to scene state
MMD material ShaderData implementations SHALL NOT mutate C4D scene objects, morph data, model manager data, or BaseMaterial parameters from shader output sampling. ShaderData output SHALL read only shader parameters, render-time snapshots, or other data prepared by the material runtime update path.

#### Scenario: Render sampling does not change morph state
- **WHEN** Cinema 4D samples an MMD material shader during viewport or render evaluation
- **THEN** the shader output SHALL NOT change morph strength values
- **AND** the shader output SHALL NOT write to `MMDMaterialData`, material morph definitions, or linked `BaseMaterial` parameters

### Requirement: Supported non-shader material fields are synchronized through adapters
Material morph fields that cannot be represented by Standard ShaderData channels but are currently represented by the material system SHALL be synchronized through the material adapter layer when the effective material runtime state changes. Material morph fields that are not yet used by the material system, including edge color and edge size, SHALL be preserved for UI editing, scene persistence, and PMX export but SHALL NOT be required to affect runtime material appearance in this change.

#### Scenario: Supported scalar fields update through adapter path
- **WHEN** a Material morph changes a supported scalar material field such as specular power
- **THEN** the effective runtime material state SHALL contain the adjusted supported field
- **AND** the material adapter SHALL apply the supported field through C4D material parameters without requiring a dedicated ShaderData plugin

#### Scenario: Unused edge fields are preserved but not applied
- **WHEN** a Material morph changes edge color or edge size for a material
- **THEN** the imported material morph data SHALL preserve the edge color and edge size values
- **AND** runtime material synchronization SHALL be allowed to ignore those fields until the material system has an edge rendering path

#### Scenario: Renderer-specific materials keep data integrity
- **WHEN** a linked material is Redshift, Octane, or Corona
- **THEN** the material adapter SHALL apply only supported precomputed simple color and float fields through renderer-specific parameters
- **AND** texture factor, sphere texture factor, toon texture factor, edge color, edge size, and other unsupported renderer-specific visual fields SHALL remain preserved in MMD material runtime and PMX export data
- **AND** the adapter SHALL NOT be required to create classic ShaderData wrappers or edit renderer-specific node graphs for this change
