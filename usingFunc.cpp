#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include "usingFunc.h"
#include "SORTINGALGORITHM.h"
using namespace std;

void sortingAlgo(string algo, vector<int> &a, unsigned long long &cmp)
{
    if (algo == "selection-sort")
        selectionSort(a, cmp);
    else if (algo == "bubble-sort")
        bubbleSort(a, cmp);
    else if (algo == "insertion-sort")
        insertionSort(a, cmp);
    else if (algo == "binary-insertion-sort")
        binaryInsertionSort(a, cmp);
    else if (algo == "shell-sort")
        shellSort(a, cmp);
    else if (algo == "shaker-sort")
        shakerSort(a, cmp);
    else if (algo == "merge-sort")
        mergeSort(a, 0, a.size() - 1, cmp);
    else if (algo == "quick-sort")
        quickSort(a, 0, a.size() - 1, cmp);
    else if (algo == "heap-sort")
        heapSort(a, cmp);
    else if (algo == "flash-sort")
        flashSort(a, cmp);
    else if (algo == "radix-sort")
        radixSort(a, cmp);
    else if (algo == "counting-sort")
        countingSort(a, cmp);
}
int checkValidInputOrder(string inputOrder)
{
    vector<string> orders(4);
    orders[0] = "-rand";
    orders[1] = "-sorted";
    orders[2] = "-rev";
    orders[3] = "-nsorted";

    for (int i = 0; i < orders.size(); i++)
    {
        if (inputOrder == orders[i])
            return i;
    }

    return -1;
}
bool checkValidFile(string fileName)
{
    if (fileName.length() >= 4 && fileName.substr(fileName.length() - 4) == ".txt")
    {
        return true;
    }
    return false;
}
bool checkValidOutputParam(string outputParam)
{
    vector<string> params(3);
    params[0] = "-time";
    params[1] = "-comp";
    params[2] = "-both";
    for (int i = 0; i < 3; i++)
    {
        if (outputParam == params[i])
            return true;
    }
    return false;
}
void readInputFile(string fileName, vector<int> &a)
{
    ifstream inFile(fileName);
    if (!inFile)
    {
        return;
    }
    int size;
    inFile >> size;
    a.resize(size);
    for (int i = 0; i < size; i++)
    {
        inFile >> a[i];
    }
    inFile.close();
}
void outputFile(vector<int> &a, string fileName)
{
    ofstream outFile(fileName);
    if (!outFile)
    {
        return;
    }
    outFile << a.size() << "\n";
    for (int i = 0; i < a.size(); i++)
    {
        outFile << a[i] << " ";
    }
    outFile.close();
}
void convertOrder(string &order)
{
    if (order == "-rand")
        order = "Randomized";
    else if (order == "-sorted")
        order = "Sorted";
    else if (order == "-rev")
        order = "Reversed";
    else if (order == "-nsorted")
        order = "Nearly Sorted";
}
void printFormattedMetric(double value)
{
    if (value >= 10000000)
    {
        cout << scientific << uppercase << setprecision(2) << value;
        cout << defaultfloat;
    }
    else
    {
        cout << (unsigned long long)value;
    }
}
void printTime(string &order, int time)
{
    if (order != "")
    {
        convertOrder(order);
        cout << "\nInput Order: " << order << endl;
    }
    cout << "-----------------------------" << endl;
    cout << "\nrunning time: ";
    printFormattedMetric(time);
    cout << endl;
}
void printCompare(string &order, unsigned long long cmp)
{
    if (order != "")
    {
        convertOrder(order);
        cout << "\nInput Order: " << order << endl;
    }
    cout << "-----------------------------" << endl;
    cout << "total comparision: ";
    printFormattedMetric(cmp);
    cout << endl;
}
void printBoth(string &order, unsigned long long cmp, int time)
{
    if (order != "")
    {
        convertOrder(order);
        cout << "\nInput Order: " << order << endl;
    }
    cout << "-----------------------------" << endl;
    cout << "\nrunning time: ";
    printFormattedMetric(time);
    cout << "\ntotal comparision: ";
    printFormattedMetric(cmp);
    cout << endl;
}
void printOutputComparison(string &order, int time1, int time2, unsigned long long cmp1, unsigned long long cmp2)
{
    if (order != "")
    {
        convertOrder(order);
        cout << "\nInput Order: " << order << endl;
    }
    cout << "-----------------------------" << endl;
    cout << "\nRunning Time: ";
    printFormattedMetric(time1);
    cout << " | ";
    printFormattedMetric(time2);
    cout << "\nComparisons: ";
    printFormattedMetric(cmp1);
    cout << " | ";
    printFormattedMetric(cmp2);
    cout << "\n";
}
