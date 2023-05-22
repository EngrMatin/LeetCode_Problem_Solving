// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/

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
    vector<int> ans;

    void inOrderTraversal(TreeNode* root)
    {
        if(root != NULL)
        {
            inOrderTraversal(root->left);
            ans.push_back(root->val);
            inOrderTraversal(root->right);
        }
    }

    int findSecondMinimumValue(TreeNode* root)
    {
        inOrderTraversal(root);

        sort(ans.begin(), ans.end());

        for(int i=0; i<ans.size()-1; i++)
        {
            if(ans[i] != ans[i+1])
            {
                return ans[i+1];
            }
        }
        return -1;
    }
};

