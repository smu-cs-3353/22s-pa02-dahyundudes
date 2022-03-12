//
// Created by Daniel Ryan on 3/8/22.
//

#ifndef INC_22S_PA02_MERGESORT_H
#define INC_22S_PA02_MERGESORT_H

#include "Sort.h"

template <class T>
class MergeSort : public Sort<T> {
private:
    /**
     * Recursively splits the array in half until its just single element
     * subsets, and then merges them together to sort.
     * @param arr the array to sort
     * @param left index of beginning of subset
     * @param right index of end of subset
     */
    void sortHelp(T* arr, int left, int right);

    /**
     * Merges the left and right array and sorts them in order
     * @param arr the array to sort
     * @param left index of beginning element
     * @param mid index of middle
     * @param right index of lst element
     */
    void merge(T* arr, int left, int mid, int right);

public:
    /**
     * Default Constructor
     */
    MergeSort();
    /**
     * Copy Constructor
     */
    MergeSort(const Sort<T>&);
    /**
     * Overloaded Constructor
     * @param T* array of templated elements
     */
    MergeSort(const T* s, int c);

    /**
     * Sorts the data array using SelectionSort and returns the result
     * @return T* array of templated elements
     */
    T* sort() override;
};

template <class T>
MergeSort<T>::MergeSort() : Sort<T>() {

}

template <class T>
MergeSort<T>::MergeSort(const Sort<T>& s) : Sort<T>(s) {

}

template <class T>
MergeSort<T>::MergeSort(const T* s, int c) : Sort<T>(s, c) {

}

template <class T>
T* MergeSort<T>::sort() {
    static MergeSort<T> temp(this->data, this->size);
    sortHelp(temp.data, 0 ,temp.size-1);

    return temp.data;
}

template<class T>
void MergeSort<T>::sortHelp(T* arr, int left, int right) {
    if(left >= right)
        return;

    //  split left and right half and merge them
    int mid = left + (right - left) / 2;
    sortHelp(arr, left, mid);
    sortHelp(arr, mid+1, right);
    merge(arr, left, mid, right);


}

template<class T>
void MergeSort<T>::merge(T* arr, int left, int mid, int right) {

    //  Tried to implement an in place merge sort algorithm, but it got too complex rip

    //  calculate size of left and right array
    int leftArrSize = mid - left + 1;
    int rightArrSize = right - mid;

    //  copy left and right array
    T* leftArr = new T[leftArrSize];
    T* rightArr = new T[rightArrSize];

    for(int i = 0; i < leftArrSize; i++)
        leftArr[i] = arr[left + i];
    for(int i = 0; i < rightArrSize; i++)
        rightArr[i] = arr[mid + 1 + i];

    // merge left and right arrays in order
    int leftIndex = 0, rightIndex = 0, arrIndex = left;
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

#endif //INC_22S_PA02_MERGESORT_H
