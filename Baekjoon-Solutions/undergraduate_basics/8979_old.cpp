// https://www.acmicpc.net/problem/8979

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

struct {
    bool operator() (vector<int> a, vector<int> b) const {
        if (a[1] == b[1]) {
            if (a[2] == b[2]) return a[3] > b[3];
            else return (a[2] > b[2]);
        }
        else return (a[1] > b[1]);
    }
} medalLess;

inline bool medal_equal(const vector<int> &a, const vector<int> &b) {
    return (a[1] == b[1] && a[2] == b[2] && a[3] == b[3]);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, target;
    cin >> n >> target;
    vector<int> medals[n];

    int gold, silver, bronze;
    for (int i=0; i < n; i++) {
        int uNum;
        cin >> uNum >> gold >> silver >> bronze;
        medals[i] = {uNum, gold, silver, bronze};
    }

    sort(&medals[0], &medals[n], medalLess);

    vector<int> prev = {0, -1, -1, -1};
    int place = 0;
    int same = 1;
    for (auto e : medals) {
        if (medal_equal(prev, e)) same ++;
        else {
            prev = e;
            place += same;
            same = 1;
        }

        if (e[0] == target) break;
    }

    cout << place << '\n';
}