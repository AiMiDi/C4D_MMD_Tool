# Name Conversion

## Overview

Maps Japanese MMD bone names to English equivalents (or other conventions like UE5). Used during model import and motion import to match bones by name.

## Architecture

### NameConversion Class

Defined in `module/ui/cmt_name_conversion_dialog.h/cpp` (coupled with dialog).

| Method | Description |
|--------|-------------|
| `Init()` | Static initialization at plugin start |
| `LoadConfig(filename)` | Loads conversion table from JSON file into lookup tables |
| `InitConver(str, op)` | Registers a bone name (`op=true`) or checks existence (`op=false`) |
| `Conver(name)` | Converts a bone name using loaded table |
| `AutoUpdate()` | Auto-update conversion when switching configs |

### UpdateNameConversionDialog

UI dialog for managing name conversion configurations. Allows users to select and edit conversion JSON files. Browses `name_conversion/` directory for `.json` files via `CheckSuffix("json")`.

## Configuration Files

JSON files stored in `res/S24_up/name_conversion/`:

| File | Purpose |
|------|---------|
| `default.json` | Standard Japanese → English mapping |
| `UE5.json` | Japanese → UE5 convention mapping |

### Format

Each JSON file maps Japanese bone names to target names:

```json
{
  "センター": "center",
  "上半身": "upper body",
  "下半身": "lower body",
  "首": "neck",
  "頭": "head"
}
```

Read/written via `cmt_json::ReadJsonFile()` / `cmt_json::WriteJsonFile()` from `utils/json_util.hpp`.

## Usage in Import

- `ModelImport::import_english` — use English names for imported bones
- `MotionImport::import_by_local_name` — match VMD motion to bones by local (Japanese) name
- The conversion table is consulted when creating C4D joint objects from PMX bone data

## Source Files

| File | Role |
|------|------|
| `module/ui/cmt_name_conversion_dialog.h/cpp` | NameConversion logic + dialog UI |
| `utils/json_util.hpp` | JSON read/write utilities |
| `res/S24_up/name_conversion/default.json` | Default mapping table |
| `res/S24_up/name_conversion/UE5.json` | UE5 mapping table |
