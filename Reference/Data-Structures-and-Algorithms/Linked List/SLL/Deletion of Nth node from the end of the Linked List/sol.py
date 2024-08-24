# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        
        slow = head # it finally points to the previous node of the target node
        fast = head # it finally points to the last node
        
        for i in range(n): # let the fast pointer move n steps ahead of the slow pointer
            fast = fast.next
        
        # This situation would happen when we are required to del the first node(n=len(List))
        # Also, it can handle the [] case
        if fast==None:
            return slow.next
        
        while fast.next:
            fast=fast.next
            slow=slow.next
            
        slow.next=slow.next.next
        
        return head
        
   
