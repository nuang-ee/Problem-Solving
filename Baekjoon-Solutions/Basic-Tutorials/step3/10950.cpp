// https://www.acmicpc.net/problem/10950
#include <iostream>
using namespace std;

int main() {
    int t;
    int a, b;
    string outputstr = "";
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        outputstr += to_string(a + b) + '\n';
    }
    cout << outputstr;
}