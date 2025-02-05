#include <iostream>
#include <vector>
#include<map>
#include <algorithm>

다시 
using namespace std;

typedef struct{
    string name;
    int start;
    int end;
}reserve_room;


int n, m;
vector<string>room;
map <string,pair<int,int>> meeting;
reserve_room reserve;
l
int main(){


    cin>>n>>m;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        room.push_back(s);
    }
    for(int i=0;i<m;i++){
        string s;
        int start,end;
        cin>>s>>start>>end;
        reserve.name = s;

        meeting.insert({s,make_pair(start,end)});
    }

    sort(room.begin(),room.end());



}