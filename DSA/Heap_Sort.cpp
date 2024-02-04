#include<iostream>
#include<math.h>
using namespace std;

class MinHeap{

    public:
    int *harr;
    int capacity;
    int heap_size;

    MinHeap(int cap){
        heap_size=cap;   // here heap_size for heap sort = cap but for simple heap operations heap_size = 0
        capacity = cap;
        harr = new int[cap];
    }

    void linearSearch(int val){
        for(int i=0;i<heap_size;i++){
            if(harr[i] == val)
            {
                cout<<"Value Found!!";
                return;
            }
        }
        cout<<"value not Found!!";
    }

    void printArray(){
        for(int i=0;i<heap_size;i++)
            cout<<harr[i]<<" ";
            cout<<endl;
        
    }

    int height(){
        return ceil(log2(heap_size + 1)) -1;
    }

    int parent(int i){
        return (i-1)/2;
    }

    int left(int i){
        return (2*i+1);
    }

    int right(int i){
        return (2*i+2);
    }

    void insertKey(int k){
        
        if(heap_size == capacity){
            cout<<"OVERFLOW!! Heap Full\n";
            return ;
        }

        heap_size++;
        int i=heap_size-1;

        harr[i]=k;

        while(i!=0 && harr[parent(i)] > harr[i]){
            swap(harr[i],harr[parent(i)]);
            i=parent(i);
        }

    }

    void minHeapify(int i){
        int l= left(i);
        int r= right(i);
        int smallest = i;

        if( l < heap_size && harr[l] < harr[i])
        smallest = l;

        if(r < heap_size && harr[r] < harr[smallest])
        smallest = r;

        if(smallest != i){
            swap(harr[i], harr[smallest]);
            minHeapify(smallest);
        }
    }


    int extractMin(){

        if(heap_size <= 0)
        return INT16_MAX;

        if(heap_size == 1){
            heap_size--;
            return harr[0];
        }

        int root = harr[0];
        harr[0]=harr[heap_size-1];
        heap_size--;
        minHeapify(0);
        return root;

    }

    int getMin(){
        return harr[0];
    }

    void decreaseKey(int i, int new_val){
        harr[i] = new_val;

        while(i != 0 && harr[parent(i) > harr[i]]){
            swap(harr[parent(i)], harr[i]);
            i=parent(i);
        }
    }

    void deleteKey(int i){
        decreaseKey(i, INT16_MIN);
        extractMin();
    }

    void getUnsortedArray(){

        cout<<"Enter "<<capacity<<" no of elements to sort using HEAPSORT \n";
        for(int i=0;i<capacity;i++)
        cin>>harr[i];
    }

    void heapSort(){
        int temp[capacity];

        for(int i=0;i<capacity;i++){
            temp[i]=extractMin();
            cout<<temp[i]<<" ";
        }
    }



};


int main(){
    system("cls");

    int s;
    cout<<"Enter the size of Min Heap: "<<endl;
    cin>>s;

    MinHeap obj(s);

    obj.getUnsortedArray();

    cout<<"unsorted Array: \n";
    obj.printArray();

    for(int i=s/2-1;i>=0;i--)
        obj.minHeapify(i);

    obj.heapSort();


    return 0;
}