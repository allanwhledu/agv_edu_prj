# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/sjtuwhl/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.7142.39/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/sjtuwhl/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.7142.39/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sjtuwhl/ROBOTLAB_WS/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sjtuwhl/ROBOTLAB_WS/devel

# Include any dependencies generated for this target.
include urg_c-master/CMakeFiles/calculate_xy.dir/depend.make

# Include the progress variables for this target.
include urg_c-master/CMakeFiles/calculate_xy.dir/progress.make

# Include the compile flags for this target's objects.
include urg_c-master/CMakeFiles/calculate_xy.dir/flags.make

urg_c-master/CMakeFiles/calculate_xy.dir/current/samples/calculate_xy.c.o: urg_c-master/CMakeFiles/calculate_xy.dir/flags.make
urg_c-master/CMakeFiles/calculate_xy.dir/current/samples/calculate_xy.c.o: /home/sjtuwhl/ROBOTLAB_WS/src/urg_c-master/current/samples/calculate_xy.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sjtuwhl/ROBOTLAB_WS/devel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object urg_c-master/CMakeFiles/calculate_xy.dir/current/samples/calculate_xy.c.o"
	cd /home/sjtuwhl/ROBOTLAB_WS/devel/urg_c-master && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/calculate_xy.dir/current/samples/calculate_xy.c.o   -c /home/sjtuwhl/ROBOTLAB_WS/src/urg_c-master/current/samples/calculate_xy.c

urg_c-master/CMakeFiles/calculate_xy.dir/current/samples/calculate_xy.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/calculate_xy.dir/current/samples/calculate_xy.c.i"
	cd /home/sjtuwhl/ROBOTLAB_WS/devel/urg_c-master && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sjtuwhl/ROBOTLAB_WS/src/urg_c-master/current/samples/calculate_xy.c > CMakeFiles/calculate_xy.dir/current/samples/calculate_xy.c.i

urg_c-master/CMakeFiles/calculate_xy.dir/current/samples/calculate_xy.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/calculate_xy.dir/current/samples/calculate_xy.c.s"
	cd /home/sjtuwhl/ROBOTLAB_WS/devel/urg_c-master && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sjtuwhl/ROBOTLAB_WS/src/urg_c-master/current/samples/calculate_xy.c -o CMakeFiles/calculate_xy.dir/current/samples/calculate_xy.c.s

# Object files for target calculate_xy
calculate_xy_OBJECTS = \
"CMakeFiles/calculate_xy.dir/current/samples/calculate_xy.c.o"

# External object files for target calculate_xy
calculate_xy_EXTERNAL_OBJECTS =

lib/urg_c/calculate_xy: urg_c-master/CMakeFiles/calculate_xy.dir/current/samples/calculate_xy.c.o
lib/urg_c/calculate_xy: urg_c-master/CMakeFiles/calculate_xy.dir/build.make
lib/urg_c/calculate_xy: lib/libopen_urg_sensor.so
lib/urg_c/calculate_xy: lib/libliburg_c.so
lib/urg_c/calculate_xy: urg_c-master/CMakeFiles/calculate_xy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sjtuwhl/ROBOTLAB_WS/devel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../lib/urg_c/calculate_xy"
	cd /home/sjtuwhl/ROBOTLAB_WS/devel/urg_c-master && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/calculate_xy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
urg_c-master/CMakeFiles/calculate_xy.dir/build: lib/urg_c/calculate_xy

.PHONY : urg_c-master/CMakeFiles/calculate_xy.dir/build

urg_c-master/CMakeFiles/calculate_xy.dir/clean:
	cd /home/sjtuwhl/ROBOTLAB_WS/devel/urg_c-master && $(CMAKE_COMMAND) -P CMakeFiles/calculate_xy.dir/cmake_clean.cmake
.PHONY : urg_c-master/CMakeFiles/calculate_xy.dir/clean

urg_c-master/CMakeFiles/calculate_xy.dir/depend:
	cd /home/sjtuwhl/ROBOTLAB_WS/devel && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sjtuwhl/ROBOTLAB_WS/src /home/sjtuwhl/ROBOTLAB_WS/src/urg_c-master /home/sjtuwhl/ROBOTLAB_WS/devel /home/sjtuwhl/ROBOTLAB_WS/devel/urg_c-master /home/sjtuwhl/ROBOTLAB_WS/devel/urg_c-master/CMakeFiles/calculate_xy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : urg_c-master/CMakeFiles/calculate_xy.dir/depend

