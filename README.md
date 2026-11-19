# cpp-template

Base template for C++ projects: CMake, clang-format, clang-tidy, clangd and pre-commit, with `src/` and `include/` at the root.

## First steps after "Use this template"

1. Rename the project in `CMakeLists.txt`: `project(app LANGUAGES CXX)`. The executable gets the same name. Do not use a reserved CMake target name (`all`, `test`, `install`, `clean`, `run`).
2. Write `src/main.cpp`. The project does not configure until `src/` has at least one `.cpp` file.
3. Enable the hooks: `pre-commit install`.

## Build and run

```sh
cmake -S . -B build
cmake --build build --target run
```

New `.cpp` files in `src/` are picked up automatically on the next build. Headers go in `include/`.

VS Code tasks: `CMake: Configure`, `CMake: Build`, `Run`.

## Requirements

- CMake 3.20+, a C++20 compiler, Linux with a single-config generator (Make or Ninja).
- LLVM/clang 19 (`clang-tidy`, `clangd`), so editor formatting matches the pinned pre-commit `clang-format` v19.1.7.
- `pre-commit`.

## Tooling

- `.clang-format`: LLVM style, indent 4.
- `.clang-tidy`: bugprone, performance, readability and modernize checks, with naming rules (CamelCase types, lower_case functions/variables, UPPER_CASE constexpr). Only headers under the project's `src/`/`include/` are checked; `build/` is excluded.
- `.clangd`: uses `build/compile_commands.json`.
- pre-commit: clang-format on every C/C++ file; clang-tidy on `src/*.cpp` whenever something in `src/` or `include/` changes, configuring `build/` first if needed.

## Ownership

See `AGENTS.md`: this is a learning setup, and agents do not write C++ source.
