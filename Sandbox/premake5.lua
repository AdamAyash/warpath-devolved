project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")
    
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

    includedirs
    {
        "%{wks.location}/WCCEngine/vendor/spdlog/include",
        "%{wks.location}/WCCEngine/src",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.GLM}",
        "%{IncludeDir.ImGUI}",
        "vendor/GLM/glm/**.hpp",
		"vendor/GLM/glm/**.inl",
    }

    links
    {
        "WCCEngine",
    }

    filter "system:windows"
        cppdialect "c++20"
        staticruntime "On"
        systemversion "latest"

        defines 
        {
            "WCC_WINDOWS_PLATFORM",
        }

    filter "configurations:Debug"
        defines "WCC_DEBUG"
        symbols "On"
        runtime "Debug"

    
    filter "configurations:Release"
        defines "WCC_RELEASE"
        optimize "On"

    
    filter "configurations:Distribution"
        defines "WCC_DISTRIBUTION"
        optimize "On"