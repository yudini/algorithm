#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){
    int N,K,num;
    vector<int>arr;
    scanf("%d %d",&N,&K);

    for(int i=0;i<N;i++){
        scanf("%d",&num);
        arr.push_back(num);
    }
    sort(arr.begin(),arr.end());

    printf("%d",arr[K-1]);

    return 0;

}