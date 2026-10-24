
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

// Insert element
void enqueue(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
 
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Element inserted\n";
}

// Delete element
void dequeue() {
    if (front == NULL) {
        cout << "Queue Underflow\n";
        return;
    }

    Node* temp = front;
    cout << "Deleted element: " << front->data << endl;

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    delete temp;
}

// Display front element
void peek() {
    if (front == NULL) {
        cout << "Queue is Empty\n";
    } else {
        cout << "Front element: " << front->data << endl;
    }
}

// Display queue
void display() {
    if (front == NULL) {
        cout << "Queue is Empty\n";
        return;
    }

    Node* temp = front;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

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
