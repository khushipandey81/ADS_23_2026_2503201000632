#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string postfix;
    stack<int> s;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    for(char ch : postfix)
    {
        if(ch >= '0' && ch <= '9')
        {
            s.push(ch - '0');
        }
        else
        {
            int b = s.top();
            s.pop();

            int a = s.top();
            s.pop();

            if(ch == '+')
                s.push(a + b);
            else if(ch == '-')
                s.push(a - b);
            else if(ch == '*')
                s.push(a * b);
            else if(ch == '/')
                s.push(a / b);
        }
    }

    cout << "Result = " << s.top();

    return 0;
}