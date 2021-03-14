#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map<string, int> m;
    for (auto e: clothes) {
        m[e[1]]++;
    }

    // cases are whether to not wear one kind of clothes,
    // or select one among those.
    for (auto it = m.begin(); it != m.end(); it++)
    {
        answer *= (it->second + 1);
    }
    // substract the case of wearing nothing.
    answer -= 1;

    return answer;
}

int main() {
    vector<vector<string>> phone_book = {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};
    cout << solution(phone_book) << "\n";
}