#include <iostream>

using namespace std;

typedef struct node
{
    char data;
    node * leftchild=NULL;
    node * rightchild=NULL;
}node;

void preorder(node *root){
    if(root){
        cout<<root->data;
        preorder(root->leftchild);
        preorder(root->rightchild);
    }
}

void inorder(node *root){
    if(root){
        inorder(root->leftchild);
        cout<<root->data;;
        inorder(root->rightchild);
    }

}

void postorder(node *root){
    if(root){
        postorder(root->leftchild);
        postorder(root->rightchild);
        cout<<root->data;
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    char a,b,c;
    node nodes[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        nodes[a-'A'].data=a;
        if(b!='.'){
            nodes[b-'A'].data=b;
            nodes[a-'A'].leftchild=&nodes[b-'A'];
        }
        if(c!='.'){
            nodes[c-'A'].data=c;
            nodes[a-'A'].rightchild=&nodes[c-'A'];;
        }
    }
    preorder(&nodes[0]);
    cout<<"\n";
    inorder(&nodes[0]);
    cout<<"\n";
    postorder(&nodes[0]);

}