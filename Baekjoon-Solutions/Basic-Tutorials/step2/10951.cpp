// https://www.acmicpc.net/problem/10951
#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a, b;
    while (true) {
        cin >> a >> b;
        if (cin.eof()) break;
        cout << a + b << '\n';
    }
}