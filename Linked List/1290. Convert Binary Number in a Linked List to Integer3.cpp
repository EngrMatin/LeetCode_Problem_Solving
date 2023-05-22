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

        return convert(str);
    }

    int convert(string s)
    {
        int ans = 0;

        for(int i=0, j=s.size()-1;  j>=0;  i++, j--)
        {
            ans += (s[j]-'0') * pow(2, i);
        }

        return ans;
    }
};

