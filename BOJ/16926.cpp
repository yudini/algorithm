#include <iostream>
#include <math.h>

using namespace std;

int a[300][300];

void rotation(){

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,r;
    cin>>n>>m>>r;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int k=min(n,m)/2;
    
    int x1,x2,y1,y2;

    while(r--){
        while(k--){
            for(int i=x1;i<n;i++){
                int temp=a[i][1];
                a[i+1][1]=a[i][1];
            }
        }
    }
}