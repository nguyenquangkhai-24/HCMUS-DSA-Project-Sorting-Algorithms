#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void sortingAlgo(string algo, vector<int> &a, unsigned long long &cmp);
int checkValidInputOrder(string inputOrder);
bool checkValidFile(string fileName);
bool checkValidOutputParam(string outputParam);
void readInputFile(string fileName, vector<int> &a);
void outputFile(vector<int> &a, string fileName);
void convertOrder(string &order);
void printFormattedMetric(double value);
void printTime(string &order, int time);
void printCompare(string &order, unsigned long long cmp);
void printBoth(string &order, unsigned long long cmp, int time);
void printOutputComparison(string &order, int time1, int time2, unsigned long long cmp1, unsigned long long cmp2);