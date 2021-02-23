#include <iostream>

using namespace std;
int N;
int map[100][100];
int visited[100][100];

long long dfs(int x,int y){
    if(x==N-1&&y==N-1)
        return 1;        //visited[x][y];
    if(visited[x][y]!=-1)
        return visited[x][y];        //visited[x][y]++;
    visited[x][y]=0;

    int jump=map[x][y];
    int dx[2]={0,jump};
    int dy[2]={jump,0};
    for(int i=0;i<2;i++){
        int x2=x+dx[i];
        int y2=y+dy[i];
        if(x2>=0&&x2<N&&y2>=0&&y2<N){
            visited[x][y]+=dfs(x2,y2);
        }
    }
    return visited[x][y];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j];
            visited[i][j]=-1;
        }
    }
    long long result=dfs(0,0);
    cout<<result;
}