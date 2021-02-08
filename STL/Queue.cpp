#include <iostream>
#include <queue>
#include <iterator>

using namespace std;

void display(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << "\t";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(3);
    q.push(6);
    q.push(1);
    q.push(15);
    q.push(43);
    q.push(23);
    q.push(12);

    display(q);

    return 0;
}