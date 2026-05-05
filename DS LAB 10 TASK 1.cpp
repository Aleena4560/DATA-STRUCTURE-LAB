#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Display function
void display() {
    cout << "Queue: ";
    if (front == -1) {
        cout << "Empty";
    } else {
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
    }
    cout << endl;
}

// Enqueue (Circular)
void enQueue(int value) {
    // Full condition
    if ((rear + 1) % SIZE == front) {
        cout << "Queue is Full\n";
        return;
    }

    if (front == -1) { // first element
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = value;

    cout << "enQueue(" << value << ")\n";
    cout << "Front: " << queue[front] << " | Rear: " << queue[rear] << endl;
    display();
    cout << "------------------\n";
}

// Dequeue (Circular)
void deQueue() {
    if (front == -1) {
        cout << "Queue is Empty\n";
        return;
    }

    cout << "deQueue()\n";

    if (front == rear) { // only one element
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }

    if (front != -1)
        cout << "Front: " << queue[front] << " | Rear: " << queue[rear] << endl;
    else
        cout << "Queue is now empty\n";

    display();
    cout << "------------------\n";
}

int main() {
	cout <<"Performing Operations on QUEUE" <<endl;
	cout << endl;
    enQueue(10);
    enQueue(20);
    enQueue(30);
    deQueue();
    enQueue(40);
    enQueue(50);
    enQueue(60); // works in circular queue

    return 0;
}