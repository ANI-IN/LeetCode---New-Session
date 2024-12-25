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
    void solve(TreeNode *root, int depth,unordered_map<int,int>&m)
    {
        if(root==NULL)
            return;
        
         if(m.find(depth)==m.end())
         {
             m[depth] = root->val;
         }
         else
         {
             m[depth] = max(m[depth] , root->val);
         }
            
            
            solve(root->left,depth+1,m);
            solve(root->right,depth+1,m);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        unordered_map<int,int> m;
        int depth=0;
        
        solve(root,depth,m);
        
        
        vector<int> ans(m.size());
        for(int i=0;i<m.size();i++)
        {
            int val = m[i];
            ans[i]=val;
        }
        return ans;
    }
};