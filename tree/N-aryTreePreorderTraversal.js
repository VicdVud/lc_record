/*********************************************************************************
*   Copyright(C)
*   FileName    :   N-aryTreePreorderTraversal.js
*   Author      :   VicdVud
*   Version     :   1.0.0.1
*   Date        :   2019-07-15
*   Description :   The solution of "589. N-ary Tree Preorder Traversal".
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
 * @return {number[]}
 */
var preorder = function(root) {
    var res = []
    helper(root, res)
    return res
};

function helper(node, res) {
    if (node === null) {
        return
    }
    
    res.push(node.val)
    
    for (const child of node.children) {
        helper(child, res)
    }
}