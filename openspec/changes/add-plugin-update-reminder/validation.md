# Validation receipts

Date: 2026-10-14. Windows host: Cinema 4D 2026.4.0.

## Build and focused checks

- SDK 2026 Debug and SDK R20 Debug compiled and linked with the final source. Both runtime resource trees were synchronized after the final preferences layout change. Logs are available in the [historical evidence directory](https://github.com/AiMiDi/C4D_MMD_Tool/tree/32753932d529ce82677538d109d0709fec8be520/docs/validation/plugin-update-reminder/20261014/); the local directory was removed during cleanup on 2026-10-15.
- `update_policy_test` passed numeric version ordering, throttling, ignores, manual checks, bounded JSON parsing, Unicode surrogate pairs, bilingual note selection and CJK wrapping.
- The same test parsed a freshly fetched full GitHub release response, selected both language sections, and reported `v0.9.3.8`. Fixture: `S:\tmp\cmt-update-live-release-full.json`.
- OpenSpec strict validation and `git diff --check` passed. No installer or release was published.

## Native issues found and fixed

1. A static `GeDialog` was constructed before the C4D API was available. The host rejected the DLL with Windows error 1114. The dialog is now allocated lazily by the main-thread timer and deleted during `PluginEnd`.
2. Popup strings were placed in a dialog-specific table while the code used `GeLoadString`. The resulting `StrNotFound` language marker selected English on the Chinese host. The strings now reside in each language's global `c4d_strings.str` in both maintained resource trees.
3. The native edit control did not wrap long unbroken Chinese text despite `DR_MULTILINE_WORDWRAP`. A UTF-8-safe display formatter now inserts conservative CJK line breaks and preserves inline Latin words.
4. A long hint label widened the native description label column and clipped the version status. The preferences layout now uses short labels and a compact installed-to-latest status; both languages were inspected at the default dialog width.

## Native setup and earlier receipts

- All tests use a task-owned artifact and isolated preference directory under `S:\tmp\cmt-update-native-20261014`. Only the copied resource version is changed to `0.9.3.0` to exercise an update against the real latest release.
- C4D loaded `net.aimidi.mmdtool`, registered preference plugin 1056725 and the tools command, and cached `v0.9.3.8` with 4716 UTF-8 bytes of notes. Receipt: `localized-startup-receipt.json`; log: `startup-localized.log`.
- Startup did not display an update reminder. Using command 1056563 displayed a titled Chinese update window with Chinese notes and 查看更新 / 稍后 / 忽略此版本. This was visually inspected before the final CJK wrapping rebuild.
- Test process 24920 exited normally through C4D's Quit command after disposing only its task-owned empty document. Receipt sequence 7; external process inspection confirmed it was gone before launching the final artifact.
- Final Chinese process 40408 loaded the revised artifact, retained the cached preferences and opened the MMD Tools settings page with `c4d.PrefsLib_OpenDialog(1056725)`. Receipt: `final-zh-startup-receipt.json`; log: `startup-final-zh.log`.

## Final native acceptance

Window access recovered and the following checks passed in Windows Cinema 4D 2026.4.0. The accepted binary SHA-256 is `A955AE0B789338E56ED3E37F917E21BED765CB61D8562BE5DBE7387B35DAFC22`.

- **Chinese settings and popup:** final process 55564 loaded the plugin, opened preference plugin 1056725, displayed the complete version status, and showed Chinese notes/buttons after tools command 1056563. Text was inspected for wrapping, scrolling and language selection; no `StrNotFound` remained.
- **English settings and popup:** final process 81228 displayed English settings and English release notes/buttons. The popup excluded the Chinese section and build/download metadata.
- **Startup and use:** startup performed a background check without showing a popup; using MMD Tools displayed the known update. Turning automatic checking off suppressed the use-triggered reminder; manual checking still displayed it.
- **Later:** after clicking 稍后 in process 40408, reopening the tools panel did not repeat the same version in that session.
- **Preference persistence:** automatic checking was turned off in process 91268 and remained off after a normal restart into process 81228.
- **Ignore persistence:** Ignore This Version in process 81228 stored `v0.9.3.8`. Process 92464 retained it after restart, and using the tools panel did not show that update despite automatic checking being enabled.
- **View release:** 查看更新 in process 55564 closed the popup and opened Chrome at `https://github.com/AiMiDi/C4D_MMD_Tool/releases/tag/v0.9.3.8`. Browser title and visible release heading confirmed the target.
- **Normal exit:** the final task-owned process 55564 exited through C4D Quit command 12104, and an external lookup confirmed it was gone. The probe disposed only the task-owned empty validation document.

Screenshots, native receipts, build logs, the task-only Python probe and external exit receipt are preserved in [the evidence index](https://github.com/AiMiDi/C4D_MMD_Tool/blob/32753932d529ce82677538d109d0709fec8be520/docs/validation/plugin-update-reminder/20261014/README.md). Native acceptance covers Windows C4D 2026.4.0; R20 compilation does not establish R20 runtime acceptance, and macOS was not exercised. No installer or release was published.
