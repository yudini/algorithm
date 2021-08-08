#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    int G[100][100];
   // int d[100][100];

    cin>>n; //정점의 개수

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>G[i][j];    //인접행렬
        }    
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){   //출발
            for(int j=0;j<n;j++){   //도착
                if(G[i][k] && G[k][j]){
                    G[i][j]=1;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<G[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}