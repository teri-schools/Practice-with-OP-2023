// Завдання 1.1.cpp 



#include <iostream>
#include <math.h>
#include "myfunc.h"

#pragma warning(disable : 4996)

using namespace std;


void task_1_1() {
    const double omega = 2.77;

    double y, x, z;
    z = sqrt(log(omega) + pow(log(omega), 2), 3);
    x = tg(z / omega) + ctg(sqrt(z));
    y = omega * pow(x, -3.1) + exp(omega * z);

    cout << "z=" << z << endl;
}

void task_1_2() {
    double S, R, P, a;
    cout << "write S = ";
    cin >> S;

    // радіус кола
    R = sqrt(S / pi);

    // довжина кола / периметер квадрата
    P = 2 * pi * R;

    // сторона квадрату
    a = P / 4;

    cout << "side square a=" << a << endl;
}

void task_1()
{
    int task;
    while (1) {
        cout << "select task(0 - exit): ";
        cin >> task;
        switch (task)
        {
        case 1:
            task_1_1();
            break;
        case 2:
            task_1_2();
            break;
        case 0:
            return;
        default:
            break;
        }
    }
    
}