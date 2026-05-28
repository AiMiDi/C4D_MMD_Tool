# libmmd-immdnode-abstraction Specification

## Purpose
TBD - created by archiving change vmd-bone-c4d-tracks. Update Purpose after archive.
## Requirements
### Requirement: IMMDNode abstract interface

The libMMD library SHALL provide an `IMMDNode` abstract interface in `IMMDNode.h` with pure virtual methods covering node operations used by `MMDIkSolver` and other subsystems (IK, physics bindings, adapters), including: `GetGlobalTransform()`, `SetGlobalTransform()`, `GetInitialGlobalTransform()` (rigid-body offset / bind pose), `GetLocalTransform()`, `SetIKRotate()`, `GetIKRotate()`, `AnimateRotate()`, `UpdateLocalTransform()`, `UpdateGlobalTransform()`, `GetParent()`. All methods SHALL use Eigen types (`Matrix4f`, `Quaternionf`) as appropriate for the existing `MMDNode` API.

#### Scenario: Interface usable by MMDIkSolver

- **WHEN** `MMDIkSolver` is compiled against `IMMDNode*` instead of `MMDNode*`

- **THEN** all solver methods (`Solve`, `SolveCore`, `SolvePlane`, `BuildChainPath`, `UpdateChainPathGlobalTransform`) SHALL compile and function correctly

### Requirement: MMDNode implements IMMDNode

`MMDNode` SHALL implement `IMMDNode`, providing the existing method implementations as overrides. Existing code using `MMDNode*` with `MMDIkSolver` SHALL continue to work when `PMXNode*` / `MMDNode*` is passed where `IMMDNode*` is expected (implicit upcast).

#### Scenario: Backward compatibility with MMDNode

- **WHEN** existing code creates an `MMDIkSolver` with `MMDNode*` pointers

- **THEN** the solver SHALL behave identically to before the interface was introduced

### Requirement: MMDIkSolver uses IMMDNode interface

`MMDIkSolver` SHALL accept `IMMDNode*` for `SetIKNode`, `SetTargetNode`, and `AddIKChain`. The `IKChain::m_node` member SHALL be typed as `IMMDNode*`. All internal solver logic SHALL operate through the `IMMDNode` interface.

#### Scenario: Solver with custom IMMDNode implementation

- **WHEN** an external consumer provides a custom `IMMDNode` implementation (e.g. `C4DIKChainNodeAdapter` wrapping C4D objects)

- **THEN** `MMDIkSolver::Solve()` SHALL correctly iterate, compute IK rotations, and call `SetIKRotate` on the custom nodes

- **THEN** `BuildChainPath()` SHALL correctly traverse `GetParent()` on custom nodes

### Requirement: Unit tests for IMMDNode interface

The libMMD test suite SHALL include tests verifying that `MMDIkSolver` works correctly with both `MMDNode` and a mock `IMMDNode` implementation.

#### Scenario: Mock node IK solving

- **WHEN** a test creates a simple 3-bone chain using mock `IMMDNode` objects

- **WHEN** `Solve()` is called with a target position

- **THEN** the chain bones' IK rotations SHALL converge toward the target within the iteration limit

