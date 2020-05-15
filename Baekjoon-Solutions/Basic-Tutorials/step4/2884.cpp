// https://www.acmicpc.net/problem/2884

#include <iostream>
using namespace std;

int main() {
    int h, m;
    int quadrant = 1;
    cin >> h >> m; 
    m -= 45;
    if (m < 0) {
        m += 60;
        h--;
    }
    if (h < 0) h += 24;
    cout << h << ' ' << m << '\n';
} // namespace std;