#include<iostream>
#include<vector>
using namespace std;


class MaxHeap{

    private:
        vector<int> heap;
        void heapify_up(int index){
            if(index == 0 )return;
            int parent = (index - 1) / 2;

            if(heap[index] > heap[parent]){
                swap(heap[index] , heap[parent]);
                heapify_up(parent);
            }
        }
        void heapify_down(int index){
            int lf = 2 * index + 1;
            int rl = 2 * index + 2;
            int lar = index;

            if(lf < heap.size() && heap[lf] > heap[lar]){
                lar = lf;
            }
            if(rl < heap.size() && heap[rl] > heap[lar]){
                lar = rl;
            }
            if(lar != index){
                swap(heap[index] , heap[lar]);
                heapify_down(lar);
            }
        }
    public:
        void add(int value){
            heap.push_back(value);
            heapify_up(heap.size() - 1);
        }
        int remove(){
            if(heap.empty()){
                cout<<"llll"<<endl;
            }
            int rm = heap[0];
            heap[0] = heap.back();
            heap.pop_back();
            heapify_down(0);
            return rm;
        }
        bool empty(){
            return heap.empty();
        }
        void print(){
            for(int  i = 0 ; i< heap.size() ; i++){
                cout<<heap[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    MaxHeap heap;
    char command;
    int value;
    while(true){
        cin>>command;
        if(command == 'a'){
            cin>>value;
            heap.add(value);
        }else if(command == 'd'){
            int rr = heap.remove();
            if( rr != -1){
                cout<<rr<<endl;
            }
        }else if(command == 'p'){
            heap.print();
        }else if(command == 'e'){
            break;
        }else{
            cout<<"kasdkawd"<<endl;
        }
    }
}