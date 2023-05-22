// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

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
        int count=0;
        ListNode* temp = head;

        while(temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }

    int getDecimalValue(ListNode* head)
    {
        int ans=0;
        int len = listSize(head);
        int locationValue = pow(2, len-1);

        ListNode* temp = head;

        while(temp != NULL)
        {
            if(temp->val == 1)
            {
                ans += locationValue;
            }

            temp = temp->next;
            locationValue /= 2;
        }

        return ans;
    }
};
