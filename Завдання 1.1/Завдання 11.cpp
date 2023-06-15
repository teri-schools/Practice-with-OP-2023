
#include <iostream>
#include <math.h>
#include <Windows.h>
#pragma warning(disable : 4996)

using namespace std;

#include "myfunc.h"

enum Gender {
	Man,
	Woman,
	X
};

struct Person
{
	char surname[100];
	int birth_year;
	char address[100];
	Gender gender;
	union{
		struct { bool is_armi; int salary; } man;
		struct { int children; char status[100]; int salary; } woman;
	};
};

Person* input_person() {
	Person* p = new Person;
	cout << "Last name: ";
	cin >> p->surname;
	cout << "Birth year: ";
	cin >> p->birth_year;
	cout << "Address: ";
	cin >> p->address;
	char gender;
	cout << "gender (M, W): ";
	cin >> gender;
	switch (gender)
	{
	case 'M':
		p->gender = Man;
		cout << "Armia ? (y, n) : ";
		char ok;
		cin >> ok;
		p->man.is_armi = (ok == 'y') ? true : false;
		cout << "Salary: ";
		cin >> p->man.salary;
		break;
	case 'W':
		p->gender = Woman;
		cout << "Count children: ";
		cin >> p->woman.children;
		cout << "Family status: ";
		cin >> p->woman.status;
		cout << "Salary: ";
		cin >> p->woman.salary;
		break;
	default:
		p->gender = X;
		break;
	}
	return p;
}


void task_11_1() {
	int n;
	cout << "count persons: ";
	cin >> n;
	Person * arr = new Person[n];
	for (int i = 0; i < n; i++)
		arr[i] = *input_person();
	
	cout << "surname" << "\t\t"
		<< "birth_year" << "\t\t"
		<< "address" << "\t\t"
		<< "gender" << "\n";
	for (int i = 0; i < n; i++)
		cout << arr[i].surname << "\t\t"
		<< arr[i].birth_year << "\t\t\t"
		<< arr[i].address << "\t\t"
		<< arr[i].gender << "\n";
	
	int count = 0, salary = 0;
	for (int i = 0; i < n; i++)
		if ((arr[i].gender == Man) and (not arr[i].man.is_armi)) {
			count++;
			salary += arr[i].man.salary;
		}
	cout << "argeve salary not armi man: " << (double)salary / count << endl;


}


struct Toy {
	string name = "";
	int price = 0;
	int from_year = 0;
	int to_year = 0;
};


void task_11_2() {
	int n;
	cout << "count toy : ";
	cin >> n;
	Toy* arr = new Toy[n];

	for (int i = 0; i < n; i++)
	{
		cout << "toy number " << i + 1 << endl;
		Toy toy = *(new Toy);
		cout << "toy name : ";
		cin >> toy.name;
		cout << "toy price : ";
		cin >> toy.price;
		cout << "toy from to years (from year, to year): ";
		cin >> toy.from_year; cin >> toy.to_year;

		arr[i] = toy;
	}

	int price, age;
	cout << "write max price : ";
	cin >> price;
	cout << "write child age : ";
	cin >> age;

	cout << endl;
	for (int i = 0; i < n; i++)
	{
		Toy toy = arr[i];
		if ((toy.price <= price) and (toy.from_year <= age) and (toy.to_year >= age)) {
			cout << "name: " << toy.name << endl;
			cout << "price: " << toy.price << endl;
			cout << "age from " << toy.from_year << " to " << toy.to_year << endl;
			cout << endl;
		}
	}
}


void task_11() {
	int task;
	while (true)
	{
		cout << "select task(0 - exit): ";
		cin >> task;
		switch (task)
		{
		case 1:
			task_11_1();
			break;
		case 2:
			task_11_2();
			break;
		case 0:
			return;
		default:
			break;
		}
	}

}