#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> v;
    int answer = 0;
    while(n){
        v.push_back(n%3);   //11122
        n/=3;
    }
    int k=1;
    for(int i=v.size()-1;i>=0;i--){
        answer+=v[i]*k;
        k*=3;
    }

    return answer;
}

int main(){
    int a=solution(229);
    printf("%d",a);
}