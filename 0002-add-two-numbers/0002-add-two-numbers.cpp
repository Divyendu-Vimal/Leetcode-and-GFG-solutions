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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int ct=0;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* newnode=new ListNode(0);
        ListNode* head=newnode;
        while(temp1!=NULL && temp2!=NULL){
            int kk=(temp1->val)+(temp2->val)+ct;
            newnode->next=new ListNode(kk%10);
            ct=kk/10;
            newnode=newnode->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1!=NULL){
            int kk=(temp1->val)+ct;
            newnode->next=new ListNode(kk%10);
            ct=kk/10;
            newnode=newnode->next;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            int kk=(temp2->val)+ct;
            newnode->next=new ListNode(kk%10);
            ct=kk/10;
            newnode=newnode->next;
            temp2=temp2->next;
        }
        if(ct!=0){
            newnode->next=new ListNode(ct);
        }
        return head->next;
    }
};