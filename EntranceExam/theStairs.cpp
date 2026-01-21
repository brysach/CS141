#include <iostream>
using namespace std;

int main()
{
    int n;
    int x = -1;
    cin >> n;
    int steps[n];
    for (int i = 0; i < n; i++)
    {
        cin >> steps[i];
    }
    bool stepFound = false;
    int i = 0;
    int realHeight;
    int difference[4];

    difference[0] = steps[i] - steps[i + 1];
    difference[1] = steps[i + 1] - steps[i + 2];
    if (difference[0] == difference[1])
    {
        realHeight = difference[0];
    }
    else
    {
        difference[2] = steps[i + 2] - steps[i + 3];
        difference[3] = steps[i + 3] - steps[i + 4];
        if (difference[1] == difference[2])
        {
            x = 0;
        }
        else if (difference[0] == difference[3])
        {
            x = 2;
        }
        else
        {
            x = 1;
        }
    }

    if (x < 0)
    {
        i = 2;
        while (!stepFound)
        {
            int newDifference1 = steps[i++] - steps[i];
            int newDifference2 = steps[i++] - steps[i];
            if (newDifference1 == realHeight && newDifference2 != realHeight)
            {
                stepFound = true;
                x = i;
            }
            else if (newDifference1 != realHeight && newDifference2 == realHeight)
            {
                stepFound = true;
                x = i - 2;
            }
            else if (newDifference1 != realHeight && newDifference2 != realHeight)
            {
                // int newDifference3 = steps[i++] - steps[i];
                stepFound = true;
                x = i - 1;
            }
        }
    }

    cout << x + 1 << endl;
    return 0;
}