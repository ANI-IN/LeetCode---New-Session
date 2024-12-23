/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   void solve(TreeNode *root, vector <int> &sol)
    {
        if(root==NULL)
            return;
        solve(root->left,sol);
        
        solve(root->right,sol);
       sol.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector <int> sol;
        solve(root,sol);
        return sol;
    }
};