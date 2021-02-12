#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x; //sum=0;
    while(cin>>x){
        int n;
        int l[1000000];

        x=x*10000000;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>l[i];
        }
        sort(l,l+n);
        int start=0;
        int end=n-1;
        int sum=0;
        while(start<end){
            sum=l[start]+l[end];
            if(l[start]+l[end]==x){ 
                break;   
            }else if(l[start]+l[end]<x){
                start++;
            }else{
                end--;
            }
        }
        if(sum==x){ //l[start]+l[end]==x ->틀림.
            cout<<"yes "<<l[start]<<" "<< l[end]<<"\n";
        }else{
            cout<<"danger\n";
        }


     /* for(int i=0;i<n/2;i++){
            for(int j=n-1;j>n/2;j--){
                if(l[i]+l[j]==x){
                    if(abs(l[i]-l[j])>sum){
                        a=l[i];
                        b=l[j];
                        sum=abs(a-b);
                    }
                }
                else if(l[i]+l[j]<x){
                    break;
                }
            }
        }*/
    }
    return 0;
}