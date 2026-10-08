# mcp-mmd-operations Specification

## Purpose
Provide discoverable, typed MCP access to production MMD operations, with explicit scene identity, documented options, transactional mutations, and verifiable release behavior.

The accepted execution scope for this delivery is Windows / Cinema 4D 2026.4+ and SDK 2026/R20 compilation. On 2026-10-08 the user explicitly deferred macOS and older-host UI execution; both remain unverified, not passed. This scope does not constitute public-release or cross-platform runtime acceptance.

## Requirements

### Requirement: Production API availability in normal releases
Normal Debug and Release distributions SHALL include the production MMD automation API and its maintained MCP adapter by default. Availability MUST NOT require enabling the runtime regression bridge. Host MCP activation and credentials SHALL remain explicit user configuration.

#### Scenario: Regular Release is connected
- **WHEN** a regular Release build with the regression bridge disabled is loaded and the authorized host connection is available
- **THEN** the adapter SHALL expose production MMD capabilities and execute supported operations

#### Scenario: Host automation is disabled
- **WHEN** the user has not enabled the host MCP service or required execution permission
- **THEN** the adapter SHALL report the missing prerequisite without changing host preferences or disrupting normal plugin use

### Requirement: Typed discovery and capability reporting
The MCP endpoint SHALL expose discoverable MMD tools with input and output schemas. Capabilities SHALL report API and plugin versions, host version, supported operations and options, and explicit compatibility status. Clients MUST NOT need to submit arbitrary Python source or private SDK parameter IDs for supported MMD operations.

#### Scenario: Client lists tools
- **WHEN** an MCP client requests tool discovery
- **THEN** it SHALL receive named, typed MMD inspection, PMX and VMD file operations, animation-slot selection, mode, physics, morph-strength, and frame-evaluation tools

#### Scenario: Plugin or protocol is unavailable
- **WHEN** the expected plugin is missing or its protocol is incompatible
- **THEN** capability discovery SHALL return an actionable compatibility error before accepting mutations

### Requirement: Explicit document and instance identity
Requests SHALL identify the target document and object using opaque handles scoped to a host session and document instance. Names, plugin type IDs, and PMX indices MUST NOT substitute for instance identity. Deleted, reopened, or replaced instances SHALL invalidate affected handles.

#### Scenario: Models have the same name
- **WHEN** a request targets one of two equally named models by handle
- **THEN** only that model SHALL be read or changed

#### Scenario: A document is reopened
- **WHEN** a client reuses handles from the prior document instance after close and reopen
- **THEN** the operation SHALL return a stale-handle error without changing the new document

#### Scenario: An object is cloned
- **WHEN** the host creates a clone of a model or camera
- **THEN** inspection SHALL expose distinct handles for the source and clone

### Requirement: Main-thread execution and document isolation
Scene access and mutation SHALL execute serially on the Cinema 4D main thread. Target liveness and document ownership SHALL be checked immediately before execution. Requests targeting another document MUST NOT silently substitute the active document or selection.

#### Scenario: A non-active document is targeted
- **WHEN** a valid request addresses a model in a non-active document
- **THEN** it SHALL operate on that document while preserving the user's active document and unrelated selection

#### Scenario: A target disappears while queued
- **WHEN** a queued request's target is deleted before execution
- **THEN** the dispatcher SHALL reject it as stale without dereferencing the old instance

### Requirement: Non-modal operations and structured results
Supported MCP operations SHALL accept paths and options as typed parameters and complete without file pickers, confirmation dialogs, or success/error message dialogs. Results SHALL contain success state, operation identity, structured errors, warnings, and operation-specific counts or handles. Invalid inputs SHALL be rejected before mutation.

#### Scenario: Invalid file or options are supplied
- **WHEN** an input is malformed, a format is unsupported, or an option is invalid
- **THEN** the tool SHALL return a structured error with the relevant field and leave the scene unchanged

#### Scenario: A motion contains unmatched names
- **WHEN** valid motion data includes bone or morph names absent from the target model
- **THEN** the result SHALL report matched counts and unmatched names without opening a dialog

