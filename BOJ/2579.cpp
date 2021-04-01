#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int stairs[301];
    int dp[301];

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>stairs[i];

    
    dp[0]=0; //점화식 쓰기 편리.    
    dp[1]=stairs[1];
    dp[2]=stairs[1]+stairs[2];
    
    for(int i=3;i<=n;i++){
        dp[i]=max(stairs[i-1]+dp[i-3],dp[i-2])+stairs[i];
    }

    cout<<dp[n];

}