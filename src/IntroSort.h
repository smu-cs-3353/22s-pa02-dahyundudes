//
// Created by Daniel Ryan on 3/8/22.
//

#ifndef INC_22S_PA02_INTROSORT_H
#define INC_22S_PA02_INTROSORT_H

#include <random>
#include <algorithm>
#include "Sort.h"

using namespace std;

template <class T>
class IntroSort : public Sort<T> {
private:
    /**
     *
     */
    void sortHelp(T*, int, int, int);

    /**
     * Implementation of insertion sort for when data subset is < 16 elements
     * @param arr array of elements to be sorted
     * @param begin  index of first element in subset
     * @param end index of last element in subset
     */
    void insertionSort(T* arr, int begin, int end);

    /**
     *  Implementation of quicksort when recursion depth of subset is
     *  low enough to avoid worst case scenarios
     *  @param arr array of elements to be sorted
     *  @param low index of first element in subset
     *  @param high index of last element in subset
     * @return index for splitting
     */
    int quickSort(T* arr, int low, int high);

    /**
     * Creates max heap of the data subset recursively by comparing left
     * and right children, then swapping the root with the largest value
     * @param arr array of elements to be sorted
     * @param size size of array
     * @param i index of root
     */
    void heapify(T* arr, int size, int i);

    /**
     * Implementation of heap sort that creates the max heaps and sorts elements
     * one by one
     * @param arr array of elements
     * @param size size of array
     */
    void heapSort(T* arr, int size);
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
     * @param int size of array
     */
    IntroSort(const T* s, int c);

    /**
     * Sorts the data array using IntroSort and returns the result
     * @return T* array of templated elements
     */
    T* sort() override;
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
    T* temp = new T[this->size];
    for (int i = 0; i < this->size; i++)
        temp[i] = this->data[i];

    //  calculates max depth
    int dl = 2 * log(this->size-1);
    sortHelp(temp, 0, this->size-1, dl);
    return temp;
}

template<class T>
void IntroSort<T>::sortHelp(T* arr, int begin, int end, int depth) {

    int size = end - begin + 1;

    //  if list is small, more efficient to sort by insertion
    if(size < 16) {
        insertionSort(arr, begin, end);
        return;
    }

    //  sorts by heap sort to all for optimized quicksort
    if(depth == 0) {
        heapSort(arr+begin, size);
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

template<class T>
void IntroSort<T>::heapify(T* arr, int size, int i) {



    int large = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // if left > root
    if(left < size && arr[left] > arr[large]) {
        large = left;
    }

    // if right > largest value
    if(right < size && arr[right] > arr[large]) {
        large = right;
    }

    // if largest value != root, otherwise redundant
    if(large != i) {
        std::swap(arr[i], arr[large]);

        // whats a sorting algorithm without nested recursive calls
        heapify(arr, size, large);
    }

}

template<class T>
void IntroSort<T>::heapSort(T* arr, int size) {
//    int size = high - low + 1;


    // build heap by rearranging array by comparing left and right half values
    for(int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }

    //  sorts array one by one
    for(int i = size - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }

}

#endif //INC_22S_PA02_INTROSORT_H
