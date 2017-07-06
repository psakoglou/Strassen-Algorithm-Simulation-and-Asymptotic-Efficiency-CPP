/*
*	© Superharmonic Technologies
*	Pavlos Sakoglou
*
*  =====================================================================================
*
*	Auxiliary functions to set up the application: 
*		matrix operations +, -
*		print()
*		intiliaze()
*		randomize()
*
*/

// Multiple inclusion guards
#ifndef AUX_HPP
#define AUX_HPP

#include <iostream>
#include <chrono>
#include <random>

// Aliases
using type = int;
using Matrix = type * *;
using size = std::size_t;


// Randomize matrix function
void randomize(Matrix &A, size N) {	// O(n^2)
	std::uniform_int<int> dist(1, 5);
	std::mt19937 eng;
	for (unsigned int i = 0; i < N; i++) {
		for (unsigned int j = 0; j < N; j++) {
			eng.seed((double)std::chrono::system_clock::now().time_since_epoch().count());
			A[i][j] = dist(eng);
		}
	}
}


// Print function
void print(Matrix A, size N) {	// O(n^2)
	for (unsigned int i = 0; i < N; i++) {
		for (unsigned int j = 0; j < N; j++) {
			std::cout << A[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}


// Returns a new NxN matrix
Matrix createMatrix(size N) {
	Matrix newMatrix = new type *[N];
	for (unsigned int i = 0; i < N; i++) {
		newMatrix[i] = new type[N];
	}
	return newMatrix;
}


/***** Matrix Operations *******/


// Add two matrices
Matrix add(Matrix A, Matrix B, size N) {

	Matrix C = createMatrix(N);

	for (unsigned int i = 0; i < N; i++)
		for (unsigned int j = 0; j < N; j++)
			C[i][j] = A[i][j] + B[i][j];

	return C;
}

// Subtract two matrices
Matrix subtract(Matrix A, Matrix B, size N) {
	Matrix C = createMatrix(N);

	for (unsigned int i = 0; i < N; i++)
		for (unsigned int j = 0; j < N; j++)
			C[i][j] = A[i][j] - B[i][j];

	return C;
}


#endif // !AUX_HPP
