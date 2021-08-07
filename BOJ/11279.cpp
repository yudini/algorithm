#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int heap[100000];
int count;

void insert_data(int data){
    heap[++count]=data;
    int child,parent;
    child=count;
    while(child>1){
        parent=child/2;
        if(heap[child]>heap[parent]){
            int temp=heap[child];
            heap[child]=heap[parent];
            heap[parent]=temp;
            child=parent;
        }
        else{
            break;
        }
    }
}

void delete_data(){
    if(count>0){
        cout<<heap[1]<<"\n";
        heap[1]=heap[count--];
        int parent=1;
        int child;
        while(1){
            child=parent*2;
            if(child+1<=count&&heap[child]<heap[child+1]){
                child++;
            }
            if(child>count ||heap[child]<heap[parent])
                break;
            int temp=heap[child];
             heap[child]=heap[parent];
            heap[parent]=temp;
            parent=child;
        }
    }else{
        cout<<0<<"\n";
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x>0){
            insert_data(x);
        }
        if(x==0){
            delete_data();
        }
    }

}