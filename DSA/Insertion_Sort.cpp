#include<iostream>
using namespace std;

void Insertion_sort(int a[], int n){
    for(int i=1;i<n;i++){
        int j=i, key=a[i];

        while(j>0 && a[j-1]>key ){
            a[j]=a[j-1];
            j--;
        }

        a[j]=key;
        // cout<<"\n"<<i<<" iteration\n";
        // for(int k=0;k<n;k++)
        // cout<<a[k]<<" ";
    }

    cout<<"The sorted  array is: \n";
    for(int i=0;i<n;i++)
    cout<<a[i]<<endl;
}

int main(){
    system("cls");

    int n, arr[10];

    cout<<"Enter the size of the array (max: 10):\n";
    cin>>n;

    cout<<"Enter the array elements: \n";
    for(int i=0;i<n;i++)
    cin>>arr[i];

    Insertion_sort(arr, n);

    return 0;
}
