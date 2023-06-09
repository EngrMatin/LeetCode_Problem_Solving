// https://leetcode.com/problems/remove-linked-list-elements/

/**
 * Definition for singly-linked list.
 * struct ListNode
   {
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
    ListNode* removeElements(ListNode* head, int val)
    {
        if(head==NULL)
        {
            return head;
        }

        ListNode *prev = new ListNode(0);
        prev->next = head;

        ListNode *temp = prev;

        while(temp->next != NULL)
        {
            if(temp->next->val == val)
            {
                ListNode *delNode= temp->next;
                temp->next = temp->next->next;
                delete delNode;
            }
            else
            {
                temp = temp->next;
            }
        }

        return prev->next;
    }
};
