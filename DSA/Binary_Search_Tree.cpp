#include<iostream>
#define SPACE 10
using namespace std;

class TreeNode{
    public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(){
        value=0;
        left= NULL;
        right = NULL;
    }

    TreeNode(int val){
        value = val;
        left = NULL;
        right = NULL;
    }

};

class BST{
    public:
    TreeNode* root;
    BST(){
        root = NULL;
    }

    bool isEmpty(){
        if(root == NULL)
        return true;

        else
        return false;
    }

    void insertNode(TreeNode* new_node){
        
        if(root == NULL){
            root = new_node;
            cout<<"Value Inserted as root node!"<<endl;
        }

        else{
            TreeNode* temp =root;

            while(temp!=NULL){
                if(new_node->value == temp->value){
                    cout<<"Value Already Exist, Insert another value!"<<endl;
                    return;
                }
                else if((new_node->value < temp->value) && (temp->left == NULL)){
                    temp->left = new_node;
                    cout<<"Value Inserted!"<<endl;
                    break;
                }
                else if(new_node->value < temp->value){
                    temp = temp->left;
                }
                else if((new_node->value > temp->value) && (temp->right == NULL)){
                    temp->right = new_node;
                    cout<<"Value Inserted!"<<endl;
                    break;
                }
                else{
                    temp= temp->right;
                }
            }
        }
    }

    int getBalanceFactor(TreeNode* n){
        if(n == NULL )
        return -1;

        else
        return (height(n->left) - height(n->right)); 
    }

    TreeNode* rightRotate(TreeNode* y){
        TreeNode* x = y->left;
        TreeNode * T2 = x->right;

        x->right =y ; // change the right child of X to be Y
        y->left = T2;

        return x;
    }

    TreeNode* leftRotate(TreeNode* x){
        TreeNode* y = x->right;
        TreeNode * T2 = y->left;

        y->left = x ; // change the right child of X to be Y
        x->right = T2;
        
        return y;
    }

    TreeNode* insertRecursive(TreeNode* r, TreeNode* new_node){

        if(r == NULL){
            r = new_node;
            return r;
        }

        else if(r->value > new_node->value){
            r->left = insertRecursive(r->left, new_node);
        }

        else if(r->value < new_node->value)
        r->right = insertRecursive(r->right, new_node);

        else
        cout<<"Duplicates not allowed \n";

        int bf= getBalanceFactor(r);

        if(bf > 1 && new_node->value < r->left->value)
        return rightRotate(r);

        if(bf < -1 && new_node->value > r->left->value)
        return leftRotate(r);

        if(bf > 1 && new_node->value > r->left->value){
            r->left = leftRotate(r->left);
            return rightRotate(r);
        }

        if(bf < -1 && new_node->value < r->left->value){
            r->right = rightRotate(r->right);
            return rightRotate(r);
        }
        


        return r;
    }

    void print2D(TreeNode* r, int space){
        if(r == NULL) // Base Case
        return;

        space += SPACE; // Increase the distance between levels
        print2D(r->right, space); // Process right child first
        cout<<endl;

        for(int i=SPACE; i<space ;i++) // Print current node after space count
        cout<<" ";

        cout<<r->value<<"\n";
        print2D(r->left, space); // Process left child 
    }

    void printPreorder(TreeNode* n){

        if( n == NULL)
        return;

        cout<<n->value<<" ";
        printPreorder(n->left);
        printPreorder(n->right);

    }
    
    void printInorder(TreeNode* n){

        if( n == NULL)
        return;

        printInorder(n->left);
        cout<<n->value<<" ";
        printInorder(n->right);
    }

    void printPostorder(TreeNode* n){
        if(n == NULL)
        return;

        printPostorder(n->left);
        printPostorder(n->right);
        cout<<n->value<<" ";
    }

    TreeNode* iterativeSearch(int val){

        if(root == NULL)
        return NULL;

        else{
            TreeNode* temp = root;

            while(temp != NULL){

            if(val == temp->value)
            return temp;

            else if(val < temp->value)
            temp = temp->left;

            else
            temp = temp->right;
            }
        }
        return NULL;
    }

    int height(TreeNode* n){
        if( n == NULL)
        return -1;

        else{
            int lheight = height(n->left);
            int rheight = height(n->right);

            if( lheight > rheight)
            return lheight+1;

            else
            return rheight+1;
        }
    }

    void printGivenLevel(TreeNode* n, int level){

        if(n == NULL)
            return;

        else if(level == 0)
         cout<<n->value<<" ";

        else{
            printGivenLevel(n->left, level-1);
            printGivenLevel(n->right, level-1);
        }
    }

    void printLevelOrderBFS(TreeNode* n){

        int Height= height(n);

        for(int i=0;i<=Height;i++)
            printGivenLevel(n, i);
    }

