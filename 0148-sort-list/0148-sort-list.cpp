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

//using merge sort 
//O(nlogn) ->TC
ListNode*findMiddle(ListNode*head){
    ListNode*slow=head;
    ListNode*fast=head->next;   //for taking the left middle node in case of even length list (STRIVER)

    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

ListNode*mergeTwoLists(ListNode*list1,ListNode*list2){
    //basically a code for merge two sorted lists
    ListNode*dummyNode=new ListNode(-1);
    ListNode*temp=dummyNode;

    while(list1 && list2){
        if(list1->val<list2->val){
            temp->next=list1;
            temp=list1;
            list1=list1->next;
        }
        else{
            temp->next=list2;
            temp=list2;
            list2=list2->next;
        }
    }
//if one of the lists left for traversal, then we just add it to the temp LL
    if(list1){
        temp->next=list1;
    }
    else{
        temp->next=list2;
    }

    return dummyNode->next;
}
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* middleNode=findMiddle(head);
        ListNode*left=head;
        ListNode*right=middleNode->next;
        middleNode->next=NULL;

//sort the individual halves recursively
         ListNode* leftPart=sortList(left);
         ListNode* rightPart=sortList(right);

        return mergeTwoLists(leftPart,rightPart);
    }
};