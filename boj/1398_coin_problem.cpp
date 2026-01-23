#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int tc;
ll N;
vector<int> dp(100, -1);

int fillDP(int n) {
    vector<int> v;
    if (dp[n] != -1) return dp[n];
    else {
        if (n >= 25) {
            v.push_back(1 + fillDP(n - 25));
        }
        if (n >= 10) {
            v.push_back(1 + fillDP(n - 10));
        }
        v.push_back(1 + fillDP(n - 1));
    }

    dp[n] = *min_element(v.begin(), v.end());

    return dp[n];
}

int solve() {
    int ans = 0;
    while (N != 0) {
        int n = N % 100;
        ans += dp[n];
        N = N / 100;
    }
    return ans;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 99; i >= 0; i--) fillDP(i);

    cin >> tc;

    while (tc--) {
        cin >> N;
        cout << solve() << endl;
    }

    return 0;
}