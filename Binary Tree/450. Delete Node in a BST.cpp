// https://leetcode.com/problems/delete-node-in-a-bst/

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
    TreeNode* inOrderSuccessor(TreeNode* root)
    {
        TreeNode* currentNode = root;

        while(currentNode->left != NULL)
        {
            currentNode = currentNode->left;
        }

        return currentNode;
    }

    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if(root == NULL)
        {
            return root;
        }

        if(key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if(root->left == NULL)
            {
                TreeNode* temp = root->right;
                delete root;
                root = temp;
            }
            else if(root->right == NULL)
            {
                TreeNode* temp = root->left;
                delete root;
                root = temp;
            }
            else
            {
                TreeNode* temp = inOrderSuccessor(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }

        return root;
    }
};


