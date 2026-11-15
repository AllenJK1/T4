#include <iostream>
using namespace std; 
//Class to encaspulate all the implementation specifics of a circular queue
class CircularQueue 
{
private:
    int *arr;
    int capacity;
    int front;   
    int rear;    
    int count;   

public:
    CircularQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~CircularQueue() { delete[] arr; }

    bool isEmpty() 
    { 
      return count == 0; 
    }
    bool isFull()  
    { 
      return count == capacity; 
    }

    void enqueue(int value) 
    {
        if (isFull()) 
        {
            cout << "queue is full!!!\n";
            return;
        }
        rear = (rear + 1) % capacity;   
        arr[rear] = value;
        count++;
        cout << value << " enqueued\n";
    }

    void dequeue() 
    {
        if (isEmpty())   
        {
            cout << "queue is empty !! \n";
            return;
        }
        cout << arr[front] << " dequeued\n";
        front = (front + 1) % capacity; // Wrap arround to begin ... like a cicular queue would
        count--;
    }

    int peek() 
    {
        if (isEmpty()) 
        {
            cout << "queue is empty !!\n";
            return -1;
        }
        return arr[front];
    }

    void display() 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty    !!\n";
            return;
        }
        cout << "queue: "; // display the queue as a list to the console
        for (int i = 0; i < count; i++)
        {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << "\n";
    }
};

int main() 
{
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);   // It should be full by here so it will show the full message..
    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

    q.enqueue(60);   // At this point it will wrap arround
    q.enqueue(70);   // reuses the second freed slot
    q.display();

    cout << "Front element: " << q.peek() << "\n";
    return 0;
}
