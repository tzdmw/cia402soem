# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /tmp/debug

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/debug/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CustomEcatAL.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CustomEcatAL.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CustomEcatAL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CustomEcatAL.dir/flags.make

CMakeFiles/CustomEcatAL.dir/customecatal.cpp.o: CMakeFiles/CustomEcatAL.dir/flags.make
CMakeFiles/CustomEcatAL.dir/customecatal.cpp.o: ../customecatal.cpp
CMakeFiles/CustomEcatAL.dir/customecatal.cpp.o: CMakeFiles/CustomEcatAL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/debug/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CustomEcatAL.dir/customecatal.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CustomEcatAL.dir/customecatal.cpp.o -MF CMakeFiles/CustomEcatAL.dir/customecatal.cpp.o.d -o CMakeFiles/CustomEcatAL.dir/customecatal.cpp.o -c /tmp/debug/customecatal.cpp

CMakeFiles/CustomEcatAL.dir/customecatal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CustomEcatAL.dir/customecatal.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/debug/customecatal.cpp > CMakeFiles/CustomEcatAL.dir/customecatal.cpp.i

CMakeFiles/CustomEcatAL.dir/customecatal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CustomEcatAL.dir/customecatal.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/debug/customecatal.cpp -o CMakeFiles/CustomEcatAL.dir/customecatal.cpp.s

CMakeFiles/CustomEcatAL.dir/test.cpp.o: CMakeFiles/CustomEcatAL.dir/flags.make
CMakeFiles/CustomEcatAL.dir/test.cpp.o: ../test.cpp
CMakeFiles/CustomEcatAL.dir/test.cpp.o: CMakeFiles/CustomEcatAL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/debug/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CustomEcatAL.dir/test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CustomEcatAL.dir/test.cpp.o -MF CMakeFiles/CustomEcatAL.dir/test.cpp.o.d -o CMakeFiles/CustomEcatAL.dir/test.cpp.o -c /tmp/debug/test.cpp

CMakeFiles/CustomEcatAL.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CustomEcatAL.dir/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/debug/test.cpp > CMakeFiles/CustomEcatAL.dir/test.cpp.i

CMakeFiles/CustomEcatAL.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CustomEcatAL.dir/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/debug/test.cpp -o CMakeFiles/CustomEcatAL.dir/test.cpp.s

# Object files for target CustomEcatAL
CustomEcatAL_OBJECTS = \
"CMakeFiles/CustomEcatAL.dir/customecatal.cpp.o" \
"CMakeFiles/CustomEcatAL.dir/test.cpp.o"

# External object files for target CustomEcatAL
CustomEcatAL_EXTERNAL_OBJECTS =

CustomEcatAL: CMakeFiles/CustomEcatAL.dir/customecatal.cpp.o
CustomEcatAL: CMakeFiles/CustomEcatAL.dir/test.cpp.o
CustomEcatAL: CMakeFiles/CustomEcatAL.dir/build.make
CustomEcatAL: CMakeFiles/CustomEcatAL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/debug/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable CustomEcatAL"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CustomEcatAL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CustomEcatAL.dir/build: CustomEcatAL
.PHONY : CMakeFiles/CustomEcatAL.dir/build

CMakeFiles/CustomEcatAL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CustomEcatAL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CustomEcatAL.dir/clean

CMakeFiles/CustomEcatAL.dir/depend:
	cd /tmp/debug/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/debug /tmp/debug /tmp/debug/cmake-build-debug /tmp/debug/cmake-build-debug /tmp/debug/cmake-build-debug/CMakeFiles/CustomEcatAL.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CustomEcatAL.dir/depend
