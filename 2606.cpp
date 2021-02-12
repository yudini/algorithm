#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> v[100];
bool visited[100];
int count=0;

void dfs(int x){
    visited[x]=true;
    for(int i=0;i< v[x].size();i++){
        int y=v[x][i];
        if(visited[y]==false){
            dfs(y);
            count++;
        }
    }

    return;

}

int main(){
    int n,e,a,b;
    cin>>n;
    cin>>e;

    for(int i=0;i<e;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    cout << count;
}