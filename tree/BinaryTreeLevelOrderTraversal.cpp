/*********************************************************************************
*	Copyright(C)
*	FileName    :   BinaryTreeLevelOrderTraversal.cpp
*   Author      :   VicdVud
*   Version     :   1.0.0.1
*   Date        :   2018-10-08
*   Description :   The solution of "102. Binary Tree Level Order Traversal".
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ret;
        if (!root)
        {
            return ret;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty())
        {
            int size = q.size();
            vector<int> sub_ret;
            
            for (int i = 0; i < size; ++i)
            {
                TreeNode* node = q.front();
                q.pop();
                
                sub_ret.push_back(node->val);
                
                if (node->left)
                {
                    q.push(node->left);
                }
                
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            ret.push_back(sub_ret);
        }
        return ret;
    }
};
