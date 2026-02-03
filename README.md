# Calculator Project 

**A modular, extensible C++ command-line calculator** designed to handle a wide range of mathematical operations from basic arithmetic to advanced linear algebra and complex numbers.

---

## Table of Contents
- Overview
- Features
- Getting Started
- Usage
- Roadmap
- Contributing
- License

## Overview

This project is a modular and extensible calculator built in C++. It serves as a powerful tool for evaluating mathematical expressions involving various data types, including scalars, vectors, matrices, and complex numbers. The architecture is designed to support future expansions into calculus and numerical analysis.

## Features

### Core Capabilities
- **Basic Arithmetic**: Support for addition, subtraction, multiplication, division (`+`, `-`, `*`, `/`) with correct precedence.
- **Trigonometry**: Standard trigonometric functions (`sin`, `cos`, `tan`) and their inverses. Supports degrees and radians.
- **Linear Algebra**:
  - **Vectors**: Operations including addition, dot product, cross product, and normalization.
  - **Matrices**: Matrix multiplication, transposition, determinant calculation, and inversion.
- **Number Bases**: Native support for Binary (`0b...`) and Hexadecimal (`0x...`) input and conversion.
- **Boolean Algebra**: Logical operators (`AND`, `OR`, `NOT`, `XOR`) for boolean expressions.
- **Complex Numbers**: Arithmetic operations for real and imaginary numbers (e.g., `3 + 4i`).

### Advanced Math (Planned)
- **Calculus**: Symbolic differentiation and numerical integration.
- **Numerical Computations**: Advanced algorithms for solving equations and optimization problems.

## Getting Started

### Prerequisites
- A C++ compiler compatible with C++17 (e.g., GCC, Clang, MSVC).

### Installation & Build

1. **Clone the repository:**
   ```sh
   git clone https://github.com/MURERWADANIEL1/Calculator
   cd Calculator
   ```

2. **Quick compile (single command)** — useful for quick tests or if you don't use CMake:
   ```bash
   g++ -std=c++17 -O2 -Wall SimpleCalculator.cpp modules/*.cpp -o calculator
   # or use the provided Makefile
   make
   ```

3. **Recommended: Build with CMake (recommended for development)**
   ```bash
   mkdir -p build
   cd build
   cmake .. -DCMAKE_BUILD_TYPE=Release
   cmake --build .
   ```

4. **Run the calculator:**
   ```sh
   ./calculator
   ```

## Project Structure

- `SimpleCalculator.cpp` — the program entry point and the menu dispatcher. It includes headers from `modules/` and calls module entry functions.
- `modules/` — each feature has its own pair of files: `modules/<feature>.h` (declaration) and `modules/<feature>.cpp` (implementation). This keeps features isolated and easy to extend.
- `Makefile` — simple build helper for quick builds.
- `CMakeLists.txt` — recommended cross-platform build configuration (preferred for development and CI).

### Adding a new module
1. Add `modules/<feature>.h` with a function declaration, e.g. `void performFeature();`.
2. Implement the function in `modules/<feature>.cpp`.
3. `#include "modules/<feature>.h"` in `SimpleCalculator.cpp` and add an entry to the `menu` map (e.g. `{"11", performFeature}`).
4. Rebuild with `make` or `cmake --build .`.

This modular layout makes it easy to work on one feature at a time, speeds up incremental compilation, and simplifies testing and maintenance.

## Usage

The calculator provides a menu-driven interface for different mathematical modes.

### Examples

**Basic Arithmetic:**
The basic arithmetic mode operates on a sequence of numbers.
```text
Enter operation (+, -, *, /) or command (b, q): +
Enter first number: 10
Enter next number or '=' to finish: 5
Enter next number or '=' to finish: 2
Enter next number or '=' to finish: =
Final Result: 17
```

**Trigonometry:**
```text
> sin(90)
1
```

**Vector Operations:**
```text
> [1, 2, 3] + [4, 5, 6]
[5, 7, 9]
```

**Matrix Multiplication:**
```text
> [[1, 2], [3, 4]] * [[0, 1], [1, 0]]
[[2, 1], [4, 3]]
```

**Complex Numbers:**
```text
> (3 + 2i) + (1 - 4i)
4 - 2i
```

**Boolean Logic:**
```text
> true AND false
false
```

##  Roadmap

The development plan includes the following milestones:

- [ ] Phase 1: Implement Basic Arithmetic.
- [ ] Phase 2: Implement Trigonometry.
- [ ] Phase 3: Implement Logarithms.
- [ ] Phase 4: Robust parsing for all basic types (Scalar, Vector, Matrix).
- [ ] Phase 5: Implementation of Complex number arithmetic and Boolean logic.
- [ ] Phase 6: Integration of Calculus module (Derivatives, Integrals).
- [ ] Phase 7: Advanced Numerical Methods (Root finding, Interpolation).


##  Contributing

Contributions are welcome! Please read `CONTRIBUTING.md` for details on our code of conduct and the process for submitting pull requests.

## License

This project is licensed under the MIT License.