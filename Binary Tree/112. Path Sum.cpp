// https://leetcode.com/problems/path-sum/

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
    bool solution(TreeNode* root, int target, int currentSum)
    {
        if(root == NULL)
        {
            return false;
        }

        if(root->left == NULL && root->right == NULL)
        {
            if(currentSum + root->val == target)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        bool x= solution(root->left, target, currentSum+root->val);
        bool y= solution(root->right, target, currentSum+root->val);
        return x || y;
    }


    bool hasPathSum(TreeNode* root, int targetSum)
    {
        bool ans = solution(root, targetSum, 0);
        return ans;
    }
};
