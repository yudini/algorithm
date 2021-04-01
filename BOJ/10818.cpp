#include <stdio.h>

int main(){
    int i,max,min,num;
    scanf("%d",&num);
    int a[num];
    for(i=0;i<num;i++){
        scanf("%d",&a[i]);
    }
   max=min=a[0];
    
    for(i=1;i<num;i++){
        if(max<a[i])
            max=a[i];
        if(min>a[i])
            min=a[i];
    }
    printf("%d %d",min,max);

}

