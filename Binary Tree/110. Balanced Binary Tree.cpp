// https://leetcode.com/problems/balanced-binary-tree/

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
    bool ans = true;
    int maxDepth(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }

        int x = maxDepth(root->left);
        int y = maxDepth(root->right);

        if(abs(x-y)>1)
        {
            ans = false;
        }

        return max(x, y)+1;
    }

    bool isBalanced(TreeNode* root)
    {
        int h = maxDepth(root);

        return ans;
    }
};
