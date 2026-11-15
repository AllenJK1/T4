#include <iostream>
using namespace std;

#define SIZE 5

class Queue 
{
private:
    int arr[SIZE];
    int front;   // index of the first element
    int rear;    // index of the last element

public:
    Queue() 
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty() 
    { 
      return front == -1 || front > rear; 
    }
    bool isFull()  
    { 
      return rear == SIZE - 1; 
    }

    // enqueue or in other words add an element at the rear
    void enqueue(int value) 
    {
        if (isFull()) 
        {
            cout << "queue is full  cannot enqueue " << value << "\n";
            return;
        }
        if (front == -1)
        {        // first element
            front = 0;
        }
        rear++;
        arr[rear] = value;
        cout << value << " enqueued\n";
    }

    // dequeue .. jst . remove an element from the front
    void dequeue() 
    {
        if (isEmpty()) 
        {
            cout << "queue is empty\n";
            return;
        }
        cout << arr[front] << " dequeued\n";
        front++;
    }

    void display() 
    {
        if (isEmpty()) 
        {
            cout << "queue is empty\n";
            return;
        }
        cout << "queue (front to rear): ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() 
{
    Queue q;
    int choice, value;

    do 
    {
        cout << "\nMENU\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: (as a number)";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 4);

    return 0;
}
