#include<iostream>
using namespace std;

class Queue{
    private:
    int front,rear,size;
    int* Array;
    public:
    Queue(int c){
        front = -1;
        rear = -1;
        size = c;
        Array = new int[size];
    }
    int empty(){
        return(front == -1 && rear == -1);
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
    }
    int dequeue(){
        if(empty()){
            return 0;
        }else{
            cout<<Array[front]<<endl;
            int temp = Array[front];
            front++;
            return temp;
        }
    }
    int print(){
        if(empty()){
            cout<<"Queue is empty !!!!";
        }
        for(int i=front;i<=rear;i++){
            cout<<Array[i]<< " " ;
        }
        cout<<endl;
    }
    int sizequeue(){
        cout<<rear+1-front<<endl;
    }
    int firtand(){
        cout<<Array[front]<<" "<<Array[rear]<<endl;
    }
};
int main(){
    int sizeArr;
    cout<<"Size of queue: ";
    cin>>sizeArr;
    Queue q(sizeArr);
    char command;
    int value;
    while(true){
        cin>>command;
        switch(command){
            case 'e':
                cin>>value;
                q.enqueue(value);
                break;
            case 'd':
                q.dequeue();
                break;
            case 'p':
                q.print();
                break;
            case 'n':
                q.sizequeue();
                break;
            case 's':
                q.firtand();
                break;
            case 'x':
                return 0;
                break;
            default:
                cout<<"invalid input: ";
                break;
        }
    }
}
