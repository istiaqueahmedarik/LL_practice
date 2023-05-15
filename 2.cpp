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
    SLL avg(SLL &s)
    {
        Node *temp = head;
        Node *temp2 = s.head;
        SLL ans;
        while (temp != NULL || temp2 != NULL)
        {
            if (temp == NULL)
            {

                ans.push_back(temp2->val / 2);
                temp2 = temp2->next;
            }
            else if (temp2 == NULL)
            {
                ans.push_back(temp->val / 2);
                temp = temp->next;
            }
            else
            {
                ans.push_back((temp->val + temp2->val) / 2);
                temp = temp->next;
                temp2 = temp2->next;
            }
        }
        return ans;
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
    s.push_back(10);
    s.push_back(20);
    s.push_back(30);
    s.push_back(40);
    s.push_back(50);
    s1.push_back(20);
    s1.push_back(40);
    s1.push_back(60);
    s1.push_back(80);
    s1.push_back(100);
    s1.push_back(120);
    SLL ans = s.avg(s1);
    ans.print();
}