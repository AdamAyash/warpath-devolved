project "UnitTests"
    kind "SharedLib"
    language "C++"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "pch.h"
    pchsource "src/pch.cpp"

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