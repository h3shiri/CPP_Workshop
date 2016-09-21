#include <string>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#include <ctime>
#include <chrono>
#include "Complex.h"
#include "Matrix.hpp"

//std::stack<clock_t> tictoc_stack;
std::stack<std::chrono::time_point<std::chrono::system_clock>> tictoc_stack;

void tic() {
	//tictoc_stack.push(clock());
	tictoc_stack.push(std::chrono::system_clock::now());
}

void toc() {
	// std::cout << "Time elapsed: "
	// 		<< ((double)(clock() - tictoc_stack.top())) / CLOCKS_PER_SEC
	// 		<< std::endl;
	// tictoc_stack.pop();
	std::chrono::duration<double> elapsed_seconds = std::chrono::system_clock::now() - tictoc_stack.top();
	std::cout << "Time elapsed: " << elapsed_seconds.count() << "sec\n";
	tictoc_stack.pop();
}

Matrix<Complex> readComplexMatrix(const std::string &FileName)
{
	std::ifstream instream(FileName.c_str());
	if (!instream.is_open())
	{
		std::cerr<<"Error! Can't open file: "<<FileName<<"."<<std::endl;
	}

	int rowsNum, colsNum;
	
	instream >> rowsNum >> colsNum;
	//std::cout << rowsNum << "," << colsNum << std::endl;
	//colsNum = 10; // THIS SETS THE NUMBER OF THREADS
	//rowsNum = 1000000;

	std::vector<Complex> cells(rowsNum*colsNum);
	unsigned int i=0;
	double real, img;
	while(instream.good())
	{
		instream >> real >> img;
		if (!instream.eof()) {
			//        	std::cout << real << "," << img << std::endl;
			if (i >= cells.size()) {
				break;
			}
			cells[i]=(Complex(real,img));
			i++;
		}
	}
	instream.close();

	return Matrix<Complex>(rowsNum, colsNum, cells);
}

Matrix<Complex> doPlus(const Matrix<Complex>& A, const Matrix<Complex>& B) {
	return (A + B);
}

Matrix<Complex> doMult(const Matrix<Complex>& A, const Matrix<Complex>& B) {
	return (A * B);
}

int main(int argc, char *argv[])
{
	//
	if (argc != 2)
	{
		std::cerr<<"Usage: ParalelChecker <matrix_file>"<<std::endl;
		exit(-1);
	}
	Matrix<Complex>::setParallel(false);

	std::string matrix(argv[1]);

	Matrix<Complex> A = readComplexMatrix(matrix);
	Matrix<Complex> B = A.trans();
	Matrix<Complex> Ra,Rm,Pa,Pm;

	// REG

	std::cout << "regular timing:" << std::endl << std::flush;tic();
	
	tic();
	Ra = doPlus(A,A);
	toc();
	tic();
	Rm = doMult(B,A);
	toc();

	//parl
	std::cout << "parallel timing" << std::endl << std::flush;
	Matrix<Complex>::setParallel(true);

	tic();
	Pa = doPlus(A,A);
	toc();
	tic();
	Pm = doMult(B,A);
	toc();
	

	std::cout << "plus (parl==reg) = " << std::boolalpha << (Pa==Ra) << std::endl;
	std::cout << "mult (parl==reg) = " << std::boolalpha << (Pm==Rm) << std::endl;
	//    std::cout << "plus:\n" << Ra << std::endl;
	//    std::cout << "mult:\n" << Rm << std::endl;

	return 0;
}
