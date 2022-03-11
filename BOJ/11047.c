#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,k,i;
    int coin=0;
    scanf("%d %d",&n,&k);
    int money[n];
    for(i=0;i<n;i++)
        scanf("%d",&money[i]);


    for(i=n-1;i>=0;i--){
        if(k/money[i]!=0){
            coin+=k/money[i];
            k%=money[i];
        }
    }

    printf("%d",coin);
    return 0;
}