#include<iostream>
using namespace std;

/* Non optimized Bubble sort */ 
// void BubbleSort(int a[], int n){
//     int temp;
//     for(int i=0;i<n-1;i++){

//         for(int j=0;j<n-i-1;j++){
//             if(a[j]> a[j+1]){
//                 temp=a[j];
//                 a[j]=a[j+1];
//                 a[j+1]=temp;
//             }
//         }
//         // cout<<"\n"<<i<<" iteration\n";
//         // for(int k=0;k<n;k++)
//         // cout<<a[k]<<endl;
//     }

//     cout<<"The sorted array is: \n";
//     for(int i=0;i<n;i++)
//     cout<<a[i]<<endl;
// }

/* Optimized Bubble sort*/
void BubbleSort(int a[], int n){
    int temp;
    for(int i=0;i<n-1;i++){
        bool flag= false;

        for(int j=0;j<n-i-1;j++){
            if(a[j]> a[j+1]){
                flag = true;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        if(flag == false) // flag will only remain false when swapping does not happens that means array is already sorted
        break;
        // cout<<"\n"<<i<<" iteration\n";
        // for(int k=0;k<n;k++)
        // cout<<a[k]<<endl;
    }

    cout<<"The sorted array is: \n";
    for(int i=0;i<n;i++)
    cout<<a[i]<<endl;
}

int main(){
    system("cls");

    int arr[10], n;

    cout<<"Enter the number of elements (max: 10): \n";
    cin>>n;

    cout<<"Enter the elements: \n";
    for(int i=0;i<n;i++)
    cin>>arr[i];

    BubbleSort(arr, n);

    return 0;
}