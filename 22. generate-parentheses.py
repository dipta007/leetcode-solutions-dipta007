def call(pos, bp, bn, now):
    if bp == 0 and bn == 0:
        res.append("".join(now))
        return
    
    if bp > 0:
        now.append('(')
        call(pos+1, bp-1, bn, now)
        now.pop()
        
    if pos > 0:
        now.append(')')
        call(pos-1, bp, bn-1, now)
        now.pop()
    
class Solution:
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        global res
        res = []
        call(0, n, n, [])
        return res