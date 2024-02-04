#include<iostream>
using namespace std;

void CountingSort(int a[], int n, int r){
    int oupArr[n];
    int count_arr[r];
    for(int i=0;i<r;i++){
        count_arr[i]=0;
    }

    for(int i=0;i<n;i++){
        ++count_arr[a[i]];
    }

    for(int i=1;i<r;i++){
        count_arr[i]=count_arr[i]+count_arr[i-1];
    }
    
    for(int i = 0; i < n; i++){
        oupArr[count_arr[a[i]]-1]=a[i];
        --count_arr[a[i]];
    }

    
    cout<<"\nThe sorted elements are: \n";
    for(int i=0;i<n;i++)
    cout<<oupArr[i]<<" ";
    
}

int main(){
    system("cls");

    int n;
    cout<<"Enter the number of elements: \n";
    cin>>n;

    int range;
    cout<<"Enter the range of the elemets: \n";
    cin>>range;

    int inpArr[n];

    cout<<"Enter the array elements: \n";
    for(int i=0;i<n;i++)
    cin>>inpArr[i];

    CountingSort(inpArr, n, range);


    return 0;
}