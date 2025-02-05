#include<iostream>
#include<string.h>

using namespace std;

int main(int argc, char** argv)
{
    
    string S;
    cin>>S;
    for(int i=0;i<S.length()-1;i++){
        cout<<S[i]<<endl;
        if(S[i]=='(' && S[i+1]==')')
            cout<<'1' ;
        if(S[i]==')'&& S[i+1]=='(')
            cout<<'+' ;
    }
    cout<<S[S.length()-1];
   return 0;
}