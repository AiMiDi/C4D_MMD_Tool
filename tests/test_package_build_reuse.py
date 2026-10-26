"""Local packaging provenance regressions; CI performs validation, not this suite."""
import copy
import importlib.util
from pathlib import Path
import unittest

spec = importlib.util.spec_from_file_location('package_reuse',
    Path(__file__).resolve().parents[1] / 'scripts/resolve_package_build.py')
reuse = importlib.util.module_from_spec(spec)
spec.loader.exec_module(reuse)


class PackageReuseTests(unittest.TestCase):
    def setUp(self):
        self.repository = 'example/plugin'
        self.source = 'a' * 40
        self.target = 'b' * 40
        self.run = {'id': 123, 'head_sha': self.source, 'status': 'completed', 'conclusion': 'success',
                    'event': 'workflow_dispatch', 'path': '.github/workflows/build.yml',
                    'repository': {'id': 42, 'full_name': self.repository}, 'head_repository': {'id': 42}}
        self.jobs = [{'name': name, 'status': 'completed', 'conclusion': 'success'}
                     for name in sorted(reuse.EXPECTED_JOBS)]
        self.jobs.append({'name': 'checks', 'status': 'completed', 'conclusion': 'success'})
        self.artifacts = [{'id': i + 1, 'name': name, 'expired': False, 'size_in_bytes': 100,
                           'digest': 'sha256:' + 'c' * 64,
                           'workflow_run': {'id': 123, 'head_sha': self.source,
                                            'repository_id': 42, 'head_repository_id': 42}}
                          for i, name in enumerate(sorted(reuse.EXPECTED_ARTIFACTS))]
        self.packages = []

    def use_package_run(self, conclusion='failure'):
        self.run.update(path='.github/workflows/package.yml', event='push', conclusion=conclusion)
        for job in self.jobs:
            job['name'] = 'Build (reusable) / ' + job['name']
        self.jobs.append({'name': 'package-macos', 'status': 'completed', 'conclusion': conclusion})
        self.packages = [self.run]

    def validate(self, differences=()):
        return reuse.validate_candidate(self.repository, self.target, self.run,
                                         self.jobs, self.artifacts, differences)

    def api(self, repository, endpoint):
        self.assertEqual(repository, self.repository)
        if endpoint.endswith('/jobs?filter=latest&per_page=100'):
            return {'jobs': self.jobs}
        if endpoint.endswith('/artifacts?per_page=100'):
            return {'artifacts': self.artifacts}
        if endpoint.startswith('actions/workflows/build.yml/'):
            return {'workflow_runs': [] if self.packages else [self.run]}
        if endpoint.startswith('actions/workflows/package.yml/'):
            return {'workflow_runs': self.packages}
        if endpoint == 'actions/runs/123':
            return self.run
        raise AssertionError(endpoint)

    def test_complete_same_source_or_packaging_only_run_is_reused(self):
        for differences in [[], ['README.md', '.github/workflows/package.yml'],
                            ['cmake/prepare_installer_resources.ps1',
                             'scripts/check_installer_resources.ps1'],
                            ['docs/dev/example.md', 'docs/validation/probe.py',
                             'res/R20-S24/cmt_version.txt', 'res/S24_up/cmt_version.txt']]:
            result = self.validate(differences)
            self.assertTrue(result['reused'])
            self.assertEqual(result['verified_matrix_jobs'], 24)
            self.assertEqual(len(result['artifacts']), 18)

    def test_runtime_resource_dependency_and_build_changes_are_rejected(self):
        for path in ['source/main.cpp', 'res/S24_up/cmt_config.json', 'dependency/libMMD',
                     'cmake/mmdtool_plugin_common.cmake', 'sdk_r20/frameworks/a.h',
                     '.github/workflows/build.yml', 'setup', 'res/S24_up/c4d_symbols.h',
                     'docs.cpp', 'scripts/build.py']:
            with self.subTest(path=path), self.assertRaises(reuse.IncompatibleBuild):
                self.validate([path])

    def test_partial_failed_and_wrong_matrix_are_rejected(self):
        original = copy.deepcopy(self.jobs)
        for mutation in ['missing', 'failed', 'skipped', 'wrong', 'duplicate']:
            self.jobs = copy.deepcopy(original)
            if mutation == 'missing': self.jobs.pop(0)
            elif mutation == 'wrong': self.jobs[0]['name'] = 'matrix-build (other, sdk_r20)'
            elif mutation == 'duplicate': self.jobs.append(self.jobs[0])
            else: self.jobs[0]['conclusion'] = mutation
            with self.subTest(mutation=mutation), self.assertRaises(reuse.IncompatibleBuild):
                self.validate()

    def test_missing_expired_empty_duplicate_and_stale_artifacts_are_rejected(self):
        original = copy.deepcopy(self.artifacts)
        for mutation in ['missing', 'expired', 'empty', 'duplicate', 'sha', 'run', 'fork', 'digest']:
            self.artifacts = copy.deepcopy(original)
            artifact = self.artifacts[0]
            if mutation == 'missing': self.artifacts.pop()
            elif mutation == 'expired': artifact['expired'] = True
            elif mutation == 'empty': artifact['size_in_bytes'] = 0
            elif mutation == 'duplicate': self.artifacts.append(copy.deepcopy(artifact))
            elif mutation == 'sha': artifact['workflow_run']['head_sha'] = 'd' * 40
            elif mutation == 'run': artifact['workflow_run']['id'] = 999
            elif mutation == 'fork': artifact['workflow_run']['head_repository_id'] = 99
            else: artifact.pop('digest')
            with self.subTest(mutation=mutation), self.assertRaises(reuse.IncompatibleBuild):
                self.validate()

    def test_wrong_workflow_or_repository_and_incomplete_run_are_rejected(self):
        original = copy.deepcopy(self.run)
        for mutation in ['workflow', 'event', 'repository', 'fork', 'running', 'failure']:
            self.run = copy.deepcopy(original)
            if mutation == 'workflow': self.run['path'] = '.github/workflows/package.yml'
            elif mutation == 'event': self.run['event'] = 'pull_request'
            elif mutation == 'repository': self.run['repository']['full_name'] = 'other/repo'
            elif mutation == 'fork': self.run['head_repository']['id'] = 99
            elif mutation == 'running': self.run['status'] = 'in_progress'
            else: self.run['conclusion'] = 'failure'
            with self.subTest(mutation=mutation), self.assertRaises(reuse.IncompatibleBuild):
                self.validate()

    def test_automatic_mode_falls_back_but_explicit_bad_run_fails(self):
        self.artifacts.pop()
        automatic = reuse.resolve(self.repository, self.target, 456, api=self.api, diff=lambda *_: [])
        self.assertFalse(automatic['reused'])
        self.assertEqual(automatic['artifact_run_id'], 456)
        with self.assertRaises(reuse.IncompatibleBuild):
            reuse.resolve(self.repository, self.target, 456, '123', api=self.api, diff=lambda *_: [])

    def test_automatic_and_explicit_good_run_use_original_artifact_run(self):
        for requested in ['', '123']:
            result = reuse.resolve(self.repository, self.target, 456, requested,
                                   api=self.api, diff=lambda *_: ['CHANGELOG.md'])
            self.assertEqual(result['artifact_run_id'], 123)
            self.assertEqual(result['artifact_source_commit'], self.source)

    def test_failed_package_with_successful_matrix_is_reused(self):
        self.use_package_run()
        for requested in ['', '123']:
            result = reuse.resolve(self.repository, self.target, 456, requested,
                                   api=self.api, diff=lambda *_: ['docs/validation/result.md'])
            self.assertTrue(result['reused'])
            self.assertEqual(result['artifact_run_id'], 123)
            self.assertEqual(result['verified_matrix_jobs'], 24)

    def test_package_requires_its_own_complete_successful_matrix(self):
        self.use_package_run()
        original = copy.deepcopy(self.jobs)
        for mutation in ['failed', 'skipped', 'missing', 'prefix', 'checks']:
            self.jobs = copy.deepcopy(original)
            if mutation in ('failed', 'skipped'):
                self.jobs[0]['conclusion'] = mutation
            elif mutation == 'missing':
                self.jobs.pop(0)
            elif mutation == 'prefix':
                self.jobs[0]['name'] = self.jobs[0]['name'].removeprefix('Build (reusable) / ')
            else:
                next(job for job in self.jobs if job['name'].endswith(' / checks'))['conclusion'] = 'failure'
            with self.subTest(mutation=mutation), self.assertRaises(reuse.IncompatibleBuild):
                self.validate()

    def test_cancelled_running_or_pr_package_is_rejected(self):
        self.use_package_run()
        original = copy.deepcopy(self.run)
        for update in [{'conclusion': 'cancelled'}, {'status': 'in_progress'}, {'event': 'pull_request'}]:
            self.run = {**original, **update}
            with self.subTest(update=update), self.assertRaises(reuse.IncompatibleBuild):
                self.validate()


if __name__ == '__main__':
    unittest.main()
