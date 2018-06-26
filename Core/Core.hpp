#ifndef __Core_hpp_2018_06_25_16_45
#define __Core_hpp_2018_06_25_16_45
#ifndef OS_DETECTED
#define OS_DETECTED
#if defined(__WIN32)||defined(__WIN64)
#define OS_WINDOWS
#elif defined(__SNESOS_LIB)
#define OS_SNESOS
#elif defined(__PLACEHOLDERMACRO_MACOS)
#define OS_MACOS
#else
#define OS_LINUX 
#endif
#endif

#ifdef OS_WINDOWS
#define LCPM_IMPORT __declspec(dllimport)
#define LCPM_EXPORT __declspec(dllexport)
#define LCPM_INTERNAL 
#define LCPM_GUI <Windows/GUIWindows.hpp>
#define LCPM_ELEVATION <Windows/Elevation.hpp>
#elif defined(OS_SNESOS)
#define LCPM_IMPORT [[visibility(private),snesos::dynamic,snesos::import_symbol]]
#define LCPM_EXPORT [[snesos::dynamic,snesos::pic,visibility(public)]]
#define LCPM_INTERNAL [[visibility(private)]]
#define LCPM_GUI <SNESOS/GUISNESOS.hpp>
#define LCPM_ELEVATION <SNESOS/Elevation.hpp>
#elif defined(OS_LINUX)
#define LCPM_IMPORT __attribute((visibility(hidden)))
#define LCPM_EXPORT __attribute((visibility(public)))
#define LCPM_INTERNAL __attribute((visibility(hidden)))
#define LCPM_GUI <linux/GUILinux.hpp>
#define LCPM_ELEVATION <linux/Elevation.hpp>
#elif defined(OS_MACOS)
#define LCPM_IMPORT
#define LCPM_EXPORT
#define LCPM_INTERNAL
#endif
#define LCPM_LIBRARY LCPM_EXPORT
#endif