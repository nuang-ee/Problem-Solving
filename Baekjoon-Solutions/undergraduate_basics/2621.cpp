// https://www.acmicpc.net/problem/2621
// find row/column that contains two adjacent . (not X)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<char> color_vec = {'R', 'B', 'Y', 'G'};

    vector<int> color_cnt(4, 0);
    vector<int> val_cnt(10, 0); // index 0 should be meaningless.

    char c;
    int v, score=0;
    int i, j;

    for (i = 0; i < 5; i++) {
        cin >> c >> v;
        for (j = 0; j < color_vec.size(); j++) {
            if (c == color_vec[j]) color_cnt[j]++;
        }
        val_cnt[v]++;
    }

    bool straight = false;
    // check straight.
    for (i = 1; i < 6; i++) {
        bool check = true;
        for (j = i; j < i+5; j++) {
            if (val_cnt[j] != 1) {
                check = false;
                break;
            }
        }
        if (check) {
            straight = true;
            break;
        }
    }

    // check flush.
    bool flush = false;
    for (i = 0; i < color_cnt.size(); i++) {
        if (color_cnt[i] == 5) flush = true;
    }

    int val_cnt_size = val_cnt.size();
    for (i = 0; i < val_cnt_size; i++) {
        if (val_cnt[i] == 4) {
            score = 800 + i;
            break;
        }
        else if (val_cnt[i] == 3) {
            for (j = 0; j < val_cnt_size; j++) {
                if (i == j) continue;
                if (val_cnt[j] == 2) {
                    score = 10 * i + j + 700;
                    break;
                }
            }
            if (score == 0) score = 400 + i;
            break;
        }
        else if (val_cnt[i] == 2) {
            for (j = 0; j < val_cnt_size; j++) {
                if (i == j) continue;
                if (val_cnt[j] == 2) {
                    score = max(i, j) * 10 + min(i, j) + 300;
                    break;
                }
                if (val_cnt[j] == 3) {
                    score = 10 * j + i + 700;
                }
            }
            if (score == 0) score = 200 + i;
            break;
        }
    }

    int max_val = 0;
    for (i = val_cnt_size - 1; i > 0; i--) {
        if (val_cnt[i] != 0) {
            max_val = i;
            break;
        }
    }
    if (straight && flush) score = 900 + max_val;
    else if (straight) score = 500 + max_val;
    else if (flush) score = 600 + max_val;

    if (score == 0) score = 100 + max_val;

    cout << score << '\n';
}