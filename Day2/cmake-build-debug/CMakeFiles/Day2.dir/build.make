# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\Saxion\Technische Informatica\Datastructures\Advent-Of-Code-2020\Day2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\Saxion\Technische Informatica\Datastructures\Advent-Of-Code-2020\Day2\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\Day2.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Day2.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Day2.dir\flags.make

CMakeFiles\Day2.dir\main.cpp.obj: CMakeFiles\Day2.dir\flags.make
CMakeFiles\Day2.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\Saxion\Technische Informatica\Datastructures\Advent-Of-Code-2020\Day2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Day2.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2017\BUILDT~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Day2.dir\main.cpp.obj /FdCMakeFiles\Day2.dir\ /FS -c "E:\Saxion\Technische Informatica\Datastructures\Advent-Of-Code-2020\Day2\main.cpp"
<<

CMakeFiles\Day2.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Day2.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\BUILDT~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\Day2.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\Saxion\Technische Informatica\Datastructures\Advent-Of-Code-2020\Day2\main.cpp"
<<

CMakeFiles\Day2.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Day2.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\BUILDT~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Day2.dir\main.cpp.s /c "E:\Saxion\Technische Informatica\Datastructures\Advent-Of-Code-2020\Day2\main.cpp"
<<

# Object files for target Day2
Day2_OBJECTS = \
"CMakeFiles\Day2.dir\main.cpp.obj"

# External object files for target Day2
Day2_EXTERNAL_OBJECTS =

Day2.exe: CMakeFiles\Day2.dir\main.cpp.obj
Day2.exe: CMakeFiles\Day2.dir\build.make
Day2.exe: CMakeFiles\Day2.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\Saxion\Technische Informatica\Datastructures\Advent-Of-Code-2020\Day2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Day2.exe"
	"C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Day2.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~2\2017\BUILDT~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Day2.dir\objects1.rsp @<<
 /out:Day2.exe /implib:Day2.lib /pdb:"E:\Saxion\Technische Informatica\Datastructures\Advent-Of-Code-2020\Day2\cmake-build-debug\Day2.pdb" /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Day2.dir\build: Day2.exe

.PHONY : CMakeFiles\Day2.dir\build

CMakeFiles\Day2.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Day2.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Day2.dir\clean

CMakeFiles\Day2.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "E:\Saxion\Technische Informatica\Datastructures\Advent-Of-Code-2020\Day2" "E:\Saxion\Technische Informatica\Datastructures\Advent-Of-Code-2020\Day2" "E:\Saxion\Technische Informatica\Datastructures\Advent-Of-Code-2020\Day2\cmake-build-debug" "E:\Saxion\Technische Informatica\Datastructures\Advent-Of-Code-2020\Day2\cmake-build-debug" "E:\Saxion\Technische Informatica\Datastructures\Advent-Of-Code-2020\Day2\cmake-build-debug\CMakeFiles\Day2.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\Day2.dir\depend
