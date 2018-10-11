/*********************************************************************************
*	Copyright(C)
*	FileName    :   UniqueBinarySearchTrees.cpp
*   Author      :   VicdVud
*   Version     :   1.0.0.1
*   Date        :   2018-10-11
*   Description :   The solution of "96. Unique Binary Search Trees".
                    Use DP.
*********************************************************************************/

class Solution {
public:
    int numTrees(int n) {
        int* nt = new int[n+1];
        nt[0] = nt[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            nt[i] = 0;
            for (int j = 1; j <= i; ++j)
            {
                nt[i] += nt[j-1] * nt[i-j];
            }
        }
        
        return nt[n];
    }
};