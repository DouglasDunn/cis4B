# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/douglasdunn/CLionProjects/cis4B/SequencePart2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/douglasdunn/CLionProjects/cis4B/SequencePart2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SequencePart2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SequencePart2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SequencePart2.dir/flags.make

CMakeFiles/SequencePart2.dir/main.cpp.o: CMakeFiles/SequencePart2.dir/flags.make
CMakeFiles/SequencePart2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/douglasdunn/CLionProjects/cis4B/SequencePart2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SequencePart2.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SequencePart2.dir/main.cpp.o -c /Users/douglasdunn/CLionProjects/cis4B/SequencePart2/main.cpp

CMakeFiles/SequencePart2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SequencePart2.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/douglasdunn/CLionProjects/cis4B/SequencePart2/main.cpp > CMakeFiles/SequencePart2.dir/main.cpp.i

CMakeFiles/SequencePart2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SequencePart2.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/douglasdunn/CLionProjects/cis4B/SequencePart2/main.cpp -o CMakeFiles/SequencePart2.dir/main.cpp.s

CMakeFiles/SequencePart2.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/SequencePart2.dir/main.cpp.o.requires

CMakeFiles/SequencePart2.dir/main.cpp.o.provides: CMakeFiles/SequencePart2.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/SequencePart2.dir/build.make CMakeFiles/SequencePart2.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/SequencePart2.dir/main.cpp.o.provides

CMakeFiles/SequencePart2.dir/main.cpp.o.provides.build: CMakeFiles/SequencePart2.dir/main.cpp.o


# Object files for target SequencePart2
SequencePart2_OBJECTS = \
"CMakeFiles/SequencePart2.dir/main.cpp.o"

# External object files for target SequencePart2
SequencePart2_EXTERNAL_OBJECTS =

SequencePart2: CMakeFiles/SequencePart2.dir/main.cpp.o
SequencePart2: CMakeFiles/SequencePart2.dir/build.make
SequencePart2: CMakeFiles/SequencePart2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/douglasdunn/CLionProjects/cis4B/SequencePart2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SequencePart2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SequencePart2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SequencePart2.dir/build: SequencePart2

.PHONY : CMakeFiles/SequencePart2.dir/build

CMakeFiles/SequencePart2.dir/requires: CMakeFiles/SequencePart2.dir/main.cpp.o.requires

.PHONY : CMakeFiles/SequencePart2.dir/requires

CMakeFiles/SequencePart2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SequencePart2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SequencePart2.dir/clean

CMakeFiles/SequencePart2.dir/depend:
	cd /Users/douglasdunn/CLionProjects/cis4B/SequencePart2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/douglasdunn/CLionProjects/cis4B/SequencePart2 /Users/douglasdunn/CLionProjects/cis4B/SequencePart2 /Users/douglasdunn/CLionProjects/cis4B/SequencePart2/cmake-build-debug /Users/douglasdunn/CLionProjects/cis4B/SequencePart2/cmake-build-debug /Users/douglasdunn/CLionProjects/cis4B/SequencePart2/cmake-build-debug/CMakeFiles/SequencePart2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SequencePart2.dir/depend

