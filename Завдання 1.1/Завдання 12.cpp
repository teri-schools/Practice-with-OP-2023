
#include <iostream>
#include <math.h>
#include <Windows.h>
#include <string>
#pragma warning(disable : 4996)

#include "myfunc.h"

using namespace std;


void task_12_1() {
	const char path[] = "12_task_12_1.txt";
	FILE* fp = fopen(path, "wt");
	if (fp == nullptr) {
		cout << "field open file" << endl;
		return;
	}

	double x = 17.421, y = 10.365 * pow(10, -3), z = 0.828 * pow(10, 5);
	double f = (sqrt(y + sqrt(x - 1, 3), 4)) / (abs(x - y) * (pow(sin(z), 2) + tg(z)));

	fprintf(fp, "%f\n", f);

}

struct Phone {
	char model[50];
	double display_diagonal;
	int graduation_year;
	int price;

};

void phone_write_to_file(Phone phones[], int length, const char path[]) {
	FILE* fp = fopen(path, "w");
	if (fp == nullptr) {
		cout << "field open file" << endl;
		return;
	}
	for (int i = 0; i < length; i++)
		fwrite(&phones[i], sizeof(Phone), 1, fp);

	fclose(fp);
}

void phone_read_from_file(Phone phones[], int length, const char path[]) {
	FILE* fp = fopen(path, "r");
	if (fp == nullptr) {
		cout << "field open file" << endl;
		return;
	}
	for (int i = 0; i < length; i++)
	{
		fread(&phones[i], sizeof(Phone), 1, fp);
	}


	fclose(fp);

}

void task_12_2() {
	const char path[] = "task_12_2.txt";
	const int n = 26;

	Phone phones[] = {
		{"iPhone 12", 6.1, 2020, 799},
		{"Samsung Galaxy S21", 6.2, 2021, 999},
		{"Google Pixel 5", 6.0, 2020, 699},
		{"OnePlus 9 Pro", 6.7, 2021, 1069},
		{"Xiaomi Mi 11", 6.81, 2020, 699},
		{"Huawei P40 Pro", 6.58, 2020, 999},
		{"Sony Xperia 1 III", 6.5, 2021, 1299},
		{"LG Velvet", 6.8, 2020, 699},
		{"Motorola Edge+", 6.7, 2020, 999},
		{"Nokia 9 PureView", 5.99, 2019, 699},
		{"Apple iPhone SE", 4.7, 2020, 399},
		{"Samsung Galaxy Note 20 Ultra", 6.9, 2020, 1299},
		{"Google Pixel 4a", 5.81, 2020, 349},
		{"OnePlus 8T", 6.55, 2020, 749},
		{"Xiaomi Redmi Note 10 Pro", 6.67, 2021, 279},
		{"Huawei Mate 40 Pro", 6.76, 2020, 1199},
		{"Sony Xperia 5 III", 6.1, 2021, 999},
		{"LG Wing", 6.8, 2020, 999},
		{"Motorola Razr 5G", 6.2, 2020, 1399},
		{"Nokia 8.3 5G", 6.81, 2020, 699},
		{"iPhone 11", 6.1, 2019, 699},
		{"Samsung Galaxy S20 Ultra", 6.9, 2020, 1399},
		{"Google Pixel 4", 5.7, 2019, 799},
		{"OnePlus 8 Pro", 6.78, 2020, 899},
		{"Xiaomi Mi 10T Pro", 6.67, 2020, 599},
		{"Huawei P30 Pro", 6.47, 2019, 799}
	};

	phone_write_to_file(phones, n, path);

	Phone arr[n];

	phone_read_from_file(arr, n, path);

	double display_diagonal;
	int from_price, to_price;
	cout << "display diagonal : ";
	cin >> display_diagonal;
	cout << "range price (from, to):";
	cin >> from_price >> to_price;

	for (int i = 0; i < n; i++)
		if ((display_diagonal == arr[i].display_diagonal) and
			(from_price <= arr[i].price) and (arr[i].price <= to_price))
			cout << endl
			<< "model: " << arr[i].model << endl
			<< "display diagonal: " << arr[i].display_diagonal << endl
			<< "graduation year: " << arr[i].graduation_year << endl
			<< "price: " << arr[i].price << endl;


}


void task_12() {
	int task;
	while (true)
	{
		cout << "select task(0 - exit): ";
		cin >> task;
		switch (task)
		{
		case 1:
			task_12_1();
			break;
		case 2:
			task_12_2();
			break;
		case 0:
			return;
		default:
			break;
		}
	}

}