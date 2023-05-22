// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

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
    ListNode* removeZeroSumSublists(ListNode* head)
    {
        ListNode *root = new ListNode(0);
        root->next = head;

        for(ListNode* i=root; i!=NULL; i=i->next)
        {
            int sum = 0;
            for(ListNode* j=i->next; j!=NULL; j=j->next)
            {
                sum += j->val;

                if(sum == 0)
                {
                    i->next = j->next;
                }
            }
        }

        return root->next;
    }
};
