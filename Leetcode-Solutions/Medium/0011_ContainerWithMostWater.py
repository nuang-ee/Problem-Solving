class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        ##GREEDY ALGORITHM??
        start = 0
        end = len(height)-1
        det = min(height[start],height[end])
        maxarea = end*det
        
        while(start != end):
            det = min(height[start],height[end])
            newarea = (end-start)*det
            if newarea > maxarea:
                maxarea = newarea
            if det == height[start]:
                start+=1
            else:
                end -= 1
                
        return maxarea        
