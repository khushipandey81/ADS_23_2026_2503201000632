
#include <iostream>
using namespace std;

#define SIZE 5

int stack[SIZE];
int top = -1;

void push(int x) {
    if (top == SIZE - 1) {
        cout << "Stack Overflow\n";
    } else {
        top++;
        stack[top] = x;
        cout << "Element inserted\n";
    }
}

void pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
    } else {
        cout << "Deleted element: " << stack[top] << endl;
        top--;
    }
}

void peek() {
    if (top == -1) {
        cout << "Stack is Empty\n";
    } else {
        cout << "Top element: " << stack[top] << endl;
    }
}

void display() {
    if (top == -1) {
        cout << "Stack is Empty\n";
    } else {
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    push(10);
    push(20);
    push(30);

    display();
    peek();
    pop();
    display();

    return 0;
}