### Requirement: Motion and runtime option fidelity
MCP parameters SHALL preserve the documented business semantics of append, active-slot replacement, explicit merge, channel switches, model information, physics handling, scale, curve selection, and baking. Frame offsets and evaluation SHALL use explicit units; VMD offsets SHALL be integral 30-fps frames.

#### Scenario: Append and replace are requested
- **WHEN** a client appends a motion and later replaces the active slot
- **THEN** append SHALL create an isolated slot and replacement SHALL retain that slot's identity while preserving other slots

#### Scenario: Model information is disabled
- **WHEN** model-info import or export is disabled
- **THEN** visibility and IK metadata SHALL follow the same disabled-channel behavior as the documented native tools

#### Scenario: Fractional VMD offset is supplied
- **WHEN** a request supplies a non-integral VMD frame offset
- **THEN** it SHALL fail validation without altering animation, materials, mode, or document time range

### Requirement: Transactional scene mutations
Each successful scene mutation SHALL form one user Undo action. Failed operations SHALL restore changed objects, materials, slots, mode, selection, and document time state. Restored or replaced subtrees SHALL have valid runtime bindings before subsequent operations.

#### Scenario: A motion import is undone
- **WHEN** the user performs one Undo after a successful MCP motion import
- **THEN** the model's prior animation state SHALL be restored without undoing an unrelated user operation

#### Scenario: A failed import is followed by a valid import
- **WHEN** an import fails and a valid request is then applied to the same model
- **THEN** the first request SHALL leave the prior state intact and the second SHALL complete without using stale runtime bindings

### Requirement: Export preserves source state and confirms file completion
Export and baking SHALL preserve source objects, tracks, materials, mode, time, and active slot. Success SHALL be reported only after the destination file is fully written, with its resolved path, size, and SHA-256. Replacing an existing file SHALL require an explicit overwrite parameter.

#### Scenario: Motion is baked
- **WHEN** a client exports final bone and morph animation with baking enabled
- **THEN** exported values SHALL match native evaluation and the source scene SHALL retain its prior state

#### Scenario: Destination cannot be written
- **WHEN** the requested destination is invalid or an existing file lacks overwrite authorization
- **THEN** export SHALL fail without a false success result or a partially replaced final file

### Requirement: Unambiguous timeout and retry behavior
Requests SHALL expose operation IDs and distinguish queued, running, completed, failed, and outcome-unknown states. A transport timeout MUST NOT be reported as proof of rollback. Reusing an operation ID within its advertised retention window SHALL return the existing outcome rather than apply the mutation twice.

#### Scenario: Client times out during an import
- **WHEN** the client wait expires while the host may still be executing
- **THEN** the adapter SHALL report an in-progress or unknown outcome and SHALL NOT automatically repeat the import

#### Scenario: Client reconnects and queries the operation
- **WHEN** the same live host session retains the operation record
- **THEN** the client SHALL retrieve its latest state or completed result by operation ID

### Requirement: Documented connection and credential handling
The release SHALL include adapter startup and client configuration instructions, supported host versions, and explicit permission requirements. Authentication material SHALL be obtained from a configured local credential source and MUST NOT appear in tool results, logs, checked-in examples, or error messages.

#### Scenario: Host authentication fails
- **WHEN** the supplied credential is missing or invalid
- **THEN** the adapter SHALL report an authentication error and configuration guidance without exposing credential values

#### Scenario: A host lacks the required MCP capability
- **WHEN** the plugin runs in a host version without the required automation transport
- **THEN** the adapter SHALL report unsupported-host status while the normal plugin workflow continues to function

### Requirement: Release MCP acceptance evidence
Production MCP acceptance SHALL run through the distributed typed tools in a normal Release build with the regression bridge disabled. Evidence SHALL identify the actual loaded plugin, host/API versions, requests and results, and resulting scene or file behavior. Regression-bridge success alone MUST NOT count as production MCP acceptance.

#### Scenario: End-to-end release validation
- **WHEN** a release candidate is evaluated for MCP support
- **THEN** acceptance SHALL cover discovery, file workflows, slots, runtime changes, save/reopen, same-name and stale handles, multiple documents, Undo, failure recovery, and timeout handling through the production endpoint
