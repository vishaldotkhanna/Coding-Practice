#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<bitset>

#define MAX_SIZE 500

using namespace std;

typedef long long LL;

//Generate all prime number pairs whose product <= the given number.

vector<int> prime;

bool is_prime(int N)    //Only works when generating prime numbers in a sequence;
{
    if(N < 2)
        return false;
    else if(N != 2 && !(N % 2))
        return false;

    int n = prime.size();
    int root = sqrt(N);

    for(int i = 0;i < n && prime[i] <= root;i++)
    {
        if(!(N % prime[i]))
            return false;
    }

    return true;
}

int get_primes()
{
    for(int i = 3;i < 200;i++)
    {
        if(is_prime(i))
            prime.push_back(i);
    }
}

int print_pairs(int N)
{
    int temp = N / 2;
    for(int i = 0;prime[i] <= temp && i < 44;i++)
    {
        //cout<<prime[i]<<" "<<prime[i]<<" ";

        for(int j = 0;prime[i] * prime[j] <= N && j < 45;j++)
            cout<<prime[i]<<" "<<prime[j]<<" ";
    }

    cout<<endl;

    return 0;
}

int main()
{
    prime.push_back(2);
    get_primes();
    int t, n;

    cin>>t;
    while(t--)
    {
        cin>>n;
        print_pairs(n);
    }

    return 0;
}
