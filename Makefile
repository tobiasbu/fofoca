
#######################################################################
# Utils
#######################################################################
# Recursive wildcard
#	$1 - Root directory
# $? - File extensions (.cpp, .c...)
rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

# Replace source file path to destiny file path
#	$1 - Source files
#	$2 - Destiny Directory
#	$3 - Destiny files extension (.o)
replacext = $(foreach T, $1,	\
						$(patsubst 		\
						%$(suffix $T),	\
						$2/%$3,			\
						$(notdir $T)) 	\
					)


#######################################################################
# Standard directories and source config
#######################################################################
ROOT_DIR = $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
BUILD_DIR := ${ROOT_DIR}/build
OBJ_DIR := ${BUILD_DIR}/obj
SRC_DIR := ${ROOT_DIR}/src
INC_DIR := ${ROOT_DIR}/include

# Fofoca lib sources
FF := fofoca
FF_EXE := ${BUILD_DIR}/${FF}
FF_SRC := $(call rwildcard,${SRC_DIR}/ff,*.c)
FF_OBJ := $(call replacext,${FF_SRC},${OBJ_DIR},.o)
FF_INC := $(INC_DIR) $(SRC_DIR)

VPATH := $(VPATH):$(SRC_DIR)/ff

# Toolchain config
CC := gcc
CXX := g++

CFLAGS := -std=gnu17 $(addprefix -I,$(FF_INC))


#######################################################################
# Standard directories and source config
#######################################################################
$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

$(FF_EXE): ${FF_OBJ}
	@$(CC) $(CFLAGS) -o $@ $^

prebuild:
	@echo "Building '${FF}' project"
	@mkdir -p ${BUILD_DIR}
	@mkdir -p ${OBJ_DIR}

build: prebuild $(FF_EXE)
	@echo "Build finish"

run:
	@cd ${ROOT_DIR}/example && $(FF_EXE) source.ff

clean:
	@rm -rf ${BUILD_DIR}

