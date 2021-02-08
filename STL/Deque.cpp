#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm>

using namespace std;

void display(deque<int> d)
{
    for (auto i = d.begin(); i != d.end(); i++)
    {
        cout << *i << "\t";
    }
    cout << endl;
}

int main()
{
    deque<int> d1;

    d1.insert(d1.begin(), 2);
    d1.insert(d1.end(), 6);
    d1.insert(d1.begin(), 3);
    d1.insert(d1.begin(), 1);
    d1.insert(d1.begin(), 8);
    d1.insert(d1.begin(), 6);
    d1.insert(d1.begin(), 5);
    d1.push_front(0);

    display(d1);
}