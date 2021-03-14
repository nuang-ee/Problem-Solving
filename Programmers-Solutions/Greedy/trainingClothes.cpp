#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;

    for (auto it = reserve.begin(); it != reserve.end();)
    {
        auto found_res = find(lost.begin(), lost.end(), *it);
        if (found_res != lost.end())
        {
            lost.erase(found_res);
            reserve.erase(it);
        }
        else
            it++;
    }

    for (auto it = lost.begin(); it != lost.end();)
    {
        int student = *it;

        auto prev_student = find(reserve.begin(), reserve.end(), student - 1);
        if (prev_student != reserve.end())
        {
            lost.erase(it);
            reserve.erase(prev_student);
            continue;
        }
        auto next_student = find(reserve.begin(), reserve.end(), student + 1);
        if (next_student != reserve.end())
        {
            lost.erase(it);
            reserve.erase(next_student);
            continue;
        }

        it++;
    }

    answer = n - lost.size();

    return answer;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    vector<int> lost = {3};
    vector<int> reserve = {1};
    cout << solution(3, lost, reserve) << endl;
}