// https://leetcode.com/problems/remove-linked-list-elements/

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
    struct Test
    {
        int position[10001];
    };

    int countLength(ListNode* &head)
    {
        int count= 0;
        ListNode *temp= head;

        while(temp != NULL)
        {
            count++;
            temp= temp->next;
        }
        return count;
    }

    Test searchByValueDuplicateReturn(ListNode* &head, int key)
    {
        ListNode *temp= head;
        Test T;
        int k=1;
        int count= 1;

        while(temp != NULL)
        {
            if(temp->val == key)
            {
                T.position[k]= count;
                k++;
            }
            temp= temp->next;
            count++;
        }
        T.position[0]=k;
        return T;
    }

    void deletionAtSpecificPosition(ListNode* &head, int position)
    {
        ListNode *temp= head;

        if(temp != NULL && position <= countLength(head))
        {
            if(position == 1)
            {
                head = temp->next;
                delete temp;
            }
            else
            {
                int i=1;
                while(i<position-1)
                {
                    temp= temp->next;
                    i++;
                }
                ListNode *delNode= temp->next;
                temp->next= delNode->next;      //temp->Next= temp->Next->Next;
                delete delNode;
            }
        }
        else
        {
            if(position > countLength(head))
            {
                cout<<"Position Out of Bound"<<endl;
            }
            else
            {
                cout<<"The list is empty"<<endl;
            }
        }
    }


    ListNode* removeElements(ListNode* head, int val)
    {
        Test T;
        T = searchByValueDuplicateReturn(head, val);
        if(T.position[0]==1)
        {
            cout<<"The value is NOT present in the list"<<endl;
            return head;
        }
        else
        {
            int size= T.position[0];
            for(int i=1; i<size; i++)
            {
                deletionAtSpecificPosition(head, T.position[i]);

                for(int i=1; i<size; i++)
                {
                    T.position[i]--;
                }
            }
        }

        return head;
    }
};

