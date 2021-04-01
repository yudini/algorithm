#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int array[1000000];
    int N,M,high=0;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>array[i];
        high=max(high,array[i]);
    }

    int mid=high/2, low=0; 
    long long result=0;
    while(low<=high){
        long long sum=0;
        for(int i=0;i<N;i++){
            if(array[i]>mid)
                sum+=array[i]-mid;
        }
        if(sum>=M){
            if(result<mid)
                result = mid;
            low=mid+1;
            mid=(low+high)/2;

        }
        else{
            high=mid-1;
            mid=(low+high)/2;
        }
    }
    cout<<result;
}