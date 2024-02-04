#include<iostream>
#include<stack>
using namespace std;

string PostfixToInfix(string postfix){
    stack<string> s;

    for(int i=0;i<postfix.length();i++){

        if((postfix[i] >= 'a' && postfix[i] <= 'z') || (postfix[i] >= 'A' && postfix[i] <= 'Z')){
            string op(1, postfix[i]);
            s.push(op);
        }

        else{
            string op1, op2;
            op1=s.top();
            s.pop();

            op2=s.top();
            s.pop();

            string exp='('+ op2 + postfix[i] + op1 + ')';
            s.push(exp);
        }
    }
    return s.top();
}

int main(){
    system("cls");

    string infix, postfix;

    cout<<"Enter a Postfix Expression: \n";
    cin>>postfix;

    infix= PostfixToInfix(postfix);

    cout<<"\nInfix Expression: "<<infix;
    return 0;
}