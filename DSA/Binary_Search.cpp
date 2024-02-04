#include<iostream>
using namespace std;

void BinarySearch(int a[], int n, int size);

int main(){
    system("cls");

    int arr[5], n, ele;

    cout<<"Enter the number of elemets in the array (max: 5): \n";
    cin>>n;

    cout<<"Enter the elements of the array in ascending order: \n";
    for(int i=0;i<n;i++)
    cin>>arr[i];

    cout<<"Enter the element to be searched: \n";
    cin>>ele;

    BinarySearch(arr, ele, n);

    return 0;
}

void BinarySearch(int a[], int n, int size){
    int temp=0;
    int mid, left=0;
    int right=size-1;
    for(int i=0; i<size; i++){
        mid=(left+right)/2;

        if(a[mid]== n){
        cout<<"Element found at position: "<<mid+1<<endl;
        temp=1;
        break;
        }
        else if(n > a[mid])
        left= mid+1;

        else
        right= mid-1;
    }
    if(temp == 0)
    cout<<"Element is not present in the array!!\n";
}