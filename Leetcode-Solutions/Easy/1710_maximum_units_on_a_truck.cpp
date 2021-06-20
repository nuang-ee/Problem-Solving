// Solution #2: Bucket Sort would be faster (O(N)). but will not implement...
// Solution #1: Greedy + sort (O(N*logN))
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int sum = 0;
        // non-increasing order sort
        sort(boxTypes.begin(), boxTypes.end(),
             [](const vector<int>& lhs, const vector<int>& rhs) { return lhs[1] >= rhs[1]; });
        int curPickedCount = 0, totalPickedCount = 0, i = 0;
        while (totalPickedCount < truckSize && i < boxTypes.size()) {
            sum += boxTypes[i][1];
            curPickedCount++; totalPickedCount++;
            if (curPickedCount >= boxTypes[i][0]) {
                curPickedCount = 0;
                i++;   
            }
        }
        return sum;
    }
};
