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
    SelectionSort() : Sort<T>() {};
    /**
     * Copy Constructor
     */
    SelectionSort(const Sort<T>& s) : Sort<T>(s) {};
    /**
     * Overloaded Constructor
     * @param T* array of templated elements
     */
    SelectionSort(T* s) : Sort<T>(s) {};

    /**
     * Sorts the data array using SelectionSort and returns the result
     * @return T* array of templated elements
     */
    T* sort() override;
};

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
