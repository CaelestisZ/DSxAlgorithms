#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main()
{
    list<int> dlist1, dlist2;
    for (int i = 1; i <= 10; i++)
    {
        dlist1.push_back(i);
    }

    for (auto i = dlist1.begin(); i != dlist1.end(); i++)
    {
        cout << "\t" << *i;
    }
    cout << endl;

    dlist1.pop_back();

    dlist1.sort();

    dlist1.reverse();

    for (auto i = dlist1.begin(); i != dlist1.end(); i++)
    {
        cout << "\t" << *i;
    }
    cout << endl;

    return 0;
}