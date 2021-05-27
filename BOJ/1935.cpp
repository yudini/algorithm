//수정필요
#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string str;
    int a[26];
    stack <int> s;
    cin>>N;
    cin>>str;
    for(int i=0;i<N;i++)
        cin>>a[i];

    for(int i=0;i<str.length();i++){
        if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'){
            switch(str[i]){
            case '+':
            case '-':
            case '*':
            case '/':
            }
        }
        else{
            //s.push(a[i]);

        }
    }
}