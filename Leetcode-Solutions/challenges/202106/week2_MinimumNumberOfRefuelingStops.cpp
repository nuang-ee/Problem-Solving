// Solution #2: dp[i] = max distance by visiting n times.
// the soltuion would be dp[i] where i is the smallest number that satisfies dp[i] >= target.
// O(N * log(N)) solution, N: outer loop, log(N): priority queue push.
// Time: 86.55%, Memory: 77.77%
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int maxRange = startFuel;
        priority_queue<int> pq;                         // new priority queue for every dp[i]
        
        int i = 0, j = 0;
        for (; maxRange < target; i++) {
            for (; j < stations.size() && stations[j][0] <= maxRange; j++) {
                pq.push(stations[j][1]);
            }
            if (pq.empty()) return -1;

            maxRange += pq.top(); pq.pop();             // to avoid duplicate visitation
                                                        // order of visitation does not affect dp[i].
        }
        return i;
    }
};

// trial: was a bad approach  
// Solution #1: dp[i] = amount of minimum gas holding?
// dp[i] = max of remainig gas(<some set of reachable points... with minimum refueling stops>)
// 
// class Solution {
// public:
//     int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
//         stations.push_back({target, 0});
//         int n = stations.size(), visitedCount = 0, i = 0;
//         vector<pair<int, int>> totalFuels;  // pair of <visitedCount, remainFuel>
//         totalFuels.emplace_back(0, startFuel);
        
//         // for (auto e: stations) {
//         //     if (startFuel < e[0]) break;
//         //     int totalFuel = startFuel + e[1];
//         //     totalFuels.emplace_back(1, totalFuel);
//         //     cout << 1 << ' ' << totalFuel << endl;
//         //     i++;
//         // }

//         for (int i = 0; i < n; i++) {
//             // cout << 2 << endl;

//             int curDistance = stations[i][0];
//             totalFuels.erase(
//                 remove_if(
//                     totalFuels.begin(),
//                     totalFuels.end(),
//                     [curDistance](pair<int, int> p){return p.second < curDistance;}
//                 ),
//                 totalFuels.end()
//             );

//             if (totalFuels.empty()) return -1;
//             // cout << 3 << endl;

//             vector<pair<int, int>> minStops;
//             copy_if(
//                 totalFuels.begin(),
//                 totalFuels.end(),
//                 back_inserter(minStops),
//                 [totalFuels](pair<int, int> p){
//                     // make sure that visitedCount monotonically increases
//                     assert(p.first >= totalFuels[0].first);
//                     return p.first == totalFuels[0].first;
//                 }
//             );
//             // cout << 4 << endl;

//             auto maxElem = max_element(
//                 minStops.begin(),
//                 minStops.end(),
//                 [](const auto& lhs, const auto& rhs) { return lhs.second < rhs.second; }
//             );
//             pair<int, int> best = make_pair(maxElem->first, maxElem->second);
            
//             totalFuels.emplace_back(best.first + 1, best.second + stations[i][1]);
//             cout << (best.first + 1) << ' ' << (best.second + stations[i][1]) << endl;
//         }
        
//         return totalFuels.back().first - 1;
//     }
// };
