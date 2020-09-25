workspace "LoggerProject"

	configurations
	{
		"Debug",
		"Release"
	}
	
	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Logger/Logger.lua"
include "Tester/Tester.lua"

workspace "LoggerProject"
	startproject "Tester" 
