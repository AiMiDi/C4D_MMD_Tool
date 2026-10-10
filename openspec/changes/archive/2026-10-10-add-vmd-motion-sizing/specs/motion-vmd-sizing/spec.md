# VMD Motion Sizing

## Purpose

Adapt a VMD motion to a different MMD model's body proportions, inspect stable intermediate results in Cinema 4D, and apply an accepted result without replacing the original animation.

## ADDED Requirements

### Requirement: Production sizing MCP interface
The plugin SHALL expose typed production MCP operations for starting, polling, cancelling and releasing sizing jobs; inspecting paginated diagnostics; previewing stages; applying member or camera results; and exporting VMD with overwrite protection. The interface SHALL operate without the runtime regression bridge, use explicit live document/model/slot handles, and accept file or stable slot inputs for 1 to 16 unique same-document characters.

#### Scenario: Background job and diagnostic inspection
- **WHEN** a client starts valid character inputs through the production interface
- **THEN** it receives an opaque job handle and can poll without waiting on the host main thread
- **AND** completed results expose ratios, warnings, stage counts and bounded constraint samples

#### Scenario: Deduplication and stale results
- **WHEN** the same operation ID is reused with different nested input parameters or an expired job is requested
- **THEN** the request is rejected explicitly
- **AND** applying a result revalidates all target binding snapshots before creating a new undoable animation slot

#### Scenario: Export and task cleanup
- **WHEN** a client exports or releases a completed job
- **THEN** existing destination files require explicit overwrite and exports use staged writes with file identity verification
- **AND** releasing the job closes only its owned preview and invalidates its handle

#### Scenario: Native validation boundary
- **WHEN** the native regression runner connects to an older loaded plugin without sizing operations
- **THEN** it records a blocked result before creating test documents
- **AND** protocol tests and compilation are not presented as native sizing acceptance

### Requirement: Reproducible upstream baseline
The project SHALL provide reproducible single-character movement baselines with upstream revision, source and input hashes, parameters, output values, dependency versions and execution evidence. Synthetic evidence SHALL be identified as such.

#### Scenario: Regenerating a baseline
- **WHEN** the documented reference runner executes against the pinned upstream checkout
- **THEN** it records the actual upstream movement output and comparison data without modifying that checkout

### Requirement: Validated movement adaptation
The tool SHALL accept a source PMX, target MMD bind model and file VMD, compute horizontal/vertical movement ratios and supported center/leg IK offsets, and report invalid or unsupported inputs. Unmodified animation channels and interpolation SHALL be preserved.

#### Scenario: Three completed stages
- **WHEN** valid inputs are processed
- **THEN** original, scaled and offset-adjusted motions are available independently
- **AND** diagnostics identify ratios, offsets and skipped corrections

#### Scenario: Invalid or degenerate input
- **WHEN** required proportions cannot be measured, hierarchy is cyclic or values are non-finite
- **THEN** processing fails explicitly without publishing a successful applicable result

### Requirement: Isolated stage comparison
Users SHALL be able to replay and switch completed stages against the unadjusted motion on the same target model in an owned preview document. Preview SHALL NOT alter the source document's animation, bind state or time.

#### Scenario: Switching a preview stage
- **WHEN** the user selects original, scaled or offset-adjusted output
- **THEN** the comparison uses that stored result at the preview timeline time
- **AND** the artist's source document remains unchanged

### Requirement: Cancellable background processing
Sizing computation SHALL run without blocking scene interaction and SHALL support cancellation without committing partial output. Worker computation SHALL NOT access mutable host scene objects.

#### Scenario: Cancel or close
- **WHEN** a job is cancelled or its tool is closed
- **THEN** no partial motion is applied to the source model

### Requirement: Safe result application and export
Applying a completed stage SHALL create a new independently persisted animation slot using one undo transaction. Stale or missing target models SHALL reject application. Users SHALL also be able to export a selected completed stage as VMD.

#### Scenario: Apply undo and reload
- **WHEN** a result is applied, undone, redone and the scene is saved and reopened
- **THEN** original and adjusted slots remain independently selectable with their respective motion

#### Scenario: Target changed during computation
- **WHEN** the target bind snapshot differs from the calculation input or the document has closed
- **THEN** application is rejected with a reason and the original animation is preserved

### Requirement: Pose and twist stages
The tool SHALL provide independent stance and twist stages. Stance SHALL account for corresponding bind segment directions; twist distribution SHALL preserve child orientation and bound end-position error for supported serial chains, including offset twist axes. Unsupported topology SHALL be diagnosed. Disabled stages SHALL preserve their predecessor.

#### Scenario: Different arm bind angles
- **WHEN** source and target arm bind directions differ
- **THEN** the stance stage corrects arm and elbow local rotations using their incoming and outgoing axes
- **AND** upstream comparison evidence identifies the exact supported case

#### Scenario: Twist chain
- **WHEN** a supported serial twist bone lies between an arm segment and its child
- **THEN** distributing twist preserves the end joint pose at sampled frames

#### Scenario: Offset twist axis
- **WHEN** the serial twist bone is not collinear with the arm and child
- **THEN** parent and child rotation compensation bounds end-position error by the configured tolerance without introducing unplayable translation channels

