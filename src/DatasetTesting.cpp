//
// Created by Daniel Ryan on 3/10/22.
//

#include "DatasetTesting.h"


DatasetTesting::DatasetTesting() {

    size = 100;

    random = new int[size];
    ascending = new int[size];
    partlyAscending = new int[size];
    twentyDups = new int[size];
    fourtyDups = new int[size];
}

void DatasetTesting::readData() {
    std::ifstream ifs;

    ifs.open("data/100_sets/random_noDup.txt");

    if(!ifs.is_open()) {
        std::cout << "error reading file" << std::endl;
        return;
    }

    std::cout << std::endl;
    int s = 0;
    ifs >> s;
    for(int i = 0; i < s; i++) {
        ifs >> random[i];
        std::cout << random[i] << ",";
    }

    std::cout << std::endl;

    Sort<int>* sort = new MergeSort<int>(random, size);
    int* result = sort->sort();
    for(int i = 0; i < size; i++)
        std::cout << result[i] << ",";


}


