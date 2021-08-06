#include <iostream>

using namespace std;

int main(){
    int n,m,r,a,b,l;  //m수색범위
    int maxitem=0;
    int graph[101][101];
    int item[101];
    int INF=1000000;

    cin>>n>>m>>r;

    for(int i=1;i<=n;i++){  //그래프 초기화
        for(int j=1;j<=n;j++){
            if(i==j){
                graph[i][j]=0;
            }
            else{
                graph[i][j]=INF;
            }
        }
    }

    for(int i=1;i<=n;i++){  //아이템 수
        cin>>item[i];
    }

    for(int i=0;i<r;i++){
        cin>>a>>b>>l;
        graph[a][b]=l;
        graph[b][a]=l;
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(graph[i][k]+graph[k][j]<graph[i][j]){
                    graph[i][j]=graph[i][k]+graph[k][j];
                }
            }
        }
    }

    for(int i=1;i<=n;i++){
        int count=0;
        for(int j=1;j<=n;j++){
            if(graph[i][j]<=m){
                count+=item[j];
            }
        }
        if(maxitem<count){
            maxitem=count;
        }
    }

    cout<<maxitem;

}