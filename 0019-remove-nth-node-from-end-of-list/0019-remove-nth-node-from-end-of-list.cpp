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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr=head;
        int ct=0;
        while(curr!=NULL){
            ct++;
            curr=curr->next;
        }
        int c=ct-n+1;
        ListNode* prev=NULL;
        curr=head;
        int ck=0;
        while(ck!=c-1){
            prev=curr;
            curr=curr->next;
            ck++;
        }
        if(prev==NULL){
            head=head->next;
            return head;
        }
        prev->next=curr->next;
        return head;
    }
};