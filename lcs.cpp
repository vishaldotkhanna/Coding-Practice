#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long LL;

//Largest common subsequence.

int rev_str(string& s)
{
    int n = s.length();

    for(int i = 0;i < (n - i - 1);i++)
    {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }

    return 0;
}

string get_LCS(string X, string Y)
{
    int m = X.length();
    int n = Y.length();

    int L[m + 1][n + 1];

    for(int i = 0;i <= m;i++)
    {
        for(int j = 0;j <= n;j++)
        {
            if(i == 0 || j == 0)
            {
                L[i][j] = 0;
            }
            else if(X[i - 1] == Y[j - 1])
            {
                L[i][j] = L[i - 1][j - 1] + 1;   //Diagonal + 1 when Xi = Yj.
            }
            else
            {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);    //Otherwise greater of top or left element.
            }

            cout<<L[i][j]<<" ";
        }

        cout<<endl;
    }



    int len = L[m][n];
    string lcs = "";

    int i = m;
    int j = n;

    while(i > 0 and j > 0)
    {
        if(X[i - 1] == Y[j - 1])    //Move diagonally if Xi = Yj.
        {
            lcs += X[i - 1];
            i--;
            j--;
        }
        else if(L[i - 1][j] > L[i][j - 1])  //Otherwise move in the direction of the greater value.
        {
            i--;
        }
        else
            j--;

    }

    rev_str(lcs);

    return lcs;

}


int main()
{
    string x = "AGGTAB";
    string y = "GXTXAYB";

    cout<<get_LCS(x, y);
}
