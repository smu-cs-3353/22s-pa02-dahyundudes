//
// Created by Zachary on 3/10/2022.
//

#include "Runner.h"

Runner::Runner() {
    pInt = nullptr;
    pString = nullptr;
}

Runner::~Runner() {
    delete pString;
    delete pInt;
}

void Runner::readFile(string filePath) {
    this->filePath = filePath;
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

    if (pString != nullptr)
        delete pString;
    if (pInt != nullptr)
        delete pInt;
    pString = new Profiler<string>(arrString, size);
    pInt = new Profiler<int>(arrInt, size);
    delete[] arrString;
    delete[] arrInt;
    file.close();
}

void Runner::sortInt(ofstream*& out) {
    double* time = pInt->sortDatasets();
    for (int i = 0; i < 6; i++) {
        out[i] << filePath << ",";
        out[i] << pInt->getSize() << ",";
        out[i] << time[i] << endl;
    }
    delete[] time;
}

void Runner::sortString(ofstream*& out) {
    double* time = pString->sortDatasets();
    for (int i = 0; i < 6; i++) {
        out[i] << filePath << ",";
        out[i] << pString->getSize() << ",";
        out[i] << time[i] << endl;
    }
    delete[] time;
}