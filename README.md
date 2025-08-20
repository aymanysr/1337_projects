
## Table of contents
- About
- Repository structure
- Typical Common Core projects (overview)
- How to use this repo
- License & credits

---

## About
The goal of the Common Core is to teach fundamental programming and system skills: C language, memory management, POSIX and Unix tooling, process control, Makefiles, Git workflow, and writing small, well-structured programs that comply with the 42 coding standards (the "Norm"). This repo groups projects and supporting material so you can practice, test, and document your progress.

---

## Repository structure (suggested)
This repository is intentionally flexible. A recommended layout:

- projects/
  - libft/                — reimplementation of a subset of libc (strings, memory, lists)
  - ft_printf/            — printf-like formatting functions
  - get_next_line/        — buffered line reader
  - minishell/            — small shell interpreter (if part of your core)
  - push_swap/            — sorting algorithm project (if in your track)
  - so_long/              — simple 2D game (optional / later stages)
  - born2beroot/          — basic system administration and security (optional)

---

## Typical Common Core projects (brief overview)

- Libft
  - Build a library of commonly used functions (string, memory, linked list helpers).
  - Learning outcomes: C fundamentals, modularization, header usage, static libraries.

- ft_printf
  - Implement a subset of printf formatting.
  - Learning outcomes: variadic functions, formatted output, parsing.

- Get_Next_Line
  - Create a function that returns the next line read from a file descriptor.
  - Learning outcomes: file I/O, static storage across calls, buffer management.

- Minishell
  - Basic shell supporting commands, pipes, redirections, and builtins.
  - Learning outcomes: processes, fork/exec, pipes, signal handling.

- Push_swap
  - Create an efficient algorithm to sort integers using a limited set of ops.
  - Learning outcomes: algorithm design, complexity optimization, stack operations.

- Born2beroot
  - Basic system administration and security practices.
  - Learning outcomes: package management, user permissions, services, hardening.
  - 
---

## How to use this repository

1. Clone
   - git clone https://github.com/aymanysr/1337_projects.git
   - cd 1337_projects

2. Work inside the project directory you want:
   - cd projects/libft
   - Read the subject and the local README.md

3. Build
   - make
   - Standard targets: make, make clean, make fclean, make re
---

## Contact / Author
- Maintainer: aymanysr
- GitHub: https://github.com/aymanysr
