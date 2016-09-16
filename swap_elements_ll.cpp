#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<bitset>

#define MAX_SIZE 500

using namespace std;

typedef long long LL;

struct node
{
    char data;
    node * next;
} *ptr, *temp, *ll1, *ll2;

node* new_node(char val)
{
    node *foo = new node;
    foo->data = val;
    foo->next = NULL;
    return foo;
}

int print_ll(node *LL)
{
    while(LL)
    {
        cout<<LL->data;
        LL = LL->next;
    }

    cout<<endl;
}

node* get_index(node *LL, int N)
{
    int count = 0;

    while(LL && count < N)
    {
        count++;
        LL = LL->next;
    }

    if(count < N)   //Return NULL if the index is greater than the list's length.
        return NULL;

    return LL;
}

node* get_prev(node *LL, node *cur)
{
    node *prev = LL;

    while(LL)
    {
        if(LL == cur)
            return prev;

        prev = LL;
        LL = LL->next;
    }

    cout<<"Node not found."<<endl;

    return NULL;
}

int swap_elements(node *LL, int N, int M)
{
    node *ptr1 = get_index(LL, N);
    node *ptr2 = get_index(LL, M);
    node *prev1 = get_prev(LL, ptr1);
    node *prev2 = get_prev(LL, ptr2);

    if(!ptr1 || !ptr2)
    {
        cout<<"Index doesn't exist."<<endl;
        return 0;
    }

    if(prev1)
    {
        prev1->next = ptr2;
    }

    if(prev2)
    {
        prev2->next = ptr1;
    }

    node *foo = ptr2->next;
    ptr2->next = ptr1->next;
    ptr1->next = foo;

    print_ll(LL);


}


int main()
{
    ptr = temp = ll1 = ll2 = NULL;
    string a;
    int n, m;

    cin>>a>>n>>m;

    ll1 = new_node(a[0]);

    ptr = ll1;
    for(int i = 1;i <= a.length();i++)
    {
        ptr->next = new_node(a[i]);
        ptr = ptr->next;
    }

    swap_elements(ll1, n, m);

    //print_ll(ll1);


}


