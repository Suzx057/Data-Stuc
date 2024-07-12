#include<iostream>
using namespace std;

class Queue {
private:
    int front, rear, size;
    int* queue;
public:
    Queue(int c) {
        front = rear = 0;
        size = c;
        queue = new int[size];
    }
    void enqueue(int data) {
        if (size == rear) {
            cout << "Queue is full" << endl;
            return;
        } else {
            queue[rear] = data;
            rear++;
        }
    }

    void dequeue() {
        if (front == rear) {
            cout << "Queue is empty" << endl;
            return;
        } else {
            cout << queue[front] << endl;
            for (int i = 0; i < rear - 1; i++) {
                queue[i] = queue[i + 1];
            }
            rear--;
        }
    }

    void printQueue() {
        if (front == rear) {
            cout << "Queue is empty" << endl;
            return;
        } else {
            for (int i = front; i < rear; i++) {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }

    void showSize() {
        cout << rear - front << endl;
    }

    void showFirstAndLast() {
        if (front == rear) {
            cout << "Queue is empty" << endl;
        } else {
            cout << queue[front] << " " << queue[rear - 1] << endl;
        }
    }
};

int main() {
    Queue q(100);
    char command;
    int value;
    while (true) {
        cin >> command;
        switch (command) {
        case 'e':
            cin >> value;
            q.enqueue(value);
            break;
        case 'd':
            q.dequeue();
            break;
        case 'p':
            q.printQueue();
            break;
        case 'n':
            q.showSize();
            break;
        case 's':
            q.showFirstAndLast();
            break;
        case 'x':
            return 0;
        default:
            cout << "Invalid command" << endl;
        }
    }
}