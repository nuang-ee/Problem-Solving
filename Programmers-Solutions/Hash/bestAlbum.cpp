#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;

    // unordered_map<string, int> genres_plays;
    // <music name, music_list<pair<unique_num, plays>>>
    unordered_map<string, vector<pair<int, int>>> m;
    for (int i = 0; i < genres.size(); i++)
    {
        // genres_plays[genres[i]] += plays[i];
        m[genres[i]].emplace_back(i, plays[i]);
    }
    // convert to vector to sort
    vector<pair<string, vector<pair<int, int>>>> elems(m.begin(), m.end());
    // sort genres by sum of plays
    sort(elems.begin(), elems.end(), [](const auto &l, const auto &r) {
        int l_sum = accumulate(l.second.begin(), l.second.end(), 0, [](const int &lv, const pair<int, int> &rv) {
            return lv + rv.second;
        });
        int r_sum = accumulate(r.second.begin(), r.second.end(), 0, [](const int &lv, const pair<int, int> &rv) {
            return lv + rv.second;
        });
        return l_sum > r_sum;
    });

    // sort musics in each genres by plays, and append to answer.
    for (auto e : elems)
    {
        vector<pair<int, int>> music_list = e.second;
        // if there is only one song in genre, just append.
        if (music_list.size() == 1)
        {
            answer.push_back(music_list[0].first);
            continue;
        }
        // else, sort and append.
        sort(music_list.begin(), music_list.end(), [](const pair<int, int> &l, const pair<int, int> &r) {
            return l.second > r.second;
        });

        for (int i = 0; i <= 1; i++)
            answer.push_back(music_list[i].first);
    }

    return answer;
}

int main()
{
    vector<string> generes = {"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays = {500, 600, 150, 800, 2500};

    for (auto e : solution(generes, plays))
    {
        cout << e << ' ';
    }
    cout << endl;
}