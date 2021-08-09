#include <iostream>
#include <vector>

using namespace std;


int a[100000];
bool visited[100000];
int N;
int count;

void find(int j){
    visited[j]=true;
    if(j+a[j]<=N){
        if(visited[j+a[j]]==false){
            find(j+a[j]);
        }
    }else{
        count++;
    }
     
}

int main(){
    int T;
    int x;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N;
        count=0;

        for(int j=1;j<=N;j++){
            cin>>x;
            a[j]=x;
            visited[j]=false;
        }

        for(int j=1;j<=N;j++){
            if(visited[j]==false){
                find(j);
            }
        }
        cout<<"Case #"<<i+1<<"\n";
        cout<<count<<"\n";
    }

    return 0;
}

/*
int main(int argc,char ** argv)
{
    int T;
    int x;
    cin>>T;
    for(int i=0;i<T;i++){   //테스트 케이스 개수
        int N;
        group a[100000];
        cin>>N;
        for(int j=1;j<=N;j++){
            cin>>x;
            a[j].nN=x;
        }
        int count=1;
        a[1].Gnumber=count;
        for(int j=1;j<=N;j++){
            if(j+a[j].nN<=N){
                if(a[j].Gnumber!=0&&a[j+a[j].nN].Gnumber==0){  //j 있 J+o 없
                    a[j+a[j].nN].Gnumber=1;
                }else if(a[j].Gnumber==0&&a[j+a[j].nN].Gnumber==0){// 없 없
                    count++;
                    a[j].Gnumber=1;
                    a[j+a[j].nN].Gnumber=1;
                }else if(a[j].Gnumber==0&&a[j+a[j].nN].Gnumber!=0){  // 없 있
                    a[j].Gnumber=1;
                }else{  //있 있
                   count--;
                }
            }
            else{
                if(a[j].Gnumber!=1){
                    count++;
                    a[j].Gnumber=1;
                }
            }
        }
        cout<<"Case #"<<i+1<<"\n";
        cout<<count<<"\n";
    }

    return 0;
}*/