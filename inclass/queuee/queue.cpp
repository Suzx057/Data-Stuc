#include<iostream>
using namespace std;
 class Queue{
    public:
    int Array[6];
    int size = 6;
    int front = -1;
    int rear = -1;
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
        if(!empty()){
            int temp = Array[front];
            front++;
            return temp;
        }
        return -1;
    }
    void print(){
        cout<<"Queue ";
        for(int i=front;i<=rear;i++){
            cout<<Array[i]<<" ";
        }
        cout<<endl;
    }
 };

 int main(){
    Queue q;
    q.enqueue(1); cout<<"Enqueue 1\t ";
    q.print();
    q.enqueue(2); cout<<"Enqueue 2\t";
    q.print();
    q.enqueue(3); cout<<"Enqueue 3\t";
    q.print();
    q.enqueue(4); cout<<"Enqueue 4\t";
    q.print();
    q.enqueue(5); cout<<"Enqueue 5\t";
    q.print();
    cout<<"Dequeue\t"; cout<<q.dequeue()<<"\t";
    q.print();
    cout<<"Dequeue\t"; cout<<q.dequeue()<<"\t";
    q.print();
    cout<<"Dequeue\t"; cout<<q.dequeue()<<"\t";
    q.print();
    cout<<"Dequeue\t"; cout<<q.dequeue()<<"\t";
    q.print();
    cout<<"Dequeue\t"; cout<<q.dequeue()<<"\t";
    q.print();
    return 0;
 }