# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/marcelo/Documentos/T1-POO

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marcelo/Documentos/T1-POO

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/marcelo/Documentos/T1-POO/CMakeFiles /home/marcelo/Documentos/T1-POO/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/marcelo/Documentos/T1-POO/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named T1_POO

# Build rule for target.
T1_POO: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 T1_POO
.PHONY : T1_POO

# fast build rule for target.
T1_POO/fast:
	$(MAKE) -f CMakeFiles/T1_POO.dir/build.make CMakeFiles/T1_POO.dir/build
.PHONY : T1_POO/fast

Cliente.o: Cliente.cpp.o

.PHONY : Cliente.o

# target to build an object file
Cliente.cpp.o:
	$(MAKE) -f CMakeFiles/T1_POO.dir/build.make CMakeFiles/T1_POO.dir/Cliente.cpp.o
.PHONY : Cliente.cpp.o

Cliente.i: Cliente.cpp.i

.PHONY : Cliente.i

# target to preprocess a source file
Cliente.cpp.i:
	$(MAKE) -f CMakeFiles/T1_POO.dir/build.make CMakeFiles/T1_POO.dir/Cliente.cpp.i
.PHONY : Cliente.cpp.i

Cliente.s: Cliente.cpp.s

.PHONY : Cliente.s

# target to generate assembly for a file
Cliente.cpp.s:
	$(MAKE) -f CMakeFiles/T1_POO.dir/build.make CMakeFiles/T1_POO.dir/Cliente.cpp.s
.PHONY : Cliente.cpp.s

ContaCorrente.o: ContaCorrente.cpp.o

.PHONY : ContaCorrente.o

# target to build an object file
ContaCorrente.cpp.o:
	$(MAKE) -f CMakeFiles/T1_POO.dir/build.make CMakeFiles/T1_POO.dir/ContaCorrente.cpp.o
.PHONY : ContaCorrente.cpp.o

ContaCorrente.i: ContaCorrente.cpp.i

.PHONY : ContaCorrente.i

# target to preprocess a source file
ContaCorrente.cpp.i:
	$(MAKE) -f CMakeFiles/T1_POO.dir/build.make CMakeFiles/T1_POO.dir/ContaCorrente.cpp.i
.PHONY : ContaCorrente.cpp.i

ContaCorrente.s: ContaCorrente.cpp.s

.PHONY : ContaCorrente.s

# target to generate assembly for a file
ContaCorrente.cpp.s:
	$(MAKE) -f CMakeFiles/T1_POO.dir/build.make CMakeFiles/T1_POO.dir/ContaCorrente.cpp.s
.PHONY : ContaCorrente.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/T1_POO.dir/build.make CMakeFiles/T1_POO.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/T1_POO.dir/build.make CMakeFiles/T1_POO.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/T1_POO.dir/build.make CMakeFiles/T1_POO.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... T1_POO"
	@echo "... edit_cache"
	@echo "... Cliente.o"
	@echo "... Cliente.i"
	@echo "... Cliente.s"
	@echo "... ContaCorrente.o"
	@echo "... ContaCorrente.i"
	@echo "... ContaCorrente.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
