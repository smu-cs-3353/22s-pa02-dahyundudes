//
// Created by Zachary on 3/10/2022.
//

#ifndef INC_22S_PA02_RUNNER_H
#define INC_22S_PA02_RUNNER_H

#include <fstream>

#include "Profiler.h"

class Runner {
private:
    Profiler<int> pInt;
    Profiler<string> pString;
public:
    void readFile(string);

    void sortInt(ofstream&);

    void sortString(ofstream&);
};


#endif //INC_22S_PA02_RUNNER_H
