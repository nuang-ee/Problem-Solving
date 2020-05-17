// https://www.acmicpc.net/problem/10817
// shitty solution I guess..
#include <iostream>
using namespace std;
// #include <algorithm> -> then use sort(num, num+3)

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int num[3], result;
    int min = 100, max = 0, i, p, q;
    cin >> num[0] >> num[1] >> num[2];

    for (i = 0; i < 3; i++) {
        if (num[i] < min) {
            p = i;
            min = num[i];
        }
        if (num[i] > max) {
            q = i;
            max = num[i];
        }
    }
    num[p] = 0;
    num[q] = 0;
    for (i = 0; i < 3; i++) {
        if (num[i]) result = num[i];
    }
    cout << result << '\n';
}