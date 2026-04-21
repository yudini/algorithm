#include <iostream>
#include <vector>

using namespace std;


/*
방은 N x M , 각 칸은 빈칸 또는 벽 (r,c)

1. 현재 칸 아직 청소 X -> 청소
2. 현재 칸의 주변 4칸(동서남북) 청소되지않은 빈칸이 없는경우
    - 바라보는 방향 유지한채로 한칸 후진 가능하면 후진하고 1번으로
    - 바라보는 방향의 뒤쪽칸이 벽이라 후진 불가능 -> 작동 멈춤
3. 현재칸 주변 4칸중 청소되지않은 빈칸 있는경우
    - 반시계방향으로 90도 회전
    - 바라보는 방향을 기준으로 앞쪽칸 청소 x면 한칸 전진
    - 1번으로 돌아감
 
 0은 빈칸, 1은 벽
*/

int N, M;
vector <int> room[51];
int visited[51][51];
// 0이면 x-1, y / 1이면 x, y+1/ 2이면 x+1, y /3이면 x, y-1
int dx[] = {-1, 0 ,1, 0};
int dy[] = {0, 1, 0 ,-1};
int answer =0;

void dfs(int x, int y, int d){
    int nd =d;
    // 0-> 3, 3->2 , 2->1, 1->0
    for(int i=0;i<4;i++){
        nd = (nd+3) % 4;
        int nx = x+ dx[nd];
        int ny = y+ dy[nd];

        if(nx<0 ||ny<0 || nx>=N ||ny>=M || room[nx][ny]==1 || visited[nx][ny]==1){
            continue;
        }
        else{
            answer++;
            visited[nx][ny]=1;
            //cout<<nx<<ny<<endl;
            dfs(nx,ny,nd);
        }

    }

    int nx = x-dx[d];
    int ny = y-dy[d];

    if(nx<0 || nx>= N || ny<0 || ny>=M || room[nx][ny] ==1){
        cout<<answer;
        exit(0);
    }
    else{
        //cout<<nx<<ny<<endl;
        dfs(nx,ny,d);
    }

}


int main(){
    int r, c, d;

    cin>>N>>M;
    cin>>r>>c>>d;  //d = 방향 (북,동,남,서 -> 0,1,2,3)
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int x;
            cin>>x;
            room[i].push_back(x);
        }
    }

    visited[r][c]=1;
    answer++;
    dfs(r,c,d);


    return 0;
}