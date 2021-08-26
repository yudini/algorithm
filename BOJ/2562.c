#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[9];
    int i,max;
    int k=0;
    
    for(i=0;i<9;i++){
        scanf("%d",&array[i]);
    }
    max=0;

    for(i=0;i<9;i++){
        if(max<array[i]){
            max=array[i];
            k=i+1;
        }
    }

    printf("%d \n",max);
    printf("%d",k);
}