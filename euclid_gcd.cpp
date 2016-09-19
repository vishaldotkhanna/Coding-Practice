#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

#define MAX 50
typedef long long LL;

int gcd(int a, int b)
{
    while(b)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    int a, b;

    cin>>a>>b;

    cout<<endl<<gcd(a, b);

    return 0;
}
