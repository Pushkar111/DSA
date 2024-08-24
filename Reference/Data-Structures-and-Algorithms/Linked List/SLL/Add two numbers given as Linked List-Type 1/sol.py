# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        # base cases
        if l1==None:
            return l2
        if l2==None:
            return l1
        
        curr = ListNode(0)
        head = curr
        carry = 0
        while l1  and l2: 
            total = 0
            total += carry + l1.val + l2.val
            curr.next = ListNode(total%10)
            carry = total // 10
            curr = curr.next
            l1 = l1.next
            l2 = l2.next
            
        while (l1):
            total = 0
            total += carry + l1.val
            curr.next = ListNode(total%10)
            carry = total // 10
            curr = curr.next
            l1 = l1.next
            
        while (l2):
            total = 0
            total += carry + l2.val
            curr.next = ListNode(total%10)
            carry = total // 10
            curr = curr.next
            l2 = l2.next
         
        if carry:
            curr.next = ListNode(carry)
            
        return head.next
                
