#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    int card[10001];
    int DP[10001];

    cin>>N;
    for(int i=1;i<=N;i++)
        cin>>card[i];
    
    DP[0]=0;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++){
            DP[i]=max(DP[i],card[j]+DP[i-j]);
        }
    }

    /*
    DP[1]=card[1]
    DP[2]=card[1]+card[1]
          card[2]
    DP[3]=card[1]+ 'card[1]+card[1]'
          card[1]+ 'card[2]'
          card[3]
    DP[4]=card[1]+'card[1]+card[1]+card[1]'
          card[1]+'card[1]+card[2]'
          card[1]+'card[3]'
          card[4]
          ->card[2]+card[2]

    DP[i]=card[1]+DP[i-1]
          card[i]

    for(int i=2;i<=N;i++){
        DP[i]=max(DP[i-1]+card[1],card[i]);           //DP[i-1]+DP[1] ->card[2]+card[2]
    }
    --------------------------------------------------
    card[2]를 무조건 사야할 때 나머지 최대로 
    DP[1]- x
    DP[2]= card[2]  
    DP[3]= card[2]+card[1]
    DP[4]= card[2]+card[1]+card[1]
           card[2]+card[2]
    
    DP[i]=card[2]+DP[i-2]
          dp[i]
    */

    cout<<DP[N];

    
}