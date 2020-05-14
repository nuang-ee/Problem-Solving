class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        cns = '1'
        for i in range(n-1):
            saveindex = 0
            countlist = [[1,cns[0]]]
            countlistindex = 0
            
            for j in range(1, len(cns)):
                if cns[saveindex] == cns[j]:
                    countlist[countlistindex][0] += 1
                else:
                    saveindex = j
                    countlist.append([1,cns[j]])
                    countlistindex += 1
            
            cns = ''
            for j in range(len(countlist)):
                cns = cns + str(countlist[j][0]) + countlist[j][1]
        return cns
            
