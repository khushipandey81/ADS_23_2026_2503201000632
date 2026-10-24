
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int x) {
    Node* newNode = new Node;
    newNode->data = x;

    if (front == NULL) {
        front = rear = newNode;
        rear->next = front;
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    cout << "Element inserted\n";
}

void dequeue() {
    if (front == NULL) {
        cout << "Queue Underflow\n";
        return;
    }

    Node* temp = front;
    cout << "Deleted element: "
         << front->data << endl;

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front;
    }

    delete temp;
}

void peek() {
    if (front == NULL) {
        cout << "Queue is Empty\n";
    } else {
        cout << "Front element: "
             << front->data << endl;
    }
}

void display() {
    if (front == NULL) {
        cout << "Queue is Empty\n";
        return;
    }

    Node* temp = front;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != front);

    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();
    peek();
    dequeue();
    display();

    return 0;
}
