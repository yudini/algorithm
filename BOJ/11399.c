#include <stdio.h>

int main(void)
{
    /* n이 5일때 총 걸리는 시간 5p1+4p2+3p3+2p4+p5*/
    int n,i,j;
    int sum=0;
    scanf("%d",&n);
    int time[n];
    for(i=0;i<n;i++)
        scanf("%d",&time[i]);

    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(time[i]>time[j]){
                time[i]^=time[j];
                time[j]^=time[i];
                time[i]^=time[j];
            }
        }
    }

    for(i=0;i<n;i++)
        sum+=time[i]*(n-i);  //5p1+4p2+3p3+2p4+p5

    printf("%d",sum);


  return 0;
}