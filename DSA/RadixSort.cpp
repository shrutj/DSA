#include<iostream>
using namespace std;

void CountingSort(int a[], int n, int d){
    
    int count[10];
    int output[n];

    for(int i=0;i<10;i++)
    count[i]=0;

    for(int i=0;i<n;i++){
        count[(a[i]/d)%10]++;
    }

    for(int i=1;i<10;i++)
    count[i]=count[i]+count[i-1];

    for(int i=n-1; i>=0;i--){
        output[count[((a[i]/d)%10)]-1]=a[i];
        count[((a[i]/d)%10)]--;
    }

    for(int i=0;i<n;i++)
    a[i]=output[i];
}

void RadixSort(int a[], int n){
    int large=a[0];

    for(int i=1;i<n;i++)
        if(a[i]> large)
        large=a[i];
    // int j=1;
    // while (large >= 0)
    // {
    //     CountingSort(a, n, j);
    //     j=j*10;
    //     large =large/10;
    // }
    
    for(int i=1; large>0; i=i*10){
        CountingSort(a, n, i);
        large=large/10;
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

    RadixSort(arr, n);

    cout<<"The sorted array is: \n";
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";

    return 0;
}