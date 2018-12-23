class Solution:
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ltr = [None] * len(nums)
        rtl = [None] * len(nums)
        for ind, val in enumerate(nums):
            if ind == 0:
                ltr[ind] = val
            else:
                ltr[ind] = ltr[ind-1] * val
                
        
        for ind in range(len(nums)-1, -1, -1):
            val = nums[ind]
            
            if ind == len(nums) - 1:
                rtl[ind] = val
            else:
                rtl[ind] = rtl[ind+1] * val
                
        res = [None] * len(nums)
        for i in range(len(nums)):
            left = 0
            right = 0
            if i == 0:
                left = 1
                right = rtl[i+1]
            elif i == len(nums)-1:
                left = ltr[i-1];
                right = 1
            else:
                left = ltr[i-1]
                right = rtl[i+1]
            res[i] = left * right
            
        return res