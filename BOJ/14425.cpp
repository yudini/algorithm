#include <iostream>
#include <vector>

using namespace std;

vector <string> s;
int count;

void test(string str){
    for(int i=0;i<s.size();i++){
        if(s[i]==str)
            count++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    string str;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>str;
        s.push_back(str);
    }
    for(int i=0;i<m;i++){
        cin>>str;
        test(str);
    }
    cout<<count;
}

/*
int n, m;

    map<string, bool> map;
 
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        map[str] = true;
    }
 
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
 
        if (map[str])
            cnt++;
    }
 
    cout << cnt;
*/