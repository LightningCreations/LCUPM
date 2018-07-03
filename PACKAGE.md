# Package Specification
## Required fields

Name (The unique identifier for your package. Example: `"g++"`)

Package location (The path online to find your package. Example: `"gcc.gnu.org/gcc-3.1.2r23-lcupm.tar.gz"`)

Build script (Used when building from source is required on the target platform. Example: `"gcc-3.1.2/build.sh"`)

Version string (The version that will be displayed to the user. Example: `"3.1.2r23"`)

Version number (The version used to sequentially identify versions of your program. Example: `324134`)

## Optional fields

Dependencies (These packages will be installed before yours, and their dependencies will be installed first too if they have any. Example: `["gcc", "man-g++"]`)

Post-install (A script to be run after installing your package. Recommended to be in Lua. Example: `"gcc-3.1.2/test.lua"`)

## Example of full package identification file
    {
        "name":"gcc",
        "location":"gcc.gnu.org/gcc-3.1.2r23-lcupm.tar.gz",
        "build":"gcc-3.1.2/build.sh",
        "version-str":"3.1.2r23",
        "version-num":324134,
        "depends":["gcc","man-g++"],
        "post-install":"gcc-3.1.2/test.lua"
    }
