# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_SOURCE_DIR = /home/qianwang/codebase/rtb5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/qianwang/codebase/rtb5

# Include any dependencies generated for this target.
include proto/CMakeFiles/campaign_pb.dir/depend.make

# Include the progress variables for this target.
include proto/CMakeFiles/campaign_pb.dir/progress.make

# Include the compile flags for this target's objects.
include proto/CMakeFiles/campaign_pb.dir/flags.make

proto/click.pb.h: proto/click.proto
proto/click.pb.h: proto/campaign.proto
proto/click.pb.h: proto/union.proto
proto/click.pb.h: proto/user.proto
proto/click.pb.h: proto/order.proto
	$(CMAKE_COMMAND) -E cmake_progress_report /home/qianwang/codebase/rtb5/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating click.pb.h, click.pb.cc, campaign.pb.h, campaign.pb.cc, union.pb.h, union.pb.cc, user.pb.h, user.pb.cc, order.pb.h, order.pb.cc, proto"
	cd /home/qianwang/codebase/rtb5/proto && protoc -I . --cpp_out . click.proto campaign.proto union.proto user.proto order.proto

proto/click.pb.cc: proto/click.pb.h

proto/campaign.pb.h: proto/click.pb.h

proto/campaign.pb.cc: proto/click.pb.h

proto/union.pb.h: proto/click.pb.h

proto/union.pb.cc: proto/click.pb.h

proto/user.pb.h: proto/click.pb.h

proto/user.pb.cc: proto/click.pb.h

proto/order.pb.h: proto/click.pb.h

proto/order.pb.cc: proto/click.pb.h

proto/proto: proto/click.pb.h

proto/CMakeFiles/campaign_pb.dir/campaign.pb.cc.o: proto/CMakeFiles/campaign_pb.dir/flags.make
proto/CMakeFiles/campaign_pb.dir/campaign.pb.cc.o: proto/campaign.pb.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/qianwang/codebase/rtb5/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object proto/CMakeFiles/campaign_pb.dir/campaign.pb.cc.o"
	cd /home/qianwang/codebase/rtb5/proto && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/campaign_pb.dir/campaign.pb.cc.o -c /home/qianwang/codebase/rtb5/proto/campaign.pb.cc

proto/CMakeFiles/campaign_pb.dir/campaign.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/campaign_pb.dir/campaign.pb.cc.i"
	cd /home/qianwang/codebase/rtb5/proto && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/qianwang/codebase/rtb5/proto/campaign.pb.cc > CMakeFiles/campaign_pb.dir/campaign.pb.cc.i

proto/CMakeFiles/campaign_pb.dir/campaign.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/campaign_pb.dir/campaign.pb.cc.s"
	cd /home/qianwang/codebase/rtb5/proto && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/qianwang/codebase/rtb5/proto/campaign.pb.cc -o CMakeFiles/campaign_pb.dir/campaign.pb.cc.s

proto/CMakeFiles/campaign_pb.dir/campaign.pb.cc.o.requires:
.PHONY : proto/CMakeFiles/campaign_pb.dir/campaign.pb.cc.o.requires

proto/CMakeFiles/campaign_pb.dir/campaign.pb.cc.o.provides: proto/CMakeFiles/campaign_pb.dir/campaign.pb.cc.o.requires
	$(MAKE) -f proto/CMakeFiles/campaign_pb.dir/build.make proto/CMakeFiles/campaign_pb.dir/campaign.pb.cc.o.provides.build
.PHONY : proto/CMakeFiles/campaign_pb.dir/campaign.pb.cc.o.provides

proto/CMakeFiles/campaign_pb.dir/campaign.pb.cc.o.provides.build: proto/CMakeFiles/campaign_pb.dir/campaign.pb.cc.o

# Object files for target campaign_pb
campaign_pb_OBJECTS = \
"CMakeFiles/campaign_pb.dir/campaign.pb.cc.o"

# External object files for target campaign_pb
campaign_pb_EXTERNAL_OBJECTS =

lib/libcampaign_pb.a: proto/CMakeFiles/campaign_pb.dir/campaign.pb.cc.o
lib/libcampaign_pb.a: proto/CMakeFiles/campaign_pb.dir/build.make
lib/libcampaign_pb.a: proto/CMakeFiles/campaign_pb.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library ../lib/libcampaign_pb.a"
	cd /home/qianwang/codebase/rtb5/proto && $(CMAKE_COMMAND) -P CMakeFiles/campaign_pb.dir/cmake_clean_target.cmake
	cd /home/qianwang/codebase/rtb5/proto && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/campaign_pb.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
proto/CMakeFiles/campaign_pb.dir/build: lib/libcampaign_pb.a
.PHONY : proto/CMakeFiles/campaign_pb.dir/build

proto/CMakeFiles/campaign_pb.dir/requires: proto/CMakeFiles/campaign_pb.dir/campaign.pb.cc.o.requires
.PHONY : proto/CMakeFiles/campaign_pb.dir/requires

proto/CMakeFiles/campaign_pb.dir/clean:
	cd /home/qianwang/codebase/rtb5/proto && $(CMAKE_COMMAND) -P CMakeFiles/campaign_pb.dir/cmake_clean.cmake
.PHONY : proto/CMakeFiles/campaign_pb.dir/clean

proto/CMakeFiles/campaign_pb.dir/depend: proto/click.pb.h
proto/CMakeFiles/campaign_pb.dir/depend: proto/click.pb.cc
proto/CMakeFiles/campaign_pb.dir/depend: proto/campaign.pb.h
proto/CMakeFiles/campaign_pb.dir/depend: proto/campaign.pb.cc
proto/CMakeFiles/campaign_pb.dir/depend: proto/union.pb.h
proto/CMakeFiles/campaign_pb.dir/depend: proto/union.pb.cc
proto/CMakeFiles/campaign_pb.dir/depend: proto/user.pb.h
proto/CMakeFiles/campaign_pb.dir/depend: proto/user.pb.cc
proto/CMakeFiles/campaign_pb.dir/depend: proto/order.pb.h
proto/CMakeFiles/campaign_pb.dir/depend: proto/order.pb.cc
proto/CMakeFiles/campaign_pb.dir/depend: proto/proto
	cd /home/qianwang/codebase/rtb5 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qianwang/codebase/rtb5 /home/qianwang/codebase/rtb5/proto /home/qianwang/codebase/rtb5 /home/qianwang/codebase/rtb5/proto /home/qianwang/codebase/rtb5/proto/CMakeFiles/campaign_pb.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : proto/CMakeFiles/campaign_pb.dir/depend
