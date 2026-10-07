## ADDED Requirements

### Requirement: Bone manager-driven hierarchy index synchronization

The system SHALL treat `MMDBoneManagerObject` as the authoritative source for bone hierarchy indices. When a managed bone hierarchy changes, the bone manager SHALL traverse its managed `Ojoint` subtree in depth-first pre-order, assign fresh bone indices from that traversal order, and use the same pass to determine each managed bone's parent bone index.

#### Scenario: Reparenting a bone updates all affected indices
- **WHEN** a user moves a managed bone from the bone manager root under another managed bone
- **THEN** the bone manager SHALL recompute bone indices for the affected managed subtree using depth-first pre-order
- **THEN** the moved bone's `PMX_BONE_PARENT_BONE_INDEX` SHALL match the new managed parent's index
- **THEN** all affected managed bones SHALL expose indices consistent with the recomputed traversal order

#### Scenario: Reordering siblings updates traversal order
- **WHEN** a user reorders two sibling managed bones under the same parent
- **THEN** the bone manager SHALL recompute indices from the new sibling order
- **THEN** the resulting bone indices SHALL reflect the updated depth-first pre-order sequence

### Requirement: Bone tags shall notify manager only on topology changes

Each `MMDBoneTag` SHALL detect runtime topology changes by tracking its current parent object, previous sibling, and resolved bone manager ownership. A bone tag SHALL send a hierarchy-dirty notification to the bone manager only when one of those topology relationships changes.

#### Scenario: No hierarchy change produces no hierarchy-dirty notification
- **WHEN** a managed bone stays under the same parent with the same previous sibling and the same resolved bone manager
- **THEN** the bone tag SHALL NOT send a hierarchy-dirty notification for that evaluation cycle

#### Scenario: Manager ownership change triggers a hierarchy-dirty notification
- **WHEN** a managed bone is moved from one bone manager subtree to another bone manager subtree
- **THEN** the bone tag SHALL detect the manager ownership change
- **THEN** the destination bone manager SHALL receive a hierarchy-dirty notification and recompute its managed cache

### Requirement: Bone manager cache and selector items stay synchronized

After a hierarchy synchronization pass, `MMDBoneManagerObject` SHALL rebuild `bone_list_` and `bone_items_` from the same traversal result. `bone_items_` SHALL always contain the `-1 -> "-"` entry and SHALL expose all managed bones in the same order and index mapping used for managed bone lookup.

#### Scenario: Adding a managed bone updates selector items
- **WHEN** a new managed bone is inserted anywhere inside the bone manager subtree
- **THEN** the next hierarchy synchronization pass SHALL include that bone in `bone_list_`
- **THEN** `bone_items_` SHALL contain the new bone's index-to-name entry while preserving the `-1 -> "-"` entry

#### Scenario: Removing a managed bone removes stale selector items
- **WHEN** a managed bone is removed from the bone manager subtree
- **THEN** the next hierarchy synchronization pass SHALL drop that bone from `bone_list_`
- **THEN** `bone_items_` SHALL NOT retain a stale entry for the removed bone

### Requirement: Bone tag hierarchy display fields are manager-owned

After each hierarchy synchronization pass, the bone manager SHALL write the synchronized values back to each managed bone tag's hierarchy display fields. `PMX_BONE_INDEX`, `PMX_BONE_PARENT_BONE_INDEX`, and `PMX_BONE_PARENT_BONE_NAME` SHALL reflect the manager-owned traversal result rather than tag-local calculations.

#### Scenario: Managed parent bone name is refreshed after reparenting
- **WHEN** a managed bone is reparented under another managed bone
- **THEN** the bone tag's `PMX_BONE_PARENT_BONE_INDEX` SHALL be updated to the new managed parent's synchronized index
- **THEN** the bone tag's `PMX_BONE_PARENT_BONE_NAME` SHALL be updated to the new managed parent's current object name

#### Scenario: Non-managed parent clears parent display fields
- **WHEN** a managed bone's direct C4D parent is not another managed bone inside the same bone manager subtree
- **THEN** the bone tag's `PMX_BONE_PARENT_BONE_INDEX` SHALL be set to `-1`
- **THEN** the bone tag's `PMX_BONE_PARENT_BONE_NAME` SHALL be set to an empty string

### Requirement: Edit mode hierarchy synchronization is event-driven

Bone hierarchy synchronization in edit mode SHALL be event-driven and SHALL NOT rely on per-frame hierarchy recalculation in `MMDBoneTag::Execute()`. When no topology change is detected, edit mode evaluation SHALL leave synchronized hierarchy fields unchanged.

#### Scenario: Idle edit mode does not recompute hierarchy every frame
- **WHEN** the model remains in edit mode and no managed bone topology changes occur between evaluations
- **THEN** bone hierarchy synchronization SHALL NOT trigger a fresh hierarchy traversal for each frame
- **THEN** the previously synchronized hierarchy fields SHALL remain valid until a topology change occurs

### Requirement: Initialization paths reuse the same hierarchy synchronization pipeline

The system SHALL reuse the same bone manager hierarchy synchronization pipeline after PMX import and after scene runtime reconstruction, so that initial cache population and later manual edits produce the same managed bone indices and parent references.

#### Scenario: PMX import initializes the authoritative hierarchy cache
- **WHEN** a PMX model import creates the bone manager subtree and managed bone tags
- **THEN** the bone manager SHALL run the same hierarchy synchronization pipeline used for manual hierarchy edits
- **THEN** the imported bone tag display fields and selector items SHALL match the authoritative managed traversal result

#### Scenario: Scene reload restores the authoritative hierarchy cache
- **WHEN** a scene containing an `MMDModelManagerObject` is reopened and the runtime rebuild reconnects the bone manager
- **THEN** the bone manager SHALL repopulate its hierarchy cache through the same synchronization pipeline
- **THEN** managed bone tag hierarchy display fields and selector items SHALL match the authoritative managed traversal result before further edits
