// https://www.acmicpc.net/problem/9498

#include <iostream>
using namespace std;

int main() {
    int score;
    cin >> score;
    string grade = score >= 90 ? "A\n" : (score >= 80 ? "B\n" : (score >= 70 ? "C\n" : (score >= 60 ? "D\n" : "F\n")));
    cout << grade;
}