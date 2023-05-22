// https://leetcode.com/problems/middle-of-the-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    int listSize(ListNode* head)
    {
        int count = 0;
        ListNode* temp = head;

        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    ListNode* middleNode(ListNode* head)
    {
        int len = listSize(head);
        int mid = len/2;

        ListNode* temp = head;
        for(int i=0; i<mid; i++)
        {
            temp = temp->next;
        }
        return temp;
    }
};
