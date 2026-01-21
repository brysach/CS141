#include <iostream>
#include <map>
#include <queue>
using namespace std;

int BFS(int *, const int *, const bool *, const int *, bool *, int);

int main()
{
    int n, m;
    cin >> n >> m;
    int childrenNumber = n - 1;

    int *parents = new int[n];
    int *children = new int[childrenNumber];
    int *traitors = new int[m];
    bool *isTraitor = new bool[n];
    bool *visited = new bool[n];
    // map<int, int> childCountPerParent;
    int *childCountPerParent = new int[n];
    int *firstChildIndex = new int[n];
    int *iterator = new int[n];
    int maxComponent = 0;

    parents[0] = -1;
    // iterator[0] = -1;
    // firstChildIndex[0] = -1;
    // isTraitor[0] = false;
    // visited[0] = false;
    //  childCountPerParent[0] = 0;
    for (int i = 0; i < n; i++)
    {
        firstChildIndex[i] = -1;
        iterator[i] = -1;
        // children[i - 1] = -1;
        isTraitor[i] = false;
        visited[i] = false;
        childCountPerParent[i] = 0;
        // cin >> parents[i];
        // childCountPerParent[parents[i]]++;
    }

    for (int i = 1; i < n; i++)
    {
        cin >> parents[i];
        childCountPerParent[parents[i]]++;
    }
    int adder = 0;
    for (int i = 0; i < n; i++)
    {
        if (childCountPerParent[i] != 0)
        {
            firstChildIndex[i] = adder;
        }
        adder += childCountPerParent[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> traitors[i];
        isTraitor[traitors[i]] = true;
    }

    for (int i = 1; i < n; i++)
    {
        if (iterator[parents[i]] == -1)
        {
            iterator[parents[i]] = firstChildIndex[parents[i]];
        }
        else
            iterator[parents[i]]++;
        children[iterator[parents[i]]] = i;
    }

    // cout << childCountPerParent[0];

    // for (int i = 0; i < childrenNumber; i++)
    // {
    //     cout << children[i] << " ";
    // }
    // cout << endl;
    for (int i = 0; i < n; i++)
    {
        // cout << firstChildIndex[i] << " ";
        if (!isTraitor[i] && !visited[i])
        {
            int componentSize = BFS(children, firstChildIndex, isTraitor, childCountPerParent, visited, i);
            if (maxComponent < componentSize)
            {
                maxComponent = componentSize;
                if (maxComponent > n / 2)
                    break;
            }
        }
    }

    cout << maxComponent;
    delete[] parents;
    delete[] children;
    delete[] traitors;
    delete[] firstChildIndex;
    delete[] iterator;
    delete[] isTraitor;
    delete[] visited;
    return 0;
}

int BFS(int *children, const int *firstChildIndex, const bool *isTraitor, const int *childCountPerParent, bool *visited, int start)
{
    int node;
    int nodesVisited = 1;
    queue<int> neighbors;
    neighbors.push(start);
    while (neighbors.size() > 0)
    {
        node = neighbors.front();
        neighbors.pop();
        visited[node] = true;
        if (firstChildIndex[node] != -1)
        {
            for (int i = firstChildIndex[node]; i < firstChildIndex[node] + childCountPerParent[node]; i++)
            {
                if (!isTraitor[children[i]])
                {
                    neighbors.push(children[i]);
                    visited[children[i]] = true;
                    nodesVisited++;
                }
            }
        }
    }
    return nodesVisited;
}