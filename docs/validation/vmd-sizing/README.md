# VMD 动作适配（motion sizing）验证档案

VMD 动作适配/缩放这条线的验证记录入口。每个子目录只保留结论（README / 评审 md）与脚本、夹具源码；
原始日志、JSON 收据、TSV 数据、截图已移出版本库，归档在
`S:\tmp\cmt_vmd_profile_20261019\repo-evidence-archive-20261024\docs-validation\vmd-sizing\` 下同名目录。

## 子目录

| 目录 | 内容 |
| --- | --- |
| `ui-sync-20261009` | 面板/菜单项与 UI 同步 |
| `algorithm-audit-20261010` | 缩放算法审计 |
| `hand-contact-fix-20261010` | 手部接触修复 |
| `joint-release-20261010` | 关节释放策略 |
| `leg-ik-fix-20261010` | 腿部 IK 修复 |
| `final-fixes-20261010` | 收尾修复 |
| `libmmd-migration-20261010` | libMMD 侧迁移 |
| `progress-20261010` | 阶段记录 |
| `submission-ci-20261010` | 提交与 CI 校验 |
| `code-review-20261010` | 代码复查 |
| `advanced` / `advanced-completion` | 进阶项与完成度 |
| `contact-quality-20261013` | 接触质量 |
| `continuity-20261012` | 连续性（跨帧稳定） |
| `followup-20261012` | 后续项 |
| `release-opt-20261012` | 释放优化 |
| `temporal-floor-20261012` | 时间下限/取整 |

## 复现

脚本（`*.py`）与夹具（`*.cpp` / `*.h` / `*.inc`）保留在各自目录内，可直接重跑；
它们读写的原始输入输出已归档，重跑时按 README 指出的路径从归档取回即可。
