#include <iostream>
#include <math.h>

#pragma warning(disable : 4996)

using namespace std;


#include "myfunc.h"


int main() {
	int task;
	while (true)
	{
		cout << "select page(0 - exit): ";
		cin >> task;
		switch (task)
		{
		case 1:
			task_1();
			break;
		case 2:
			task_2();
			break;
		case 3:
			task_3();
			break;
		case 4:
			task_4();
			break;
		case 5:
			task_5();
			break;
		case 6:
			task_6();
			break;
		case 7:
			task_7();
			break;
		case 8:
			task_8();
			break;
		case 9:
			task_9();
			break;
		case 10:
			task_10();
			break;
		case 11:
			task_11();
			break;
		case 12:
			task_12();
			break;
		case 13:
			task_13();
			break;
		case 0:
			return 0;
		default:
			break;
		}
	}

}