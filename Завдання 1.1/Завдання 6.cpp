
#include <iostream>
#include <math.h>

#pragma warning(disable : 4996)

#include "myfunc.h"

using namespace std;

void task_6_1() {
    const int n = 3;
    int arr[n] = { 0 };
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

    cout << "arr = [";
    for (int i = 0; i < n; i++)
        cout << arr[i] << ", ";
    cout << "\b\b]" << endl;
}

void task_6_2() {
    const int ROWS = 4;
    const int COLS = 5;
    int arr[ROWS][COLS] =
    {
        {5, 2, 8, 3, 1},
        {6, 4, 7, 9, 0},
        {3, 1, 2, 6, 5},
        {9, 7, 4, 0, 8}
    };
    cout << "Matrix:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 1; j < COLS; j++) {
            int key = arr[i][j];
            int k = j - 1;
            while (k >= 0 && arr[i][k] < key) {
                arr[i][k + 1] = arr[i][k];
                k--;
            }
            arr[i][k + 1] = key;
        }
    }
    cout << "sort matrix:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void task_6() {
    int task;
    while (true)
    {
        cout << "select task(0 - exit): ";
        cin >> task;
        switch (task)
        {
        case 1:
            task_6_1();
            break;
        case 2:
            task_6_2();
            break;
        case 0:
            return;
        default:
            break;
        }
    }

}