# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/marc/docs/host/graphics/uebung01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marc/docs/host/graphics/uebung01

# Include any dependencies generated for this target.
include CMakeFiles/bin_03.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bin_03.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bin_03.dir/flags.make

CMakeFiles/bin_03.dir/03.c.o: CMakeFiles/bin_03.dir/flags.make
CMakeFiles/bin_03.dir/03.c.o: 03.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marc/docs/host/graphics/uebung01/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/bin_03.dir/03.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bin_03.dir/03.c.o   -c /home/marc/docs/host/graphics/uebung01/03.c

CMakeFiles/bin_03.dir/03.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bin_03.dir/03.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/marc/docs/host/graphics/uebung01/03.c > CMakeFiles/bin_03.dir/03.c.i

CMakeFiles/bin_03.dir/03.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bin_03.dir/03.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/marc/docs/host/graphics/uebung01/03.c -o CMakeFiles/bin_03.dir/03.c.s

CMakeFiles/bin_03.dir/03.c.o.requires:

.PHONY : CMakeFiles/bin_03.dir/03.c.o.requires

CMakeFiles/bin_03.dir/03.c.o.provides: CMakeFiles/bin_03.dir/03.c.o.requires
	$(MAKE) -f CMakeFiles/bin_03.dir/build.make CMakeFiles/bin_03.dir/03.c.o.provides.build
.PHONY : CMakeFiles/bin_03.dir/03.c.o.provides

CMakeFiles/bin_03.dir/03.c.o.provides.build: CMakeFiles/bin_03.dir/03.c.o


# Object files for target bin_03
bin_03_OBJECTS = \
"CMakeFiles/bin_03.dir/03.c.o"

# External object files for target bin_03
bin_03_EXTERNAL_OBJECTS =

bin/bin_03: CMakeFiles/bin_03.dir/03.c.o
bin/bin_03: CMakeFiles/bin_03.dir/build.make
bin/bin_03: /usr/lib/libGL.so
bin/bin_03: /usr/lib/libGLU.so
bin/bin_03: /usr/lib/libglut.so
bin/bin_03: /usr/lib/libXmu.so
bin/bin_03: /usr/lib/libXi.so
bin/bin_03: CMakeFiles/bin_03.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marc/docs/host/graphics/uebung01/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bin/bin_03"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bin_03.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bin_03.dir/build: bin/bin_03

.PHONY : CMakeFiles/bin_03.dir/build

CMakeFiles/bin_03.dir/requires: CMakeFiles/bin_03.dir/03.c.o.requires

.PHONY : CMakeFiles/bin_03.dir/requires

CMakeFiles/bin_03.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bin_03.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bin_03.dir/clean

CMakeFiles/bin_03.dir/depend:
	cd /home/marc/docs/host/graphics/uebung01 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marc/docs/host/graphics/uebung01 /home/marc/docs/host/graphics/uebung01 /home/marc/docs/host/graphics/uebung01 /home/marc/docs/host/graphics/uebung01 /home/marc/docs/host/graphics/uebung01/CMakeFiles/bin_03.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bin_03.dir/depend
