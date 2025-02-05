#include <iostream>

using namespace std;

long long k, p, n;

int cal(long long count){
    if(count ==1)  
        return p;

    long long result = cal(count/2);

    result = (result*result) %1000000007;
    if(count%2==1){
        result = (result*p) %1000000007;
    }
    return result;
}

int main(){

    cin>>k>>p>>n;
    int answer = (cal(n*10)*k)%1000000007;;

    cout<<answer<<'\n';
    
    //cout<<new_n<<'\n';

}