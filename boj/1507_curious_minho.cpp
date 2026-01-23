#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M;
vector<vector<int>> dist;
vector<vector<int>> visited(21, vector<int>(21, 0));
int solve() {
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            int d = 1e9;
            for (int k = 1; k <= N; k++) {
                if (i != k && j != k) {
                    // (i, k) -> (k, j)
                    d = min(d, dist[i][k] + dist[k][j]);
                }
                if (d < dist[i][j]) return -1;
            }

            if (d > dist[i][j]) {
                // cout << "edge from " << i << " to " << j << endl;
                // cout << "weight: " << dist[i][j] << endl;
                ans += dist[i][j];
            }
        }
    }
    return ans / 2;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    dist.assign(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int t; cin >> t;
            dist[i][j] = t;
        }
    }
    cout << solve() << endl;
    return 0;
}