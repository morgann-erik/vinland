project "VinlandChronicles"
    kind "ConsoleApp"
    language "C"
    cdialect "C99"
    targetdir ("%{wks.location}/bin/" .. outDir)
    objdir ("%{wks.location}/obj/" .. outDir)

    links {"VinlandCore"}

    includedirs {
    "%{prj.location}/include", 
    "%{wks.location}/vinland/include"
    }
    files {"%{prj.location}/src/**.c"}
    buildoptions {"-std=c99"}
