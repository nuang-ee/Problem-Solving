#include <iostream>

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;

    vector<bool> visited(n, false);

    stack<int> s;

    for (int k = 0; k < n; k++)
    {
        if (visited[k])
            continue;

        // if cur node is not visited, traverse all connected nodes with bfs.
        s.push(k);
        visited[k] = true;

        while (!s.empty())
        {
            int cur = s.top();
            s.pop();

            for (int i = 0; i < n; i++)
            {
                if (computers[cur][i] && !visited[i])
                {
                    visited[i] = true;
                    s.push(i);
                }
            }
        }
        answer++;
    }

    return answer;
}

int main()
{
    vector<vector<int>> computers1 = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    vector<vector<int>> computers2 = {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};

    cout << solution(3, computers1) << endl;
    cout << solution(3, computers2) << endl;
}