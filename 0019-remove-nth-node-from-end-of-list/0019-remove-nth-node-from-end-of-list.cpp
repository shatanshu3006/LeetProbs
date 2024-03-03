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
        int length=0;
        ListNode*curr=head;

        //find the length of the linked list
        while(curr!=NULL){
            length++;
            curr=curr->next;
        }
        //find the position to remove
        int traverseTill=length-n-1;
        int i=0;
        curr=head; //reset the curr pointer to head again

        //if the head needs to be removed
        if(traverseTill==-1){
            head=head->next;
            delete curr;
            return head;
        }

        //traverse the node before the one to be removed
        while(i<traverseTill){
            curr=curr->next;
            i++;
        }

        //removing the nth node
        ListNode*temp=curr->next;
        //change the connections
        curr->next=curr->next->next;
        //delete the temporary pointer
        delete temp;

        return head;
    }
};