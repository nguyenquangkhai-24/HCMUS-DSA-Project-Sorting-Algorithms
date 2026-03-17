#ifndef SORTINGALGORITHM_H
#define SORTINGALGORITHM_H

#include <vector>
using namespace std;

void selectionSort(vector<int> &a, unsigned long long &cmp);

void bubbleSort(vector<int> &a, unsigned long long &cmp);

void insertionSort(vector<int> &a, unsigned long long &cmp);

void binaryInsertionSort(vector<int> &a, unsigned long long &cmp);

void merge(vector<int> &a, int left, int right, int mid, unsigned long long &cmp);
void mergeSort(vector<int> &a, int left, int right, unsigned long long &cmp);

int bigger(vector<int> &a, int left, int right, unsigned long long &cmp);
int medianOfThree(vector<int> &a, int left, int right, unsigned long long &cmp);
int partition(vector<int> &a, int left, int right, unsigned long long &cmp);
void quickSort(vector<int> &a, int left, int right, unsigned long long &cmp);

void countingSort(vector<int> &a, unsigned long long &cmp);

void countingSortForRadix(vector<int> &a, int exp, unsigned long long &cmp);
void radixSort(vector<int> &a, unsigned long long &cmp);

void heapify(vector<int> &a, int n, int i, unsigned long long &cmp);
void heapSort(vector<int> &a, unsigned long long &cmp);

void shellSort(vector<int> &a, unsigned long long &cmp);

void shakerSort(vector<int> &a, unsigned long long &cmp);

void flashSort(vector<int> &a, unsigned long long &cmp);
#endif
