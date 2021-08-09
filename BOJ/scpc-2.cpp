/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(int argc, char** argv)
{
	int T,n,t;
    char B[50000];

	cin >> T;
	for(int i = 0; i< T; i++)
	{
        cin>>n>>t;
        cin>>B;
        char Answer[50000];
        bool fixed[50000]={false};

        for(int j=1;j<=n;j++){
            if(j<=t){
                fixed[j+t]=true;
                if(B[j-1]=='1'){
                    Answer[j+t]='1';
                }else{
                    Answer[j+t]='0';
                }
            }
            if(j>n-t){
                fixed[j-t]=true;
                if(B[j-1]=='1'){
                    Answer[j-t]='1';
                }else{
                    Answer[j-t]='0';
                }
            }
        }

        for(int j=t+1;j<=n-t;j++){
            if(B[j-1]=='0'){
                fixed[j+t]=true;
                fixed[j-t]=true;
                Answer[j-t]='0';
                Answer[j+t]='0';
            }
        }

        for(int j=t+1;j<=n-t;j++){
            if(B[j-1]=='1'){
                if(!fixed[j-t]&&!fixed[j+t]){
                    fixed[j+t]=true;
                    fixed[j-t]=true;
                    Answer[j-t]='0';
                    Answer[j+t]='1';
                }else if(!fixed[j+t]&&fixed[j-t]){
                    fixed[j+t]=true;
                    if(Answer[j-t]=='1'){
                        Answer[j+t]='0';
                    }
                    else{
                        Answer[j+t]='1';
                    }
                }else if(!fixed[j-t]&&fixed[j+t]){
                    fixed[j-t]=true;
                    if(Answer[j+t]=='1'){
                        Answer[j-t]='0';
                    }else{
                        Answer[j-t]='1';
                    }
                }
            }
        }

		cout << "Case #" << i+1 << endl;
		for(int j=1;j<=n;j++){
            cout<<Answer[j];
        }
        cout<<"\n";
	}

	return 0;
}