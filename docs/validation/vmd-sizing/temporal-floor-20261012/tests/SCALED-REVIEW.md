# Scaled source-to-target temporal floor regression

Private regression only. No shared source, shared tests, SDK build, or C4D process changed.

`scaled-probe.cpp` is the runnable test. `Advanced-scaled-floor-draft.cpp` is the self-contained integration draft, entry `CheckScaledFloorContinuity()`.

Eight target/source ratios (.82, .86, .90, .92, .97, 1.03, 1.07, 1.11) each run ten scenarios: leaving contact, entering contact, one-frame pulse, left IK off/on, those four with a rotated parent, and two three-frame boundary cases. There are 1456 frames and2912 foot samples. Input keys use the source model bind positions. Target PMX bone/rigidbody positions and dimensions are scaled; parent rotation and authored center XZ motion keep their previous semantics. The target step limit is .075*ratio, with a fixed2e-6 verification allowance for float VMD channels. Original pair and IK guards are unchanged.

Baseline `Floor-diagnostic.cpp` is the unrounded prototype plus diagnostics only at frames1525+, outside these short tests. Both executable variants link the same private frozen libMMD library; the positive target explicitly compiles the private `Floor-rounded.cpp` snapshot. See scaled-receipt.json for SHA256 identities. This avoids confusing test executables with concurrently updated shared outputs.

Result: baseline41 STEP_FAIL assertions; patched0 failures and0 warnings. Every pair, both foot IK errors, disabled/inactive correction, worldXZ, and authored center channels pass. Per-left-foot cumulative absolute correction must exceed .05*ratio, in addition to the existing peak requirement. This specifically rejects all-zero output. A per-frame .05*ratio minimum would be invalid for the .92 pulse: the correction crosses from +.04 to a legitimate limited -.029, since the allowed step is .069.

Minimal observed failure: ratio .92, ordinary-parent exit case0, left foot. At frame8 actual correction is -.138000011444. Unrounded frame9 falls back to raw -.182163715362 and frame10 is0, creating a .182163715362 jump despite the .069 budget. Rounded frame9 is -.069000005722 and frame10 is0. This is the introduced temporal-bound failure, not a historical pre-temporal comparison.

Reproduce:

```powershell
cmake --build S:/tmp/cmt-sizing-temporal-floor-20261012/tests/build --config Release --target scaled_before scaled_after
& S:/tmp/cmt-sizing-temporal-floor-20261012/tests/build/Release/scaled_before.exe
& S:/tmp/cmt-sizing-temporal-floor-20261012/tests/build/Release/scaled_after.exe
```

Expected exit codes are1 and0 respectively. Logs: scaled-before.log and scaled-after.log. Spatially infeasible/disconnected IK domains remain outside this continuity guarantee; these fixtures are deliberately bent and reachable so a rounding failure cannot be dismissed as a safety-domain transition.
