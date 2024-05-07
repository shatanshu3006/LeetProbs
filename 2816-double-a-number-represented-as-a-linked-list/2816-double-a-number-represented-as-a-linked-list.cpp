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
int twiceOfVal(ListNode* head){
    if(!head){
        return 0;
    }

    //double the val at the current node and add the res of next nodes 

    int doubledValue=head->val*2 + twiceOfVal(head->next);

    //update hte current node's value with the units digit of the result
    head->val=doubledValue%10;

    //return the carry (tens of the result)
    return doubledValue/10;
}
    ListNode* doubleIt(ListNode* head) {
        int carry =twiceOfVal(head);

        //if there is a carry, insert a new node at the beginning with the carry value
        if(carry){
            head=new ListNode(carry,head);
        }
        return head;
    }
};