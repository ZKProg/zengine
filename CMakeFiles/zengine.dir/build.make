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
CMAKE_SOURCE_DIR = /home/john/Programming/cpp/zengine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/john/Programming/cpp/zengine

# Include any dependencies generated for this target.
include CMakeFiles/zengine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/zengine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zengine.dir/flags.make

CMakeFiles/zengine.dir/main.cpp.o: CMakeFiles/zengine.dir/flags.make
CMakeFiles/zengine.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/john/Programming/cpp/zengine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/zengine.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zengine.dir/main.cpp.o -c /home/john/Programming/cpp/zengine/main.cpp

CMakeFiles/zengine.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zengine.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/john/Programming/cpp/zengine/main.cpp > CMakeFiles/zengine.dir/main.cpp.i

CMakeFiles/zengine.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zengine.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/john/Programming/cpp/zengine/main.cpp -o CMakeFiles/zengine.dir/main.cpp.s

CMakeFiles/zengine.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/zengine.dir/main.cpp.o.requires

CMakeFiles/zengine.dir/main.cpp.o.provides: CMakeFiles/zengine.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/zengine.dir/build.make CMakeFiles/zengine.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/zengine.dir/main.cpp.o.provides

CMakeFiles/zengine.dir/main.cpp.o.provides.build: CMakeFiles/zengine.dir/main.cpp.o


CMakeFiles/zengine.dir/src/music.cpp.o: CMakeFiles/zengine.dir/flags.make
CMakeFiles/zengine.dir/src/music.cpp.o: src/music.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/john/Programming/cpp/zengine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/zengine.dir/src/music.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zengine.dir/src/music.cpp.o -c /home/john/Programming/cpp/zengine/src/music.cpp

CMakeFiles/zengine.dir/src/music.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zengine.dir/src/music.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/john/Programming/cpp/zengine/src/music.cpp > CMakeFiles/zengine.dir/src/music.cpp.i

CMakeFiles/zengine.dir/src/music.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zengine.dir/src/music.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/john/Programming/cpp/zengine/src/music.cpp -o CMakeFiles/zengine.dir/src/music.cpp.s

CMakeFiles/zengine.dir/src/music.cpp.o.requires:

.PHONY : CMakeFiles/zengine.dir/src/music.cpp.o.requires

CMakeFiles/zengine.dir/src/music.cpp.o.provides: CMakeFiles/zengine.dir/src/music.cpp.o.requires
	$(MAKE) -f CMakeFiles/zengine.dir/build.make CMakeFiles/zengine.dir/src/music.cpp.o.provides.build
.PHONY : CMakeFiles/zengine.dir/src/music.cpp.o.provides

CMakeFiles/zengine.dir/src/music.cpp.o.provides.build: CMakeFiles/zengine.dir/src/music.cpp.o


CMakeFiles/zengine.dir/src/sound.cpp.o: CMakeFiles/zengine.dir/flags.make
CMakeFiles/zengine.dir/src/sound.cpp.o: src/sound.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/john/Programming/cpp/zengine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/zengine.dir/src/sound.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zengine.dir/src/sound.cpp.o -c /home/john/Programming/cpp/zengine/src/sound.cpp

CMakeFiles/zengine.dir/src/sound.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zengine.dir/src/sound.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/john/Programming/cpp/zengine/src/sound.cpp > CMakeFiles/zengine.dir/src/sound.cpp.i

CMakeFiles/zengine.dir/src/sound.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zengine.dir/src/sound.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/john/Programming/cpp/zengine/src/sound.cpp -o CMakeFiles/zengine.dir/src/sound.cpp.s

CMakeFiles/zengine.dir/src/sound.cpp.o.requires:

.PHONY : CMakeFiles/zengine.dir/src/sound.cpp.o.requires

CMakeFiles/zengine.dir/src/sound.cpp.o.provides: CMakeFiles/zengine.dir/src/sound.cpp.o.requires
	$(MAKE) -f CMakeFiles/zengine.dir/build.make CMakeFiles/zengine.dir/src/sound.cpp.o.provides.build
.PHONY : CMakeFiles/zengine.dir/src/sound.cpp.o.provides

CMakeFiles/zengine.dir/src/sound.cpp.o.provides.build: CMakeFiles/zengine.dir/src/sound.cpp.o


