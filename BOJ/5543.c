#include <stdio.h>

int main()
{
    int burger=2000;
    int drink=2000;
    int i,a,b;

    for(i=0;i<3;i++){
        scanf("%d",&a);
        if(a<burger)
            burger=a;
    }

    for(i=0;i<2;i++){
        scanf("%d",&b);
        if(b<drink)
            drink=b;
    }
    printf("%d",burger+drink-50);

    return 0;
}