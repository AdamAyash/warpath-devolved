project "WCCEngine"
    kind "SharedLib"
    language "C++"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "wccpch.h"
    pchsource "src/wccpch.cpp"

    externalwarnings "Off"

    buildoptions
    {
        "/utf-8"
    }

    files
    {
        "src/**.h",
        "src/**.cpp"
    }

    defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

    includedirs
    {
        "vendor/spdlog/include",
        "vendor/stb_image",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.GLM}",
        "%{IncludeDir.ImGUI}",
        "vendor/GLM/glm/**.hpp",
		"vendor/GLM/glm/**.inl",
    }

    links
    {
        "GLFW",
        "Glad",
        "opengl32.lib",
        "ImGUI"
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
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"),
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/UnitTests")
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