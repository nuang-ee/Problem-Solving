// Solution #3: DP(i, j) = [Alex's best score - Lee's best score] where piles[i...j] left.
class Solution {
    public:
    bool stoneGame(vector<int>& piles) {
        bool turn = true;
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int dist = 1; dist < n; dist++) {
            for (int i = 0; i < n - dist; i++) {
                int j = i + dist;
                if (turn) {
                    dp[i][j] = max(piles[i] + dp[i+1][j], piles[j] + dp[i][j-1]);
                } else {
                    dp[i][j] = min(dp[i+1][j] - piles[i], dp[i][j-1] - piles[j]);
                }
            }
            turn = !turn;
        }
        return dp[0][n-1] > 0;
    }
};


// class Solution {
// public:
//     bool stoneGame(vector<int>& piles) {
//         bool turn = true;   // true -> Alex's turn, false -> Lee's turn
//         int alex = 0, lee = 0;
//         int i = 0, j = piles.size() - 1;
//         while (i != j) {
//             int greedyPick = max(piles[i], piles[j]);
//             (piles[i] == greedyPick) ? i++ : j--;
            
//             if (turn) alex += greedyPick;
//             else lee += greedyPick;            
//         }
//         return alex > lee;
//     }
// };

// Solution #2: Greedy Works?: passed the test cases, but not sure...
// class Solution {
// public:
//     bool stoneGame(vector<int>& piles) {
//         bool turn = true;   // true -> Alex's turn, false -> Lee's turn
//         int alex = 0, lee = 0;
//         int i = 0, j = piles.size() - 1;
//         while (i != j) {
//             int greedyPick = max(piles[i], piles[j]);
//             (piles[i] == greedyPick) ? i++ : j--;
            
//             if (turn) alex += greedyPick;
//             else lee += greedyPick;            
//         }
//         return alex > lee;
//     }
// };


// Solution #1: Alex Rules!!!
// class Solution {
// public:
//     bool stoneGame(vector<int>& piles) {
//         return true;        
//     }
// };
