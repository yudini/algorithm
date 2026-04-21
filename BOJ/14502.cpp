#include <iostream>
#include <vector>

using namespace std;

/*
0은 빈칸, 1은 벽, 2는 바이러스
바이러스는 상화좌우 인접한 빈칸으로 퍼져나갈수있음
3개의 벽을 세워야함
세운 뒤 안전영역 크기의 최대값 구함
*/

int n,m;

int map[9][9];
int map2[9][9];
int result_map[9][9];
int result=0;

vector <pair<int,int>> virus_pos;


void mapCopy(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            map2[i][j] = map[i][j];
        }
    }
}

void Coppy(int map[9][9]){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            result_map[i][j] = map[i][j];
        }
    }
}

void Virus(int x, int y){
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    for(int j=0;j<4;j++){
        int nx = x + dx[j];
        int ny = y + dy[j];
        
        if(nx<0 || nx>=8 || ny<0 || ny>=8)
            continue;

        if(map2[nx][ny] == 0){
            map2[nx][ny] = 2;
            Virus(nx,ny);
        }
        
    }

}

void Wall(int start_x,int start_y, int count){
    if(count == 3){
        int safe =0;
        mapCopy();
        for(int i=0;i<virus_pos.size();i++){
            int x = virus_pos[i].first;
            int y = virus_pos[i].second;

            Virus(x,y);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map2[i][j]==0){
                    safe++;
                }
            }
        }
        if(result < safe){
            result = safe;
            Coppy(map2);
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout<<result_map[i][j];
                }
                cout<<"\n";
            }
            cout<<"\n";
        }
    }else{
        for(int i=start_x;i<n;i++, start_y=0){
            for(int j=start_y;j<m;j++){
                if(map[i][j]==0){
                    map[i][j]=1;
                    Wall(i,j, count+1);
                    map[i][j]=0;
                }
            }
        }
    }
}



int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
            if(map[i][j]==2){
                virus_pos.push_back(make_pair(i,j));
            }
        }
    }

    Wall(0,0,0);

    cout<<result;
}