#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
vector<ll> dp(100001, -1);
ll fac[100001];

void fillFac() {
    fac[0] = 1;
    ll cur = 1;
    for (ll i = 1; i <= N; i++) {
        cur = cur * i % 1000000007;
        fac[i] = cur;
    }
}

ll helper(ll n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    if (n == 2) return 1;
    dp[0] = 1;
    dp[1] = 0;
    if (dp[n] != -1) return dp[n];

    for (ll i = 2; i <= n; i++) {
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % 1000000007;
    }

    return dp[n];
}

ll solve() {
    fillFac();
    ll x = helper(N);
    return x * fac[N] % 1000000007;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    cout << solve() << endl;
    return 0;
}