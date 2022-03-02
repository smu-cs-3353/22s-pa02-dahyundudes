//
// Created by Zachary on 3/2/2022.
//

#ifndef INC_22S_PA02_TESTSORT_H
#define INC_22S_PA02_TESTSORT_H

#include "Sort.h"

template <class T>
class TestSort : public Sort<T> {
public:
    TestSort();
    TestSort(T*);

    T* sort();
};


#endif //INC_22S_PA02_TESTSORT_H
