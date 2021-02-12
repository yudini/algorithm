#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>

using namespace std;
int graph[1001][1001];
int visited[1001][1001]={0,};// 메모리 초과
//vector <int> visited[1001] 런타임에러
//vector<vector<int>> 런타임에러 
queue <pair<int,int>>q;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int N,M;

void bfs(){

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int x2=x+dx[i];
            int y2=y+dy[i];
            if(x2>=0&& x2<N && y2>=0 && y2<M &&graph[x2][y2]==0 &&!visited[x2][y2]){
                q.push(make_pair(x2,y2));
                graph[x2][y2]=1;
                visited[x2][y2]=visited[x][y]+1;
            }
        }
    }
}


int main(){
    int count=0;
    scanf("%d %d",&M,&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d",&graph[i][j]);
            visited[i][j]=0;
            if(graph[i][j]==1){
                q.push(make_pair(i,j));
                visited[i][j]=1;
            }
        }
    }
    bfs();

    printf("%d",1);

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(visited[i][j]==0){
                printf("%d",-1);
                return 0;
            }
            if(count < visited[i][j]){
                count=visited[i][j];
            }
        }
    }
    printf("%d",count);

}