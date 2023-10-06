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
    ListNode* reversenode(ListNode* head){
        if(head->next==NULL){
            return head;
        }
        ListNode* nhead=head->next;
        ListNode* prev=head;
        ListNode* pprev=NULL;
        while(prev!=NULL){
            prev->next=pprev;
            pprev=prev;
            prev=nhead;
            if(nhead!=NULL){
                nhead=nhead->next;
            }
        }
        return pprev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* nhead=reversenode(head);
        ListNode* temp=nhead;
        int ct=0;
        ListNode* prev=temp;
        while(temp!=NULL){
            int k=((temp->val*2)+ct);
            temp->val=k%10;
            ct=k/10;
            prev=temp;
            temp=temp->next;
        }
        if(ct!=0){
            ListNode* newnode=new ListNode(ct);
            prev->next=newnode;
        }
        nhead=reversenode(nhead);
        return nhead;
    }
};