# Display Frame Manager

## Purpose
Preserve and edit PMX display frame data on the model manager so imported frame groups, bone targets, morph targets, and export ordering survive Cinema 4D scene workflows.

## Requirements

### Requirement: Display Frame Data Model

The system SHALL define a `DisplayFrameData` struct containing the following fields:
- `name` (String): Frame group name
- `name_universal` (String): Frame group universal/English name
- `frame_type` (Enum): DefaultFrame / SpecialFrame
- `targets` (BaseArray): Item list, where each item contains a type (Bone/Morph) and a target index (Int32)

The system SHALL store all display frame data as a `maxon::BaseArray<DisplayFrameData>` within `MMDModelManagerObject`.

#### Scenario: Data Model Population After PMX Import
- **WHEN** a user imports a PMX file containing display frame data
- **THEN** the system SHALL convert each `PMXDisplayFrame` into `DisplayFrameData` and store it in the list, preserving the frame group name, type flag, and the type/index of all items

#### Scenario: Empty Display Frame List
- **WHEN** a user imports a PMX file that contains no display frames
- **THEN** the display frame list SHALL be empty, and the UI displays no frame groups

### Requirement: Display Frame Serialization

The system SHALL implement Read/Write/CopyTo methods for display frame data, ensuring the data is fully preserved when saving, loading, or duplicating the project.

#### Scenario: Reopening Saved Project
- **WHEN** a user saves a project file containing edited display frames and reopens it
- **THEN** all display frame data (frame group names, item lists) SHALL exactly match the pre-save state

#### Scenario: Backward Compatibility for Older Files
- **WHEN** a user opens an older project file lacking display frame data
- **THEN** the system SHALL load normally, with an empty display frame list and no errors generated

### Requirement: Display Frame UI - Frame Group Selection

The system SHALL provide a `LONG` + `CYCLE` dropdown list in the "Display Frame" tab of `MMDModelManagerObject`, listing all frame group names for the user to select the currently edited frame group.

#### Scenario: Selecting a Frame Group
- **WHEN** a user selects a frame group from the dropdown list
- **THEN** the properties area below SHALL display the name edit box and the item list for that frame group

#### Scenario: Empty Frame Group List
- **WHEN** there is no display frame data
- **THEN** the dropdown list SHALL show a placeholder prompt, and all editing controls SHALL be disabled

### Requirement: Frame Group Name Editing

The system SHALL provide a STRING type property control to display the local and universal names of the currently selected frame group, allowing users to edit them directly.

#### Scenario: Modifying Frame Group Name
- **WHEN** a user modifies the frame group name field
- **THEN** the system SHALL update the `name` field of the corresponding `DisplayFrameData` and synchronously update the display text in the CYCLE dropdown list

### Requirement: Item List Display

Once a frame group is selected, the system SHALL display all its items using a dynamic description. Each item SHALL appear as one row, containing:
- Type label (`[Bone]` or `[Morph]`)
- Target name (looked up from the bone or morph list using the index)

#### Scenario: Displaying a Bone Item
- **WHEN** the frame group contains an item of type BoneIndex with index N
- **THEN** the item row SHALL display `[Bone]` and the name of the N-th bone

#### Scenario: Displaying a Morph Item
- **WHEN** the frame group contains an item of type MorphIndex with index N
- **THEN** the item row SHALL display `[Morph]` and the name of the N-th morph

#### Scenario: Invalid Index
- **WHEN** the target index of an item exceeds the current bone or morph list bounds
- **THEN** the item SHALL display the index number as its name

### Requirement: Adding Items

The system SHALL provide functionality to add items in the frame group editing area:
- Type selection control (CYCLE: Bone/Morph)
- Target selection control (CYCLE: dynamically populated with the current model's bone or morph names)
- Add button

#### Scenario: Adding a Bone Item
- **WHEN** a user selects "Bone" as type, selects a bone, and clicks Add
- **THEN** the system SHALL append a BoneIndex item to the end of the current frame group, and the item list UI SHALL refresh immediately

#### Scenario: Adding a Morph Item
- **WHEN** a user selects "Morph" as type, selects a morph, and clicks Add
- **THEN** the system SHALL append a MorphIndex item to the end of the current frame group, and the item list UI SHALL refresh immediately

### Requirement: Deleting Items

Each item row SHALL provide a Delete button.

#### Scenario: Deleting an Item
- **WHEN** a user clicks the Delete button for an item
- **THEN** the system SHALL remove the item from the current frame group, and the item list UI SHALL refresh immediately

### Requirement: Item Sorting

Each item row SHALL provide Move Up (↑) and Move Down (↓) buttons.

#### Scenario: Moving an Item Up
- **WHEN** a user clicks the Move Up button on a non-first item
- **THEN** the item SHALL swap positions with the previous item, and the UI SHALL refresh

#### Scenario: Moving an Item Down
- **WHEN** a user clicks the Move Down button on a non-last item
- **THEN** the item SHALL swap positions with the next item, and the UI SHALL refresh

#### Scenario: Moving First Item Up or Last Item Down
- **WHEN** a user clicks the Move Up button on the first item, or Move Down on the last item
- **THEN** the system SHALL take no action

### Requirement: Adding a New Frame Group

The system SHALL provide functionality to add a new frame group, including a name input box and an Add button.

#### Scenario: Adding a New Frame Group
- **WHEN** a user inputs a frame group name and clicks the Add button
- **THEN** the system SHALL append an empty frame group to the end of the display frame list, update the CYCLE dropdown list, and automatically switch to the new frame group

### Requirement: Deleting a Frame Group

The system SHALL provide a button to delete the currently selected frame group.

#### Scenario: Deleting a Frame Group
- **WHEN** a user clicks the delete frame group button
- **THEN** the system SHALL remove the currently selected frame group and all its items, update the CYCLE dropdown list, and adjust the selected index to a valid value

### Requirement: PMX Export Display Frames

The system SHALL convert the `DisplayFrameData` list into `PMXFile::m_displayFrames` in `SavePMX` when writing the export file.

#### Scenario: Exporting with Display Frames
- **WHEN** a user exports a PMX file, and display frame data exists
- **THEN** the exported PMX file SHALL contain a display frame structure (frame group names, types, item lists) strictly matching the edited state

#### Scenario: Exporting Empty Display Frames
- **WHEN** a user exports a PMX file, and the display frame list is empty
- **THEN** the `m_displayFrames` of the exported PMX file SHALL be empty
