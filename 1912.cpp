#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    int array[100001];
    int d[100001];
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>array[i];
    }
    int result=-1000;
    d[0]=array[0];
    for(int i=1;i<N;i++){
        d[i]=max(d[i-1]+array[i],array[i]);
        result=max(result,d[i]);
    }
    result=max(result,d[0]);

    cout<<result;

    return 0;
     
}