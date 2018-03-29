/*
*	© Superharmonic Technologies
*	Pavlos Sakoglou
*
*  ==================================================================================
*
*	Asymptotic Comparison of Strassen's Algorithm to the naive algorithm  
*	for matrix multiplication
*
*/

#include <iostream>
#include <chrono>
#include <random>

#include "Strassen.hpp"


// Test
int main() {

	// Simple Test

	// Size
	size N = 8;

	// Matrices
	Matrix A = createMatrix(N), B = createMatrix(N), C = createMatrix(N);

	// Initialize the matrices
	randomize(A, N);
	randomize(B, N);

	// Print their values
	std::cout << "Matrix A:\n";
	print(A, N);

	std::cout << "\n\nMatrix B:\n";
	print(B, N);

	// Compute A * B using Strassen's Algorithm
	C = strassen(A, B, N);

	// Print result
	std::cout << "\n\nResult with Strassen method:\n";
	print(C, N);

	// Compute A * B using a classic multiplication Algorithm
	C = sq_matrix_multiply(A, B, N);

	// Print result
	std::cout << "\n\nResult with classic multiplication method:\n";
	print(C, N);
	std::cout << "\n\n\n";


	/**********************   Simulation   **************************/

	// Simulation and running time analysis

	// Matrix to store the average running times 10x10
	double * * strassen_times = new double *[10];
	double * * classic_mult_times = new double *[10];

	for (size i = 0; i < 10; i++) {
		strassen_times[i] = new double[10];
		classic_mult_times[i] = new double[10];
	}

	double sum1 = 0, sum2 = 0;

	// Chrono objects to measure time
	std::chrono::system_clock::time_point begin, end;

	// Vectors to hold the individual calls' running time
	std::vector<type> running_times1, running_times2;

	std::cout << "\nSimulation begins...\n\n\n";
	// Simulate on sizes NxN, N = { 10, 20, ... , 100 }
	int x = 0;
	for (unsigned int N_ = 10; N_ < 110; N_ += 10) {

		// Dynamically increase the size as per N
		A = createMatrix(N_);
		B = createMatrix(N_);

		// Simulate NSim = { 10k, 20k, 30k, 50k, 60k, 70k, 80k, 90k, 100k }
		int y = 0;
		for (unsigned int NSim = 10; NSim < 110; NSim += 10) {

			for (unsigned int k = 0; k < NSim; k++) {

				// Randomize the matrices
				randomize(A, N_);
				randomize(B, N_);

				// Strassen
				begin = std::chrono::system_clock::now();
				strassen(A, B, N);
				end = std::chrono::system_clock::now();

				// Elapsed running time
				sum1 += std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

				// Classic Multiplication
				begin = std::chrono::system_clock::now();
				sq_matrix_multiply(A, B, N);
				end = std::chrono::system_clock::now();

				// Elapsed running time
				sum2 += std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

			}

			// Store the simulation's overall time
			strassen_times[x][y] = sum1;

			// Store the simulation's overall time
			classic_mult_times[x][y] = sum2;

			sum1 = 0;
			sum2 = 0;

			y++;
		}
		std::cout << N_ << "x" << N_ << ": Complete!\n";
		x++;
	}

	// Print running times:

	// Print Strassen's Overall Running Times
	std::cout << "\n\nStrassen's Algorithm running times for N = 10, ... , 100 :\n\n";
	std::cout << "10k\t20k\t30k\t40k\t50k\t60k\t70k\t80k\t90k\t100k\n\n";
	std::cout.precision(5);
	for (unsigned int i = 0; i < 10; i++) {
		for (unsigned int j = 0; j < 10; j++) {
			std::cout << strassen_times[i][j] << "\t";
		}
	}

	// Print Classic Method's Overall Running Times
	std::cout << "\n\n\n";
	std::cout << "Classic Multiplication running times for N = 10, ... , 100 :\n\n";
	std::cout << "10k\t20k\t30k\t40k\t50k\t60k\t70k\t80k\t90k\t100k\n\n";
	std::cout.precision(5);
	for (unsigned int i = 0; i < 10; i++) {
		for (unsigned int j = 0; j < 10; j++) {
			std::cout << classic_mult_times[i][j] << "\t";
		}
	}

	return 0;
}
