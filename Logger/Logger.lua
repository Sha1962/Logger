project "Logger"
	kind "SharedLib"
	language "C++"

	targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
	objdir ("../bin-int/" .. outputdir ..  "/%{prj.name}")

	files
	{
		"**.h",
		"**.cpp",
		"Logger.lua"
	}

	includedirs {
		"Headers"
    }
	
	filter "system:windows"
		cppdialect "C++latest"
		staticruntime "on"
		systemversion "latest"
		architecture "x86_64"

		defines
		{
			"BUILD_DLL"
		}

		postbuildcommands
		{
			("{mkdir} ../bin/" .. outputdir .. "/Tester"),
			("{copy} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Tester")
		}

	filter "configurations:Debug"
		defines "CH_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "CH_RELEASE"
		optimize "on"

		
