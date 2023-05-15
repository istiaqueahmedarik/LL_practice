#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *next;

    Node(int val)
    {
        value = val;
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
        if (head == NULL)
        {
            head = new Node(val);
            return;
        }
        Node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = new Node(val);
    }

    void pop_front()
    {
        if (head == NULL)
            return;
        Node *curr = head;
        head = head->next;
        delete curr;
    }

    int last_occurance(int val)
    {
        Node *curr = head;
        int index = -1;
        int count = 0;
        while (curr != NULL)
        {
            if (curr->value == val)
                index = count;
            curr = curr->next;
            count++;
        }
        return index;
    }
    int count(int val)
    {
        Node *curr = head;
        int count = 0;
        while (curr != NULL)
        {
            if (curr->value == val)
                count++;
            curr = curr->next;
        }
        return count;
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
    void delete_duplicate()
    {
        Node *curr = head;
        while (curr != NULL)
        {
            dltDuplicate(curr->value);
            curr = curr->next;
        }
    }
    void dltDuplicate(int val)
    {
        if ((count(val) == 1) || count(val) == 0)
            return;
        dlt(last_occurance(val));
        dltDuplicate(val);
    }

    void print()
    {
        Node *curr = head;
        while (curr != NULL)
        {
            cout << curr->value << " ";
            curr = curr->next;
        }
    }
    ~SLL()
    {
        delete head;
    }
};
int main()
{
    SLL s;
    s.push_back(2);
    s.push_back(2);
    s.push_back(2);
    s.push_back(3);
    s.push_back(4);
    s.push_back(5);
    s.push_back(5);
    s.delete_duplicate();
    s.print();
    cout << endl;
}