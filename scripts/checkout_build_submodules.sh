#!/usr/bin/env bash
# Keep every dependency at the superproject's pinned commit. The Eigen mirror
# avoids GitLab overload failures; this URL override is limited to this command.
set -euo pipefail

git submodule sync -- dependency/bullet3 dependency/libMMD
for attempt in 1 2 3; do
  if git -c url.https://github.com/eigen-mirror/eigen.git.insteadOf=https://gitlab.com/libeigen/eigen.git \
    submodule update --init --recursive dependency/bullet3 dependency/libMMD; then
    exit 0
  fi
  if [[ "$attempt" -eq 3 ]]; then
    echo "Pinned build dependency checkout failed after three attempts." >&2
    exit 1
  fi
  delay=$((attempt * 5))
  echo "Dependency checkout attempt $attempt failed; retrying in ${delay}s." >&2
  sleep "$delay"
done
