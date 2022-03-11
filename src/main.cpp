//
// Created by Zachary on 3/2/2022.
//

#include <iostream>
#include <iomanip>
#include <chrono>
#include "Runner.h"

using namespace std;

int main(int argc, char** argv) {
//    if (argc == 1)
//        cout << "No arguments provided." << endl;
//    else {
        cout << "Hello CS3353, your arguments were: ";
        for (int i = 1; i < argc; i++) {
            cout << argv[i];
            if (i < argc - 1)
                cout << ", ";
        }
        cout << endl;

        Runner r;
        for (int i = 1; i < argc; i++) {
            string fileName(argv[i]);
            r.readFile(argv[i]);
            ofstream out(fileName.substr(0,fileName.size()-4)+"_out.txt");
            r.sortInt(out);
            r.sortString(out);
        }
//    }
}