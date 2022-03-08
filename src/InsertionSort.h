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
    InsertionSort(const T*, int);
    /**
     * Destructor
     */
//    ~InsertionSort();

    /**
     * Sorts the data array using InsertionSort and returns the result
     * @return T* array of templated elements
     */
    T* sort() override;
};

template <class T>
InsertionSort<T>::InsertionSort() : Sort<T>(){
}

template <class T>
InsertionSort<T>::InsertionSort(const Sort<T>& other) : Sort<T>(other){
//    if (sizeof(other.data) > 0) {
//        this->data = new T[sizeof(other.data)];
//        for (int i = 0; i < sizeof(other.data); i++)
//            this->data[i] = other.data[i];
//    }
}

template <class T>
InsertionSort<T>::InsertionSort(const T* other, int size) : Sort<T>(other, size) {
//    if (sizeof(other > 0)) {
//        this->data = new T[sizeof(other)];
//        for (int i = 0; i < sizeof(other); i++)
//            this->data[i] = other[i];
//    }
}

template <class T>
T* InsertionSort<T>::sort() {
    static InsertionSort<T> temp(this->data, this->size);

    for (int i = 1; i < temp.size; i++) {
        int j = i;
        while (j > 0 && temp.data[j] < temp.data[j-1]) {
            T val = temp.data[j-1];
            temp.data[j-1] = temp.data[j];
            temp.data[j] = val;
            j--;
        }
    }
    return temp.data;
}

#endif //INC_22S_PA02_INSERTIONSORT_H
