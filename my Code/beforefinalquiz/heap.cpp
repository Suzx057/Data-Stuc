#include<iostream>
#include<vector>
using namespace std;

class MaxHeap{
    private:
        vector<int> heap;
        void heapify_up(int index){
            if(index == 0)return;
            int parent = (index - 1 ) / 2;

            if(heap[index] > heap[parent]){
                swap(heap[index] , heap[parent]);
                heapify_up(parent);
            }
        }
        void heapify_down(int index){
            int left_child = 2 * index + 1;
            int right_child = 2 * index + 2;
            int largest = index;

            if(left_child < heap.size() && heap[left_child] > heap[largest]){
                largest = left_child;
            }
            if(right_child < heap.size() && heap[right_child] > heap[largest]){
                largest = right_child;
            }
            if(largest != index){
                swap(heap[index] , heap[largest]);
                heapify_down(largest);
            }
        }
    public:
        void add(int value){
            heap.push_back(value);
            heapify_up(heap.size() - 1);
        }
        int remove (){
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
        void printheap(){
            cout<<"Max heap : ";
            for( int i : heap){
                cout<<i<<" ";
                
            }
            cout<<endl;
        }
        bool empty(){
            return heap.empty();
        }
};

class MinHeap{
    private:
        vector<int> hiep;
        void heapify_up(int index){
            if(index == 0)return;
            int parent = (index - 1) / 2;

            if(hiep[index] < hiep[parent]){
                swap(hiep[index] , hiep[parent]);
                heapify_up(parent);
            }
        }
        void heapify_down(int index){
            int left_child = 2 * index + 1;
            int right_child = 2 * index + 2;
            int largest = index;

            if(left_child < hiep.size() && hiep[left_child] < hiep[largest]){
                largest = left_child;
            }
            if(right_child < hiep.size() && hiep[right_child] < hiep[largest]){
                largest = right_child;
            }
            if(largest != index){
                swap(hiep[index] , hiep[largest]);
                heapify_down(largest);
            }
        }
    public:
        public:
        void add(int value){
            hiep.push_back(value);
            heapify_up(hiep.size() - 1);
        }
        int remove (){
            if(hiep.empty()){
                cout<<"heap is empty"<<endl;
                return -1;
            }
            int remove_value = hiep[0];
            hiep[0] = hiep.back();
            hiep.pop_back();
            heapify_down(0);
            return remove_value;
        }
        void printheap(){
            cout<<"Min heap : ";
            for( int i : hiep){
                cout<<i<<" ";
                
            }
            cout<<endl;
        }
        bool empty(){
            return hiep.empty();
        }
};

int main(){
    MaxHeap heap;
    MinHeap hii;
    char command;
    int value;
    while(true){
        cin>>command;
        if(command == 'a'){
            cin>>value;
            heap.add(value);
            hii.add(value);
        }else if(command == 'd'){
            int rm = heap.remove();
            int mmi = hii.remove();
            if(rm != -1){
                cout<<"for max heap : "<<rm<<endl;
                cout<<"for mi heap : "<< mmi << endl;
            }
        }else if(command == 'p'){
            heap.printheap();
            cout<<endl;
            hii.printheap();
        }else if(command == 'e'){
            break;
        }else{
            cout<<"invalid command"<<endl;
        }
    }
    return 0;
}