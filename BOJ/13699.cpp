#include <iostream>

using namespace std;

long long t[36];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    t[0]=1;
    //t[n]=t[0]*t[n-1]+t[1]*t[n-2]+...t[n-1]*t[0];

    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            t[i]+=t[j]*t[i-j-1]; 
        }
    }

    cout<<t[n];

}