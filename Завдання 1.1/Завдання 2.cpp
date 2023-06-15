
#include <iostream>
#include <math.h>

#pragma warning(disable : 4996)

using namespace std;
#include "myfunc.h"

void task_2_1() {
	double y, x, z;
	cout << "write x, z : ";
	cin >> x >> z;
	if ((x >= 2 * z) and (abs(z) > 1))
		y = pow(log(abs(x - z)), 2);
	else if ((0 < abs(z)) and (abs(z) < 1) and (x > z))
		y = pow(log10(abs((x / z) - 1)), 2);
	else if ((z <= x) and (abs(z) > 1))
		y = pow(tan(x + z), 3);
	else if ((x <= z) and (abs(z) < 1))
		y = 5.6 * pow(10, -3);
	else {
		cout << "function not find" << endl;
		return;
	}
	cout << "y=" << y << endl;
}




void task_2_2() {
	double x, y, z, q1, q2;
	cout << "write x, y, z : ";
	cin >> x >> y >> z;
	cout << "write q1, q2 : ";
	cin >> q1 >> q2;
	if ((x < q1) or (x > q2))
		cout << "x";
	if ((y < q1) or (y > q2))
		cout << "y";
	if ((z < q1) or (z > q2))
		cout << "z";
	cout << endl;
}

struct pos {
	double x;
	double y;
};

double distance(pos p1, pos p2) {
	return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

void task_2_3() {
	pos poss[4];
	cout << "write 4 pos (x, y)" << endl;
	for (int i = 0; i < 4; i++) {
		pos* p = new pos;
		cin >> (*p).x >> (*p).y;
		poss[i] = *p;
	}

	double max_s = -1;
	for (pos p1 : poss)
		for (pos p2 : poss)
			for (pos p3 : poss) {
				double a, b, c, p, S;

				a = distance(p1, p2);
				b = distance(p2, p3);
				c = distance(p1, p3);

				p = (a + b + c) / 2.0;
				S = sqrt(p * (p - a) * (p - b) * (p - c));
				
				max_s = (S > max_s) ? S : max_s;
			}
	cout << "max S = " << max_s << endl;
}


void task_2() {
	int task_2;
	while (true)
	{
		cout << "select task_2(0 - exit): ";
		cin >> task_2;
		switch (task_2)
		{
		case 1:
			task_2_1();
			break;
		case 2:
			task_2_2();
			break;
		case 3:
			task_2_3();
			break;
		case 0:
			return;
		default:
			break;
		}
	}

}