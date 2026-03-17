#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include "SORTINGALGORITHM.h"
#include "dataGenerator.h"
#include "usingFunc.h"
using namespace std;
using namespace std::chrono;

int main(int argc, char *argv[])
{
    if (argc == 5)
    {
        string mode = argv[1];
        if (mode == "-a")
        {
            cout << "ALGORITHM MODE";
            string algo = argv[2];
            cout << "\nAlgorithm: " << algo;
            if (checkValidFile(argv[3]))
            {
                if (checkValidOutputParam(argv[4]))
                {
                    vector<int> a;
                    readInputFile(argv[3], a);
                    unsigned long long cmp = 0;
                    cout << "\nInput File: " << argv[3];
                    cout << "\nInput Size: " << a.size();
                    auto start = high_resolution_clock::now();
                    sortingAlgo(algo, a, cmp);
                    auto end = high_resolution_clock::now();
                    auto duration = duration_cast<milliseconds>(end - start).count();
                    outputFile(a, "output.txt");
                    string order = "";
                    string param = argv[4];
                    if (param == "-time")
                        printTime(order, duration);
                    else if (param == "-comp")
                        printCompare(order, cmp);
                    else if (param == "-both")
                        printBoth(order, cmp, duration);
                }
            }
            else
            {
                if (checkValidOutputParam(argv[4]))
                {
                    cout << "\nInput Size: " << stoi(argv[3]);
                    vector<int> a;
                    vector<int> a1;
                    vector<int> a2;
                    vector<int> a3;
                    string order1 = "-rand";
                    string order2 = "-sorted";
                    string order3 = "-nsorted";
                    string order4 = "-rev";
                    unsigned long long cmp1, cmp2, cmp3, cmp4;
                    cmp1 = cmp2 = cmp3 = cmp4 = 0;
                    generateData(a, stoi(argv[3]), 0);
                    outputFile(a, "input_1.txt");
                    generateData(a1, stoi(argv[3]), 3);
                    outputFile(a1, "input_2.txt");
                    generateData(a2, stoi(argv[3]), 1);
                    outputFile(a2, "input_3.txt");
                    generateData(a3, stoi(argv[3]), 2);
                    outputFile(a3, "input_4.txt");
                    auto start1 = high_resolution_clock::now();
                    sortingAlgo(algo, a, cmp1);
                    auto end1 = high_resolution_clock::now();
                    auto duration1 = duration_cast<milliseconds>(end1 - start1).count();
                    string param = argv[4];
                    if (param == "-time")
                        printTime(order1, duration1);
                    else if (param == "-comp")
                        printCompare(order1, cmp1);
                    else if (param == "-both")
                        printBoth(order1, cmp1, duration1);
                    auto start2 = high_resolution_clock::now();
                    sortingAlgo(algo, a1, cmp2);
                    auto end2 = high_resolution_clock::now();
                    auto duration2 = duration_cast<milliseconds>(end2 - start2).count();
                    if (param == "-time")
                        printTime(order3, duration2);
                    else if (param == "-comp")
                        printCompare(order3, cmp2);
                    else if (param == "-both")
                        printBoth(order3, cmp2, duration2);
                    auto start3 = high_resolution_clock::now();
                    sortingAlgo(algo, a2, cmp3);
                    auto end3 = high_resolution_clock::now();
                    auto duration3 = duration_cast<milliseconds>(end3 - start3).count();
                    if (param == "-time")
                        printTime(order2, duration3);
                    else if (param == "-comp")
                        printCompare(order2, cmp3);
                    else if (param == "-both")
                        printBoth(order2, cmp3, duration3);
                    auto start4 = high_resolution_clock::now();
                    sortingAlgo(algo, a3, cmp4);
                    auto end4 = high_resolution_clock::now();
                    auto duration4 = duration_cast<milliseconds>(end4 - start4).count();
                    if (param == "-time")
                        printTime(order4, duration4);
                    else if (param == "-comp")
                        printCompare(order4, cmp4);
                    else if (param == "-both")
                        printBoth(order4, cmp4, duration4);
                }
            }
        }
        else if (mode == "-c")
        {
            cout << "COMPARE MODE";
            string algo1 = argv[2];
            string algo2 = argv[3];
            cout << "Algorithm: " << algo1 << " | " << algo2;
            if (checkValidFile(argv[4]))
            {
                cout << "Input File: " << argv[4];
                vector<int> a1;
                vector<int> a2;
                unsigned long long cmp1, cmp2;
                cmp1 = cmp2 = 0;
                readInputFile(argv[4], a1);
                cout << "Input Size: " << a1.size();
                a2 = a1;
                auto start1 = high_resolution_clock::now();
                sortingAlgo(algo1, a1, cmp1);
                auto end1 = high_resolution_clock::now();
                auto duration1 = duration_cast<milliseconds>(end1 - start1).count();
                auto start2 = high_resolution_clock::now();
                sortingAlgo(algo2, a2, cmp2);
                auto end2 = high_resolution_clock::now();
                auto duration2 = duration_cast<milliseconds>(end2 - start2).count();
                string order = "";
                printOutputComparison(order, duration1, duration2, cmp1, cmp2);
            }
        }
    }
    else if (argc == 6)
    {
        string mode = argv[1];
        if (mode == "-a")
        {
            cout << "ALGORITHM MODE";
            string algo = argv[2];
            cout << "\nAlgorithm: " << algo;
            cout << "\nInput Size: " << stoi(argv[3]);
            int order = checkValidInputOrder(argv[4]);
            if (order != -1)
            {
                string order1 = argv[4];
                cout << "\nInput Order: " << argv[4];
                vector<int> a;
                unsigned long long cmp = 0;
                generateData(a, stoi(argv[3]), order);
                outputFile(a, "input.txt");
                auto start = high_resolution_clock::now();
                sortingAlgo(algo, a, cmp);
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<milliseconds>(end - start).count();
                outputFile(a, "output.txt");
                string param = argv[5];
                if (param == "-time")
                    printTime(order1, duration);
                else if (param == "-comp")
                    printCompare(order1, cmp);
                else if (param == "-both")
                    printBoth(order1, cmp, duration);
            }
        }
        else if (mode == "-c")
        {
            cout << "COMPARE MODE";
            string algo1 = argv[2];
            string algo2 = argv[3];
            cout << "\nAlgorithm: " << algo1 << " | " << algo2;
            cout << "\nInput Size: " << stoi(argv[4]);
            string order = argv[5];
            int ordercheck = checkValidInputOrder(order);
            if (ordercheck != -1)
            {
                vector<int> a1, a2;
                generateData(a1, stoi(argv[4]), ordercheck);
                outputFile(a1, "input.txt");
                unsigned long long cmp1, cmp2;
                cmp1 = cmp2 = 0;
                a2 = a1;
                auto start1 = high_resolution_clock::now();
                sortingAlgo(algo1, a1, cmp1);
                auto end1 = high_resolution_clock::now();
                auto duration1 = duration_cast<milliseconds>(end1 - start1).count();
                auto start2 = high_resolution_clock::now();
                sortingAlgo(algo2, a2, cmp2);
                auto end2 = high_resolution_clock::now();
                auto duration2 = duration_cast<milliseconds>(end2 - start2).count();
                printOutputComparison(order, duration1, duration2, cmp1, cmp2);
            }
        }
    }
}