#include <iostream>
using namespace std;

int main()
{
    int galleons = 0;
    int sickles = 0;
    int knuts;

    cin >> knuts;

    while (knuts >= 29)
    {
        knuts -= 29;
        sickles++;
    }

    while (sickles >= 17)
    {
        sickles -= 17;
        galleons++;
    }

    cout << galleons << " " << sickles << " " << knuts;
    return 0;
}