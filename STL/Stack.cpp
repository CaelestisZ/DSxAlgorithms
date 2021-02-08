#include <iostream>
#include <stack>

using namespace std;

void display(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << "\t";
        s.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.size() << endl;
    display(s);
    return 0;
}