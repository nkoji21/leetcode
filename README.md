# leetcode

LeetCode solutions repository

![LeetCode Stats](https://leetcard.jacoblin.cool/nkoji)

## Usage

### 1. Initial Setup

```sh
make init
```

Select your preferred language to create a working file.

### 2. Solve Problems

Edit the working file to solve problems.

```sh
# Run and test
make run
```

### 3. Save Solution

```sh
make sv
```

Enter the problem number (e.g., `17`):
- Saves to `_result/0017.{ext}` (4-digit zero-padded)
- Auto-commits to git
- Resets working file to template

### 4. Change Language

```sh
make setlang
```

Switch to a different language.

## Directory Structure

```
.
├── main.c           # Working file
├── language         # Current language setting
├── Makefile
├── shell/
│   ├── init.sh      # Initial setup
│   ├── setlang.sh   # Language switcher
│   └── solve.sh     # Solution saver
├── _template/       # Language templates
│   ├── c/main.c
│   ├── cpp/main.cpp
│   └── python/main.py
└── _result/         # Saved solutions
    ├── 0001.c
    ├── 0002.c
    └── ...
```
