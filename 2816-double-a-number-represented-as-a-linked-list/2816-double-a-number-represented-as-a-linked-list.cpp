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
    ListNode* doubleIt(ListNode* head) {
        ListNode*p2=head;
        ListNode*ans=new ListNode(0);
        ListNode*p1=ans;
        ans->next=head;

        while(p2!=NULL){
            int cal=(p2->val)*2;
            p2->val=cal%10;
            p1->val+=(cal/10);

            p2=p2->next;
            p1=p1->next;
        }
        if(ans->val != 0)
        return ans;
        else 
        return ans->next;
    }
};