class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        d = {}
        pair = 0
        for n in nums:
            if n not in d:
                d[n] = 1
            else:
                pair += d[n]
                d[n] += 1
        return pair