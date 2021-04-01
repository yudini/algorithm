#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A,B,C;
    int n=1;
    scanf("%d %d %d",&A,&B,&C);

    if(C>B){
        n=A/(C-B)+1;
    }
    else
        n=-1;
    
    printf("%d",n);
    return 0;
}

