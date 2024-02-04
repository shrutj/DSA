#include<iostream>
#include<stack>
using namespace std;

string PrefixToPostfix(string prefix){
    stack<string> s;

    for(int i=prefix.length()-1;i>=0;i--){
        if((prefix[i] >= 'a' && prefix[i] <= 'z') || (prefix[i] >= 'A' && prefix[i] <= 'Z')){
            string op(1, prefix[i]);
            s.push(op);
        }

        else{
            string op1=s.top();
            s.pop();
            string op2=s.top();
            s.pop();
            string exp=op1+op2+prefix[i];
            s.push(exp);
        }
    }
    return s.top();
}

int main(){
    system("cls");

    string prefix, postfix;

    cout<<"Enter the prefix string: \n";
    cin>>prefix;

    postfix= PrefixToPostfix(prefix);
    cout<<"The converted string is: \n"<<postfix;
    return 0;
}