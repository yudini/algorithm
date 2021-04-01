#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stack>

using namespace std;

//런타임에러
vector<int> graph[100000];
int visited[100000];
vector <int> check;
stack<int>s;
int answer=0;


void dfs(int start){
    s.push(start);
    visited[start]=1;

    while(!s.empty()){
        int x=s.top();
        s.pop();
        printf("%d \n",start);

        for(int i=0;i<graph[x].size();i++){
            int y=graph[x][i];
            check.push_back(y);
            if(!visited[y]){
                visited[y]=1;
                s.push(y);
                break;
            }else{
                int a = find(check.begin(),check.end(),y)-check.begin();
                int b=check.end()-check.begin();
                answer+=b-a-1;
            }
        }
    }
}


int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(visited,0,sizeof(visited));
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int a,b;
            scanf("%d",&a);
            graph[i].push_back(a);
            printf("%d",a);
        }

        for(int i=1;i<=n;i++){
            if(!visited[i]){
                check.push_back(i);
                dfs(i);
            }
        }
        printf("%d",answer);

        answer=0;
        memset(visited,0,sizeof(visited));
        check.clear();
        for(int i=0;i<graph[i].size();i++)  
            graph[i].clear();
    }
}