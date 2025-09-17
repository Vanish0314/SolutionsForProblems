#!/usr/bin/env bash
set -euo pipefail

SRC_FILE="$1"
BASENAME_NO_EXT="$(basename "${SRC_FILE}" .cs)"
WORK_DIR="$(cd "$(dirname "$0")/.." && pwd)"
OUT_ROOT="${WORK_DIR}/.vscode/tmp_cs/${BASENAME_NO_EXT}"

mkdir -p "${OUT_ROOT}"

if [ ! -f "${OUT_ROOT}/${BASENAME_NO_EXT}.csproj" ]; then
  dotnet new console -n "${BASENAME_NO_EXT}" -o "${OUT_ROOT}" --force --framework net8.0 --language "C#" >/dev/null
fi

# Replace Program.cs with the active file
mkdir -p "${OUT_ROOT}/Properties"
cp "${SRC_FILE}" "${OUT_ROOT}/Program.cs"

dotnet build "${OUT_ROOT}" -c Debug

echo "Built C# -> ${OUT_ROOT}/bin/Debug/net8.0/${BASENAME_NO_EXT}.dll"


