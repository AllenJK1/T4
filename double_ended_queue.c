#include <stdio.h>

#define SIZE 5

int deque[SIZE];
int front = -1;
int rear = -1;

int isFull() 
{
    return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
}

int isEmpty() 
{
    return front == -1;
}

// front insertion
void insertFront(int value) 
{
    if (isFull()) 
    {
        printf("Deque Overflow\n");
        return;
    }
    if (front == -1)
    {              // first element
        front = rear = 0;
    } else if (front == 0)
    {           
      // wrap around to the end
        front = SIZE - 1;
    }
    else 
    {
        front--;
    }
    deque[front] = value;
}

// rear insertion
void insertRear(int value)
{
    if (isFull())
    {
        printf("Deque Overflow\n");
        return;
    }
    if (front == -1) 
    {              // first element
        front = rear = 0;
    }
    else if (rear == SIZE - 1) 
    {  // wrap around to the start
        rear = 0;
    }
    else 
    {
        rear++;
    }
    deque[rear] = value;
}

// front deletion
void deleteFront()
{
    if (isEmpty())
    {
        printf("There are no more elemets duhh\n");
        return;
    }
    printf("Deleted this: %d from front", deque[front]);
    if (front == rear) 
    {            //when only one element was present
        front = rear = -1;
    } else if (front == SIZE - 1)
    { // wrap around to the start
        front = 0;
    } 
    else 
    {
        front++;
    }
}

// rear deletion
void deleteRear() 
{
    if (isEmpty())
    {
        printf("There are no more elements to remove dum dum\n");
        return;
    }
    printf("Deleted the followig  from rear: %d\n", deque[rear]);
    if (front == rear) 
    {            // if only one element was present
        front = rear = -1;
    } 
    else if (rear == 0) 
    {         // wrap around to the end
        rear = SIZE - 1;
    } 
    else 
    {
        rear--;
    }
}
// Below is the code to test it
// It's commented out since the question only wants functions for each implementation i guess
/*

void display() 
{
    if (isEmpty())
    {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque: ");
    int i = front;
    while (1) 
    {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() 
{
    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertFront(1);
    display();          // shoud show 1 5 10 20 as per the test run

    deleteFront();      // removes 1
    deleteRear();       // removes 20
    display();          // then the dispay outputs this as per test again : 5 10

    insertFront(7);
    insertRear(30);
    insertRear(40);
    display();          // THe output is this as per run 7 5 10 30 40
    insertRear(50);     // overflows the queue  since its already full (size is 5)

    return 0;
}

*/
