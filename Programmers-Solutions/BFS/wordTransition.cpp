#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int solution(string begin, string target, vector<string> words)
{
    int answer = 0;

    if (find(words.begin(), words.end(), target) == words.end())
        return answer;

    int len_words = words.size();
    queue<pair<string, vector<bool>>> q;
    q.emplace(make_pair(begin, vector<bool>(len_words, false)));

    bool done = false;
    while (!q.empty())
    {
        int q_size = q.size();
        for (int k = 0; k < q_size; k++)
        {

            string cur;
            vector<bool> cur_visited;
            tie(cur, cur_visited) = q.front();
            q.pop();

            if (cur == target)
            {
                done = true;
                break;
            }

            for (int i = 0; i < len_words; i++)
            {
                vector<bool> next_visited = cur_visited;
                if (!next_visited[i])
                {
                    int diff_cnt = 0;
                    for (int j = 0; j < words[i].length(); j++)
                    {
                        if (cur[j] != words[i][j])
                            diff_cnt++;
                    }
                    if (diff_cnt == 1)
                    {
                        next_visited[i] = true;
                        string next = words[i];
                        q.emplace(make_pair(next, next_visited));
                    }
                }
            }
        }
        if (done)
            break;
        answer++;
    }

    return answer;
}

int main()
{
    cout << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}) << endl;
    cout << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log"}) << endl;
}