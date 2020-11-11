/* https://www.acmicpc.net/problem/1700 */
/* plugged_in */

#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, K, temp, plugged_out = 0;
    cin >> N >> K;

    deque<int> devices;
    deque<int> plugged_in;
    vector<int> left(K);
    for (int i = 0; i < K; i++)
    {
        cin >> temp;
        devices.push_back(temp);
    }

    // plug in as much as possible
    while (plugged_in.size() < N && !devices.empty()) {
        int cur = devices.front();
        // if not plugged in
        if (find(plugged_in.begin(), plugged_in.end(), cur) == plugged_in.end()) {
            plugged_in.push_back(cur);
        }
        devices.pop_front();
    }

    // after all occupied, plug out least remained
    while (!devices.empty()) {
        int cur = devices.front();
        // if not plugged in
        if (find(plugged_in.begin(), plugged_in.end(), cur) == plugged_in.end()) {
            int farthest_index = 0, evicted_index = -1;
            // find the one that would be used at last, from plugged ones
            for (auto e : plugged_in)
            {
                // if there is device that wouldn't be used anymore, evict that.
                if (find(devices.begin(), devices.end(), e) == devices.end()) {
                    evicted_index = find(plugged_in.begin(), plugged_in.end(), e) - plugged_in.begin();
                    break;
                }
                int temp = find(devices.begin(), devices.end(), e) - devices.begin();
                if (temp > farthest_index) {
                    farthest_index = temp;
                }
            }
            // if every plugged devices were found in remaining devices queue
            if (evicted_index == -1)
                evicted_index = find(plugged_in.begin(), plugged_in.end(), devices[farthest_index]) - plugged_in.begin();

            plugged_in[evicted_index] = cur;
            plugged_out++;
        }
        devices.pop_front();
    }
    cout << plugged_out << '\n';

    return 0;
}