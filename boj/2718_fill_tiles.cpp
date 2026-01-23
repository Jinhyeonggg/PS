#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll tc;
ll N;
vector<ll> dp;

void initDP() {
    dp.assign(N + 1, -1);
}

int solve(int n) {
    if (dp[n] != -1) return dp[n];
    if (n == 0) return 1;
    if (n == 1) return 1;
    if (n == 2) return 5;

    ll ans = solve(n - 1) + solve(n - 2);

    int t = n - 2;
    while (t >= 0) {
        ans += 2 * solve(t);
        t -= 1;
    }

    t = 2;
    while (t <= n) {
        ans += solve(n - t);
        t += 2;
    }
    dp[n] = ans;
    return ans;
}   

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> tc;
    while (tc--)
    {
        cin >> N;
        initDP();
        ll ans = solve(N);
        cout << ans << endl;
    }
    return 0;
}