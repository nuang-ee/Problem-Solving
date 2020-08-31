// https://www.acmicpc.net/problem/1918
// change infix notation to postfix notation.
// reference : https://en.wikipedia.org/wiki/Shunting-yard_algorithm
#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    stack<char> ops;
    vector<char> ids;
    char opsTop = '\0';
    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
            case '+':
            case '-':
                while (true) {
                    if (ops.empty()) break;
                    opsTop = ops.top();
                    if (opsTop == '+' || opsTop == '-' || opsTop == '*' || opsTop == '/') {
                        ids.push_back(opsTop);
                        ops.pop();
                    }
                    else break;
                }
                ops.push(s[i]);
                break;
            case '*':
            case '/':
                while (true) {
                    if (ops.empty()) break;
                    opsTop = ops.top();
                    if (opsTop == '*' || opsTop == '/') {
                        ids.push_back(opsTop);
                        ops.pop();
                    }
                    else break;
                }
                ops.push(s[i]);
                break;
            case '(':
                ops.push(s[i]);
                break;
            case ')':
                if (ops.empty()) break;
                opsTop = ops.top();
                while (opsTop != '(') {
                    ids.push_back(opsTop);
                    ops.pop();
                    opsTop = ops.top();
                }
                ops.pop();
                break;
            default:
                ids.push_back(s[i]);
                break;
        }
    }

    while (!ops.empty()) {
        ids.push_back(ops.top()); ops.pop();
    }

    if (!ids.empty()) for (auto c : ids) cout << c;
    cout << '\n';

    return 0;
}