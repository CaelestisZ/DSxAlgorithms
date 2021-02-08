#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    s1.insert(5);

    s1.erase(s1.begin(), s1.find(30));

    set<int> s2(s1.begin(), s1.end());

    for (auto i = s2.begin(); i != s2.end(); i++)
    {
        cout << *i << "\t";
    }
    cout << endl;

    // lower bound and upper bound for set s1
    cout << "s1.lower_bound(40) : \n"
         << *s1.lower_bound(40)
         << endl;
    cout << "s1.upper_bound(40) : \n"
         << *s1.upper_bound(40)
         << endl;

    // lower bound and upper bound for set s2
    cout << "s2.lower_bound(40) :\n"
         << *s2.lower_bound(40)
         << endl;
    cout << "s2.upper_bound(40) : \n"
         << *s2.upper_bound(40)
         << endl;

    return 0;
}