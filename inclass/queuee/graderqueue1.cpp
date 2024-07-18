#include<iostream>
using namespace std;
 class Queue{
    public:
    //int Array[6];
    // int size = 6;
    // int front = -1;
    // int rear = -1;
    int front,rear,size;
    int *Array;
    Queue(int c){
        front = -1;
        rear = -1;
        size = c;
        Array = new int[size];

    }
    bool empty(){
        return(front == -1 && rear == -1);
    }
    bool full(){
        return(rear == size - 1);
    }
    void enqueue(int data){
        if(empty()){
            rear++;
            front++;
            Array[rear] = data;
        }else if(!empty()){
            rear++;
            Array[rear] = data;
        }
        // if(!full()){
        //     rear++;
        //     Array[rear] = data;

        // }
    }
    int dequeue(){
        cout<<Array[front]<<endl;
        if(!empty()){
            int temp = Array[front];
            front++;
            return temp;
        }
        return -1;
    }
    void print(){
        // cout<<"Queue ";
        for(int i=front;i<=rear;i++){
            cout<<Array[i]<<" ";
        }
        cout<<endl;
    }
    void showSize(){
        cout<< rear+1-front << endl;
    }
    void showFirstandLast(){
        if(empty()){
            cout<<"Queue is empty: "<<endl;
        }else{
            cout<< Array[front] << " " <<Array[rear] << endl;
        }
    }
 };

 int main(){
    // int num;
    // cout<<"Size of queue : "<< endl;
    // cin>>num;
    // Queue q(num);
    Queue q(10);
    char command;
    int value;
    while(true){
        cin>>command;
        switch(command){
            case 'e' :
                cin>>value;
                q.enqueue(value);
                break;
            case 'd' :
                q.dequeue();
                break;
            case 'p' :
                q.print();
                break;
            case 'n' :
                q.showSize();
                break;
            case 's' :
                q.showFirstandLast();
                break;
            case 'x' :
                return 0;
                break;
            default:
                cout<<"invalid command : ";
                break;
        }
    }
    return 0;
 }