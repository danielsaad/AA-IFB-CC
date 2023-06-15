#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

void solve(vector<pii> &intervals)
{
    sort(intervals.begin(), intervals.end());

    vector<pii> ans;
    ans.push_back(intervals[0]);
    int last = ans[0].second;
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i].first >= last)
        {
            ans.push_back(intervals[i]);
            last = intervals[i].second;
        }
    }
    for (auto &e : ans)
        cout << "[" << e.first << ", " << e.second << "] ";
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<pii>> tests;
    tests.push_back(vector<pii>{{1, 2}, {2, 6}, {2, 3}, {3, 5}, {6, 7}, {3, 4}, {6, 8}});
    tests.push_back(vector<pii>{{1, 5}, {1, 3}, {6, 9}, {8, 20}, {7, 10}, {9, 10}, {10, 7}});
    for (auto &test : tests)
        solve(test);
    return 0;
}