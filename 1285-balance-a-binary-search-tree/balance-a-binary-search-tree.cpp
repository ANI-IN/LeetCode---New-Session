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
    void solve(TreeNode *root, vector<int>&sorted)
    {
        if(root==NULL)
        return;

        solve(root->left,sorted);
        sorted.push_back(root->val);
        solve(root->right,sorted);
    }

    TreeNode* solve1(vector<int>&sorted, int l, int r)
    {   
        if(l>r)
        return NULL;

        int mid = l + (r-l)/2;
        TreeNode *node = new TreeNode(sorted[mid]);
        node->left=solve1(sorted,l,mid-1);
        node->right=solve1(sorted,mid+1,r);

        return node;

    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sorted;
        solve(root,sorted);
        int l=0,r=sorted.size()-1;
        return solve1(sorted,l,r);
    }
};