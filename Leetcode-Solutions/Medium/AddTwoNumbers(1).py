# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        
        carry = False
        ans = ListNode(l1.val + l2.val)
        if ans.val >= 10:
            carry = True
            ans.val -= 10
        l1 = l1.next
        l2 = l2.next
        p = ans
        
        while l1!=None and l2!=None:
            if carry:
                newval = l1.val + l2.val +1
            else:
                newval = l1.val + l2.val
            
            new_node = ListNode(newval)
            
            carry = False
            if new_node.val >= 10:
                carry = True
                new_node.val -= 10
            
            p.next = new_node
            p = p.next
            l1 = l1.next
            l2 = l2.next
        
        while l1!=None:
            if carry:
                newval = l1.val+1
                carry = False
            else:
                newval = l1.val
            new_node = ListNode(newval)
            if new_node.val >= 10:
                carry = True
                new_node.val -= 10
            
            p.next = new_node
            p = p.next
            l1 = l1.next
        
        while l2!=None:
            if carry:
                newval = l2.val +1
                carry = False
            else:
                newval = l2.val
            new_node = ListNode(newval)
            if new_node.val >= 10:
                carry = True
                new_node.val -=10
            p.next = new_node
            p = p.next
            l2 = l2.next
            
        if carry:
            new_node = ListNode(1)
            p.next = new_node
            p = p.next
        
        return ans
