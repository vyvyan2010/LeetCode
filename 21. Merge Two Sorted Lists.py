# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        Curl1, Curl2 = l1, l2
        Prel1 = ListNode(1)
        Prel2 = ListNode(1)
        while Curl1 and Curl2:
            while Curl1 and Curl1.val <= Curl2.val:
                Prel1 = Curl1
                Curl1 = Curl1.next
            Prel1.next = Curl2
            if not Curl1:
                break
            while Curl2 and Curl2.val <= Curl1.val:
                Prel2 = Curl2
                Curl2 = Curl2.next
            Prel2.next = Curl1
        if (not l2) or (l1 and l1.val <= l2.val):
            return l1
        else:
            return l2
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        
