#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef struct Jewel{
    int M;
    int V;
}Jewel;

int N,K;
priority_queue<int>pq;

bool compare(const Jewel &a,const Jewel &b){
        return a.M<b.M;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>K;
    Jewel jewel[N];
    int C[K];
    for(int i=0;i<N;i++){
        cin>>jewel[i].M>>jewel[i].V;
    }
    for(int i=0;i<K;i++){
        cin>>C[i];
    }
    sort(C,C+K);
    sort(jewel,jewel+N,compare);
    int j=0;
    long long sum=0;
    for(int i=0;i<K;i++){
        while(j<N&&jewel[j].M <= C[i]){
            pq.push(jewel[j].V);
            j++;
        }
        if(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
    }
    cout<<sum;
    return 0;
}


/*
bool compare(const Jewel &a,const Jewel &b){
        return a.V>b.V;
}

int push(Jewel jewel[],vector<long long>C){
    int sum=0,x=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<C.size();j++){
            if(jewel[i].M<=C.at(j)){
                sum+=jewel[i].V;
                C.erase(C.begin());
                break;
            }
        }
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector <long long> C; 
    cin>>N>>K;
    Jewel jewel[N];
    for(int i=0;i<N;i++){
        cin>>jewel[i].M>>jewel[i].V;
    }
    for(int i=0;i<K;i++){
        int a;
        cin>>a;
        C.push_back(a);
    }

    sort(jewel,jewel+N,compare);
    sort(C.begin(),C.end());

    cout<<push(jewel,C);

}*/