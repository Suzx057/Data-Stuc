#include <iostream>
using namespace std;

struct Process{
    int pid;
    int arrivalTime;
    int serviceTime;
};
void push(Process stack[],int &top,Process p){
    stack[++top] = p;
}
Process pop(Process stack[],int &top){
    return stack[top--];
}

int main(){
    int N;
    cin>>N;
    Process processes[100];
    Process stack[100];
    int top = -1;
    for(int i = 0;i<N;i++){
        cin>>processes[i].pid>>processes[i].arrivalTime>>processes[i].serviceTime;
        
    }
    int index = 0;
    int time = 0;
    while(index<N||top>=0){
       if(index<N&&processes[index].arrivalTime == time){
        push(stack,top,processes[index]);
        index++;
       }
       if(top>=0){
        Process current = pop(stack,top);
        while(current.serviceTime>0){
            cout<<current.pid<<" : "<<current.serviceTime<<endl;
            current.serviceTime--;
            time++;
            if(index<N&&processes[index].arrivalTime == time){
                push(stack,top,processes[index]);
                index++;
            }
        }
       }else{
        time++;
       }
        
    }
    return 0;
}