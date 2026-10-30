#include <iostream>
using namespace std;

#define MAX 5

int stackArr[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        cout << "Stack Overflow\n";
        return;
    }

    stackArr[++top] = value;
    cout << value << " pushed\n";
}

void pop()
{
    if (top == -1)
    {
        cout << "Stack Underflow\n";
        return;
    }

    cout << stackArr[top--] << " popped\n";
}

void display()
{
    if (top == -1)
    {
        cout << "Stack is empty\n";
        return;
    }

    cout << "Stack elements: ";
    for (int i = top; i >= 0; i--)
        cout << stackArr[i] << " ";

    cout << endl;
}

int main()
{
    push(70);
    push(76);
    push(56);

    display();

    pop();
    display();

    return 0;
}