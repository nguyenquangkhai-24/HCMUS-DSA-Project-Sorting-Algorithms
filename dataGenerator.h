#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <vector>
using namespace std;

void generateRandomData(vector<int> &a, int n);
void generateSortedData(vector<int> &a, int n);
void generateReverseData(vector<int> &a, int n);
void generateNearlySortedData(vector<int> &a, int n);
void generateData(vector<int> &a, int n, int dataType);