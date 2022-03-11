//
// Created by Zachary on 3/10/2022.
//

#ifndef INC_22S_PA02_PROFILER_H
#define INC_22S_PA02_PROFILER_H

#include "Sort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "IntroSort.h"
#include "TimSort.h"

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

}

template <class T>
double Profiler<T>::sortDataset(int i) {

}

#endif //INC_22S_PA02_PROFILER_H
