//
// Created by Zachary on 3/10/2022.
//

#include "Runner.h"

void Runner::readFile(string filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        throw std::logic_error("File not found.");
    }

    // temporary character array to read from the file
    char temp[32];
    file.getline(temp, 32, '\n');
    int size = atoi(temp);

    string* arrString = new string[size];
    int* arrInt = new int[size];

    for (int i = 0; i < size; i++) {
        file.getline(temp, 32, '\n');
        arrString[i] = temp;
        arrInt[i] = atoi(temp);
    }

    pString = Profiler<string>(arrString, size);
    pInt = Profiler<int>(arrInt, size);
}

void Runner::sortInt(ofstream& out) {
    auto* time = pInt.sortDatasets();
    for (int i = 0; i < sizeof(time); i++) {
        out << time[i].count();
        if (i < sizeof(time) - 1)
            out << ",";
    }
    out << endl;
}

void Runner::sortString(ofstream& out) {
    auto* time = pString.sortDatasets();
    for (int i = 0; i < sizeof(time); i++) {
        out << time[i].count();
        if (i < sizeof(time) - 1)
            out << ",";
    }
    out << endl;
}