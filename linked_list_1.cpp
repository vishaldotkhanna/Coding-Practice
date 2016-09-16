#include<iostream>

using namespace std;

struct node
{
    int data;
    struct node *next;
}   *start, *ptr, *temp, *prev;

int print_LL()
{
    struct node *PTR = start;

    if(PTR == NULL)
    {
        cout<<"List is empty.\n";
        return 0;
    }

    cout<<"Printing the list.\n";

    while(PTR != NULL)
    {
        cout<<PTR->data<<" "<<PTR<<"\n";
        PTR = PTR->next;
    }

    return 0;
}

int add_start()
{
    int val;
    cout<<"Enter value.\n";
    cin>>val;

    ptr = new struct node;
    ptr->data = val;

    if(start == NULL)
    {
        start = ptr;
        ptr->next = NULL;
        return 0;
    }

    ptr->next = start;
    start = ptr;

    return 0;
}

int add_end()
{
    int val;
    cout<<"Enter value.\n";
    cin>>val;

    ptr = new struct node;
    ptr->data = val;

    if(start == NULL)   //Empty list.
    {
        start = ptr;
        ptr->next = NULL;
        return 0;
    }

    temp = start;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = ptr;
    ptr->next = NULL;

    return 0;
}

int add_after()
{
    if(start == NULL)
    {
        cout<<"Empty list.\n";
        return 0;
    }

    int val, findval;

    cout<<"Enter value after which to insert new node.\n";
    cin>>findval;

    cout<<"Enter value of new node.\n";
    cin>>val;

    ptr = new struct node;
    ptr->data = val;

    temp = start;

    while(temp->data != findval)
    {
        temp = temp->next;
        if(temp == NULL)
        {
            cout<<"Value not found in the list.\n";
            return 0;
        }
    }

    ptr->next = temp->next;
    temp->next = ptr;

    return 0;
}

int add_before()
{
    if(start == NULL)
    {
        cout<<"List is empty.\n";
        return 0;
    }

    int val, findval;

    cout<<"Enter value before which to insert new node.\n";
    cin>>findval;

    cout<<"Enter value of the new node.\n";
    cin>>val;

    ptr = new struct node;
    ptr->data = val;

    temp = prev = start;

    while(temp->data != findval)
    {
        prev = temp;
        temp = temp->next;

        if(temp == NULL)
        {
            cout<<"Value not found in the list.\n";
            return 0;
        }
    }

    if(prev == temp)   //findval is stored in the first element of the list. prev and temp both point to that element.
    {
        ptr->next = start;
        start = ptr;
        return 0;
    }

    ptr->next = prev->next;    //We can also directly do ptr->next = temp;
    prev->next = ptr;

    return 0;
}

int del_start()
{
    if(start == NULL)
    {
        cout<<"Empty list.";
        return 0;
    }

    ptr = start;
    start = start->next;
    delete ptr;
}

int del_end()
{
    if(start == NULL)
    {
        cout<<"List is empty.\n";
        return 0;
    }

    prev = temp = start;

    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    if(prev == temp)    //List has only 1 element. prev, temp and start point to it.
    {
        delete start;
        start = prev = temp = NULL;
        return 0;
    }

    prev->next = NULL;
    delete temp;
    temp = NULL;

}

int del_current()
{
    if(start == NULL)
    {

        cout<<"List is empty.\n";
        return 0;
    }

    temp = prev = start;

    int findval;
    cout<<"Enter value of the node to be deleted.";
    cin>>findval;

    while(temp->data != findval)
    {
        prev = temp;
        temp = temp->next;

        if(temp == NULL)
        {
            cout<<"Element not found.";
            return 0;
        }
    }

    if(prev == temp)    //If the 1st element is to be deleted.
    {
        start = start->next;
        delete temp;
        temp = prev = NULL;
        return 0;
    }

    prev->next = temp->next;
    delete temp;
    temp = NULL;

    return 0;
}

int del_previous()
{
    if(start == NULL)
    {
        cout<<"List is empty.";
        return 0;
    }

    int findval;
    cout<<"Enter value to search for in the list.";
    cin>>findval;

    if(start->data == findval)
    {
        cout<<"There is no node before the node containing the value specified.";
        return 0;
    }

    temp = prev = start;

    while(temp->next->data != findval)
    {
        prev = temp;
        temp = temp->next;

        if(temp->next == NULL)
        {
            cout<<"Element not found.";
            return 0;
        }
    }

    if(prev == temp)    //2nd node contains the value given in findval. 1st node is to be deleted.
    {
        prev->next = temp->next;
        delete temp;
        temp = NULL;
    }

    prev->next = temp->next;
    delete temp;
    temp = NULL;

    return 0;
}

int main()
{
    start = ptr = temp = prev = NULL;
    int choice;
    char foo;

    do
    {
        cout<<"Enter your choice.\n";
        cout<<"0. print_LL()\n";
        cout<<"1. add_start()\n";
        cout<<"2. add_end()\n";
        cout<<"3. add_after()\n";
        cout<<"4. add_before()\n";
        cout<<"5. del_start()\n";
        cout<<"6. del_end()\n";
        cout<<"7. del_current()\n";
        cin>>choice;

        switch(choice)
        {
            case 1:
                    add_start();
                    break;

            case 2:
                    add_end();
                    break;

            case 3:
                    add_after();
                    break;

            case 4:
                    add_before();
                    break;

            case 5:
                    del_start();
                    break;

            case 6:
                    del_end();
                    break;

            case 7:
                    del_current();
                    break;

            case 0:
                    print_LL();
                    break;

            default:
                    cout<<"Invalid output.\n";

        }

        cout<<"Continue? (y/n)\n";
        cin>>foo;

    }   while(foo == 'y' || foo == 'Y');

    return 0;


}
