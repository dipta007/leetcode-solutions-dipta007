class Solution:
    def fourSumCount(self, A, B, C, D):
        """
        :type A: List[int]
        :type B: List[int]
        :type C: List[int]
        :type D: List[int]
        :rtype: int
        """
        ab = []
        for va in A:
            for vb in B:
                ab.append(va + vb)
                
        cd = []
        for vc in C:
            for vd in D:
                cd.append(vc + vd)
                
        cd.sort()
        
        mcd = dict()
        for v in cd:
            if v not in mcd:
                mcd[v] = 0
            mcd[v] += 1
        
        cnt = 0
        for v in ab:
            need = -v
            if need in mcd:
                cnt += mcd[need]
                
        return cnt