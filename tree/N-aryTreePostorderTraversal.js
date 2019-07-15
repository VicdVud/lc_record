/*********************************************************************************
*   Copyright(C)
*   FileName    :   N-aryTreePostorderTraversal.js
*   Author      :   VicdVud
*   Version     :   1.0.0.1
*   Date        :   2019-07-15
*   Description :   The solution of "590. N-ary Tree Postorder Traversal".
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
var postorder = function(root) {
    var res = []
    
    var helper = function(node, res) {
        if (node === null) {
            return
        }

        for (const child of node.children) {
            helper(child, res)
        }
        res.push(node.val)
    }

    helper(root, res)
    return res
};