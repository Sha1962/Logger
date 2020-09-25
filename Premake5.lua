workspace "Logger"

	configurations
	{
		"Debug",
		"Release"
	}
	
	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


project "Logger"
	location "Logger"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir ..  "/%{prj.name}")

	files
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp",
		"Logger.bat",
		"Premake5.lua"
	}

	includedirs {
		"Logger/Headers",		
		"Logger/Src",
		"Logger/"
	
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

		
	
project "Tester"
	location "Tester"
	kind "ConsoleApp"
	language "C++"
	systemversion "latest" 
	targetdir ("bin/" ..  outputdir .. "/%{prj.name}")
	objdir ("bin-int/" ..  outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp"
	}

	includedirs {
		"Logger/Headers",		
		"Logger/Src",
		"Logger/"	
    	}
	
	links
	{
		"Logger"
	}

	filter "system:windows"
		cppdialect "C++latest"
		staticruntime "on"
		systemversion "latest"
		architecture "x86_64"


	filter "configurations:Debug"
		defines "CH_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "CH_RELEASE"
		optimize "on"


workspace "Logger"
	startproject "Tester" 
