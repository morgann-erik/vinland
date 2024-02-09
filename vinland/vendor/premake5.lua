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
