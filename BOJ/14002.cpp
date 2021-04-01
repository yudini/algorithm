#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    int N,array[1001];
    int dp[1001];
    int index[1001]={0,};
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>array[i];
    }   

    for (int i = 0; i < N; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (array[i] > array[j]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    index[i]=j;    //자신보다 작은값을 가지는 요소들 중 바로 전 인덱스 
                }
            }
        }
    }
    int max = dp[0];
	int end = 0;
	for (int i = 1; i < N; i++) {
		if (max < dp[i]) {
			max = dp[i];
			end = i;
		}
	}

    cout<<max<<"\n";

    int result[1001];
    for(int i=0;i<max;i++){
        result[i]=array[end];
        end=index[end];
    }

    for(int i=1;i<=max;i++)
        cout<<result[max-i]<<" ";
}

//i      :0  1  2  3  4  5
//array[]:10 20 10 30 20 50
//dp[]   :1  2  1  3  2  4
//index[]:0  0  0  1  0  3
