// https://www.acmicpc.net/problem/14681

#include <iostream>
using namespace std;

int main() {
    int x, y;
    int quadrant = 1;
    cin >> x >> y; 
    if (y < 0) quadrant += 2;
    if (x * y < 0) quadrant += 1;
    cout << quadrant << '\n';
} // namespace std;