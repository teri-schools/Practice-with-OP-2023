
#include <iostream>
#include <math.h>
#include <Windows.h>
#pragma warning(disable : 4996)

using namespace std;

#include "myfunc.h"

int grade_str_to_int(string s) {
	if (s == "відмінно")
		return 5;
	else if (s == "добре")
		return 4;
	else if (s == "задовільно")
		return 3;
	else
		return 2;
}

void task_10_1() {
	const int n = 5;
	// №	П.І.Б		Вища математика		Фізика		Чисельні методи
	string arr[n][5] = {
		{"1", "Іваненко A.M.", "задовільно", "добре", "незадовільно"},
		{"2", "Петренко О.О.", "добре", "незадовільно", "добре"},
		{"3", "Сидорук К.С.", "відмінно", "задовільно", "добре"},
		{"4", "Крук П.В.", "відмінно", "відмінно", "відмінно"},
		{"5", "Голуб О.В.", "задовільно", "добре", "добре"}
	};
	int math_grade = 0, physcis_grade = 0, num_metods_grade = 0;
	for (auto row : arr) {
		math_grade += grade_str_to_int(row[2]);
		physcis_grade += grade_str_to_int(row[3]);
		num_metods_grade += grade_str_to_int(row[4]);
	}
	cout << "agrevate math grade = " << (double)math_grade / n << endl;
	cout << "agrevate physcis grade = " << (double)physcis_grade / n << endl;
	cout << "agrevate number metods grade = " << (double)num_metods_grade / n << endl;

}

void task_10_2() {
	SetConsoleOutputCP(65001);
	//
	string T = "ой на, ой на горі там женці жнуть", N = "";
	for (int i = 0; i < T.size(); i++)
		if (((i + 3) < T.size()) and (T[i] == 'т') and (T[i + 1] == 'а') and (T[i + 2] == 'м')) {
			i += 2;
			continue;
		}
		else if (T[i] != ' ')
			N.push_back(T[i]);
	cout << N << endl;
}

void task_10() {
	int task;
	while (true)
	{
		cout << "select task(0 - exit): ";
		cin >> task;
		switch (task)
		{
		case 1:
			task_10_1();
			break;
		case 2:
			task_10_2();
			break;
		case 0:
			return;
		default:
			break;
		}
	}

}