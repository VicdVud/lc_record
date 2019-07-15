/*********************************************************************************
*   Copyright(C)
*   FileName    :   IncreasingOrderSearchTree.go
*   Author      :   VicdVud
*   Version     :   1.0.0.1
*   Date        :   2019-07-15
*   Description :   The solution of "897. Increasing Order Search Tree".
*********************************************************************************/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func increasingBST(root *TreeNode) *TreeNode {
    if root == nil {
        return nil
    }
    
    if root.Left == nil && root.Right == nil {
        return root
    }
    
    var nodeList = []*TreeNode{}
    helper(root, &nodeList)
    
    count := len(nodeList)
    nodeList[count-1].Left = nil
    nodeList[count-1].Right = nil
    
    for i := count - 2; i >= 0; i-- {
        nodeList[i].Left = nil
        nodeList[i].Right = nodeList[i+1]
    }
    return nodeList[0]
}

func helper(node *TreeNode, nodeList *[]*TreeNode) {
    if node == nil {
        return
    }
    
    helper(node.Left, nodeList)
    *nodeList = append(*nodeList, node)
    helper(node.Right, nodeList)
}