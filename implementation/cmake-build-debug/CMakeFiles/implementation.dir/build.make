# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Samuel\Documents\Coding\programming-competitions\implementation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Samuel\Documents\Coding\programming-competitions\implementation\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/implementation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/implementation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/implementation.dir/flags.make

CMakeFiles/implementation.dir/lca.cpp.obj: CMakeFiles/implementation.dir/flags.make
CMakeFiles/implementation.dir/lca.cpp.obj: ../lca.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Samuel\Documents\Coding\programming-competitions\implementation\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/implementation.dir/lca.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\implementation.dir\lca.cpp.obj -c C:\Users\Samuel\Documents\Coding\programming-competitions\implementation\lca.cpp

CMakeFiles/implementation.dir/lca.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/implementation.dir/lca.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Samuel\Documents\Coding\programming-competitions\implementation\lca.cpp > CMakeFiles\implementation.dir\lca.cpp.i

CMakeFiles/implementation.dir/lca.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/implementation.dir/lca.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Samuel\Documents\Coding\programming-competitions\implementation\lca.cpp -o CMakeFiles\implementation.dir\lca.cpp.s

# Object files for target implementation
implementation_OBJECTS = \
"CMakeFiles/implementation.dir/lca.cpp.obj"

# External object files for target implementation
implementation_EXTERNAL_OBJECTS =

implementation.exe: CMakeFiles/implementation.dir/lca.cpp.obj
implementation.exe: CMakeFiles/implementation.dir/build.make
implementation.exe: CMakeFiles/implementation.dir/linklibs.rsp
implementation.exe: CMakeFiles/implementation.dir/objects1.rsp
implementation.exe: CMakeFiles/implementation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Samuel\Documents\Coding\programming-competitions\implementation\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable implementation.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\implementation.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/implementation.dir/build: implementation.exe

.PHONY : CMakeFiles/implementation.dir/build

CMakeFiles/implementation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\implementation.dir\cmake_clean.cmake
.PHONY : CMakeFiles/implementation.dir/clean

CMakeFiles/implementation.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Samuel\Documents\Coding\programming-competitions\implementation C:\Users\Samuel\Documents\Coding\programming-competitions\implementation C:\Users\Samuel\Documents\Coding\programming-competitions\implementation\cmake-build-debug C:\Users\Samuel\Documents\Coding\programming-competitions\implementation\cmake-build-debug C:\Users\Samuel\Documents\Coding\programming-competitions\implementation\cmake-build-debug\CMakeFiles\implementation.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/implementation.dir/depend

