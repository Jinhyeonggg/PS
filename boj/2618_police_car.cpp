#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, W;
vector<pair<int, int>> A;
vector<vector<int>> dp; 
vector<int> track;
vector<vector<int>> record(1001, vector<int>(1001, 0));
int a, b;

int getDist(int i, int j, int car) {
    pair<int, int> zeroPos = car == 1 ? make_pair(1, 1) : make_pair(N, N);
    pair<int, int> p1 = i == 0 ? zeroPos : A[i];
    pair<int, int> p2 = j == 0 ? zeroPos : A[j];
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int getDist(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int solve() {
    dp[0][0] = 0, dp[1][0] = getDist(0, 1, 1), dp[0][1] = getDist(0, 1, 2);
    int i, j;
    for (int M = 2; M <= W; M++) {
        // i <- M
        i = M;
        for (j = 0; j <= i - 2; j++) {
            dp[i][j] = dp[i - 1][j] + getDist(i - 1, i, 1);
            record[i][j] = i - 1;
        }
        for (int k = 0; k <= i - 2; k++) {
            int t = dp[k][i - 1] + getDist(k, i, 1);
            if (dp[i][i - 1] > t) {
                record[i][i - 1] = k;
                dp[i][i - 1] = t;
            }
        }

        // j <- M
        j = M;
        for (i = 0; i <= j - 2; i++) {
            dp[i][j] = dp[i][j - 1] + getDist(j - 1, j, 2);
            record[i][j] = j - 1;
        }
        for (int k = 0; k <= j - 2; k++) {
            int t = dp[j - 1][k] + getDist(k, j, 2);
            if (dp[j - 1][j] > t) {
                record[j - 1][j] = k;
                dp[j - 1][j] = t;
            }
        }
    }

    int ans = 1e9;
    for (int i = 0; i < W; i++) {
        if (ans > dp[i][W]) {
            a = i, b = W;
            ans = dp[i][W];
        }

        if (ans > dp[W][i]) {
            a = W, b = i;
            ans = dp[W][i];
        }
    }
    return ans;
}

void tracking(int i, int j) {
    while (i != 0 || j != 0) {
        if (i > j) {
            track.push_back(1);
            i = record[i][j];
        }
        else {
            track.push_back(2);
            j = record[i][j];
        }
    }
    reverse(track.begin(), track.end());
    for (int i: track) {
        cout << i << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> W;
    dp.assign(W + 1, vector<int>(W + 1, 1e9));

    A.push_back({-1, -1});
    for (int i = 0; i < W; i++) {
        int a, b; cin >> a >> b;
        A.push_back({a, b});
    }

    int ans = 1e9;
    cout << solve() << endl;
    tracking(a, b);

    return 0;
}