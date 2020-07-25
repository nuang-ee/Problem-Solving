// https://www.acmicpc.net/problem/10953
// adding n pairs of numbers.
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    string str;
    int a, b;
    for (int i = 0; i < n; i++) {
        getline(cin, str, ',');
        a = stoi(str);
        getline(cin, str);
        b = stoi(str);

        cout << a+b << '\n';
    }
}