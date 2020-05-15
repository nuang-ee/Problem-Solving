// https://www.acmicpc.net/problem/2753

#include <iostream>
using namespace std;

int main() {
    int year;
    bool isLeapYear = false;
    cin >> year;
    if (!(year%4) && (year%100 || !(year%400))) isLeapYear = true;
    cout << (isLeapYear) ? 1 : 0 << '\n';
} // namespace std;