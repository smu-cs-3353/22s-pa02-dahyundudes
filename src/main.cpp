//
// Created by Zachary on 3/2/2022.
//

#include <iostream>
#include <iomanip>
#include <chrono>
#include "Runner.h"
#include "DSString.h"

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
        cout << endl << endl;

        Runner r;
        ofstream* out = new ofstream[6];

        out[0].open("./data/InsertionSort.csv");
        out[1].open("./data/QuickSort.csv");
        out[2].open("./data/ShellSort.csv");
        out[3].open("./data/MergeSort.csv");
        out[4].open("./data/IntroSort.csv");
        out[5].open("./data/TimSort.csv");

        for (int i = 0; i < 6; i++)
            out[i] << fixed << setprecision(7) << "File,Size,Time" << endl;

        // loop through the list of arguments
        for (int i = 1; i < argc; i++) {
            // print out the argument
            cout << argv[i] << endl;

            // cast it to a DSString
            DSString fileName(argv[i]);

            r.readFile(argv[i]);

            cout << endl;
            cout << "Int Sort: " << endl;
            r.sortInt(out);
            cout << "String Sort: " << endl;
            r.sortString(out);
            cout << endl;
        }

        for (int i = 0; i < 6; i++)
            out[i].close();
//    }
}