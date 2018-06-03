/*********************************************************************************
*	Copyright(C)
*	FileName    :   FindLargestValueInEachTreeRow.cpp
*   Author      :   VicdVud
*   Version     :   1.0.0.1
*   Date        :   2018-06-03
*   Description :   The solution of "515. Find Largest Value in Each Tree Row".
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        
        if (root == nullptr)
        {
            return res;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty())
        {
            int max_num = INT_MIN;
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode* n = q.front();
                q.pop();
                if (n->left)
                {
                    q.push(n->left);
                }
                if (n->right)
                {
                    q.push(n->right);
                }
                max_num = max(max_num, n->val);
            }
            res.push_back(max_num);
        }
        return res;
    }
};
