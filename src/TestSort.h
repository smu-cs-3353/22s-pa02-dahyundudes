//
// Created by Zachary on 3/2/2022.
//

#ifndef INC_22S_PA02_TESTSORT_H
#define INC_22S_PA02_TESTSORT_H

#include "Sort.h"

template <class T>
class TestSort : public Sort<T> {
public:
    /**
     * Default Constructor
     */
    TestSort();
    /**
     * Copy Constructor
     */
    TestSort(const Sort<T>&);
    /**
     * Overloaded Constructor
     * @param T* array of templated elements
     */
    TestSort(T*);
    /**
     * Destructor
     */
    ~TestSort();

    /**
     * Sorts the data array using MiracleSort and returns the result
     * @return T* array of templated elements
     */
    T* sort();
};

template <class T>
TestSort<T>::TestSort() {
    this->data = nullptr;
}

template <class T>
TestSort<T>::TestSort(const Sort<T>& other) {
    if (sizeof(other.data) > 0) {
        this->data = new T[sizeof(other.data)];
        for (int i = 0; i < sizeof(other.data); i++)
            this->data[i] = other.data[i];
    }
}

template <class T>
TestSort<T>::TestSort(T* other) {
    if (sizeof(other) > 0) {
        this->data = new T[sizeof(other)];
        for (int i = 0; i < sizeof(other); i++)
            this->data[i] = other[i];
    }
}

template <class T>
TestSort<T>::~TestSort() {
    if (this->data != nullptr)
        delete[] this->data;
}

template <class T>
T* TestSort<T>::sort() {
    TestSort<T> temp(*this);
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 1; i < sizeof(temp.data); i++)
            if (temp.data[i] < temp.data[i - 1]) {
                sorted = false;
                break;
            }
    }
    return temp.data;
}

#endif //INC_22S_PA02_TESTSORT_H
