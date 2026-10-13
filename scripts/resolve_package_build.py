"""Select a successful, source-compatible full Build run for packaging.

Only an explicit list of documentation/packaging files may differ. Runtime
source, SDKs, resources, dependency gitlinks and compiler configuration must
match. No artifact or plugin is installed or executed by this check.
"""
import argparse
import json
import os
import re
import subprocess
from pathlib import Path


SDKS = ('sdk_r20', 'sdk_r21', 'sdk_r23', 'sdk_r25',
        'sdk_2023', 'sdk_2024', 'sdk_2025', 'sdk_2026')
PACKAGING_ONLY = frozenset({
    '.github/workflows/package.yml',
    'scripts/resolve_package_build.py',
    'tests/test_package_build_reuse.py',
    'README.md', 'README_zh.md', 'CHANGELOG.md', 'CHANGELOG_zh.md',
    'DEVELOPMENT.md', 'DEVELOPMENT_zh.md',
})
EXPECTED_JOBS = {
    f'matrix-build ({platform}, {sdk})'
    for platform in ('windows-2022', 'macos-26-intel') for sdk in SDKS
} | {
    f'matrix-build (macos-26, {sdk}, release-macos, workflow-release-macos, Xcode, arm64, false)'
    for sdk in SDKS[3:]
}
EXPECTED_ARTIFACTS = {
    f'build-{platform}-{sdk}'
    for platform in ('Windows-x64', 'macOS-x86_64') for sdk in SDKS
}


class IncompatibleBuild(ValueError):
    """The candidate cannot prove all required build inputs and outputs."""


def require(condition, message):
    if not condition:
        raise IncompatibleBuild(message)


def gh_json(repository, endpoint):
    output = subprocess.check_output(['gh', 'api', f'repos/{repository}/{endpoint}'], text=True)
    return json.loads(output)


def changed_paths(source, target):
    # A completed run may belong to an older branch which checkout did not fetch.
    if subprocess.run(['git', 'cat-file', '-e', f'{source}^{{commit}}'],
                      stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL).returncode:
        subprocess.run(['git', 'fetch', '--no-tags', 'origin', source], check=True)
    output = subprocess.check_output(
        ['git', 'diff', '--name-only', '--no-renames', '-z', source, target])
    return [path.decode('utf-8') for path in output.split(b'\0') if path]


def validate_candidate(repository, target, run, jobs, artifacts, differences):
    source = run.get('head_sha', '')
    require(re.fullmatch(r'[0-9a-f]{40}', source), 'Invalid source commit')
    require(run.get('status') == 'completed' and run.get('conclusion') == 'success',
            'Build run has not completed successfully')
    require(run.get('event') == 'workflow_dispatch' and run.get('path') == '.github/workflows/build.yml',
            'Reuse requires the standalone full Build workflow')
    repository_id = run.get('repository', {}).get('id')
    require(isinstance(repository_id, int) and repository_id > 0 and
            run.get('repository', {}).get('full_name') == repository and
            run.get('head_repository', {}).get('id') == repository_id,
            'Build does not belong to the release repository')
    require(not (set(differences) - PACKAGING_ONLY),
            'Compiler/runtime inputs differ: ' + ', '.join(sorted(set(differences) - PACKAGING_ONLY)))

    matrix = [job for job in jobs if job.get('name', '').startswith('matrix-build (')]
    require(len(matrix) == 21 and {job['name'] for job in matrix} == EXPECTED_JOBS,
            'Build does not contain the complete 21 SDK/platform jobs')
    require(all(job.get('status') == 'completed' and job.get('conclusion') == 'success' for job in matrix),
            'An SDK/platform job was not successful')
    require(any(job.get('name') == 'checks' and job.get('status') == 'completed' and
                job.get('conclusion') == 'success' for job in jobs),
            'Build input checks were not successful')

    outputs = {}
    for artifact in artifacts:
        if artifact.get('name') not in EXPECTED_ARTIFACTS:
            continue
        require(artifact['name'] not in outputs, 'Duplicate SDK artifact')
        provenance = artifact.get('workflow_run', {})
        require(not artifact.get('expired', True) and artifact.get('size_in_bytes', 0) > 0,
                'SDK artifact is missing, empty or expired')
        require(provenance.get('id') == run['id'] and provenance.get('head_sha') == source,
                'SDK artifact source does not match its Build run')
        require(provenance.get('repository_id') == repository_id and
                provenance.get('head_repository_id') == repository_id,
                'Fork artifacts cannot be reused for a release')
        require(re.fullmatch(r'sha256:[0-9a-f]{64}', artifact.get('digest', '')),
                'SDK artifact digest is missing')
        outputs[artifact['name']] = {key: artifact[key] for key in
                                    ('id', 'name', 'digest', 'size_in_bytes')}
    require(set(outputs) == EXPECTED_ARTIFACTS, 'The 16 packaged SDK artifacts are incomplete')
    return {'reused': True, 'artifact_run_id': run['id'], 'artifact_source_commit': source,
            'target_commit': target, 'repository': repository,
            'packaging_only_differences': sorted(differences),
            'verified_matrix_jobs': 21, 'artifacts': list(outputs.values())}


