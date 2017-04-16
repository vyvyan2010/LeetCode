# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def preorderTraversal(self, root):
        stack = []
        ans = []
        times = {}
        TempNode = root
        
        while TempNode != None:
            stack.append(TempNode)
            times[TempNode] = False
            TempNode = TempNode.right
        
        while len(stack) != 0:
            CurNode = stack[-1]
            if CurNode.left == None or times[CurNode] == True:
                stack.pop(-1)
                times.pop(CurNode)
                ans.append(CurNode.val)
                continue

            times[CurNode] = True
            TempNode = CurNode.left
            while TempNode != None:
                stack.append(TempNode)
                times[TempNode] = False
                TempNode = TempNode.right                
        
        return ans[::-1]
            
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        