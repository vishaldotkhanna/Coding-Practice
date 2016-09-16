#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long LL;

//Generate subsets with equal sum for an array.

struct MySet
{
    int sum;
    vector<int> element;

    bool operator<(struct MySet& s)
    {
        return sum < s.sum;
    }

    int display_elements()
    {
        int n = element.size();

        cout<<"{";
        for(int i = 0;i < n;i++)
            cout<<" "<<element[i];
        cout<<" }"<<endl;
    }


};

vector<MySet> subset;

int find_sum(vector<int> a)
{
    int n = a.size();
    int sum = 0;

    for(int i = 0;i < n;i++)
        sum += a[i];

    return sum;
}

int power_set(int a[], int n)
{
    for(int i = 0;i < pow(2, n);i++)    //Iterating over all subsets.
    {
        struct MySet temp;

        for(int j = 0;j < n;j++)    //Iterating over all possible elements in the subset.
        {
            if(i & (1 << j))    //Checking if jth element is present in ith subset.
                temp.element.push_back(a[j]);
        }

        temp.sum = find_sum(temp.element);
        subset.push_back(temp);
    }

    return 0;
}

int display_subsets()
{
    int n = subset.size();

    for(int i = 0;i < n;i++)
    {
        subset[i].display_elements();
        cout<<"Sum = "<<subset[i].sum<<endl;
    }

}

int equal_sum()
{
    sort(subset.begin(), subset.end());

    int n = subset.size();

    for(int i = 0;i < n;i++)
    {
        if(subset[i].sum == subset[i + 1].sum)
        {
            cout<<"Sum = "<<subset[i].sum<<endl;
            subset[i++].display_elements();

            while(subset[i].sum == subset[i + 1].sum)
            {
                subset[i++].display_elements();
            }

            subset[i].display_elements();
        }
    }

    return 0;
}



int main()
{
    int arr[] = {1, 2, 3, 4};

    power_set(arr, 4);

    //display_subsets();

    equal_sum();



}
