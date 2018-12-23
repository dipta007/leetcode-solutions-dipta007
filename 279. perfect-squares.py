dp = [-1] * 100000
def call(n):
    if n == 0:
        return 0
    if dp[n] != -1:
        return dp[n]

    dp[n] = 100000
    for i in range(100000):
        now = i * i
        if now > n:
            break
        dp[n] = min(dp[n], 1 + call(n-now));

    return dp[n]

class Solution:
        
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        return call(n)