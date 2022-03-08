//
// Created by Daniel Ryan on 3/8/22.
//

#ifndef INC_22S_PA02_INTROSORT_H
#define INC_22S_PA02_INTROSORT_H

#include "Sort.h"
#include <random>

template <class T>
class IntroSort : public Sort<T> {
public:
    /**
     * Default Constructor
     */
    IntroSort();
    /**
     * Copy Constructor
     */
    IntroSort(const Sort<T>&);
    /**
     * Overloaded Constructor
     * @param T* array of templated elements
     */
    IntroSort(const T* s, int c);

    /**
     * Sorts the data array using SelectionSort and returns the result
     * @return T* array of templated elements
     */
    T* sort() override;

    void sortHelp(T*, int, int, int);

    void insertionSort(T*, int, int);

    int quickSort(T*, int, int);
};

template <class T>
IntroSort<T>::IntroSort() : Sort<T>() {

}

template <class T>
IntroSort<T>::IntroSort(const Sort<T>& s) : Sort<T>(s) {

}

template <class T>
IntroSort<T>::IntroSort(const T* s, int c) : Sort<T>(s, c) {

}

template <class T>
T* IntroSort<T>::sort() {
    ///Make sure to figure out how this works!!!!
    static IntroSort<T> temp(this->data, this->size);

    int dl = 2 * log(temp.size-1);
    sortHelp(temp.data, 0, temp.size-1, dl);
    return temp.data;
}

template<class T>
void IntroSort<T>::sortHelp(T* arr, int begin, int end, int depth) {

    int size = end - begin + 1;

    if(size < 16) {
        insertionSort(arr, begin, end);
        return;
    }

    if(depth == 0) {
        T* t = arr + end;
        std::make_heap(arr+begin, t+1);   //TODO: implement heap sort
        std::sort_heap(arr+begin, t+1);
        return;
    }

    int ind = quickSort(arr, begin, end);
    sortHelp(arr, begin, ind-1, depth-1);
    sortHelp(arr, ind + 1, end, depth-1);


}

template<class T>
void IntroSort<T>::insertionSort(T* arr, int begin, int end) {

    for (int i = begin+1; i <= end; i++) {
        int j = i;
        while (j > begin && arr[j] < arr[j-1]) {
            T val = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = val;
            j--;
        }
    }
}

template<class T>
int IntroSort<T>::quickSort(T* arr, int low, int high) {
    srand(time(nullptr));
    int pivot = low + rand() % (high - low);
    int i = (low - 1);

    std::swap(arr[pivot], arr[high]);
    pivot = high;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= arr[pivot]) {
            i++;
            T val = arr[i];
            arr[i] = arr[j];
            arr[j] = val;
        }
    }
    T val = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = val;
    return (i + 1);
}

#endif //INC_22S_PA02_INTROSORT_H
