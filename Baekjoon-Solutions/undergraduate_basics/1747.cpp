// https://www.acmicpc.net/problem/1747
// minimal prime & palindrome between [N, 1_000_000]
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

bool is_prime(int num) {
    if (num == 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, ans;
    cin >> n;
    for (int i = n; i <= 1003001; i++) {
        string temp = to_string(i);
        string rev = temp;
        reverse(rev.begin(), rev.end());

        if (temp != rev) continue;
        
        if (is_prime(i)) {
            ans = i;
            break;
        }
    }
    cout << ans << '\n';
}