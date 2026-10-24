"""Exercise the real CMake guard on package modules, including nested xlibs."""
from pathlib import Path
import subprocess
import tempfile
import unittest

GUARD = Path(__file__).resolve().parents[1] / 'cmake/check_profiling_disabled.cmake'


class PackageProfileGuardTests(unittest.TestCase):
    def check_module(self, suffix, enabled):
        with tempfile.TemporaryDirectory() as temporary:
            directory = Path(temporary)
            module = directory / 'nested' / ('mmdtool' + suffix)
            module.parent.mkdir()
            module.write_bytes(b'\0fixture\0' + (b'CMT_RUNTIME_PROFILING=1\0' if enabled else b'production\0'))
            result = subprocess.run(['cmake', '-DPLUGIN_DIR=' + str(directory), '-P', str(GUARD)],
                                    text=True, capture_output=True)
            self.assertEqual(result.returncode == 0, not enabled, result.stdout + result.stderr)
            if enabled:
                self.assertIn('Packaging rejected instrumented module', result.stderr)

    def test_disabled_modules_pass_and_enabled_modules_fail(self):
        for suffix in ('.xdl64', '.xlib', '.dylib'):
            for enabled in (False, True):
                with self.subTest(suffix=suffix, enabled=enabled):
                    self.check_module(suffix, enabled)

    def test_missing_module_is_not_accepted(self):
        with tempfile.TemporaryDirectory() as temporary:
            result = subprocess.run(['cmake', '-DPLUGIN_DIR=' + temporary, '-P', str(GUARD)],
                                    text=True, capture_output=True)
            self.assertNotEqual(result.returncode, 0)
            self.assertIn('No plugin modules found', result.stderr)


if __name__ == '__main__':
    unittest.main()
