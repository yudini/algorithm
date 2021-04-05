#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,count=0;
    scanf("%d",&N);
    if(N<0||99<N)
        scanf("%d",&N);
    int k=N;
    while(1){
        N=(N%10)*10+((N%10+N/10)%10);
        count++;
        if(k==N)
            break;
    }
    printf("%d",count);

    return 0;
}
