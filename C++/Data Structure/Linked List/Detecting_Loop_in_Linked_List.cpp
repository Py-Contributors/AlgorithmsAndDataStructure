#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

bool detectLoop(struct ListNode *ptr)
{
    unordered_set<ListNode *> s;
    while (ptr != NULL)
    {
        if (s.find(ptr) != s.end())
            return true;
        s.insert(ptr);
        ptr = ptr->next;
    }

    return false;
}

int main()
{
    struct ListNode *head = new ListNode;
    head->val = 2;
    struct ListNode *l1 = new ListNode;
    l1->val = 8;
    head->next = l1;
    struct ListNode *l2 = new ListNode;
    l2->val = 3;
    l1->next = l2;
    struct ListNode *l3 = new ListNode;
    l3->val = 5;
    l2->next = l3;
    struct ListNode *l4 = new ListNode;
    l4->val = 10;
    l3->next = l4;
    l4->next = l2;

    // 2->8->3->5->10--
    //       ^            |
    //       |             |
    //       |_ _ __ _|
    printf("%d", detectLoop(head));
    return 0;
}