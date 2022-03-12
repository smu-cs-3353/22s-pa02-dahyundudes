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
     * @param int size of array
     */
    InsertionSort(const T*, int);

    /**
     * Sorts the data array using Insertion Sort and returns the result
     * @return T* array of templated elements
     */
    T* sort() override;
};

template <class T>
InsertionSort<T>::InsertionSort() : Sort<T>(){
}

template <class T>
InsertionSort<T>::InsertionSort(const Sort<T>& other) : Sort<T>(other){
}

template <class T>
InsertionSort<T>::InsertionSort(const T* other, int size) : Sort<T>(other, size) {
}

template <class T>
T* InsertionSort<T>::sort() {
    static InsertionSort<T> temp(this->data, this->size);

    for (int i = 1; i < temp.size; i++) {
        int j = i;
        while (j > 0 && temp.data[j] < temp.data[j-1]) {
            // swap smallest element
            T val = temp.data[j-1];
            temp.data[j-1] = temp.data[j];
            temp.data[j] = val;
            j--;
        }
    }
    return temp.data;
}

#endif //INC_22S_PA02_INSERTIONSORT_H