CMakeFiles/zengine.dir/src/soundeffect.cpp.o: CMakeFiles/zengine.dir/flags.make
CMakeFiles/zengine.dir/src/soundeffect.cpp.o: src/soundeffect.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/john/Programming/cpp/zengine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/zengine.dir/src/soundeffect.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zengine.dir/src/soundeffect.cpp.o -c /home/john/Programming/cpp/zengine/src/soundeffect.cpp

CMakeFiles/zengine.dir/src/soundeffect.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zengine.dir/src/soundeffect.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/john/Programming/cpp/zengine/src/soundeffect.cpp > CMakeFiles/zengine.dir/src/soundeffect.cpp.i

CMakeFiles/zengine.dir/src/soundeffect.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zengine.dir/src/soundeffect.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/john/Programming/cpp/zengine/src/soundeffect.cpp -o CMakeFiles/zengine.dir/src/soundeffect.cpp.s

CMakeFiles/zengine.dir/src/soundeffect.cpp.o.requires:

.PHONY : CMakeFiles/zengine.dir/src/soundeffect.cpp.o.requires

CMakeFiles/zengine.dir/src/soundeffect.cpp.o.provides: CMakeFiles/zengine.dir/src/soundeffect.cpp.o.requires
	$(MAKE) -f CMakeFiles/zengine.dir/build.make CMakeFiles/zengine.dir/src/soundeffect.cpp.o.provides.build
.PHONY : CMakeFiles/zengine.dir/src/soundeffect.cpp.o.provides

CMakeFiles/zengine.dir/src/soundeffect.cpp.o.provides.build: CMakeFiles/zengine.dir/src/soundeffect.cpp.o


CMakeFiles/zengine.dir/src/2D/asset.cpp.o: CMakeFiles/zengine.dir/flags.make
CMakeFiles/zengine.dir/src/2D/asset.cpp.o: src/2D/asset.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/john/Programming/cpp/zengine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/zengine.dir/src/2D/asset.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zengine.dir/src/2D/asset.cpp.o -c /home/john/Programming/cpp/zengine/src/2D/asset.cpp

CMakeFiles/zengine.dir/src/2D/asset.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zengine.dir/src/2D/asset.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/john/Programming/cpp/zengine/src/2D/asset.cpp > CMakeFiles/zengine.dir/src/2D/asset.cpp.i

CMakeFiles/zengine.dir/src/2D/asset.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zengine.dir/src/2D/asset.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/john/Programming/cpp/zengine/src/2D/asset.cpp -o CMakeFiles/zengine.dir/src/2D/asset.cpp.s

CMakeFiles/zengine.dir/src/2D/asset.cpp.o.requires:

.PHONY : CMakeFiles/zengine.dir/src/2D/asset.cpp.o.requires

CMakeFiles/zengine.dir/src/2D/asset.cpp.o.provides: CMakeFiles/zengine.dir/src/2D/asset.cpp.o.requires
	$(MAKE) -f CMakeFiles/zengine.dir/build.make CMakeFiles/zengine.dir/src/2D/asset.cpp.o.provides.build
.PHONY : CMakeFiles/zengine.dir/src/2D/asset.cpp.o.provides

CMakeFiles/zengine.dir/src/2D/asset.cpp.o.provides.build: CMakeFiles/zengine.dir/src/2D/asset.cpp.o


CMakeFiles/zengine.dir/src/2D/circle.cpp.o: CMakeFiles/zengine.dir/flags.make
CMakeFiles/zengine.dir/src/2D/circle.cpp.o: src/2D/circle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/john/Programming/cpp/zengine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/zengine.dir/src/2D/circle.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zengine.dir/src/2D/circle.cpp.o -c /home/john/Programming/cpp/zengine/src/2D/circle.cpp

CMakeFiles/zengine.dir/src/2D/circle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zengine.dir/src/2D/circle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/john/Programming/cpp/zengine/src/2D/circle.cpp > CMakeFiles/zengine.dir/src/2D/circle.cpp.i

CMakeFiles/zengine.dir/src/2D/circle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zengine.dir/src/2D/circle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/john/Programming/cpp/zengine/src/2D/circle.cpp -o CMakeFiles/zengine.dir/src/2D/circle.cpp.s

