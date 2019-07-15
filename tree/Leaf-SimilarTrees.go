/*********************************************************************************
*   Copyright(C)
*   FileName    :   Leaf-SimilarTrees.go
*   Author      :   VicdVud
*   Version     :   1.0.0.1
*   Date        :   2019-07-15
*   Description :   The solution of "872. Leaf-Similar Trees".
*********************************************************************************/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
    var leafSequenceOne, leafSequenceTwo []int
    GetLeafSequence(root1, &leafSequenceOne)
    GetLeafSequence(root2, &leafSequenceTwo)
    return CompareSlice(leafSequenceOne, leafSequenceTwo)
}

func GetLeafSequence(node *TreeNode, leafSequence *[]int) {
    if node == nil {
        return
    }
    
    GetLeafSequence(node.Left, leafSequence)
    
    if node.Left == nil && node.Right == nil {
        *leafSequence = append(*leafSequence, node.Val)
    }
    
    GetLeafSequence(node.Right, leafSequence)
}

func CompareSlice(sliceOne []int, sliceTwo []int) bool {
    if len(sliceOne) != len(sliceTwo) {
        return false
    }
    
    for i := 0; i < len(sliceOne); i++ {
        if sliceOne[i] != sliceTwo[i] {
            return false
        }
    }
    return true
}