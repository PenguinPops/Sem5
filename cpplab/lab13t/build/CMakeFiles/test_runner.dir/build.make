# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/evani/Documents/Sem5/cpplab/lab13t

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/evani/Documents/Sem5/cpplab/lab13t/build

# Include any dependencies generated for this target.
include CMakeFiles/test_runner.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_runner.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_runner.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_runner.dir/flags.make

CMakeFiles/test_runner.dir/main.cpp.o: CMakeFiles/test_runner.dir/flags.make
CMakeFiles/test_runner.dir/main.cpp.o: /home/evani/Documents/Sem5/cpplab/lab13t/main.cpp
CMakeFiles/test_runner.dir/main.cpp.o: CMakeFiles/test_runner.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/evani/Documents/Sem5/cpplab/lab13t/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_runner.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_runner.dir/main.cpp.o -MF CMakeFiles/test_runner.dir/main.cpp.o.d -o CMakeFiles/test_runner.dir/main.cpp.o -c /home/evani/Documents/Sem5/cpplab/lab13t/main.cpp

CMakeFiles/test_runner.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_runner.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/evani/Documents/Sem5/cpplab/lab13t/main.cpp > CMakeFiles/test_runner.dir/main.cpp.i

CMakeFiles/test_runner.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_runner.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/evani/Documents/Sem5/cpplab/lab13t/main.cpp -o CMakeFiles/test_runner.dir/main.cpp.s

CMakeFiles/test_runner.dir/test.cpp.o: CMakeFiles/test_runner.dir/flags.make
CMakeFiles/test_runner.dir/test.cpp.o: /home/evani/Documents/Sem5/cpplab/lab13t/test.cpp
CMakeFiles/test_runner.dir/test.cpp.o: CMakeFiles/test_runner.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/evani/Documents/Sem5/cpplab/lab13t/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test_runner.dir/test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_runner.dir/test.cpp.o -MF CMakeFiles/test_runner.dir/test.cpp.o.d -o CMakeFiles/test_runner.dir/test.cpp.o -c /home/evani/Documents/Sem5/cpplab/lab13t/test.cpp

CMakeFiles/test_runner.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_runner.dir/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/evani/Documents/Sem5/cpplab/lab13t/test.cpp > CMakeFiles/test_runner.dir/test.cpp.i

CMakeFiles/test_runner.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_runner.dir/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/evani/Documents/Sem5/cpplab/lab13t/test.cpp -o CMakeFiles/test_runner.dir/test.cpp.s

# Object files for target test_runner
test_runner_OBJECTS = \
"CMakeFiles/test_runner.dir/main.cpp.o" \
"CMakeFiles/test_runner.dir/test.cpp.o"

# External object files for target test_runner
test_runner_EXTERNAL_OBJECTS =

test_runner: CMakeFiles/test_runner.dir/main.cpp.o
test_runner: CMakeFiles/test_runner.dir/test.cpp.o
test_runner: CMakeFiles/test_runner.dir/build.make
test_runner: /usr/local/lib64/libgtest.a
test_runner: CMakeFiles/test_runner.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/evani/Documents/Sem5/cpplab/lab13t/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable test_runner"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_runner.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_runner.dir/build: test_runner
.PHONY : CMakeFiles/test_runner.dir/build

CMakeFiles/test_runner.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_runner.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_runner.dir/clean

CMakeFiles/test_runner.dir/depend:
	cd /home/evani/Documents/Sem5/cpplab/lab13t/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/evani/Documents/Sem5/cpplab/lab13t /home/evani/Documents/Sem5/cpplab/lab13t /home/evani/Documents/Sem5/cpplab/lab13t/build /home/evani/Documents/Sem5/cpplab/lab13t/build /home/evani/Documents/Sem5/cpplab/lab13t/build/CMakeFiles/test_runner.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/test_runner.dir/depend

