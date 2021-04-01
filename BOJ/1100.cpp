#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int board[8][8]={
        {0,1,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0}
    };

    char chess[8][8];
    int sum=0;

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin>>chess[i][j];
            if(chess[i][j]=='F'&&board[i][j]==0){
                sum++;
            }
        }
    }
    cout<<sum;


}
