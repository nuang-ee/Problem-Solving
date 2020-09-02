// https://www.acmicpc.net/problem/10819
// get permutation of A, which maximizes |A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]|
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> numbers;
    int max = 0, temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        numbers.push_back(temp);
    }

    sort(numbers.begin(), numbers.end());
    do {
        temp = 0;
        for (int i = 0; i < n-1; i++) {
            temp += abs(numbers[i] - numbers[i+1]);
        }
        if (temp > max) max = temp;
    } while (next_permutation(numbers.begin(), numbers.end()));

    cout << max << '\n';
    return 0;
}