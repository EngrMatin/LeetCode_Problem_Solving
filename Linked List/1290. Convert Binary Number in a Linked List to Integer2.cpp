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
    int getDecimalValue(ListNode* head)
    {
        string str = "";

        while(head != NULL)
        {
            str += to_string(head->val);
            head = head->next;
        }

        int ans = 0;

        for(int i=0, j=str.size()-1;  j>=0;  i++, j--)
        {
            ans += (str[j]-'0') * pow(2, i);
        }

        return ans;
    }
};

