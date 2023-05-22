// https://leetcode.com/problems/cousins-in-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
public:
    bool isCousins(TreeNode* root, int x, int y)
    {
        queue<TreeNode *> q;
        q.push(root);

        while(q.size())
        {
            int n = q.size();
            bool isX = false, isY = false;

            for(int i=0; i<n; i++)
            {
                TreeNode* temp = q.front();
                q.pop();

                if(temp->val == x)
                {
                    isX = true;
                }
                if(temp->val == y)
                {
                    isY = true;
                }

                if(temp->left && temp->right)
                {
                    if((temp->left->val == x && temp->right->val == y) ||
                       (temp->left->val == y && temp->right->val == x))
                    {
                        return false;
                    }
                }

                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }

            if(isX && isY)
            {
                return true;
            }
        }

        return false;
    }
};
