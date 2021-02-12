#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int a[100000];

int Q(int i,int j,int k){
    int a2[100000];
    int y=0;
    for(int x=i-1;x<=j-1;x++){
        a2[y]=a[x];
        y++;
    }

    sort(a2,a2+y);
    return a2[k-1];
}

int main (){
    int n,m,i,j,k;
    scanf("%d %d",&n,&m);
    for(int x=0;x<n;x++){
        scanf("%d",&a[x]);
    }
    
    for(int x=0;x<m;x++){
        scanf("%d %d %d",&i,&j,&k);
        printf("%d \n",Q(i,j,k));
    }
}
