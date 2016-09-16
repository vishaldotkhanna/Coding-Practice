#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long LL;

int bubble_sort(int a[], int n) //Descending order.
{
    for(int i = n - 2;i >=0;i--)
    {
        for(int j = 0;j <= i;j++)
        {
            if(a[j] < a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    return 0;
}

int selection_sort(string a)
{
    int n = a.length();

    for(int i = 0;i < n - 1;i++)
    {
        int foo = i + 1;

        for(int j = i + 2;j < n;j++)
        {
            if(a[j] < a[foo])
            {
                foo = j;
            }
        }

        if(a[foo] < a[i])
        {
            char temp = a[i];
            a[i] = a[foo];
            a[foo] = temp;
        }

    }

    cout<<a<<endl;
}


int display_arr(int a[], int n)
{
    for(int i = 0;i < n;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    return 0;
}

int main()
{
    int arr[] = {5, 1, 2, 7, 8, 90, 22};

    bubble_sort(arr, 7);

    display_arr(arr, 7);
}
