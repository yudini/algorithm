#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int n;

int S[21][21];

int visited[21];

int result = 9999999;

void dfs(int start, int count){

    if(count==n/2){
        int score1=0;
        int score2 =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visited[i] &&visited[j]){
                    score1 +=S[i][j];
                }else if(!visited[i] && !visited[j]){
                    score2 +=S[i][j];
                }
            }
        }

        // if(result > abs(score1-score2)){
        //     result = abs(score1-score2);
        //     for(int i=0;i<n;i++){
        //         if(visited[i]){}
        //             cout<<i;
        //     }
        //     cout<<"\n";
        // }


        result = min(result, abs(score1 - score2));

    }else{

        for(int i=start;i<n;i++){
            // visited[i]=1;
            // dfs(i+1,count+1);
            // visited[i]=0;
            if(visited[i]==0){
                visited[i] = 1;
                dfs(i,count+1);
                visited[i]=0;
            }
        }
    
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>S[i][j];
        }
    }
    

    dfs(0,0);
    cout<<result;
    


    return 0;
}