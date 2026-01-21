#include <iostream>
using namespace std;

void quickSort(int arr[], int, int);
int partition(int arr[], int, int);
void swap(int &, int &);
void printArr(const int arr[], const int);

int main()
{
    int arr[] = {1, 9, 3, 2, 4, 8, 7, 6, 5};
    int size = sizeof(arr) / sizeof(int);
    printArr(arr, size);
    quickSort(arr, 0, size - 1);
    printArr(arr, size);

    return 0;
}

void quickSort(int arr[], int start, int end)
{
    int pivotIndex;
    if (start < end)
    {
        pivotIndex = partition(arr, start, end);
        quickSort(arr, start, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
    }
}

int partition(int arr[], int start, int end)
{
    int mid = (start + end) / 2;
    swap(arr[start], arr[mid]);
    int pivotIndex = start;
    int pivot = arr[pivotIndex];

    for (int i = start + 1; i <= end; i++)
    {
        cout << "\tITERATION: " << i << endl;
        printArr(arr, end + 1);
        cout << "Pivot: " << pivot << " | PivotIndex: " << pivotIndex << endl
             << endl;
        if (arr[i] < pivot)
        {
            pivotIndex++;
            swap(arr[i], arr[pivotIndex]);
            cout << "Swapped: " << endl;
            printArr(arr, end + 1);
            cout << "Pivot: " << pivot << " | PivotIndex: " << pivotIndex << endl
                 << endl;
        }
    }
    swap(arr[start], arr[pivotIndex]);
    cout << "After last swap" << endl;
    printArr(arr, end + 1);
    cout << "Pivot Index: " << pivotIndex << endl
         << endl;
    return pivotIndex;
}

void swap(int &value1, int &value2)
{
    int temp = value1;
    value1 = value2;
    value2 = temp;
}

void printArr(const int arr[], const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}