// Solution #4 : optimization?
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxScores(n, INT_MIN);
        multiset<int> pool = { maxScores[0] = nums[0] };
        
        for (int i = 1; i < n; i++) {
            int boundaryStart = std::max(0, i-k);
            if (i > k) pool.erase(pool.find(maxScores[boundaryStart - 1]));
            pool.insert(maxScores[i] = *pool.rbegin() + nums[i]);
        }

        return maxScores[n-1];
    }
};

// Solution #3 : maintain a pool of reachable indexes' value as multiset (sorted set that can have eq values).
// remove is done by log(POOL_SIZE), so O(n*k) solution.
/*
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxScores(n, INT_MIN);
        maxScores[0] = nums[0];
        multiset<int> pool;
        pool.insert(maxScores[0]);
        
        for (int i = 1; i < n; i++) {
            int boundaryStart = std::max(0, i-k);
            if (boundaryStart > 0) {
                pool.erase(pool.find(maxScores[boundaryStart - 1]));
            }

            maxScores[i] = *pool.rbegin() + nums[i];
            pool.insert(maxScores[i]);
        }

        return maxScores[n-1];
    }
};
*/

// Solution #2 : Remember best, remove and fetch new best when boundary passed,
// still worst-case n*k?
/*
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxScores;
        pair<int, int> best;    // [index, value]
        maxScores.push_back(nums[0]);
        best = make_pair(0, nums[0]);
        
        for (int i = 1; i < n; i++) {
            if (best.first < std::max(0, i-k)) {
                vector<int>::iterator boundaryStart = maxScores.begin() + std::max(0, i-k);
                int localBestIndex = max_element(boundaryStart, maxScores.begin() + i) - maxScores.begin();
                best = make_pair(localBestIndex, maxScores[localBestIndex]);
            }

            int localBestScore = best.second + nums[i];
            if (localBestScore > best.second) {
                best = make_pair(i, localBestScore);
            }
            maxScores.push_back(localBestScore);
        }

        return maxScores[n-1];
    }
};
*/

// Solution #1 : Simple DP
// n * k solution
/*
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxScores;
        maxScores.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            vector<int>::iterator start = maxScores.begin() + std::max(0, i-k);
            int localBestScore = *max_element(start, maxScores.begin() + i);
            maxScores.push_back(localBestScore + nums[i]);
        }

        return maxScores[n-1];
    }
};
*/
