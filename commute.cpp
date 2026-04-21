#include <iostream>
#include <vector>

using namespace std;

int n,m,s,t;

vector<int>v1[100001];
vector<int>v2[100001];

//Again

/* 
집에서 회사가는길 정점 수 
모든 경로 탐색? 
역방향 그래프 이용
*/

int visit_go1[100001];
int visit_back1[100001];
int visit_go2[100001];
int visit_back2[100001];


void dfs(int x,int end,vector<int>v[],int visited[]){
    if(visited[x] ==1){
        return;
    }

    visited[x] =1;

    for(int i=0;i<v[x].size();i++){
        dfs(v[x][i],end,v,visited); 
    }
}

int main(){
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        v1[x].push_back(y);
        v2[y].push_back(x);
    }

    cin>>s>>t;

    visit_go1[t]=1;    //1
    visit_back1[s]=1;  //2

    dfs(s,t,v1,visit_go1);  //출근 순방향
    dfs(t,s,v1,visit_back1);  //퇴근 순방향

    dfs(s,t,v2,visit_go2); //출근 역방향
    dfs(t,s,v2,visit_back2); //퇴근 역방향

    int sum=0;
    for(int i=0;i<=n;i++){
        if(visit_go1[i] && visit_go2[i] && visit_back1[i] && visit_back2[i])
            sum++;
    }
    cout<<sum-2<<'\n';  //출발, 도착 지점 제외
} 