#include <iostream>
#include <stdio.h>
#include <vector>

vector <int> a[50];

int a[50][50];
int visited[50][50];

using namespace std;

void dfs(int x,int y){
    visited[x][y]=1;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(visited[x+i][y+j]==0&&a[x+i][y+j]==1){
                dfs(x+i,y+j);
            }
        }
    }
}


int main()
{
    int w,h;
    while(1){
        int count=0;
        cin>>w>>h;
        if(w==0||h==0)
            break;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>a[i][j];
                visited[i][j]=0;
            }
        }

        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(visited[i][j]==0 &&a[i][j]==1){
                    dfs(i,j);
                    count++;
                }
            }
        }
        cout<<count;
    }

    return 0;
}


