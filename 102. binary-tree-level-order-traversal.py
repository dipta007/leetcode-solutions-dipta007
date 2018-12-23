# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

res = []

def call(curr, lvl):
    global res
    if curr is None:
        return
    if len(res) < lvl+1:
        res.append([])
    
    res[lvl].append(curr.val)
    call(curr.left, lvl+1)
    call(curr.right, lvl+1)

class Solution:
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        global res
        res = []
        call(root, 0)
        return res