    TreeNode* minValueNode(TreeNode* n){
        TreeNode* current = n;

        while(current->left != NULL)
            current= current->left;
        return current;
    }

    TreeNode* deleteNode(TreeNode* n, int v){
        if(n == NULL)
        return NULL;

        else if(v < n->value)
            n->left = deleteNode(n->left, v);

        else if(v > n->value)
            n->right = deleteNode(n->right, v);
        
        else{
            TreeNode* temp;
            if(n->left == NULL){
                temp = n->right;
                delete n;
                return temp;
            }

            else if(n->right == NULL){
                temp = n->left;
                delete n;
                return temp;
            }

            else{
                temp = minValueNode(n->right);
                n->value = temp->value;
                n->right = deleteNode(n->right, temp->value);
            }
        }

        return n;

    }

    TreeNode* AVLdeleteNode(TreeNode* n, int v){
        if(n == NULL)
        return NULL;

        else if(v < n->value)
            n->left = deleteNode(n->left, v);

        else if(v > n->value)
            n->right = deleteNode(n->right, v);
        
        else{
            TreeNode* temp;
            if(n->left == NULL){
                temp = n->right;
                delete n;
                return temp;
            }

            else if(n->right == NULL){
                temp = n->left;
                delete n;
                return temp;
            }

            else{
                temp = minValueNode(n->right);
                n->value = temp->value;
                n->right = deleteNode(n->right, temp->value);
            }
        }

        int bf= getBalanceFactor(n);

        if(bf == 2  && getBalanceFactor(n->left) >= 0)
        return rightRotate(n);

        else if(bf == 2 && getBalanceFactor(n->left) == -1){
            n->left = leftRotate(n->left);
            return rightRotate(n);
        }

        else if(bf == -2 && getBalanceFactor(n->right) <= 0)
        return leftRotate(n);

        else if(bf == -2 && getBalanceFactor(n->right) == 1){
            n->right = rightRotate(n->right);
            return leftRotate(n);
        }

        return n;

    }


};

int main(){
    system("cls");

   // TreeNode t1;
    BST b1;
    int value, option;

    do{

        cout<<"What operation do you want to perform? \nSelect Option number. Enter 0 to exit: \n";
        cout<<"1. Insert Node \n";
        cout<<"2. Search Node \n";
        cout<<"3. Delete Node \n";
        cout<<"4. print BST values \n";
        cout<<"5. Height of tree \n";
        cout<<"6. Clear Screen \n";
        cout<<"0. Exit Program \n";

        cin>>option;
        TreeNode* new_node = new TreeNode();

        switch(option){
            case 0:
                break;

            case 1:
                cout<<"INSERT \n";
                cout<<"Enter the value of TREE NODE to INSERT in BST: ";
                cin>>value;
                new_node->value = value;
                //  b1.insertNode(new_node);
                b1.root=b1.insertRecursive(b1.root, new_node);
                //insertion code
                break;
            
            case 2:
                cout<<"SEARCH \n";
                cout<<"Enter the value to be searched: ";
                cin>>value;
                new_node = b1.iterativeSearch(value);
                
                if(new_node != NULL)
                cout<<"Value Found\n";
                else
                cout<<"Value not Found \n";
                break;
            
            case 3:
                cout<<"DELETE \n";
                cout<<"Enter the value to be deleted: ";
                cin>>value;
                new_node = b1.iterativeSearch(value);

                if(new_node != NULL){
                    b1.root=b1.AVLdeleteNode(b1.root, value);
                    cout<<"Value Deleted \n";
                }
                else
                    cout<<"Value not found: \n";
                
                break;

            case 4:
                cout<<"PRINT AND TRAVERSE \n";

                cout<<"2D Traversal\n";
                b1.print2D(b1.root, 5);
                cout<<endl<<endl;

                cout<<"PreOrder Traversal\n";
                b1.printPreorder(b1.root);
                cout<<endl<<endl;

                cout<<"InOrder Traversal\n";
                b1.printInorder(b1.root);
                cout<<endl<<endl;

                cout<<"PostOrder Traversal\n";
                b1.printPostorder(b1.root);
                cout<<endl<<endl;

                cout<<"Level Order BFS Traversal\n";
                b1.printLevelOrderBFS(b1.root);
                cout<<endl<<endl;

                break;

            case 5:
                cout<<"TREE HEIGHT \n";
                cout<<"Height: "<<b1.height(b1.root)<<endl;
                break;

            case 6:
                cout<<"CLEAR SCREEN \n";
                system("cls");
                break;

            default:
                cout<<"Enter proper option number \n";

        }

    }while(option != 0);

    return 0;
}