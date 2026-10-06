"""Dependency evidence must follow the selected build, not nearby artifacts."""

import importlib.util
from pathlib import Path
import subprocess
import tempfile
import unittest
from unittest.mock import patch
import xml.etree.ElementTree as ET


REPO = Path(__file__).resolve().parents[2]
spec = importlib.util.spec_from_file_location(
    "production_dependency_fixture", REPO / "scripts/c4d_production_mcp_validation.py")
runner = importlib.util.module_from_spec(spec)
spec.loader.exec_module(runner)

LIBRARIES = ("libMMD", "Bullet3Common", "BulletCollision", "BulletDynamics",
             "BulletInverseDynamics", "BulletSoftBody", "LinearMath")


class DependencyProvenanceTests(unittest.TestCase):
    def setUp(self):
        temporary_root = Path("S:/tmp")
        self.temporary = tempfile.TemporaryDirectory(
            prefix="cmt-dependency-provenance-",
            dir=str(temporary_root) if temporary_root.is_dir() else None)
        self.addCleanup(self.temporary.cleanup)
        self.root = Path(self.temporary.name).resolve()
        self.prebuilt = self.root / "selected"
        self.lib = self.prebuilt / "lib"
        self.lib.mkdir(parents=True)
        self.project = self.root / "build/plugins/mmdtool/project/mmdtool.vcxproj"
        self.project.parent.mkdir(parents=True)
        self.cache = {"identity": {"path": str(self.root / "build/CMakeCache.txt")},
                      "values": {"CMT_DEPS_PREBUILT_DIR": str(self.prebuilt)}}
        for configuration in ("Debug", "Release"):
            for name in LIBRARIES:
                suffix = "_Debug.lib" if configuration == "Debug" else ".lib"
                (self.lib / (name + suffix)).write_bytes((name + configuration).encode())
        self.write_project()

    def write_project(self, excluded=(), wrong_debug=False, search_path=None):
        graph = ET.Element("Project", xmlns="http://schemas.microsoft.com/developer/msbuild/2003")
        for configuration in ("Debug", "Release"):
            group = ET.SubElement(graph, "ItemDefinitionGroup", {
                "Condition": "'$(Configuration)|$(Platform)'=='" + configuration + "|x64'"})
            link = ET.SubElement(group, "Link")
            ET.SubElement(link, "AdditionalLibraryDirectories").text = (
                str(search_path or self.lib) + ";%(AdditionalLibraryDirectories)")
            suffix = "_Debug.lib" if configuration == "Debug" or wrong_debug else ".lib"
            ET.SubElement(link, "AdditionalDependencies").text = ";".join(
                name + suffix for name in LIBRARIES if name not in excluded
            ) + ";kernel32.lib;%(AdditionalDependencies)"
        ET.ElementTree(graph).write(self.project, encoding="utf-8", xml_declaration=True)

    def test_selected_link_inputs_are_recorded_without_build_attestation(self):
        # A nearby file is not an input unless the generated linker selects it.
        (self.lib / "unlinked.lib").write_bytes(b"not linked")
        result = runner.prebuilt_linker_identity(self.cache)
        self.assertEqual(result["status"], "recorded")
        self.assertFalse(result["source_build_relationship_verified"])
        for configuration in ("Debug", "Release"):
            libraries = result["configurations"][configuration]["libraries"]
            self.assertEqual(len(libraries), 7)
            self.assertNotIn("unlinked.lib", [Path(item["path"]).name for item in libraries])

    def test_same_name_other_directory_cannot_substitute_for_selected_input(self):
        other = self.root / "unselected/lib"
        other.mkdir(parents=True)
        (other / "libMMD.lib").write_bytes(b"wrong build")
        (self.lib / "libMMD.lib").unlink()
        result = runner.prebuilt_linker_identity(self.cache)
        release = result["configurations"]["Release"]
        self.assertEqual(release["status"], "unknown")
        self.assertIn("libMMD.lib", release["missing_required"])

    def test_unlinked_required_library_is_not_accepted_by_directory_scan(self):
        self.write_project(excluded=("BulletDynamics",))
        result = runner.prebuilt_linker_identity(self.cache)
        self.assertEqual(result["status"], "unknown")
        self.assertIn("BulletDynamics.lib", result["configurations"]["Release"]["missing_required"])

    def test_release_linking_debug_libraries_is_unknown(self):
        self.write_project(wrong_debug=True)
        release = runner.prebuilt_linker_identity(self.cache)["configurations"]["Release"]
        self.assertEqual(release["status"], "unknown")
        self.assertEqual(len(release["wrong_configuration"]), 7)

    def test_generated_project_must_confirm_the_configured_search_directory(self):
        self.write_project(search_path=self.root / "other/lib")
        release = runner.prebuilt_linker_identity(self.cache)["configurations"]["Release"]
        self.assertEqual(release["status"], "unknown")
        self.assertEqual(release["reason"], "configured_prebuilt_link_search_path_not_confirmed")

    def test_relative_prebuilt_path_remains_unknown(self):
        self.cache["values"]["CMT_DEPS_PREBUILT_DIR"] = "relative/prebuilt"
        result = runner.prebuilt_linker_identity(self.cache)
        self.assertEqual(result["status"], "unknown")
        self.assertEqual(result["reason"], "relative_prebuilt_cache_path_unresolved")

    def test_malformed_generated_project_remains_unknown(self):
        self.project.write_text("<broken", encoding="utf-8")
        self.assertEqual(runner.prebuilt_linker_identity(self.cache)["reason"],
                         "generated_linker_project_unreadable")

    def test_source_changes_invalidate_snapshot_but_test_output_does_not(self):
        dependency = self.root / "dependency"
        source = dependency / "src"
        source.mkdir(parents=True)
        maintained = source / "physics.cpp"
        maintained.write_bytes(b"first")
        unavailable_git = subprocess.CompletedProcess([], 1, "", "not a checkout")
        with patch.object(runner.subprocess, "run", return_value=unavailable_git):
            first = runner.dependency_source_identity(dependency)
            tests = dependency / "tests"
            tests.mkdir()
            (tests / "receipt.json").write_bytes(b"test output")
            self.assertEqual(first, runner.dependency_source_identity(dependency))
            maintained.write_bytes(b"other")
            changed = runner.dependency_source_identity(dependency)
        self.assertNotEqual(first["sha256"], changed["sha256"])
        self.assertEqual(first["file_count"], 1)
        self.assertEqual(first["git"]["status"], "unknown")

    def test_relative_source_override_blocks_release_snapshot(self):
        self.cache["values"]["CMT_LIBMMD_SOURCE_DIR"] = "relative/libMMD"
        recorded = {"status": "recorded"}
        with patch.object(runner, "dependency_source_identity", side_effect=(
                {"status": "unknown"}, recorded)), patch.object(
                runner, "prebuilt_linker_identity", return_value={
                    "configurations": {"Release": recorded}}):
            result = runner.dependency_identity(self.cache)
        self.assertFalse(result["snapshot_complete_for_release"])


if __name__ == "__main__":
    unittest.main()
