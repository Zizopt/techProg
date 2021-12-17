#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "dopF.h"
#include "mat/multM.h"
#include "mat/multMElem.h"
#include <boost/program_options.hpp>

using namespace std;

int main(int argc, const char *argv[])
{
	setlocale(LC_ALL, "rus");
	using namespace boost::program_options;

	double **A=0, **B=0;

	string fileNameA, fileNameB;
	int act = 0;
	int nA=0, nB=0, mA=0, mB=0;
	try//работа через командную строку
	{
		

		store(parse_command_line(argc, argv, desc), vm);
		notify(vm);
		if (vm.count("help")){
			std::cout << desc << '\n';
			return 0;
		}

		if (vm.count("inputA"))
		{
			cout << "\nВведите матрицу A:";
			nA = vm["nA"].as<int>();
			mA = vm["mA"].as<int>();
			A = inputM(nA, mA);
		}
		else if (vm.count("fileA")) {
			fileNameA= vm["fileA"].as<string>();
			nA = vm["nA"].as<int>();
			mA = vm["mA"].as<int>();
			A=inputFM(fileNameA, nA, mA);
		} 

		if (vm.count("inputB"))
		{
			cout << "\nВведите матрицу B:";
			nB = vm["nB"].as<int>();
			mB = vm["mB"].as<int>();
			B = inputM(nB, mB);
		}
		else if (vm.count("fileB")) {
			fileNameB = vm["fileB"].as<string>();
			nB = vm["nB"].as<int>();
			mB = vm["mB"].as<int>();
			B = inputFM(fileNameB, nB, mB);
		}
		if (vm.count("action"))
		{
			string action = vm["action"].as<string>();
			if (action == "*")
				act = 0;
			else if (action == ".*")
				act = 1;
		}
	}
	catch (const error& ex)
	{
		std::cerr << ex.what() << '\n';
	}
	/*
	nA = 3;
	mA = 4;
	nB = 4;
	mB = 3;
	A = inputFM("./A.txt", nA, mA);
	B = inputFM("./B.txt", nB, mB);
	*/
	if (A == 0 || B == 0) {
		cout << "\nМатрицы не введены!\n";
		return 1;
	}
	else if (nA == 0 || mA == 0 || nB == 0 || mB == 0) {
		cout << "\nРазмеры матриц не введены!\n";
		return 1;
	}

	cout << endl;
	cout << "Матрица A:" << endl;
	outputM(A, nA, mA);
	cout << "Матрица B:" << endl;
	outputM(B, nB, mB);

	int nC = nA, mC = mA;
	double** C=0;
	if (act == 0) {
		C = multM(A, nA, mA, B, nB, mB, nC, mC);
	}
	else if (act == 1) {
		C = multMElem(A, nA, mA, B, nB, mB);
	}
	if (C == 0) {
		cout << "\nНе соответствие размеров матриц!\n";
		return 1;
	}
	cout << "Матрица C:" << endl;
	outputM(C, nC, mC);

	deleteM(A, nA, mA);
	deleteM(B, nB, mB);
	deleteM(C, nC, mC);
}
