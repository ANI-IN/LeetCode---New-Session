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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=0;
        ListNode*curr=head;
        while(curr)
        {
            len++;
            curr=curr->next;
        }
        
        int batch=len/k;
        int extra=len%k;
        
        vector<ListNode *> ans(k,NULL);
        curr=head;
        ListNode *prev=NULL;
        
        for(int i=0 ; curr && i< k ; i++)
        {
            ans[i]=curr;
            
            int size = batch + ((extra>0)?1:0);
            
            
            for(int count = 1 ; count <= size ; count++ )
            {
                prev=curr;
                curr=curr->next;
            }
            
            if(prev!=NULL)
            prev->next=NULL;
            extra--;
        }
        return ans;
    }
};