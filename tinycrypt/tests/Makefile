# ------------------------------------------------
# @author Adrian Szczepanski
# @date 06-03-2023
# ------------------------------------------------

# Target
tested_library_name := tinycrypt

# Directories
project_dir ?= ../..
make_dir := $(project_dir)/make
external_dir := $(project_dir)/external

# Sources 
cxx_sources :=  \
$(wildcard *.cpp) \

c_sources := \
$(wildcard *.c) \

# Includes
cxx_includes := \
-I. \

# Defines
cxx_defs := \
-DENABLE_TESTS

use_gcc_for_c_files := 1

# Append rest of Makefile from template
include $(make_dir)/SoftwareTestLib.mk