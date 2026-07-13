#!/usr/bin/env bash
set -euo pipefail

usage() {
  cat <<'USAGE'
Usage:
  scripts/build_macos.sh
  scripts/build_macos.sh --sdk sdk_2025
  scripts/build_macos.sh --all

Environment overrides:
  CMT_CMAKE=/path/to/cmake          CMake executable, default: cmake
  CMT_NINJA=/path/to/ninja          Ninja executable when using a Ninja generator
  CMT_GENERATOR="Ninja Multi-Config"  CMake generator, default: Ninja Multi-Config
  CMT_BUILD_CONFIG=Debug            Debug, Release, RelWithDebInfo, or MinSizeRel
  CMT_SDK_DIR=sdk_2026              SDK tree to build
  CMT_ALL_SDKS=1                    Build all supported SDK trees
  CMT_BUILD_DIR=_build_macos_ninja  Root build directory
  CMT_ARCHS=arm64                   macOS architectures; use "arm64;x86_64" or "universal".
                                    Defaults to x86_64 for sdk_r20/r21/r23, else host arch.
  CMT_CC=/path/to/clang             C compiler, default: Xcode toolchain clang
  CMT_CXX=/path/to/clang++          C++ compiler, default: Xcode toolchain clang++
  CMT_SDKROOT=/path/to/MacOSX.sdk   macOS SDK root, default: Xcode MacOSX.sdk
  CMT_LIBMMD_SOURCE_DIR=/path       Optional libMMD source override
  CMT_LIBMMD_SNAPSHOT_REF=ref       Ref to archive when dependency/libMMD is missing

The SDK wrapper is staged under CMT_BUILD_DIR/_sdk_src/<sdk> before configure.
Generated source/res links and sourceprocessor output are kept out of the
tracked sdk_* directories.
USAGE
}

die() {
  printf 'error: %s\n' "$*" >&2
  exit 1
}

find_executable() {
  local candidate=$1
  if command -v "$candidate" >/dev/null 2>&1; then
    command -v "$candidate"
    return 0
  fi
  return 1
}

