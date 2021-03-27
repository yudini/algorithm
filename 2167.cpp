#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,K;
    int I,J,X,Y;
    int array[301][301];

    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>array[i][j];
        }
    }
    cin>>K;
    for(int i=0;i<K;i++){
        int sum=0;
        cin>>I>>J>>X>>Y;
        for(int i=I;i<=X;i++){
            for(int j=J;j<=Y;j++){
                sum+=array[i][j];
            }
        }
        cout<<sum<<"\n";
    }


}