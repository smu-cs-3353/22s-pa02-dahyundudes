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
    Profiler(T*, int);

    ~Profiler();

    /**
     * Sort the dataset using each sort and return an array of times
     *
     * @return double* the array of times
     */
    double* sortDatasets();

    double time(string, Sort<T>&);

    int getSize();
};

template <class T>
Profiler<T>::Profiler() {
    this->arr = new T[0];
    this->size = 0;
}

template <class T>
Profiler<T>::Profiler(T* arr, int size) {
    this->arr = new T[size];
    for (int i = 0; i < size; i++)
        this->arr[i] = arr[i];
    this->size = size;
}

template <class T>
Profiler<T>::~Profiler() {
    delete[] arr;
}

template <class T>
double* Profiler<T>::sortDatasets() {
    // variable to hold the timing data
    double* timingData = new double[6];

    for (int i = 0; i < 6; i++)
        timingData[i] = 0;

    cout << "Size: " << size << endl;

    // Insertion Sort
    InsertionSort<T> insert(this->arr, this->size);
    timingData[0] = time("Insertion", insert);

    // Quick Sort
    QuickSort<T> quick(this->arr, this->size);
    timingData[1] = time("Quick", quick);

    // Shell Sort
    ShellSort<T> shell(this->arr, this->size);
    timingData[2] = time("Shell", shell);

    // Merge Sort
    MergeSort<T> merge(this->arr, this->size);
    timingData[3] = time("Merge", merge);

    // Intro Sort
    IntroSort<T> intro(this->arr, this->size);
    timingData[4] = time("Intro", intro);

    // Tim Sort
    TimSort<T> tim(this->arr, this->size);
    timingData[5] = time("Tim", tim);

    return timingData;
}

template <class T>
double Profiler<T>::time(string name, Sort<T>& temp) {
    double timingData = 0;

    // the start time
    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();

    // sort the array and grab the pointer to the sorted array
    T* sort = temp.sort();

    // the end time
    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();

    // grab the difference between start and end time to get the total time
    timingData = chrono::duration_cast<chrono::duration<double>>(t2 - t1).count();
    cout << name << " sort took " << timingData << " seconds." << endl;

    return timingData;
}

template <class T>
int Profiler<T>::getSize() { return this->size; }

#endif //INC_22S_PA02_PROFILER_H
