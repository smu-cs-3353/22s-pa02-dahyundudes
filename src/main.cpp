//
// Created by Zachary on 3/2/2022.
//

#include <iostream>
#include <iomanip>
#include <chrono>
#include "Profiler.h"

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

        int size = 10000;

        int* temp = new int[size];
        for (int i = 0; i < size; i++) {
            temp[size-1 - i] = i;
        }

        int* result;
        cout << "Original list: ";
        for (int i = 0; i < size; i++) {
            cout << temp[i] << ",";
        }
        cout << endl;

        Profiler<int> p(temp, size);
        chrono::duration<double>* times = p.sortDatasets();
    }
}