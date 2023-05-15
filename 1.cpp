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
    void push_front(int val)
    {
        if (head == NULL)
        {
            head = new Node(val);
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
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
    void inset_after(int val, int data)
    {
        Node *curr = head;
        while (curr->value != val && curr->next != NULL)
        {
            curr = curr->next;
        }
        Node *newNode = new Node(data);
        newNode->next = curr->next;
        curr->next = newNode;
    }
    void pop_front()
    {
        if (head == NULL)
            return;
        Node *curr = head;
        head = head->next;
        delete curr;
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
    void delete_a_value(int val)
    {
        Node *curr = head;
        Node *prev = NULL;
        while (curr != NULL)
        {
            if (curr->value == val)
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
    s.push_back(1);
    s.push_back(2);
    s.push_back(2);
    s.push_back(2);
    s.push_back(3);
    s.push_back(4);
    s.push_back(5);
    s.push_front(0);
    s.inset_after(2, 9);
    s.pop_back();
    s.delete_a_value(1);
    s.print();
    cout << endl;
}