/*********************************************************************************
*	Copyright(C)
*	FileName    :   BinaryTreePreorderTraversal.cpp
*   Author      :   VicdVud
*   Version     :   1.0.0.1
*   Date        :   2018-06-03
*   Description :   The solution of "144. Binary Tree Preorder Traversal".
*********************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        PreOrder(root, ret);
        return ret;
    }
    
    void PreOrder(TreeNode* node, vector<int>& ret)
    {
        if (!node)
        {
            return;
        }
        
        ret.push_back(node->val);
        
        PreOrder(node->left, ret);
        PreOrder(node->right, ret);
    }
};