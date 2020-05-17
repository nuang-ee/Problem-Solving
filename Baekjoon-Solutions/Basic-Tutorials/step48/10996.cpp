// https://www.acmicpc.net/problem/10996
#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    int i, j;
    cin >> n;

    for (i = 1; i <= n; i++) {
        for (j=1; j<=n; j++) {
            if (j%2) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
        for (j=0; j<n; j++) {
            if (j%2) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }
}
