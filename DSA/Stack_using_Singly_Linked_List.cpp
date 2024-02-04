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

class Stack{
    public:
    Node* top;

    Stack(){
        top=NULL;
    }

    bool isEmpty(){
        if(top == NULL)
        return true;
        else
        return false;
    }

    bool checkIfNodeExists(Node* n){
        Node* temp=top;
        bool exist =false;

        while(temp != NULL){
            if(temp->key == n->key){
                exist =true;
                break;
            }
            temp =temp->next;
        }
        return exist;
    }



    void push(Node* n){
        if(top == NULL){
            top = n;
            cout<<"Node Pushed \n";
        }

        else if(checkIfNodeExists(n))
            cout<<"Same key not alloewed \n";
        
        else{
            Node* temp= top;
            top=n;
            n->next= temp;
            cout<<"Node Pushed \n";
        }
    }

    Node* pop(){
        Node* temp = NULL;
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
            return temp;
        }  
        else{
            temp= top;
            top= top->next;
            return temp;

        } 
    }

    Node* peek(){
        if(isEmpty()){
            cout<<"Stack Underflow \n";
            return NULL;
        }
        else
        return top;
    }

    int count(){
        int count = 0;
        Node* temp=top;
        while(temp != NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }

    void display(){
        cout<<"All values in the stack are: "<<endl;
        Node* temp=top;
        while(temp != NULL){
            cout<<" ("<<temp->key<<" , "<<temp->data<<")"<<" -> "<<endl;
            temp=temp->next;
        }
        cout<<"Total no of Nodes in the stack :"<<count()<<endl;
        cout<<endl;
    }
};

int main(){
    system("cls");

    Stack s1;
    int option, position, key, data;

    do{
        cout<<"What operation do you want to perform? "<<"\nSelect option Number. Enter 0 to exit. \n";
        cout<<"1. Push() \n";
        cout<<"2. Pop() \n";
        cout<<"3. isEmpty() \n";
        cout<<"4. peek() \n";
        cout<<"5. count() \n";
        cout<<"6. display() \n";
        cout<<"7. Clear Screen \n";
        cin>>option;

        Node* new_node= new Node();  

        switch(option){
            case 0:
                break;

            case 1:
                cout<<"Enter KEY and VALUE of NODE to push int the stack \n";
                cin>>key;
                cin>>data;
                new_node->key= key;
                new_node->data= data;
                s1.push(new_node);
                break;

            case 2:
                cout<<"POp function called- Popped Value: \n";
                new_node= s1.pop();
                cout<<"Top of the Stack is: ("<<new_node->key<<" , "<<new_node->data<<" )\n";
                delete new_node;
                break;

            case 3:
                if(s1.isEmpty())
                cout<<"Stack is Empty \n";
                else
                cout<<"Stack is not Empty \n";
                break;

            case 4:
                if(s1.isEmpty()){
                    cout<<"Stack is Empty \n";
                }
                else{
                    cout<<"PEEK function called: \n";
                    new_node=s1.peek();
                    cout<<"Top of the Stack is: ("<<new_node->key<<" , "<<new_node->data<<" )\n";
                    break;
                }

            case 5:
                cout<<"Count function called: \n";
                cout<<"No of nodes in the Stack: "<<s1.count()<<endl;
                break;

            case 6:
                cout<<"Display function called- \n";
                s1.display();
                break;

            case 7:
                system("cls");
                break;
            
            default:
                cout<<"Enter Proper Option Number \n";

        }
    }while(option != 0);

    return 0;
}