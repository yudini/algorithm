#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int row = commands.size();
    for(int i=0;i<row;i++){
        vector <int> a;
        for(int j=commands[i][0]-1;j<commands[i][1];j++){
            a.push_back(array[j]);
        }
        sort(a.begin(),a.end());
        answer.push_back(a[commands[i][2]-1]);
    }
    return answer;
}

int main(){
    vector <int> array={1,5,2,6,3,7,4};
    vector <vector<int>>commands={
        {2,5,3},
        {4,4,1},
        {1,7,3},
        {1,5,3}
    };
    vector<int>answer=solution(array,commands);
    for(int i=0;i<answer.size();i++)
          cout<<answer[i];

}