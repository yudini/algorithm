#include <iostream>
#include <vector>

using namespace std;
다시

int graph[4][4];
int vistited[4][4];
int n,m;
int result=0;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

vector<pair<int,int>> node;


void dfs(int x, int y,int cnt){
    if(node[cnt] == make_pair(x,y)){
        cnt++;
        if(cnt>=m){
            result++;
            return;
        }
    }
    vistited[x][y]=1;
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
        if(graph[nx][ny] ==0 && vistited[nx][ny] ==0 ){
            dfs(nx,ny,cnt);
        }
    }
    vistited[x][y]=0;
    return;


}

int main(){
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>> graph[i][j];
        }
    }
    
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        node.push_back(make_pair(x-1,y-1));
    }
    vistited[node[0].first][node[0].second]=1;
    dfs(node[0].first, node[0].second,1);

    cout<<result<<endl;

    return 0;
}