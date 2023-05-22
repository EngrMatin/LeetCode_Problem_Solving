// https://leetcode.com/problems/sum-of-left-leaves/

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
    bool checkLeaf(TreeNode *node)
    {
        if(node->left == NULL && node->right == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int sum = 0;
    void getAns(TreeNode *root)
    {
        if(root == NULL)
        {
            return;
        }

        if(root->left != NULL)
        {
            if(checkLeaf(root->left))
            {
                sum += root->left->val;

            }
            else
            {
                getAns(root->left);
            }
        }

        if(root->right != NULL)
        {
            getAns(root->right);
        }
    }

    int sumOfLeftLeaves(TreeNode* root)
    {
        getAns(root);
        return sum;
    }
};
