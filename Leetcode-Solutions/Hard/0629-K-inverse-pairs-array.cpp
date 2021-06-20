// Solution #1: DP
// * dp(n, k) = number of different arrays consist of number from 1 to n
//              i.e. there are exactly k inverse pairs.
// * dp[1][0] = 1, 
// * we can make at most i * (i-1) / 2 inverse pairs with i numbers. (reverse-sorted)
// dp(n, k) = dp(n-1, k) + dp(n-1, k-1) + dp(n-1, k-2) + ... + dp(n-1, k-(n-1))
// dp(n, k+1) = dp(n-1, k+1) + dp(n-1, k) + ... + dp(n-1, k+1-(n-2)) + dp(n-1, k+1-(n-1))
// dp(n, k+1) - dp(n, k) = dp(n-1, k+1) - dp(n-1, k-(n-1))
// dp(n, k+1) = dp(n, k) + dp(n-1, k+1) - dp(n-1, k-n+1)
// So, dp(n, k) = dp(n, k-1) + dp(n-1, k) - dp(n-1, k-n)
// skip negative term if invalid.

// More Optimization? 
// Fact: D[n][k] = D[n][n * (n - 1) - k]
// it is semetric
class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<long>> dp(n+1, vector<long>(k+1, 0));
        int modDivisor = pow(10, 9) + 7;

        dp[1][0] = 1;
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        for (int i = 2; i <= n; i++) {
            int acc = 0;
            for (int j = 1; j <= min(k, i * (i-1) / 2); j++) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
                if (j >= i) dp[i][j] -= dp[i-1][j-i];
                dp[i][j] = (dp[i][j] + modDivisor) % modDivisor;
            }
        }
        return (int) dp[n][k];
    }
};
