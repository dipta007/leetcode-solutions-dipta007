# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

res = None
count = 0
def findd(root, k):
    if root == None:
        return
    findd(root.left, k)
    global count
    if count == k-1:
        global res
        res = root.val
    count += 1
    findd(root.right, k)

class Solution:
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        global count
        count = 0
        findd(root, k)
        print(res)
        return res