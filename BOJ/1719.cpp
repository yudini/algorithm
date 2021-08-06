#include <iostream>
#include <memory.h>

using namespace std;

int graph[201][201];
int INF=1000000;
int n;
int start[201][201];

void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(graph[i][k] + graph[k][j]<graph[i][j]){
                    graph[i][j]=graph[i][k]+graph[k][j];
                    start[i][j]=start[i][k];
                }
            }
        }
    }
}

int main(){
    int m,a,b,c;
    
    cin>>n>>m;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==j){
                graph[i][j]=0;
            }
            else{
                graph[i][j]=INF;
            }
        }
    }

    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        graph[a][b]=c;
        graph[b][a]=c;
        start[a][b]=b;    //a에서 b로가기위해 제일 먼저 이동해야하는 집하장
        start[b][a]=a;
    }

    floyd();

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                cout<<"-"<<" ";
            }
            else{
                cout<<start[i][j]<<" ";
            }
        }
        cout<<"\n";
    }

    return 0;
}