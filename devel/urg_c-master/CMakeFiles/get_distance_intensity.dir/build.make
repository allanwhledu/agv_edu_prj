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
include urg_c-master/CMakeFiles/get_distance_intensity.dir/depend.make

# Include the progress variables for this target.
include urg_c-master/CMakeFiles/get_distance_intensity.dir/progress.make

# Include the compile flags for this target's objects.
include urg_c-master/CMakeFiles/get_distance_intensity.dir/flags.make

urg_c-master/CMakeFiles/get_distance_intensity.dir/current/samples/get_distance_intensity.c.o: urg_c-master/CMakeFiles/get_distance_intensity.dir/flags.make
urg_c-master/CMakeFiles/get_distance_intensity.dir/current/samples/get_distance_intensity.c.o: /home/sjtuwhl/ROBOTLAB_WS/src/urg_c-master/current/samples/get_distance_intensity.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sjtuwhl/ROBOTLAB_WS/devel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object urg_c-master/CMakeFiles/get_distance_intensity.dir/current/samples/get_distance_intensity.c.o"
	cd /home/sjtuwhl/ROBOTLAB_WS/devel/urg_c-master && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/get_distance_intensity.dir/current/samples/get_distance_intensity.c.o   -c /home/sjtuwhl/ROBOTLAB_WS/src/urg_c-master/current/samples/get_distance_intensity.c

urg_c-master/CMakeFiles/get_distance_intensity.dir/current/samples/get_distance_intensity.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/get_distance_intensity.dir/current/samples/get_distance_intensity.c.i"
	cd /home/sjtuwhl/ROBOTLAB_WS/devel/urg_c-master && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sjtuwhl/ROBOTLAB_WS/src/urg_c-master/current/samples/get_distance_intensity.c > CMakeFiles/get_distance_intensity.dir/current/samples/get_distance_intensity.c.i

urg_c-master/CMakeFiles/get_distance_intensity.dir/current/samples/get_distance_intensity.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/get_distance_intensity.dir/current/samples/get_distance_intensity.c.s"
	cd /home/sjtuwhl/ROBOTLAB_WS/devel/urg_c-master && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sjtuwhl/ROBOTLAB_WS/src/urg_c-master/current/samples/get_distance_intensity.c -o CMakeFiles/get_distance_intensity.dir/current/samples/get_distance_intensity.c.s

# Object files for target get_distance_intensity
get_distance_intensity_OBJECTS = \
"CMakeFiles/get_distance_intensity.dir/current/samples/get_distance_intensity.c.o"

# External object files for target get_distance_intensity
get_distance_intensity_EXTERNAL_OBJECTS =

lib/urg_c/get_distance_intensity: urg_c-master/CMakeFiles/get_distance_intensity.dir/current/samples/get_distance_intensity.c.o
lib/urg_c/get_distance_intensity: urg_c-master/CMakeFiles/get_distance_intensity.dir/build.make
lib/urg_c/get_distance_intensity: lib/libopen_urg_sensor.so
lib/urg_c/get_distance_intensity: lib/libliburg_c.so
lib/urg_c/get_distance_intensity: urg_c-master/CMakeFiles/get_distance_intensity.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sjtuwhl/ROBOTLAB_WS/devel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../lib/urg_c/get_distance_intensity"
	cd /home/sjtuwhl/ROBOTLAB_WS/devel/urg_c-master && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/get_distance_intensity.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
urg_c-master/CMakeFiles/get_distance_intensity.dir/build: lib/urg_c/get_distance_intensity

.PHONY : urg_c-master/CMakeFiles/get_distance_intensity.dir/build

urg_c-master/CMakeFiles/get_distance_intensity.dir/clean:
	cd /home/sjtuwhl/ROBOTLAB_WS/devel/urg_c-master && $(CMAKE_COMMAND) -P CMakeFiles/get_distance_intensity.dir/cmake_clean.cmake
.PHONY : urg_c-master/CMakeFiles/get_distance_intensity.dir/clean

urg_c-master/CMakeFiles/get_distance_intensity.dir/depend:
	cd /home/sjtuwhl/ROBOTLAB_WS/devel && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sjtuwhl/ROBOTLAB_WS/src /home/sjtuwhl/ROBOTLAB_WS/src/urg_c-master /home/sjtuwhl/ROBOTLAB_WS/devel /home/sjtuwhl/ROBOTLAB_WS/devel/urg_c-master /home/sjtuwhl/ROBOTLAB_WS/devel/urg_c-master/CMakeFiles/get_distance_intensity.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : urg_c-master/CMakeFiles/get_distance_intensity.dir/depend
