#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    int N,count=0;
    int max=0;
    long long k;
    long long arr[100000];
    cin>>N;       
    for(int i=0;i<N;i++)
        cin>>arr[i]; 
    sort(arr,arr+N);

    k=arr[0];    
    for(int i=1;i<N;i++){
        if(arr[i-1]==arr[i]){
            count++;
        }
        else{
            count=0;
        }

        if(count>max){
            max=count;
            k=arr[i];
        }

    }
    cout<<k;  
}