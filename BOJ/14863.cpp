#include <iostream>
#include <vector>

using namespace std;

vector <pair<int,int>> walk;
vector <pair<int,int>> bicycle; 
//int walk[101];
//int bicycle[101];

// 서울제외   N개
//서울 -> 순서대로 도시 -> 경산
//서울 -> 2번도시 ..... 경산
//     1         2    n
//n은 구간수 
//도보 or 자전거

int main(){
    int n,k;
    int a,b,c,d;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c>>d;
        walk.push_back(make_pair(a,b));
        bicycle.push_back(make_pair(c,d));
    }
    
    for(int i=0;i<n;i++){
        if(walk[i].second<bicycle[i].second){
            
        }
    }
}