# shader-driven-material-morph Specification

## Purpose
Provide reusable internal Standard shader outputs and fixed Redshift node graphs
driven by immutable PMX Material Morph evaluation. Define isolated preview,
explicit upgrade and ownership rules while preserving separate texture Mul/Add
operands and accurately recording the limits of renderer and native-MMD evidence.

## Requirements

### Requirement: Immutable material evaluation
The plugin SHALL evaluate base materials and effective morph weights without mutating definitions or renderer graphs.

#### Scenario: Repeated and reordered evaluation
- **WHEN** the same weights are evaluated repeatedly or after seeking
- **THEN** the result SHALL match fresh evaluation from base data

### Requirement: Renderer-owned output modules
Standard and Redshift SHALL provide color, scalar and sampled texture coefficient outputs for prepared plugin-owned bindings.

#### Scenario: Background animation render
- **WHEN** a render document evaluates a frame
- **THEN** its outputs SHALL use that document and frame without relying on viewport caches or material graph mutation

### Requirement: Native MMD texture semantics
Texture Morph rendering SHALL use native MMD output as the authority for Mul/Add order, sample dependence and factor-Alpha interpretation. Saba SHALL be treated as a reference implementation, not proof of native equivalence. Separate texture Mul/Add RGBA state SHALL be retained until the sampling operation; collapsing them into one texture multiplier requires demonstrated equivalence. The reference repair preserves these operands but does not establish native fidelity.

#### Scenario: Reference implementation divergence
- **WHEN** the current texture formula differs from libMMD/Saba and no native MMD output settles the behavior
- **THEN** the texture semantics SHALL remain unresolved, and tests derived from the current formula SHALL NOT establish native MMD fidelity

#### Scenario: Reference sampling regression
- **WHEN** a .25 texel has neutral multiplication and additive RGB .2 / Alpha 0
- **THEN** the reference texture output SHALL be .45 before Diffuse, rather than the old .30 combined-factor result
- **AND** factor Alpha SHALL affect the reference RGB operation, while image Alpha and Diffuse Alpha determine opacity

#### Scenario: Explicit acceptance waiver
- **WHEN** the user explicitly waives native MMD comparison and requests completion
- **THEN** the change MAY be completed and archived using the documented reference operation
- **AND** the acceptance record SHALL preserve the waiver and state that native MMD fidelity remains unverified

### Requirement: Isolated mixed preview
The editor SHALL provide transient Material/Group/Flip preview weights separate from formal animation.

#### Scenario: Exit preview or reopen
- **WHEN** preview is disabled or the scene is reopened
- **THEN** base state SHALL be restored without modifying saved morph definitions or tracks

### Requirement: Explicit upgrade
Legacy material structures SHALL remain intact until a user invokes an undoable upgrade on a recognized plugin-owned material.

#### Scenario: Artist modification
- **WHEN** a prepared binding no longer matches its owned structure
- **THEN** automatic application SHALL stop with a diagnostic and SHALL NOT overwrite unrelated nodes

### Requirement: Ordinary Redshift material input parity
The ordinary Redshift adapter SHALL resolve valid PMX Sphere texture indices and
apply specular color and power during material creation and explicit synchronization.
Its power-to-roughness approximation SHALL match the Morph binding approximation.

#### Scenario: Reverse synchronization without a Morph binding
- **WHEN** an ordinary plain or textured RS material has unconnected specular inputs
- **THEN** reverse synchronization SHALL read specular color and convert roughness to finite PMX power
- **AND** invalid input values or connected shader outputs SHALL preserve the corresponding stored base values
- **AND** resolving a Sphere path SHALL NOT imply a Sphere rendering implementation
