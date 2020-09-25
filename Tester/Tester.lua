project "Tester"
	kind "ConsoleApp"
	language "C++"
	systemversion "latest" 
	targetdir ("../bin/" ..  outputdir .. "/%{prj.name}")
	objdir ("../bin-int/" ..  outputdir .. "/%{prj.name}")

	files
	{
		"**.h",
		"**.cpp",
		"Tester.lua"
	}

	includedirs {
		"../Logger/Headers"	
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



