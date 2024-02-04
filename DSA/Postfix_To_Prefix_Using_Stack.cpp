#include<iostream>
#include<stack>
using namespace std;

string PostfixToPrefix(string postfix){
    stack<string> s;

    for(int i=0;i<postfix.length();i++){

        if((postfix[i] >= 'a' && postfix[i] <= 'z') || (postfix[i] >= 'A' && postfix[i] <= 'Z')){
            string op(1, postfix[i]);
            s.push(op);
        }
        else{
            string op1= s.top();
            s.pop();
            string op2= s.top();
            s.pop();
            string exp= postfix[i]+op2+op1;
            s.push(exp);
        }
    }
    return s.top();
}

int main(){
    system("cls");

    string prefix, postfix;

    cout<<"Enter the postfix expression: \n";
    cin>>postfix;

    prefix= PostfixToPrefix(postfix);

    cout<<"The prefix expression is: "<<prefix;
    return 0;
}