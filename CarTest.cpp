#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// !! DONE !! 

/*
연비가 높을수록 연료 소비 적고 더 많은 거리 주행

n대 자동차 중 q개의 질의에 대해 3대 자동차를 골라
중앙값 mi 값이 나오는 서로다른 경우의 수
*/

int n,q;

vector<int> car;
vector<int> m;

int BinarySearch(int start, int end, int m){

    if(start>end) return -1;

    int pos = (start+end)/2;
    if(car[pos] == m){
        return pos;
    }else if(car[pos]>m){
        return BinarySearch(start,pos-1,m);
    }else{
        return BinarySearch(pos+1,end,m);
    }
}


int main(){
    cin>>n>>q;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        car.push_back(x);
    }

    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        m.push_back(x);
    }

    sort(car.begin(),car.end());

    for(int i=0;i<q;i++){
        int pos = BinarySearch(0,n,m[i]);

        if(pos<0 || pos>n-1){
            cout<<0<<'\n';
        }else{
            cout<<pos* (n-1-pos)<<'\n';
        }

    }

}