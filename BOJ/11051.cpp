#include <iostream>

using namespace std;

int dp[1001][1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin>>n>>k;

    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(j==0||j==i)
                dp[i][j]=1;
            else
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%10007;
        }
    }

    cout<<dp[n][k];

    
}