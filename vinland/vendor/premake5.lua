project "FLECS"
    location "flecs"
    kind "StaticLib"
    language "C"
    cdialect "C99"
    targetdir ("%{wks.location}/bin/" .. outDir)
    objdir ("%{wks.location}/obj/" .. outDir)

    includedirs {"%{prj.location}/include"}
    files {"%{prj.location}/src/**.c"}
    buildoptions {"-std=c99"}

project "Raylib"
		kind "StaticLib"
		links {"pthread", "GL", "m", "dl", "rt", "X11"}
			
		defines{"_GNU_SOURCE","PLATFORM_DESKTOP", "GRAPHICS_API_OPENGL_33"}
	
		language "C"
        cdialect "C99"
		targetdir "bin/%{cfg.buildcfg}"
		
		includedirs { "raylib/src", "raylib/src/external/glfw/include"}
		vpaths 
		{
			["Header Files"] = { "raylib/src/**.h"},
			["Source Files/*"] = {"raylib/src/**.c"},
		}
		files {"raylib/src/*.h", "raylib/src/*.c"}
