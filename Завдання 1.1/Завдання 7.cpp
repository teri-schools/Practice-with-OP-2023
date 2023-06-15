
#include <iostream>
#include <math.h>

#pragma warning(disable : 4996)

using namespace std;

#include "myfunc.h"


void task_7_1_a() {
	const double start_x = 7.2, end_x = 12, del_x = 0.5;
	for (double x = start_x; x <= end_x; x += del_x)
	{
		double z = (2 * pow(sin(x + 2), 2)) / (pow(x, 2) + 1);
		cout << x << "\t" << z << endl;
	}
}

void task_7_1_b() {
	const double start_x = 0, del_x = 0.1;
	const int max_n = 5;

	double x = start_x, z;
	int n = max_n;
	while (n)
	{
		z = (2 * pow(sin(x + 2), 2)) / (pow(x, 2) + 1);
		cout << x << '\t' << z << endl;

		x += del_x;
		n -= 1;
	}
}

void task_7_1() {
	char task;
	while (1) {
		cout << "select variant task(0 - exit): ";
		cin >> task;
		switch (task)
		{
		case 'a':
			task_7_1_a();
			break;
		case 'b':
			task_7_1_b();
			break;
		case '0':
			return;
		default:
			break;
		}
	}
}

double p(double x, double u) { return pow(log(u * x - 1), 2); }

void task_7_2() {
	double a, b, x, z;
	cout << "write a, b, x : ";
	cin >> a >> b >> x;
	z = (p(x, a) / (2 * sin(x))) - (p(x, b) / (2 * cos(x)));
	cout << "z = " << z << endl;
}



double func(double a, double b, double c, double d, double e) {
	return (a + b + c + d + e) / 5;
}

int func(int* arr, int len) {
	int count = 0;
	for (int i = 0; i < len; i++)
		if (arr[i] % 2)
			count++;
	return count;
}

void task_7_3() {
	double result = func(1.0, 2.0, 3.0, 4.0, 5.0);
	std::cout << "Double func result: " << result << std::endl;

	// Example usage of the int func
	int arr[] = { 1, 2, 3, 4, 5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int count = func(arr, len);
	std::cout << "Int func result: " << count << std::endl;
}



void task_7() {
	int task;
	while (true)
	{
		cout << "select task(0 - exit): ";
		cin >> task;
		switch (task)
		{
		case 1:
			task_7_1();
			break;
		case 2:
			task_7_2();
			break;
		case 3:
			task_7_3();
			break;
		case 0:
			return;
		default:
			break;
		}
	}

}