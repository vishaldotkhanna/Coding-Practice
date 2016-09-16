#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<bitset>

#define MAX_SIZE 500

using namespace std;

typedef long long LL;

//Compare strings stored as LL.

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

int compare_string(node *LL1, node *LL2)
{
    while(LL1 && LL2)
    {
        if(LL1->data == LL2->data)
        {
            LL1 = LL1->next;
            LL2 = LL2->next;
        }
        else if(LL1->data > LL2->data)
            return -1;
        else
            return 1;
    }

    if(!LL1 && !LL2)
        return 0;
    else if(LL1)
        return -1;
    else return 1;
}

int main()
{
    ptr = temp = ll1 = ll2 = NULL;
    string a, b;

    cin>>a>>b;

    ll1 = new_node(a[0]);
    ll2 = new_node(b[0]);

    ptr = ll1;
    for(int i = 1;i <= a.length();i++)
    {
        ptr->next = new_node(a[i]);
        ptr = ptr->next;
    }

    ptr = ll2;
    for(int i = 1;i <= b.length();i++)
    {
        ptr->next = new_node(b[i]);
        ptr = ptr->next;
    }

    //print_ll(ll1);
    //print_ll(ll2);

    cout<<compare_string(ll1, ll2);
}


