# Name Conversion

## Overview

Maps Japanese MMD bone names to English equivalents (or other conventions like UE5). Used during model import and motion import to match bones by name.

## Architecture

### NameConversion Class

Defined in `module/ui/cmt_name_conversion_dialog.h/cpp` (coupled with dialog).

| Method | Description |
|--------|-------------|
| `Init()` | Static initialization at plugin start |
| `InitConver()` | Loads conversion table from YAML |
| `Conver(name)` | Converts a bone name using loaded table |
| `AutoUpdate()` | Auto-update conversion when switching configs |

### UpdateNameConversionDialog

UI dialog for managing name conversion configurations. Allows users to select and edit conversion YAML files.

## Configuration Files

YAML files stored in `res/S24_up/name_conversion/`:

| File | Purpose |
|------|---------|
| `default.yaml` | Standard Japanese → English mapping |
| `UE5.yaml` | Japanese → UE5 convention mapping |

### Format

Each YAML file maps Japanese bone names to target names:

```yaml
センター: center
上半身: upper_body
下半身: lower_body
首: neck
頭: head
# ... etc
```

## Usage in Import

- `ModelImport::import_english` — use English names for imported bones
- `MotionImport::import_by_local_name` — match VMD motion to bones by local (Japanese) name
- The conversion table is consulted when creating C4D joint objects from PMX bone data

## Source Files

| File | Role |
|------|------|
| `module/ui/cmt_name_conversion_dialog.h/cpp` | NameConversion logic + dialog UI |
| `res/S24_up/name_conversion/default.yaml` | Default mapping table |
| `res/S24_up/name_conversion/UE5.yaml` | UE5 mapping table |
