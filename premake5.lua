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
IncludeDir["GLFW"] = "WCCEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "WCCEngine/vendor/Glad/include"
IncludeDir["GLM"] = "WCCEngine/vendor/GLM/glm"

include "WCCEngine/vendor/GLFW"
include "WCCEngine/vendor/Glad"

project "WCCEngine"
    location "WCCEngine"
    kind "SharedLib"
    language "C++"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "wccpch.h"
    pchsource "WCCEngine/src/wccpch.cpp"

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
        "%{prj.name}/vendor/stb_image",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.GLM}",
        "vendor/GLM/glm/**.hpp",
		"vendor/GLM/glm/**.inl",
    }

    links
    {
        "GLFW",
        "Glad",
        "opengl32.lib",
    }

    filter "system:windows"
        cppdialect "c++20"
        staticruntime "off"
        runtime "Debug"
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
        "%{wks.location}/WCCEngine/vendor/spdlog/include",
        "WCCEngine/src",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.GLM}",
        "vendor/GLM/glm/**.hpp",
		"vendor/GLM/glm/**.inl",
    }

    links
    {
        "WCCEngine"
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
    
project "UnitTests"
    location "UnitTests"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include",
        "WCCEngine/src"
    }

    links
    {
        "WCCEngine"
    }
