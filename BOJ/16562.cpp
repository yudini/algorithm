#include <iostream>
#include <vector>
#include <stack>
#include <math.h>

using namespace std;
int result;

int a[10001];
vector <int> f[10001];
int visited[10001];

void dfs(int start){
    stack<int> s;
    int cost=a[start];
    s.push(start);
    visited[start]=true;
    while(!s.empty()){
        int x=s.top();
        s.pop();
        for(int i=0;i<f[x].size();i++){
            int y=f[x][i];
            if(!visited[y]){
                visited[y]=true;
                cost=min(a[y],cost);
                s.push(x);
                s.push(y);
                break;
            }
        }
    }
    result+=cost;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,m,k,v,w;

    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>v>>w;
        f[v].push_back(w);
        f[w].push_back(v); 
    }

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    if(result<=k){
        cout<<result;
    }else{
        cout<<"Oh no";
    }
}