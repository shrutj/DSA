#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    int key;
    Node *next;
    Node *previous;

    Node(){
        data=0;
        key=0;
        next=NULL;
        previous=NULL;
    }

    Node(int k, int d){
        data=d;
        key=k;
    }
};

class DoublyLinkedList{
    public:
    Node *head;

    DoublyLinkedList(){
        head=NULL;
    }

    DoublyLinkedList(Node *n){
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
                n->previous= ptr;
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
            head->previous= n;
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
         else {
            if(nodeExists(n->key) != NULL){
            cout<<"Node already exists with key value: "<<n->key<<", Append another node with different key value\n";
        }
            else{
                Node *nextNode= ptr->next;
                //inserting at the end
                if(nextNode == NULL){
                    n->previous= ptr;
                    ptr->next= n;
                    cout<<"Node Inserted at the END\n";
                }
                //inserting in between
                else{
                n->next=nextNode;
                nextNode->previous= n;
                n->previous= ptr;
                ptr->next= n;
                
                cout<<"New node inserted\n";
                }
            }
        }
    }

    // delete node by unique key

    void deleteNodeByKey(int k){
        Node *ptr= nodeExists(k);
        if(head == NULL){
            cout<<"Doubly Linked List is empty. Can't delete anything\n";
        }
        else if(ptr == NULL){
            cout<<"No node exists with the key value: "<<k<<endl;
        }

        else if(head->key == k){
                head= head->next;
                cout<<"Node unlinked with key value: "<<k<<endl;
            }
        else{
                Node *nextNode= ptr->next;
                Node *prevNode= ptr->previous;

                //deleting at the end
                if(nextNode== NULL){
                    prevNode->next= NULL;
                    cout<<"Node deleted at the end\n";
                }
                //deleteing in between
                else{
                    prevNode->next= nextNode;
                    nextNode->previous= prevNode;
                    cout<<"Node Deleted in Between"<<endl;
                }

            }
        
    }

    // Update node by key

    void updateNodeBykey(int k, int d){
        Node *ptr=nodeExists(k);

        if(ptr!=NULL){
            ptr->data= d;
            cout<<"Node data updated successfully"<<endl;
        }
        else{
            cout<<"Node doesn't exist with the key value: "<<k<<endl;
        }
    }

    // Print the Doubly Linked List

    void printList(){
        if(head== NULL){
            cout<<"No nodes in Doubly Linked List\n";
        }
        else{
            cout<<"Doubly Linked List values: ";
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

    DoublyLinkedList d;

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
        Node *n1= new Node();// n1 is a pointer to a new object of class Node in the heap and not the object itself
                              // We are doing this for dynamic memory allocation
            // To be able to create new nodes in the heap without creating new variables for each node

        switch(option){
        case 1:
            cout<<"Append Node Operation: Enter key and data to be appended:"<<endl;
            cin>>key1;
            cin>>data1;
            n1->key=key1; // we are using n1->key instead of n1.key because n1 is a pointer and not the object
            n1->data= data1;
            d.appendNode(n1); // if we would have used variable instead of pointer then we had to pass
                              // &n1 to return the address of the object because the argument we have
                              // given in the appendNode function is the pointer0 
            break;

        case 2:
            cout<<"Prepend Node Operation: Enter key and data to be Prepended:\n";
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data= data1;
            d.prependNode(n1);
            break;
        
        case 3:
            cout<<"Insert Node After Operation: Enter key of the existing node after which you want to insert this node:\n";
            cin>>k1;
            cout<<"Enter key and data of the new node first:\n";
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data= data1;
            d.insertNodeAfter(k1, n1);
            break;

        case 4:
            cout<<"Delete Node By Key Operation: Enter key of the node to be deleted:\n";
            cin>>k1;
            d.deleteNodeByKey(k1);
            break;

        case 5:
            cout<<"Update Data By Key operation: Enter key and new data to be updated\n";
            cin>>key1;
            cin>>data1;
            d.updateNodeBykey(key1,data1);
            break;
        
        case 6:
            d.printList();
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