CMakeFiles/zengine.dir/src/2D/circle.cpp.o.requires:

.PHONY : CMakeFiles/zengine.dir/src/2D/circle.cpp.o.requires

CMakeFiles/zengine.dir/src/2D/circle.cpp.o.provides: CMakeFiles/zengine.dir/src/2D/circle.cpp.o.requires
	$(MAKE) -f CMakeFiles/zengine.dir/build.make CMakeFiles/zengine.dir/src/2D/circle.cpp.o.provides.build
.PHONY : CMakeFiles/zengine.dir/src/2D/circle.cpp.o.provides

CMakeFiles/zengine.dir/src/2D/circle.cpp.o.provides.build: CMakeFiles/zengine.dir/src/2D/circle.cpp.o


CMakeFiles/zengine.dir/src/2D/fonttexture.cpp.o: CMakeFiles/zengine.dir/flags.make
CMakeFiles/zengine.dir/src/2D/fonttexture.cpp.o: src/2D/fonttexture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/john/Programming/cpp/zengine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/zengine.dir/src/2D/fonttexture.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zengine.dir/src/2D/fonttexture.cpp.o -c /home/john/Programming/cpp/zengine/src/2D/fonttexture.cpp

CMakeFiles/zengine.dir/src/2D/fonttexture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zengine.dir/src/2D/fonttexture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/john/Programming/cpp/zengine/src/2D/fonttexture.cpp > CMakeFiles/zengine.dir/src/2D/fonttexture.cpp.i

CMakeFiles/zengine.dir/src/2D/fonttexture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zengine.dir/src/2D/fonttexture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/john/Programming/cpp/zengine/src/2D/fonttexture.cpp -o CMakeFiles/zengine.dir/src/2D/fonttexture.cpp.s

CMakeFiles/zengine.dir/src/2D/fonttexture.cpp.o.requires:

.PHONY : CMakeFiles/zengine.dir/src/2D/fonttexture.cpp.o.requires

CMakeFiles/zengine.dir/src/2D/fonttexture.cpp.o.provides: CMakeFiles/zengine.dir/src/2D/fonttexture.cpp.o.requires
	$(MAKE) -f CMakeFiles/zengine.dir/build.make CMakeFiles/zengine.dir/src/2D/fonttexture.cpp.o.provides.build
.PHONY : CMakeFiles/zengine.dir/src/2D/fonttexture.cpp.o.provides

CMakeFiles/zengine.dir/src/2D/fonttexture.cpp.o.provides.build: CMakeFiles/zengine.dir/src/2D/fonttexture.cpp.o


CMakeFiles/zengine.dir/src/2D/gameengine.cpp.o: CMakeFiles/zengine.dir/flags.make
CMakeFiles/zengine.dir/src/2D/gameengine.cpp.o: src/2D/gameengine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/john/Programming/cpp/zengine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/zengine.dir/src/2D/gameengine.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zengine.dir/src/2D/gameengine.cpp.o -c /home/john/Programming/cpp/zengine/src/2D/gameengine.cpp

CMakeFiles/zengine.dir/src/2D/gameengine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zengine.dir/src/2D/gameengine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/john/Programming/cpp/zengine/src/2D/gameengine.cpp > CMakeFiles/zengine.dir/src/2D/gameengine.cpp.i

CMakeFiles/zengine.dir/src/2D/gameengine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zengine.dir/src/2D/gameengine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/john/Programming/cpp/zengine/src/2D/gameengine.cpp -o CMakeFiles/zengine.dir/src/2D/gameengine.cpp.s

CMakeFiles/zengine.dir/src/2D/gameengine.cpp.o.requires:

.PHONY : CMakeFiles/zengine.dir/src/2D/gameengine.cpp.o.requires

CMakeFiles/zengine.dir/src/2D/gameengine.cpp.o.provides: CMakeFiles/zengine.dir/src/2D/gameengine.cpp.o.requires
	$(MAKE) -f CMakeFiles/zengine.dir/build.make CMakeFiles/zengine.dir/src/2D/gameengine.cpp.o.provides.build
.PHONY : CMakeFiles/zengine.dir/src/2D/gameengine.cpp.o.provides

CMakeFiles/zengine.dir/src/2D/gameengine.cpp.o.provides.build: CMakeFiles/zengine.dir/src/2D/gameengine.cpp.o


