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
        unordered_map<int, ListNode*> umap;   //<prefixSum, ptr>

        ListNode *root = new ListNode(0);
        root->next = head;

        int sum = 0;
        auto temp = root;

        while(temp != NULL)
        {
            sum += temp->val;
            umap[sum] = temp;
            temp = temp->next;
        }

        sum = 0;
        temp = root;

        while(temp != NULL)
        {
            sum += temp->val;
            temp->next = umap[sum]->next;
            temp = temp->next;
        }

        return root->next;
    }
};
