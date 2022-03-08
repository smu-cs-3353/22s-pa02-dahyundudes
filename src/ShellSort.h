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
    static ShellSort<T> temp(this->data, this->size);
    for (int i = temp.size/2; i > 0; i /= 2)
    {
        for (int j = i; i < temp.size; j += 1)
        {
            int t = temp.data[j];
            int k;
            for (k = j; k >= i && temp.data[k - i] > t; k -= i)
                temp.data[k] = temp.data[k - i];
            temp.data[k] = t;
        }
    }
    return temp.data;
}

#endif //INC_22S_PA02_SHELLSORT_H
