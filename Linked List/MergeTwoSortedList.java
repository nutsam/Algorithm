/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
// iterative
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1 == null) return l2;
        if(l2 == null) return l1;
        ListNode head = new ListNode(-1);
        ListNode dummy = head;
        
        while(l1 != null && l2 != null){
            if(l1.val >= l2.val){
                head.next = l2;
                l2 = l2.next;
            }
            else{
                head.next = l1;
                l1 = l1.next;
            }
            head = head.next;
        }

        head.next = l1 == null ? l2 : l1;
        
        return dummy.next;
    }
}


// recursive
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1 == null || l2 == null){
            return l1 == null ? l2 : l1;
        }
        
        if(l1.val > l2.val){
            l2.next = mergeTwoLists(l1, l2.next);    
            return l2;
        }
        else{
            l1.next = mergeTwoLists(l1.next, l2);
            return l1;
        }
    }
}