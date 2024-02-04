#include<iostream>
using namespace std;

void selectionSort(int a[], int n){
    int min;

    for(int i=0;i<n-1;i++){
        min=i;

        for(int j=i+1;j<n;j++)
            if(a[j]< a[min])
            min=j;
        

        if(i != min){
            int temp= a[min];
            a[min]=a[i];
            a[i]=temp;
        }
    }

    cout<<"The sorted elements are:\n";
    for(int i=0;i<n;i++)
    cout<<a[i]<<endl;
}

int main(){
    system("cls");

    int arr[10];
    int n;

    cout<<"Enter the number of elements in the array:\n";
    cin>>n;

    cout<<"Enter the Elements:\n";
    for(int i=0;i<n;i++)
    cin>>arr[i];

    selectionSort(arr, n);


    return 0;
}