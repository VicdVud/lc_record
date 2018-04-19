/*********************************************************************************

*	Copyright(C)
*	FileName    :   BinaryTreePruning.cpp
*   Author      :   VicdVud
*   Version     :   1.0.0.1
*   Date        :   2018-04-19
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
	TreeNode* pruneTree( TreeNode* root ) {
		if( root )
		{
			root->left = pruneTree( root->left );
			root->right = pruneTree( root->right );

			if( !root->left && !root->right && 0 == root->val )
			{
				root = NULL;
			}
		}
		return root;
	}
};