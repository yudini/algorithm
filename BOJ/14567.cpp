#include <iostream>
#include <vector>
#include <memory.h>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;

vector <int> graph[1001];
int dp[1001];
int check[1001];
queue<int>q;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,m,a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        check[b]++;
    }

    for(int i=1;i<=n;i++){
        if(check[i]==0){
            q.push(i);
        }
        dp[i]=1;
    }
    
    while(!q.empty()){
        int x=q.front();
        q.pop();

        for(int i=0;i<graph[x].size();i++){
            int y=graph[x][i];
            check[y]--;
            if(check[y]==0){
                q.push(y);
                dp[y]=max(dp[y],dp[x]+1);
            }
        }
    }

    
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<" ";
    }

    return 0;

}