#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    int key;
    Node *next;

    Node(){
        data=0;
        key=0;
        next=NULL;
    }

    Node(int k, int d){
        data=d;
        key=k;
    }
};

class SinglyLinkedList{
    public:
    Node *head;

    SinglyLinkedList(){
        head=NULL;
    }

    SinglyLinkedList(Node *n){
        head= n;
    }

    // Check if node exists using key value
    Node *nodeExists(int k){
        Node *temp= NULL;
        Node *ptr= head;

        while(ptr != NULL){
            if(ptr -> key ==k){
                temp=ptr;
            }
            ptr= ptr->next;
        }
        return temp;
    }

    //Append a node to the list

    void appendNode(Node *n){
        if(nodeExists(n->key) != NULL){
            cout<<"Node already exists with key value: "<<n->key<<", Append another node with different key value\n";

        }

        else if(head == NULL){
                head= n;
                cout<<"Node appended\n";
            }
            else{
                Node *ptr= head;

                while(ptr->next != NULL){
                    ptr= ptr->next;
                }
                ptr->next= n;
                cout<<"Node Appended\n";
            }
        
    }

    // Prepend a node to the list

    void prependNode(Node *n){
        if(nodeExists(n->key) != NULL){
            cout<<"Node already exists with key value: "<<n->key<<", Append another node with different key value\n";
        }
        else if(head == NULL){
            head=n;
            cout<<"Node Prepended as head node\n";
        }
        else{
            n->next= head;
            head= n;
            cout<<"Node prepended\n";
        }
        
    }

    // Insert the node after a particular node in the list

    void insertNodeAfter(int k, Node *n){
         Node *ptr= nodeExists(k);
         if(ptr == NULL){
            cout<<"No node exists with key value: "<<k<<endl;
         }
         else{
            if(nodeExists(n->key) != NULL){
            cout<<"Node already exists with key value: "<<n->key<<", Append another node with different key value\n";
           }
           else{
            n->next=ptr->next;
            ptr->next= n;
            cout<<"New node inserted\n";
            }
         }
    }

    // delete nod eby unique key

    void deleteNodeByKey(int k){
        if(head == NULL){
            cout<<"Singly Linked List is empty. Can't delete anything\n";
        }

        else{
            if(head->key == k){
                head= head->next;
                cout<<"Node unlinked with key value: "<<k<<endl;
            }
            else{
                Node *temp=NULL;
                Node *prevPtr= head;
                Node *currentPtr= head->next;
                while (currentPtr != NULL)
                {
                    if(currentPtr->key == k){
                        temp= currentPtr;
                        currentPtr= NULL;
                    }
                    else{
                        prevPtr= prevPtr->next;
                        currentPtr= currentPtr->next;
                    }
                }

                if(temp != NULL){
                    prevPtr->next= temp->next;
                    cout<<"Node unlinked with keys value: "<<k<<endl;
                }
                else{
                    cout<<"Node doesn't exist with key value: "<<k<<endl;
                }
                
            }
        }
    }

    // Update node by key

    void updateNodeBykey(int k, int d){
        Node *ptr=nodeExists(k);

        if(ptr!=NULL){
            ptr->data= d;
            cout<<"Nod edata updated successfully"<<endl;
        }
        else{
            cout<<"Node doesn't exist with the key value: "<<k<<endl;
        }
    }

    // Print the Singly Linked List

    void printList(){
        if(head== NULL){
            cout<<"No nodes in Singly Linked List\n";
        }
        else{
            cout<<"Singly Linked List values: ";
            Node *temp= head;

            while(temp != NULL){
                cout<<"("<<temp->key<<","<<temp->data<<")\n";
                temp= temp->next;
            }
        }
    }

};

int main(){
    system("cls");

    SinglyLinkedList s;

    int option, key1, data1, k1;
    
    do{
        cout<<"Choose any option : \n";
        cout<<"1. appendNode() \n";
        cout<<"2. prependNode() \n";
        cout<<"3. insertNodeAfter() \n";
        cout<<"4. deleteNodeByKey() \n";
        cout<<"5. updateNodeByKey() \n";
        cout<<"6. print() \n";
        cout<<"7. Clear Screen() \n";
        cout<<"0. Exit \n\n\n";

        cin>>option;
        Node *n1= new Node();

        switch(option){
        case 1:
            cout<<"Append Node Operation: Enter key and data to be appended:"<<endl;
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data= data1;
            s.appendNode(n1);
            break;

        case 2:
            cout<<"Prepend Node Operation: Enter key and data to be Prepended:\n";
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data= data1;
            s.prependNode(n1);
            break;
        
        case 3:
            cout<<"Insert Node After Operation: Enter key of the existing node after which you want to insert this node:\n";
            cin>>k1;
            cout<<"Enter key and data of the new node first:\n";
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data= data1;
            s.insertNodeAfter(k1, n1);
            break;

        case 4:
            cout<<"Delete Node By Key Operation: Enter key of the node to be deleted:\n";
            cin>>k1;
            s.deleteNodeByKey(k1);
            break;

        case 5:
            cout<<"Update Data By Key operation: Enter key and new data to be updated\n";
            cin>>key1;
            cin>>data1;
            s.updateNodeBykey(key1,data1);
            break;
        
        case 6:
            s.printList();
            break;
        
        case 7:
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