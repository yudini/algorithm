#include <iostream>
#include <vector>

using namespace std;


int n;
int stone[30001];
int dp[30001];
int answer =1;
//vector<int> stone;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>stone[i];
        dp[i]=1;
    }
    
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(stone[i] < stone[j]){
                dp[j] = max(dp[j],dp[i]+1);
                answer = max(answer, dp[j]);
            }
        }
    }
    
    // for(int i=0;i<n;i++){
    //     cout<<dp[i];
    // }
    cout<< '\n'<<answer<<'\n';


}