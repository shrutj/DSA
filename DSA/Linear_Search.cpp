#include<iostream>
using namespace std;

void LinearSearch(int a[], int n, int size){
    int temp=0;

    for(int i=0;i<size;i++){
        if(a[i]==n){
            cout<<"The element is found at position: "<<i+1<<endl;
            temp=1;
            break;
        }
    }
    if(temp == 0)
    cout<<"Element not found!!";
}

int main(){
    system("cls");

    int arr[5];
    int n,ele;

    cout<<"Enter the number of elements (max: 5): \n";
    cin>>n;

    cout<<"Enter the elements: \n";
    for(int i=0;i<n;i++)
    cin>>arr[i];

    cout<<"Enter the element to be searched: \n";
    cin>>ele;

    LinearSearch(arr, ele, n);
    return 0;
}
