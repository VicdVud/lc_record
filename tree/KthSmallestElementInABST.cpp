/*********************************************************************************
*	Copyright(C)
*	FileName    :   KthSmallestElementInABST.cpp
*   Author      :   VicdVud
*   Version     :   1.0.0.1
*   Date        :   2018-06-04
*   Description :   The solution of "230. Kth Smallest Element in a BST".
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
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        InOrder(root, k, res);
        return res;
    }
    
    void InOrder(TreeNode* node, int& k, int& res)
    {
        if (node == nullptr)
        {
            return;
        }
        
        InOrder(node->left, k, res);
        if (0 == --k)
        {
            res = node->val;
            return;
        }
        InOrder(node->right, k, res);
    }
};
