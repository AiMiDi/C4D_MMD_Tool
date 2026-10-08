## Why

Material morph evaluation currently rewrites material parameters and may build shader branches during expression execution. This couples animation to scene mutation and cannot guarantee independent background-render evaluation. Introduce internal, reusable color/scalar/texture outputs driven by a pure material evaluator.

## What Changes

- Standard render snapshots and fixed Redshift User Data graphs for plugin-owned materials.
- Independent mixed Material/Group/Flip preview, explicit legacy upgrade and binding diagnostics.
- Preserve PMX definitions, existing shader compatibility and artist-owned content.

## Capabilities

### New Capabilities
- `shader-driven-material-morph`: immutable evaluation, internal outputs and explicit binding lifecycle.

### Modified Capabilities
- `material-system`: creation and morph bindings for Standard/Redshift.

## Impact

Shared plugin source/resources, SDK-independent tests, native material regression fixtures and material workflow documentation. No user baking step or arbitrary-material takeover.
