//
// Created by Zachary on 3/10/2022.
//

#ifndef INC_22S_PA02_PROFILER_H
#define INC_22S_PA02_PROFILER_H

#include <iostream>
#include <chrono>

#include "Sort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "IntroSort.h"
#include "TimSort.h"

using namespace std;

template <class T>
class Profiler {
private:
    int size;
    T* arr;
public:
    /**
     * Default constructor
     */
    Profiler();

    /**
     * Overloaded constructor
     *
     * @param T* the array to be sorted
     * @param int the size of the array (or the amount of the array that should be sorted)
     */
    Profiler(T*&, int);

    /**
     * Sort the dataset using each sort and return an array of times
     *
     * @return double* the array of times
     */
    double* sortDatasets();

    /**
     * Sort the dataset using the specified sort and return the timing data
     *
     * @param int the number of sort to test
     * @return double the time the sort took
     */
    double sortDataset(int);
};

template <class T>
Profiler<T>::Profiler() {
    this->arr = new T[0];
    this->size = 0;
}

template <class T>
Profiler<T>::Profiler(T*& arr, int size) {
    this->arr = arr;
    this->size = size;
}

template <class T>
double* Profiler<T>::sortDatasets() {
    // variable to hold the timing data
    double* timingData = new double[7];

    // Selection Sort
    SelectionSort<T> select(this->arr);
    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
    select.sort();
    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
    timingData[0] = (chrono::duration_cast<chrono::duration<double>>(t2 - t1)).count();
    cout << "Selection sort took " << timingData[0] << " seconds." << endl;

    // Insertion Sort
    InsertionSort<T> insert(this->arr);
    t1 = chrono::high_resolution_clock::now();
    insert.sort();
    t2 = chrono::high_resolution_clock::now();
    timingData[1] = (chrono::duration_cast<chrono::duration<double>>(t2 - t1)).count();
    cout << "Insertion sort took " << timingData[1] << " seconds." << endl;

    // Quick Sort
    QuickSort<T> quick(this->arr);
    t1 = chrono::high_resolution_clock::now();
    quick.sort();
    t2 = chrono::high_resolution_clock::now();
    timingData[2] = (chrono::duration_cast<chrono::duration<double>>(t2 - t1)).count();
    cout << "Quick sort took " << timingData[2] << " seconds." << endl;

    // Shell Sort
    ShellSort<T> shell(this->arr);
    t1 = chrono::high_resolution_clock::now();
    shell.sort();
    t2 = chrono::high_resolution_clock::now();
    timingData[3] = (chrono::duration_cast<chrono::duration<double>>(t2 - t1)).count();
    cout << "Shell sort took " << timingData[3] << " seconds." << endl;

    // Merge Sort
    MergeSort<T> merge(this->arr);
    t1 = chrono::high_resolution_clock::now();
    merge.sort();
    t2 = chrono::high_resolution_clock::now();
    timingData[4] = (chrono::duration_cast<chrono::duration<double>>(t2 - t1)).count();
    cout << "Merge sort took " << timingData[4] << " seconds." << endl;

    // Intro Sort
    IntroSort<T> intro(this->arr);
    t1 = chrono::high_resolution_clock::now();
    intro.sort();
    t2 = chrono::high_resolution_clock::now();
    timingData[5] = (chrono::duration_cast<chrono::duration<double>>(t2 - t1)).count();
    cout << "Intro sort took " << timingData[5] << " seconds." << endl;

    // Tim Sort
    InsertionSort<T> tim(this->arr);
    t1 = chrono::high_resolution_clock::now();
    tim.sort();
    t2 = chrono::high_resolution_clock::now();
    timingData[6] = (chrono::duration_cast<chrono::duration<double>>(t2 - t1)).count();
    cout << "Tim sort took " << timingData[6] << " seconds." << endl;

    return timingData;
}

template <class T>
double Profiler<T>::sortDataset(int i) {

}

#endif //INC_22S_PA02_PROFILER_H
