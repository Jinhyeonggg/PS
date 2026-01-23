#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, K;
vector<ll> A;
vector<ll> dp;
vector<ll> prefixSum;

void initPrefix() {
    prefixSum.push_back(0);
    ll t = 0;
    for (ll i = 0; i < N; i++) {
        t += A[i];
        prefixSum.push_back(t);
    }
}

ll getSum(ll l, ll r) {
    return prefixSum[r + 1] - prefixSum[l];
}

ll solve() {
    ll l = 0, sum = A[0];
    dp[0] = sum >= K ? sum - K : 0;
    if (sum >= K) {
        dp[0] = sum - K;
        sum = 0;
        l++;
    }
    for (ll r = 1; r < N; r++) {
        dp[r] = dp[r - 1];
        sum += A[r];
        if (sum >= K) {
            while (sum >= K) {
                if (l == 0) dp[r] = max(dp[r], sum - K);
                else dp[r] = max(dp[r], dp[l - 1] + sum - K);
                sum -= A[l];
                l++;
            }   
        }
    }
    return dp[N - 1];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> K;
    dp.assign(N, 0);
    for (ll i = 0; i < N; i++) {
        ll t; cin >> t;
        A.push_back(t);
    }
    initPrefix();

    cout << solve() << endl;
    return 0;
}