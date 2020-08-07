// https://www.acmicpc.net/problem/1652
// find place to lay down.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, place_row = 0, place_col = 0;
    vector<string> row_vec;

    cin >> n;
    bool blocked;
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        row_vec.push_back(row);
        
        blocked = true;
        char prev = 'X';
        for (int j = 0; j < row.length(); j++) {
            char cur = row.at(j);
            if (!blocked && cur == 'X') blocked = true;
            if (blocked && cur == '.' && prev == '.') {
                place_row++;
                blocked = false;
            }
            prev = cur;
            
        }
    }

    for (int i = 0; i < n; i++) {
        blocked = true;
        char prev = 'X';
        for (int j = 0; j < n; j++) {
            string row = row_vec[j];
            char cur = row[i];
            if (!blocked && cur == 'X') blocked = true;
            if (blocked && cur == '.' && prev == '.') {
                place_col++;
                blocked = false;
            }
            prev = cur;
        }
    }

    cout << place_row << ' ' << place_col << '\n';
}
