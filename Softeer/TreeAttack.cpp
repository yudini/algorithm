#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector> 
#include <queue>

using namespace std;

int main(){
    int n,m;
    int graph[101][101];
    int L[2]; 
    int R[2];
    int count =0;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>graph[i][j];
            if(graph[i][j]==1){
                count++;
            }
        }
    }
    for(int i=0;i<2;i++){
        cin>>L[i]>>R[i];
    }

    for(int i=0;i<2;i++){
        for(int j=L[i];j<=R[i];j++){
            for(int k=1;k<=m;k++){
                if(graph[j][k]==1){
                    graph[j][k]=0;
                    count --;
                    break;
                }
            }
        }
    }

    cout<<count<<'\n';

}   
