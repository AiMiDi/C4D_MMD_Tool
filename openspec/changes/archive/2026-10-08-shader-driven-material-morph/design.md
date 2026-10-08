## Context and decisions

Implement the user-approved shader-driven material morph plan. Keep persistent base materials and PMX offsets authoritative. Use reusable internal output roles (color, scalar, texture wrapper) rather than per-morph plugin classes. Preserve the existing shader plugin ID and legacy parameter interpretation; role parameters select the new behavior.

Group/Flip expansion and Mul/Add composition are pure. Rendering resolves the source model in its own document and obtains an immutable state for the requested time. Standard InitRender captures state; Output only consumes that state and an initialized child shader. Redshift uses fixed native User Data readers on prepared mesh parameters. Runtime never builds material graphs.

Preview weights are transient and separate from animated strengths, support mixed Material/Group/Flip, affect only materials and clear on entering animation mode or ordinary reopening. Render-document cloning preserves the preview snapshot. New imports prepare managed bindings; old files require an undoable upgrade. Material mutation and binding preparation are main-thread operations.

Current output follows the Saba reference, with native-MMD fidelity still pending: keep texture Mul M and Add A separately; U=(1-M.a)+T_rgb*M.rgb*M.a, textured RGB=(clamp(U+(U-1)*A.a,0,1)+A.rgb)*D_rgb; opacity=T_a*D_a. Factor Alpha affects RGB, not opacity. Standard evaluates the operation after child sampling. Redshift uses the equivalent affine input scale M.rgb*M.a*(1+A.a) and bias 1-M.a*(1+A.a), then saturates, adds A.rgb and multiplies D.rgb through fixed native nodes. State and checksums retain raw Mul/Add for main, sphere and toon textures. The final texture contract must be decided by native MMD output; Saba is a comparison reference, not the authority. No-texture outputs use D alone. Roughness=clamp(pow(2/(max(power,0)+2),0.25),0,1). This correction does not add sphere, toon, ambient or edge display promises.

Binding version 2 requires explicit undoable upgrade from version 1; old owned bindings are recognized and diagnosed rather than sent through legacy material writes. Legacy unbound shader parameters retain their old interpretation. Redshift prepares seven readers and four texture math nodes, validates internal and surface wiring, and refuses foreign connections or edited math operations. No per-frame graph mutation is introduced. Existing images from version 1 remain historical receipts only.

## Validation and risks

Prove the Standard snapshot and Redshift User Data routes in a minimal native render before completing UI migration. Cover cycles, mixed weights, repeats, resets, document cloning, seek, background rendering, save/reload, ownership and rollback. User-owned running C4D sessions and unrelated dirty files must remain intact. Native rendering evidence is separate from compilation and node inspection.
