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
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    void pop_back()
    {
        if (head == NULL)
            return;
        if (head->next == NULL)
            delete head;
        Node *curr = head;
        while (curr->next->next != NULL)
        {
            curr = curr->next;
        }
        Node *temp = curr->next;
        curr->next = NULL;
        delete temp;
    }
    void deleteOdd()
    {
        Node *curr = head;
        Node *prev = NULL;
        while (curr != NULL)
        {
            if (curr->value & 1)
            {
                if (curr == head)
                {
                    if (head == NULL)
                        return;
                    Node *temp = head;
                    head = head->next;
                    prev = curr;
                    curr = curr->next;
                    delete temp;
                    continue;
                }
                else if (curr->next == NULL)
                    pop_back();
                else
                {
                    Node *temp = curr;
                    prev->next = curr->next;
                    curr = curr->next;
                    delete temp;
                    curr = prev;
                }
            }
            prev = curr;
            curr = curr->next;
        }
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
    s.push_back(11);
    s.push_back(12);
    s.push_back(13);
    s.push_back(14);
    s.push_back(15);
    s.push_back(16);
    s.deleteOdd();
    s.print();
}