#include<iostream>-
using namespace std;

int Partition(int a[], int s, int e){
    int pivot= a[e];
    int pIndex=s;
    for(int i=s;i<e;i++){
        if(a[i] <= pivot){
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
    swap(a[e], a[pIndex]);
    return pIndex;
}

void QuickSort(int a[], int s, int e){

    if(s < e){
        int p=Partition(a, s, e);
        QuickSort(a, s, p-1);
        QuickSort(a,p+1,e);
    }
}

int main(){
    system("cls");

    int n;

    cout<<"Enter the number of elements: \n";
    cin>>n;

    int arr[n];

    cout<<"Enter the elements: \n";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<endl;
    QuickSort(arr, 0, n-1);

    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";

    return 0;
}