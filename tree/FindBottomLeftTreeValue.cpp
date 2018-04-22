/*********************************************************************************
*	Copyright(C)
*	FileName    :   FindBottomLeftTreeValue.cpp
*   Author      :   VicdVud
*   Version     :   1.0.0.1
*   Date        :   2018-04-22
*   Description :   The solution of "513.Find Bottom Left Tree Value".
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ret = root->val;
        while (!q.empty())
        {
            int size = q.size();
            ret = q.front()->val;
            for (int i = 0; i < size; ++i)
            {
                TreeNode* node = q.front();
                q.pop();
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
