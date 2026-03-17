
#include <iostream>
#include "dataGenerator.h"
#include <fstream>
#include <cmath>
#include <time.h>
#include <vector>
using namespace std;

void generateRandomData(vector<int> &a, int n)
{
	a.resize(n);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand()%n;
	}
}
void generateSortedData(vector<int> &a, int n)
{
	a.resize(n);
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}
void generateReverseData(vector<int> &a, int n)
{
	a.resize(n);
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}
void generateNearlySortedData(vector<int> &a, int n)
{
	a.resize(n);
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int) time(NULL));
	for (int i = 0; i < 0.05*n; i ++)
	{
		int r1 = rand()%n;
		int r2 = rand()%n;
		swap(a[r1],a[r2]);
	}
}
void generateData(vector<int> &a, int n, int dataType)
{
	switch (dataType)
	{
	case 0:
		generateRandomData(a, n);
		break;
	case 1:
		generateSortedData(a, n);
		break;
	case 2:
		generateReverseData(a, n);
		break;
	case 3:
		generateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}