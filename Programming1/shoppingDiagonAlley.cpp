#include <iostream>
#include <vector>

using namespace std;

void mergeSort(const vector<int> &, vector<int> &, int, int);
vector<int> merge(const vector<int> &, int, int, int, int);

int main()
{
    int galleons, n;
    cin >> galleons >> n;
    vector<int> prices(n);
    vector<int> fooPrices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    mergeSort(prices, fooPrices, 0, n);
    return 0;
}

void mergeSort(const vector<int> &prices, vector<int> &fooPrices, int start, int end)
{
    if (end - start <= 1)
    {
        return;
    }
    else
    {
        int middle = start + (end - start) / 2;
        mergeSort(prices, fooPrices, start, middle);
        mergeSort(prices, fooPrices, middle, end);
        fooPrices = merge(prices, start, middle, middle + 1, end);
        for (int nums : fooPrices)
        {
            cout << nums << " ";
        }

        cout << endl;
    }
}

vector<int> merge(const vector<int> &prices, int start1, int end1, int start2, int end2)
{
    int i = start1, j = start2, k = 0;
    vector<int> tempPrices(end1 - start1 + end2 - start2);
    while (i < end1 && j < end2)
    {
        if (prices[i] < prices[j])
        {
            tempPrices[k++] = prices[i++];
        }
        else
        {
            tempPrices[k++] = prices[j++];
        }
    }
    if (i < end1)
    {
        while (i < end1)
        {
            tempPrices[k++] = prices[i++];
        }
    }
    if (j < end2)
    {
        while (j < end2)
        {
            tempPrices[k++] = prices[j++];
        }
    }
    return tempPrices;
}