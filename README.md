# Strassen Algorithm Simulation and Asymptotic Efficiency in C++

**Description**

Strassen's Algorithm implementation in C++, simulation for NxN cases where N = { 10, ..., 100 } and its asymptotic comparison with the naive matrix multiplication algorithm.

**Strassen's Algorithm**

Strassen's Algorithm is a divide and conquer algorithm that divides input matrices of N = 2^n (dimensions of input must be a power of 2) into four N/2 submatrices, performs simpler multiplications, and finally combines the results into the result matrix. 

It is proven that Strassen's Algorithm runs in O(n^2.8) which asymptotically beats the naive multiplication, which is of O(n^3), by powers of 10 as N -> inf.

**Naive Algorithm**

Iterates to all rows and columns for each element of the result matrix, simply mimicking the mathematical formula for matrix multiplication. It's called naive due to its obvious simplicity. It runs in O(n^3) -> exponential growth as N -> inf.

**Simulation and comparison**

Assymptotically the Strassen's Algorithm running time is:

![Alt text](img/strassen_asymptotic.png?raw=true "Optional Title")

Assymptotically the Naive Algorithm's running time is:

![Alt text](img/naive_asymptotic.png?raw=true "Optional Title")
