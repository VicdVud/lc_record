/*********************************************************************************
*	Copyright(C)
*	FileName    :   BinarySearchTreeIterator.cpp
*   Author      :   VicdVud
*   Version     :   1.0.0.1
*   Date        :   2018-10-08
*   Description :   The solution of "173. Binary Search Tree Iterator".
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
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        addLeft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s_.empty();
    }

    /** @return the next smallest number */
    int next() {
        if (s_.empty())
        {
            return -1;
        }

        TreeNode* node = s_.top();
        s_.pop();

        int ret = node->val;
        addLeft(node->right);

        return ret;
    }

private:
    void addLeft(TreeNode* node)
    {
        while (node)
        {
            s_.push(node);
            node = node->left;
        }
    }

private:
    stack<TreeNode*> s_;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
