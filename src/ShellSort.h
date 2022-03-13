//
// Created by Daniel Ryan on 3/7/22.
//

#ifndef INC_22S_PA02_SHELLSORT_H
#define INC_22S_PA02_SHELLSORT_H

#include "Sort.h"

template <class T>
class ShellSort : public Sort<T> {
public:
    /**
     * Default Constructor
     */
    ShellSort();
    /**
     * Copy Constructor
     */
    ShellSort(const Sort<T>&);
    /**
     * Overloaded Constructor
     * @param T* array of templated elements
     * @param int size of array
     */
    ShellSort(const T* s, int c);

    /**
     * Sorts the data array using SelectionSort and returns the result
     * @return T* array of templated elements
     */
    T* sort() override;
};

template <class T>
ShellSort<T>::ShellSort() : Sort<T>() {

}

template <class T>
ShellSort<T>::ShellSort(const Sort<T>& s) : Sort<T>(s) {

}

template <class T>
ShellSort<T>::ShellSort(const T* s, int c) : Sort<T>(s, c) {

}

template <class T>
T* ShellSort<T>::sort() {
    T* temp = new T[this->size];
    for (int i = 0; i < this->size; i++)
        temp[i] = this->data[i];

    //  Similar to insertion, but optimized for moving items far apart
    for (int gap = this->size/2; gap > 0; gap /= 2) {
        for (int i = gap; i < this->size; i += 1) {
            T val = temp[i];
            int j = i;
            while(j >= gap && temp[j - gap] > val) {
                temp[j] = temp[j - gap];
                j-=gap;
            }

            temp[j] = val;
        }
    }
    return temp;
}

#endif //INC_22S_PA02_SHELLSORT_H
