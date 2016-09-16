#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

typedef long long LL;

//int arr[] = {10, 14, 19, 26, 27, 31, 33, 35, 42, 44};

int arr[] = {12, 11, 13, 5, 6, 7};

int display_arr()
{
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0;i < n;i++)
        cout<<arr[i]<<" ";

    return 0;
}

int merge_arr(int l, int mid, int r)
{
    int n = r - l + 1, i, j, k;
    int temp[n];
    i = j = l;
    k = mid + 1;

    cout<<"test merge_arr "<<l<<" mid = "<<mid<<" "<<r<<" "<<endl;


    while(j <= mid && k <= r)
    {
        if(arr[j] <= arr[k])
        {
            temp[i++] = arr[j++];
        }
        else
        {
            temp[i++] = arr[k++];
        }
    }

    cout<<"merge_arr2.1 "<<i<<" "<<j<<" "<<" "<<k<<endl;

    if(!(j > mid))
    {
        while(j <= mid)
        {
            temp[i++] = arr[j++];
        }
    }

    if(!(k > r))
    {
        while(k <= r)
        {
            temp[i++] = arr[k++];
        }
    }

    cout<<"merge_arr2.2 "<<i<<" "<<j<<" "<<" "<<k<<endl;

    for(i = l;i <= r;i++)
    {
        arr[i] = temp[i];
        cout<<"merge_arr3 "<<arr[i]<<" ";
    }

    cout<<endl;



    return 0;
}

int merge_sort(int l, int r)
{
    cout<<"test merge_sort "<<l<<" "<<r<<" mid = "<<(l + r) / 2<<endl;

    if(l < r)
    {
        int mid = (l + r) / 2;
        merge_sort(l, mid);
        merge_sort(mid + 1, r);

        merge_arr(l, mid, r);
    }

    return 0;
}

int main()
{
    int N = sizeof(arr)/sizeof(arr[0]);

    merge_sort(0, N - 1);

    display_arr();

    return 0;
}
