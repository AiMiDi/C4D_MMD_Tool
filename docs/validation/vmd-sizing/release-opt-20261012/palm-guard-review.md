# Avoidance palm regression drafts

All files live in the temporary directory. Shared source/tests/build were not edited. The tested Constraints source snapshot SHA256 is 9042EFC4642892224757E5AA4EC3E23931647BE0B845DEC9952080314F4189A3.

## Cross-arm compensation guard

`cross-arm.cpp::CheckCrossArmPalmGuard` constructs an asset-free two-arm PMX skeleton. It isolates the internal palm-helper contract after avoidance has rotated the left upper arm20 degrees. An offset box/capsule attached to the left wrist is initially clear of all right-arm samples. The test explicitly evaluates full counterrotation and requires penetration greater than .15, proving that the intended rejection path is reached.

For both shapes: full penetration is approximately .2 PMX; guarded penetration is .00197053416, below .002 tolerance. Remaining palm angle .0537319382rad is strictly between zero and input .34906585rad, proving partial compensation rather than either unconditional full acceptance or no-op. Every sampled collision guard,30degree wrist budget and unchanged finger-local rotation is asserted.

`Constraints-no-guard.cpp` differs only by disabling the compensation collision guard. `no_guard.exe` fails with depth .2 and the explicit cross-arm penetration assertion. This is an internal-helper unit fixture, not a claim that a complete Run(source,target,motion) automatically generates the simulated avoided pose.

## Unwritable wrist tracks

`unwritable.cpp.inc::CheckUnwritablePalmTracks` tests flags0x102 append rotation,0x202 append translation,0x402 fixed axis,4 nonrotatable, with both absent and authored wrist keys. It runs the actual private Avoid stage over11frames with a world sphere that moves the wrist by .350442 PMX. It requires the arm to have moved, then verifies the protected wrist has respectively0 or2 keys with exact authored frame/translation/quaternion/interpolation preservation.

All8 cases pass. `Constraints-unsafe-wrist.cpp` removes only the writable-channel selection condition in Avoid's controlled set. `unsafe_wrist.exe` fails the no-added/replaced-wrist-keys assertion.

The tests include a Constraints implementation snapshot into their TU to access private helper boundaries and override that object from the existing static core archive. This is temporary test plumbing. The unwritable scenario can be adapted directly into the maintained Advanced test through the normal Run stage, while the cross-arm fixture needs an internal-test access strategy or its own isolated TU target; no public production API was added.

## Evidence and build

CMakeLists.txt builds guard, no_guard and unsafe_wrist against the existing SSE2 standalone libMMD.lib, without rebuilding the shared core. `guard.log` exits0; `no-guard.log` and `unsafe-wrist.log` exit1 for the intended assertions. Numeric source is asset-free. Final shared-core/SDK/native acceptance remains the parent task's responsibility.
