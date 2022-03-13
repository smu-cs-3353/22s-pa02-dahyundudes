//
// Created by Daniel Ryan on 3/8/22.
//

#ifndef INC_22S_PA02_TIMSORT_H
#define INC_22S_PA02_TIMSORT_H

#include "Sort.h"

template <class T>
class TimSort : public Sort<T> {
private:
    /**
     * Implementation of insertion sort for the smaller sub-arrays
     * @param arr array to be sorted
     * @param low index of first element
     * @param high index of last element
     */
    void insertionSort(T* arr, int low, int high);

    /**
     * Implementation of merge sort to merge pre sorted sections of arrays
     * from insertion sort
     * @param arr array to be sorted
     * @param low index of first element
     * @param mid index of middle element
     * @param high index of last element
     */
    void mergeSort(T* arr, int low, int mid, int high);

public:
    /**
     * Default Constructor
     */
    TimSort();
    /**
     * Copy Constructor
     */
    TimSort(const Sort<T>&);
    /**
     * Overloaded Constructor
     * @param T* array of templated elements
     * @param int size of array
     */
    TimSort(const T* s, int c);

    /**
     * Sorts the data array using Tim Sort and returns the result
     * @return T* array of templated elements
     */
    T* sort() override;
};

template <class T>
TimSort<T>::TimSort() : Sort<T>() {

}

template <class T>
TimSort<T>::TimSort(const Sort<T>& s) : Sort<T>(s) {

}

template <class T>
TimSort<T>::TimSort(const T* s, int c) : Sort<T>(s, c) {

}

template <class T>
T* TimSort<T>::sort() {
    T* temp = new T[this->size];
    for (int i = 0; i < this->size; i++)
        temp[i] = this->data[i];

    //  sorts every 32 elements separately with insertion
    for(int i = 0; i < this->size; i+=32) {
        if(i+31 < this->size-1)
            insertionSort(temp, i, (i+31));
        else
            insertionSort(temp, i, this->size-1);
    }

    //  merges presorted arrays from insertion
    for(int s = 32; s < this->size; s*=2) {

        for(int low = 0; low < this->size; low += 2*s) {
            int mid = low + this->size - 1;
            int high = ((low + 2*this->size - 1) < this->size-1) ? (low + 2*this->size - 1) : this->size-1;

            if(mid < high)
                mergeSort(temp, low, mid, high);
        }
    }

    return temp;
}

template<class T>
void TimSort<T>::insertionSort(T* arr, int low, int high) {

    for (int i = low+1; i <= high; i++) {
        int j = i;
        while (j > low && arr[j] < arr[j-1]) {
            T val = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = val;
            j--;
        }
    }

}

template<class T>
void TimSort<T>::mergeSort(T* arr, int low, int mid, int high) {

    // exact same merge algorithm from merge sort

    //  calculate size of left and right array
    int leftArrSize = mid - low + 1;
    int rightArrSize = high - mid;

    //  copy left and right array
    T* leftArr = new T[leftArrSize];
    T* rightArr = new T[rightArrSize];

    for(int i = 0; i < leftArrSize; i++)
        leftArr[i] = arr[low + i];
    for(int i = 0; i < rightArrSize; i++)
        rightArr[i] = arr[mid + 1 + i];

    // merge left and right arrays in order
    int leftIndex = 0, rightIndex = 0, arrIndex = low;
    while(leftIndex < leftArrSize || rightIndex < rightArrSize) {
        if(rightIndex == rightArrSize) {    // if right array is fully merged
            arr[arrIndex] = leftArr[leftIndex];
            leftIndex++;
        } else if(leftIndex == leftArrSize) {   // if left array is fully merged
            arr[arrIndex] = rightArr[rightIndex];
            rightIndex++;
        } else if(leftArr[leftIndex] <= rightArr[rightIndex]) { // adds smallest element
            arr[arrIndex] = leftArr[leftIndex];
            leftIndex++;
        } else {
            arr[arrIndex] = rightArr[rightIndex];
            rightIndex++;

        }
        arrIndex++;
    }

    if(leftArrSize != 0)
        delete[] leftArr;
    if(rightArrSize != 0)
        delete[] rightArr;
}

#endif //INC_22S_PA02_TIMSORT_H
