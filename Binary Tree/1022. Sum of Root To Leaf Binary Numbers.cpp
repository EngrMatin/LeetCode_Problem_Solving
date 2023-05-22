// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

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
    int total = 0;

    void sumBinary(TreeNode* head, int sum)
    {
        if(head==NULL)
        {
            return;
        }

        sum = sum * 2 + head->val;

        if(head->left==NULL && head->right==NULL)
        {
            total += sum;
            return;
        }

        sumBinary(head->left, sum);
        sumBinary(head->right, sum);
    }

    int sumRootToLeaf(TreeNode* root)
    {
        sumBinary(root, 0);
        return total;
    }
};

