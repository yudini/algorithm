#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

int solution(string dartResult) {
    vector<int>v;
    int i=0;
    int n=0;
    while(dartResult[i]!=NULL){
        switch (dartResult[i])
        {
        case 'S':{
            v.push_back(n);   
        }
            break;
        case 'D':{
            v.push_back(n*n);
        }
        break;
        case 'T':{
            v.push_back(n*n*n);
        }
        break;
        case '*':{
            int k=v.size()-1;
            v[k]=v[k]*2;
            if(k>=1){
                v[k-1]=v[k-1]*2;
            }

        }
        break;
        case '#':{
            int k=v.size()-1;
            v[k]=v[k]*(-1);
        }
        break;

        default:{
            if(isdigit(dartResult[i-1]))
                n=n*10+(dartResult[i]-'0');
            else
                n=dartResult[i]-'0';
        }
            break;
        }
        i++;
    }

    int answer = 0;
    for(int j=0;j<v.size();j++){
        answer+=v[j];
    }
    return answer;
}