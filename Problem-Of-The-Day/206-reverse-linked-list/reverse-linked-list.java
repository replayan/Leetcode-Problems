class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode r = null;
        for (; head != null;) {
            ListNode temp = head;
            head = head.next;
            temp.next = r;
            r = temp;
        }
        return r;
    }
}