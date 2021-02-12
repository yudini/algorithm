#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

vector <int>graph[1001];
int visited[1001];

void dfs(int x){
    visited[x]=1;
    for(int i=0;i<graph[x].size();i++){
        int s=graph[x][i];
        if(!visited[s]){
            dfs(s);
        }
    }
}

int main(){
    int t,n,x;
    cin>>t;
    while(t--){
        int count=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            visited[i]=0;
            cin>>x;
            graph[i].push_back(x);
        }

        for(int i=1;i<=n;i++){
            if(!visited[i]){
                dfs(i);
                count++;
            }
        }
        cout<<count<<"\n";

        for(int i=1;i<=n;i++){
            graph[i].clear();
        }
    }
}