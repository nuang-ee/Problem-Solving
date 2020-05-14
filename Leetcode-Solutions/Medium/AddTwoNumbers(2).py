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
        
        def getVal(node):
            if node is None:
                return 0
            else:
                return node.val
        
        def getNext(node):
            if node is None:
                return None
            else:
                return node.next
        
        carry = 0
        p = ans = ListNode(0)
        while True:
            newval = getVal(l1) + getVal(l2) + carry
            new_node = ListNode(newval)
            carry = new_node.val / 10
            new_node.val %= 10
            
            p.next = new_node
            p = p.next
            l1 = getNext(l1)
            l2 = getNext(l2)

            if l1 is None and l2 is None:
                if carry > 0:
                    p.next = ListNode(carry)
                break
        
        return ans.next
