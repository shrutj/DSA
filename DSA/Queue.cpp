#include<iostream>
using namespace std;

class Queue{
    int front, rear;
    int arr[5];

   public:
    Queue(){
        front= rear= -1;
        for(int i=0;i<5; i++){
            arr[i]=0;
        }
    }

    bool isEmpty(){
        if(front == -1 && rear == -1){
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull(){
        if(rear == 4){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int val){
        if(isFull()){
            cout<<"Queue id Full \n";
            return;
        }
        else if(isEmpty()){
            front++;
            rear++;
            arr[rear]=val;
        }
        else{
            rear++;
            arr[rear]=val;
        }
        
    }

    int dequeue(){
        int temp;
        if(isEmpty()){
            cout<<"Queue is Empty \n";
            return 0;
        }
        else if( front == rear){
            temp=arr[front];
            arr[front]=0;
            front=rear=-1;
            return temp;
        }
        else{
            temp=arr[front];
            arr[front]=0;
            front++;
            return temp;
        }
    }

    int count(){
        return (rear-front+1);
    }

     void display(){
        cout<<"All values of queue are here \n";
        for(int i=0; i<=4; i++)
        cout<<arr[i]<<"  ";
    }

};


int main(){
    system("cls");

    Queue q1;

    int option, pos, value;
    
    do{
        cout<<"Choose any option : \n";
        cout<<"1. Enqueue \n";
        cout<<"2. Dequeue \n";
        cout<<"3. isEmpty() \n";
        cout<<"4. isFull() \n";
        cout<<"5. count() \n";
        cout<<"6. display() \n";
        cout<<"7. Clear Screen() \n";
        cout<<"0. Exit \n\n\n";

        cin>>option;

        switch(option){
        case 0:
            break;

        case 1:
            cout<<"Enter value to perform Enqueue Operation: \n";
            cin>>value;
            q1.enqueue(value);
            break;
        
        case 2:
            cout<<"Dequeue operation called \n";
            q1.dequeue();
            break;

        case 3:
            if(q1.isEmpty())
            cout<<"Queue id Empty \n";
            else
            cout<<"Queue is not Empty \n";
            break;

        case 4:
            if(q1.isFull())
            cout<<"Queue is Full \n";
            else
            cout<<"Queue is not Full \n";
            break;

        case 5:
            cout<<"Count operation called!! count of items in the queue is: "<<q1.count();
            break;

        case 6:
            q1.display();
            break;

        case 7:
            system("cls");
            break;

        default:
            cout<<"Enter proper value!! \n";
    }

    }while(option != 0);

    return 0;
}