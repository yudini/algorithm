#include <iostream>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);

    for(int i=1;i<N;i++){
        for (int j = 1; j <= N - i; j++){
            printf(" ");
        }
        for(int j=0;j<2*i-1;j++){
            printf("*");
        }
        printf("\n");
    }

    for(int i=N;i>=1;i--){
        for(int j=1;j<=N-i;j++){
            printf(" ");
        }
        for(int j=2*i-1;j>0;j--){
            printf("*");
        }
        printf("\n");
    }
}