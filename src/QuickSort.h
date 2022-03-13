//
// Created by Zachary on 3/3/2022.
//

#ifndef INC_22S_PA02_QUICKSORT_H
#define INC_22S_PA02_QUICKSORT_H

#include "Sort.h"
#include "random"

template <class T>
class QuickSort : public Sort<T> {
private:
    /**
     * Recursively splits array, petitions, and sorts. returns result
     * @param arr array to be sorted
     * @param low index of first element
     * @param high index of last element
     * @return T* the sorted array
     */
    T* sortHelp(T* arr, int low, int high);

    /**
     * Splits array based on a randomized pivot and returns position of pivot
     * @param arr array to be sorted
     * @param low index of first element
     * @param high index of last element
     * @return int index of petition
     */
    int partition(T* arr, int low, int high);

public:
    /**
     * Default Constructor
     */
    QuickSort();
    /**
     * Copy Constructor
     */
    QuickSort(const Sort<T>&);
    /**
     * Overloaded Constructor
     * @param T* array of templated elements
     * @param int size of array
     */
    QuickSort(const T*, int);
    /**
     * Destructor
     */

    /**
     * Sorts the data array using QuickSort and returns the result
     * @return T* array of templated elements
     */
    T* sort() override;
};

template <class T>
QuickSort<T>::QuickSort() : Sort<T>(){

}

template <class T>
QuickSort<T>::QuickSort(const Sort<T>& other) : Sort<T>(other){

}

template <class T>
QuickSort<T>::QuickSort(const T* other, int size) : Sort<T>(other, size){

}

template <class T>
T* QuickSort<T>::sort() {
    T* temp = new T[this->size];
    for (int i = 0; i < this->size; i++)
        temp[i] = this->data[i];

    sortHelp(temp, 0, this->size-1);
    return temp;
}

template <class T>
T* QuickSort<T>::sortHelp(T* arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);

        sortHelp(arr, low, pivot - 1);
        sortHelp(arr, pivot + 1, high);
    }
    else {
        return arr;
    }

}

template <class T>
int QuickSort<T>::partition(T* arr, int low, int high) {

    //  chooses a random pivot
    srand(time(nullptr));
    int pivot = low + rand() % (high - low);
    int i = (low - 1);

    //  puts pivot value at the end of sub array
    std::swap(arr[pivot], arr[high]);
    pivot = high;

    //  iterates through array to sort items based on pivot
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= arr[pivot]) {
            i++;
            T val = arr[i];
            arr[i] = arr[j];
            arr[j] = val;
        }
    }
    T val = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = val;
    return (i + 1);
}

#endif //INC_22S_PA02_QUICKSORT_H
