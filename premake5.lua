workspace "Turing"
	architecture "x64"
	configurations{ "Debug","Release","Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Turing"
	location "Turing"
	kind	 "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir	  ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src",
		"%{prj.name}/src/Turing"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TR_PLATFORM_WINDOWS",
			"TR_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "CTURING_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CTURING_RELEASE"
		optimize "On"

	filter "configurations:Dis"
		defines "CTURING_DEBUG"
		optimize "On"

	-- 目前用不到多线程
	--filters { "system:windows","configurations:Release" }
		--buildoptions "/MT"

project "Sandbox"
	location "Sandbox"
	kind	 "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir	  ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Turing/vendor/spdlog/include",
		"Turing/src/Turing",
		"Turing/src"
	}

	links
	{
		"Turing"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TR_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CTURING_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CTURING_RELEASE"
		optimize "On"

	filter "configurations:Dis"
		defines "CTURING_DEBUG"
		optimize "On"