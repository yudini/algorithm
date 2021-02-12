#include <iostream>
#include <algorithm>

using namespace std;

typedef struct Log{
    int x1,x2,y,num,group;
}Log;

Log log[100000];
int N,Q;

bool compare(const Log &a,const Log &b){
    return a.x1<b.x1;
}

void jump(){
    int k=1;
    log[0].group=k;
    for(int i=0;i<N-1;i++){
        if(log[i].x2>=log[i+1].x1){
            log[i+1].group=k;
        }else{
            log[i+1].group=++k;
        }
    }
}

void findGroup(int a,int b){
    int j,k;
    for(int i=0;i<N;i++){
        if(log[i].num==a){
            j=i;
        }
        if(log[i].num==b){
            k=i;
        }
    }

    if(log[j].group==log[k].group)
        printf("1\n");//cout<<"1 \n";
    else
        printf("0\n");//cout<<"0 \n";
}

int main(){
    scanf("%d %d",&N,&Q);
    for(int i=0;i<N;i++){
        scanf("%d %d %d",&log[i].x1,&log[i].x2,&log[i].y);

        log[i].num=i+1;
    }

    sort(log,log+N,compare);

    jump();

    for(int i=0;i<Q;i++){
        int a,b;
        scanf("%d %d",&a,&b);   
        findGroup(a,b);
    }
    return 0;
}