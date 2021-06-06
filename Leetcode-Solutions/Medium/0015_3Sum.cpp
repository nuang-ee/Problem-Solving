// Solution #2: 1 less loop
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> threeSums;
        unsigned int sizeOfInput = nums.size();
        
        // O(N * log(N))
        sort(nums.begin(), nums.end());
        
        // O(N**2), worst O(N**3)?
        for (unsigned int cursor = 0; cursor < sizeOfInput; cursor++) {
            unsigned int left = cursor + 1, right = sizeOfInput - 1;
            while (left < right) {
                int sum = nums[cursor] + nums[left] + nums[right];
                if (sum == 0) {
                    vector<int> candidate = {nums[cursor], nums[left], nums[right]};
                    threeSums.push_back(candidate);

                    if (left < right) left++;
                    if (left < right) right--;

                    // change both sides to different number.
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
                else if (sum > 0) {
                    right--;
                }
                else if (sum < 0) {
                    left++;
                }
            }

            while (cursor < sizeOfInput - 1 && nums[cursor] == nums[cursor + 1]) {
                cursor++;
            }
        }
        return threeSums;
    }
};


// Solution #1: brute force
//  how to skip existing ones -> make it to set or something...?
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         // naive solution, n^4?... this exceeds time limit.
//         vector<vector<int>> threeSums;
//         sort(nums.begin(), nums.end());
//         for (unsigned int cursor1 = 0; cursor1 < nums.size(); cursor1++) {
//             for (unsigned int cursor2 = cursor1 + 1; cursor2 < nums.size(); cursor2++) {
//                 for (unsigned int cursor3 = cursor2 + 1; cursor3 < nums.size(); cursor3++) {
//                     if (nums[cursor1] + nums[cursor2] + nums[cursor3] == 0) {
//                         bool valid = true;
//                         for (unsigned int bt = 0; bt < threeSums.size(); bt++) {
//                             if (nums[cursor1] == threeSums[bt][0] && nums[cursor2] == threeSums[bt][1] && nums[cursor3] == threeSums[bt][2]) {
//                                 valid = false;
//                                 break;
//                             }
//                         }
//                         if (valid) threeSums.push_back({nums[cursor1], nums[cursor2], nums[cursor3]});
//                     }
//                 }
//             }
//         }
//         return threeSums;
//     }
// };
