
#include <iostream>
#include <math.h>

#pragma warning(disable : 4996)

using namespace std;
#include "myfunc.h"

struct Worker {
	double T;
	double G;
	double get_Z();
};

double Worker::get_Z() { return this->T * this->G / 8.0; }

void task_3_1() {
	int n;
	cout << "write n=";
	cin >> n;
	Worker* workers = new Worker[n];
	for (int i = 0; i < n; i++)
	{
		Worker* w = new Worker;
		cout << "worker number " << i + 1 << endl;
		cout << "write T, G : ";
		cin >> w->T >> w->G;
		workers[i] = *w;
	}
	double min_z = workers[0].get_Z();
	for (int i = 0; i < n; i++)
	{
		double z = workers[i].get_Z();
		min_z = (min_z < z) ? min_z : z;
	}
	cout << "min Z=" << min_z;
}


void task_3_2_a() {
	double x = 7.2, z, del_x = 0.5;
	int i = 0;
	while (x <= 12)
	{
		i += 1;
		z = (2 * pow(sin(x + 2), 2)) / (pow(x, 2) + 1);
		cout << i << ':' << z << endl;
		x += del_x;
	}
}

void task_3_2_b() {
	double x = 0, z, del_x = 0.1;
	int i = 0, n = 5;
	while (n)
	{
		i += 1;
		z = (2 * pow(sin(x + 2), 2)) / (pow(x, 2) + 1);
		cout << i << ':' << z << endl;
		x += del_x;
		n -= 1;
	}
}

void task_3_2() {
	char task_3;
	while (1) {
		cout << "select variant task_3(0 - exit): ";
		cin >> task_3;
		switch (task_3)
		{
		case 'a':
			task_3_2_a();
			break;
		case 'b':
			task_3_2_b();
			break;
		case '0':
			return;
		default:
			break;
		}
	}
}


void task_3_3() {
	double x = -0.8, y = 0, z;
	const double del_x = 0.1, del_y = 0.2;
	do
	{
		z = pow(x, 2) + 2.08 * y;
		cout << z << endl;
		x += del_x;
		y += del_y;
	} while ((x <= 0) and (y <= 1.5));
}

void task_3() {
	int task_3;
	while (true)
	{
		cout << "select task_3(0 - exit): ";
		cin >> task_3;
		switch (task_3)
		{
		case 1:
			task_3_1();
			break;
		case 2:
			task_3_2();
			break;
		case 3:
			task_3_3();
			break;
		case 0:
			return;
		default:
			break;
		}
	}

}