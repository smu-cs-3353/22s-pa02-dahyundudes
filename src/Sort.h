//
// Created by Zachary on 3/2/2022.
//

#ifndef INC_22S_PA02_SORT_H
#define INC_22S_PA02_SORT_H

template <class T>
class Sort {
public:
    T* data;
    int size;
    /**
     * Default Constructor
     */
    Sort();
    /**
     * Copy Constructor
     */
    Sort(const Sort<T>&);
    /**
     * Overloaded Constructor
     * @param T* array of templated elements
     */
    Sort(const T*, int s);
    /**
     * Destructor
     */
    ~Sort();

    /**
     * Sorts the data array and returns the result
     * @return T* array of templated elements
     */
    virtual T* sort();

    int getSize();
};

template<class T>
Sort<T>::Sort() {
    this->data = nullptr;
    this->size = 0;
}

template<class T>
Sort<T>::Sort(const Sort<T> &other) {
    if (other.size > 0) {
        this->data = new T[other.size];
        for (int i = 0; i < other.size; i++)
            this->data[i] = other.data[i];
    }
    this->size = other.size;
}

template<class T>
Sort<T>::Sort(const T *other, int s) {
    if (s > 0) {
        this->size = s;
        this->data = new T[this->size];
        for (int i = 0; i < this->size; i++) {
            this->data[i] = other[i];
        }
    }
}

template<class T>
Sort<T>::~Sort() {
    if (this->data != nullptr)
        delete[] this->data;
}

template<class T>
T *Sort<T>::sort() {
    return this->data;
}

template<class T>
int Sort<T>::getSize() {
    return size;
}

#endif //INC_22S_PA02_SORT_H
