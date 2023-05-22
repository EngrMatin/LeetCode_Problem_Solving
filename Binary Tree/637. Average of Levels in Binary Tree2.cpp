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
        int count = 0;
        queue<TreeNode*> tempQ;

        while (!q.empty())
        {
            TreeNode* chkNode = q.front();
            q.pop();
            sum += chkNode->val;
            count++;

            if (chkNode->left != NULL)
            {
                tempQ.push(chkNode->left);
            }

            if (chkNode->right != NULL)
            {
                tempQ.push(chkNode->right);
            }
        }

        q = tempQ;
        cout<< sum/count <<" ";
        ans.push_back(sum/count);
    }

    return ans;
}
};
