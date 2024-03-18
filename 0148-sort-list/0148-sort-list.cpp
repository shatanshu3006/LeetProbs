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
ListNode*merge(ListNode*left_head,ListNode*right_head){
    //no need for extra space we have the nodes which can be easily moved to any place
    ListNode*merged_head=new ListNode(-1);
    ListNode*dummy=merged_head;
    while(left_head!=NULL && right_head!=NULL){
        if(left_head->val <=right_head->val){
            dummy->next=left_head;
            left_head=left_head->next;
        }
        else{
            dummy->next=right_head;
            right_head=right_head->next;
        }
        dummy=dummy->next;
    }
    //remaining chunk is taken as it is
    if(left_head!=NULL){
        dummy->next=left_head;
    }
    if(right_head!=NULL){
        dummy->next=right_head;
    }
    return merged_head->next;
}
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode*s=head;
        //f is head->next,allows to always split evel LL equally

// first we find the mid part by using tortoise-hare algo
        ListNode*f=head->next;
        while(f!=NULL && f->next!=NULL){
            s=s->next;
            f=f->next->next;
        }
        ListNode *mid=s;
        ListNode *left_head=head;
        ListNode *right_head=mid->next;
        //break the LL by pointing mid to NULL and declared right_head as mid->next
        mid->next=NULL;
        ListNode*l=sortList(left_head);
        ListNode*r=sortList(right_head);
        return merge(l,r);
    }
};