#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,i,j,k;
    int sum=0,max=0;
    scanf("%d %d",&n,&m);

    int card[n];
    for(i=0;i<n;i++){
        scanf("%d",&card[i]);
    }

    for(i=0;i<n-2;i++){
        for(j=i+1;j<n-1;j++){
            for(k=j+1;k<n;k++){
                sum=card[i]+card[j]+card[k];
                if(sum>max&&sum<=m)
                    max=sum;
            }
        }
    }

    printf("%d",max);


    return 0;
}

