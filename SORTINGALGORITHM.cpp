
#include "SORTINGALGORITHM.h"
#include <climits>
#include <vector>
#include <algorithm>

void selectionSort(vector<int> &a, unsigned long long &cmp)
{
    int n = a.size();
    for (int i = 0; (++cmp) && i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; (++cmp) && j < n; j++)
        {
            if ((++cmp) && a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int t = a[min];
            a[min] = a[i];
            a[i] = t;
        }
    }
}

void bubbleSort(vector<int> &a, unsigned long long &cmp)
{
    int n = a.size();
    for (int i = 0; (++cmp) && i < n - 1; i++)
    {
        bool flag = false;
        for (int j = n - 1; (++cmp) && j > i; j--)
        {
            if ((++cmp) && a[j] < a[j - 1])
            {
                int t = a[j - 1];
                a[j - 1] = a[j];
                a[j] = t;
                flag = true;
            }
        }
        if (flag == false)
            break;
    }
}
void shellSort(vector<int> &a, unsigned long long &cmp)
{
    int size = a.size();

    for (int gap = size / 2; (++cmp) && (gap > 0); gap /= 2)
    {
        for (int i = gap; (++cmp) && (i < size); i++)
        {
            int temp = a[i];

            int j;
            for (j = i; (++cmp) && (j >= gap) && (++cmp) && (a[j - gap] > temp); j -= gap)
            {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
    }
}
void insertionSort(vector<int> &a, unsigned long long &cmp)
{
    int size = a.size();

    for (int i = 1; (++cmp) && (i < size); i++)
    {
        int key = a[i];
        int j = i - 1;

        while ((++cmp && j >= 0) && (++cmp && a[j] > key))
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
void flashSort(vector<int> &a, unsigned long long &cmp)
{
    int size = a.size();

    if ((++cmp) && size <= 1)
        return;

    int minVal = a[0], maxIdx = 0;

    for (int i = 1; (++cmp) && i < size; i++)
    {
        if ((++cmp) && a[i] < minVal)
            minVal = a[i];

        if ((++cmp) && a[i] > a[maxIdx])
            maxIdx = i;
    }

    if ((++cmp) && minVal == a[maxIdx])
        return;

    int m = int(0.45 * size);
    vector<int> L(m, 0);
    double c1 = (double)(m - 1) / (a[maxIdx] - minVal);

    for (int i = 0; (++cmp) && i < size; i++)
    {
        int k = int(c1 * (a[i] - minVal));
        L[k]++;
    }

    for (int i = 1; i < m; i++)
    {
        L[i] += L[i - 1];
    }

    int count = 0, i = 0, k = m - 1, hold;

    while ((++cmp) && count < size - 1)
    {
        while ((++cmp) && i > L[k] - 1)
        {
            i++;
            k = int(c1 * (a[i] - minVal));
        }
        hold = a[i];
        while ((++cmp) && i != L[k])
        {
            k = int(c1 * (hold - minVal));
            swap(hold, a[L[k] - 1]);
            L[k]--;
            count++;
        }
    }
    insertionSort(a, cmp);
}
void countingSortForRadix(vector<int> &a, int exp, unsigned long long &cmp)
{
    int size = a.size();
    vector<int> output(size);
    int count[10] = {0};

    for (int i = 0; (++cmp) && i < size; i++)
        count[(a[i] / exp) % 10]++;

    for (int i = 1; (++cmp) && i < 10; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; (++cmp) && i >= 0; i--)
    {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    for (int i = 0; (++cmp) && i < size; i++)
        a[i] = output[i];
}
void radixSort(vector<int> &a, unsigned long long &cmp)
{
    if ((++cmp) && a.empty())
        return;

    int maxVal = *max_element(a.begin(), a.end());

    for (int exp = 1; (++cmp) && maxVal / exp > 0; exp *= 10)
    {
        countingSortForRadix(a, exp, cmp);
    }
}
void merge(vector<int> &a, int left, int right, int mid, unsigned long long &cmp)
{
    vector<int> tmp1(mid - left + 1);
    vector<int> tmp2(right - mid);
    for (int i = 0; (++cmp) && i < mid - left + 1; i++)
    {
        tmp1[i] = a[i + left];
    }
    for (int i = 0; (++cmp) && i < right - mid; i++)
    {
        tmp2[i] = a[i + mid + 1];
    }
    int i = 0;
    int j = 0;
    while ((++cmp) && i < tmp1.size() && j < tmp2.size())
    {
        if ((++cmp) && tmp1[i] <= tmp2[j])
        {
            a[left++] = tmp1[i];
            i++;
        }
        else
        {
            a[left++] = tmp2[j];
            j++;
        }
    }
    while ((++cmp) && i < tmp1.size())
    {
        a[left++] = tmp1[i];
        i++;
    }
    while ((++cmp) && j < tmp2.size())
    {
        a[left++] = tmp2[j];
        j++;
    }
    return;
}
void mergeSort(vector<int> &a, int left, int right, unsigned long long &cmp)
{
    if ((++cmp) && left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(a, left, mid, cmp);
        mergeSort(a, mid + 1, right, cmp);
        merge(a, left, right, mid, cmp);
    }
    return;
}
int bigger(vector<int> &a, int left, int right, unsigned long long &cmp)
{
    ++cmp;
    return a[left] > a[right] ? left : right;
}
int medianOfThree(vector<int> &a, int left, int right, unsigned long long &cmp)
{
    int mid = left + (right - left) / 2;
    int bigE = bigger(a, left, bigger(a, mid, right, cmp), cmp);
    if ((++cmp) && bigE == left)
        return bigger(a, mid, right, cmp);
    if ((++cmp) && bigE == right)
        return bigger(a, left, mid, cmp);
    ++cmp;
    return bigger(a, left, right, cmp);
}
int partition(vector<int> &a, int left, int right, unsigned long long &cmp)
{
    int median = medianOfThree(a, left, right, cmp);
    swap(a[median], a[right]);
    int pivot = a[right];
    int box = left - 1;
    for (int i = left; (++cmp) && i < right; i++)
    {
        if ((++cmp) && a[i] <= pivot)
        {
            box++;
            swap(a[box], a[i]);
        }
    }
    ++box;
    swap(a[box], a[right]);
    return box;
}
void quickSort(vector<int> &a, int left, int right, unsigned long long &cmp)
{
    if ((++cmp) && left < right)
    {
        int p = partition(a, left, right, cmp);
        quickSort(a, left, p - 1, cmp);
        quickSort(a, p + 1, right, cmp);
    }
}
void countingSort(vector<int> &a, unsigned long long &cmp)
{
    int maxEle = INT_MIN;
    for (int i = 0; (++cmp) && i < a.size(); i++)
    {
        if ((++cmp) && a[i] > maxEle)
            maxEle = a[i];
    }
    vector<int> countAr(maxEle + 1);
    for (int i = 0; (++cmp) && i < a.size(); i++)
    {
        countAr[a[i]]++;
    }
    int index = 0;
    for (int i = 0; (++cmp) && i < countAr.size(); i++)
    {
        while ((++cmp) && countAr[i] > 0)
        {
            a[index++] = i;
            countAr[i]--;
        }
    }
    return;
}
void binaryInsertionSort(vector<int> &a, unsigned long long &cmp)
{
    int size = a.size();

    for (int i = 1; (++cmp) && i < size; i++)
    {
        int key = a[i];
        int left = 0, right = i - 1;

        while ((++cmp) && left <= right)
        {
            int mid = left + (right - left) / 2;

            if ((++cmp) && a[mid] > key)
                right = mid - 1;
            else
                left = mid + 1;
        }

        for (int j = i - 1; (++cmp) && j >= left; j--)
        {
            a[j + 1] = a[j];
        }
        a[left] = key;
    }
}
void shakerSort(vector<int> &a, unsigned long long &cmp)
{
    int left = 0, right = a.size() - 1;
    bool swapped;

    do
    {
        swapped = false;

        for (int i = left; (++cmp) && i < right; i++)
        {
            if ((++cmp) && a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }

        right--;
        for (int i = right; (++cmp) && i > left; i--)
        {
            if ((++cmp) && a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
                swapped = true;
            }
        }
        left++;
    } while ((++cmp) && swapped);
}
void heapify(vector<int> &a, int n, int i, unsigned long long &cmp)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if ((++cmp) && (left < n) && (++cmp) && (a[left] > a[largest]))
        largest = left;

    if ((++cmp) && (right < n) && (++cmp) && (a[right] > a[largest]))
        largest = right;

    if ((++cmp) && (largest != i))
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest, cmp);
    }
}

void heapSort(vector<int> &a, unsigned long long &cmp)
{
    int size = a.size();

    for (int i = size / 2 - 1; (++cmp) && (i >= 0); i--)
        heapify(a, size, i, cmp);

    for (int i = size - 1; (++cmp) && i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0, cmp);
    }
}