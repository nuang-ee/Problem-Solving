#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> p_map, c_map;
    for (auto e: participant) {
        if (p_map.find(e) == p_map.end())
            p_map[e] = 1;
        else p_map[e]++;
    }

    for (auto e: completion) {
        if (c_map.find(e) == c_map.end())
            c_map[e] = 1;
        else c_map[e]++;
    }

    for (auto it = p_map.begin(); it != p_map.end(); it++) {
        if (c_map.find(it->first) == c_map.end() || c_map[it->first] != it->second) {
            answer = it->first;
            break;
        }
    }

    return answer;
}

int main() {
    vector<string> participant = {"leo", "kiki", "eden"};
    vector<string> completion = {"eden", "kiki"};

    cout << solution(participant, completion) << "\n";
}