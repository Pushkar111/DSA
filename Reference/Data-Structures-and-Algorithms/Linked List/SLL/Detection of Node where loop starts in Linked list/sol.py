# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        if head==None or head.next==None:
            return None
        
        # Floyd's cycle finding algo to find the node where slow and fast pointers meet
        slow=head
        fast=head
        
        while fast and fast.next:
            fast=fast.next.next
            slow=slow.next
            
            if fast==slow: # Now fast and slow both points at same node in cycle
                break
                
        temp=head # instead of temp, we can also do with head pointer as well
        if fast==slow:
            # we increment temp and fast by one at each iteration and they will meet at the node where loop starts
            while fast != temp:
                fast = fast.next
                temp = temp.next
            return temp
        else:
            return None
        