CMakeFiles/zengine.dir/src/2D/geometry.cpp.o: CMakeFiles/zengine.dir/flags.make
CMakeFiles/zengine.dir/src/2D/geometry.cpp.o: src/2D/geometry.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/john/Programming/cpp/zengine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/zengine.dir/src/2D/geometry.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zengine.dir/src/2D/geometry.cpp.o -c /home/john/Programming/cpp/zengine/src/2D/geometry.cpp

CMakeFiles/zengine.dir/src/2D/geometry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zengine.dir/src/2D/geometry.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/john/Programming/cpp/zengine/src/2D/geometry.cpp > CMakeFiles/zengine.dir/src/2D/geometry.cpp.i

CMakeFiles/zengine.dir/src/2D/geometry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zengine.dir/src/2D/geometry.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/john/Programming/cpp/zengine/src/2D/geometry.cpp -o CMakeFiles/zengine.dir/src/2D/geometry.cpp.s

CMakeFiles/zengine.dir/src/2D/geometry.cpp.o.requires:

.PHONY : CMakeFiles/zengine.dir/src/2D/geometry.cpp.o.requires

CMakeFiles/zengine.dir/src/2D/geometry.cpp.o.provides: CMakeFiles/zengine.dir/src/2D/geometry.cpp.o.requires
	$(MAKE) -f CMakeFiles/zengine.dir/build.make CMakeFiles/zengine.dir/src/2D/geometry.cpp.o.provides.build
.PHONY : CMakeFiles/zengine.dir/src/2D/geometry.cpp.o.provides

CMakeFiles/zengine.dir/src/2D/geometry.cpp.o.provides.build: CMakeFiles/zengine.dir/src/2D/geometry.cpp.o


CMakeFiles/zengine.dir/src/2D/rectangle.cpp.o: CMakeFiles/zengine.dir/flags.make
CMakeFiles/zengine.dir/src/2D/rectangle.cpp.o: src/2D/rectangle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/john/Programming/cpp/zengine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/zengine.dir/src/2D/rectangle.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zengine.dir/src/2D/rectangle.cpp.o -c /home/john/Programming/cpp/zengine/src/2D/rectangle.cpp

CMakeFiles/zengine.dir/src/2D/rectangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zengine.dir/src/2D/rectangle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/john/Programming/cpp/zengine/src/2D/rectangle.cpp > CMakeFiles/zengine.dir/src/2D/rectangle.cpp.i

CMakeFiles/zengine.dir/src/2D/rectangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zengine.dir/src/2D/rectangle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/john/Programming/cpp/zengine/src/2D/rectangle.cpp -o CMakeFiles/zengine.dir/src/2D/rectangle.cpp.s

CMakeFiles/zengine.dir/src/2D/rectangle.cpp.o.requires:

.PHONY : CMakeFiles/zengine.dir/src/2D/rectangle.cpp.o.requires

CMakeFiles/zengine.dir/src/2D/rectangle.cpp.o.provides: CMakeFiles/zengine.dir/src/2D/rectangle.cpp.o.requires
	$(MAKE) -f CMakeFiles/zengine.dir/build.make CMakeFiles/zengine.dir/src/2D/rectangle.cpp.o.provides.build
.PHONY : CMakeFiles/zengine.dir/src/2D/rectangle.cpp.o.provides

CMakeFiles/zengine.dir/src/2D/rectangle.cpp.o.provides.build: CMakeFiles/zengine.dir/src/2D/rectangle.cpp.o


CMakeFiles/zengine.dir/src/2D/texture.cpp.o: CMakeFiles/zengine.dir/flags.make
CMakeFiles/zengine.dir/src/2D/texture.cpp.o: src/2D/texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/john/Programming/cpp/zengine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/zengine.dir/src/2D/texture.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zengine.dir/src/2D/texture.cpp.o -c /home/john/Programming/cpp/zengine/src/2D/texture.cpp

CMakeFiles/zengine.dir/src/2D/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zengine.dir/src/2D/texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/john/Programming/cpp/zengine/src/2D/texture.cpp > CMakeFiles/zengine.dir/src/2D/texture.cpp.i

CMakeFiles/zengine.dir/src/2D/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zengine.dir/src/2D/texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/john/Programming/cpp/zengine/src/2D/texture.cpp -o CMakeFiles/zengine.dir/src/2D/texture.cpp.s

