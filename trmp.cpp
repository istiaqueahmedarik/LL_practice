#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int val;
    node *next;
};

class linklist
{

public:
    // node nod;

    node *head;

    void insertfirst(int v)
    {
        node *temp;
        temp = new node;
        temp->val = v;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }
    void insertlast(int v)
    {
        node *newitem;
        newitem = new node;
        newitem->val = v;
        newitem->next = NULL;

        if (head == NULL)
        {
            head = newitem;
        }
        else
        {

            node *temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newitem;
        }
    }

    void print()
    {
        cout << "WORKING";
        if (head == NULL)
            return;

        else
        {
            node *temp;
            temp = head;

            while (temp != NULL)
            {
                cout << temp->val << "->";
                temp = temp->next;
            }

            cout << endl;
        }
    }
};

int main()
{
    linklist p1;

    p1.insertfirst(1);
    p1.insertfirst(2);
    p1.insertfirst(3);
    p1.insertlast(6);
    p1.print();
}