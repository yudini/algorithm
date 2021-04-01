#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int coin[101];
    int dp[101];
    int N,K,result=0;
    cin>>N>>K;
    for(int i=0;i<N;i++)
        cin>>coin[i];

    for (int i = 0; i < N; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (coin[i] > coin[j]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    result=max(result,dp[i]);
                }
            }
        } 
    }

    cout<<result;

}