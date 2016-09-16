#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<bitset>

#define MAX_SIZE 500

using namespace std;

typedef long long LL;

//Sorted insertion in Linked List.

struct node
{
    int data;
    struct node* next;
} *start, *ptr, *prev, *cur;

int insert_back(int val)
{
    ptr = new struct node;
    ptr->data = val;
    ptr->next = NULL;    //Since the element is to be inserted at te end, it will always point to null.

    if(start == NULL)   //Empty list.
    {
        start = ptr;
        return 0;
    }

    cur = start;
    while(cur->next != NULL)
        cur = cur->next;

    cur->next = ptr;

    return 0;
}

int print_LL()
{
    if(start == NULL)
        cout<<"List is empty.";
    else
    {
        cur = start;
        while(cur != NULL)
        {
            cout<<cur->data<<" ";
            cur = cur->next;
        }

        cout<<endl;
    }

    return 0;
}

int insert_sorted(int val)
{
    ptr = new struct node;
    ptr->data = val;

    if(start == NULL)
    {
        start = ptr;
        ptr->next = NULL;
    }
    else if(val < start->data)  //Insertion at the front.
    {
        ptr->next = start;
        start = ptr;
    }
    else
    {
        cur = prev = start;
        while(cur != NULL && cur->data <= val)
        {
            prev = cur;
            cur = cur->next;
        }

        ptr->next = prev->next;    //Insertion after prev.
        prev->next = ptr;
    }

    return 0;


}

int main()
{
    int arr[] = {1, 2, 3, 7, 8};

    for(int i = 0;i < 5;i++)
        insert_back(arr[i]);

    int n;

    while(cin)
    {
        cin>>n;
        insert_sorted(n);
        print_LL();
    }


    return 0;

}
