# Pending native motion-sizing acceptance

Source change archived: `openspec/changes/archive/2026-10-10-add-vmd-motion-sizing`. These checks remain unverified and must not be marked passed based on offline tests or CI compilation.

- [ ] Verify Tools and motion-sizing entries appear directly as siblings in Extensions; fix the remaining outer Mmdtool grouping if needed.
- [ ] Load the packaged binary and record its SHA256; verify MCP inputs/options/member/stage/overlay in both already-open and newly-opened dialogs. Verify close/release/expiry and that UI edits create an independent job.
- [ ] Add A then B without overwriting A; verify draft blocks automatic computation, switching restores independent/hidden settings, removing B loads A, and removing the last role clears inputs and pending computation.
- [ ] Preserve user documents; retain only task-owned validation documents and record cleanup and original document restoration.

Use the 8.5 scene scale for the real asset demonstration. The historical native advanced solve and current offline migration comparison have distinct receipts and are not substitutes for these checks.