CMakeFiles/zengine.dir/src/2D/texture.cpp.o.requires:

.PHONY : CMakeFiles/zengine.dir/src/2D/texture.cpp.o.requires

CMakeFiles/zengine.dir/src/2D/texture.cpp.o.provides: CMakeFiles/zengine.dir/src/2D/texture.cpp.o.requires
	$(MAKE) -f CMakeFiles/zengine.dir/build.make CMakeFiles/zengine.dir/src/2D/texture.cpp.o.provides.build
.PHONY : CMakeFiles/zengine.dir/src/2D/texture.cpp.o.provides

CMakeFiles/zengine.dir/src/2D/texture.cpp.o.provides.build: CMakeFiles/zengine.dir/src/2D/texture.cpp.o


CMakeFiles/zengine.dir/src/3D/glcontext.cpp.o: CMakeFiles/zengine.dir/flags.make
CMakeFiles/zengine.dir/src/3D/glcontext.cpp.o: src/3D/glcontext.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/john/Programming/cpp/zengine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/zengine.dir/src/3D/glcontext.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zengine.dir/src/3D/glcontext.cpp.o -c /home/john/Programming/cpp/zengine/src/3D/glcontext.cpp

CMakeFiles/zengine.dir/src/3D/glcontext.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zengine.dir/src/3D/glcontext.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/john/Programming/cpp/zengine/src/3D/glcontext.cpp > CMakeFiles/zengine.dir/src/3D/glcontext.cpp.i

CMakeFiles/zengine.dir/src/3D/glcontext.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zengine.dir/src/3D/glcontext.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/john/Programming/cpp/zengine/src/3D/glcontext.cpp -o CMakeFiles/zengine.dir/src/3D/glcontext.cpp.s

CMakeFiles/zengine.dir/src/3D/glcontext.cpp.o.requires:

.PHONY : CMakeFiles/zengine.dir/src/3D/glcontext.cpp.o.requires

CMakeFiles/zengine.dir/src/3D/glcontext.cpp.o.provides: CMakeFiles/zengine.dir/src/3D/glcontext.cpp.o.requires
	$(MAKE) -f CMakeFiles/zengine.dir/build.make CMakeFiles/zengine.dir/src/3D/glcontext.cpp.o.provides.build
.PHONY : CMakeFiles/zengine.dir/src/3D/glcontext.cpp.o.provides

CMakeFiles/zengine.dir/src/3D/glcontext.cpp.o.provides.build: CMakeFiles/zengine.dir/src/3D/glcontext.cpp.o


CMakeFiles/zengine.dir/src/3D/mesh.cpp.o: CMakeFiles/zengine.dir/flags.make
CMakeFiles/zengine.dir/src/3D/mesh.cpp.o: src/3D/mesh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/john/Programming/cpp/zengine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/zengine.dir/src/3D/mesh.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zengine.dir/src/3D/mesh.cpp.o -c /home/john/Programming/cpp/zengine/src/3D/mesh.cpp

CMakeFiles/zengine.dir/src/3D/mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zengine.dir/src/3D/mesh.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/john/Programming/cpp/zengine/src/3D/mesh.cpp > CMakeFiles/zengine.dir/src/3D/mesh.cpp.i

CMakeFiles/zengine.dir/src/3D/mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zengine.dir/src/3D/mesh.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/john/Programming/cpp/zengine/src/3D/mesh.cpp -o CMakeFiles/zengine.dir/src/3D/mesh.cpp.s

CMakeFiles/zengine.dir/src/3D/mesh.cpp.o.requires:

.PHONY : CMakeFiles/zengine.dir/src/3D/mesh.cpp.o.requires

CMakeFiles/zengine.dir/src/3D/mesh.cpp.o.provides: CMakeFiles/zengine.dir/src/3D/mesh.cpp.o.requires
	$(MAKE) -f CMakeFiles/zengine.dir/build.make CMakeFiles/zengine.dir/src/3D/mesh.cpp.o.provides.build
.PHONY : CMakeFiles/zengine.dir/src/3D/mesh.cpp.o.provides

CMakeFiles/zengine.dir/src/3D/mesh.cpp.o.provides.build: CMakeFiles/zengine.dir/src/3D/mesh.cpp.o


