#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void BFS(int graph[][7], int i, int n)
{
    queue<int> q;
    cout << i << "\t";
    int visited[7] = {0};
    visited[i] = 1;

    q.push(i);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int k = 1; k <= n; k++)
        {
            if (graph[u][k] == 1 && visited[k] == 0)
            {
                cout << k << "\t";
                visited[k] = 1;
                q.push(k);
            }
        }
    }
    cout << endl;
}

void DFS(int graph[][7], int u, int n)
{
    static int visited[7] = {0};

    if (visited[u] == 0)
    {
        cout << u << "\t";
        visited[u] = 1;
        for (int v = 1; v <= n; v++)
        {
            if (graph[u][v] == 1 && visited[v] == 0)
            {
                DFS(graph, v, n);
            }
        }
    }
}

int main()
{
    int graph[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 1, 1, 0, 0, 0},
                       {0, 1, 0, 0, 1, 0, 0},
                       {0, 1, 0, 0, 1, 0, 0},
                       {0, 0, 1, 1, 0, 1, 1},
                       {0, 0, 0, 0, 1, 0, 0},
                       {0, 0, 0, 0, 1, 0, 0}};

    BFS(graph, 1, 7);
    DFS(graph, 1, 7);
    cout << endl;
    return 0;
}