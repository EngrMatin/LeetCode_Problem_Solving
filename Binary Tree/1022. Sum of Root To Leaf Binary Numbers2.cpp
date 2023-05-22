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
    int sum=0;
    void preorder(TreeNode* head, int n)
    {
        if(head != NULL)
        {
            n = (n<<1) | head->val;

            if(head->left==NULL && head->right==NULL)
            {
                sum += n;
            }

            preorder(head->left, n);
            preorder(head->right, n);
        }
    }

    int sumRootToLeaf(TreeNode* root)
    {
        preorder(root, 0);
        return sum;
    }
};


