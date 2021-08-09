#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int h,w;
    cin>>h>>w;
    bool a[h][w];
    int k;

    for(int i=0;i<w;i++){
        cin>>k;
        for(int j=0;j<k;j++){
            a[h-j-1][i]=true;
        }
    }

    for(int i=0;i<h;i++){
        int temp=0;
        for(int j=1;j<w;j++){
            if(a[i][j]==1 && a[i][j-1]==1){
                temp=0;
            }else if(a[i][j]==0 &&a[i][j-1]){
                
            }
        }
    }
}