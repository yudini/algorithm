#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

// 이분탐색
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,k,m,x,mid;
    int p=-1;
    int end=0,count=0;
    int start=1;
    vector <int> L;
    cin>>n>>k>>m;
    for(int i=0;i<n;i++){
        cin>>x;
        if(k<x&&x<2*k){
            L.push_back(x-k);
            end=max(end,x-k);
        }
        if(x>2*k){
            L.push_back(x-2*k);
            end=max(end,x-2*k);
        }
    }

    while(start<=end){
        mid=(start+end)/2;
        count=0;
        for(int i=0;i<L.size();i++){
            count+=L[i]/mid;
        }
        if(count<m){
            end=mid-1;
        }else{
            p=mid;
            start=mid+1;
        }
    }

    cout<<p<<"\n";
    
    return 0;

}