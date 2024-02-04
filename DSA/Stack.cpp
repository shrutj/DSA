#include<iostream>
using namespace std;

class Stack{
    int top;
    int arr[5];

   public:
    Stack(){
        top=-1;

        for(int i=0; i<5; i++)
            arr[i]=0;
    }

    bool isEmpty(){
        if(top==-1)
            return true;
        else
            return false;
    }

    bool isFull(){
        if(top==4)
           return true;
        else
            return false;
    }

    void Push(int val){
        if( isFull())
          cout<<"Stack Overflow!! \n";
        else{
            top++;
            arr[top]=val;
        }
    }

    int Pop(){
        if(isEmpty()){
            cout<<"Stack UnderFlow!! \n";
            return 0;
        }
        else{
            int temp=arr[top];
            arr[top]= 0;
            top--;
            return temp;
        }
    }

    int count(){
        return top+1;
    }

    int Peek(int pos){
        if(isEmpty()){
            cout<<"The Stack is Empty \n";
            return 0;
        }
        else{
            return arr[pos];
        }
    }

    void change(int pos, int val){
        if(top < pos-1){
            cout<<"The stack is Empty at "<<pos<<"th position \n";
        }
        else{
            arr[pos]= val;
            cout<<"The value has updated!! \n";
        }
    }

    void display(){
        cout<<"All values of stack are here \n";
        for(int i=top; i>=0; i--)
        cout<<arr[i]<<endl;
    }
};


int main(){
    system("cls");

    Stack s1;

    int option, pos, value;
    
    do{
        cout<<"Choose any option : \n";
        cout<<"1. Push \n";
        cout<<"2. Pop \n";
        cout<<"3. isEmpty() \n";
        cout<<"4. isFull() \n";
        cout<<"5. Peek() \n";
        cout<<"6. count() \n";
        cout<<"7. change() \n";
        cout<<"8. display() \n";
        cout<<"9. Clear Screen() \n";
        cout<<"0. Exit \n\n\n";

        cin>>option;

        switch(option){
        case 1:
            cout<<"Enter the value to push: ";
            cin>>value;
            s1.Push(value);
            break;

        case 2:
            cout<<"The value is popped!! \n"<<s1.Pop();
            break;
        
        case 3:
            if(s1.isEmpty())
            cout<<"The stack is Empty!!\n";
            else
            cout<<"The stack is not Empty!! \n";
            break;

        case 4:
            if(s1.isFull())
            cout<<"The stack is Full!!\n";
            else
            cout<<"The stack is not Full!! \n";
            break;

        case 5:
            cout<<"Enter the position: ";
            cin>>pos;
            cout<<"Peek function called: \n"<<s1.Peek(pos);
            break;
        
        case 6:
            cout<<"The number of items in the stack is: "<<s1.count();
            break;

        case 7:
            cout<<"Enter position of the item you want to change: ";
            cin>>pos;
            cout<<"Enter the value you want to insert: ";
            cin>>value;
            s1.change(pos, value);
            break;

        case 8:
            s1.display();
            break;
        
        case 9:
            system("cls");
            break;

        case 0:
            cout<<"The program teminated!!";
            break;
        
        default:
            cout<<"Enter proper value!!";
    }

    }while(option != 0);

    return 0;
}