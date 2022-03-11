//
// Created by Daniel Ryan on 3/8/22.
//

#ifndef INC_22S_PA02_MERGESORT_H
#define INC_22S_PA02_MERGESORT_H

#include "Sort.h"

template <class T>
class MergeSort : public Sort<T> {
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

    void sortHelp(T*, int, int);

    void merge(T*, int, int, int);
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
void MergeSort<T>::sortHelp(T* temp, int left, int right) {
    if(left >= right)
        return;

    int mid = left + (right - left) / 2;
    sortHelp(temp, left, mid);
    sortHelp(temp, mid+1, right);
    merge(temp, left, mid, right);


}

template<class T>
void MergeSort<T>::merge(T* arr, int left, int mid, int right) {

    //  Tried to implement an in place merge sort algorithm, but it got too complex rip

    int leftArrSize = mid - left + 1;
    int rightArrSize = right - mid;

    T* leftArr = new T[leftArrSize];
    T* rightArr = new T[rightArrSize];

    for(int i = 0; i < leftArrSize; i++)
        leftArr[i] = arr[left + i];
    for(int i = 0; i < rightArrSize; i++)
        rightArr[i] = arr[mid + 1 + i];


    int leftIndex = 0, rightIndex = 0, arrIndex = left;
    while(leftIndex < leftArrSize || rightIndex < rightArrSize) {
        if(rightIndex == rightArrSize) {
            arr[arrIndex] = leftArr[leftIndex];
            leftIndex++;
        } else if(leftIndex == leftArrSize) {
            arr[arrIndex] = rightArr[rightIndex];
            rightIndex++;
        } else if(leftArr[leftIndex] <= rightArr[rightIndex]) {
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

//    delete[] leftArr;
//    delete[] rightArr;
    /// ^^gave error when testing other lists soo...



    ///if somethings doesnt work its bc of this commented out code-- so lmk so i can fix
//    while(leftIndex < leftArrSize) {
//        arr[arrIndex] = leftArr[leftIndex];
//        leftIndex++;
//        arrIndex++;
//    }
//
//    while(rightIndex < rightArrSize) {
//        arr[arrIndex] = rightArr[rightIndex];
//        rightIndex++;
//        arrIndex++;
//    }

}

#endif //INC_22S_PA02_MERGESORT_H
