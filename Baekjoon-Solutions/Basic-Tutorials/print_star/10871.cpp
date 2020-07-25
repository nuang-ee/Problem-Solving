// https://www.acmicpc.net/problem/10871
#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, x, elem;
    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> elem;
        if (elem < x) cout << elem << ' ';
    }
}