#include <iostream>
using namespace std;

class Node {
public:
    int id;
    Node* next;

    Node(int int_id)  {
        id = int_id;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    bool findNode(int id, Node* &prev, Node* &curr) {
        prev = NULL;
        curr = head;
        while (curr && curr->id != id) {
            prev = curr;
            curr = curr->next;
        }
        return curr != NULL;
    }

    bool checkDuplicate(int id) {
        Node* temp = head;
        while (temp) {
            if (temp->id == id) return true;
            temp = temp->next;
        }
        return false;
    }


    LinkedList(){
        head = NULL;
    }

    
    void insertBefore(int beforeID, int newID) {
        if (checkDuplicate(newID)){
            return;
        }

        Node* newNode = new Node(newID);
        if (!head || head->id == beforeID) {
            newNode->next = head;
            head = newNode;
            printList();
            return;
        }

        Node* prev = NULL;
        Node* curr = NULL;
        if (findNode(beforeID, prev, curr)) {
            if (prev) {
                newNode->next = curr;
                prev->next = newNode;
                printList();
            } else {
                newNode->next = head;
                head = newNode;
                printList();
            }
        } else {
            
            prev = head;
            while (prev->next) prev = prev->next;
            prev->next = newNode;
            printList();
        }
    }

    
    void insertAfter(int afterID, int newID) {
        if (checkDuplicate(newID)){
            return;
        }

        Node* newNode = new Node(newID);
        Node* prev = NULL;
        Node* curr = NULL;
        if (findNode(afterID, prev, curr)) {
            newNode->next = curr->next;
            curr->next = newNode;
            printList();
        } else {
            
            if (!head) {
                head = newNode;
                printList();
            } else {
                curr = head;
                while (curr->next) curr = curr->next;
                curr->next = newNode;
                printList();
            }
            
        }
        
    }

    
 void deleteNode(int deleteID) {
        if (!head){
            return;
        }

        if (head->id == deleteID) {
            head = head->next;
            printList();
            return;
        }

        Node* prev = NULL;
        Node* curr = NULL;
        if (findNode(deleteID, prev, curr)) {
            prev->next = curr->next;
            printList();
            // Note: `curr` is not deleted, so it will be a memory leak if not managed
        }
    }


    
    void printList()  {
        Node* current = head;
        while (current) {
            cout << current->id;
            if (current->next) cout << " ";
            current = current->next;
        }
        cout << endl;
    }

};

int main() {
    LinkedList list;
    char command;
    int id, value;

    while (cin >> command) {
        if (command == 'E') break;
        cin >> value;
        if (command == 'I') {
            cin >> id;
            list.insertBefore(id, value);
            //list.printList();
            
        } else if (command == 'A') {
            cin >> id;
            list.insertAfter(id, value);
            //list.printList();
        } else if (command == 'D') {
            list.deleteNode(value);
            //list.printList();
        }
        //list.printList();
    }
    return 0;
}