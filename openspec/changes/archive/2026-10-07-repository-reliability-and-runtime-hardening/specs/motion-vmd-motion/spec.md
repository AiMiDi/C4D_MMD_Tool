## ADDED Requirements

### Requirement: Motion import options control channel replacement
Motion import SHALL honor the bone, morph, and model-info channel switches. Replacement SHALL replace the active slot while preserving other slots; non-replacement SHALL add an isolated slot; explicit merge SHALL combine keys in the active slot with incoming keys winning at matching times.

#### Scenario: Model info disabled
- **WHEN** a VMD with visibility and IK keys is imported with model info disabled
- **THEN** those keys are not imported

#### Scenario: Replacement and additional slot
- **WHEN** import is performed with replacement enabled
- **THEN** the active slot is replaced by the imported animation and other slots are retained
- **WHEN** import is performed with replacement disabled
- **THEN** previous slots remain and the new slot does not inherit their morph or IK tracks

### Requirement: Model info follows animation slots and scene persistence
Model visibility and IK states SHALL follow the selected animation slot and survive scene save/reload. Scenes from earlier persistence versions SHALL remain readable. Leaving animated visibility playback SHALL restore the artist's base viewport/render visibility.

#### Scenario: Save reload and slot switch
- **WHEN** two slots have different visibility and IK keys and the scene is saved and reopened
- **THEN** selecting either slot evaluates only its corresponding keys

### Requirement: Motion export options reflect actual output
Motion export SHALL honor channel switches, position scale, frame offset, and rotation curve selection. Model-info-disabled output SHALL contain no visibility or IK keys. Sparse export SHALL preserve stored key interpolation; baked export SHALL sample evaluated final poses at 30 VMD frames per second.

#### Scenario: Bake without disturbing source scene
- **WHEN** the user exports baked motion containing IK, controls, or physics
- **THEN** the output contains evaluated bone poses for every sampled frame
- **AND** the original document time, mode, tracks, and simulation state are preserved

#### Scenario: Model info round trip
- **WHEN** a motion containing visibility toggles is imported and exported with model info enabled
- **THEN** exported show/hide transitions retain their values and frame positions
