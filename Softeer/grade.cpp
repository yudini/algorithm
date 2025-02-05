#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;

    vector<pair<int,int>> grade[4];
    vector<pair<int,int>> total;
    //vector<int>answer[100001];
   // int grade[3][100001];
    int answer[4][100001];
    int sum[100001]={0,};


    cin>>n;
    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            grade[i].push_back(make_pair(x,j));  //성적, 사람
            sum[j]+=x;
        }
    }
    
    for(int i=0;i<n;i++){
        grade[3].push_back({sum[i],i});
    }

    // for(int i=0;i<3;i++){
    //     cout<<total[i].first<<' ';
    // }
    // cout<<'\n';
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<n;j++){
    //         cout<< grade[i][j].first<<' ';
    //     }
    //     cout<<'\n';
    // }

    for(int i=0;i<4;i++){
        sort(grade[i].begin(),grade[i].end(),greater<>());
        int rank=1;
        int temp=1;
        answer[i][grade[i][0].second] = rank;
        for(int j=1;j<n;j++){
            if(grade[i][j].first == grade[i][j-1].first){
                answer[i][grade[i][j].second] = rank;
                temp++; 
            }else{
                rank+=temp;
                temp =1;  //temp 원래대로
                answer[i][grade[i][j].second] = rank;
            }
        }
    }

    // answer[3][total[0].second] = 0;
    // for(int j=1;j<n;j++){
    //     if(total[j].first == total[j-1].first){
    //         answer[3][total[j].second] = j-1;
    //         j++;
    //     }else{
    //         answer[3][total[j].second] = j;
    //     }
    // }

    for(int i=0;i<4;i++){
        for(int j=0;j<n;j++){
            cout<<answer[i][j]<<' ';
        }
        cout<<'\n';
    }

}
