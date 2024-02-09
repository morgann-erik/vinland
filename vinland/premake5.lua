project "VinlandCore"
    kind "ConsoleApp"
    language "C"
    cdialect "C99"
    targetdir ("%{wks.location}/bin/" .. outDir)
    objdir ("%{wks.location}/obj/" .. outDir)

    links {}

    includedirs {"%{prj.location}/include/vinland"}
    files {"%{prj.location}/src/**.c"}
    
    buildoptions {"-std=c99", "-Wall", "-Wextra", "-pedantic"}

include "vendor"
