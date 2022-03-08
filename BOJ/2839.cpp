#include <stdio.h>
int main(){
    int n;
    int count=0;
    scanf("%d",&n);
    count=n/5;
    if(n%5!=0){
        while(count>=0){
            if((n-5*count)%3==0){
                count+=(n-5*count)/3;
                break;
            }
            count--;
        }
    }
    printf("%d",count);
    return 0;
}