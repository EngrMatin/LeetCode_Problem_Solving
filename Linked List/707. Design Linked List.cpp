// https://leetcode.com/problems/design-linked-list/

class MyLinkedList
{
public:
    int val;
    MyLinkedList *next;
    MyLinkedList *head;

    MyLinkedList()
    {
        head = NULL;
    }

    MyLinkedList(int val)
    {
        this->val = val;
        this->next = NULL;
    }

    int get(int index)
    {
        MyLinkedList *temp = head;

        for(int i=0; i<index; i++)
        {
            temp = temp->next;

            if(temp == NULL)
            {
                break;
            }
        }

        if(temp == NULL)
        {
            return -1;
        }
        else
        {
            return temp->val;
        }
    }

    void addAtHead(int val)
    {
        MyLinkedList *newNode = new MyLinkedList(val);
        newNode->next= head;
        head = newNode;
    }

    void addAtTail(int val)
    {
        MyLinkedList *newNode = new MyLinkedList(val);

        if(head == NULL)
        {
            head = newNode;
            return;
        }

        MyLinkedList *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void addAtIndex(int index, int val)
    {
        if(index == 0)
        {
           addAtHead(val);
            return;
        }

        MyLinkedList *temp = head;

        for(int i=0; i<index-1; i++)
        {
            temp = temp->next;

            if(temp == NULL)
            {
                break;
            }
        }

        if(temp == NULL)
        {
            return;
        }

        MyLinkedList *newNode = new MyLinkedList(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtIndex(int index)
    {
        if(index == 0)
        {
            MyLinkedList *delNode = head;
            head = head->next;
            delete delNode;
            return;
        }

        MyLinkedList *temp = head;

        for(int i=0; i<index-1; i++)
        {
            temp = temp->next;

            if(temp == NULL)
            {
                break;
            }
        }

        if(temp == NULL)
        {
            return;
        }

        MyLinkedList *delNode = temp->next;
        if(delNode == NULL)
        {
            return;
        }
        temp->next = delNode->next;
        delete delNode;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
