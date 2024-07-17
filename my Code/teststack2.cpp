#include<iostream>
using namespace std;

#define MAX 1000

class Stack{
    int top;
    public:
    int a[MAX];
    Stack(){top = -1;}
    int push(int x){
        if(top>=MAX){
            return -1;
        }else{
            a[++top] = x;
            return x;
        }
    }
    int pop(){
        if(top<0){
            return -1;
        }else{
            int x = a[top--];
            return x;
        }
    }
    bool Empty(){
        return (top<0);
    }
    void printss(){
        if(top<0){
            cout<<"Stack is empty"<<endl;
        }else{
            for(int i=0;i<=top;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
    }
    int size(){
        return top+1;
    }
    int peek(){
        int x = a[top];
        return x;
    }
};
int main(){
    Stack s;
    char command;
    int n;
    while(true){
        cin>>command;

        switch(command){
            case 'U':
                cin>>n;
                s.push(n);
                break;
            case 'O':
                if(s.Empty()){
                    cout<<"STack is empty pls use option U: "<< endl;

                }else{
                    cout<<"Pop number: "<<s.pop()<<endl;
                }
                break;
            case 'T':
                cout<<s.peek()<<endl;
                break;
            case 'P':
                s.printss();
                break;
            case 'N':
                cout<< s.size() << endl;
                break;
            case 'X':
                return 0;
            default:
                cout<<"invalid in put";
                break;
        }
    }
}