// https://www.acmicpc.net/problem/1330
// comparing two nums.
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    string output = a <= b ? (a == b ? "==\n" : "<\n" ) : ">\n";
    cout << output;
}