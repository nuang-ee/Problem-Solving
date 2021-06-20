// Solution #3: use map?
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s.at(l) != s.at(r)) {
                return false;
            }
            l++; r--;
        }
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> m;
        vector<vector<int>> pairs;
        int n = words.size();
        vector<vector<int>> picked(n, vector<int>());
        
        for (int i = 0; i < n; i++) {
            m[words[i]] = i;
        }
        
        for (int i = 0; i < n; i++) {
            string cur = words[i];
            int curLen = cur.length(), res = -1;
            string search1 = "";    // where <foundResult><cur> is palindrome
            string search2 = "";    // where <cur><foundResult> is palindrome
            
            for (int j = 0; j <= curLen; j++) {
                auto searchResult1 = m.find(search1);
                if (searchResult1 != m.end() && searchResult1->second != i && isPalindrome(cur.substr(0, curLen - j))) {
                    int pairIndex = searchResult1->second;
                    vector<int> v = picked[pairIndex];
                    if (find(v.begin(), v.end(), i) == v.end()) {
                        pairs.push_back({ pairIndex, i });
                        picked[pairIndex].push_back(i);
                    }
                }

                auto searchResult2 = m.find(search2);
                if (searchResult2 != m.end() && searchResult2->second != i && isPalindrome(cur.substr(j, curLen - j))) {
                    int pairIndex = searchResult2->second;
                    vector<int> v = picked[i];
                    if (find(v.begin(), v.end(), pairIndex) == v.end()) {
                        pairs.push_back({ i, pairIndex });
                        picked[i].push_back(pairIndex);
                    }
                }
                
                if (j < curLen) {
                    search1 = search1 + cur.at(curLen - j - 1); // if cur='abc', 'c' -> 'cb' -> ..
                    search2 = cur.at(j) + search2;              // if cur='abc', 'a' -> 'ba' -> ..
                }                
            }
        }
        
        return pairs;
    }
};


// Solution #2: just concat and compare front & end linearly
// O(n**2 * k)? -> TLE...
// class Solution {
// public:
//     vector<vector<int>> palindromePairs(vector<string>& words) {
//         vector<vector<int>> pairs;
//         int n = words.size();
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (i == j) continue;
                
//                 string cur = words[i] + words[j];
//                 int l = 0, r = cur.size() - 1;
                
//                 bool isPalindrome = true;
//                 while (l < r) {
//                     if (cur.at(l) != cur.at(r)) {
//                         isPalindrome = false;
//                         break;
//                     }
//                     l++; r--;
//                 }
//                 if (isPalindrome) pairs.push_back({ i, j });
//             }
//         }
//         return pairs;
//     }
// };

// // Solution #1: stacks & queues... does not work, too much complexity (not elegant)
// class Solution {
// public:
//     vector<vector<int>> palindromePairs(vector<string>& words) {
//         int n = words.size();
//         vector<stack<char>> stacks;
//         vector<queue<char>> queues;
//         vector<vector<int>> pairs;
//         vector<bool> isSelfComplete(n, false);
        
//         for (int i = 0; i < n; i++) {
//             string word = words[i];
//             stack<char> s;
//             queue<char> q;
            
//             for (auto c: word) {
//                 q.push(c);
//                 s.push(c);
//             }
            
//             stacks.push_back(s);
//             queues.push_back(q);
//         }
        
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (i == j) continue;
//                 if (isSelfComplete[i] && queues[j].empty()) {
//                     pairs.push_back({ i, j });
//                     continue;
//                 }
                    
//                 if (stacks[i].size() != queues[j].size()) continue;
//                 assert(!stacks[i].empty() && !queues[i].empty());
//                 if (stacks[i].top() != queues[j].front()) continue;
                
//                 stack<char> s = stacks[i];
//                 queue<char> q = queues[j];
                
//                 bool isSame = true;
//                 while (!s.empty()) {
//                     if (s.top() != q.front()) {
//                         isSame = false;
//                         break;
//                     }
//                     s.pop(); q.pop();
//                 }
//                 if (isSame) pairs.push_back({ i, j });
//             }
//         }

//         return pairs;
//     }
// };
