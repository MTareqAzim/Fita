workspace "Fita"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Fita"
	location "Fita"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "fipch.h"
	pchsource "Fita/src/fipch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FI_PLATFORM_WINDOWS",
			"FI_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "FI_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FI_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FI_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
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
		"Fita/vendor/spdlog/include",
		"Fita/src"
	}

	links
	{
		"Fita"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FI_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "FI_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FI_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FI_DIST"
		optimize "On"