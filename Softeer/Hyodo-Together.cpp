#include <iostream>
#include <vector>
#include <algorithm>

다시

using namespace std;

int m,n;

int graph[21][21];
int visited[21][21];
int permu_visited[4];
int sum =0;
int temp_total=0;
int temp_result=0;
int answer =0;

vector <pair<int,int>> start_pos;
vector<pair<int,int>>temp_path;
vector<pair<int,int>> path;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
// int cnt =0;

int dfs(int x,int y,int cnt){
    if(cnt == 3){
        int sum =0;
        for(int i=0;i<4;i++){
            sum+=graph[temp_path[i].first][temp_path[i].second];
        }

        if(temp_total<sum){
            temp_total = sum;
            for(int i=0;i<4;i++){
                cout<<temp_path[i].first<<temp_path[i].second<<' ';
            }
            cout<<temp_total<<'\n';
            path = temp_path;
        }

        //visited[x][y][rank] =1;
        return;
    }

    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx>=n || nx <0 || ny >=n || ny<0 || visited[nx][ny] ==1)
            continue;
        
        visited[nx][ny] =1;
        temp_path.push_back(make_pair(nx,ny));
        int total_fruit = dfs(nx,ny,cnt+1);
        visited[nx][ny]=0;
        temp_path.pop_back();
        
    }
}


int num[3];
void permutation(int depth){
    if(depth == m){
        temp_result=0;
        for(int i=0;i<m;i++){
            temp_total=0;
            int start_x = start_pos[num[i]].first;
            int start_y = start_pos[num[i]].second;

            visited[start_x][start_y]=1;
            temp_path.push_back(make_pair(start_x,start_y));
            dfs(start_x,start_y,0);
            for(int i=0;i<4;i++){
                visited[path[i].first][path[i].second]=1;
            }
            temp_result += temp_total;
            temp_path.clear();
        }

        if(answer<temp_result){
            answer = temp_result;
        }

    }

    for(int i=0;i<m;i++){
        if(permu_visited[i]!=1){
            permu_visited[i] =1;
            num[depth]=i;
            permutation(depth+1);
            permu_visited[i]=0;
        }
    }


}

int main(){
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }

    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        start_pos.push_back(make_pair(x-1,y-1));
    }
    permutation(0);

    cout<<answer<<'\n';

}