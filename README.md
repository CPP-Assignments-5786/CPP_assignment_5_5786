# Assignment 5 — Deep Copy and Conversion Operators

## Academic Integrity

During work on assignments, you may consult with other students and search for information online. However, it is forbidden to copy complete code segments from external sources, including other students, websites, and AI models (such as ChatGPT).

All assistance received must be reported, whether from other students or online sources, in accordance with the [department's integrity policy](https://www.ariel.ac.il/wp/cs/wp-content/uploads/sites/88/2020/08/Guidelines-for-Academic-Integrity.pdf).
**When using AI tools, you must attach the prompts you entered and the responses received.**

## Overview

This assignment focuses on two core topics:

1. **Deep Copy** — classes that manage dynamic memory (`new[]`) must implement a copy constructor, assignment operator, and destructor that perform deep (independent) copies.
2. **Explicit Conversion Operators** — converting between types using explicit casts, e.g., converting a complex number to `double` (magnitude), `std::string` (text representation), and `bool` (zero/non-zero check).

The assignment is based on a complex number system:
- `Complex` — a complex number with arithmetic, comparison, and explicit conversion operators.
- `ComplexArray` — a dynamic array of `Complex` objects that demonstrates deep copy.

## Requirements

You must implement the following files from scratch:

- **`Complex.hpp`** and **`Complex.cpp`** — the `Complex` class in namespace `complex_math`
- **`ComplexArray.hpp`** and **`ComplexArray.cpp`** — the `ComplexArray` class in namespace `complex_math`
- **`StudentTest.cpp`** — your own test file with at least 20 test cases (different from those in `test.cpp`)

Your implementation must:
- Compile and run without errors
- Pass all tests in `test.cpp`
- Implement correct deep copy semantics in `ComplexArray`

## Files Provided

- **`main.cpp`** — full usage demo with expected output in comments
- **`test.cpp`** — unit tests your implementation must pass
- **`doctest.h`** — testing framework
- **`Makefile`** — build and run commands

## Build and Run

```bash
make              # compile and run the demo
make test         # compile and run the unit tests
make student_test # compile and run your StudentTest.cpp (must have 20+ test cases)
make tidy         # run clang-tidy static analysis
make clean        # remove build artifacts
```

## Submission

Submit all files you created. Verify that your code compiles and runs correctly before submitting.

---

Good luck!