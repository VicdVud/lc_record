/*********************************************************************************
*   Copyright(C)
*   FileName    :   SearchInABinarySearchTree.go
*   Author      :   VicdVud
*   Version     :   1.0.0.1
*   Date        :   2019-07-15
*   Description :   The solution of "700. Search in a Binary Search Tree".
*********************************************************************************/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func searchBST(root *TreeNode, val int) *TreeNode {
    return helper(root, val)
}

func helper(node* TreeNode, val int) *TreeNode {
    if node == nil {
        return nil
    }
    
    if node.Val == val {
        return node
    }
    
    if node.Val > val {
        return helper(node.Left, val)
    }
    
    return helper(node.Right, val)
}