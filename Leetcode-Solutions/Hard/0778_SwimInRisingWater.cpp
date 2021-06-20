// Solution #1: (Only thought, not implemented) do DFS from starting point, N**2 Times.             [O(n**4)]
// Solution #2: (Only thought, not implemented) do DFS from both points (start + end), N**2 Times.  [O(n**4)]
// Solution #3: Union-Find!!    [O(n**2) for optimal implementation of union-find data structure]
// represent score = n*i + j, grids with same score are in same area (visitable)
class Solution {
public:
    int doFind(vector<vector<int>>& parent, int x, int y, int n) {
        if (parent[x][y] == n*x + y) return n*x + y;
        return doFind(parent, parent[x][y] / n, parent[x][y] % n, n);
    }

    void doUnion(vector<vector<int>>& parent, int x1, int y1, int x2, int y2, int n) {
        int set1 = doFind(parent, x1, y1, n);
        int set2 = doFind(parent, x2, y2, n);
        if (set1 < set2) {
            parent[set2 / n][set2 % n] = set1;
        } else {
            parent[set1 / n][set1 % n] = set2;
        }
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int> dx = {-1, 0, 1,  0};
        vector<int> dy = { 0, 1, 0, -1};
        vector<vector<int>> parents(n, vector<int>(n, 0));
        vector<int> order(n*n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                order[grid[i][j]] = n*i + j;    // order[k] = grid[i][j], k th grid in permutation is grid[i][j]
                parents[i][j] = n*i + j;
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int t = n*i + j;
                int curGrid = order[t];
                int curX = curGrid / n, curY = curGrid % n;

                for (int k = 0; k < 4; k++) {
                    int adjX = curX + dx[k], adjY = curY + dy[k];
                    if (adjX < 0 || adjX >= n || adjY < 0 || adjY >= n) continue;
                    if (t < grid[adjX][adjY]) continue;
                    
                    doUnion(parents, curX, curY, adjX, adjY, n);
                }
                if (doFind(parents, n-1, n-1, n) == parents[0][0]) return t;
            }
        }

        
        return INT_MAX; // Failure
    }
};
