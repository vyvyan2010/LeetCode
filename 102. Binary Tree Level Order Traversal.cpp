/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
		vector<int> temp;
        queue<TreeNode*> q;
        
        if(NULL != root)
        {
            q.push(root);
        }
        
        for(int level = 0; !q.empty(); level++)
        {
            size_t size = q.size();
            for(size_t i = 0; i < size; i++)
            {
                TreeNode* tempPtr = q.front();
                q.pop();
				result.resize(level+1);
                result[level].push_back(tempPtr->val);
                if(NULL != tempPtr->left)
                {
                    q.push(tempPtr->left);
                }
                if(NULL != tempPtr->right)
                {
                    q.push(tempPtr->right);
                }                
            }
        }
        
        return result;
    }
};
