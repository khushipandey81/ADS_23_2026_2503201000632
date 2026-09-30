#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* top = NULL;

// Push operation
void push(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop operation
void pop() {
    if (top == NULL) {
        cout << "Stack Underflow" << endl;
        return;
    }

    Node* temp = top;
    cout << "Deleted Element: " << top->data << endl;
    top = top->next;
    delete temp;
}

// Peek operation
void peek() {
    if (top == NULL)
        cout << "Stack is Empty" << endl;
    else
        cout << "Top Element: " << top->data << endl;
}

// Display operation
void display() {
    if (top == NULL) {
        cout << "Stack is Empty" << endl;
        return;
    }

    Node* temp = top;
    cout << "Stack Elements: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
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