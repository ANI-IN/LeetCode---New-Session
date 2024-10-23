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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> sum;
        if(root==NULL)
            return NULL;
        queue<TreeNode * > q;
        
        q.push(root);
        
        while(!q.empty())
        {
            int level_sum=0;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode *node=q.front();
                q.pop();
                level_sum+=node->val;
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            sum.push_back(level_sum);
        }
        
        q.push(root);
        root->val=0;
        int index=1;
        while(!q.empty())
        {
            int n=q.size();
            
            for(int i=0;i<n;i++)
            {
                TreeNode *node=q.front();
                q.pop();
                
                int s=node->left!=NULL ? node->left->val:0;
                 s+=node->right!=NULL ? node->right->val:0;
                
                
                
                if(node->left)
                {
                    node->left->val=sum[index] - s;
                    q.push(node->left);
                }
                
                if(node->right)
                {
                    node->right->val=sum[index] - s;
                    q.push(node->right);
                }
            }
            index++;
        }
        return root;
    }
};