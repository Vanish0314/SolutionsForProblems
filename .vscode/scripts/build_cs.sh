#!/usr/bin/env bash
set -euo pipefail

SRC_FILE="$1"
BASENAME_NO_EXT="$(basename "${SRC_FILE}" .cs)"
# project root is two levels up from this script: .vscode/scripts -> project
PROJECT_ROOT="$(cd "$(dirname "$0")/../.." && pwd)"
OUT_ROOT="${PROJECT_ROOT}/.vscode/tmp_cs/${BASENAME_NO_EXT}"
ABS_SRC="$(cd "$(dirname "${SRC_FILE}")" && pwd)/$(basename "${SRC_FILE}")"

mkdir -p "${OUT_ROOT}"

# Generate a minimal csproj that compiles the original file directly so PDBs map to your source path
rm -f "${OUT_ROOT}/Program.cs" || true

cat > "${OUT_ROOT}/${BASENAME_NO_EXT}.csproj" <<EOF
<Project Sdk="Microsoft.NET.Sdk">
  <PropertyGroup>
    <OutputType>Exe</OutputType>
    <TargetFramework>net8.0</TargetFramework>
    <ImplicitUsings>enable</ImplicitUsings>
    <Nullable>enable</Nullable>
    <Optimize>false</Optimize>
    <DebugType>portable</DebugType>
    <EnableDefaultItems>false</EnableDefaultItems>
  </PropertyGroup>
  <ItemGroup>
    <Compile Include="${ABS_SRC}" Link="Program.cs" />
    <Compile Include="Compat.Internal.cs" />
  </ItemGroup>
</Project>
EOF

# Provide a shim for `using Internal;` if present in the source
cat > "${OUT_ROOT}/Compat.Internal.cs" <<'EOF'
namespace Internal { }
EOF

dotnet build "${OUT_ROOT}" -c Debug

echo "Built C# -> ${OUT_ROOT}/bin/Debug/net8.0/${BASENAME_NO_EXT}.dll"


