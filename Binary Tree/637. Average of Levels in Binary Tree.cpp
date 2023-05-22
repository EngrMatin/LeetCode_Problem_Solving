// https://leetcode.com/problems/average-of-levels-in-binary-tree/

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
    vector<double> averageOfLevels(TreeNode* root)
    {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            double sum = 0.00;
            int preSize = q.size();

            for(int i=0; i<preSize; i++)
            {
                TreeNode* chkNode = q.front();
                q.pop();
                sum += chkNode->val;

                if (chkNode->left != NULL)
                {
                    q.push(chkNode->left);
                }

                if (chkNode->right != NULL)
                {
                    q.push(chkNode->right);
                }
            }

            ans.push_back(sum/preSize);
        }

        return ans;
    }
};

