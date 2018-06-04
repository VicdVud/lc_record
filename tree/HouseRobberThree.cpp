/*********************************************************************************
*	Copyright(C)
*	FileName    :   HouseRobberThree.cpp
*   Author      :   VicdVud
*   Version     :   1.0.0.1
*   Date        :   2018-06-04
*   Description :   The solution of "337. House Robber Three".
					Use DP.
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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> m;
        return Helper(root, m);
    }
    
    int Helper(TreeNode* node, unordered_map<TreeNode*, int>& m)
    {
        if (node == nullptr)
        {
            return 0;
        }
        
        auto it = m.find(node);
        if (it != m.end())
        {
            return it->second;
        }
        
        int sum = 0;
        if (node->left)
        {
            sum += Helper(node->left->left, m) + Helper(node->left->right, m);
        }
        
        if (node->right)
        {
            sum += Helper(node->right->left, m) + Helper(node->right->right, m);
        }
        
        sum = max(sum + node->val, Helper(node->left, m) + Helper(node->right, m));
        
        m[node] = sum;
        return sum;
    }
};
