#include <iostream>
using namespace std;

const int MAX = 1000;

class Stack {
    int top;
    int arr[MAX]; 

public:
    Stack() { top = -1; }

    bool push(int x){
        if (top >= (MAX - 1)) {
        cout << "Stack Overflow" << endl;
        return false;
    } else {
        arr[++top] = x;
        return true;
    }
    }

    int pop(){
        if (top < 0) {
        cout << "Stack Underflow" << endl;
        return 0;
    } else {
        int x = arr[top--];
        return x;
    }
    }

    int peek(){
        if (top < 0) {
        cout << "Stack is empty" << endl;
        return 0;
    } else {
        int x = arr[top];
        return x;
    }
    }

    bool isEmpty(){
        return (top < 0);
    }
    
    int size(){
        return top + 1;
    }

    void printStack(){
        if (top < 0) {
        cout << "Stack is empty" << endl;
    } else {
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    }

};

// bool Stack::push(int x) {
//     if (top >= (MAX - 1)) {
//         cout << "Stack Overflow" << endl;
//         return false;
//     } else {
//         arr[++top] = x;
//         return true;
//     }
// }

// int Stack::pop() {
//     if (top < 0) {
//         cout << "Stack Underflow" << endl;
//         return 0;
//     } else {
//         int x = arr[top--];
//         return x;
//     }
// }

// int Stack::peek() {
//     if (top < 0) {
//         cout << "Stack is empty" << endl;
//         return 0;
//     } else {
//         int x = arr[top];
//         return x;
//     }
// }

// bool Stack::isEmpty() {
//     return (top < 0);
// }

// int Stack::size() {
//     return top + 1;
// }

// void Stack::printStack() {
//     if (top < 0) {
//         cout << "Stack is empty" << endl;
//     } else {
//         for (int i = 0; i <= top; i++) {
//             cout << arr[i] << " ";
//         }
//         cout << endl;
//     }
// }

int main() {
    Stack s;
    string command;
    int value;

    while (true) {
        cin >> command;

        char cmd = command[0];
        switch (cmd) {
            case 'U':
                cin >> value;
                s.push(value);
                break;
            case 'O':
                if (!s.isEmpty()) {
                    cout << s.pop() << endl;
                } else {
                    cout << "Stack is empty" << endl;
                }
                break;
            case 'T':
                if (!s.isEmpty()) {
                    cout << s.peek() << endl;
                } else {
                    cout << "Stack is empty" << endl;
                }
                break;
            case 'P':
                s.printStack();
                break;
            case 'N':
                cout << s.size() << endl;
                break;
            case 'X':
                return 0;
            default:
                cout << "Invalid command" << endl;
                break;
        }
    }

    return 0;
}
