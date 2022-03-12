//
// Created by Daniel Ryan on 3/8/22.
//

#ifndef INC_22S_PA02_INTROSORT_H
#define INC_22S_PA02_INTROSORT_H

#include "Sort.h"
#include <random>
#include <algorithm>

using namespace std;

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

    void heapify(T*, int, int);

    void heapSort(T*, int);
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
//        T* t = arr + end;
//        std::make_heap(arr+begin, t+1);   //TODO: implement heap sort, not sure if required
//        std::sort_heap(arr+begin, t+1);
        heapSort(arr+begin, size);
//        for(int i = begin; i < end; i++) {
//            std::cout << arr[i] << ",";
//            if(arr[i] >= arr[i+1])
//                std::cout << "bad" << std::endl;
//        }
//        std::cout << std::endl;
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
//    int pivot = low + (high-low)/2;
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

    for(int i = size - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }

}

#endif //INC_22S_PA02_INTROSORT_H