def resolve(repository, target, current_run, requested_run='', api=gh_json, diff=changed_paths):
    require(re.fullmatch(r'[\w.-]+/[\w.-]+', repository), 'Invalid repository')
    require(re.fullmatch(r'[0-9a-f]{40}', target), 'Invalid package commit')
    if requested_run:
        require(requested_run.isdecimal() and int(requested_run) > 0, 'Invalid Build run ID')
        candidates = [api(repository, f'actions/runs/{requested_run}')]
    else:
        # PR/main checks compile one SDK; only dispatch runs contain the full matrix.
        candidates = api(repository, 'actions/workflows/build.yml/runs?event=workflow_dispatch&status=success&per_page=30')['workflow_runs']
    for run in candidates:
        try:
            source = run.get('head_sha', '')
            require(re.fullmatch(r'[0-9a-f]{40}', source), 'Invalid source commit')
            differences = diff(source, target)
            require(not (set(differences) - PACKAGING_ONLY), 'Runtime/build inputs changed')
            jobs = api(repository, f"actions/runs/{run['id']}/jobs?filter=latest&per_page=100")['jobs']
            artifacts = api(repository, f"actions/runs/{run['id']}/artifacts?per_page=100")['artifacts']
            return validate_candidate(repository, target, run, jobs, artifacts, differences)
        except IncompatibleBuild as error:
            if requested_run:
                raise
            print(f"Build {run.get('id')} is not reusable: {error}")
    return {'reused': False, 'artifact_run_id': current_run,
            'artifact_source_commit': target, 'target_commit': target,
            'repository': repository, 'reason': 'No successful source-compatible full Build run found'}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--repository', required=True)
    parser.add_argument('--target', required=True)
    parser.add_argument('--current-run', required=True, type=int)
    parser.add_argument('--build-run-id', default='')
    parser.add_argument('--output', required=True, type=Path)
    args = parser.parse_args()
    result = resolve(args.repository, args.target, args.current_run, args.build_run_id)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2) + '\n', encoding='utf-8')
    if os.environ.get('GITHUB_OUTPUT'):
        with open(os.environ['GITHUB_OUTPUT'], 'a', encoding='utf-8') as output:
            output.write(f"reused={str(result['reused']).lower()}\n")
            output.write(f"artifact_run_id={result['artifact_run_id']}\n")
            output.write(f"artifact_source_commit={result['artifact_source_commit']}\n")
    print(json.dumps({key: result[key] for key in
                      ('reused', 'artifact_run_id', 'artifact_source_commit', 'target_commit')}))


if __name__ == '__main__':
    main()
