/*********************************************************************************
*   Copyright(C)
*   FileName    :   MaximumDepthOfN-aryTree.js
*   Author      :   VicdVud
*   Version     :   1.0.0.1
*   Date        :   2019-07-15
*   Description :   The solution of "559. Maximum Depth of N-ary Tree".
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
 * @return {number}
 */
var maxDepth = function(root) {
    if (root === null) {
        return 0
    }
    
    var depth = 0
    var q = new Array(root)
    
    while (q.length !== 0) {
        depth += 1
        
        const size = q.length
        for (let i = 0; i < size; ++i) {
            const node =  q.shift()
            
            for (const child of node.children) {
                q.push(child)
            }
        }
    }
    return depth
};