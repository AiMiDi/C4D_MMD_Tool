## ADDED Requirements

### Requirement: Group morph propagation to sub-morphs

GroupMorph SHALL propagate its strength to sub-morphs using additive semantics. When `UpdateMorph` is called, each sub-morph's strength SHALL be incremented by `group_strength * sub_morph_weight`, rather than being overwritten.

#### Scenario: Group morph adds to sub-morph strength
- **WHEN** a GroupMorph has strength 0.8 and references sub-morph A with weight 0.5
- **AND** sub-morph A already has strength 0.3 (from its own CTrack or manual setting)
- **THEN** after `GroupMorph::UpdateMorph`, sub-morph A's strength becomes 0.3 + (0.8 * 0.5) = 0.7

#### Scenario: Group morph with zero strength does not affect sub-morphs
- **WHEN** a GroupMorph has strength 0.0
- **THEN** sub-morph strengths remain unchanged after `GroupMorph::UpdateMorph`

### Requirement: Flip morph propagation to sub-morphs

FlipMorph SHALL propagate its activation to sub-morphs using additive semantics. When `UpdateMorph` is called and the flip morph's strength is >= 0.5, each sub-morph's strength SHALL be incremented by the sub-morph's defined weight. When strength < 0.5, sub-morphs SHALL not be modified.

#### Scenario: Flip morph activated adds to sub-morph strength
- **WHEN** a FlipMorph has strength 0.7 (>= 0.5) and references sub-morph B with weight 1.0
- **AND** sub-morph B already has strength 0.2
- **THEN** after `FlipMorph::UpdateMorph`, sub-morph B's strength becomes 0.2 + 1.0 = 1.2

#### Scenario: Flip morph not activated leaves sub-morphs unchanged
- **WHEN** a FlipMorph has strength 0.3 (< 0.5)
- **THEN** sub-morph strengths remain unchanged after `FlipMorph::UpdateMorph`

### Requirement: UpdateMorph execution order for compound morphs

The system SHALL process Group and Flip morphs before Mesh, UV, Bone, Material, and Impulse morphs during the `UpdateMorph` loop, ensuring compound morph propagation is complete before leaf morphs push values to their respective managers.

#### Scenario: Group morph propagates before mesh morph applies
- **WHEN** `Execute()` runs the UpdateMorph loop
- **THEN** all Group and Flip morphs have their `UpdateMorph` called first (propagating strength to sub-morphs)
- **THEN** all other morph types have their `UpdateMorph` called second (pushing final strength values to mesh/bone managers)

### Requirement: Morph UI visible in VMD mode

The `MODEL_MORPH_GRP` group SHALL be visible in VMD mode, allowing users to see morph strength sliders. Add/delete/rename/editor buttons for morphs SHALL be hidden in VMD mode (same as non-edit mode behavior).

#### Scenario: Morph sliders visible during VMD playback
- **WHEN** the model is in `MODEL_MODE_VMD`
- **THEN** the `MODEL_MORPH_GRP` group is visible in the attribute manager
- **THEN** morph strength sliders display current animated values
- **THEN** morph add-name inputs and add/delete/rename buttons are hidden

#### Scenario: Morph sliders reflect CTrack animation values
- **WHEN** the model is in `MODEL_MODE_VMD` and the timeline is playing
- **THEN** morph strength sliders update in real-time to reflect CTrack keyframe interpolation
