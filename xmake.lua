add_rules("mode.debug", "mode.release")

set_toolchains("clang")

set_languages("c++23")

local files = table.join(os.files("LeetCode/**.cpp"), os.files("CodeForces/**.cpp"))
for _, file in ipairs(files) do
    -- use base filename (without extension) as target name to keep a stable and simple mapping
    -- so VS Code can build/debug the currently opened file via ${fileBasenameNoExtension}
    local name = path.filename(file):gsub("%.cpp$", "")
	target(name)
		set_kind("binary")
		add_files(file)
end
