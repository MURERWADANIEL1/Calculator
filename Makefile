# Minimal Makefile that delegates to CMake for the normal build
# Keeps a `quick` target for fast, ad-hoc g++ builds when you don't want to run CMake.

CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2
CMAKE_BUILD_DIR ?= build

SRC := SimpleCalculator.cpp \
       modules/basicmath.cpp \
       modules/trigonometry.cpp \
       modules/logarithms.cpp \
       modules/vectors.cpp \
       modules/matrices.cpp \
       modules/complexnumbers.cpp \
       modules/booleanalgebra.cpp \
       modules/integrals.cpp \
       modules/derivatives.cpp \
       modules/numericalmethods.cpp

.PHONY: all configure build quick clean install

all: configure build

# Configure step — runs cmake to generate build system in $(CMAKE_BUILD_DIR)
configure:
	@echo "Configuring project with CMake (in $(CMAKE_BUILD_DIR))..."
	@mkdir -p $(CMAKE_BUILD_DIR)
	@cd $(CMAKE_BUILD_DIR) && cmake .. -DCMAKE_BUILD_TYPE=Release

# Build step — builds the project using CMake
build: configure
	@echo "Building project using CMake..."
	@cmake --build $(CMAKE_BUILD_DIR) --config Release
	@echo "Build output: $(CMAKE_BUILD_DIR)/calculator"

# Quick direct compile without CMake (useful for fast local iterations)
quick:
	$(CXX) $(CXXFLAGS) $(SRC) -o calculator
	@echo "Built './calculator' using g++ (quick build)."

# Install (delegates to CMake install if provided)
install: build
	@echo "Installing (via CMake install if configured)..."
	@cmake --install $(CMAKE_BUILD_DIR) --config Release || true

# Clean build artifacts
clean:
	@echo "Cleaning build artifacts..."
	rm -rf $(CMAKE_BUILD_DIR) calculator *.o

