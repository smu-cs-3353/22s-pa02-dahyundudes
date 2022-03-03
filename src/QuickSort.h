//
// Created by Zachary on 3/3/2022.
//

#ifndef INC_22S_PA02_QUICKSORT_H
#define INC_22S_PA02_QUICKSORT_H

#include "Sort.h"

template <class T>
class QuickSort : public Sort<T> {
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
     */
    QuickSort(T*);
    /**
     * Destructor
     */
    ~QuickSort();

    /**
     * Sorts the data array using QuickSort and returns the result
     * @return T* array of templated elements
     */
    T* sort();

    T* sortHelp(T*, int, int);

    int partition(T*, int, int);
};

template <class T>
QuickSort<T>::QuickSort() {
    this->data = nullptr;
}

template <class T>
QuickSort<T>::QuickSort(const Sort<T>& other) {
    if (sizeof(other.data) > 0) {
        this->data = new T[sizeof(other.data)];
        for (int i = 0; i < sizeof(other.data); i++)
            this->data[i] = other.data[i];
    }
}

template <class T>
QuickSort<T>::QuickSort(T* other) {
    if (sizeof(other > 0)) {
        this->data = new T[sizeof(other)];
        for (int i = 0; i < sizeof(other); i++)
            this->data[i] = other[i];
    }
}

template <class T>
QuickSort<T>::~QuickSort() {
    if (this->data != nullptr)
        delete[] this->data;
}

template <class T>
T* QuickSort<T>::sort() {
    QuickSort<T> temp(this->data);
    return sortHelp(temp.data, 0, sizeof(temp.data));
}

template <class T>
T* QuickSort<T>::sortHelp(T* temp, int low, int high) {
    if (low < high) {
        int pivot = partition(temp, low, high);

        sortHelp(temp, low, pivot - 1);
        sortHelp(temp, pivot + 1, high);
    }
    else
        return temp;
}

template <class T>
int QuickSort<T>::partition(T* temp, int low, int high) {
    int pivot = temp[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (temp[j] <= pivot) {
            i++;
            T val = temp[i];
            temp[i] = temp[j];
            temp[j] = val;
        }
    }
    T val = temp[i + 1];
    temp[i + 1] = temp[high];
    temp[high] = val;
    return (i + 1);
}

#endif //INC_22S_PA02_QUICKSORT_H
