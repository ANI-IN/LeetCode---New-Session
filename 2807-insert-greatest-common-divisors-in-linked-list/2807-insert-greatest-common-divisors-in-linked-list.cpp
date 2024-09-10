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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *ans=head;
        
        while(head->next!=NULL)
        {
            ListNode *node=head;
            node=node->next;
            
            int gcd=__gcd(head->val,node->val);
            
            ListNode *curr=new ListNode(gcd);
            
            head->next=curr;
            curr->next=node;
            head=node;
        }
        return ans;
    }
};