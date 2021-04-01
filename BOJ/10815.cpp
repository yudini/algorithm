#include <iostream>
#include <algorithm>

using namespace std;
int N,M;
int card[500000];
int number[500000];
int result[500000]={0,};

void search(){
    for(int i=0;i<M;i++){
        int low=0, high=N;
        while(low<=high){
            int mid=(low+high)/2;
            if(card[mid]==number[i]){
                result[i]=1;
                break;
            }
            else if(number[i]<card[mid]){
                high=mid-1;
            }else{
                low=mid+1;
            }

        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>card[i];  //가지고 있는 카드
    }
    cin>>M;
    for(int i=0;i<M;i++){
        cin>>number[i];
    }
    sort(card,card+N);
    search();
    for(int i=0;i<M;i++){
        cout<<result[i]<<" ";
    }


}
