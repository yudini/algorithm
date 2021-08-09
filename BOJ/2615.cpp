#include <iostream>

using namespace std;

int board[19][19];

void checkRow(){
    for(int i=0;i<19;i++){
        for(int j=0;j<=15;j++){
            if(board[i][j]==1){
                
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0;i<19;i++){
        for(int j=0;j<19;j++){
            cin>>board[i][j];
        }
    }

}
