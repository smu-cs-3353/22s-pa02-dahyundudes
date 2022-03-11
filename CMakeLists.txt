cmake_minimum_required(VERSION 3.16)
project(22s_pa02)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_RELEASE -O3)

configure_file(data/100_sets/random_noDup.txt data/100_sets/random_noDup.txt COPYONLY)


add_executable(pa02 src/main.cpp src/Sort.h src/SelectionSort.h src/InsertionSort.h src/DatasetTesting.cpp
        src/QuickSort.h src/TestSort.h src/ShellSort.h src/MergeSort.h src/IntroSort.h src/TimSort.h)
add_executable(pa02_test src/catch_setup.cpp src/test.cpp src/Sort.h)

