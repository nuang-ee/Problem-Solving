// https://www.acmicpc.net/problem/2816

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<string> channel_vec;
    int n, cha1, cha2;
    string answer = "";
    cin >> n;

    int cursor = 0;
    
    for (int i = 0; i < n; i++) {
        string cur;
        cin >> cur;
        if (cur == "KBS1") cha1 = i;
        if (cur == "KBS2") cha2 = i;
        channel_vec.push_back(cur);
    }

    for (; cursor != cha1; cursor++) answer += "1";
    for (; cursor > 0; cursor--) answer += "4";

    if (cha1 > cha2) cha2++;
    for (; cursor != cha2; cursor++) answer += "1";
    for (; cursor > 1; cursor--) answer += "4";
    cout << answer << '\n';
}