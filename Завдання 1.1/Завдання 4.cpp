
#include <iostream>
#include <math.h>

#pragma warning(disable : 4996)
#include "myfunc.h"

using namespace std;

void task_4_1() {
	double arr[6] = { 2.3, 4.3, -15.2, 1.1, -1.2, -3.3 };
	double mul = 1;
	for (auto itm : arr)
		if (itm > 2)
			mul *= itm;
	cout << "mul item (>2) = " << mul << endl;
}

void task_4_2() {

	double X[13] = { 0.01, -27.3, 0, 125.27, -371.45, 0, 12, -5, -172.3, 0.05, -17.1, 49.5, -0.01 };
	//double a = 5.34;
	int negetive_count = 0;
	int negetive_indexs[13] = { -1 };

	for (int i = 0; i < 13; i++) 
		if (X[i] < 0) {
			negetive_indexs[negetive_count] = i;
			negetive_count += 1;
		}
	
	cout << "negetive_count = " << negetive_count << endl;
	for (int i = 0; i < negetive_count; i++)
		cout << negetive_indexs[i] << '\t';
	cout << endl;
}

void task_4_3() {
	double x[27] = { -8.16, -8.25 };
	const double del_x = 0.9;
	for (int k = 2; k < 27; k++)
		x[k] = x[k - 1] + del_x;

	double g = 0;
	for (int k = 15; k <= 25; k++)
		g += (pow(tan(x[k]), 2)) / (abs(x[k - 1] + x[k + 1]));
	cout << "g = " << g << endl;
}

void task_4() {
	int task;
	while (true)
	{
		cout << "select task(0 - exit): ";
		cin >> task;
		switch (task)
		{
		case 1:
			task_4_1();
			break;
		case 2:
			task_4_2();
			break;
		case 3:
			task_4_3();
			break;
		case 0:
			return;
		default:
			break;
		}
	}

}