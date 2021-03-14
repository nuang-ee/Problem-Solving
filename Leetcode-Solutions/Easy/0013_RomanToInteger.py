class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        def translator(x): 
            return {"I":1, "V":5, "X": 10, "L":50, "C":100, "D":500, "M":1000}[x]
        
        translated = 0
        
        for i in range(len(s)-1):
            if translator(s[i]) < translator(s[i+1]):
                translated -= translator(s[i])
            else:
                translated += translator(s[i])
        translated += translator(s[-1])
                
        return translated
