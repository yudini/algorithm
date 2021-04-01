#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

vector <int> graph[20001];
int visited[20001]={0,};

void dfs(int x){
    if(!visited[x])
        visited[x]=1;

    for(int i=0;i<graph[x].size();i++){
        int s=graph[x][i];
        if(!visited[s]){
            if(visited[x]==1){
                visited[s]=2;
            }else if(visited[x]==2){
                visited[s]=1;
            }
            dfs(s);
        }
    }
}

bool check(int v){
    for(int i=1;i<=v;i++){
        for(int j=0;j<graph[i].size();j++){
            int s=graph[i][j];
            if(visited[i]==visited[s]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int k,v,e,i=0;
    cin>>k;
    while(k--){
        cin>>v>>e;
        for(int i=1;i<=e;i++){
            int a,b;
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i=1;i<=v;i++){
            if(!visited[i]){
                dfs(i);
            }
        }
        if(check(v)){
            cout<<"YES \n";
        }else{
            cout<<"NO \n";
        }
        for(int i=1;i<=v;i++){
            graph[i].clear();
            visited[i]=0;
        }
    }
}