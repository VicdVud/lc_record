/*********************************************************************************
*	  Copyright(C)
*	  FileName    :   BinaryTreeInorderTraversal.cpp
*   Author      :   VicdVud
*   Version     :   1.0.0.1
*   Date        :   2018-06-03
*   Description :   The solution of "94.Binary Tree Inorder Traversal".
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        InOrder(root, ret);
        return ret;
    }
    
    void InOrder(TreeNode* node, vector<int>& ret)
    {
        if (node == nullptr)
        {
            return;
        }
        
        InOrder(node->left, ret);
        ret.push_back(node->val);
        InOrder(node->right, ret);
    }
};
