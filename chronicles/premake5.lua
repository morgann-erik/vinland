project "VinlandChronicles"
    kind "ConsoleApp"
    language "C"
    cdialect "C99"
    targetdir ("%{wks.location}/bin/" .. outDir)
    objdir ("%{wks.location}/obj/" .. outDir)

    links {"VinlandCore", "FLECS", "Raylib", "pthread", "GL", "m", "dl", "rt", "X11"}
    includedirs {
    "%{prj.location}/include", 
    "%{wks.location}/vinland/include",
    "%{wks.location}/vinland/vendor/flecs/include",
    "%{wks.location}/vinland/vendor/raylib/src",
    "%{wks.location}/vinland/vendor/raylib/src/external",
    "%{wks.location}/vinland/vendor/raylib/src/external/glfw/include"
    }
    files {"%{prj.location}/src/**.c"}
    buildoptions {"-std=c99"}
