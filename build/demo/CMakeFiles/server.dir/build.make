# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/feng/CS/Program/my-src/my-weberver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/feng/CS/Program/my-src/my-weberver/build

# Include any dependencies generated for this target.
include demo/CMakeFiles/server.dir/depend.make

# Include the progress variables for this target.
include demo/CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include demo/CMakeFiles/server.dir/flags.make

demo/CMakeFiles/server.dir/main.cpp.o: demo/CMakeFiles/server.dir/flags.make
demo/CMakeFiles/server.dir/main.cpp.o: ../demo/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/feng/CS/Program/my-src/my-weberver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object demo/CMakeFiles/server.dir/main.cpp.o"
	cd /home/feng/CS/Program/my-src/my-weberver/build/demo && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/main.cpp.o -c /home/feng/CS/Program/my-src/my-weberver/demo/main.cpp

demo/CMakeFiles/server.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/main.cpp.i"
	cd /home/feng/CS/Program/my-src/my-weberver/build/demo && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/feng/CS/Program/my-src/my-weberver/demo/main.cpp > CMakeFiles/server.dir/main.cpp.i

demo/CMakeFiles/server.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/main.cpp.s"
	cd /home/feng/CS/Program/my-src/my-weberver/build/demo && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/feng/CS/Program/my-src/my-weberver/demo/main.cpp -o CMakeFiles/server.dir/main.cpp.s

# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/main.cpp.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

../bin/server: demo/CMakeFiles/server.dir/main.cpp.o
../bin/server: demo/CMakeFiles/server.dir/build.make
../bin/server: ../lib/libmy-webserver.so
../bin/server: demo/CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/feng/CS/Program/my-src/my-weberver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/server"
	cd /home/feng/CS/Program/my-src/my-weberver/build/demo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
demo/CMakeFiles/server.dir/build: ../bin/server

.PHONY : demo/CMakeFiles/server.dir/build

demo/CMakeFiles/server.dir/clean:
	cd /home/feng/CS/Program/my-src/my-weberver/build/demo && $(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : demo/CMakeFiles/server.dir/clean

demo/CMakeFiles/server.dir/depend:
	cd /home/feng/CS/Program/my-src/my-weberver/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/feng/CS/Program/my-src/my-weberver /home/feng/CS/Program/my-src/my-weberver/demo /home/feng/CS/Program/my-src/my-weberver/build /home/feng/CS/Program/my-src/my-weberver/build/demo /home/feng/CS/Program/my-src/my-weberver/build/demo/CMakeFiles/server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : demo/CMakeFiles/server.dir/depend

