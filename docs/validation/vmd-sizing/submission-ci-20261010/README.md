# Motion sizing submission and CI packaging — 2026-10-10

The libMMD motion-sizing core and CMT host integration are committed and pushed. The OpenSpec change is archived and synchronized to the main specification. The latest compatibility fix is `c7d9a8afba3dcc8dfc0453984f8ef0d961fb5d95`; its libMMD dependency is `e4aca1048af9216d65bea91ec734710e360bcdd0`, published on `codex/motion-sizing`.

[Package run 38027413361](https://github.com/AiMiDi/C4D_MMD_Tool/actions/runs/38027413361) passed all 21 SDK/platform builds: 8 Windows x64, 8 macOS Intel and 5 Apple Silicon. Functional checks passed 41 MCP tests, 15 libMMD tests and 24 plugin tests. The first attempt exposed three old-SDK compatibility issues; `compatibility-failures.log` records them and the full rerun validates their fixes.

The CI produced one Windows installer and eight macOS Intel ZIPs using package version `0.9.3.2`. These are CI validation artifacts, not a new published release. The installer ProductVersion, all ZIP CRCs, plugin architectures, real resource files, motion-sizing license and bundled MCP source were checked. `artifact-verification.json` records SHA-256 hashes. Local downloads are under `output/vmd-sizing-ci-38027413361` (untracked).

`receipt.json` contains job links and artifact identities. `functional-checks.log` contains cloud test evidence. `archive-validation.json` records focused OpenSpec success and eight unrelated pre-existing specification failures. Unchecked archive tasks 8.2, 12.3 and 13.5 remain tracked in `docs/dev/vmd-sizing-pending-validation.md`.

No installer was executed and no current Cinema 4D session was restarted. Package inspection and compilation do not replace pending native menu, MCP/dialog synchronization and queue-interaction acceptance. Unrelated PE synchronization work remains uncommitted and was excluded from the published source.
