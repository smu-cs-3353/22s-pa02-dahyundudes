//
// Created by Zachary on 3/3/2022.
//

#ifndef INC_22S_PA02_SELECTIONSORT_H
#define INC_22S_PA02_SELECTIONSORT_H

#include "Sort.h"

template <class T>
class SelectionSort : public Sort<T> {
public:
    /**
     * Default Constructor
     */
    SelectionSort();
    /**
     * Copy Constructor
     */
    SelectionSort(const Sort<T>&);
    /**
     * Overloaded Constructor
     * @param T* array of templated elements
     */
    SelectionSort(T*);
    /**
     * Destructor
     */
    ~SelectionSort();

    /**
     * Sorts the data array using SelectionSort and returns the result
     * @return T* array of templated elements
     */
    T* sort();
};

template <class T>
SelectionSort<T>::SelectionSort() {
    this->data = nullptr;
}

template <class T>
SelectionSort<T>::SelectionSort(const Sort<T>& other) {
    if (sizeof(other.data) > 0) {
        this->data = new T[sizeof(other.data)];
        for (int i = 0; i < sizeof(other.data); i++)
            this->data[i] = other.data[i];
    }
}

template <class T>
SelectionSort<T>::SelectionSort(T* other) {
    if (sizeof(other > 0)) {
        this->data = new T[sizeof(other)];
        for (int i = 0; i < sizeof(other); i++)
            this->data[i] = other[i];
    }
}

template <class T>
SelectionSort<T>::~SelectionSort() {
    if (this->data != nullptr)
        delete[] this->data;
}

template <class T>
T* SelectionSort<T>::sort() {
    SelectionSort<T> temp(this->data);
    int minIndex = 0;
    T* min = &temp.data[0];
    for (int i = 0; i < sizeof(temp.data); i++) {
        for (int j = i; j < sizeof(temp.data); j++)
            if (temp.data[j] < *min) {
                minIndex = j;
                min = &temp.data[j];
            }
        T val = *min;
        temp.data[minIndex] = temp.data[i];
        temp.data[i] = val;
        minIndex = i;
    }
    return temp.data;
}

#endif //INC_22S_PA02_SELECTIONSORT_H
