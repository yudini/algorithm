#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long l[10001];
    long long K,N;
    long long high=0;
    cin>>K>>N;
    for(int i=0;i<K;i++){
        cin>>l[i];
        high=max(l[i],high);
    }
    long long low=1;
    int result =0;
    while(low<=high){
        int sum=0;
        long long mid=(high+low)/2; 
        for(int i=0;i<K;i++){
            sum+=l[i]/mid;
        }

        if(sum>=N){
            if(result<mid)
                result = mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<result;

}