#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<bitset>

using namespace std;

typedef long long LL;

//Queue as array.

struct Q
{
    int front_, rear_, qn;
    string q[100];

    Q()
    {
        front_ = rear_ = -1;
        qn = 0;
    }

    int q_push(string val)
    {
        if(rear_ == 99)
        {
            cout<<"Overflow"<<endl;
            return 0;
        }

        if(rear_ == -1)
        {
            front_++;
        }

        q[++rear_] = val;
        qn++;

        return 0;
    }

    string q_pop()
    {
        if(front_ == -1)
        {
            cout<<"Underflow";
            return 0;
        }

        qn--;
        string temp = q[front_];

        if(front_ == rear_)
        {
            front_ = rear_ = -1;
        }
        else
        {
            front_++;
        }

        return temp;
    }

    int display_q()
    {
        if(!qn)
        {
            cout<<"Queue is empty."<<endl;
            return 0;
        }

        for(int i = front_;i <= rear_;i++)
            cout<<q[i]<<" ";
        cout<<endl;

        return 0;
    }

};



int main()
{
    struct Q q1;

    q1.q_push("hi");
    q1.q_push("hel");

    q1.display_q();

    q1.q_pop();
    q1.display_q();
}
