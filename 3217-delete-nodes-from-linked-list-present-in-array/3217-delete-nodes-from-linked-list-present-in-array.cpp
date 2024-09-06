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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode *node= new ListNode(-1);
        ListNode *ans=node;
        
        set<int> st;
        for(auto it : nums)
            st.insert(it);
        
        while(head!=NULL)
        {
            if(st.find(head->val)==st.end())
            {
                node->next=head;
                node=node->next;
            }
            head=head->next;
        }
        node->next=NULL;
        ans=ans->next;
        
        return ans;
    }
};