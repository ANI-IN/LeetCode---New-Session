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
    int miniOperation(vector<int>&arr)
    {
        vector<int> temp=arr;
        unordered_map<int,int> m;
        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]]=i;
        }
        int ans=0;
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<arr.size();i++)
        {   
            if(arr[i]==temp[i])
                continue;
            
            int index = m[arr[i]];
            
            m[temp[i]] = index;
            
            swap(temp[index],temp[i]);
            ans++;
        }
        return ans;
    }
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode *>q;
        q.push(root);
        
        int ans=0;
        while(!q.empty())
        {
            int size=q.size();
            vector<int> temp;
            for(int i=0;i<size;i++)
            {
                TreeNode * curr= q.front();
                temp.push_back(curr->val);
                q.pop();
                
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            ans += miniOperation(temp);
        }
        
        return ans;
    }
};