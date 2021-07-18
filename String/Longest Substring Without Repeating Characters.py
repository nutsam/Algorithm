class Solution:
    def lengthOfLongestSubstring(self, s):
        d = {}
        maxLen = 0
        start = -1
        for i, char in enumerate(s):
            if char in d:
                if d[char] > start: # abba
                    start = d[char]
            d[char] = i
            maxLen = max(maxLen, i-start)
        
        return maxLen