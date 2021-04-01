#include <iostream>
#include <vector>

using namespace std;
vector <int> sequence;
int N;
int array[1000000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int length=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>array[i];
    }

    sequence.push_back(array[0]);
    int low,high;
    for(int i=1;i<N;i++){
        if(sequence.back()<array[i]){
            sequence.push_back(array[i]);
        }
        else{
            low=0;
            high=sequence.size();
            while(low<high){
                int mid=(low+high)/2;
                if(sequence[mid]>=array[i]){
                    high=mid;
                }else{
                    low=mid+1;
                }    
            }
            sequence[high]=array[i];
        }
    }
    cout<<sequence.size();
}