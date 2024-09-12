#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


class Queue {
private:
    Node* queue[100];  
    int front, rear;

public:
    
    Queue() : front(0), rear(0) {}

    bool isEmpty() {
        return front == rear;
    }

    void enqueue(Node* node) {
        queue[rear++] = node;
    }

    Node* dequeue() {
        if (isEmpty()) {
            return nullptr;
        }
        return queue[front++];
    }

   
    int getFront() const {
        return front;
    }

 
    int getRear() const {
        return rear;
    }
};


class BST {
private:
    Node* root;


    Node* addNode(Node* root, int data) {
        if (root == nullptr) {
            return new Node(data);
        }

        if (data < root->data) {
            root->left = addNode(root->left, data);
        } else {
            root->right = addNode(root->right, data);
        }
        return root;
    }

   
    Node* removeNode(Node* root, int data) {
        if (root == nullptr) {
            return nullptr;
        }

        if (data < root->data) {
            root->left = removeNode(root->left, data);
        } else if (data > root->data) {
            root->right = removeNode(root->right, data);
        } else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else {
                Node* temp = findMin(root->right);
                root->data = temp->data;
                root->right = removeNode(root->right, temp->data);
            }
        }
        return root;
    }

   
    Node* findMin(Node* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    
    void breadthFirstTraversal(Node* root) {
        if (root == nullptr) return;

        Queue q;
        q.enqueue(root);

        while (!q.isEmpty()) {
            int levelSize = q.getRear() - q.getFront();  

            for (int i = 0; i < levelSize; i++) {
                Node* current = q.dequeue();
                cout << current->data;

                if (i < levelSize - 1) {
                    cout << ",";  
                }

                if (current->left != nullptr) q.enqueue(current->left);
                if (current->right != nullptr) q.enqueue(current->right);
            }

            if (!q.isEmpty()) {
                cout << ",|";  
            } else {
                cout << ",|";  
            }
        }
        cout << endl; 
    }

   
    void inorder(Node* root) {
        if (root == nullptr) return;
        inorder(root->left);
        cout << root->data << ",";
        inorder(root->right);
    }

    
    void preorder(Node* root) {
        if (root == nullptr) return;
        cout << root->data << ",";
        preorder(root->left);
        preorder(root->right);
    }

  
    void postorder(Node* root) {
        if (root == nullptr) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << ",";
    }

public:
    BST() : root(nullptr) {}

    void add(int data) {
        root = addNode(root, data);
    }

    void remove(int data) {
        root = removeNode(root, data);
    }

    void breadthFirstTraversal() {
        breadthFirstTraversal(root);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }

    void preorder() {
        preorder(root);
        cout << endl;
    }

    void postorder() {
        postorder(root);
        cout << endl;
    }
};

int main() {
    BST bst;
    char command;
    int value;

    while (true) {
        cin >> command;
        if (command == 'x') break;  

        if (command == 'a') {  
            cin >> value;
            bst.add(value);
        } else if (command == 'd') {  
            cin >> value;
            bst.remove(value);
        } else if (command == 'b') {  
            bst.breadthFirstTraversal();
        } else if (command == 'i') { 
            bst.inorder();
        } else if (command == 'p') {  
            bst.preorder();
        } else if (command == 't') {  
            bst.postorder();
        }
    }

    return 0;
}