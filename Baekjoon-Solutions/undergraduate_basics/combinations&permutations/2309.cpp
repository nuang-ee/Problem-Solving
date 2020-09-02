// https://www.acmicpc.net/problem/2309
// 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> heights;
    vector<bool> v(9);
    vector<int> realOnes;
    int h;
    for (int i = 0; i < 9; i++) {
        cin >> h;
        heights.push_back(h);
    }

    fill(v.begin(), v.begin() + 7, true);
    do {
        int sumHeights = 0;
        realOnes.clear();
        for (int i = 0; i < 9; i++) {
            if (v[i]) {
                sumHeights += heights[i];
                realOnes.push_back(heights[i]);
            }
        }
        if (sumHeights == 100) break;
    } while (prev_permutation(v.begin(), v.end()));

    sort(realOnes.begin(), realOnes.end());
    for (auto height : realOnes) cout << height << '\n';

    return 0;
}