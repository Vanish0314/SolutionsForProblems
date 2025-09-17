#!/usr/bin/env bash
set -euo pipefail

SRC_FILE="$1"
BASENAME_NO_EXT="$(basename "${SRC_FILE}" .fs)"
WORK_DIR="$(cd "$(dirname "$0")/.." && pwd)"
OUT_ROOT="${WORK_DIR}/.vscode/tmp_fs/${BASENAME_NO_EXT}"

mkdir -p "${OUT_ROOT}"

if [ ! -f "${OUT_ROOT}/${BASENAME_NO_EXT}.fsproj" ]; then
  dotnet new console -n "${BASENAME_NO_EXT}" -o "${OUT_ROOT}" --force --framework net8.0 --language "F#" >/dev/null
fi

# Replace Program.fs with the active file
cp "${SRC_FILE}" "${OUT_ROOT}/Program.fs"

dotnet build "${OUT_ROOT}" -c Debug

echo "Built F# -> ${OUT_ROOT}/bin/Debug/net8.0/${BASENAME_NO_EXT}.dll"


