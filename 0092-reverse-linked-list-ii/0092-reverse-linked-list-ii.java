class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        if (left == right) {
            return head;
        } 
        ListNode preHead = null;
        ListNode pre = head;
        for (int i = 0; pre != null && i < left - 1; ++i) {
            preHead = pre;
            pre = pre.next;
        }
        ListNode newEnd = pre;
        ListNode prev = null;
        ListNode next = pre.next;
        for (int i = 0; pre != null && i < right - left + 1; ++i) {
            pre.next = prev;
            prev = pre;
            pre = next;
            if (next != null) {
                next = next.next;
            }
        }   
        if (preHead != null) {
            preHead.next = prev;
        } else {
            head = prev;
        }
        newEnd.next = pre;
        return head;
    }
}
