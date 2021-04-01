#include <iostream>

using namespace std;

int main()
{
    int A,B,V,n;
    cin>>A>>B>>V;
    if((V-A)%(A-B)==0)
        n=(V-A)/(A-B) +1;
    else
        n=(V-A)/(A-B) +2;
    cout<<n<<endl;
    return 0;
}