CMakeFiles/zengine.dir/src/3D/plane.cpp.o: CMakeFiles/zengine.dir/flags.make
CMakeFiles/zengine.dir/src/3D/plane.cpp.o: src/3D/plane.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/john/Programming/cpp/zengine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/zengine.dir/src/3D/plane.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zengine.dir/src/3D/plane.cpp.o -c /home/john/Programming/cpp/zengine/src/3D/plane.cpp

CMakeFiles/zengine.dir/src/3D/plane.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zengine.dir/src/3D/plane.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/john/Programming/cpp/zengine/src/3D/plane.cpp > CMakeFiles/zengine.dir/src/3D/plane.cpp.i

CMakeFiles/zengine.dir/src/3D/plane.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zengine.dir/src/3D/plane.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/john/Programming/cpp/zengine/src/3D/plane.cpp -o CMakeFiles/zengine.dir/src/3D/plane.cpp.s

CMakeFiles/zengine.dir/src/3D/plane.cpp.o.requires:

.PHONY : CMakeFiles/zengine.dir/src/3D/plane.cpp.o.requires

CMakeFiles/zengine.dir/src/3D/plane.cpp.o.provides: CMakeFiles/zengine.dir/src/3D/plane.cpp.o.requires
	$(MAKE) -f CMakeFiles/zengine.dir/build.make CMakeFiles/zengine.dir/src/3D/plane.cpp.o.provides.build
.PHONY : CMakeFiles/zengine.dir/src/3D/plane.cpp.o.provides

CMakeFiles/zengine.dir/src/3D/plane.cpp.o.provides.build: CMakeFiles/zengine.dir/src/3D/plane.cpp.o


CMakeFiles/zengine.dir/src/3D/shader.cpp.o: CMakeFiles/zengine.dir/flags.make
CMakeFiles/zengine.dir/src/3D/shader.cpp.o: src/3D/shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/john/Programming/cpp/zengine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/zengine.dir/src/3D/shader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zengine.dir/src/3D/shader.cpp.o -c /home/john/Programming/cpp/zengine/src/3D/shader.cpp

CMakeFiles/zengine.dir/src/3D/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zengine.dir/src/3D/shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/john/Programming/cpp/zengine/src/3D/shader.cpp > CMakeFiles/zengine.dir/src/3D/shader.cpp.i

CMakeFiles/zengine.dir/src/3D/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zengine.dir/src/3D/shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/john/Programming/cpp/zengine/src/3D/shader.cpp -o CMakeFiles/zengine.dir/src/3D/shader.cpp.s

CMakeFiles/zengine.dir/src/3D/shader.cpp.o.requires:

.PHONY : CMakeFiles/zengine.dir/src/3D/shader.cpp.o.requires

CMakeFiles/zengine.dir/src/3D/shader.cpp.o.provides: CMakeFiles/zengine.dir/src/3D/shader.cpp.o.requires
	$(MAKE) -f CMakeFiles/zengine.dir/build.make CMakeFiles/zengine.dir/src/3D/shader.cpp.o.provides.build
.PHONY : CMakeFiles/zengine.dir/src/3D/shader.cpp.o.provides

CMakeFiles/zengine.dir/src/3D/shader.cpp.o.provides.build: CMakeFiles/zengine.dir/src/3D/shader.cpp.o


# Object files for target zengine
zengine_OBJECTS = \
"CMakeFiles/zengine.dir/main.cpp.o" \
"CMakeFiles/zengine.dir/src/music.cpp.o" \
"CMakeFiles/zengine.dir/src/sound.cpp.o" \
"CMakeFiles/zengine.dir/src/soundeffect.cpp.o" \
"CMakeFiles/zengine.dir/src/2D/asset.cpp.o" \
"CMakeFiles/zengine.dir/src/2D/circle.cpp.o" \
"CMakeFiles/zengine.dir/src/2D/fonttexture.cpp.o" \
"CMakeFiles/zengine.dir/src/2D/gameengine.cpp.o" \
"CMakeFiles/zengine.dir/src/2D/geometry.cpp.o" \
"CMakeFiles/zengine.dir/src/2D/rectangle.cpp.o" \
"CMakeFiles/zengine.dir/src/2D/texture.cpp.o" \
"CMakeFiles/zengine.dir/src/3D/glcontext.cpp.o" \
"CMakeFiles/zengine.dir/src/3D/mesh.cpp.o" \
"CMakeFiles/zengine.dir/src/3D/plane.cpp.o" \
"CMakeFiles/zengine.dir/src/3D/shader.cpp.o"

