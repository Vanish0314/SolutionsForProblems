#!/usr/bin/env bash
set -euo pipefail

SRC_FILE="$1"
BASENAME_NO_EXT="$(basename "${SRC_FILE}" .fs)"
# project root is two levels up from this script: .vscode/scripts -> project
PROJECT_ROOT="$(cd "$(dirname "$0")/../.." && pwd)"
OUT_ROOT="${PROJECT_ROOT}/.vscode/tmp_fs/${BASENAME_NO_EXT}"
ABS_SRC="$(cd "$(dirname "${SRC_FILE}")" && pwd)/$(basename "${SRC_FILE}")"

mkdir -p "${OUT_ROOT}"

# Generate a minimal fsproj that compiles the original file directly so PDBs map to your source path
rm -f "${OUT_ROOT}/Program.fs" || true

cat > "${OUT_ROOT}/${BASENAME_NO_EXT}.fsproj" <<EOF
<Project Sdk="Microsoft.NET.Sdk">
  <PropertyGroup>
    <OutputType>Exe</OutputType>
    <TargetFramework>net8.0</TargetFramework>
    <Optimize>false</Optimize>
    <DebugType>portable</DebugType>
    <EnableDefaultItems>false</EnableDefaultItems>
  </PropertyGroup>
  <ItemGroup>
    <Compile Include="${ABS_SRC}" Link="Program.fs" />
  </ItemGroup>
</Project>
EOF

dotnet build "${OUT_ROOT}" -c Debug

echo "Built F# -> ${OUT_ROOT}/bin/Debug/net8.0/${BASENAME_NO_EXT}.dll"


