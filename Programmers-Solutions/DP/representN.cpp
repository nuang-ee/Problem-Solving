#include <iostream>

#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(int N, int number)
{
    int answer = 0;

    if (N == number)
    {
        answer = 1;
        return answer;
    }

    vector<set<int>> dp_table(8);
    int mul = 1;
    for (auto &e : dp_table)
    {
        e.insert(N * mul);
        mul = mul * 10 + 1;
    }

    for (int i = 1; i < 8; i++)
    {
        for (int j = 0; j < i; j++)
        {
            // make dp_table[i] with components of dp_table[j] and dp_table[i-j-1]
            // since dp_table would contain numbers that is consisted of i+1 uses of N,
            // j+1 + i-j.
            for (auto l_num : dp_table[j])
            {
                for (auto r_num : dp_table[i - j - 1])
                {
                    dp_table[i].insert(l_num + r_num);
                    dp_table[i].insert(l_num - r_num);
                    dp_table[i].insert(l_num * r_num);
                    if (r_num != 0)
                    {
                        dp_table[i].insert(l_num / r_num);
                    }
                }
            }
        }
        if (dp_table[i].find(number) != dp_table[i].end())
        {
            answer = i + 1;
            break;
        }
    }
    if (answer == 0)
        answer = -1;

    return answer;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cout << solution(2, 11) << endl;
    return 0;
}