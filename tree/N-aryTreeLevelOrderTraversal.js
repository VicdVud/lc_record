/*********************************************************************************
*   Copyright(C)
*   FileName    :   N-aryTreeLevelOrderTraversal-aryTree.js
*   Author      :   VicdVud
*   Version     :   1.0.0.1
*   Date        :   2019-07-15
*   Description :   The solution of "429. N-ary Tree Level Order Traversal".
*********************************************************************************/

/**
 * // Definition for a Node.
 * function Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */
/**
 * @param {Node} root
 * @return {number[][]}
 */
var levelOrder = function(root) {
    if (root == null) {
        return []
    }

    let res = []
    let q = [root]
    
    res.push([root.val])
    
    while (q.length !== 0) {
        let sub = []

        const size = q.length
        for (let i = 0; i < size; ++i) {
            const node =  q.shift()

            for (const child of node.children) {
                q.push(child)
                sub.push(child.val)
            }
        }
        
        if (sub.length > 0) {
            res.push(sub)
        }
    }
    return res
};