// https://leetcode.com/problems/reverse-linked-list/

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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prevNode = NULL;
        ListNode* currentNode = head;
        if(head == NULL)
        {
            return head;
        }
        ListNode* nextNode = head->next;

        while(1)
        {
            currentNode->next = prevNode;

            prevNode = currentNode;
            currentNode = nextNode;

            if(currentNode == NULL)
            {
                break;
            }

            nextNode = nextNode->next;
        }

        return prevNode;
    }
};
