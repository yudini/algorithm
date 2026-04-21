#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<pair<char,char>> m;
char table[5][5];
char alpha[26];
string key;
string s;

map<char, pair<int,int>> position;
vector<char> cipher;

void make_table(){

    int k;
    int i=0; 
    // int j=0;

    for(int k=0;k<key.length();k++){
        int pos = key[k]-65;


        if(alpha[pos]==1)
            continue;

            table[i/5][i%5] = pos+65;   
            alpha[pos] =1;
            position.emplace(key[k],make_pair(i/5,i%5));

            i++;
        // if(i==5){
        //     i=0;
        // }
        // if(j==5){
        //     j=0;
        //     i++;
        // }

        // table[i][j] = pos+65;
        // position.emplace(key[k],make_pair(i,j));
        // //cout<<table[i][j];
        // alpha[pos]=1;
        // j++;
        
    }

    for(int k=0;k<26;k++){
        if(alpha[k]==1)
            continue;

        table[i/5][i%5] = k+65;   
        position.emplace(k+65,make_pair(i/5,i%5));

        i++;

        // if(i==5){
        //     i=0;
        // }
        // if(j==5){
        //     j=0;
        //     i++;
        // }
        // table[i][j] = k+65;
        // position.emplace(k+65,make_pair(i,j));
        // alpha[k]=1;
        // j++;
    }

    

}

void MakePair(){
    int i=0;
    string pair_msg = "";
    for(int i=0;i<s.size();i++){
        if(pair_msg.size()%2 == 1 && pair_msg.back() == s[i] ){
            if(pair_msg.back()=='X') pair_msg += 'Q';
            else pair_msg +='X';
        }
        pair_msg+=s[i];
    }
    
    if(pair_msg.size()%2==1) pair_msg+='X';

    for(int i=0;i<pair_msg.size();i+=2){
        m.push_back({pair_msg[i],pair_msg[i+1]});
    }

    // for(int j=0;j<m.size();j++){
    //     cout<<m[j].first<<m[j].second<<' ';
    // }
    // cout<<'\n';
}

void Encrypt(){
    for(int i=0;i<m.size();i++){
        char new_a, new_b;
        char a = m[i].first;
        char b = m[i].second;

        int x1 = position[a].first;
        int y1 = position[a].second;

        int x2 = position[b].first;
        int y2 = position[b].second;

    //    cout<<x1<<' '<<y1<<' ' << x2 << ' ' << y2;

        if(x1 == x2){
            // cout<<1<<'\n';
            new_a = table[x1][(y1+1)%5];
            new_b = table[x2][(y2+1)%5];
        }else if(y1==y2){
            // cout<<2<<'\n';
            new_a = table[(x1+1)%5][y1];
            new_b = table[(x2+1)%5][y2];
        }else{
            // cout<<3<<'\n';
            new_a = table[x1][y2];
            new_b = table[x2][y1];
        }

        cipher.push_back(new_a);
        cipher.push_back(new_b);
    }
}

int main(){
    cin>>s;
    cin>>key;
    // char a;

    // for(int i=0;i<2;i++){
    //     for(int j=0;j<2;j++){
    //         cout<<a[i][j];
    //     }
    // }

    alpha[9]=1; //j
    make_table();

    // for(int i=0;i<5;i++){
    //     for(int j=0;j<5;j++){
    //         cout<<table[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }

    MakePair();
    
    Encrypt();

    // for(int i=0;i<5;i++){
    //     for(int j=0;j<5;j++){
    //         cout<<table[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }

    for(int i=0;i<cipher.size();i++){
        cout<<cipher[i];
    }
    cout<<'\n';

    return 0;



}