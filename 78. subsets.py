class Solution:
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        lim = (1 << len(nums))
        for mask in range(lim):
            tmp = []
            for i in range(len(nums)):
                def check(n, ind):
                    return (((1 << ind) & n) > 0)
                
                if check(mask, i):
                    tmp.append(nums[i])
            res.append(tmp)
        return res