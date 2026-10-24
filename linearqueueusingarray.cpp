
#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == SIZE - 1) {
        cout << "Queue Overflow\n";
    } else {
        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = x;
        cout << "Element inserted\n";
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow\n";
    } else {
        cout << "Deleted element: "
             << queue[front] << endl;
        front++;

        if (front > rear) {
            front = rear = -1;
        }
    }
}

void peek() {
    if (front == -1) {
        cout << "Queue is Empty\n";
    } else {
        cout << "Front element: "
             << queue[front] << endl;
    }
}

void display() {
    if (front == -1) {
        cout << "Queue is Empty\n";
    } else {
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
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
 