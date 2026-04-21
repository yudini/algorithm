#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector <int> map[4];
int k;
vector <pair<int,int>> rotation;


void Rotate2(int pos, int direct){
    if(direct == 1){
        int x= map[pos].back();

        map[pos].insert(map[pos].begin(),x);
        map[pos].pop_back();
    }
    if(direct == -1){
        int x = map[pos].front();

        map[pos].push_back(x);
        map[pos].erase(map[pos].begin());
    }

}


void Rotate(int pos,int direct){

    vector <pair<int,int>> r;
    r.push_back(make_pair(pos,direct));
    int direction = direct;

    for(int i=pos;i+1<4;i++){
        if(map[i][2]!= map[i+1][6]){
            direction=-direction;
            r.push_back(make_pair(i+1,direction));
        }else{
            break;
        }
    }

    direction = direct;
        
    for(int i=pos;i-1>=0;i--){
        if((map[i][6]!=map[i-1][2])){
            direction=-direction;
            r.push_back(make_pair(i-1,direction));
        }else{
            break;
        }
    }

    
    for(int i=0;i<r.size();i++){
        Rotate2(r[i].first,r[i].second);
    }

    // for(int i=0;i<4;i++){
    //     for(int j=0;j<8;j++){
    //         cout<<map[i][j];
    //     }
    //     cout<<"\n";
    // }
    // cout<<"\n";
    // cout<<"\n";

}

int main(){

    for(int i=0;i<4;i++){
        string s;
        cin>>s;
        for(int j=0;j<8;j++){
            if(s[j]=='0')
                map[i].push_back(0);
            else
                map[i].push_back(1);
        }
    }
    cin>>k;

    for(int i=0;i<k;i++){
        int pos, direct;
        cin>>pos>>direct;
        rotation.push_back(make_pair(pos,direct));
    }

    for(int i=0;i<rotation.size();i++){
        //cout<<"hi"<<"\n";
        int pos = rotation[i].first;
        int direct = rotation[i].second;
        Rotate(pos-1,direct);
    }

    int score =0;

    for(int i=0;i<4;i++){
        if(map[i].front() == 1){
            score += pow(2,i);
            //cout<<i<<score<<"\n";
        }
    }

    cout<<score;
    
}