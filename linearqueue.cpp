#include <iostream>
using namespace std;

#define MAX 5

class Queue {
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow" << endl;
        } else {
            if (front == -1)
                front = 0;

            rear++;
            arr[rear] = value;
            cout << value << " inserted" << endl;
        }
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow" << endl;
        } else {
            cout << arr[front] << " deleted" << endl;
            front++;
        }
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is Empty" << endl;
        } else {
            cout << "Queue: ";
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(60);

    q.display();

    q.dequeue();
     q.dequeue();
    q.display();

    return 0;
}