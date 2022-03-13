//
// Created by Zachary on 3/10/2022.
//

#ifndef INC_22S_PA02_RUNNER_H
#define INC_22S_PA02_RUNNER_H

#include <fstream>
#include <iostream>
#include <cstring>

#include "Profiler.h"
#include "DSString.h"

class Runner {
private:
    Profiler<int>* pInt;
    Profiler<string>* pString;
    DSString filePath;
public:
    Runner();

    ~Runner();

    void readFile(string);

    void sortInt(ofstream*&);

    void sortString(ofstream*&);
};


#endif //INC_22S_PA02_RUNNER_H
