# ------------------------------------------------
# @author Adrian Szczepanski
# @date 06-03-2023
# ------------------------------------------------

# Target
tested_library_name := tinycryptpp

# Directories
project_dir ?= ../..
make_dir := $(project_dir)/make
external_dir := $(project_dir)/external

# Sources 
cxx_sources :=  \
$(wildcard *.cpp) \
$(wildcard aes/*.cpp) \

# Includes
cxx_includes := \
-I. \
-I$(project_dir)/tinycrypt \

# Defines
cxx_defs := \

external_library_flags := \
-ltinycrypt

# Append rest of Makefile from template
include $(make_dir)/SoftwareTestLib.mk