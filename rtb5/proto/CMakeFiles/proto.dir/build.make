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

# Utility rule file for proto.

# Include the progress variables for this target.
include proto/CMakeFiles/proto.dir/progress.make

proto/CMakeFiles/proto: proto/click.pb.h
proto/CMakeFiles/proto: proto/click.pb.cc
proto/CMakeFiles/proto: proto/campaign.pb.h
proto/CMakeFiles/proto: proto/campaign.pb.cc
proto/CMakeFiles/proto: proto/union.pb.h
proto/CMakeFiles/proto: proto/union.pb.cc
proto/CMakeFiles/proto: proto/user.pb.h
proto/CMakeFiles/proto: proto/user.pb.cc
proto/CMakeFiles/proto: proto/order.pb.h
proto/CMakeFiles/proto: proto/order.pb.cc

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

proto: proto/CMakeFiles/proto
proto: proto/click.pb.h
proto: proto/click.pb.cc
proto: proto/campaign.pb.h
proto: proto/campaign.pb.cc
proto: proto/union.pb.h
proto: proto/union.pb.cc
proto: proto/user.pb.h
proto: proto/user.pb.cc
proto: proto/order.pb.h
proto: proto/order.pb.cc
proto: proto/proto
proto: proto/CMakeFiles/proto.dir/build.make
.PHONY : proto

# Rule to build all files generated by this target.
proto/CMakeFiles/proto.dir/build: proto
.PHONY : proto/CMakeFiles/proto.dir/build

proto/CMakeFiles/proto.dir/clean:
	cd /home/qianwang/codebase/rtb5/proto && $(CMAKE_COMMAND) -P CMakeFiles/proto.dir/cmake_clean.cmake
.PHONY : proto/CMakeFiles/proto.dir/clean

proto/CMakeFiles/proto.dir/depend:
	cd /home/qianwang/codebase/rtb5 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qianwang/codebase/rtb5 /home/qianwang/codebase/rtb5/proto /home/qianwang/codebase/rtb5 /home/qianwang/codebase/rtb5/proto /home/qianwang/codebase/rtb5/proto/CMakeFiles/proto.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : proto/CMakeFiles/proto.dir/depend

