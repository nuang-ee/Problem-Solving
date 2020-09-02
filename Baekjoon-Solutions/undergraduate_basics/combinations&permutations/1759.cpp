// https://www.acmicpc.net/problem/1759
// given characters, print out all increasing permutations.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int L, C;
    cin >> L >> C;

    vector<char> chrs;
    char chr;
    for (int i = 0; i < C; i++) {
        cin >> chr;
        chrs.push_back(chr);
    }
    sort(chrs.begin(), chrs.end());

    vector<bool> v(C);
    fill(v.begin(), v.begin() + L, true);
    string s;
    do {
        int numVowels = 0, numConsonants = 0;
        s.clear();
        for (int i = 0; i < C; i++) {
            if (v[i]) {
                s += chrs[i];
                if (chrs[i] == 'a' || chrs[i] == 'e' || chrs[i] == 'i' || chrs[i] == 'o' || chrs[i] == 'u') numVowels++;
                else numConsonants++;
            }
        }
        if (numVowels == 0 || numConsonants < 2) continue;
        cout << s << '\n';
    } while (prev_permutation(v.begin(), v.end()));

    return 0;
}