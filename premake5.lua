workspace "Vinland"
    architecture "x64"
    configurations {"Debug", "Release", "Dist"}

outDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}-%{prj.name}"

include "vinland"
include "chronicles"

filter "configurations:Debug"
    defines "V_DEBUG"
    runtime "Debug"
    symbols "On"

filter "configurations:Release"
    defines "V_RELEASE"
    runtime "Debug"
    optimize "On"

filter "configurations:Dist"
    defines "V_DIST"
    runtime "Release"
    symbols "On"

