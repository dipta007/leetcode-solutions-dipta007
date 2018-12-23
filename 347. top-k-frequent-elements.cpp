class Solution:
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        mp = dict()
        for val in nums:
            if val not in mp:
                mp[val] = 0
            mp[val] += 1
            
        mpl = list(reversed(sorted(mp.items(), key=lambda x: x[1])))
        res = []
        for ind, val in enumerate(mpl):
            if ind < k:
                res.append(val[0])
        return res