// https://www.acmicpc.net/problem/1935
// evaluate given postfix-notation expression.

#include <iostream>
#include <iomanip>
#include <stack>
#include <string>

using namespace std;

double values[26];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    stack<double> st;

    string s;
    cin >> s;

    double val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        values[i] = val;
    }

    double l, r;
    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
            case '+':
                r = st.top(); st.pop();
                l = st.top(); st.pop();
                st.push(l + r);
                break;
            case '-':
                r = st.top(); st.pop();
                l = st.top(); st.pop();
                st.push(l - r);
                break;
            case '*':
                r = st.top(); st.pop();
                l = st.top(); st.pop();
                st.push(l * r);
                break;
            case '/':
                r = st.top(); st.pop();
                l = st.top(); st.pop();
                st.push(l / r);
                break;
            default:
                st.push(values[s[i] - 'A']);
                break;
        }
    }

    cout << fixed << setprecision(2) << st.top() << '\n';

    return 0;
}