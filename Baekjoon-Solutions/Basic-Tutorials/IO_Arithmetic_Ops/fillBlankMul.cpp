// https://www.acmicpc.net/problem/2588
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int one = b%10;
    int ten = (b%100) / 10;
    int hundred = b / 100;
    cout << a * one << '\n' << a * ten << '\n' << a * hundred << '\n' << a * b << endl;
}