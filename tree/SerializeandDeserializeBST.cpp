/*********************************************************************************
*	Copyright(C)
*	FileName    :   SerializeandDeserializeBST.cpp
*   Author      :   VicdVud
*   Version     :   1.0.0.1
*   Date        :   2018-10-09
*   Description :   The solution of "449. Serialize and Deserialize BST".
                    Use BFS.
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        if (!root)
        {
            return ret;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode* node = q.front();
                q.pop();
                
                ret += Int2String(node->val) + ",";
                
                if (node->left)
                {
                    q.push(node->left);
                }
                
                if (node->right)
                {
                    q.push(node->right);
                }
            }
        }
        
        if (!ret.empty())
        {
            ret.pop_back();
        }
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // Split data
        vector<int> numbers = SplitString(data);
        
        TreeNode* root = NULL;
        for (int i = 0; i < numbers.size(); ++i)
        {
            if (i == 0)
            {
                // Root node
                root = new TreeNode(numbers[i]);
            }
            else
            {
                // Other node
                InsertBST(root, numbers[i]);
            }
        }
        
        return root;
    }
    
private:
    string Int2String(int val)
    {
        char c[8];
        sprintf(c, "%d", val);
        return c;
    }
    
    vector<int> SplitString(const string& str)
    {
        vector<int> numbers;
        
        string word;
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] != ',')
            {
                word += str[i];
            }
            else
            {
                int num = atoi(word.c_str());
                numbers.push_back(num);
                word.clear();
            }
        }
        
        if (!word.empty())
        {
            // Add last number
            int num = atoi(word.c_str());
            numbers.push_back(num);
        }
        
        return numbers;
    }
    
    void InsertBST(TreeNode* root, int val)
    {
        if (root->val > val)
        {
            // Insert left
            TreeNode* node = root->left;
            if (!node)
            {
                node = new TreeNode(val);
                root->left = node;
            }
            else
            {
                InsertBST(root->left, val);
            }
        }
        else
        {
            // Insert right
            TreeNode* node = root->right;
            if (!node)
            {
                node = new TreeNode(val);
                root->right = node;
            }
            else
            {
                InsertBST(root->right, val);
            }
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));