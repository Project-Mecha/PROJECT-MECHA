# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "C:/Users/Beyioku/Documents/Unreal Projects/Aptos-Cpp-SDK/build/_deps/toolbox-src")
  file(MAKE_DIRECTORY "C:/Users/Beyioku/Documents/Unreal Projects/Aptos-Cpp-SDK/build/_deps/toolbox-src")
endif()
file(MAKE_DIRECTORY
  "C:/Users/Beyioku/Documents/Unreal Projects/Aptos-Cpp-SDK/build/_deps/toolbox-build"
  "C:/Users/Beyioku/Documents/Unreal Projects/Aptos-Cpp-SDK/build/_deps/toolbox-subbuild/toolbox-populate-prefix"
  "C:/Users/Beyioku/Documents/Unreal Projects/Aptos-Cpp-SDK/build/_deps/toolbox-subbuild/toolbox-populate-prefix/tmp"
  "C:/Users/Beyioku/Documents/Unreal Projects/Aptos-Cpp-SDK/build/_deps/toolbox-subbuild/toolbox-populate-prefix/src/toolbox-populate-stamp"
  "C:/Users/Beyioku/Documents/Unreal Projects/Aptos-Cpp-SDK/build/_deps/toolbox-subbuild/toolbox-populate-prefix/src"
  "C:/Users/Beyioku/Documents/Unreal Projects/Aptos-Cpp-SDK/build/_deps/toolbox-subbuild/toolbox-populate-prefix/src/toolbox-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/Beyioku/Documents/Unreal Projects/Aptos-Cpp-SDK/build/_deps/toolbox-subbuild/toolbox-populate-prefix/src/toolbox-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/Beyioku/Documents/Unreal Projects/Aptos-Cpp-SDK/build/_deps/toolbox-subbuild/toolbox-populate-prefix/src/toolbox-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
