res = []
vis = []

def dfs(nums, now):
    if len(now) == len(nums):
        res.append(now[:])
        return
    
    for ind, val in enumerate(nums):
        if vis[ind] == 0:
            vis[ind] = 1
            now.append(val)
            dfs(nums, now)
            now.pop()
            vis[ind] = 0
    
    
class Solution:
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        global res
        global vis
        res = []
        vis = [0] * len(nums)
        dfs(nums, [])
        return res