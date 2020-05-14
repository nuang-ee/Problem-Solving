class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        longestsubstring = ''
        for i in range(len(s)):
            for j in range(i, len(s)+1):
                temp = set(s[i:j])
                if len(temp)== j-i:
                    if len(temp)>len(longestsubstring):
                        longestsubstring = ''.join(temp)
        # print longestsubstring
        return len(longestsubstring)
