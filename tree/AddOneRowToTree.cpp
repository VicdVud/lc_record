/*********************************************************************************
*	Copyright(C)
*	FileName    :   AddOneRowToTree.cpp
*   Author      :   VicdVud
*   Version     :   1.0.0.1
*   Date        :   2018-06-03
*   Description :   The solution of "623. Add One Row to Tree".
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1)
        {
            TreeNode* new_node = new TreeNode(v);
            new_node->left = root;
            return new_node;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        int dep = 2;
        
        while (!q.empty())
        {
            int size = q.size();
            
            for (int i = 0; i < size; ++i)
            {
                
                TreeNode* node = q.front();
                q.pop();
                
                if (dep == d)
                {
                    TreeNode* new_left = new TreeNode(v);
                    new_left->left = node->left;
                    node->left = new_left;
                    
                    TreeNode* new_right = new TreeNode(v);
                    new_right->right = node->right;
                    node->right = new_right;
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
            
            if (dep == d)
            {
                break;
            }
            ++dep;
        }
        return root;
    }
};