### Requirement: Playback-consistent advanced pose evaluation
Advanced solving SHALL use the host libMMD interpolation convention and evaluate rotation and translation append dependencies, including local append and negative weights. Unsupported cyclic append branches SHALL be isolated and diagnosed; invalid indices and non-finite weights SHALL fail preflight. Target append source and weight changes SHALL invalidate applicable results.

#### Scenario: Sparse animation on a shoulder append chain
- **WHEN** a valid shoulder append chain is evaluated between motion keys
- **THEN** the offline arm pose agrees with the corresponding C4D playback pose within numeric tolerance
- **AND** original VMD rotations are not projected onto fixed axes during sampling

#### Scenario: Shared finger controls
- **WHEN** several contact goals share arm joints or a finger touches multiple other fingers
- **THEN** connected contacts share a consistent goal and are solved simultaneously with bounded steps
- **AND** the final diagnostics retain unresolved constraints

### Requirement: Bounded collision and contact solving
The tool SHALL support sphere, box and capsule avoidance, source-derived wrist/finger pair contacts and floor contacts in PMX units. Solving SHALL be bounded and cancellable and SHALL report residuals and unresolved constraints. Reported collision coverage SHALL describe sampled arm points rather than full surface guarantees.

#### Scenario: Reachable and unreachable constraints
- **WHEN** the selected constraints are solved
- **THEN** reachable fixtures reduce their residuals
- **AND** unreachable constraints remain visible in diagnostics without non-finite output

### Requirement: Batch and camera adaptation
The tool SHALL accept multiple source/target/motion sets in a shared MMD coordinate system, solve cross-character contacts at common frames and adapt a camera VMD's framing. The C4D dialog SHALL expose the batch, member results, stage comparison and separate camera export/application.

#### Scenario: Two character contact
- **WHEN** original motions contain close hands across characters
- **THEN** the batch stage attempts to preserve their shared contact and reports final error

#### Scenario: Camera framing
- **WHEN** a camera VMD and valid character batch are supplied
- **THEN** framing is adapted using common source/target landmarks while preserving rotation, field of view, perspective flag and interpolation bytes
- **AND** original camera input remains available independently

### Requirement: Scene-linked sizing panel
The tool SHALL expose the sizing panel and original Tools panel as sibling entries in the Extensions menu, reuse the MMD Tools logo, and accept an imported scene MMD model through a link field. Motion input SHALL support either a VMD file or a stable-identity animation slot from that model.

#### Scenario: Read an imported motion slot
- **WHEN** the user selects a model slot as motion input
- **THEN** the tool reads that slot in an isolated document clone without changing the source model's active slot, bind state, or time
- **AND** a deleted slot is rejected rather than replaced with another slot at the same index

### Requirement: Automatic model comparison
The panel SHALL offer debounced automatic calculation and stage preview after parameter changes. The preview SHALL use disposable model copies and preserve the comparison time; only explicit application writes a new animation slot to the source model.

#### Scenario: Change parameters during calculation
- **WHEN** automatic preview is enabled and solver parameters change while a job runs
- **THEN** the old job is cancelled and only the latest input is previewed after calculation
- **AND** closing the preview disables automatic reopening until the user enables it again

### Requirement: MCP sizing panel synchronization
Production MCP sizing operations SHALL publish their effective input and presentation state to the sizing dialog, including model links, file or stable slot inputs, per-member options, camera options, selected member, stage and overlay. Dialog synchronization SHALL NOT start a duplicate calculation or mutate a job's immutable inputs.

#### Scenario: MCP starts before the dialog opens
- **WHEN** a valid MCP sizing job starts and the dialog opens later
- **THEN** the dialog displays its effective inputs and result state
- **AND** selecting a batch member restores that member's options without discarding hidden solver settings

#### Scenario: Preview and UI lifecycle
- **WHEN** MCP previews a member and stage
- **THEN** the open dialog reflects that member, stage and overlay and operates on the same result
- **AND** closing the dialog does not cancel or release the MCP job

#### Scenario: Editing and releasing
- **WHEN** the user edits synchronized inputs
- **THEN** subsequent UI computation uses a separate job without changing the original MCP job
- **AND** releasing or expiring an observed MCP job disables its result actions without retaining its session

### Requirement: Reusable libMMD computation
The SDK-independent motion sizing API and implementation SHALL be owned by libMMD, use the `libmmd::sizing` namespace and the public `libMMD/Model/MMD/MMDMotionSizing.h` header, and be built into the existing libMMD target. Core tests, synthetic fixtures and upstream license notices SHALL reside with the library. Host document and UI lifecycle SHALL remain outside libMMD.

#### Scenario: Independent library consumer
- **WHEN** a C++17 application uses the installed libMMD public headers and library
- **THEN** it can call Run and RunBatch without C4D SDK headers or the former cmt_motion_sizing target
- **AND** the library's focused regression tests can run without the parent plugin repository

### Requirement: Consistent role queue editing
Selecting an unqueued model SHALL create a draft without replacing an existing queue member. Removing a member SHALL update the editor to the selected remaining member, preserving each member's own options.

#### Scenario: Add a second role
- **WHEN** role A is queued and the user selects role B
- **THEN** A remains unchanged and B is shown as a draft until explicitly added
- **AND** pending draft inputs cannot trigger calculation of a different queued member

#### Scenario: Remove a role
- **WHEN** the user removes the selected role
- **THEN** all editor inputs are restored from the selected remaining role
- **AND** removing the last role clears target and motion inputs and stops pending automatic calculation
