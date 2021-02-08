#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v;

    int A[] = {7, 2, 3, 1, 3, 5, 6};
    sort(A, A + 6);

    cout << endl;

    for (int i = 0; i < 7; i++)
    {
        cout << A[i] << " ";
    }

    cout << endl;
    // assign all elements in the vector to zero
    // v.assign(10, 0);

    // Push elements to the end of the vector
    for (int i = 1; i <= 5; i++)
    {
        v.push_back(9 - i);
    }
    v.push_back(6);
    // pop elements from the end of the vector
    v.pop_back();

    // displaying elements by dereferencing the pointers
    for (auto iterator = v.begin(); iterator != v.end(); iterator++)
    {
        cout << *iterator << " ";
    }

    cout << endl;

    // Inserting elements at a specified position
    // v.insert(v.end() - v.size(), 90);
    v.emplace(v.end() - v.size(), 90);

    // Using the sort() function instead of std's qsort() as it is way faster than  qsort()
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    // "auto" declares the variable with the type as the same as that of the value on the rhs
    for (auto iterator = v.begin(); iterator != v.end(); iterator++)
    {
        cout << *iterator << " ";
    }

    // v.erase(v.begin());
    // v.erase(v.begin(), v.end());

    cout << endl;
    if (binary_search(v.begin(), v.end(), 8))
    {
        cout << "Element found!";
    }
    else
    {
        cout << "Element not found!";
    }

    cout << endl
         << *min_element(v.begin(), v.end()) << endl
         //  << v.max_size() << endl
         << v.at(0) << endl
         << v.front() << endl
         << v.back() << endl;

    return 0;
}