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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;//left most node
        ListNode* curr=head;//curr to traverse
        ListNode* nex;//next to curr
        while(curr){
            nex=curr->next;  // next is current's next.
            curr->next=prev; // relinking to previous node (curr's next is prev)
            prev=curr;// moving prev to curr's position
            curr=nex; // moving curr to next's position to move ahead in first iteration.
        }
        return prev; //return the pointer with head
    }
};