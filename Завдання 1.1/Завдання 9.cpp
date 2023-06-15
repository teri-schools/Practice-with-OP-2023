
#include <iostream>
#include <math.h>

#pragma warning(disable : 4996)

#include "myfunc.h"

using namespace std;


void task_9_1() {
	int n = 4, m = 3;
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
		matrix[i] = new int[m];

	cout << "write matrix(4,3):" << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> matrix[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if ((matrix[i][j] < 0) and (matrix[i][j] % 2))
				matrix[i][j] *= 2;

	double* arr = new double[n] {0};
	for (int i = 0; i < n; i++) {
		double s = 0;
		for (int j = 0; j < m; j++)
			if (matrix[i][j] > 0)
				s += log10(matrix[i][j]);
		arr[i] = s;
	}

	cout << "matrix: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << matrix[i][j] << "\t";
		cout << '\b' << endl;
	}

	cout << "arr: " << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << "\t";
	cout << endl;

}


void task_9() {
	task_9_1();
}