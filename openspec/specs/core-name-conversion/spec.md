# Name Conversion

## Purpose

Maps Japanese MMD bone names to English equivalents (or other conventions like UE5). Used during model import and motion import to match bones by name.

## Requirements

### Requirement: Name conversion configurations
The system SHALL load name conversion tables from JSON files stored in the plugin resource `name_conversion/` directory.

#### Scenario: Load a conversion table
- **WHEN** a user selects a name conversion JSON file
- **THEN** the system SHALL load its Japanese-to-target-name mappings for later lookup

#### Scenario: Enumerate available conversion files
- **WHEN** the name conversion dialog is opened
- **THEN** the system SHALL list `.json` files from the configured `name_conversion/` resource directory

### Requirement: Name conversion lookup
The system SHALL provide lookup functions that convert PMX or VMD bone names using the active conversion table.

#### Scenario: Convert a known bone name
- **WHEN** a source bone name exists in the active conversion table
- **THEN** `NameConversion::Conver()` SHALL return the mapped target name

#### Scenario: Use conversion during import
- **WHEN** model import requests English bone names or motion import requires converted matching
- **THEN** the import flow SHALL consult the loaded conversion table before creating or matching C4D bone names

### Requirement: Name conversion editing
The system SHALL allow users to manage JSON name conversion mappings through the update dialog.

#### Scenario: Save edited mappings
- **WHEN** the user edits a conversion mapping and saves it
- **THEN** the mapping SHALL be written back as a JSON object that can be loaded by the conversion system

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
