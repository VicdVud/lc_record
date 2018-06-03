/*********************************************************************************
*	  Copyright(C)
*	  FileName    :   BinaryTreePruning.cpp
*   Author      :   VicdVud
*   Version     :   1.0.0.1
*   Date        :   2018-06-03
*   Description :   The solution of BinaryTreePruning
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int, int> m;
        int max_times = -1;
        PostOrder(root, m, max_times);
        
        vector<int> res;
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            if (it->second == max_times)
            {
                res.push_back(it->first);
            }
        }
        return res;
    }
    
    int PostOrder(TreeNode* node, map<int, int>& m, int& max_times)
    {
        if (!node)
        {
            return 0;
        }
        
        int left_sum = 0, right_sum = 0;
        if (node->left)
        {
            left_sum = PostOrder(node->left, m, max_times);
        }
        if (node->right)
        {
            right_sum = PostOrder(node->right, m, max_times);
        }
        
        int sum = node->val + left_sum + right_sum;
        m[sum] += 1;
        max_times = max(max_times, m[sum]);
        return sum;
    }
};
