//
// Created by Zachary on 3/10/2022.
//

#include "Runner.h"

Runner::Runner() {

}

Runner::~Runner() {
    delete pString;
    delete pInt;
}

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

    pString = new Profiler<string>(arrString, size);
    pInt = new Profiler<int>(arrInt, size);
    delete[] arrString;
    delete[] arrInt;
    file.close();
}

void Runner::sortInt(ofstream& out) {
    auto* time = pInt->sortDatasets();
    for (int i = 0; i < 7; i++) {
        out << time[i].count();
        if (i < 6)
            out << ",";
    }
    out << endl;
    delete[] time;
}

void Runner::sortString(ofstream& out) {
    auto* time = pString->sortDatasets();
    for (int i = 0; i < 7; i++) {
        out << time[i].count();
        if (i < 6)
            out << ",";
    }
    out << endl;
    delete[] time;
}