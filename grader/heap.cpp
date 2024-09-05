#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    private:
        vector<int> heap;

        
        void heapify_up(int index) {
            if (index == 0) return; 
            int parent = (index - 1) / 2;

           
            if (heap[index] > heap[parent]) {
                swap(heap[index], heap[parent]);
                heapify_up(parent); 
            }
        }

        
        void heapify_down(int index) {
            int left_child = 2 * index + 1;
            int right_child = 2 * index + 2;
            int largest = index;

            if (left_child < heap.size() && heap[left_child] > heap[largest])
                largest = left_child;

            
            if (right_child < heap.size() && heap[right_child] > heap[largest])
                largest = right_child;

            
            if (largest != index) {
                swap(heap[index], heap[largest]);
                heapify_down(largest); 
            }
        }

    public:
       
        void add(int value) {
            heap.push_back(value);
            heapify_up(heap.size() - 1); 
        }

        
        int remove() {
            if (heap.empty()) {
                cout << "Heap is empty!" << endl;
                return -1;
            }
            int removed_value = heap[0];
            heap[0] = heap.back();
            heap.pop_back();
            heapify_down(0); 
            return removed_value;
        }

        
        void print_heap() {
            for (int i : heap)
                cout << i << " ";
            cout << endl;
        }

        
        bool is_empty() {
            return heap.empty();
        }
};

int main() {
    MaxHeap heap;
    char command;
    int value;
    while (true) {
        cin >> command;
        if (command == 'a') { // add
            cin >> value;
            heap.add(value);
        } else if (command == 'd') { // delete
            int removed_value = heap.remove();
            if (removed_value != -1) {
                cout <<removed_value << endl;
            }
        } else if (command == 'p') { // print
            heap.print_heap();
        } else if (command == 'e') { // exit
            break;
        } else {
            cout << "Invalid command!" << endl;
        }
    }

    return 0;
}