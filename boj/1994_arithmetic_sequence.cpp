#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
vector<int> A;

// dp[i][j]: i번째 원소로 끝나는, 이전원소가 j (<= i)인 등차수열의 최대길이
vector<vector<int>> dp(2001, vector<int>(2001, 0)); 

int solve() {
    dp[0][0] = 1;
    dp[1][0] = 2;
    dp[1][1] = 1;

    for (int i = 2; i < N; i++) {
        for (int j = i; j >= 0; j--) {
            if (j == i) dp[i][j] = 1;
            else {
                int d = A[i] - A[j];
                auto p = lower_bound(A.begin(), A.begin() + j, A[j] - d);
                if (p == A.begin() + j || *p != A[j] - d) {
                    dp[i][j] = 2;
                    continue;
                }
                else {
                    int idx = upper_bound(A.begin(), A.begin() + j, A[j] - d) - A.begin() - 1;
                    dp[i][j] = dp[j][idx] + 1;
                }
            }
        }
    }
    
    int ans = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int t; cin >> t;
        A.push_back(t);
    }
    sort(A.begin(), A.end());

    cout << solve() << endl;
    return 0;
}