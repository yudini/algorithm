#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
    int n;
    int answer=0;
    vector<pair<int,int>> classes;
    int dp[1000001];
    cin>>n;
    for(int i=0;i<n;i++){
        int s,f;
        cin>>s>>f;
        classes.push_back(make_pair(f,s));
    }

    sort(classes.begin(), classes.end());
    int time = 0;

    int cur = classes[0].first;
    int cnt = 1;

    for(int i=1;i<n;i++){
        if(cur<=classes[i].second){
            cur = classes[i].first;
            cnt++;
        }
    }

    cout<<cnt<<'\n';
    
}