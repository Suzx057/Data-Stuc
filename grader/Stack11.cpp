#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Stack
{
	public:
		int Array[100];
		int top =  - 1;
	
		bool empty(){
			return top == -1;
			
		}
		bool full(){
	   		return top == 99;
		}
		void push(int data){
			if(!full()){
				top++;
				Array[top] = data;
			}
		}
		int pop(){
			if( !empty()){
				int temp = Array[top];
				top--;
				return '\0';
			}
			return -1;
		}
		void print(){
			cout<<"Stack: ";
			for(int i=0 ; i<= 4;i++){
				cout<< Array[i] << " ";
			}
			cout << endl;
		}
		
};
bool bracket(string str){
	Stack s;
	for(int i = 0; i< str.length();i++){
		char ch = str[i];
		if(ch == '('){
			s.push(ch);
		}else if (ch == ')'){
			if (s.empty()){
				return false;
			}
			s.pop();
		}
	}
	return s.empty();
}

int main(){
	
	string str;
	getline(cin,str);

	
	if(bracket(str)){
		cout<< "Pass" ;
		
	}else{
		cout<< "Error";
	}
	return 0;
	
}
