//
// Created by Zachary on 3/2/2022.
//

#ifndef INC_22S_PA02_SORT_H
#define INC_22S_PA02_SORT_H

template <class T>
class Sort {
protected:
    T* data;
public:
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
    Sort(T*);
    /**
     * Destructor
     */
     ~Sort();

    /**
     * Sorts the data array and returns the result
     * @return T* array of templated elements
     */
    virtual T* sort();
};

#endif //INC_22S_PA02_SORT_H
