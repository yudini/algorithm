#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int cow[11]={-1,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,num,x;
    int count=0;
    cin>>n;
    memset(cow,-1,sizeof(cow));
    for(int i=0;i<n;i++){
        cin>>num>>x;
        if(cow[num]==-1){
            cow[num]=x;
        }else if(cow[num]!=x){
            cow[num]=x;
            count++;
        }
        
    }
    cout<<count;
}