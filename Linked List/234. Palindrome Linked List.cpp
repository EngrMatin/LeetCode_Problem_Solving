// https://leetcode.com/problems/palindrome-linked-list/

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
    bool isPalindrome(ListNode* head)
    {
        stack<int> st;
        queue<int> q;

        while(head != NULL)
        {
            st.push(head->val);
            q.push(head->val);
            head = head->next;
        }

        while(!st.empty())
        {
            if(st.top() != q.front())
            {
                return false;
            }

            st.pop();
            q.pop();
        }

        return true;
    }
};
