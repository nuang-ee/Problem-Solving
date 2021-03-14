#include <iostream>

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> phonenum_set;
    for (auto e: phone_book)
        phonenum_set.insert(e);

    for (auto e: phone_book) {
        for (int i = 1; i < e.length(); i++) {
            // if substr found
            if (phonenum_set.find(e.substr(0, i)) != phonenum_set.end()) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    vector<string> phone_book = {"123", "456", "789"};
    cout << (solution(phone_book) ? "true" : "false") << "\n";
}