add_rules("mode.debug", "mode.release")

set_toolchains("clang")

for _, file in ipairs(os.files("Solves/**.cpp")) do
    local rel = path.relative(file, "Solves")
    local name = rel:gsub("%.cpp$", ""):gsub("[/\\]+", "_")
    target(name)
        set_kind("binary")
        add_files(file)
end