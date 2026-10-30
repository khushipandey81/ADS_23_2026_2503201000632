#include <iostream>
using namespace std;

#define MAX 5

int q[MAX], front = -1, rear = -1;

void enqueue(int x)
{
    if ((rear + 1) % MAX == front)
        cout << "Overflow\n";
    else
    {
        if (front == -1)
            front = rear = 0;
        else
            rear = (rear + 1) % MAX;

        q[rear] = x;
        cout << x << " inserted\n";
    }
}

void dequeue()
{
    if (front == -1)
        cout << "Underflow\n";
    else
    {
        cout << q[front] << " deleted\n";

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
    }
}

void display()
{
    if (front == -1)
        cout << "Queue is empty\n";
    else
    {
        cout << "Queue: ";
        int i = front;

        while (true)
        {
            cout << q[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    enqueue(40);
    display();

    return 0;
}