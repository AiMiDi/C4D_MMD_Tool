# Model Import Delta

## MODIFIED Requirements

### Requirement: Import option handling
The PMX import flow SHALL honor `ModelImport` settings for scale, model components, name conversion, and material renderer type, including the distinct RS Toon choice when supported. Existing saved material choices and the default Standard selection SHALL retain their meaning.

#### Scenario: Import options are applied
- **WHEN** a PMX import runs with specific `ModelImport` flags
- **THEN** the importer SHALL enable or skip polygon, normal, UV, material, bone, weight, IK, inherit, expression, multipart, and English-name handling according to those flags

#### Scenario: RS Toon is selected for model import
- **WHEN** materials are enabled and the user selects an available RS Toon profile
- **THEN** imported material entries SHALL receive Toon materials with supported animation bindings in both merged-mesh and multipart import modes

#### Scenario: A saved legacy choice is loaded
- **WHEN** import settings store any pre-existing material-type value
- **THEN** that value SHALL resolve to the same material type as before this change

## ADDED Requirements

### Requirement: Consistent Toon discovery and import
The native import UI and production automation interface SHALL expose the same RS Toon capability. Automation SHALL accept the material type `redshift_toon` and advertise it only when required capabilities are available. Unsupported explicit requests SHALL fail before import mutation rather than falling back to another renderer.

#### Scenario: An automation client imports with Toon
- **WHEN** the client selects `redshift_toon` on a capable host
- **THEN** the imported profile and supported appearance SHALL match the native UI option

#### Scenario: The host cannot provide Toon
- **WHEN** an explicit Toon import is requested with material import enabled
- **THEN** the result SHALL identify the unavailable capability and leave the pre-existing document state unchanged

### Requirement: Import scene-setting isolation
Selecting RS Toon SHALL NOT silently change the document renderer, lights, exposure or color-management settings. Documentation and diagnostics SHALL identify the rendering prerequisites for viewing the generated materials.

#### Scenario: Toon is imported into a document using another renderer
- **WHEN** Toon material creation is available but the document uses a different active renderer
- **THEN** import SHALL preserve document rendering settings and explain that Redshift rendering is required to view the intended result
