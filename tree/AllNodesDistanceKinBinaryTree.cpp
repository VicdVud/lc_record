/*********************************************************************************
*	Copyright(C)
*	FileName    :   AllNodesDistanceKinBinaryTree.cpp
*   Author      :   VicdVud
*   Version     :   1.0.0.1
*   Date        :   2018-10-11
*   Description :   The solution of "863. All Nodes Distance K in Binary Tree".
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<TreeNode*> tns;
        
        // Find list from root to target
        PreOrderFinder(root, target, tns);
        tns.push_back(root);
        
        vector<int> ret;
        
        for (int i = 0; i < tns.size(); ++i)
        {
            int n = K - i;
            if (n == 0)
            {
                SearchK(tns[i], NULL, n, ret);
            }
            else
            {
                SearchK(tns[i], tns[i-1], n, ret);
            }
        }
        
        return ret;
    }
    
private:
    TreeNode* PreOrderFinder(TreeNode* from, TreeNode* target, vector<TreeNode*>& tns)
    {
        if (from == target)
        {
            return from;
        }
        else
        {
            TreeNode* finder = NULL;
            if (from->left)
            {
                finder = PreOrderFinder(from->left, target, tns);
                if (finder)
                {
                    tns.push_back(finder);
                    return from;
                }
            }
            
            if (from->right)
            {
                finder = PreOrderFinder(from->right, target, tns);
                if (finder)
                {
                    tns.push_back(finder);
                    return from;
                }
            }
        }
        
        return NULL;
    }
    
    void SearchK(TreeNode* node, TreeNode* prev_node, int K, vector<int>& ret)
    {
        if (K == 0)
        {
            ret.push_back(node->val);
        }
        else
        {
            --K;
            if (node->left && node->left != prev_node)
            {
                SearchK(node->left, node->right, K, ret);
            }
            
            if (node->right && node->right != prev_node)
            {
                SearchK(node->right, node->left, K, ret);
            }
        }
    }
};