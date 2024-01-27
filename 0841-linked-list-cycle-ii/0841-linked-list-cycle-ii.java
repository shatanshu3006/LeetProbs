/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        
        if(head == null) return null;
        ListNode faster = head;
        ListNode slow = head;
        while(faster != null && faster.next != null){
            
            slow = slow.next;
            faster = faster.next.next;
            if(slow == faster){
                while(true){
                    if(slow == head) return slow;
                    slow = slow.next;
                    head = head.next;
                }
            }
        }
        
        return null;
        
    }
}