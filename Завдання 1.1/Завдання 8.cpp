
#include <iostream>
#include <math.h>

#pragma warning(disable : 4996)

#include "myfunc.h"

using namespace std;

void task_8_1() {
	const int i = 2, k = 6;
	double s = 0;
	for (int l = 2; l <= 12; l++)
		s += pow((-1), l) * (pow(l, 4) - 2) / (pow(l, 2) + 3);

	double y = 1;
	for (int l = i; l <= k; l++)
		y *= (5 * pow(l, 2) - 2 * l + 1) / (3 * l + 5);

	cout << "s = " << s << endl
		<< "y = " << y << endl;
}

void task_8_2() {
	int s = 0;
	for (int x = -5; x <= 15; x++)
		s += x;
	cout << s;
	s = (-5 + 15) / 2 * (15 + 5 + 1);
	cout << s << endl;
}

void task_8_3() {
	double x, y;
	int n;
	cout << "write x, n : ";
	cin >> x >> n;
	if (x > 0) {
		y = 0;
		for (int i = 1; i <= n - 1; i++)
			for (int j = 0; j <= n - 1; j++)
				y += x / (i + j);
	}
	else {
		y = 1;
		for (int i = 0; i <= n - 1; i++)
			y *= pow(i, 3) + x;
		y += x;
	}
	cout << "y = " << y << endl;
}


void task_8() {
	int task;
	while (true)
	{
		cout << "select task(0 - exit): ";
		cin >> task;
		switch (task)
		{
		case 1:
			task_8_1();
			break;
		case 2:
			task_8_2();
			break;
		case 3:
			task_8_3();
			break;
		case 0:
			return;
		default:
			break;
		}
	}

}