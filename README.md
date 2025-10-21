# cp_course_aca

This repository is a personal collection of C and C++ solutions, exercises, and small utilities for competitive programming and coursework.

## Goals

- Keep small, self-contained C and C++ programs organized and easy to build.
- Provide conventions and examples so code is reproducible on any Linux/macOS/Windows (WSL) environment.

## Recommended repository layout

Organize your code into folders by topic or language. Example:

- `c/` — C source files and C-specific helpers
- `cpp/` — C++ source files and C++-specific helpers
- `algorithms/` — algorithm implementations (subfolders by topic)
- `problems/` — solved contest/problem files
- `tools/` — helper scripts, Makefiles, test runners

You can also keep single-file programs at the root for quick experiments.

## File naming conventions

- Use descriptive names, e.g. `binary_search.cpp`, `bubble_sort.c`.
- Prefer lowercase and underscores: `problem_name.cpp`.
- If a problem comes from an online judge, include the source or problem id: `cf_1234A.cpp`.

## How to compile

Quick single-file compile (C):

```bash
gcc -O2 -std=c17 -Wall -Wextra -o program program.c
```

Quick single-file compile (C++):

```bash
g++ -O2 -std=c++17 -Wall -Wextra -o program program.cpp
```

Compile all `.cpp` files in a folder (simple):

```bash
g++ -O2 -std=c++17 -Wall -Wextra -Iinclude -o all_programs *.cpp
```

A minimal Makefile to build one target (drop into a folder):

```Makefile
CC := g++
CFLAGS := -O2 -std=c++17 -Wall -Wextra
SRC := $(wildcard *.cpp)
OBJ := $(SRC:.cpp=.o)
TARGET := program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
```

## Running programs

After compiling, run the binary directly:

```bash
./program
```

For competitive programming, use input redirection:

```bash
./program < input.txt > output.txt
```

## Editor / tooling suggestions

- Add a simple `tasks.json` or small Makefile for VS Code to build quickly.
- Use clang-format for consistent formatting.
- Add a `.gitignore` to exclude build artifacts (binaries, object files).

Example `.gitignore` entries:

```
*.o
*.out
program
build/
.vscode/
```

## Contributing / Personal notes

This is mainly a personal repo. Keep commits small and descriptive. If you reuse code between tasks, factor helpers into `include/` or `tools/`.

## License

You can add a license if you want to share this publicly (MIT is common for small code collections).

---

If you'd like, I can:

- add a starter Makefile at the repo root,
- create `c/` and `cpp/` folders and move files into them,
- add a `tasks.json` for VS Code to build C/C++ files.

Tell me which of those you'd like next.