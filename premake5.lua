include "dependencies.lua"

workspace "WarpathDevolved"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Distribution"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
    include "WCCEngine/vendor/GLFW"
    include "WCCEngine/vendor/Glad"
    include "WCCEngine/vendor/ImGUI"
group ""

group "Core"
	include "WCCEngine"
group ""

group "Misc"
	include "Sandbox"
    include "UnitTests"
group ""
