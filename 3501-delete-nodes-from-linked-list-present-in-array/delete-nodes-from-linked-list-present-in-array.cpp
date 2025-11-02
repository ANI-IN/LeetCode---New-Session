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
        unordered_map<int,int> m;
        for(auto it : nums)
        {
            m[it]++;
        }

        ListNode *ans = new ListNode (-1);
        ListNode *temp = ans;

        while(head!=NULL)
        {
            int val = head->val;
            if(m.find(val)==m.end())
            {   
                 temp->next = new ListNode(val);
                 temp=temp->next;
            }

            head=head->next;
        }
        return ans->next;
    }
};