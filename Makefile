# ============================================================================
#  Jay's C++ DSA Library - Makefile
#
#  make                   build everything (menu + every standalone test)
#  make run               build and launch the interactive test menu (main.cpp)
#  make test              build and run every test bench, one after another
#  make test_<name>       build and run one test bench, e.g. make test_array_list
#  make list              show the test names you can use with test_<name>
#  make clean             delete everything this Makefile built
# ============================================================================

# ---- Compiler settings ------------------------------------------------------
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -g
# -MMD -MP: while compiling, also write a .d file listing every header the .cpp
# included, so editing a .h/.tpp makes make rebuild the files that use it.
DEPFLAGS := -MMD -MP

# One folder per data structure. Each one is added as an include path (-I),
# so code can just write #include "linked_list.h" from any folder.
MODULES  := array_list linked_list hash_map stack
INCLUDES := -I. $(addprefix -I,$(MODULES))

# ---- Test benches -----------------------------------------------------------
# To add a new test: create <folder>/<name>_test.cpp that defines a function,
# declare that function in test_bench.h, then add <name> to TESTS and a
# FN_<name> line saying which function to call.
TESTS := array_list linked_list hash_map_chaining hash_map_OA stack

FN_array_list        := ArrayListTest
FN_linked_list       := LinkedListTest
FN_hash_map_chaining := HashMapChainingTest
FN_hash_map_OA       := HashMapOATest
FN_stack             := StackTest

# ---- Output locations -------------------------------------------------------
# Only build/obj and build/bin belong to this Makefile; the rest of build/ is
# left alone (the VS Code C/C++ Runner extension uses build/Debug and build/Release).
OBJ_DIR := build/obj
BIN_DIR := build/bin
EXE     := $(if $(filter Windows_NT,$(OS)),.exe,)

# Maps a test name to its source file, e.g. hash_map_OA -> hash_map/hash_map_OA_test.cpp
test_src  = $(wildcard */$(1)_test.cpp)
test_obj  = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(call test_src,$(1)))
TEST_SRCS := $(foreach t,$(TESTS),$(call test_src,$(t)))
TEST_OBJS := $(TEST_SRCS:%.cpp=$(OBJ_DIR)/%.o)

MENU      := $(BIN_DIR)/dsa_menu$(EXE)
TEST_BINS := $(TESTS:%=$(BIN_DIR)/test_%$(EXE))

# ---- Top-level commands -----------------------------------------------------
.PHONY: all run test list clean $(TESTS:%=test_%)
.DEFAULT_GOAL := all
MAKEFLAGS += --no-builtin-rules
# Keep the .o files make builds along the way (otherwise it deletes the runner objects).
.SECONDARY:

all: $(MENU) $(TEST_BINS)

run: $(MENU)
	./$(MENU)

# Runs every test bench; stops at the first one that crashes or exits non-zero.
test: $(TEST_BINS)
	@for t in $(TESTS); do \
	    echo; echo "################ $$t ################"; \
	    ./$(BIN_DIR)/test_$$t$(EXE) || exit 1; \
	done

# make test_array_list, make test_stack, ...
$(TESTS:%=test_%): test_%: $(BIN_DIR)/test_%$(EXE)
	./$<

list:
	@echo "Available tests (run with: make test_<name>):"
	@for t in $(TESTS); do echo "  $$t"; done

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# ---- Linking ----------------------------------------------------------------
# The menu = main.cpp + every test bench.
$(MENU): $(OBJ_DIR)/main.o $(TEST_OBJS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $^ -o $@

# A standalone test = test_runner.cpp (built for that test) + that one test bench.
.SECONDEXPANSION:
$(BIN_DIR)/test_%$(EXE): $(OBJ_DIR)/runner_%.o $$(call test_obj,$$*)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $^ -o $@

# ---- Compiling --------------------------------------------------------------
# Any .cpp -> matching .o under build/obj, keeping the folder structure.
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) $(INCLUDES) -c $< -o $@

# test_runner.cpp is compiled once per test, with TEST_FN set to that test's function.
$(OBJ_DIR)/runner_%.o: test_runner.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) $(INCLUDES) -DTEST_FN=$(FN_$*) -c $< -o $@

# Pull in the header dependency lists written by -MMD (missing on a first build, which is fine).
-include $(wildcard $(OBJ_DIR)/*.d $(OBJ_DIR)/*/*.d)
