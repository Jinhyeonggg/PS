#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, W;
vector<pair<int, int>> A;
vector<vector<int>> dp; 
vector<int> track;
vector<vector<pair<int, int>>> record(1001, vector<pair<int, int>>(1001, {0, 0}));

int getDist(int i, int j, int car) {
    pair<int, int> zeroPos = car == 1 ? make_pair(1, 1) : make_pair(N, N);
    pair<int, int> p1 = i == 0 ? zeroPos : A[i];
    pair<int, int> p2 = j == 0 ? zeroPos : A[j];
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int getDist(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void update(int i, int j) {
    if (max(i, j) == W) return;

    int next = max(i, j) + 1;
    // move 1st car
    dp[next][j] = dp[i][j] + getDist(i, next, 1);
    update(next, j);

    // move 2nd car
    dp[i][next] = dp[i][j] + getDist(j, next, 2);
    update(i, next);
}

int solve(int i, int j) {
    dp[0][0] = 0;
    update(0, 0);
    return 0;
}

void tracking(int i, int j) {
    while (i != 0 || j != 0) {
        // cout << i << ' ' << j << endl;
        if (i < j) {
            while (j > i) {
                track.push_back(2);
                j--;
            }
            if (j == 0) break;
            j++; // i j
        }
        else if (i > j) {
            while (i > j) {
                track.push_back(1);
                i--;
            }
            if (i == 0) break;
            i++; // j i
        }
        int a = record[i][j].first, b = record[i][j].second;
        if (a == 1) {
            i = b;
        }
        else {
            j = b;
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
    solve(0, 0);
    for (int i = 0; i < W; i++) {
        if (ans > dp[i][W]) {
            ans = dp[i][W];
        }

        if (ans > dp[W][i]) {
            ans = dp[W][i];
        }
    }
    cout << ans << endl;
    // for (int i = 0; i <= W; i++) {
    //     for (int j = 0; j <= W; j++) {
    //         cout << '(' << track[i][j].first << ' ' << track[i][j].second << ')' << ' ';
    //     }
    //     cout << endl;
    // }
    return 0;
}