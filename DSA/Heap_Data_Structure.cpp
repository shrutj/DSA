#include<iostream>
#include<math.h>
using namespace std;

class MinHeap{

    public:
    int *harr;
    int capacity;
    int heap_size;

    MinHeap(int cap){
        heap_size=0;   // here heap_size for heap sort = cap but for simple heap operations heap_size = 0
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




};


int main(){
    system("cls");

    int s;
    cout<<"Enter the size of Min Heap: "<<endl;
    cin>>s;

    MinHeap obj(s);

    cout<<"Min Heap Created"<<endl;

    int option, val;

    do{
        cout<<"What operation do you want to perform? "<<" Select Option number, Enter 0 to exit."<<endl;
        cout<<"1. insert Key/Node"<<endl;
        cout<<"2. Search key/Node"<<endl;
        cout<<"3. Delete Key/Node"<<endl;
        cout<<"4. get Min"<<endl;
        cout<<"5. Extract Min"<<endl;
        cout<<"6. Height of Heap"<<endl;
        cout<<"7. Print/Traversal Heap values"<<endl;
        cout<<"8. Clear Screen"<<endl;
        cout<<"0. Exit Program"<<endl;

        cin>>option;

        switch(option){
            case 0:
                break;
            case 1:
                cout<<"INSERT Operation- "<<endl;
                cout<<"Enter VALUE to INSERT in Heap: ";
                cin>>val;
                obj.insertKey(val);
                cout<<"The key inserted successfully: \n";
                cout<<endl;
                break;
            
            case 2:
                cout<<"SEARCH operation-"<<endl;
                cout<<"Enter VALUE to SEARCH in HEAP: ";
                cin>>val;
                obj.linearSearch(val);
                break;

            case 3:
                cout<<"DELETE Operation-"<<endl;
                cout<<"Enter INDEX of Heap Array to DELETE: ";
                cin>>val;
                obj.deleteKey(val);
                cout<<"Key Deleted!!";
                break;

            case 4:
                cout<<"Get Min value: ";
                cout<<obj.getMin()<<endl;
                cout<<endl;
                break;

            case 5:
                cout<<"EXTRACT Min value: ";
                cout<<obj.extractMin()<<endl;
                cout<<endl;
                break;

            case 6:
                cout<<"HEAP TREE HEIGHT: ";
                //cout<<obj.height()<<endl;
                break;

            case 7:
                cout<<"PRINT Heap Array: "<<endl;
                obj.printArray();
                cout<<endl;
                break;

            case 8:
                system("cls");
                break;
            default:
                cout<<"Enter proper option number"<<endl;
        }

    }while(option != 0);


    return 0;
}