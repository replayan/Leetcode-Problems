class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # o(n) inplace
        curr = head
        while curr.next:
            node = curr.next
            curr = curr.next
            while curr.next.val != 0:
                node.val += curr.next.val
                curr = curr.next
            
            curr = curr.next
            node.next = curr.next
        return head.next
