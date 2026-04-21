#include <string.h>
#include <vector>

using namespace std;

int n,w;

vector <int> gift;
int visited[5001];

long long sum=0;

string answer = "NO";

long long solution(int N) {
    long long answer = 0;
    return answer;
}

void Find(int start, int count){
    if(count ==3){
        if(sum ==w){
            answer = "Yes";
        }

    }else{
        for(int i=start;i<n;i++){
            visited[i]=1;
            sum+=gift[i];
            Find(start+1, count+1);
            visited[i]=0;
            sum-=gift[i];
        }
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        gift.push_back(x);
    }
    Find(0,0);

    cout<<answer;
    
}