# Archive summary

Archived on 2026-10-08 with all 15 implementation tasks complete.

Material Morph evaluation now supplies immutable render state to internal
Standard shaders and fixed Redshift User Data graphs. It preserves independent
texture Mul/Add RGBA, supports isolated mixed preview and formal animation,
and provides explicit versioned upgrade, ownership checks and undoable editing.
The material editor also provides an EDIT-only whole Material Morph delete
button alongside offset deletion.

Evidence covers algorithm and PMX tests, SDK compatibility builds, native
shader sampling, GPU seek and 31-frame rendering, managed lighting responses,
and deletion/upgrade Undo/Redo with immediate save/reopen and PMX export.
The completion evidence is retained at
`_build_msvc/validation/shader-driven-material-morph/completion-20261008/`;
earlier binary-specific checkpoints remain in the same validation area.

Native MMD comparison was explicitly waived by the user. The texture operation
follows the documented Saba reference; native MMD fidelity and MMD BRDF
equivalence remain unverified. Task completion and archival do not certify
those claims or public-release/package acceptance.

`validation.md` preserves detailed receipts, exact module identities and the
distinction between historical failures and the later successful checkpoints.
