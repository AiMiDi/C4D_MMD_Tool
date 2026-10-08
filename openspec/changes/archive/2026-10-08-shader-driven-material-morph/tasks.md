## 1. Evaluation and render channels
- [x] 1.1 Implement pure Group/Flip expansion and material snapshot evaluation with focused tests.
- [x] 1.2 Implement internal Standard color/scalar/texture output roles and versioned bindings.
- [x] 1.3 Implement fixed Redshift User Data bindings and object-state publication.
- [x] 1.4 Build SDK 2026 and prove both paths with native minimal rendering.
- [x] 1.5 Resolve texture Morph Mul/Add and factor-Alpha semantics against native MMD output before claiming fidelity.
  - 2026-10-08: user explicitly requested skipping the native MMD comparison and marking this item complete. Accepted by user waiver; separate Mul/Add and Saba-reference implementation remain in use. Native MMD fidelity is unverified and is not claimed.
  - Reference repair implemented: separate main/sphere/toon Mul/Add RGBA, Saba post-sampling operation in Standard and an equivalent fixed Redshift graph, binding v2 explicit migration, independent factor checksums. Focused counterexamples and 450 direct/affine channel comparisons pass. Native MMD remains the final authority; reference agreement is not native fidelity. The user subsequently authorized another GPU verification run; its receipts are kept separate from the native MMD acceptance item.

## 2. Authoring and compatibility
- [x] 2.1 Add independent mixed preview, neutral reset and support diagnostics.
- [x] 2.2 Add explicit upgrade/repair transactions, ownership validation and clone/reopen handling.
  - Release 5a8929a8: two-material Standard/Redshift upgrades each pass three Undo/Redo cycles with immediate save/reopen; repair, shared-owner diagnostics and independent-copy persistence pass.
- [x] 2.3 Cover material/morph deletion, reordering, reverse-sync gating and PMX round-trip.
  - 2026-10-08: full material deletion passes three Undo/Redo cycles with immediate save/reopen and PMX export. Added the missing EDIT-only whole Material Morph delete button, preserving existing resource IDs; SDK 2026/2024/R20 compilation passes. After the user handled the confirmation, whole-Morph deletion passes three Undo/Redo cycles with immediate save/reopen, PMX export and native preview sampling. Group references remap to Multiply at index 0, and Flip still targets Group at index 1. The timed-out MCP operation is reconciled; private-document cleanup passes. Receipt: `_build_msvc/validation/shader-driven-material-morph/completion-20261008/completion-receipt.json`.
  - Last-offset deletion, reorder target preservation, reverse-sync gating and material PMX round-trip passed in the preceding checkpoints; full material/Morph deletion acceptance is now complete.

## 3. Acceptance
- [x] 3.1 Run focused logic and PMX tests and compatibility builds.
  - Offline highlight analyzer follow-up: 18/18 current CTest groups pass, including 16 analyzer positive/negative cases and a separate 12-image synthetic RGBA PNG CLI smoke check. These verify the validator, not native rendering; no C4D calls were made in this follow-up.
  - 2026-10-07: current SDK-independent Debug graph passes all 17 CTest groups, including four host-free highlight-session ownership/restoration cases. No C4D or GPU acceptance is implied; native highlight work is deferred while another agent owns the shared host.
  - 15 CTest groups passed; SDK 2026, 2024 and R20 Release builds passed after the batch-upgrade Undo fix. Earlier Debug compatibility receipts are retained separately.
  - Texture-factor repair: all 15 CTest groups and SDK 2026/2024/R20 Release builds pass; Standard six native sampling cases and actual v1-to-v2 Standard/Redshift upgrade Undo/Redo save/reopen pass on 5d699ce5.
- [x] 3.2 Run native preview, timeline, background render, Undo/Redo and persistence acceptance.
  - 2026-10-08: complete managed Standard/Redshift bindings render six lit-sphere cases each, covering Power 2/510, red/zero specular, repeat and save/reopen. Both renderers pass width/color/zero assertions and exact repeat/reopen PNG hashes. These complement the preceding texture, preview, animation and background-render receipts. Native MMD comparison was explicitly waived by the user, not proven by these images.
  - Ordinary RS Standard highlight follow-up: six native c4dpy images on Release d6ca05c6 / RS 2026.9.0 pass broad/narrow Power response, red specular, zero specular, repeat and save/reopen; repeat/reopen PNG hashes are identical. This closes the ordinary highlight response slice only; full managed-binding lighting and native MMD fidelity remain open. Either CPU or GPU suffices; device comparison is optional per user instruction.
  - Release 5a8929a8 passes Standard rendering, Redshift GPU preview, GPU 0/15/30/0/30/15/0 and CPU 0/30/15/0 rendering. GPU every-frame rendering passes 0 through 3, then runs out of memory at frame 4; full lighting/highlight images remain open.
  - Superseding texture repair 5d699ce5: all seven GPU seek renders and all 31 GPU frames 0..30 pass, with RGB/Alpha assertions and matching repeated-frame PNG hashes. The full lighting/highlight image matrix and native MMD fidelity remain open.
- [x] 3.3 Document tested capabilities and outstanding evidence with exact module identity.
  - Crash and batch-Undo failure evidence, exact corrected binary/PDB and native receipts archived; GPU sequence, full release/image matrix and independent UV export limits remain explicit.

## 4. Ordinary RS material parity
- [x] 4.1 Resolve the Sphere path in direct PMX creation and share specular conversion between ordinary materials and Morph bindings.
- [x] 4.2 Apply specular color/power in ordinary creation and sync; reverse-read plain/textured materials while preserving connected or invalid inputs.
- [x] 4.3 Verify conversion boundaries, SDK compilation, native plain/textured sync, reverse sync and save/reopen; record exact module identity.
  - C4D 2026.4.0 / RS 2026.9.0, Release module d6ca05c6: both plain/textured cases pass creation, sync, reverse sync and connected-input preservation; save/reopen and original-document restoration pass. Receipt: `_build_msvc/validation/remaining/rs-standard-specular-20261007/run/native-post-install-2/receipt.json`. This is node/data acceptance, not rendered highlight fidelity.
- [x] 4.4 Render and inspect ordinary RS specular color, zero specular and Power width response, with repeat/save-reopen verification on an available device.
  - Receipt: `_build_msvc/validation/remaining/rs-standard-highlight-native-20261007/receipt.json`; six successful native images, half-peak area 7385 -> 88 for Power 2 -> 510, red-only response and zero RGB peak. Original document and device settings restored in the isolated host; MMD BRDF equivalence is not claimed.
