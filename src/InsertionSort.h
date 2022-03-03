//
// Created by Zachary on 3/3/2022.
//

#ifndef INC_22S_PA02_INSERTIONSORT_H
#define INC_22S_PA02_INSERTIONSORT_H

#include "Sort.h"

template <class T>
class InsertionSort : public Sort<T> {
public:
    /**
     * Default Constructor
     */
    InsertionSort();
    /**
     * Copy Constructor
     */
    InsertionSort(const Sort<T>&);
    /**
     * Overloaded Constructor
     * @param T* array of templated elements
     */
    InsertionSort(T*);
    /**
     * Destructor
     */
    ~InsertionSort();

    /**
     * Sorts the data array using InsertionSort and returns the result
     * @return T* array of templated elements
     */
    T* sort();
};

template <class T>
InsertionSort<T>::InsertionSort() {
    this->data = nullptr;
}

template <class T>
InsertionSort<T>::InsertionSort(const Sort<T>& other) {
    if (sizeof(other.data) > 0) {
        this->data = new T[sizeof(other.data)];
        for (int i = 0; i < sizeof(other.data); i++)
            this->data[i] = other.data[i];
    }
}

template <class T>
InsertionSort<T>::InsertionSort(T* other) {
    if (sizeof(other > 0)) {
        this->data = new T[sizeof(other)];
        for (int i = 0; i < sizeof(other); i++)
            this->data[i] = other[i];
    }
}

template <class T>
InsertionSort<T>::~InsertionSort() {
    if (this->data != nullptr)
        delete[] this->data;
}

template <class T>
T* InsertionSort<T>::sort() {
    InsertionSort<T> temp(this->data);
    for (int i = 1; i < sizeof(temp.data); i++) {
        int j = i;
        while (temp.data[j] < temp.data[j-1] && j > 0) {
            T val = temp.data[j-1];
            temp.data[j-1] = temp.data[j];
            temp.data[j] = val;
            j--;
        }
    }
    return temp.data;
}

#endif //INC_22S_PA02_INSERTIONSORT_H
