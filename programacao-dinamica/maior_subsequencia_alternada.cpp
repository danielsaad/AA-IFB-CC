#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

// Questão 05
void print_sequence(vi &v, vi &par, vi &impar)
{
    int n = par.size();
    int value = par[n - 1];
    bool alternate = true;
    vi ans;
    for (int i = n - 1; i >= 0; i--)
    {
        if (alternate)
        {
            while (i >= 0 && par[i] == value)
                i--;
            value -= v[i + 1];
        }
        else
        {
            while (i >= 0 && impar[i] == value)
                i--;
            value += v[i + 1];
        }
        alternate = !alternate;
        ans.push_back(i + 1);
    }
    reverse(ans.begin(), ans.end());
    for (auto &e : ans)
        cout << v[e] << ' ';
    cout << '\n';
}

// Questão 04
void solve(vi &v)
{
    int n = v.size();
    vi par(n), impar(n);
    par[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        par[i] = max(par[i - 1], impar[i - 1] + v[i]);
        impar[i] = max(impar[i - 1], par[i - 1] - v[i]);
    }
    cout << "Maior valor: " << par[n - 1] << '\n';
    print_sequence(v, par, impar);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vi> tests;
    tests.push_back(vi{9, 5, 2, 4, 1});    // 11
    tests.push_back(vi{6, 2, 1, 2, 4, 5}); // 10
    for (auto &test : tests)
        solve(test);
    return 0;
}