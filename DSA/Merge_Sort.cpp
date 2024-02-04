#include<iostream>
using namespace std;


void merge(int a[], int l, int r, int m){
    int i=l, j=m+1, k=0;
    int size= (r-l)+1;
    int temp[size];

    while(i<=m && j<=r){
        if(a[i]<= a[j]){
            temp[k]=a[i];
            i++, k++;
        }
        else{
            temp[k]=a[j];
            j++, k++;
        }
    }

    while(i<=m){
        temp[k]=a[i];
        k++, i++;
    }

    while(j<=r){
        temp[k]=a[j];
        k++, j++;
    }
    
    for(int p=l, q=0; p<=r, q<size; p++, q++)
    a[p]= temp[q];
    
}


void mergeSort(int a[], int l, int r){

    if(l < r){
        int m=l+(r-l)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, r, m);
    }
}

int main(){
    system("cls");

    int n;

    cout<<"Enter the size of array: \n";
    cin>>n;

    int arr[n];

    cout<<"Enter the array elements: \n";
    for(int i=0;i<n;i++)
    cin>>arr[i];

    mergeSort(arr,0, n-1);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";

    return 0;
}