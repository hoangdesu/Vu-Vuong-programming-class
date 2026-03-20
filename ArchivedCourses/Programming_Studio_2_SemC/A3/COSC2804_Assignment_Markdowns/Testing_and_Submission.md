# COSC2804 - Testing, Code Organization & Submission

## Testing for Correctness
- Use I/O black-box testing via CLI
- Two files per test:
  - `testname.input`
  - `testname.expout`
- Run using:
  ```bash
  ./gen-village --testmode [args] < testname.input > testname.out
  diff -w testname.expout testname.out
  ```

## Test Mode
- Deterministic algorithms (no randomness)
- Example: grid scanning for plots, fixed plot sizes, predictable door placement

## Submission Guidelines
- Submit via GitHub Classroom
- Compile using G++17:
  ```bash
  g++ -Wall -Werror -std=c++17 -O -g -o gen-village ./*.cpp -lmcpp
  ```
- Include README.md and TESTING.md
