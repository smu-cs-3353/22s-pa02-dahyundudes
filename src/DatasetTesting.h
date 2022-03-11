//
// Created by Daniel Ryan on 3/10/22.
//

#ifndef INC_22S_PA02_DATASETTESTING_H
#define INC_22S_PA02_DATASETTESTING_H

#include <fstream>
#include <iostream>

#include "Sort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "IntroSort.h"
#include "TimSort.h"

class DatasetTesting {
private:

    int size;

    int* random;
    int* ascending;
    int* partlyAscending;
    int* twentyDups;
    int* fourtyDups;

public:
    DatasetTesting();

    void readData();


};


#endif //INC_22S_PA02_DATASETTESTING_H
