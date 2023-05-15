#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
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
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new Node(val);
    }

    void priority_insert(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *curr = head;
        Node *prev = NULL;
        while (curr != NULL)
        {
            if (curr->val > val)
            {
                if (prev == NULL)
                {
                    newNode->next = head;
                    head = newNode;
                    return;
                }
                newNode->next = curr;
                prev->next = newNode;
                return;
            }
            else if (curr->val == val)
                return;
            prev = curr;
            curr = curr->next;
        }

        if (prev == NULL)
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        newNode->next = curr;
        prev->next = newNode;
        return;

        prev = curr;
        curr = curr->next;
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

    SLL Merge(SLL &other)
    {
        SLL merged;
        Node *curr = head;
        Node *curr1 = other.head;
        while (curr != NULL)
        {
            merged.priority_insert(curr->val);
            curr = curr->next;
        }
        while (curr1 != NULL)
        {
            merged.priority_insert(curr1->val);
            curr1 = curr1->next;
        }
        return merged;
    }
    ~SLL() { delete head; }
};
int main()
{
    SLL s, s1;
    s.push_back(1);
    s.push_back(9);
    s.push_back(2);
    s.push_back(4);
    s.push_back(10);
    s1.push_back(3);
    s1.push_back(1);
    s1.push_back(5);
    SLL ans = s.Merge(s1);
    ans.print();
}