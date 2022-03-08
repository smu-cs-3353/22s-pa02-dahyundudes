//
// Created by Zachary on 3/2/2022.
//

#include <iostream>
#include <iomanip>
#include <chrono>
#include "Sort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "ShellSort.h"

using namespace std;

int main(int argc, char** argv) {
//    if (argc == 1)
//        cout << "No arguments provided." << endl;
//    else {
        cout << "Hello CS3353, your arguments were: ";
        for (int i = 1; i < argc; i++) {
            cout << argv[i];
            if (i < argc - 1)
                cout << ", ";
        }
        cout << endl;

        int* temp = new int[10];
        int size = 10;
        for (int i = 0; i < 10; i++) {
            temp[9 - i] = i;
        }

        int* result;

        for (int i = 0; i < 10; i++) {
            cout << temp[i] << ",";
        }
        cout << endl;

        Sort<int>* select = new SelectionSort<int>(temp, size);
        result = select->sort();
        for (int i = 0; i < 10; i++) {
            cout << result[i] << ",";
        }
        cout << endl;

        Sort<int>* insert = new InsertionSort<int>(temp, size);
        result = insert->sort();
        for (int i = 0; i < size; i++) {
            cout << result[i] << ",";
        }
        cout << endl;

        Sort<int>* quick = new QuickSort<int>(temp, size);
        result = quick->sort();
        for (int i = 0; i < size; i++) {
            cout << result[i] << ",";
        }
        cout << endl;

//        Sort<int>* shell = new ShellSort<int>(temp, size);
//        result = shell->sort();
//        for (int i = 0; i < size; i++) {
//            cout << result[i] << ",";
//        }
//        cout << endl;

//    }
}