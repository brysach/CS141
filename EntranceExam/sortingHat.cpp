#include <iostream>
#include <string>
#include <cstring>
#include <utility>
#include <vector>

using namespace std;

void quickSort(vector<pair<string, char>> &, int, int);
int partition(vector<pair<string, char>> &, int, int);
void swap(pair<string, char> &, pair<string, char> &);

int main()
{
    int size;
    vector<pair<string, char>> students;
    string name;
    char house = ' ';

    cin >> size;
    cin.ignore();
    for (int i = 0; i < size; i++)
    {
        getline(cin, name, ' ');
        cin.get(house);
        students.emplace_back(make_pair(name, house));
        cin.ignore(20, '\n');
    }

    quickSort(students, 0, size - 1);

    // bool swap;

    // do
    // {
    //     swap = false;
    //     for (int i = 0; i < size - 1; i++)
    //     {
    //         if (students[i].second > students[i + 1].second)
    //         {
    //             pair<string, char> temp = students[i];
    //             students[i] = students[i + 1];
    //             students[i + 1] = temp;
    //             swap = true;
    //         }
    //         else if (students[i].second == students[i + 1].second)
    //         {
    //             string str1 = students[i].first;
    //             string str2 = students[i + 1].first;
    //             if (str1.compare(str2) > 0)
    //             {
    //                 pair<string, char> temp = students[i];
    //                 students[i] = students[i + 1];
    //                 students[i + 1] = temp;
    //                 swap = true;
    //             }
    //         }
    //     }

    // } while (swap);

    int i = 0;
    cout << "Gryffindor" << endl;
    while (students[i].second == 'G')
    {
        cout << students[i].first << endl;
        i++;
    }
    cout << "Hufflepuff" << endl;
    while (students[i].second == 'H')
    {
        cout << students[i].first << endl;
        i++;
    }
    cout << "Ravenclaw" << endl;
    while (students[i].second == 'R')
    {
        cout << students[i].first << endl;
        i++;
    }
    cout << "Slytherin" << endl;
    while (students[i].second == 'S' && i < size)
    {
        cout << students[i].first << endl;
        i++;
    }

    return 0;
}

void quickSort(vector<pair<string, char>> &students, int start, int end)
{
    int pivot;

    if (start < end)
    {
        pivot = partition(students, start, end);
        quickSort(students, start, pivot - 1);
        quickSort(students, pivot + 1, end);
    }
}

int partition(vector<pair<string, char>> &students, int start, int end)
{
    int mid = (start + end) / 2;
    swap(students[start], students[mid]);
    int pivotIndex = start;
    pair<string, char> pivot = students[pivotIndex];
    for (int i = start + 1; i <= end; i++)
    {
        if (students[i].second < pivot.second)
        {
            pivotIndex++;
            swap(students[i], students[pivotIndex]);
        }
        else if (students[i].second == pivot.second && students[i].first.compare(pivot.first) < 0)
        {
            pivotIndex++;
            swap(students[i], students[pivotIndex]);
        }
    }
    swap(students[start], students[pivotIndex]);
    return pivotIndex;
}

void swap(pair<string, char> &student1, pair<string, char> &student2)
{
    pair<string, char> temp;
    temp = student1;
    student1 = student2;
    student2 = temp;
}
