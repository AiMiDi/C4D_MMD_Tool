## ADDED Requirements

### Requirement: Native PSR constraints feed MMD pose evaluation
In animation mode, enabled native PSR position and rotation constraints evaluated in the Expression priority range SHALL supply the driven bone channels to MMD append, IK and physics evaluation. The system SHALL preserve frozen bind transforms and the constraint settings. Unconstrained channels SHALL retain MMD animation behavior.

#### Scenario: A constrained IK goal moves the limb
- **WHEN** a null object drives an MMD IK goal through a native PSR constraint and the IK solver is enabled
- **THEN** moving or keyframing the null updates both the goal and the solved limb in that evaluation
- **AND** priorities -100, 0 and 100 yield equivalent results

#### Scenario: Position-only and rotation-only constraints
- **WHEN** only one transform channel is constrained
- **THEN** the other channel continues to follow its MMD animation

### Requirement: External pose input has evaluation-local lifetime
External pose samples SHALL be recomputed for each document evaluation, including repeated evaluations at the same time. Disabling or removing the last effective constraint SHALL restore ordinary MMD animation without seeking. Copies, undo and scene reload SHALL NOT reuse samples from another object tree. Same-frame evaluation SHALL NOT advance physics time.

#### Scenario: Disable and restore a constraint at the same frame
- **WHEN** a PSR constraint is disabled, removed, or loses its target
- **THEN** the affected bone resumes MMD animation in the next evaluation at the current frame
- **WHEN** a valid constraint is enabled again
- **THEN** its current result is consumed without stale IK overrides

#### Scenario: Save reload and copy
- **WHEN** a scene with keyframed nulls and PSR constraints is saved and reopened or copied
- **THEN** the current document's targets drive its own bones and IK chain
- **AND** the source scene and bind matrices remain unchanged
