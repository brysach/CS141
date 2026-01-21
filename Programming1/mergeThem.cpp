#include <iostream>
#include <vector>
#include <utility>
using namespace std;

pair<int, int> divide(const vector<int> &, int, int, long long &);
pair<int, int> calculateCandies(vector<int>, int, int, int, int, int &);
int main()
{
    int n;
    long long candies = 0;
    cin >> n;
    vector<int> scores(n);
    for (int i = 0; i < n; i++)
    {
        cin >> scores[i];
    }

    pair<int, int> min_max = divide(scores, 0, n, candies);
    cout << candies;
    // for (int score : scores)
    // {
    //     cout << score << " ";
    // }
    return 0;
}

pair<int, int> divide(const vector<int> &scores, int first, int last, long long &candies)
{
    pair<int, int> leftPair;
    pair<int, int> rightPair;
    pair<int, int> pMinMax;
    if (last - first <= 1)
    {
        pMinMax = make_pair(scores[first], scores[first]);
        return pMinMax;
    }
    else
    {
        int middle = first + (last - first) / 2;
        leftPair = divide(scores, first, middle, candies);
        rightPair = divide(scores, middle, last, candies);
        if (leftPair.first < rightPair.first)
        {
            pMinMax.first = leftPair.first;
        }
        else
        {
            pMinMax.first = rightPair.first;
        }
        if (leftPair.second > rightPair.second)
        {
            pMinMax.second = leftPair.second;
        }
        else
        {
            pMinMax.second = rightPair.second;
        }
    }
    candies += pMinMax.second - pMinMax.first;
    return pMinMax;
}

// pair<int, int> calculateCandies(vector<int> scores, int leftStart, int leftEnd, int rightStart, int rightEnd, int &candies)
// {
//     pair<int, int> tempMinMax;
//     int min1, max1, minAbs = 0, maxAbs = 0;
//     if (leftEnd - leftStart == 1)
//     {
//         if (scores[leftStart] < scores[rightStart])
//         {
//             tempMinMax = make_pair(scores[leftStart], scores[rightStart]);
//         }
//         else
//         {
//             tempMinMax = make_pair(scores[rightStart], scores[leftStart]);
//         }
//     }

//     candies += tempMinMax.second - tempMinMax.first;
//     return tempMinMax;
// }