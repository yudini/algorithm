#include <iostream>
#include <queue>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    int x=0;
    queue <int> q;
    cin>>N;


/*
q.pop();
q.push(q.front());
q.pop();
*/
    for(int i=1;i<=N;i++){
        q.push(i);
    }

    while(q.size()!=1){

        /*
        q.pop();
        q.push(q.front());
        q.pop();
        */
        if(x%2==0){
            q.pop();
        }
        else{
            int k= q.front();
            q.push(k);  
            q.pop();
        }
        x++;
    }

    cout<<q.front();
}