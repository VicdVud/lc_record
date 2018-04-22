/*********************************************************************************
*	  Copyright(C)
*	  FileName    :   BinaryTreePruning.cpp
*   Author      :   VicdVud
*   Version     :   1.0.0.1
*   Date        :   2018-04-22
*   Description :   The solution of "654.Maximum Binary Tree".
                    This problem is about the construction of Cartesian Tree.
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> v;
        for (int i = 0; i < nums.size(); ++i)
        {
            TreeNode* cur = new TreeNode(nums[i]);
            while (!v.empty() && v.back()->val < nums[i])
            {
                cur->left = v.back();
                v.pop_back();
            }
            if (!v.empty())
            {
                v.back()->right = cur;
            }
            v.push_back(cur);
        }
        return v.front();
    }
};
