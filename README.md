# Solver of quadratic equation
This program is the first task of ISP RAS course.
## Structure
- Main project 
    - src/
      - solver_quadratic_equation.c 
      - equation_lib.c
- Test project
    - tests/
      - tests_from_file.c
      - tests.c
      - test_lib.h
- File with tests
  - file_test.txt

# Run
To run main program

```bash
cmake .
make
./quadratic_equation
```

To run tests

```bash
cmake .
make
./tests
```
To run tests with data from .txt
- The line of test.txt looks like ``` a b c roots x1 x2 ```
- roots = -42 means overflow, roots = -1 means infinite number of roots (value of x1 and x2 do not matter), if roots = 0 then x1 = -1 x2 = -1
- example ```-1 -2 15 2 3.0 -5.0``` or ```1.79769e+308 1.79769e+308 1.79769e+308 -42 0.0 0.0```
- example for liner ```0 1 0 1 0 0``` or
                       ```0 3 -9 1 3 0```
```bash
cmake .
make
./tests_from_file
```
or To run tests from test_lib.h
```bash
cmake .
make
./tests
```

## Documentation
You can watch documentation by opening
```docs/html/index.html ``` in browser.
## OS
 KUbuntu 18.04