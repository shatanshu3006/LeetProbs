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
ListNode* merge (ListNode* l1,ListNode* l2){
    if(l1==NULL){
        return l2;
    }
    if(l2==NULL){
        return l1;
    }
    if(l1->val<l2->val){        //comparing the front values
        l1->next=merge(l1->next,l2);  //moving to the next value and merging again
        return l1;  //since the change has been made in l1, we return l1
    }
    else{
        l2->next=merge(l2->next,l1);
        return l2;
    }
}
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return merge(list1,list2);
    }
};