abs_path() {
  local path=$1
  case "$path" in
    /*) printf '%s\n' "$path" ;;
    *) printf '%s\n' "$REPO_ROOT/$path" ;;
  esac
}

libmmd_source_has_layout() {
  local path=$1
  [[ -f "$path/CMakeLists.txt" && -f "$path/src/libMMD/Model/MMD/PMXFile.h" ]]
}

libmmd_ref_has_layout() {
  local ref=$1
  git -C "$REPO_ROOT/dependency/libMMD" cat-file -e "$ref:CMakeLists.txt" >/dev/null 2>&1 &&
    git -C "$REPO_ROOT/dependency/libMMD" cat-file -e "$ref:src/libMMD/Model/MMD/PMXFile.h" >/dev/null 2>&1
}

normalize_archs() {
  local archs=$1
  if [[ "$archs" == "universal" ]]; then
    printf 'arm64;x86_64\n'
  else
    printf '%s\n' "$archs"
  fi
}

default_archs_for_sdk() {
  local sdk_name=$1
  case "$sdk_name" in
    sdk_r20|sdk_r21|sdk_r23) printf 'x86_64\n' ;;
    *) uname -m ;;
  esac
}

is_truthy() {
  case "${1:-}" in
    1|ON|on|TRUE|true|YES|yes) return 0 ;;
    *) return 1 ;;
  esac
}

prepare_sdk_source() {
  local sdk_dir=$1
  local sdk_name=$2
  local staging_root="$BUILD_ROOT/_sdk_src"
  local staged_sdk_dir="$staging_root/$sdk_name"

  mkdir -p "$staging_root"
  rm -rf "$staging_root/cmake"
  ln -s "$REPO_ROOT/cmake" "$staging_root/cmake"
  rsync -a --delete \
    --exclude '/plugins/mmdtool/source' \
    --exclude '/plugins/mmdtool/res' \
    "$sdk_dir/" "$staged_sdk_dir/"
  rm -rf "$staged_sdk_dir/plugins/mmdtool/source" "$staged_sdk_dir/plugins/mmdtool/res"
  printf '%s\n' "$staged_sdk_dir"
}

reset_sdk_build_dir_if_needed() {
  local build_dir=$1
  local source_dir=$2
  local cache_file="$build_dir/CMakeCache.txt"
  local cached_source=""

  if [[ -f "$cache_file" ]]; then
    cached_source=$(awk -F= '/^CMAKE_HOME_DIRECTORY:INTERNAL=/ { print $2; exit }' "$cache_file")
    if [[ -n "$cached_source" && "$cached_source" != "$source_dir" ]]; then
      printf '==> Resetting SDK build dir because source moved: %s\n' "$build_dir"
      rm -rf "$build_dir"
    fi
  fi
}

SCRIPT_DIR=$(CDPATH= cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)
REPO_ROOT=$(CDPATH= cd -- "$SCRIPT_DIR/.." && pwd)

ALL_SDK_TREES=(sdk_r20 sdk_r21 sdk_r23 sdk_r25 sdk_2023 sdk_2024 sdk_2025 sdk_2026)
BUILD_ALL=${CMT_ALL_SDKS:-0}

while [[ $# -gt 0 ]]; do
  case "$1" in
    -h|--help)
      usage
      exit 0
      ;;
    --all)
      BUILD_ALL=1
      shift
      ;;
    --sdk)
      [[ $# -ge 2 ]] || die "--sdk requires an SDK directory"
      CMT_SDK_DIR=$2
      shift 2
      ;;
    --sdk=*)
      CMT_SDK_DIR=${1#--sdk=}
      shift
      ;;
    *)
      die "unknown argument: $1"
      ;;
  esac
done

CMAKE_BIN=${CMT_CMAKE:-cmake}
CMAKE_BIN=$(find_executable "$CMAKE_BIN") || die "cmake not found. Install CMake or set CMT_CMAKE=/path/to/cmake."

GENERATOR=${CMT_GENERATOR:-Ninja Multi-Config}
BUILD_CONFIG=${CMT_BUILD_CONFIG:-Debug}
SDK_DIR=$(abs_path "${CMT_SDK_DIR:-sdk_2026}")
BUILD_ROOT=$(abs_path "${CMT_BUILD_DIR:-_build_macos_ninja}")

DEVELOPER_DIR=${DEVELOPER_DIR:-/Applications/Xcode.app/Contents/Developer}
TOOLCHAIN_BIN="$DEVELOPER_DIR/Toolchains/XcodeDefault.xctoolchain/usr/bin"
CC_BIN=${CMT_CC:-$TOOLCHAIN_BIN/clang}
CXX_BIN=${CMT_CXX:-$TOOLCHAIN_BIN/clang++}
SDKROOT=${CMT_SDKROOT:-$DEVELOPER_DIR/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk}

[[ -x "$CC_BIN" ]] || die "C compiler not executable: $CC_BIN"
[[ -x "$CXX_BIN" ]] || die "C++ compiler not executable: $CXX_BIN"
[[ -d "$SDKROOT" ]] || die "macOS SDK not found: $SDKROOT"

MAKE_PROGRAM_ARGS=()
if [[ "$GENERATOR" == Ninja* ]]; then
  NINJA_BIN=${CMT_NINJA:-ninja}
  NINJA_BIN=$(find_executable "$NINJA_BIN") || die "ninja not found for generator '$GENERATOR'. Install Ninja, set CMT_NINJA, or set CMT_GENERATOR=Xcode."
  MAKE_PROGRAM_ARGS=(-D "CMAKE_MAKE_PROGRAM:FILEPATH=$NINJA_BIN")
fi

LIBMMD_SOURCE=${CMT_LIBMMD_SOURCE_DIR:-$REPO_ROOT/dependency/libMMD}
if ! libmmd_source_has_layout "$LIBMMD_SOURCE"; then
  if [[ -n "${CMT_LIBMMD_SOURCE_DIR:-}" ]]; then
    die "CMT_LIBMMD_SOURCE_DIR does not contain the expected libMMD layout: $LIBMMD_SOURCE"
  fi

  LIBMMD_REF=""
  SUPERPROJECT_LIBMMD_REF=$(git -C "$REPO_ROOT" ls-tree HEAD dependency/libMMD | awk '{print $3}')
  LIBMMD_REF_CANDIDATES=()
  [[ -n "${CMT_LIBMMD_SNAPSHOT_REF:-}" ]] && LIBMMD_REF_CANDIDATES+=("$CMT_LIBMMD_SNAPSHOT_REF")
  [[ -n "$SUPERPROJECT_LIBMMD_REF" ]] && LIBMMD_REF_CANDIDATES+=("$SUPERPROJECT_LIBMMD_REF")
  LIBMMD_REF_CANDIDATES+=(origin/aimidi HEAD)

  for ref in "${LIBMMD_REF_CANDIDATES[@]}"; do
    if libmmd_ref_has_layout "$ref"; then
      LIBMMD_REF=$ref
      break
    fi
  done
  [[ -n "$LIBMMD_REF" ]] || die "dependency/libMMD is missing or incompatible and no usable libMMD ref was found. Run git submodule update --init dependency/libMMD, or set CMT_LIBMMD_SOURCE_DIR."

  SNAPSHOT_DIR="$BUILD_ROOT/_deps/libMMD-src"
  if libmmd_source_has_layout "$SNAPSHOT_DIR"; then
    printf 'dependency/libMMD is missing or incompatible; reusing build-only worktree: %s\n' "$SNAPSHOT_DIR"
  else
    printf 'dependency/libMMD is missing or incompatible; creating a build-only worktree from %s.\n' "$LIBMMD_REF"
    git -C "$REPO_ROOT/dependency/libMMD" worktree remove --force "$SNAPSHOT_DIR" >/dev/null 2>&1 || rm -rf "$SNAPSHOT_DIR"
    git -C "$REPO_ROOT/dependency/libMMD" worktree prune >/dev/null 2>&1 || true
    git -C "$REPO_ROOT/dependency/libMMD" worktree add --force --detach "$SNAPSHOT_DIR" "$LIBMMD_REF"
    git -C "$SNAPSHOT_DIR" submodule update --init --depth 1 external/eigen external/spdlog
  fi
  LIBMMD_SOURCE="$SNAPSHOT_DIR"
fi

build_sdk() {
  local sdk_dir=$1
  local root_build_dir=$2
  local sdk_build_dir=$3
  local sdk_name
  local archs
  local staged_sdk_dir

  [[ -d "$sdk_dir" ]] || die "SDK directory not found: $sdk_dir"
  sdk_name=$(basename "$sdk_dir")
  archs=$(normalize_archs "${CMT_ARCHS:-$(default_archs_for_sdk "$sdk_name")}")
  staged_sdk_dir=$(prepare_sdk_source "$sdk_dir" "$sdk_name")
  reset_sdk_build_dir_if_needed "$sdk_build_dir" "$staged_sdk_dir"

  local configure_args=(
    -S "$REPO_ROOT"
    -B "$root_build_dir"
    -G "$GENERATOR"
    "${MAKE_PROGRAM_ARGS[@]}"
    -D "CMAKE_C_COMPILER:FILEPATH=$CC_BIN"
    -D "CMAKE_CXX_COMPILER:FILEPATH=$CXX_BIN"
    -D "CMAKE_OSX_SYSROOT:PATH=$SDKROOT"
    -D "CMAKE_OSX_ARCHITECTURES:STRING=$archs"
    -D "CMT_PROJECT_ROOT_DIR:PATH=$REPO_ROOT"
    -D "CMT_SDK_DIR:PATH=$staged_sdk_dir"
    -D "CMT_SDK_BINARY_DIR:PATH=$sdk_build_dir"
    -D "CMT_SDK_GENERATOR:STRING=$GENERATOR"
    -D "CMT_SDK_SKIP_VS_A_AND_T:BOOL=ON"
    -D "CMT_SDK_BUILD_CONFIG:STRING=$BUILD_CONFIG"
    -D "CMT_SDK_BUILD_TARGET:STRING=mmdtool"
    -D "CMT_SDK_OSX_ARCHITECTURES:STRING=$archs"
    -D "CMT_LIBMMD_SOURCE_DIR:PATH=$LIBMMD_SOURCE"
  )

  printf '\n==> Configuring macOS build: %s %s %s\n' "$sdk_name" "$BUILD_CONFIG" "$archs"
  printf '==> Staged SDK source: %s\n' "$staged_sdk_dir"
  "$CMAKE_BIN" "${configure_args[@]}"

  printf '==> Building %s mmdtool through cmt-workflow...\n' "$sdk_name"
  "$CMAKE_BIN" --build "$root_build_dir" --config "$BUILD_CONFIG" --target cmt-workflow

  printf '==> Build finished: %s\n' "$sdk_build_dir/bin/$BUILD_CONFIG/plugins/mmdtool"
}

if is_truthy "$BUILD_ALL"; then
  for sdk in "${ALL_SDK_TREES[@]}"; do
    sdk_name=$(basename "$sdk")
    build_sdk "$(abs_path "$sdk")" "$BUILD_ROOT/_root_$sdk_name" "$BUILD_ROOT/$sdk_name"
  done
else
  sdk_name=$(basename "$SDK_DIR")
  build_sdk "$SDK_DIR" "$BUILD_ROOT" "$BUILD_ROOT/$sdk_name"
fi
