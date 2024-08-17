#include <iostream>
#include <string>
using namespace std;

struct Node {
    int key;
    string value;
    Node* next;
};

class HashTable {
    Node* table[17]; // The hash table with 17 buckets

    // Hash function
    int hashFunction(int key) {
        return key % 17;
    }

public:
    // Constructor
    HashTable() {
        for (int i = 0; i < 17; ++i) {
            table[i] = nullptr;
        }
    }

    // Add key-value pair
    void add(int key, string value) {
        int index = hashFunction(key);
        Node* newNode = new Node();  // Corrected initialization
        newNode->key = key;          
        newNode->value = value;      
        newNode->next = nullptr;     

        if (!table[index]) {
            table[index] = newNode;
        } else {
            Node* temp = table[index];
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Find value by key
    string find(int key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        
        while (temp) {
            if (temp->key == key) {
                return temp->value;
            }
            temp = temp->next;
        }
        return "-";
    }

    // Print the hash table
    void print() {
        for (int i = 0; i < 17; ++i) {
            if (table[i]) {
                Node* temp = table[i];
                while (temp) {
                    cout << "(" << temp->key << "," << temp->value << ") ";
                    temp = temp->next;
                }
            } else {
                cout << "(-1,-) ";
            }
            cout << std::endl;
        }
    }
};

int main() {
    HashTable ht;
    char command;
    int key;
    string value;

    while (true) {
        cin >> command;
        if (command == 'a') {
            cin >> key >> value;
            ht.add(key, value);
        } else if (command == 's') {
            cin >> key;
            cout << ht.find(key) << endl;
        } else if (command == 'p') {
            ht.print();
        } else if (command == 'e') {
            break;
        }
    }

    return 0;
}