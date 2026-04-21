#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M;
int size=2;
int cnt =0;
int map[21][21];
queue <pair<int,int>>q;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

void bfs(){

    while(!q.empty()){
        int x= q.front().first;
        int y= q.front().second;
        

        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx<0 || ny<0 || nx>=N || ny>=N) continue;

            if(map[nx][ny]!=0){
                if(map[nx][ny] <size){
                    cnt++;
                    map[nx][ny]=0;
                    q=queue<pair<int,int>>();
                    q.push(make_pair(nx,ny));
                    break;
                }else if(map[nx][ny]==size){
                    q.push(make_pair(nx,ny));
                }
            }else{
                q.push(make_pair(nx,ny));
            }
        }

    }

}

int main(){
    int x, y;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j];
            if(map[i][j]==9){
                x =i;
                y =j;
            }
        }   
    }
    q.push(make_pair(x,y));
    bfs();
}