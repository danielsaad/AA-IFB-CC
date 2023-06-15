#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

void solve(vector<pii> &intervals)
{
    sort(intervals.begin(), intervals.end()); // θ(nlogn)
    int start;
    pii location;
    int max_collision = 0;
    int collision = 0;
    priority_queue<int, std::vector<int>, std::greater<int>> end;
    // Esse loop possui complexidade θ(logn)
    for (int i = 0; i < intervals.size(); i++)
    {
        end.push(intervals[i].second); // θ(logn)
        if (intervals[i].first <= end.top())
        { // θ(1)
            collision++;
            start = intervals[i].first;
        }

        if (collision > max_collision)
        {
            max_collision = collision;
            location = {start, end.top()}; // θ(1)
        }

        while (intervals[i].first > end.top())
        { // θ(1)
            collision--;
            end.pop(); // θ(logn)
        }
    }
    // Complexidade final: θ(nlogn)
    cout << "[" << location.first << ", " << location.second << "]\n";
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<pii>> tests;
    tests.push_back(vector<pii>{{1, 3}, {2, 4}, {3, 4}, {5, 7}});                         // [3,3]
    tests.push_back(vector<pii>{{1, 3}, {5, 7}, {8, 9}, {10, 100}});                      // [1,3]
    tests.push_back(vector<pii>{{1, 100}, {1, 50}, {1, 20}, {3, 10}, {5, 9}, {6, 8}});    // [6,8]
    tests.push_back(vector<pii>{{2, 5}, {3, 6}, {4, 5}, {5, 6}, {6, 8}, {3, 8}, {6, 7}}); // [5,5]
    tests.push_back(vector<pii>{{2, 9}, {3, 5}, {4, 7}, {5, 6}, {5, 7}});                 // [5,5]
    tests.push_back(vector<pii>{{1, 5}, {2, 6}, {3, 6}, {4, 5}, {2, 7}});                 // [4,5]
    for (auto &test : tests)
        solve(test);
    return 0;
}