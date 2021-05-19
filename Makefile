include  specificMakefile.mk
SHELL := /bin/bash
#set -e
INCLUDES  :=  -I$(BOOST_INCLUDEDIR)
LIBRARIES := -L$(BOOST_LIBRARYDIR)
SRC_DIR := ./src
OBJ_DIR := ./obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
LDFLAGS := $(LIBRARIES) -lboost_system -lboost_program_options
CPPFLAGS := -g -Wall -std=c++11  $(INCLUDES) 
CXXFLAGS :=
EXE_FILE_NAME ?= main.out
EXE_COMMAND  ?= ./$(EXE_FILE_NAME)
EXTRA_COMPILE_OPTIONS  ?=-DUSE_THE_MAIN_MAIN
all: build

testEcdcho:
	echo $(OBJ_FILES) 
	echo $(SRC_DIR)

$(EXE_FILE_NAME): $(OBJ_FILES) 
	g++ $(LDFLAGS) -o $@ $^
	
loadModules:
	bash -c "module load boost"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp loadModules
	g++ $(CPPFLAGS)  $(CXXFLAGS) $(EXTRA_COMPILE_OPTIONS) $(CONFIGURATION_COMPILE_OPTIONS) -fmax-errors=5 -c -o $@ $<
build: $(EXE_FILE_NAME)
########################Main program
run:compile	
	$(EXE_COMMAND) $(COMMAND_LINE_OPTIONS)

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(EXE_FILE_NAME)
	mkdir obj
	
release:
	cp $(EXE_FILE_NAME) bin/$(EXE_FILE_NAME)
	
compile: $(EXE_FILE_NAME)


.DEFAULT_GOAL := compile