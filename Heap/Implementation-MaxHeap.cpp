#include<iostream>
#include<queue>
using namespace std;

class heap {
    public:
        int arr[100];
        int size = 0;

    void insert(int val) {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index > 1) {
            int parent = index/2;

            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }
    void print () {
        for(int i = 1; i <= size; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void deleteRoot() {
        if(size == 0){
            cout<<"nothing to delete"<<endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        //take root node to its correct position
        int i = 1;
        while(i < size) {
            int leftIndex = 2*i;
            int rightIndex = 2*i + 1;

            if(leftIndex < size && arr[i] < arr[leftIndex]) {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex < size && arr[i] < arr[rightIndex]) {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return;
            }
        }
    }
};

// Create a heap from an array - O(logn)
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest] < arr[left]) {
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]) {
        largest = right;
    }

    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int size = n;
    while(size > 1) {
        //step 1 - swap root node with node at last index
        swap(arr[1], arr[size]);
        size--;
        //step 2 - place root node at correct position
        heapify(arr, size, 1); 
    }
}

int main () {
    heap h;
    h.insert(60);
    h.insert(50);
    h.insert(40);
    h.insert(30);
    h.insert(20);
    h.print(); // 60 50 40 30 20
    h.insert(55);
    h.print(); // 60 50 55 30 20 40
    h.insert(70);
    h.print(); // 70 50 60 30 20 40 55
    h.deleteRoot();
    h.print(); // 60 50 55 30 20 40

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i = n/2; i > 0; i--) {
        heapify(arr, n, i);
    }
    cout<<"After Heapify: "<<endl;
    for(int i = 1; i <= n; i++) {
        cout<<arr[i]<<" "; // 55 53 54 52 50
    }
    cout<<endl;

    //heap sort
    heapSort(arr, n);
    cout<<"After Heap Sort: "<<endl;
    for(int i = 1; i <= n; i++) {
        cout<<arr[i]<<" "; // 50 52 53 54 55
    }
    cout<<endl;

    cout<<"Using Priority Queue STL:"<<endl;
    //max heap
    priority_queue<int> pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(1);

    cout<<"Element at top: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Element at top: "<<pq.top()<<endl;


    //min heap
    priority_queue<int, vector<int>, greater<int>> minheap;

    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(1);

    cout<<"Element at top: "<<minheap.top()<<endl;
    minheap.pop();
    cout<<"Element at top: "<<minheap.top()<<endl;

}