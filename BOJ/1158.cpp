#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int n,k,temp;
    queue <int> q;
    vector <int> v;
    scanf("%d %d",&n,&k);

    for(int i=1;i<=n;i++)
        q.push(i);

    while(!q.empty()){
        for(int i=0;i<k-1;i++){
            temp=q.front();
            q.pop();
            q.push(temp);
        }
        v.push_back(q.front());
        q.pop();
    }

    printf("<");
    for(int i=0;i<v.size()-1;i++)
        printf("%d, ",v[i]);
    printf("%d",v[v.size()-1]);
    printf(">");
}