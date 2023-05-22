// https://leetcode.com/problems/design-browser-history/

class BrowserHistory {
public:
    class Node
    {
    public:

        string val;
        Node *next;
        Node *prev;

        Node(string val)
        {
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
        }
    };

    Node *current = NULL;

    BrowserHistory(string homepage)
    {
        Node *newNode = new Node(homepage);
        current = newNode;
    }

    void visit(string url)
    {
        Node *visitNode = new Node(url);
        current->next = visitNode;
        visitNode->prev = current;
        current = visitNode;
    }

    string back(int steps)
    {
        while(current->prev != NULL && steps > 0)
        {
            current = current->prev;
            steps--;
        }

        return current->val;
    }

    string forward(int steps)
    {
        while(current->next != NULL && steps>0)
        {
            current = current->next;
            steps--;
        }

        return current->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
