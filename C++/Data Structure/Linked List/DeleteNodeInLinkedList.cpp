/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) //102
    {
        node->val=node->next->val;
        node->next=node->next->next;
    }
};

/*
100->102->104->106->108

*/
