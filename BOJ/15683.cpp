#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
1은 한쪽 방향
2는 양쪽
3은 직각
4는 ㅏ,ㅓ,ㅗ,ㅜ
5는 상하좌우
회전가능
*/

int map[9][9];
vector <pair<int,int>> pos;

int N, M;
int answer = 999999999;
//90도 회전, 북 동 남 서 기준
int dx[]={-1, 0, 1, 0};
int dy[]={0, 1, 0, -1};

void check(int x, int y, int dir, int arr[9][9]){

    dir = dir%4;

    while(1){
        int nx = x +dx[dir];
        int ny = y + dy[dir];

        x =nx;
        y =ny;

        if(nx<0 || ny<0 || nx>=N || ny>=M) return;

        if(arr[nx][ny]==6) return;

        if(arr[nx][ny]!=0) continue;

        //cout<<"dd"<<endl;

        arr[nx][ny]=-1;
    }
}



void dfs(int idx, int arr[9][9]){

    if(idx == pos.size()){
        int cnt= 0 ;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(!arr[i][j]){
                    cnt++;
                }
            }
        }

        answer = min(cnt, answer);
        return;
    }

    int x = pos[idx].first;
    int y = pos[idx].second;

    int cctv_num = map[x][y];

    for(int i=0;i<4;i++){
        int tmp[9][9];

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                tmp[i][j] = arr[i][j];
            }
        }


        if(cctv_num == 1){
            check(x,y,i,tmp);
        }else if(cctv_num == 2){
            check(x,y,i,tmp); //0,1,2,3 
            check(x,y,i+2,tmp); //2,3,4,5-> 2,3,0,1
        }else if(cctv_num == 3){
            check(x,y,i,tmp);  //0,1,2,3 
            check(x,y,i+1,tmp); //1,2,3,4 -> 1,2,3,0
        }else if(cctv_num == 4){
            check(x,y,i,tmp);  //0,1,2,3
            check(x,y,i+1,tmp); //1,2,3,4 
            check(x,y,i+2,tmp); //2,3,4,5
        }else if(cctv_num == 5){
            check(x,y,i,tmp);
            check(x,y,i+1,tmp);
            check(x,y,i+2,tmp);
            check(x,y,i+3,tmp);
        }

        dfs(idx+1,tmp);

    }
}

int main(){
    cin>>N>>M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
            if(map[i][j]!=0 && map[i][j]!=6){
                pos.push_back(make_pair(i,j));
            }
        }
    }

    dfs(0,map);

    cout<<answer<<endl;
    return 0;
}