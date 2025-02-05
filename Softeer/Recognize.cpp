#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
char graph[25][25];
int visited[25][25];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};


vector<int>c;
queue<pair<int,int>>q;

int total=0;


void bfs(int start_x, int start_y){
    int cnt=0;
    q.push(make_pair(start_x,start_y));

    while(!q.empty()){
        cnt++;
        int x = q.front().first;
        int y = q.front().second;
        //cout<<x<<y<<'\n';
       // cout<<"hehe"<<'\n';
        q.pop();

        for(int k=0;k<4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx<0 || nx >=n || ny<0 || ny>=n || visited[nx][ny]== 1 || graph[nx][ny]=='0')
                continue;
            
            //cout<<"dx"<<'\n';
            visited[nx][ny]=1;
            q.push(make_pair(nx,ny));
        }
    }
    //cout<<cnt<<'\n';
    c.push_back(cnt);
}


int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j] == '1' && visited[i][j]==0){
                //cout<<"hi"<<"\n";
                visited[i][j]=1;
                bfs(i,j);
            }
        }
    }
    sort(c.begin(),c.end());
    cout<<c.size()<<"\n";
    for(int i=0;i<c.size();i++){
        cout<<c[i]<<'\n';
    }

    

}