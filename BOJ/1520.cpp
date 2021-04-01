#include <iostream>
#include <stack>


using namespace std;

int N,M;

int map[500][500];
int visited[500][500];   //{0,}
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int dfs(int x,int y){
    if(x==M-1&&y==N-1)
        return 1;        //visited[x][y];
    if(visited[x][y]!=-1)
        return visited[x][y];        //visited[x][y]++;
    visited[x][y]=0;
    for(int i=0;i<4;i++){
        int x2=x+dx[i];
        int y2=y+dy[i];
        if(x2>=0&&x2<M&&y2>=0&&y2<N){
            if(map[x2][y2]<map[x][y]){
                visited[x][y]+=dfs(x2,y2);    //dfs(x2,y2);
            }
        }
    }
    return visited[x][y];

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>M>>N;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j];
            visited[i][j]=-1;
        }
    }
    int result = dfs(0,0);
    cout<<result;

}