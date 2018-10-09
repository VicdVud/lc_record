/*********************************************************************************
*	Copyright(C)
*	FileName    :   BinaryTreeRightSideView.cpp
*   Author      :   VicdVud
*   Version     :   1.0.0.1
*   Date        :   2018-10-09
*   Description :   The solution of "199. Binary Tree Right Side View".
                    Use BFS.
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if (!root)
        {
            return ret;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode* node = q.front();
                q.pop();
                
                if (i + 1 == size)
                {
                    ret.push_back(node->val);
                }
                
                if (node->left)
                {
                    q.push(node->left);
                }
                
                if (node->right)
                {
                    q.push(node->right);
                }
            }
        }
        
        return ret;
    }
};