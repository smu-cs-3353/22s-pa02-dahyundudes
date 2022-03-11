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
#include "MergeSort.h"
#include "IntroSort.h"
#include "TimSort.h"
#include "DatasetTesting.h"

using namespace std;

int main(int argc, char** argv) {
//    if (argc == 1)
//        cout << "No arguments provided." << endl;
//    else {
        cout << "Hello CS3353, your arguments were: ";

        DatasetTesting d;
        d.readData();


//        for (int i = 1; i < argc; i++) {
//            cout << argv[i];
//            if (i < argc - 1)
//                cout << ", ";
//        }
//        cout << endl;
//
//        int* temp = new int[10];
//        int size = 10;
//        for (int i = 0; i < 10; i++) {
//            temp[9 - i] = i;
//        }
//
//        int* result;
//        cout << "Original list:  ";
//        for (int i = 0; i < 10; i++) {
//            cout << temp[i] << ",";
//        }
//        cout << endl;
//
//        Sort<int>* select = new SelectionSort<int>(temp, size);
//        result = select->sort();
//        cout << "Selection Sort: ";
//        for (int i = 0; i < 10; i++) {
//            cout << result[i] << ",";
//        }
//        cout << endl;
//
//        Sort<int>* insert = new InsertionSort<int>(temp, size);
//        result = insert->sort();
//        cout << "Insertion Sort: ";
//        for (int i = 0; i < size; i++) {
//            cout << result[i] << ",";
//        }
//        cout << endl;
//
//        Sort<int>* quick = new QuickSort<int>(temp, size);
//        result = quick->sort();
//        cout << "Quick Sort:     ";
//        for (int i = 0; i < size; i++) {
//            cout << result[i] << ",";
//        }
//        cout << endl;
//
//        Sort<int>* shell = new ShellSort<int>(temp, size);
//        result = shell->sort();
//        cout << "Shell Sort:     ";
//        for (int i = 0; i < size; i++) {
//            cout << result[i] << ",";
//        }
//        cout << endl;
//
//        Sort<int>* merge = new MergeSort<int>(temp, size);
//        result = merge->sort();
//        cout << "Merge Sort:     ";
//        for(int i = 0; i < size; i++) {
//                cout << result[i] << ",";
//        }
//        cout << endl;
//
//
//        Sort<int>* intro = new IntroSort<int>(temp, size);
//        result = intro->sort();
//        cout << "Intro Sort:     ";
//        for(int i = 0; i < size; i++) {
//                cout << result[i] << ",";
//        }
//        cout << endl;
//
//        Sort<int>* tim = new TimSort<int>(temp, size);
//        result = tim->sort();
//        cout << "Tim Sort:       ";
//        for(int i = 0; i < size; i++) {
//            cout << result[i] << ",";
//        }
//        cout << endl;


//    }
}