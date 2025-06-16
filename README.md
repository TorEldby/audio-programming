# Project template
This is a very simple project template for C++ development using vcpkg as a package manager.

## Using vcpkg
There are two ways of using vcpkg for C++ projects. Either through "Classic mode", or "Manifest mode".
Remember to configure the CMake toolchain to point correctly towards your installation of vcpkg.

### Manifest mode
For manifest mode, simply populate "vcpkg.json" with the desired libraries and versions for your project, and configure the correct triplet for your toolchain.
When you're finished configuring the manifest, simply call `vcpkg install` in the project folder (Make sure vcpkg is configured in your environment variables). The libraries will be installed into a local folder, which is already .gitignored

### Classic mode
For classic mode, remove vcpkg.json, and use vcpkg as normal, through setting the CMake toolchain.

### Non MSVC
Vcpkg assumes primarily that you use the MSVC compiler package (Such as what you get from installing Visual Studio), but if you want to use another, such as mingw, then you need to set a couple variables. This is also applicable if you want to manage whether vcpkg fetches dynamic or static libraries. My system as of writing this is a 64-bit Windows system, using manually installed and configured mingw from winlib.
`setx VCPKG_DEFAULT_TRIPLET x64-mingw-dynamic`
`setx VCPKG_DEFAULT_HOST_TRIPLET x64-mingw-dynamic`
For linux, use
`export VCPKG_DEFAULT_TRIPLET=x64-mingw-dynamic`
`export VCPKG_DEFAULT_HOST_TRIPLET=x64-mingw-dynamic`

More information about triplets can be found [here](https://learn.microsoft.com/en-us/vcpkg/concepts/triplets), along with some info on [triplet variables](https://learn.microsoft.com/en-us/vcpkg/users/triplets)