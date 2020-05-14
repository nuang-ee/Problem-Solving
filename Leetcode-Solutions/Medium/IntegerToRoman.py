class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        def intToRom(x):
            return {1:"I", 5:"V", 10:"X", 50:"L", 100:"C", 500:"D", 1000:"M"}[x]
        
        
        ans = ""
        temp = num
        seat = 1
        while(temp>=1):
            step = temp%10
            if step==4 or step==9:
                step+=1
                ans = intToRom(seat) + intToRom(step*seat) + ans
            elif step>=5:
                step-=5
                ans = intToRom(seat*5) + intToRom(seat)*step + ans
            elif step<4:
                ans = intToRom(seat)*step + ans
            seat*=10
            temp//=10
        return ans
