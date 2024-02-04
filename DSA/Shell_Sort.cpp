#include<iostream>
using namespace std;

void ShellSort(int a[], int n){

    for(int gap=n/2; gap > 0; gap=gap/2){

        for(int j=gap; j<n;j++){
            int temp=a[j];

            int i=0;

            for(i=j; i>= gap && a[i-gap] > temp; i=i-gap){
                a[i]=a[i-gap];
            }
            a[i]=temp;
        }
    }

    cout<<"The sorted elements are: \n";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}

int main(){
    system("cls");

    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements: \n";
    for(int i=0;i<n;i++)
    cin>>arr[i];

    ShellSort(arr, n);

    return 0;
}