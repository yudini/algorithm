#include <iostream>
#include <algorithm>

using namespace std;

/*
NxM 종이 위에 숫자들. 
테트로미노 하나를 놓아서 놓인 칸에 쓰여있는 수 합 최대

확인해야될 것 : 테트로미노 모양, 합

N,M<=500 
테트로미노 5가지

다 확인 가능한가? 

500* 500 *5 = 1250000

*/

int N, M;
int paper[501][501];
int visited[501][501];
int answer = 0;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void dfs(int x, int y, int cnt, int sum){
    //cout<<cnt<<endl;
    if(cnt==4){
        answer = max(answer, sum);
        return;
    }

    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(visited[nx][ny] == 1 || nx<0 || ny<0 || nx>=N || ny>=M){
            continue;
        }
        
        visited[nx][ny]=1;
        sum+= paper[nx][ny];
        dfs(nx, ny, cnt+1, sum);
        sum-=paper[nx][ny];
        visited[nx][ny]=0;
        
    }

}

void others(int x, int y){
    /*
    ㅜ , ㅗ, ㅏ, ㅓ
    */ 

    //ㅜ
    if(y-1>=0 && y+1<M && x+1<N){
        int sum = paper[x][y-1] + paper[x][y] + paper[x][y+1] + paper[x+1][y];
        answer = max(sum, answer);
    }    
    // ㅗ
    if(y-1>=0 && y+1<M && x-1>=0){
        int sum = paper[x][y-1] + paper[x][y] + paper[x][y+1] + paper[x-1][y];
        answer = max(sum, answer);
    }
    // ㅏ
    if(x-1>=0 && x+1<N && y+1<M){
        int sum = paper[x-1][y] + paper[x][y] + paper[x+1][y] + paper[x][y+1];
        answer = max(sum, answer);
    }

    // ㅓ
    if(x-1>=0 && x+1<N && y-1>=0){
        int sum = paper[x-1][y] + paper[x][y] + paper[x+1][y] + paper[x][y-1];
        answer = max(sum, answer);
    }


}

int main(){
    
    cin>> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>paper[i][j];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int cnt =1;
            visited[i][j] = 1;
            int sum =paper[i][j];
            dfs(i,j,cnt, sum);
            visited[i][j]=0;
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            others(i,j);
        }
    }
    cout<<answer<<endl;
    return 0;
}