#include<iostream>
#include<stack>
using namespace std;

string PrefixToInfix(string prefix){
    stack<string> s;

    for(int i=prefix.length()-1;i>=0;i--){

        if((prefix[i] >= 'a' && prefix[i] <= 'z') || (prefix[i] >= 'A' && prefix[i] <= 'Z')){
            string op(1, prefix[i]);
            s.push(op);
        }

        else{
            string op1, op2;
            op1=s.top();
            s.pop();

            op2=s.top();
            s.pop();

            string exp='('+ op1 + prefix[i] + op2 + ')';
            s.push(exp);
        }
    }
    return s.top();
}

int main(){
    system("cls");

    string infix, prefix;

    cout<<"Enter a Postfix Expression: \n";
    cin>>prefix;

    infix= PrefixToInfix(prefix);

    cout<<"\nInfix Expression: "<<infix;
    return 0;
}