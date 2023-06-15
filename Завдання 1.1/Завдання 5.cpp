
#include <iostream>
#include <math.h>

#pragma warning(disable : 4996)

#include "myfunc.h"
using namespace std;

void task_5_1() {
	double P[3][6] = { {7.2,  3.6,  4.8,  6.3,  0, 3.2 },
						{4.5, 2.3, -5.1, 1.3, 8.1, 0},
						{6.3, -2.4, 8.4, 0, 1.6, 1.5} };
	// Для кожної стрічки матриці P знайти та надрукувати суму елементів з парними номерами.

	for (int i = 0; i < 3; i++) {
		double s = 0;
		for (int j = 0; j < 6; j++)
			if (not ((j + 1) % 2))
				s += P[i][j];
		cout << i + 1 << " : " << s << endl;

	}
}

void task_5_2() {
	double A[3][4] = { {3, 4, 1.3, 0.7},
					{1, 3, 2.2, 0.8},
					{5, 2, 3.5, 0.6} };
	double X[4] = { 0 };
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++)
			X[j] += A[i][j];

	cout << "X = [";
	for (auto x : X)
		cout << x << ", ";
	cout << "\b\b]" << endl;

}

void task_5_3() {
	int m, n;
input_m_n:
	cout << "write size matrix (m, n) : ";
	cin >> m >> n;
	if (not ((m <= 5) and (n <= 4))) {
		cout << "not valid index m<=5 and n <=4" << endl;
		goto input_m_n;
	}
	// create matrix
	double** A = new double* [m];
	for (int i = 0; i < m; i++) {
		auto row = new double[n] {0};
		A[i] = row;
	}

	cout << "write matrix" << endl;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> A[i][j];

	// prosses matrix
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (((i + j) % 2) == 0)
				A[i][j] = (i * j);

	// print result
	cout << "result :" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << A[i][j] << '\t';
		cout << '\b' << endl;
	}

}

void task_5() {
	int task;
	while (true)
	{
		cout << "select task(0 - exit): ";
		cin >> task;
		switch (task)
		{
		case 1:
			task_5_1();
			break;
		case 2:
			task_5_2();
			break;
		case 3:
			task_5_3();
			break;
		case 0:
			return;
		default:
			break;
		}
	}

}