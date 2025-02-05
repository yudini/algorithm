#include <iostream>
//#include <string.h>
#include <string>
#include <vector>

using namespace std;


int n;

int main(){
    vector <string> s;
    vector <string> t;
    
    vector <char> p;

    cin>>n;
    for (int i=0;i<n;i++){
        string a,b;
        cin>>a>>b;
        s.push_back(a);
        t.push_back(b);
        //cout<<s[i]<<t[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<s[i].length();j++){
            if(s[i][j] == 'x' || s[i][j] == 'X' ){
                //cout<<i;
                if(t[i][j]>96){
                    p.push_back(t[i][j]-32);
                }
                else{
                    p.push_back(t[i][j]);
                }
            }
        }
    }

    for(int i=0;i<p.size();i++){
        cout<<p[i];
    }
    cout<<"\n";
}