# External object files for target zengine
zengine_EXTERNAL_OBJECTS =

zengine: CMakeFiles/zengine.dir/main.cpp.o
zengine: CMakeFiles/zengine.dir/src/music.cpp.o
zengine: CMakeFiles/zengine.dir/src/sound.cpp.o
zengine: CMakeFiles/zengine.dir/src/soundeffect.cpp.o
zengine: CMakeFiles/zengine.dir/src/2D/asset.cpp.o
zengine: CMakeFiles/zengine.dir/src/2D/circle.cpp.o
zengine: CMakeFiles/zengine.dir/src/2D/fonttexture.cpp.o
zengine: CMakeFiles/zengine.dir/src/2D/gameengine.cpp.o
zengine: CMakeFiles/zengine.dir/src/2D/geometry.cpp.o
zengine: CMakeFiles/zengine.dir/src/2D/rectangle.cpp.o
zengine: CMakeFiles/zengine.dir/src/2D/texture.cpp.o
zengine: CMakeFiles/zengine.dir/src/3D/glcontext.cpp.o
zengine: CMakeFiles/zengine.dir/src/3D/mesh.cpp.o
zengine: CMakeFiles/zengine.dir/src/3D/plane.cpp.o
zengine: CMakeFiles/zengine.dir/src/3D/shader.cpp.o
zengine: CMakeFiles/zengine.dir/build.make
zengine: CMakeFiles/zengine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/john/Programming/cpp/zengine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Linking CXX executable zengine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zengine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zengine.dir/build: zengine

.PHONY : CMakeFiles/zengine.dir/build

CMakeFiles/zengine.dir/requires: CMakeFiles/zengine.dir/main.cpp.o.requires
CMakeFiles/zengine.dir/requires: CMakeFiles/zengine.dir/src/music.cpp.o.requires
CMakeFiles/zengine.dir/requires: CMakeFiles/zengine.dir/src/sound.cpp.o.requires
CMakeFiles/zengine.dir/requires: CMakeFiles/zengine.dir/src/soundeffect.cpp.o.requires
CMakeFiles/zengine.dir/requires: CMakeFiles/zengine.dir/src/2D/asset.cpp.o.requires
CMakeFiles/zengine.dir/requires: CMakeFiles/zengine.dir/src/2D/circle.cpp.o.requires
CMakeFiles/zengine.dir/requires: CMakeFiles/zengine.dir/src/2D/fonttexture.cpp.o.requires
CMakeFiles/zengine.dir/requires: CMakeFiles/zengine.dir/src/2D/gameengine.cpp.o.requires
CMakeFiles/zengine.dir/requires: CMakeFiles/zengine.dir/src/2D/geometry.cpp.o.requires
CMakeFiles/zengine.dir/requires: CMakeFiles/zengine.dir/src/2D/rectangle.cpp.o.requires
CMakeFiles/zengine.dir/requires: CMakeFiles/zengine.dir/src/2D/texture.cpp.o.requires
CMakeFiles/zengine.dir/requires: CMakeFiles/zengine.dir/src/3D/glcontext.cpp.o.requires
CMakeFiles/zengine.dir/requires: CMakeFiles/zengine.dir/src/3D/mesh.cpp.o.requires
CMakeFiles/zengine.dir/requires: CMakeFiles/zengine.dir/src/3D/plane.cpp.o.requires
CMakeFiles/zengine.dir/requires: CMakeFiles/zengine.dir/src/3D/shader.cpp.o.requires

.PHONY : CMakeFiles/zengine.dir/requires

CMakeFiles/zengine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/zengine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/zengine.dir/clean

CMakeFiles/zengine.dir/depend:
	cd /home/john/Programming/cpp/zengine && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/john/Programming/cpp/zengine /home/john/Programming/cpp/zengine /home/john/Programming/cpp/zengine /home/john/Programming/cpp/zengine /home/john/Programming/cpp/zengine/CMakeFiles/zengine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zengine.dir/depend
