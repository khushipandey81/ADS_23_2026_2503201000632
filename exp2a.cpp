#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter queue size: ";
    cin >> n;

    int queue[100];
    int front = -1, rear = -1;
    int choice, value;

    do
    {
        cout << "\n1. ENQUEUE";
        cout << "\n2. DEQUEUE";
        cout << "\n3. DISPLAY";
        cout << "\n4. EXIT";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                if(rear == n - 1)
                    cout << "Queue Overflow";
                else
                {
                    cout << "Enter value: ";
                    cin >> value;

                    if(front == -1)
                        front = 0;

                    queue[++rear] = value;
                    cout << value << " inserted";
                }
                break;

            case 2:
                if(front == -1 || front > rear)
                    cout << "Queue Underflow";
                else
                {
                    cout << queue[front] << " deleted";
                    front++;

                    if(front > rear)
                        front = rear = -1;
                }
                break;

            case 3:
                if(front == -1)
                    cout << "Queue is empty";
                else
                {
                    cout << "Queue: ";
                    for(int i = front; i <= rear; i++)
                        cout << queue[i] << " ";
                }
                break;

            case 4:
                cout << "Exit";
                break;

            default:
                cout << "Invalid choice";
        }

    } while(choice != 4);

    return 0;
}