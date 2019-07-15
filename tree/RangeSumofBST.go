/*********************************************************************************
*   Copyright(C)
*   FileName    :   RangeSumofBST.go
*   Author      :   VicdVud
*   Version     :   1.0.0.1
*   Date        :   2019-07-15
*   Description :   The solution of "938. Range Sum of BST".
*********************************************************************************/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func rangeSumBST(root *TreeNode, L int, R int) int {
    return helper(root, L, R)
}

func helper(node *TreeNode, L int, R int) int {
    if node == nil {
        return 0
    }
    
    if node.Val < L {
        return helper(node.Right, L, R)
    }
    
    if node.Val > R {
        return helper(node.Left, L, R)
    }
    
    return helper(node.Left, L, R) + helper(node.Right, L, R) + node.Val
}