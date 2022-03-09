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
    SelectionSort(const T* s, int c);

    /**
     * Sorts the data array using SelectionSort and returns the result
     * @return T* array of templated elements
     */
    T* sort() override;
};

template <class T>
SelectionSort<T>::SelectionSort() : Sort<T>() {

}

template <class T>
SelectionSort<T>::SelectionSort(const Sort<T>& s) : Sort<T>(s) {

}

template <class T>
SelectionSort<T>::SelectionSort(const T* s, int c) : Sort<T>(s, c) {

}

template <class T>
T* SelectionSort<T>::sort() {
    static SelectionSort<T> temp(this->data, this->size);
    int minIndex = 0;
//    T min = this->data[0];
    for (int i = 0; i < temp.size; i++) {
        minIndex = i;
        T min = temp.data[minIndex];
        for (int j = i+1; j < temp.size; j++)
            if (temp.data[j] < min) {
                minIndex = j;
                min = temp.data[j];
            }
        T val = min;
        temp.data[minIndex] = temp.data[i];
        temp.data[i] = val;
    }
    return temp.data;
}

#endif //INC_22S_PA02_SELECTIONSORT_H
