class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        cand = ""
        maxlenstr = ""
        for i in range(len(s)):
            if s[i] in cand:
                cand = cand[cand.find(s[i])+1 :] + s[i]
            elif s[i] not in cand:
                cand += s[i]
            if len(maxlenstr)<len(cand):
                maxlenstr = cand
        return len(maxlenstr)
