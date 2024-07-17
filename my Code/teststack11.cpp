#include <iostream>
using namespace std;
#define MAX 1000

class Stack{
    int top;
    public:
        int a[MAX];
        Stack(){top = -1;}
        bool push(int x){
            if( top >= (MAX -1 )){
                return false;
            }else{
                a[++top] = x;
                return true;
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
        int peek(){
            int x = a[top];
            return x;
        }
        bool Empty(){
            return (top<0);
        }
        void printss(){
            if(top<0){
                cout<<"Stack is empty";
            }else{
                cout<<"In this stack : ";
                for(int i=0;i<=top;i++){
                    cout<<a[i]<<" ";
                }
                cout<<endl;
            }
        }
 
};

int main(){
    Stack s;
    string str;
    cout<<"Pls input: "<<endl;
    getline(cin,str);
    cout<<"This output: ";
    //cout<<str;
    for(int i=0;i<str.length();i++){
        if(str[i] ==  '('){
            s.push(str[i]);
            
        }else if(str[i] == ')'){
            if(s.Empty()){
                cout<<"Error";
                return false;
            }
            //cout<<"pop";
            s.pop();
            
        }
    }
    if(s.Empty()){
        cout<<"Pass";
    }else{
        cout<<"Error";
    }
    
}