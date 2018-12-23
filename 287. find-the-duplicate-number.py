class Solution:
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        low = 1
        high = len(nums)-1
        
        while low < high:
            mid = (low + high) // 2
            
            print(low, mid, high)
            
            cnt = 0
            for val in nums:
                if val <= mid:
                    cnt += 1
            
            if cnt > mid:
                high = mid
            else:
                low = mid+1
                
        return low