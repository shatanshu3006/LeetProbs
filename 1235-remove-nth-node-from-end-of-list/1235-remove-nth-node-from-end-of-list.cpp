/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *first;
        ListNode *second;
        ListNode *third;
        first = second = third = head;
        for (int i = 1; i < n; i++) {
            first = first->next;
        }
        while (first->next) {
            if (third != second) {
                third = third->next;
            }
            first = first->next;
            second = second->next;
        }
        third->next = second->next;
        return head;
    }
};