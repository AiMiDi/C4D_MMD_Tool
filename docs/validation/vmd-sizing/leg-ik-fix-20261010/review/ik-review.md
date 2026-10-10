# Motion sizing independent review — 2026-10-10

Read-only review of current libMMD motion sizing changes. Production files and C4D were not mutated by this reviewer.

## Confirmed findings

1. IK iteration-count contract mismatch (P1/P2, release gate)
   - New bridge `dependency/libMMD/src/libMMD/Model/MMD/MMDMotionIK.cpp` used `std::max(4, bone.m_ikIterationCount)`.
   - C4D `source/module/tools/object/mmd_model_runtime.cpp:658` uses `iter_count <= 0 ? 4 : iter_count`; legal positive counts 1–3 must remain unchanged.
   - Independent repro in this directory uses the same MMDIkSolver, fixture geometry, node bridge, and compiler ISA. `reference.cpp` deliberately retains the OLD minimum-4 rule; current linked library contains the parent's fix.
   - At count=1, left/right knee position difference is 0.164982 PMX units (1.402347 at 8.5 scene scale); ankle difference is 0.0615301 PMX units.
   - Parent informed and implemented preserve-positive-count semantics plus 1-vs-4 and 0-vs-4 tests.

2. Generated foot-IK channels on append-driven controls are discarded by C4D (P2)
   - `MMDMotionLegs.cpp` selected standard controls via 0x24, SupportedChain, and ikAffected, without excluding append flags 0x300.
   - `source/module/tools/object/mmd_model_manager.cpp:3845-3849` skips importing motion channels for every append/inherit bone.
   - Thus a legal standard-named foot IK with append translate/rotate could be solved/baked offline and then lose its correction on import.
   - Parent informed and is adding conservative skip + warning + unchanged-track regression.
   - The same older issue exists in floor foot-goal selection at `MMDMotionConstraints.cpp:336-343`: it also needs writable-translation and non-append checks. C4D clears non-translatable input at `mmd_bone.cpp:3405`. Parent informed separately.

## Validation / scope

- Read IK node reset, PMX parent/append/deform grouping, VMD IK switch lookup, leg capsule distance and temporal smoothing, foot displacement backtracking, hand/contact/floor stage ordering, and C4D runtime/import contracts.
- Existing focused CTest run passed 2/2 before the parent's subsequent fixes. This is independent execution of existing tests, not new native verification.
- Did not operate or restart C4D. Did not claim newly built DLL has been loaded.
- The caller's documented residual crossings, physics/morph/external-control exclusions, and lack of universal velocity continuity are known scope limits rather than review findings.
- An initial standalone reference build incorrectly used AVX2 against the SSE2 standalone library and crashed; corrected reference to matching SSE2. This was only the reviewer-owned repro tool, and the successful numerical result above comes from matching ISA.
