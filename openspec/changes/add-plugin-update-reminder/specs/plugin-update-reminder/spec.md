# Spec Delta

## Purpose

Let Cinema 4D MMD Tool users discover newer stable releases without interrupting their scene workflow, and control automatic checks and ignored versions across restarts and plugin installations.

## ADDED Requirements

### Requirement: Background stable release check
The plugin SHALL check the fixed project GitHub latest-release endpoint in one background worker with TLS validation, bounded network waits and response size. Automatic checks SHALL default to enabled and occur at most once per 24 hours. Shutdown SHALL cancel and join the worker.

#### Scenario: Startup is due
- **WHEN** automatic checking is enabled and the last attempt is at least 24 hours old
- **THEN** startup initiates a background request without blocking the UI

#### Scenario: Unreachable service
- **WHEN** networking or parsing fails
- **THEN** no modal prompt is shown and the last attempt is persisted to prevent request storms

### Requirement: Numeric release comparison
The plugin SHALL compare validated three-part or four-part numeric versions component by component, accepting an optional v prefix and treating a missing fourth component as zero. Drafts, prereleases, invalid versions and versions not newer than the installed version SHALL NOT produce a new-update reminder.

#### Scenario: Four-part version comparison
- **WHEN** installed version is 0.9.3.2 and stable release is v0.9.3.10
- **THEN** a newer release is identified

### Requirement: User-controlled reminder
The Cinema 4D preferences SHALL contain an MMD Tools category with automatic-check toggle, installed/latest status, manual check and release-page buttons. The tool panel SHALL NOT contain update controls. Manual checking SHALL bypass automatic-check throttling and ignored-version suppression. Opening the fixed project release page SHALL require the user's button action.

#### Scenario: Ignored release
- **WHEN** the user ignores a newer release
- **THEN** automatic reminders for that exact numeric version are suppressed while a later release remains eligible

#### Scenario: Explicit recheck
- **WHEN** the user manually checks an ignored release
- **THEN** the result is displayed and the release page can be opened

### Requirement: Durable update preferences and package identity
The plugin SHALL store update preferences and last-known stable version in C4D user preferences without overwriting unrelated values. The installed version SHALL come from a resource version file stamped with the final package version, including packages using reused build artifacts. Missing or invalid installed version SHALL disable update comparison.

#### Scenario: Reinstall and restart
- **WHEN** resources are replaced and Cinema 4D restarts
- **THEN** automatic-check and ignored-version choices remain in user preferences

#### Scenario: Cached newer release
- **WHEN** a newer stable release was cached and no check is currently due
- **THEN** using an MMD Tools function can display its reminder subject to automatic-check and ignore preferences

### Requirement: Use-triggered localized release popup
Startup SHALL only check in the background. After opening MMD Tools or motion adaptation, or invoking an import/export operation, the plugin SHALL show a nonmodal popup for an eligible newer release. It SHALL display only the current UI language's Chinese or English release section when bilingual headings exist. The popup SHALL offer release page, later and ignore-version actions, and automatically appear at most once per version per session.

#### Scenario: Startup without tool usage
- **WHEN** a newer release is found before any MMD Tools function is used
- **THEN** no update popup is shown

#### Scenario: Localized release notes
- **WHEN** an eligible newer release has Chinese and English sections and the UI is Chinese
- **THEN** tool usage shows the Chinese section and excludes the English section and build metadata

#### Scenario: Later in current session
- **WHEN** the user dismisses a version with Later and invokes another MMD Tools function
- **THEN** that version is not automatically shown again in the current session

#### Scenario: Missing translation
- **WHEN** the release has language sections but lacks the current UI language
- **THEN** the popup displays a localized instruction to view the release page
