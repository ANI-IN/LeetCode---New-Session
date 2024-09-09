/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        
        int left=0,right=n-1;
        int top=0,bot=m-1;
        
        while(head!=NULL)
        {
            for(int i=left; i<=right && head!=NULL ;i++)
            {
                int value=head->val;
                ans[top][i]=value;
                head=head->next;
            }
            
            for(int j=top+1 ; j<=bot && head!=NULL ; j++)
            {
                int value=head->val;
                ans[j][right]=value;
                head=head->next;
            }
            
            for(int i=right-1; i>=left && head!=NULL; i--)
            {
                int value=head->val;
                ans[bot][i]=value;
                head=head->next;
            }
            
            for(int j=bot-1 ; j>=top+1 && head!=NULL ; j--)
            {
                int value=head->val;
                ans[j][left]=value;
                head=head->next;
            }
            
            
            left++;
            right--;
            top++;
            bot--;
        }
        return ans;
    }
};