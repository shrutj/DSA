#include<iostream>
using namespace std;

class Node{
    public:
    int key;
    int data;
    Node* next;

    Node(){
        key=0;
        data=0;
        next= NULL;
    }

    Node(int k, int d){
        key=k;
        data=d;
        next=NULL;
    }
};

class Queue{
    public:
    Node* front;
    Node* rear;

    Queue(){
        front = NULL;
        rear = NULL;
    }

    bool isEmpty(){
        if(front == NULL && rear == NULL)
        return true;
        else
        return false;
    }

    bool checkIfNodeExist(Node* n){
        Node* temp= front;
        bool exist = false;

        do{
            if(temp->key == n->key){
            return true;
            break;
            }
            temp=temp->next;
        }while(temp != front);

        return exist;
    }

    void enqueue(Node* n){
        if(isEmpty()){
            front = n;
            rear = n;
            front->next=n;
            cout<<"Node Enqueued \n";
        }

        else if(checkIfNodeExist(n)){
            cout<<"Node already exist with the same key, change the key and enqueue again \n";
        }

        else{
            rear->next = n;
            rear= n;
            n->next=front;
            cout<<"Node Enqueued \n";
        }
    }

    Node* dequeue(){
        Node* temp=NULL;
        if(isEmpty()){
            cout<<"No  Node to dequeue \n";
            return NULL;
        }
        else{
            if(front == rear){
                temp = front;
                front = NULL;
                rear = NULL;
                return temp;
            }

            else{
                temp = front;
                front =front->next;
                rear->next=front;
                return temp;
            }
        }
    }

    int count(){
        int count =0;
        Node* temp=front;
        if(isEmpty())
        return 0;

        do{
            count++;
            temp=temp->next;
        }while(temp!=front);
        return count;
    }

    void display(){
        cout<<"All values in the queue are: "<<endl;
        Node* temp=front;
        do{
            cout<<" ("<<temp->key<<" , "<<temp->data<<")"<<" -> ";
            temp=temp->next;
        }while(temp != front);
        cout<<" ("<<temp->key<<" , "<<temp->data<<")";
        cout<<"\nTotal no of Nodes in the queue :"<<count()<<endl;
        cout<<endl;
    }
};



int main(){
    system("cls");

    Queue q;
    int option, key, data;

    do{
        cout<<"What operation do you want to perform? "<<"\nSelect option Number. Enter 0 to exit. \n";
        cout<<"1. Enqueue() \n";
        cout<<"2. Dequeue() \n";
        cout<<"3. isEmpty() \n";
        cout<<"4. count() \n";
        cout<<"5. display() \n";
        cout<<"6. Clear Screen \n"<<endl;
        cin>>option;

        Node* new_node= new Node();  

        switch(option){
            case 0:
                break;

            case 1:
                cout<<"Enter KEY and VALUE of NODE to Enqueue \n";
                cin>>key;
                cin>>data;
                new_node->key= key;
                new_node->data= data;
                q.enqueue(new_node);
                break;

            case 2:
                cout<<"Dequeue function called- \n";
                new_node= q.dequeue();
                cout<<"Dequeued value is: ("<<new_node->key<<" , "<<new_node->data<<" )\n";
                delete new_node;
                break;

            case 3:
            cout<<"isEmpty function called- \n";
                if(q.isEmpty())
                cout<<"Queue is Empty \n";
                else
                cout<<"Queue is not Empty \n";
                break;

            case 4:
                cout<<"Count function called: \n";
                cout<<"No of nodes in the queue: "<<q.count()<<endl;
                break;

            case 5:
                cout<<"Display function called- \n";
                q.display();
                cout<<endl;
                break;

            case 6:
                system("cls");
                break;
            
            default:
                cout<<"Enter Proper Option Number \n";

        }
    }while(option != 0);

    return 0;
}