#include<iostream>
using namespace std;

class Stack{
    private:
        int top;
        string arr[100];
    public:
        Stack(){
            top = -1;
        }
        bool push(string c){
            if(top>=99){
                cout<<"stack is full";
                return false;
            }else{
                arr[++top] = c;
                return true;
            }
        }
        string pop(){
            if(top<0){
                cout<<"stack is empty";
                return "";
            }else{
                string c = arr[top--];
                return c;
            }
        }
        bool empty(){
            return (top <0);
        }
};
bool matched(string open,string close){
    if(open == "(" && close == ")")return true;
    if(open == "[" && close == "]")return true;
    if(open == "{" && close == "}")return true;
    if(open == "<" && close == ">")return true;
    if(open == "<<" && close == ">>")return true;
    return false;
}

int main(){
    Stack s;
    string input;
    getline(cin,input);
    int matchcount = 0;
    for(int i = 0;i<input.length();i++){
        string current(1,input[i]);
        if(current == "<" && i+1<input.length() && input[i+1] == '<'){
            s.push("<<");
            i++;
        }else if(current == ">" && i+1<input.length() && input[i+1] == '>'){
            if(s.empty() || s.pop() != "<<"){
                cout<<"Not matched\n"<<matchcount<<" matched";
                return 0;
            }else{
                matchcount++;
                i++;
            }
        }else if(current == "(" || current == "[" || current == "{" || current == "<"){
            s.push(current);
        }else if(current == ")" || current == "]" || current =="}" || current ==">"){
            if(s.empty()){
                cout<<"Not matched\n"<<matchcount<<" matched";
                return 0;
            }else{
                string top = s.pop();
                if(matched(top,current)){
                    matchcount++;
                }else{
                    cout<<"Not matched\n"<<matchcount<<" matched";
                    return 0;
                }
            }
        }
    }
    if(s.empty()){
        cout<<matchcount<<" matched";
    }else{
        cout<<"Not matched\n"<<matchcount<<" matched";
        return 0;
    }
}