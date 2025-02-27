workspace "WarcraftClone"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Distribution"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Engine/vendor/GLFW/include"
IncludeDir["Glad"] = "Engine/vendor/Glad/include"

include "Engine/vendor/GLFW"
include "Engine/vendor/Glad"

project "Engine"
    location "Engine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "wccpch.h"
    pchsource "src/wccpch.cpp"

    buildoptions
    {
        "/utf-8"
    }

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}"
    }

    links
    {
        "GLFW",
        "Glad",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "c++20"
        staticruntime "On"
        systemversion "latest"

        defines 
        {
            "WCC_BUILD_DLL",
            "WCC_WINDOWS_PLATFORM"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "WCC_DEBUG"
        symbols "On"

    
    filter "configurations:Release"
        defines "WCC_RELEASE"
        optimize "On"

    
    filter "configurations:Distribution"
        defines "WCC_DISTRIBUTION"
        optimize "On"
    
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    buildoptions
    {
        "/utf-8"
    }

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{wks.location}/Engine/vendor/spdlog/include",
        "Engine/src"
    }

    links
    {
        "Engine"
    }

    filter "system:windows"
        cppdialect "c++20"
        staticruntime "On"
        systemversion "latest"

        defines 
        {
            "WCC_WINDOWS_PLATFORM"
        }

    filter "configurations:Debug"
        defines "WCC_DEBUG"
        symbols "On"

    
    filter "configurations:Release"
        defines "WCC_RELEASE"
        optimize "On"

    
    filter "configurations:Distribution"
        defines "WCC_DISTRIBUTION"
        optimize "On"
    
    