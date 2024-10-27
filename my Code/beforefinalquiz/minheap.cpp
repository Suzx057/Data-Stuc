#include<iostream>
#include<vector>
using namespace std;

class MinHeap{
    private:
        vector<int> heap;
        void heapify_up(int index){
            if(index == 0)return;
            int parent = (index - 1)/ 2;

            if(heap[index] < heap[parent]){
                swap(heap[index] , heap[parent]);
                heapify_up(parent);
            }
        }
        void heapify_down(int index){
            int left_child = 2 * index + 1;
            int right_child = 2 * index + 2;
            int largest = index;

            if(left_child < heap.size() && heap[left_child] < heap[largest]){
                largest = left_child;
            }
            if(right_child < heap.size() && heap[right_child] < heap[largest]){
                largest = right_child;
            }
            if(largest != index){
                swap(heap[index], heap[largest]);
                heapify_down(largest);
            }
        }
    public:
        void add(int value){
            heap.push_back(value);
            heapify_up(heap.size() - 1);
        }
        int remove(){
            if(heap.empty()){
                cout<<"heap is empty"<<endl;
                return -1;
            }
            int remove_value = heap[0];
            heap[0] = heap.back();
            heap.pop_back();
            heapify_down(0);
            return remove_value;
        }
        bool empty(){
            return heap.empty();
        }
        void printheap(){
            for(int i : heap){
                cout<<i<<" ";
            }
            cout<<endl;
        }
};

int main(){
    MinHeap heap;
    char command;
    int value;
    while(true){
        cin>>command;
        if(command == 'a'){
            cin>>value;
            heap.add(value);
        }else if(command == 'p'){
            heap.printheap();
        }else if(command == 'd'){
            int rm = heap.remove();
            if(rm != -1){
                cout<<rm<<endl;
            }
        }else if(command == 'e'){
            break;
        }else{
            cout<<"invalid command"<<endl;
        }
    }
    return 0;
}