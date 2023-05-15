#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int x)
    {
        val = x;
        next = NULL;
    }
};
class SLL
{
    Node *head;

public:
    SLL()
    {
        head = NULL;
    }
    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        return;
    }
    void pop_front()
    {
        if (head == NULL)
            return;
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    int presence(int val)
    {
        int index = -1;
        int c = 0;
        Node *curr = head;
        while (curr != NULL)
        {
            if (curr->val == val)
            {
                index = c;
                break;
            }
            curr = curr->next;
            c++;
        }
        return index;
    }
    void dlt(int index)
    {
        Node *curr = head;
        Node *prev = NULL;
        if (head == NULL)
            return;
        if (!index)
        {
            pop_front();
            return;
        }
        int c = 0;
        while (c != index && curr != NULL)
        {
            prev = curr;
            curr = curr->next;
            c++;
        }
        if (curr == NULL)
            prev->next = NULL;
        else
            prev->next = curr->next;
    }

    void magicDelete(SLL &others)
    {
        bool flag = false;

        Node *head2 = others.head;
        while (head2 != NULL)
        {
            int ind = presence(head2->val);
            if (ind != -1)
            {
                dlt(ind);
                flag = true;
            }
            head2 = head2->next;
        }
        if (!flag)
            cout << "bla bla bla";
    }
    void print()
    {
        Node *curr = head;
        while (curr != NULL)
        {
            cout << curr->val << " ";
            curr = curr->next;
        }
    }
};

int main()
{
    SLL s, s1;
    s.push_back(1);
    s.push_back(9);
    s.push_back(2);
    s.push_back(4);
    s.push_back(10);

    s1.push_back(4);
    s1.push_back(1);
    s1.push_back(9);

    s.magicDelete(s1);
    s.print();
    cout << endl;
    s1.print();
}